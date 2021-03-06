// /std_bhm/src/ed_1d/quench_0T/tuned_hopping/main_alg.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <string>
#include <iostream>
#include <limits>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/tuned_hopping/main_alg.h"
#include "ed_1d/quench_0T/tuned_hopping/main_alg_params.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "hopping/quench/linear/quench_params.h"
#include "hopping/quench/linear/amplitude.h"
#include "ed_1d/local_params.h"
#include "ed_1d/step_params.h"
#include "ed_1d/quench_0T/tuned_hopping/Ohm_1.h"
#include "ed_1d/quench_0T/n_k.h"
#include "ed_1d/bhm_params.h"
#include "ed_1d/quench_0T/ground_state.h"
#include "arma_support/conv.h"
#include "ed_1d/step_evolve_mat_rep.h"
#include "ed_1d/lanczos_alg_params.h"
#include "hopping/spatial_params.h"
#include "density_matrix/single_particle/calc_from_n_k_data.h"
#include "output/write_time_series_to_file.h"
#include "output/gen_abs_pathname_for_output_directories.h"
#include "k_map/gen_minimal_k_ints_set.h"
#include "str_ops/to_string_no_trailing_zeros.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void begin_simulation(arma::cx_dvec& state_vec,
		      const ::NSA3::Ohm_1& Ohm_1,
		      const ::NSA2::n_k& n_k,
		      const ::NSA3::main_alg_params& main_params);

void calc_avg_n_k(int n,
		  double dt,
		  dbl_vec_2d& n_k_time_series,
		  const ::NSA2::n_k& n_k,
		  arma::cx_dvec& state_vec);

void write_single_particle_density_matrix_to_file(
         const ::NSA3::main_alg_params& main_params,
	 const dbl_vec_2d& density_matrix);

std::string gen_abs_filename_for_output_file(
                 const ::NSA3::main_alg_params& main_params,
		 const int_vec& vec_index,
		 const std::string& lowest_level_dir_name_and_file_prefix);

std::string gen_system_data_set_directory_name(
                const ::NSA3::main_alg_params& main_params);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate matrix representation of the interaction part of the BHM
// Hamiltonian where the interaction strength 'U' is set to unity.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA4 = std_bhm::hopping::quench::linear;
namespace NSA5 = std_bhm::arma_support;

void NSA3::main_alg()
{
    const auto main_params = ::NSA3::main_alg_params();

    const auto& fb_params = main_params.get_fock_basis_params();
    const auto basis = ::NSA2::fock_basis(fb_params);

    const auto& q_params = main_params.get_quench_params();
    const auto J = ::NSA4::amplitude(q_params);

    const auto& l_params = main_params.get_local_params();
    const auto& dt_and_Nt = main_params.get_step_params();
    const auto dt = dt_and_Nt.get_dt();
    auto Ohm_1 = ::NSA3::Ohm_1(basis, J, l_params, dt);

    const auto n_k = ::NSA2::n_k(basis);

    const auto D = basis.get_hilbert_space_dimension();
    auto ground_state_vec = arma::dvec(D);
    const auto initial_model_params = ::NSA1::bhm_params(J.eval(0), l_params);
    ::NSA2::ground_state(ground_state_vec, basis, initial_model_params);
    auto state_vec = ::NSA5::dvec_to_cx_dvec(ground_state_vec);

    ::unnamed::begin_simulation(state_vec, Ohm_1, n_k, main_params);
}



