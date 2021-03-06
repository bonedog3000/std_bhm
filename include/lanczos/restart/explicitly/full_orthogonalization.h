// /std_bhm/include/lanczos/restart/explicitly/full_orthogonalization.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_LANCZOS_RESTART_EXPLICITLY_FULL_ORTHOGONALIZATION_H
#define STD_BHM_LANCZOS_RESTART_EXPLICITLY_FULL_ORTHOGONALIZATION_H

/* Include standard libraries */
#include <cmath>
#include <limits>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */



namespace std_bhm
{
namespace lanczos
{
namespace restart
{
namespace explicitly
{
namespace full_orthogonalization_detail
{

const auto epsilon = std::numeric_limits<double>::epsilon();

void full_orthogonalization( const arma::sp_cx_mat& A,
			     arma::cx_dvec x,
			     int p,
			     arma::dvec& eigvals,
			     arma::cx_mat& eigvecs,
			     double tol=pow(epsilon, 1.0/3.0) );

} // end of full_orthogonalization_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::lanczos::restart::explicitly::full_orthogonalization_detail::\
full_orthogonalization;



} // end of explicitly namespace
} // end of restart namespace
} // end of lanczos namespace
} // end of std_bhm namespace


#endif
 
