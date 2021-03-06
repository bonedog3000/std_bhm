// /std_bhm/test/lanczos/restart/explicitly/full_orthogonalization.cpp

// -----------------------------------------------------------------------

// This program serves as a unit test of the classes defined in the 
// .cpp file 'std_bhm/test/lanczos/restart/explicitly/
// full_orthogonalization.cpp'.

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <limits>
#include <cmath>
#include <iostream>

/* Non-standard third-party libraries */
#include <armadillo>

/* Include user-defined header files */
#include "lanczos/restart/explicitly/full_orthogonalization.h"
#include "ed_1d/quench_0T/tuned_hopping/main_alg_params.h"
#include "ed_1d/local_params.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/step_params.h"
#include "ed_1d/lanczos_alg_params.h"
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/quench_0T/tuned_hopping/Ohm_1.h"
#include "hopping/quench/linear/amplitude.h"
#include "hopping/quench/linear/quench_params.h"
#include "parameters/from_std_cin.h"
#include "arma_support/conv.h"



namespace NSA1 = std_bhm::parameters::from_std_cin;
namespace NSA2 = std_bhm::lanczos::restart::explicitly;
namespace NSA3 = std_bhm::ed_1d;
namespace NSA4 = NSA3::quench_0T;
namespace NSA5 = NSA4::tuned_hopping;
namespace NSA6 = std_bhm::hopping::quench::linear;
namespace NSA7 = std_bhm::arma_support;

int main(int argc, char** argv)
{
    const auto main_params = ::NSA5::main_alg_params();

    const auto& l_params = main_params.get_local_params();
    const auto& fb_params = main_params.get_fock_basis_params();
    const auto& q_params = main_params.get_quench_params();
    const auto& dt_and_Nt = main_params.get_step_params();
    const auto& la_params = main_params.get_lanczos_alg_params();

    const auto basis = ::NSA4::fock_basis(fb_params);
    const auto J = ::NSA6::amplitude(q_params);
    const auto dt = dt_and_Nt.get_dt();

    auto Ohm = ::NSA5::Ohm_1(basis, J, l_params, dt);

    const auto D = basis.get_hilbert_space_dimension();
    const auto t = ::NSA1::to_value<double>();
    auto A = ::NSA7::sp_mat_to_sp_cx_mat( Ohm.eval(t) );

    const auto seed = ::NSA1::to_value<double>();
    arma::arma_rng::set_seed(seed);
    auto x = arma::cx_dvec(D, arma::fill::randu);

    const auto p = la_params.get_krylov_dimension();
    const auto tol = la_params.get_convergence_tolerance();
    
    auto eigvals = arma::dvec();
    auto eigvecs = arma::cx_mat();
    ::NSA2::full_orthogonalization(A, x, p, eigvals, eigvecs, tol);

    typedef std::numeric_limits<double> dbl_lim;
    std::cout.precision(dbl_lim::max_digits10);

    eigvals = arma::sort(eigvals);
    eigvals.raw_print(std::cout, "\nApproximate eigenvalues:");

    const auto A_dense = arma::cx_dmat(A);
    arma::eig_sym(eigvals, eigvecs, A_dense);

    eigvals = arma::sort(eigvals);
    eigvals.raw_print(std::cout, "\n\n\nAll eigenvalues:");
    
    return 0;
}

