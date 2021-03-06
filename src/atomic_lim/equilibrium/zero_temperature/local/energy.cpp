// std_bhm/src/atomic_lim/equilibrium/zero_temperature/local/energy.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "atomic_lim/local/energy.h"
#include "atomic_lim/equilibrium/zero_temperature/local/energy.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"



// Calculate the local single-particle excitation energy (in the atomic limit)
// at zero temperature for a system with chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

double NSA2::single_particle_excitation_energy(double mu)
{
    const auto m = ::NSA2::particle_count(mu);
    return ::NSA1::single_particle_excitation_energy(m, mu);
}



// Calculate the local single-hole excitation energy (in the atomic limit)
// at zero temperature for a system with chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

double NSA2::single_hole_excitation_energy(double mu)
{
    const auto m = ::NSA2::particle_count(mu);
    return ::NSA1::single_hole_excitation_energy(m, mu);
}



// Calculate the local n-particle excitation energy (in the atomic limit)
// at zero temperature for a system with chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

double NSA2::n_particle_excitation_energy(int n, double mu)
{
    const auto m = ::NSA2::particle_count(mu);
    return ::NSA1::n_particle_excitation_energy(n, m, mu);
}



// Calculate the local n-hole excitation energy (in the atomic limit)
// at zero temperature for a system with chemical potential 'mu'.
namespace NSA1 = std_bhm::atomic_lim::local;
namespace NSA2 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

double NSA2::n_hole_excitation_energy(int n, double mu)
{
    const auto m = ::NSA2::particle_count(mu);
    return ::NSA1::n_hole_excitation_energy(n, m, mu);
}
