// /std_bhm/include/ed_1d/step_evolve_mat_rep.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ED_1D_STEP_EVOLVE_MAT_REP_H
#define STD_BHM_ED_1D_STEP_EVOLVE_MAT_REP_H

/* Include standard libraries */

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */



namespace std_bhm
{
namespace ed_1d
{



class lanczos_alg_params; // forward declaration



namespace step_evolve_mat_rep_detail
{

namespace NSA1 = std_bhm::ed_1d;

arma::cx_mat step_evolve_mat_rep(const arma::sp_cx_mat& Ohm,
				 const arma::cx_dvec& current_state,
				 const NSA1::lanczos_alg_params& la_params);

arma::cx_mat step_evolve_mat_rep(const arma::cx_mat& Ohm,
				 const arma::cx_dvec& current_state);

} // end of step_evolve_mat_rep_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::ed_1d::step_evolve_mat_rep_detail::step_evolve_mat_rep;



} // end of ed_1d namespace
} // end of std_bhm namespace


#endif
 
