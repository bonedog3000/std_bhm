// std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/u1.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/zero_temperature/u1.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "atomic_lim/equilibrium/zero_temperature/static_lim/local/\
retarded_propagator.h"
#include "atomic_lim/equilibrium/zero_temperature/local/energy.h"



// Calculate the u1, which is a constant that comes out of the static limit 
// of the u-vertex in the BHM-2HS-2PI theory.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::zero_temperature;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::zero_temperature;
namespace NSA3 = NSA2::local;
namespace NSA4 = NSA2::static_lim::local;

double NSA1::u1(double mu)
{
    const auto n = ::NSA3::particle_count(mu);
    const auto nP1 = n + 1;
    const auto nP2 = n + 2;
    const auto nM1 = n - 1;

    const auto E0_p = ::NSA3::single_particle_excitation_energy(mu);
    const auto E0_h = ::NSA3::single_hole_excitation_energy(mu);
    const auto E0_2p = ::NSA3::n_particle_excitation_energy(2, mu);
    const auto E0_2h = ::NSA3::n_hole_excitation_energy(2, mu);

    const auto G0_R12_w0 = ::NSA4::retarded_propagator(mu);

    return ( -2 / G0_R12_w0 / G0_R12_w0 / G0_R12_w0 / G0_R12_w0
	     * (nP1 * nP2 / E0_2p / E0_p / E0_p 
		+ n * nM1 / E0_2h / E0_h / E0_h
		- nP1 * nP1 / E0_p / E0_p / E0_p 
		- n * n / E0_h / E0_h / E0_h
		- n * nP1 / E0_p / E0_h / E0_h 
		- n * nP1 / E0_p / E0_p / E0_h) );
}
