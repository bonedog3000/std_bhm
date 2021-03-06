// std_bhm/src/atomic_lim/equilibrium/zero_temperature/local/spectral_func.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "atomic_lim/equilibrium/local/two_pt_func.h"
#include "atomic_lim/equilibrium/zero_temperature/local/spectral_func.h"
#include "atomic_lim/equilibrium/zero_temperature/local/particle_count.h"
#include "atomic_lim/equilibrium/zero_temperature/local/energy.h"



// Partial definition of impl class
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

struct NSA1::spectral_func::impl
{
    impl(double mu);

    const double coef_term_1;
    const double coef_term_2;
    const std::complex<double> exp_term_1;
    const std::complex<double> exp_term_2;

    std::complex<double> do_eval(double t) const;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.

namespace unnamed
{
namespace
{

const double calc_coef_term_1(double mu);
const double calc_coef_term_2(double mu);
const std::complex<double> calc_exp_term_1(double mu);
const std::complex<double> calc_exp_term_2(double mu);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// spectral_func constructor
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

NSA1::spectral_func::spectral_func(double mu)
    : pimpl{ spimpl::make_impl<impl>(mu) }
{}



// spectral_func::impl constructor
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

NSA1::spectral_func::impl::impl(double mu)
    : coef_term_1{ unnamed::calc_coef_term_1(mu) },
    coef_term_2{ unnamed::calc_coef_term_2(mu) },
    exp_term_1{ unnamed::calc_exp_term_1(mu) },
    exp_term_2{ unnamed::calc_exp_term_2(mu) }
{}



// Calculate the value of impl.coef_term_1
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

namespace unnamed
{
namespace
{

const double calc_coef_term_1(double mu)
{
    const auto n0 = ::NSA1::particle_count(mu);
    return n0 + 1;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the value of impl.coef_term_2
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

namespace unnamed
{
namespace
{

const double calc_coef_term_2(double mu)
{
    const auto n0 = ::NSA1::particle_count(mu);
    return -n0;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the value of impl.exp_term_1
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

namespace unnamed
{
namespace
{

const std::complex<double> calc_exp_term_1(double mu)
{
    const auto I = std::complex<double>{0, 1};
    const auto E0_p = ::NSA1::single_particle_excitation_energy(mu);
    return -I * E0_p;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the value of impl.exp_term_2
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

namespace unnamed
{
namespace
{

const std::complex<double> calc_exp_term_2(double mu)
{
    const auto I = std::complex<double>{0, 1};
    const auto E0_h = ::NSA1::single_hole_excitation_energy(mu);
    return I * E0_h;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Wrapper function to pimpl->do_eval(...): see below for definition.
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

std::complex<double> NSA1::spectral_func::do_eval(double t) const
{ return pimpl->do_eval(t); }



// Evaluate local spectral function at time t.
namespace NSA1 = std_bhm::atomic_lim::equilibrium::zero_temperature::local;

std::complex<double> NSA1::spectral_func::impl::do_eval(double t) const
{
    return ( coef_term_1 * std::exp(exp_term_1 * t)
	     + coef_term_2 * std::exp(exp_term_2 * t) );
}
