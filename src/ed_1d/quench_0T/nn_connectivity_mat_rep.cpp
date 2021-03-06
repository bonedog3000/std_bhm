// /std_bhm/src/ed_1d/quench_0T/nn_connectivity_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <cmath>
#include <limits>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/nn_connectivity_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d::quench_0T;

namespace unnamed
{
namespace
{

bool equal_to_integer_within_machine_precision(double x);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate matrix representation of the nearest-neighbour connectivity
// operator.
namespace NSA1 = std_bhm::ed_1d::quench_0T;
namespace NSA2 = NSA1::nn_connectivity_mat_rep_detail;

arma::sp_mat NSA2::nn_connectivity_mat_rep(const ::NSA1::fock_basis& basis)
{
    const auto D = basis.get_hilbert_space_dimension();

    auto locs = arma::umat(2, D);
    auto values = arma::dvec(D);
    
    for(auto col=decltype(D){0}; col<D; col++)
    {
	const auto fock_state = basis.get_fock_state(col);

	auto mat_elem = 0.0;
	const auto M = basis.get_number_of_lattice_sites();
	for(auto k=decltype(M){0}; k<M; k++)
	{   
	    const auto n_k = fock_state[k];
	    const auto two_pi = std::atan(1.0) * 8.0;
	    mat_elem += std::cos(two_pi * k / M) * n_k;
	}

	mat_elem *= 2.0;

	if ( ::unnamed::equal_to_integer_within_machine_precision(mat_elem) )
	    mat_elem = round(mat_elem);
	    
	values(col) = mat_elem;
	locs(0, col) = col;
	locs(1, col) = col;
    }

    return arma::sp_mat(locs, values, D, D, false, false);
}



// Check whether double is equal in value to an integer modulo machine
// precision.

namespace unnamed
{
namespace
{

bool equal_to_integer_within_machine_precision(double x)
{
    const auto tol = std::numeric_limits<double>::epsilon() * 10.0;
    const auto x_mod_1 = fmod(x, 1.0);
    
    if (std::fabs(x_mod_1) < tol)
	return true;
    else if (1 - std::fabs(x_mod_1) < tol)
	return true;
    else
	return false;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace
