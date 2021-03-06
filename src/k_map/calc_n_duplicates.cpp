// std_bhm/src/k_map/calc_n_duplicates.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>
#include <algorithm>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "k_map/calc_n_duplicates.h"



// Calculate the number of k-vectors related to a given k-vector by
// reflections and permutations.
namespace NSA1 = std_bhm::k_map::calc_n_duplicates_detail;

using dbl_vec = std::vector<double>;

int NSA1::calc_n_duplicates(dbl_vec k_vec)
{
    const auto tol = 1.0e-15;

    for(auto& k_val : k_vec)
	k_val = fabs(k_val);
    
    auto reflection_factor = 1;

    for(auto k_val : k_vec)
    {
	const auto pi = atan(1.0) * 4.0;
	const auto temp_diff = std::abs(pi - k_val);
	if ( (k_val != 0) && (temp_diff > tol) )
	    reflection_factor *= 2;
    }

    auto permutation_factor = 1;
    
    std::sort( k_vec.begin(), k_vec.end() );
    while ( std::next_permutation( k_vec.begin(), k_vec.end() ) )
	permutation_factor++;
    
    return reflection_factor * permutation_factor;
}
