// std_bhm/src/density_matrix/single_particle/calc_from_n_k_data.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <string>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "density_matrix/single_particle/calc_from_n_k_data.h"
#include "density_matrix/single_particle/calc_density_matrix_element.h"
#include "hopping/spatial_params.h"
#include "parameters/read_spatial_params_off_sys_data_dir_name.h"
#include "n_k/load_n_k_data_arrays.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

void calc_from_n_k_data_inner_loop(int depth,
				   int_vec& delta_r_ints, 
				   int max,
				   dbl_vec_2d& density_matrix,
				   const dbl_vec_2d& n_k_arrays,
				   int L);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace




// Calculate the single-particle density matrix from the n_k data found
// in given system data set. (Overload #1)
namespace NSA1 = std_bhm::density_matrix::single_particle;
namespace NSA2 = NSA1::calc_from_n_k_data_detail;
namespace NSA3 = std_bhm::parameters;
namespace NSA4 = std_bhm::n_k;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d NSA2::calc_from_n_k_data
                     (const std::string& abs_sys_data_set_dir_name)
{
    const auto& sp_params = ::NSA3::read_spatial_params_off_sys_data_dir_name(
	                                abs_sys_data_set_dir_name);
	
    const auto L = sp_params.get_L();
    const auto d = sp_params.get_d();

    const auto& n_k_arrays
	= ::NSA4::load_n_k_data_arrays(abs_sys_data_set_dir_name);

    auto density_matrix = dbl_vec_2d();
    auto delta_r_ints = int_vec(d);

    ::unnamed::calc_from_n_k_data_inner_loop(d,
					     delta_r_ints,
					     L/2,
					     density_matrix,
					     n_k_arrays,
					     L);

    return density_matrix;
}



// Calculate the single-particle density matrix from n_k data. (Overload #2)
namespace NSA1 = std_bhm::density_matrix::single_particle;
namespace NSA2 = NSA1::calc_from_n_k_data_detail;

namespace NSA5 = std_bhm::hopping;

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d NSA2::calc_from_n_k_data(const ::NSA5::spatial_params& sp_params,
				    const dbl_vec_2d& n_k_arrays)
{
    const auto L = sp_params.get_L();
    const auto d = sp_params.get_d();

    auto density_matrix = dbl_vec_2d();
    auto delta_r_ints = int_vec(d);

    ::unnamed::calc_from_n_k_data_inner_loop(d,
					     delta_r_ints,
					     L/2,
					     density_matrix,
					     n_k_arrays,
					     L);

    return density_matrix;
}



// A recursive for-loop to load the n_k data_arrays from each data_arrays file.
namespace NSA1 = std_bhm::density_matrix::single_particle;

namespace unnamed
{
namespace
{

void calc_from_n_k_data_inner_loop(int depth,
				   int_vec& delta_r_ints, 
				   int max,
				   dbl_vec_2d& density_matrix,
				   const dbl_vec_2d& n_k_arrays,
				   int L)
{
    if(depth > 0)
    {
	for(auto i=decltype(max){0}; i<=max; i++)
	{
	    const auto d = delta_r_ints.size();
	    delta_r_ints[d-depth] = i;
	    unnamed::calc_from_n_k_data_inner_loop(depth-1,
						   delta_r_ints,
						   i,
						   density_matrix,
						   n_k_arrays,
						   L);
	}
    }
    else
    {
	const auto density_matrix_element
	    = ::NSA1::calc_density_matrix_element(delta_r_ints, n_k_arrays, L);

	density_matrix.push_back(density_matrix_element);
    }
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
