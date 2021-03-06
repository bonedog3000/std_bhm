// std_bhm/src/hopping/epsilon.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <cmath>
#include <algorithm>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "hopping/epsilon.h"
#include "hopping/fourier_transform_of_connectivity.h"



// Calculate the fourier transform of the hopping given a quasi-momentum vector
namespace NSA1 = std_bhm::hopping;

double NSA1::epsilon(double J, const std::vector<double>& k_vector)
{
    return -J * ::NSA1::fourier_transform_of_connectivity(k_vector);
}
