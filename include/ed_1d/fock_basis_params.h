// /std_bhm/include/ed_1d/fock_basis_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_FOCK_BASIS_PARAMS_H
#define STD_BHM_ED_1D_FOCK_BASIS_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{

class fock_basis_params
{
public:
    fock_basis_params(int total_number_of_particles,
		      int number_of_lattice_sites);

    int get_total_number_of_particles() const;
    int get_number_of_lattice_sites() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
