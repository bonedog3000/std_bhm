// /std_bhm/include/ed_1d/lanczos_alg_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_LANCZOS_ALG_PARAMS_H
#define STD_BHM_ED_1D_LANCZOS_ALG_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{

class lanczos_alg_params
{
public:
    lanczos_alg_params(int krylov_dimension, double convergence_tolerance);

    int get_krylov_dimension() const;
    double get_convergence_tolerance() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
