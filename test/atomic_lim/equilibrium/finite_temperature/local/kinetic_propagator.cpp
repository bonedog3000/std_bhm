// /std_bhm/test/atomic_lim/equilibrium/finite_temperature/local
// /kinetic_propagator.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/atomic_lim/equilibrium/finite_temperature/local
// /kinetic_propagator.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/equilibrium/finite_temperature/local/kinetic_propagator.h"
#include "atomic_lim/local/params.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;

int main(int argc, char** argv)
{
    const auto beta = ::NSA1::to_value<double>();
    const auto mu = ::NSA1::to_value<double>();
    const auto max_band_index = ::NSA1::to_value<int>();
    const auto& l_params = local_params(beta, mu, max_band_index);
    const auto G0_K12 = ::NSA2::kinetic_propagator(l_params);

    const auto s = ::NSA1::to_value<double>();

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    std::cout << "G0_K12(" << s << ") = " << G0_K12.eval(s) << std::endl;
    
    return 0;
}

