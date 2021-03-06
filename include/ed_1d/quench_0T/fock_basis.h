// /std_bhm/include/ed_1d/quench_0T/fock_basis.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_QUENCH_0T_FOCK_BASIS_H
#define STD_BHM_ED_1D_QUENCH_0T_FOCK_BASIS_H

/* Include standard libraries */
#include <memory>
#include <vector>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{



class fock_basis_params; // forward declaration



namespace quench_0T
{
namespace fock_basis_detail
{

namespace NSA1 = std_bhm::ed_1d;

using int_vec = std::vector<int>;

class fock_basis
{
public:
    fock_basis(const NSA1::fock_basis_params& fb_params);

    int get_hilbert_space_dimension() const;
    int get_total_number_of_particles() const;
    int get_number_of_lattice_sites() const;

    int_vec get_fock_state(int i) const;
    int find_fock_state(int_vec fock_state) const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of fock_basis_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::quench_0T::fock_basis_detail::fock_basis;



} // end of quench_0T namespace
} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
