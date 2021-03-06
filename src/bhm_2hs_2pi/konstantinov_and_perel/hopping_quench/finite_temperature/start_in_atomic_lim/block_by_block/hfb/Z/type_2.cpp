// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/Z/type_2.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/type_2.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/Z/element.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Z;

using dbl_vec = std::vector<double>;

struct NSA3::type_2::impl
{
    impl(const dbl_vec& n_array);

    const dbl_vec& n_array;
};



// type_2 constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Z;

using dbl_vec = std::vector<double>;

NSA3::type_2::type_2(const dbl_vec& n_array)
    : pimpl{ spimpl::make_impl<impl>(n_array) }
{}



// type_2::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Z;

using dbl_vec = std::vector<double>;

NSA3::type_2::impl::impl(const dbl_vec& n_array)
    : n_array(n_array)
{}



// Evaluate Z_type_2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb::Z;

double NSA3::type_2::do_eval(int l1, int l2) const
{
    const auto index = l1 - l2;
    return (3.0 * pimpl->n_array[index]
	    + 6.0 * pimpl->n_array[index - 1]
	    - 1.0 * pimpl->n_array[index - 2]) / 8.0;
}
