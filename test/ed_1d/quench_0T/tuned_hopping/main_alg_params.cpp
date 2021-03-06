// /std_bhm/test/ed_1d/quench_0T/tuned_hopping/main_alg_params.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the classes defined in the 
// .cpp file 'std_bhm/test/ed_1d/quench_0T/tuned_hopping/main_alg_params.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "ed_1d/quench_0T/tuned_hopping/main_alg_params.h"
#include "ed_1d/local_params.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/step_params.h"
#include "ed_1d/lanczos_alg_params.h"
#include "hopping/quench/linear/quench_params.h"



namespace NSA1 = std_bhm::ed_1d::quench_0T::tuned_hopping;

int main(int argc, char** argv)
{
    const auto main_params = ::NSA1::main_alg_params();

    const auto& l_params = main_params.get_local_params();
    const auto& fb_params = main_params.get_fock_basis_params();
    const auto& q_params = main_params.get_quench_params();
    const auto& dt_and_Nt = main_params.get_step_params();
    const auto& la_params = main_params.get_lanczos_alg_params();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    std::cout << "mu = " << l_params.get_mu() << std::endl;
    std::cout << "U = " << l_params.get_U() << std::endl;
    std::cout << "Total # of particles = "
	      << fb_params.get_total_number_of_particles() << std::endl;
    std::cout << "# of lattice sites = "
	      << fb_params.get_number_of_lattice_sites() << std::endl;
    std::cout << "ji = " << q_params.get_ji() << std::endl;
    std::cout << "jf = " << q_params.get_jf() << std::endl;
    std::cout << "tc = " << q_params.get_tc() << std::endl;
    std::cout << "tau_Q = " << q_params.get_tau_Q() << std::endl;
    std::cout << "dt = " << dt_and_Nt.get_dt() << std::endl;
    std::cout << "Nt = " << dt_and_Nt.get_Nt() << std::endl;
    std::cout << "Krylov dimension = " << la_params.get_krylov_dimension()
	      << std::endl;
    std::cout << "Convergence-tolerance = "
	      << la_params.get_convergence_tolerance() << std::endl;
    
    return 0;
}

