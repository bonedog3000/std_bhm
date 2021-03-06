// /std_bhm/src/ed_1d/quench_0T/local_hamiltonian_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/local_hamiltonian_mat_rep.h"
#include "ed_1d/quench_0T/unit_strength_interaction_mat_rep.h"
#include "ed_1d/quench_0T/total_particle_number_mat_rep.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/local_params.h"



// Generate matrix representation of the interaction part of the BHM
// Hamiltonian where the interaction strength 'U' is set to unity.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::local_hamiltonian_mat_rep_detail;

arma::sp_mat NSA3::local_hamiltonian_mat_rep
                       (const ::NSA2::fock_basis& basis,
			const ::NSA1::local_params& l_params)
{
    const auto U = l_params.get_U();
    const auto mu = l_params.get_mu();
    
    auto H_0 = arma::sp_mat();
    H_0 = U * ::NSA2::unit_strength_interaction_mat_rep(basis);
    H_0 -= mu * ::NSA2::total_particle_number_mat_rep(basis);

    return H_0;
}
