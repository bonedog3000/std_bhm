// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/k_eqn/params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_K_EQN_PARAMS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_K_EQN_PARAMS_H

/* Include standard libraries */
#include <memory>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */



namespace std_bhm
{



namespace atomic_lim
{
namespace local
{
class params; // forward declaration
}
}



namespace bhm_2hs_2pi
{
namespace konstantinov_and_perel
{
namespace hopping_quench
{
namespace finite_temperature
{
namespace start_in_atomic_lim
{
namespace block_by_block
{
namespace hfb
{



class step_params; // forward declaration

namespace epsilon_params_detail
{
class epsilon_params; // forward declaration
}



namespace k_eqn
{
namespace params_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;
namespace NSA4 = NSA3::epsilon_params_detail;

using local_params = std_bhm::atomic_lim::local::params;

class params
{
public:
    params(const local_params& l_params,
		 const NSA4::epsilon_params& e_params,
		 const NSA3::step_params& s_params);

    local_params get_local_params() const;
    NSA4::epsilon_params get_epsilon_params() const;
    NSA3::step_params get_step_params() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of params_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::k_eqn::\
params_detail::params;



} // end of k_eqn namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
