// std_bhm/src/atomic_lim/equilibrium/finite_temperature/local
// /partition_func.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <cmath>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/equilibrium/finite_temperature/local/partition_func.h"
#include "atomic_lim/local/params.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "atomic_lim/local/energy.h"



// Calculate the partition function.
namespace NSA1 = std_bhm::atomic_lim::equilibrium::finite_temperature::local;
namespace NSA2 = NSA1::partition_func_detail;
namespace NSA3 = std_bhm::atomic_lim::local;
namespace NSA4 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

using local_params = std_bhm::atomic_lim::local::params;

double NSA2::partition_func(const local_params& l_params)
{
    const auto mu = l_params.get_mu();
    const auto beta = l_params.get_beta();
    const auto max_band_index = l_params.get_max_band_index();
    
    const auto E0_n0 = ::NSA3::ground_state_energy(mu);
    const auto n0 = ::NSA4::particle_count(mu);
    const auto temp_1 = beta * (E0_n0 - n0 * mu);

    auto Z0 = 0.0;

    for(auto m=decltype(max_band_index){0}; m<max_band_index; m++)
    {
	const auto E0_m = ::NSA3::energy(m);
	const auto temp_2 = beta * (E0_m - m * mu);
	Z0 += std::exp(temp_1 - temp_2);
    }

    return Z0;
}
