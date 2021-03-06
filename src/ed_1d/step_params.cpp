// /std_bhm/ed_1d/step_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/step_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;

struct NSA1::step_params::impl
{
    impl(int Nt, double dt);

    const int Nt;
    const double dt;
};



// step_params constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::step_params::step_params(int Nt, double dt)
    : pimpl{ spimpl::make_impl<impl>(Nt, dt) }
{}



// step_params::impl constructor.
namespace NSA1 = std_bhm::ed_1d;

NSA1::step_params::impl::impl(int Nt, double dt)
    : Nt{Nt}, dt{dt}
{}



// Get # of time steps Nt.
namespace NSA1 = std_bhm::ed_1d;

int NSA1::step_params::get_Nt() const { return pimpl->Nt; }



// Get time stepsize dt.
namespace NSA1 = std_bhm::ed_1d;

double NSA1::step_params::get_dt() const { return pimpl->dt; }
