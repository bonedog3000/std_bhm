// /std_bhm/test/ed_1d/quench_0T/nn_connectivity_mat_rep.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the functions defined in the 
// .cpp file 'std_bhm/test/ed_1d/quench_0T/nn_connectivity_mat_rep.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <iostream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "ed_1d/quench_0T/nn_connectivity_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/fock_basis_params.h"
#include "parameters/from_std_cin.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::ed_1d;
namespace NSA3 = NSA2::quench_0T;

using int_vec = std::vector<int>;

int main(int argc, char** argv)
{
    const auto total_number_of_particles = ::NSA1::to_value<int>();
    const auto number_of_lattice_sites = ::NSA1::to_value<int>();
    const auto fb_params = ::NSA2::fock_basis_params(total_number_of_particles,
						     number_of_lattice_sites);

    const auto basis = ::NSA3::fock_basis(fb_params);
    const auto nn_connectivity = ::NSA3::nn_connectivity_mat_rep(basis);
    
    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);
    
    std::cout << "Nearest neighbour connectivity matrix representation with: "
	      << "\n  Total # of particles = " << total_number_of_particles
	      << "\n  # of lattice sites = " << number_of_lattice_sites
	      << "\n" << std::endl;

    nn_connectivity.raw_print(std::cout, "\nMatrix rep:");
    
    return 0;
}

