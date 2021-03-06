// std_bhm/include/n_k/load_n_k_data_arrays.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_N_K_LOAD_N_K_DATA_ARRAYS_H
#define STD_BHM_N_K_LOAD_N_K_DATA_ARRAYS_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */


namespace std_bhm
{
namespace n_k
{
namespace load_n_k_data_arrays_detail
{

using dbl_vec = std::vector<double>;
using dbl_vec_2d = std::vector<dbl_vec>;

dbl_vec_2d load_n_k_data_arrays
               (const std::string& abs_sys_data_set_dir_name);

} // end of load_n_k_data_arrays_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::n_k::load_n_k_data_arrays_detail::load_n_k_data_arrays;



} // end of n_k namespace
} // end of std_bhm namespace


#endif
