// /std_bhm/src/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/step_params.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "bhm_2hs_2pi/konstantinov_and_perel/hopping_quench/finite_temperature/\
start_in_atomic_lim/block_by_block/hfb/step_params.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

struct NSA3::step_params::impl
{
    impl(int n_block_steps, double ds, int window_index);

    const int n_block_steps;
    const double ds;
    const int window_index;
};



// step_params constructor #1.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::step_params::step_params(int n_block_steps, double ds)
    : pimpl{ spimpl::make_impl<impl>(n_block_steps, ds, n_block_steps) }
{}



// step_params constructor #2.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::step_params::step_params(int n_block_steps, double ds, int window_index)
    : pimpl{ spimpl::make_impl<impl>(n_block_steps, ds, window_index) }
{}



// step_params::impl constructor.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

NSA3::step_params::impl::impl(int n_block_steps, double ds, int window_index)
    : n_block_steps{n_block_steps}, ds{ds}, window_index{window_index}
{}



// Get # of time steps n_block_steps.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

int NSA3::step_params::get_n_block_steps() const
{
    return pimpl->n_block_steps;
}



// Get time stepsize ds.
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

double NSA3::step_params::get_ds() const { return pimpl->ds; }



// Get window index (m_W).
namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

int NSA3::step_params::get_window_index() const
{
    return pimpl->window_index;
}
