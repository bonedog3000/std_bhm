// std_bhm/src/hopping/quench/linear/amplitude.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <memory>
#include <cmath>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "hopping/quench/amplitude.h"
#include "hopping/quench/linear/quench_params.h" 
#include "hopping/quench/linear/amplitude.h"



// Partial definition of impl class
namespace NSA1 = std_bhm::hopping::quench::linear;

struct NSA1::amplitude::impl
{
    impl(const ::NSA1::quench_params& q_params);

    const double ji; // initial value of hopping amplitude
    const double jf; // final value of hopping amplitude
    const double tc; // time marking the halfway point of the hopping quench
    const double tau_Q; // quench timescale -> determines speed of quench

    double do_eval(double t) const;
};



// amplitude constructor
NSA1::amplitude::amplitude(const ::NSA1::quench_params& q_params)
    : pimpl{ spimpl::make_impl<impl>(q_params) }
{}



// amplitude::impl constructor
namespace NSA1 = std_bhm::hopping::quench::linear;

NSA1::amplitude::impl::impl(const ::NSA1::quench_params& q_params)
    : ji{ q_params.get_ji() }, jf{ q_params.get_jf() },
      tc{ q_params.get_tc() }, tau_Q{ q_params.get_tau_Q() }
{}



// Wrapper function to pimpl->do_eval(...): see above for definition.
namespace NSA1 = std_bhm::hopping::quench::linear;

double NSA1::amplitude::do_eval(double t) const { return pimpl->do_eval(t); }



// Evaluate hopping amplitude at time t.
double NSA1::amplitude::impl::do_eval(double t) const
{
    return 0.5 * ( (jf - ji) * std::tanh( (t-tc) / tau_Q ) + (jf + ji) );
}
