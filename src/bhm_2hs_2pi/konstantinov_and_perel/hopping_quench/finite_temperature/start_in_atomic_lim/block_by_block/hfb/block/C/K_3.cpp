// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/block
// /C/K_3.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/C/K_3.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/block/builder_set.h"

#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/element.h"
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/M/set.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::C;

namespace NSA6 = NSA3::M;

struct NSA5::K_3::impl
{
    impl(const ::NSA4::builder_set& block_builder_set);

    const ::NSA6::element M_rho_K_4;
    const ::NSA6::element M_rho_K_5;
};



// K_3 constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::C;

NSA5::K_3::K_3(const ::NSA4::builder_set& block_builder_set)
    : pimpl{ spimpl::make_impl<impl>(block_builder_set) }
{}



// builder_set::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::C;

NSA5::K_3::impl::impl(const ::NSA4::builder_set& block_builder_set)
    : M_rho_K_4{ ( block_builder_set.get_M_set() ).get_rho_K_4() },
      M_rho_K_5{ ( block_builder_set.get_M_set() ).get_rho_K_5() }
{}



// Evaluate C-matrix.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::block;
namespace NSA5 = NSA4::C;

using cmplx_dbl = std::complex<double>;
using cmplx_vec = std::vector<cmplx_dbl>;

cmplx_vec NSA5::K_3::do_eval(int m1, int m2) const
{
    const auto& M_rho_K_4 = pimpl->M_rho_K_4;
    const auto& M_rho_K_5 = pimpl->M_rho_K_5;
    
    auto C_K_3 = cmplx_vec(4);

    C_K_3[0] = (m1 != 0 ? M_rho_K_4.eval(2*m1, 2*m2+1, 2*m1) / 3.0 : 0.0);
    C_K_3[1] = 0.0;
    C_K_3[2] = (M_rho_K_4.eval(2*m1+1, 2*m2+1, 2*m1) / 2.0
		  + M_rho_K_5.eval(2*m1+1, 2*m2+1, 2*m1) / 2.0);
    C_K_3[3] = (M_rho_K_4.eval(2*m1+1, 2*m2+1, 2*m1+1) / 6.0
		  + M_rho_K_5.eval(2*m1+1, 2*m2+1, 2*m1) / 4.0);
    
    return C_K_3;
}
