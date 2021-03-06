// std_bhm/include/k_map/gen_minimal_k_ints_set.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_K_MAP_GEN_MINIMAL_K_INTS_SET_H
#define STD_BHM_K_MAP_GEN_MINIMAL_K_INTS_SET_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "hopping/spatial_params.h"



namespace std_bhm
{
namespace k_map
{
namespace gen_minimal_k_ints_set_detail
{

namespace NSA1 = std_bhm::hopping;

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

int_vec_2d gen_minimal_k_ints_set(const NSA1::spatial_params& sp_params);

} // end of gen_minimal_k_ints_set_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::k_map::gen_minimal_k_ints_set_detail::gen_minimal_k_ints_set;



} // end of k_map namespace
} // end of std_bhm namespace


#endif
