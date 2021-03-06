// /std_bhm/test/n_k/load_n_k_data_arrays.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/n_k/load_n_k_data_arrays.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/load_n_k_data_arrays.h"
#include "os/get_abs_path_of_exe.h"
#include "str_ops/replace.h"
#include "output/vector_to_string.h"
#include "k_map/gen_minimal_k_ints_set.h"
#include "hopping/spatial_params.h"



namespace NSA1 = std_bhm::n_k;
namespace NSA2 = std_bhm::os;
namespace NSA3 = std_bhm::str_ops;
namespace NSA4 = std_bhm::output;
namespace NSA5 = std_bhm::k_map;
namespace NSA6 = std_bhm::hopping;

int main(int argc, char** argv)
{
    const auto abs_path_of_exe = ::NSA2::get_abs_path_of_exe();
    const auto substr_index = abs_path_of_exe.find_last_of("/\\");
    auto abs_dir_name_for_sys_data_set
	= abs_path_of_exe.substr(0, substr_index);
    ::NSA3::replace(abs_dir_name_for_sys_data_set, "/bin/", "/data/");
    abs_dir_name_for_sys_data_set
	+= "/d_3 L_6 beta_100 mu_0.42 jf_0.03 tc_100 tauQ_5 ds_0.05 Ns_1001";
    
    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto L = int(6);
    const auto d = int(3);
    const auto& sp_params = ::NSA6::spatial_params(L, d);
	
    const auto& n_k_arrays
	= ::NSA1::load_n_k_data_arrays(abs_dir_name_for_sys_data_set);
    const auto& k_ints_set = ::NSA5::gen_minimal_k_ints_set(sp_params);

    auto n_k_array = n_k_arrays[0];
    auto k_ints = k_ints_set[0];
    const auto Ns = n_k_array.size();
    std::cout << "Printing n_k_array contents for k = "
	      << ::NSA4::vector_1d_to_string(k_ints) << ":" << std::endl;
    for(auto i=decltype(10){0}; i<10; i++)
	std::cout << "n_k_array[" << i << "] = " << n_k_array[i] << std::endl;
    for(auto i=decltype(Ns){Ns-10}; i<Ns; i++)
	std::cout << "n_k_array[" << i << "] = " << n_k_array[i] << std::endl;

    std::cout << std::endl;

    n_k_array = n_k_arrays[2];
    k_ints = k_ints_set[2];
    std::cout << "Printing n_k_array contents for k = "
	      << ::NSA4::vector_1d_to_string(k_ints) << ":" << std::endl;
    for(auto i=decltype(10){0}; i<10; i++)
	std::cout << "n_k_array[" << i << "] = " << n_k_array[i] << std::endl;
    for(auto i=decltype(Ns){Ns-10}; i<Ns; i++)
	std::cout << "n_k_array[" << i << "] = " << n_k_array[i] << std::endl;
    
    return 0;
}

