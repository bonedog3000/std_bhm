// std_bhm/include/k_map/k_vec_to_k_ints.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_K_MAP_K_VEC_TO_K_INTS_H
#define STD_BHM_K_MAP_K_VEC_TO_K_INTS_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */

/* Include user-defined header files */



namespace std_bhm
{
namespace k_map
{
namespace k_vec_to_k_ints_detail
{

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

int_vec k_vec_to_k_ints(dbl_vec k_vec, int L);

} // end of k_vec_to_k_ints_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::k_map::k_vec_to_k_ints_detail::k_vec_to_k_ints;



} // end of k_map namespace
} // end of std_bhm namespace


#endif
