// /std_bhm/include/arma_support/conv.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

#ifndef STD_BHM_ARMA_SUPPORT_CONV_H
#define STD_BHM_ARMA_SUPPORT_CONV_H

/* Include standard libraries */
#include <vector>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */



namespace std_bhm
{
namespace arma_support
{
namespace conv_detail
{

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

arma::umat std_int_vec_2d_to_arma_umat(const int_vec_2d& std_mat);
arma::umat locs_std_to_locs_arma(const int_vec& locs_std);

arma::cx_dvec dvec_to_cx_dvec(const arma::dvec& vec);
arma::sp_cx_mat sp_mat_to_sp_cx_mat(const arma::sp_mat& mat);

} // end of conv_detail namespace



// lift relevant classes and functions up one namespace
using std_bhm::arma_support::conv_detail::std_int_vec_2d_to_arma_umat;
using std_bhm::arma_support::conv_detail::locs_std_to_locs_arma;

using std_bhm::arma_support::conv_detail::dvec_to_cx_dvec;
using std_bhm::arma_support::conv_detail::sp_mat_to_sp_cx_mat;



} // end of arma_support namespace
} // end of std_bhm namespace


#endif
 
