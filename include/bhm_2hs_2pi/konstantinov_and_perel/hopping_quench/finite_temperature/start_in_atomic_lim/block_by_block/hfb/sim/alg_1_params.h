// std_bhm/include/bhm_2hs_2pi/konstantinov_and_perel/hopping_quench
// /finite_temperature/start_in_atomic_lim/block_by_block/hfb/sim
// /alg_1_params.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_SIM_ALG_1_PARAMS_H
#define STD_BHM_BHM_2HS_2PI_KONSTANTINOV_AND_PEREL_HOPPING_QUENCH_\
FINITE_TEMPERATURE_START_IN_ATOMIC_LIM_BLOCK_BY_BLOCK_HFB_SIM_ALG_1_PARAMS_H

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

namespace hopping
{

class spatial_params; // forward declaration

namespace quench
{
namespace linear
{

class quench_params; // forward declaration

}
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



namespace sim
{
namespace alg_1_params_detail
{

namespace NSA1 = std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench;
namespace NSA2 = NSA1::finite_temperature::start_in_atomic_lim::block_by_block;
namespace NSA3 = NSA2::hfb;

namespace NSA4 = std_bhm::hopping;
namespace NSA5 = NSA4::quench::linear;

using local_params = std_bhm::atomic_lim::local::params;

class alg_1_params
{
public:
    alg_1_params();

    local_params get_local_params() const;
    NSA4::spatial_params get_spatial_params() const;
    NSA5::quench_params get_quench_params() const;
    NSA3::step_params get_step_params() const;
    double get_convergence_tolerance() const;

private:
    class impl;
    spimpl::impl_ptr<impl> pimpl;
};

} // end of alg_1_params_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::bhm_2hs_2pi::konstantinov_and_perel::hopping_quench::\
finite_temperature::start_in_atomic_lim::block_by_block::hfb::sim::\
alg_1_params_detail::alg_1_params;



} // end of sim namespace
} // end of hfb namespace
} // end of block_by_block namespace
} // end of start_in_atomic_lim namespace
} // end of finite_temperature namespace
} // end of hopping_quench namespace
} // end of konstantinov_and_perel namespace
} // end of bhm_2hs_2pi namespace
} // end of std_bhm namespace


#endif
 
