// /std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/
// /u1.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/bhm_2hs_2pi/konstantinov_and_perel
// /finite_temperature/u1.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/finite_temperature/u1.h"
#include "atomic_lim/local/params.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel;
namespace NSA3 = NSA2::finite_temperature;

using local_params = std_bhm::atomic_lim::local::params;

int main(int argc, char** argv)
{
    const auto beta = ::NSA1::to_value<double>();
    const auto mu = ::NSA1::to_value<double>();
    const auto max_band_index = ::NSA1::to_value<int>();
    const auto& l_params = local_params(beta, mu, max_band_index);
    const auto u1_result = ::NSA3::u1(l_params);

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    std::cout << "u1 = " << u1_result << std::endl;
    
    return 0;
}

