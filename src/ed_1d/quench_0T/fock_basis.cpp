// /std_bhm/src/ed_1d/quench_0T/fock_basis.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>
#include <vector>
#include <algorithm>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"
#include <boost/math/special_functions/binomial.hpp>

/* Include user-defined header files */
#include "ed_1d/quench_0T/fock_basis.h"
#include "ed_1d/fock_basis_params.h"
#include "ed_1d/tag.h"
#include "ed_1d/sorted_array.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

struct NSA2::fock_basis::impl
{
    impl(const ::NSA1::fock_basis_params& fb_params);

    const int_vec_2d fock_states;
    
    const int hilbert_space_dimension;
    const int N;
    const int M;

    const ::NSA1::sorted_array sorted_tags;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;

namespace unnamed
{
namespace
{

int_vec_2d calc_fock_states(const ::NSA1::fock_basis_params& fb_params);
int_vec calc_next_state(int N, int M, const int_vec& previous_state);
int calc_k(int M, const int_vec& previous_state);
int total_momentum(const int_vec& fock_state);
bool greater_than_or_equal_to_reflection(const int_vec& fock_state);
::NSA1::sorted_array calc_sorted_tag_array
                                 (const int_vec_2d& fock_states);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// fock_basis constructor.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

NSA2::fock_basis::fock_basis(const ::NSA1::fock_basis_params& fb_params)
    : pimpl{ spimpl::make_impl<impl>(fb_params) }
{}



// fock_basis::impl constructor.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

NSA2::fock_basis::impl::impl(const ::NSA1::fock_basis_params& fb_params)
    : fock_states{ ::unnamed::calc_fock_states(fb_params) },
      hilbert_space_dimension( fock_states.size() ),
      N{ fb_params.get_total_number_of_particles() },
      M{ fb_params.get_number_of_lattice_sites() },
      sorted_tags{ ::unnamed::calc_sorted_tag_array(fock_states) }
{}



// Calculate the fock states.
namespace NSA1 = std_bhm::ed_1d;

using int_vec = std::vector<int>;
using int_vec_2d = std::vector<int_vec>;
const auto binom = boost::math::binomial_coefficient<double>;

namespace unnamed
{
namespace
{

int_vec_2d calc_fock_states(const ::NSA1::fock_basis_params& fb_params)
{
    auto fock_states = int_vec_2d();

    const auto N = fb_params.get_total_number_of_particles();
    const auto M = fb_params.get_number_of_lattice_sites();
    
    auto first_state = int_vec(M, 0);
    first_state[0] = N;
    fock_states.push_back(first_state);

    const auto D = int( round( binom(N + M - 1, N) ) );
    if (M > 2)
	fock_states.reserve(D / (M - 2) / 2);
    else
	fock_states.reserve(D);

    auto previous_state = first_state;
    for(auto v=decltype(D){1}; v<D; v++)
    {
	const auto next_state
	    = ::unnamed::calc_next_state(N, M, previous_state);
	const auto K = ::unnamed::total_momentum(next_state);

	if (K == 0)
	    if ( ::unnamed::greater_than_or_equal_to_reflection(next_state) )
		fock_states.push_back(next_state);
	
	previous_state = next_state;
    }

    fock_states.shrink_to_fit();

    return fock_states;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the next fock state.
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

int_vec calc_next_state(int N, int M, const int_vec& previous_state)
{

    const auto k = ::unnamed::calc_k(M, previous_state);
    
    auto next_state = int_vec(M);
    auto sum = 0;
	
    if (1 <= k)
    {
	for(auto i=decltype(k-1){0}; i<=k-1; i++)
	{
	    const auto n_i = previous_state[i];
	    next_state[i] = n_i;
	    sum += n_i;
	}
    }

    next_state[k] = previous_state[k] - 1;
    next_state[k+1] = N - sum - next_state[k];

    if (k + 2 < M)
    {
	for(auto i=decltype(M){k+2}; i<M; i++)
	{
	    next_state[i] = 0;
	}
    }

    return next_state;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the k-index used in the algorithm to construct the fock basis.
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

int calc_k(int M, const int_vec& previous_state)
{

    auto k = 0;

    for(auto i=decltype(M-1){0}; i<M-1; i++)
    {
	const auto n_k = previous_state[i];
	if (n_k != 0) { k = i; }
    }

    return k;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the total momentum of a given fock state.
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

int total_momentum(const int_vec& fock_state)
{
    auto K = 0;
    const auto M = fock_state.size();
    for(auto k = decltype(M){0}; k<M; k++)
	K += k * fock_state[k];

    K = K % M;
    return K;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Check whether fock state is lexographically greater than or equal to
// reflection.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

bool greater_than_or_equal_to_reflection(const int_vec& fock_state)
{
    auto reflected_state = fock_state;
    std::reverse( reflected_state.begin()+1, reflected_state.end() );
    
    const auto tag_1 = ::NSA1::gen_fock_state_tag(fock_state);
    const auto tag_2 = ::NSA1::gen_fock_state_tag(reflected_state);

    if (tag_1 <= tag_2)
	return true;
    else
	return false;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Calculate the sorted tag array used to search for fock states in basis set.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

::NSA1::sorted_array calc_sorted_tag_array(const int_vec_2d& fock_states)
{
    const auto tags = ::NSA1::gen_fock_state_tags(fock_states);
    return ::NSA1::sorted_array(tags);
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Get Hilbert space dimension.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

int NSA2::fock_basis::get_hilbert_space_dimension() const
{
    return pimpl->hilbert_space_dimension;
}



// Get total number of particles 'N'.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

int NSA2::fock_basis::get_total_number_of_particles() const
{
    return pimpl->N;
}



// Get number of lattice sites 'M'.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

int NSA2::fock_basis::get_number_of_lattice_sites() const
{
    return pimpl->M;
}



// Get the ith fock state.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

int_vec NSA2::fock_basis::get_fock_state(int i) const
{
    return pimpl->fock_states[i];
}



// Return index to fock state of interest.
namespace NSA1 = std_bhm::ed_1d;
namespace NSA2 = NSA1::quench_0T;

using int_vec = std::vector<int>;

int NSA2::fock_basis::find_fock_state(int_vec fock_state) const
{
    if ( ! unnamed::greater_than_or_equal_to_reflection(fock_state) )
	std::reverse( fock_state.begin()+1, fock_state.end() );
    
    const auto tag = ::NSA1::gen_fock_state_tag(fock_state);
    
    return pimpl->sorted_tags.where_in_unsorted(tag);
}
