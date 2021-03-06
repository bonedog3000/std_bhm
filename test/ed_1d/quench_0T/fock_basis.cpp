// /std_bhm/test/ed_1d/quench_0T/fock_basis.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the classes defined in the 
// .cpp file 'std_bhm/test/ed_1d/quench_0T/fock_basis.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/fock_basis_params.h"
#include "output/vector_to_string.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::ed_1d;
namespace NSA3 = NSA2::quench_0T;
namespace NSA4 = std_bhm::output;

using int_vec = std::vector<int>;

int main(int argc, char** argv)
{
    const auto total_number_of_particles = ::NSA1::to_value<int>();
    const auto number_of_lattice_sites = ::NSA1::to_value<int>();
    const auto fb_params = ::NSA2::fock_basis_params(total_number_of_particles,
						     number_of_lattice_sites);

    const auto basis = ::NSA3::fock_basis(fb_params);
    
    std::cout << "Fock basis for a system with: "
	      << "\n  Total # of particles = " << total_number_of_particles
	      << "\n  # of lattice sites = " << number_of_lattice_sites
	      << "\n" << std::endl;

    const auto D = basis.get_hilbert_space_dimension();
    std::cout << "There are " << D << " basis states:" << std::endl;
    return 0;
    for(auto i=decltype(D){0}; i<D; i++)
    {
	const auto fock_state = basis.get_fock_state(i);
	std::cout << ::NSA4::vector_1d_to_string(fock_state) << std::endl;
    }
    
    return 0;
}

