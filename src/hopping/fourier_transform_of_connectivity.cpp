// std_bhm/src/hopping/fourier_transform_of_connectivity.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>
#include <algorithm>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "hopping/fourier_transform_of_connectivity.h"



// Calculate the Fourier transform of the connectivity matrix given a 
// quasi-momentum vector
namespace NSA1 = std_bhm::hopping;

double NSA1::fourier_transform_of_connectivity
(const std::vector<double>& k_vector)
{
    auto sum = 0.0;
    std::for_each(k_vector.cbegin(), k_vector.cend(), 
		  [&] (double x) { sum += std::cos(x); } );
    auto tol = 1.0e-10;
    return (std::abs(sum) < tol) ? 0 : 2.0 * sum;
}
