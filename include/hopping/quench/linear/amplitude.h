// std_bhm/include/hopping/quench/linear/amplitude.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_HOPPING_QUENCH_LINEAR_AMPLITUDE_H
#define STD_BHM_HOPPING_QUENCH_LINEAR_AMPLITUDE_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "hopping/quench/amplitude.h" 



namespace std_bhm
{
namespace hopping
{
namespace quench
{
namespace linear
{

struct quench_params; // forward declaration

namespace amplitude_detail
{

namespace NS1 = std_bhm::hopping::quench;
namespace NS2 = NS1::linear;

class amplitude: public NS1::amplitude
{
public:
    amplitude(const NS2::quench_params& q_params);

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;

    virtual double do_eval(double t) const;
};

} // end of amplitude_detail namespace

// lift relevant classes and functions up one namespace
using std_bhm::hopping::quench::linear::amplitude_detail::amplitude;

} // end of linear namespace
} // end of quench namespace
} // end of hopping namespace
} // end of std_bhm namespace


#endif
 
