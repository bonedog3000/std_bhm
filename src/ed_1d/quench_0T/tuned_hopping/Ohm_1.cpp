// /std_bhm/src/ed_1d/quench_0T/tuned_hopping/Ohm_1.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"
#include <armadillo>

/* Include user-defined header files */
#include "ed_1d/quench_0T/tuned_hopping/Ohm_1.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/local_params.h"
#include "ed_1d/quench_0T/nn_connectivity_mat_rep.h"
#include "ed_1d/quench_0T/local_hamiltonian_mat_rep.h"
#include "hopping/quench/amplitude.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA4 = std_bhm::hopping::quench;

struct NSA3::Ohm_1::impl
{
    impl(const ::NSA2::fock_basis& basis,
	 const ::NSA4::amplitude& J,
	 const ::NSA1::local_params& l_params,
	 double dt);

    const arma::sp_mat H_0;
    const arma::sp_mat nn_connectivity;
    const ::NSA4::amplitude& J;
    double dt;

    double integrate_J_over_time(double t) const;
};



// Ohm_1 constructor.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA4 = std_bhm::hopping::quench;

NSA3::Ohm_1::Ohm_1(const ::NSA2::fock_basis& basis,
		   const ::NSA4::amplitude& J,
		   const ::NSA1::local_params& l_params,
		   double dt)
    : pimpl{ spimpl::make_impl<impl>(basis, J, l_params, dt) }
{}



// Ohm_1::impl constructor.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;
namespace NSA4 = std_bhm::hopping::quench;

NSA3::Ohm_1::impl::impl(const ::NSA2::fock_basis& basis,
			const ::NSA4::amplitude& J,
			const ::NSA1::local_params& l_params,
			double dt)
    : H_0{ ::NSA2::local_hamiltonian_mat_rep(basis, l_params) },
      nn_connectivity{ ::NSA2::nn_connectivity_mat_rep(basis) },
      J(J),
      dt{dt}
{}



// Evaluate Ohm_1.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;

arma::sp_mat NSA3::Ohm_1::eval(double t) const
{
    const auto J_integrated = pimpl->integrate_J_over_time(t);
    return -J_integrated * pimpl->nn_connectivity + pimpl->dt * pimpl->H_0;
}



// Integrate the hopping amplitude over the next time interval.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;

double NSA3::Ohm_1::impl::integrate_J_over_time(double t) const
{
    return dt * ( J.eval(t) + 4.0 * J.eval(t + dt / 2) + J.eval(t + dt) ) / 6.0;
}



// Set timestep 'dt'.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;
namespace NSA3 = NSA2::tuned_hopping;

void NSA3::Ohm_1::set_timestep(double dt) { pimpl->dt = dt; }
