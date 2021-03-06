// std_bhm/src/n_k/gen_n_k_array_from_G_K12_array.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <cmath>

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/gen_n_k_array_from_G_K12_array.h"



// Generate quasi-momentum distribution array from G_K12 array.
namespace NSA1 = std_bhm::n_k::gen_n_k_array_from_G_K12_array_detail;

using dbl_vec = std::vector<double>;
using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

dbl_vec NSA1::gen_n_k_array_from_G_K12_array(const cmplx_vec& G_K12_array)
{
    const auto size = G_K12_array.size();
    const auto Ns = ( -1 + int( round( sqrt(1 + 8 * size) ) ) ) / 2;

    auto array_index = -1;
    auto n_k_array = dbl_vec();

    for(auto i=decltype(Ns){0}; i<Ns; i++)
    {
	array_index += i + 1;
	const auto I = cmplx_dbl(0.0, 1.0);
	const auto n_k_value
	    = std::real( 0.5 * (I * G_K12_array[array_index] - 1.0) );
	n_k_array.push_back(n_k_value);
    }

    return n_k_array;
}