// Begin simulation.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA4 = std_bhm::hopping::quench::linear;
namespace NSA5 = std_bhm::arma_support;
namespace NSA6 = std_bhm::hopping;
namespace NSA7 = std_bhm::density_matrix::single_particle;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void begin_simulation(arma::cx_dvec& state_vec,
		      const ::NSA3::Ohm_1& Ohm_1,
		      const ::NSA2::n_k& n_k,
		      const ::NSA3::main_alg_params& main_params)
{   
    const auto& dt_and_Nt = main_params.get_step_params();
    const auto Nt = dt_and_Nt.get_Nt();
    const auto& fb_params = main_params.get_fock_basis_params();
    const auto M = fb_params.get_number_of_lattice_sites();
    auto n_k_time_series = dbl_vec_2d( M,  dbl_vec(Nt) );
    
    auto t = 0.0;
    for(auto n=decltype(Nt){0}; n<Nt; n++)
    {
	const auto dt = dt_and_Nt.get_dt();
	::unnamed::calc_avg_n_k(n, dt, n_k_time_series, n_k, state_vec);

	const auto Ohm = ::NSA5::sp_mat_to_sp_cx_mat( Ohm_1.eval(t) );
	// const auto& la_params = main_params.get_lanczos_alg_params();
	// const auto step_evolve = ::NSA1::step_evolve_mat_rep(Ohm,
	// 						     state_vec,
	// 						     la_params);
	const auto Ohm_dense = ::arma::cx_mat(Ohm);
	const auto step_evolve = ::NSA1::step_evolve_mat_rep(Ohm_dense,
							     state_vec);
	
	state_vec = step_evolve * state_vec;
	state_vec /= arma::norm(state_vec);

	t += dt;
    }

    const auto sp_params = ::NSA6::spatial_params(M, 1);
    const auto density_mat = ::NSA7::calc_from_n_k_data(sp_params,
							n_k_time_series);

    ::unnamed::write_single_particle_density_matrix_to_file(main_params,
							    density_mat);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate expectation value of n_k at current timestep.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

namespace unnamed
{
namespace
{

void calc_avg_n_k(int n,
		  double dt,
		  dbl_vec_2d& n_k_time_series,
		  const ::NSA2::n_k& n_k,
		  arma::cx_dvec& state_vec)
{   
    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    auto N = 0.0;
    const auto M = n_k_time_series.size();
    for(auto k=decltype(M){0}; k<M; k++)
    {
	const auto avg_n_k = n_k.expectation_value(k, state_vec);
	n_k_time_series[k][n] = avg_n_k;
	N += avg_n_k;
    }
    
    std::cout << "t = " << n * dt
	      << ",\ttotal # of particles = " << N << std::endl;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Write single-particle density matrix data to a set of files.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA6 = std_bhm::hopping;
namespace NSA8 = std_bhm::k_map;
namespace NSA9 = std_bhm::output;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

namespace unnamed
{
namespace
{

void write_single_particle_density_matrix_to_file(
         const ::NSA3::main_alg_params& main_params,
	 const dbl_vec_2d& density_matrix)
{
    const auto& fb_params = main_params.get_fock_basis_params();
    const auto M = fb_params.get_number_of_lattice_sites();
    const auto sp_params = ::NSA6::spatial_params(M, 1);

    // Note that delta_r_ints_set = k_ints_set
    const auto& delta_r_ints_set = ::NSA8::gen_minimal_k_ints_set(sp_params);
    const auto set_size = delta_r_ints_set.size();

    #pragma omp parallel
    {
	#pragma omp for
	for(auto i=decltype(set_size){0}; i<set_size; i++)
	{
	    const auto& delta_r_ints = delta_r_ints_set[i];
	    const auto& temp_str
		= "single-particle density matrix data/r-vector";
	    const auto abs_filename
		= ::unnamed::gen_abs_filename_for_output_file(main_params,
							      delta_r_ints,
							      temp_str);
	    const auto& dt_and_Nt = main_params.get_step_params();
	    const auto dt = dt_and_Nt.get_dt();
	    const auto& density_matrix_element = density_matrix[i];
	    const auto data_label = "rho_1";
	    ::NSA9::write_time_series_to_file(abs_filename,
					      density_matrix_element,
					      dt,
					      data_label);
	}
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate absolute filename for n_k data file (to be written presumably).
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA9 = std_bhm::output;

using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

std::string gen_abs_filename_for_output_file(
                const ::NSA3::main_alg_params& main_params,
		const int_vec& vec_index,
		const std::string& lowest_level_dir_name_and_file_prefix)
{
    const auto abs_pathname_for_output_directories
	= ::NSA9::gen_abs_pathname_for_output_directories();
    const auto system_data_set_directory_name
	= ::unnamed::gen_system_data_set_directory_name(main_params);

    auto vec_index_str_rep = std::string();
    for(const auto& value : vec_index)
	vec_index_str_rep += " " + std::to_string(value);
    vec_index_str_rep += ".txt";

    return (abs_pathname_for_output_directories + "/"
	    + system_data_set_directory_name + "/"
	    + lowest_level_dir_name_and_file_prefix
	    + vec_index_str_rep);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Generate name for system data set directory based on main algorithm
// parameters.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA10 = std_bhm::str_ops;

namespace unnamed
{
namespace
{

std::string gen_system_data_set_directory_name(
                const ::NSA3::main_alg_params& main_params)
{
    const auto l_params = main_params.get_local_params();
    const auto fb_params = main_params.get_fock_basis_params();
    const auto q_params = main_params.get_quench_params();
    const auto dt_and_Nt = main_params.get_step_params();
    
    const auto L = fb_params.get_number_of_lattice_sites();
    const auto mu = l_params.get_mu();
    const auto jf = q_params.get_jf();
    const auto tc = q_params.get_tc();
    const auto tau_Q = q_params.get_tau_Q();
    const auto dt = dt_and_Nt.get_dt();
    const auto Nt = dt_and_Nt.get_Nt();

    const auto L_str = ::NSA10::to_string_no_trailing_zeros(L);
    const auto mu_str = ::NSA10::to_string_no_trailing_zeros(mu);
    const auto jf_str = ::NSA10::to_string_no_trailing_zeros(jf);
    const auto tc_str = ::NSA10::to_string_no_trailing_zeros(tc);
    const auto tau_Q_str = ::NSA10::to_string_no_trailing_zeros(tau_Q);
    const auto dt_str = ::NSA10::to_string_no_trailing_zeros(dt);
    const auto Nt_str = ::NSA10::to_string_no_trailing_zeros(Nt);

    return ( "d_1 L_" + L_str + " T_0 mu_" + mu_str + " jf_" + jf_str
	     + " tc_" + tc_str + " tauQ_" + tau_Q_str + " dt_" + dt_str
	     + " Nt_" + Nt_str );
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
