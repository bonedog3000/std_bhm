// /std_bhm/test/k_map/gen_minimal_k_vec_set.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/k_map/gen_minimal_k_vec_set.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "k_map/gen_minimal_k_vec_set.h"
#include "k_map/gen_minimal_k_ints_set.h"
#include "hopping/spatial_params.h"
#include "parameters/from_std_cin.h"
#include "output/vector_to_string.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::hopping;
namespace NSA3 = std_bhm::k_map;
namespace NSA4 = std_bhm::output;

int main(int argc, char** argv)
{
    const auto L = ::NSA1::to_value<int>();
    const auto d = ::NSA1::to_value<int>();
    const auto& sp_params = ::NSA2::spatial_params(L, d);
	
    const auto& k_vec_set = ::NSA3::gen_minimal_k_vec_set(sp_params);
    const auto& k_ints_set = ::NSA3::gen_minimal_k_ints_set(sp_params);

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    const auto set_size = k_vec_set.size();
    for(auto i=decltype(set_size){0}; i<set_size; i++)
    {
	std::cout << ::NSA4::vector_1d_to_string(k_vec_set[i]) << "\t"
		  << ::NSA4::vector_1d_to_string(k_ints_set[i]) << std::endl;
    }
    
    return 0;
}

