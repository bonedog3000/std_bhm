// /std_bhm/src/ed_1d/sorted_array.h

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

/* Non-standard third-party libraries */
#include "third_party/spimpl.h"

/* Include user-defined header files */
#include "ed_1d/sorted_array.h"



// Partial definition of impl class.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

struct NSA1::sorted_array::impl
{
    impl(const dbl_vec& data);

    const int_vec sorted_to_unsorted_map;
    const dbl_vec sorted_data;
};



// The 'unnamed' namespace is introduced to make it clear to the reader
// of this code which functions belong to this translation unit's true 
// unnamed namespace.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

int_vec calc_sorted_to_unsorted_map(const dbl_vec& data);
dbl_vec sort_array(dbl_vec data);

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// sorted_array constructor.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;

NSA1::sorted_array::sorted_array(const dbl_vec& data)
    : pimpl{ spimpl::make_impl<impl>(data) }
{}



// sorted_array::impl constructor.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;

NSA1::sorted_array::impl::impl(const dbl_vec& data)
    : sorted_to_unsorted_map( ::unnamed::calc_sorted_to_unsorted_map(data) ),
      sorted_data( ::unnamed::sort_array(data) )
{}



// Calculate the mapping array between the sorted and unsorted data.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;
using int_vec = std::vector<int>;

namespace unnamed
{
namespace
{

int_vec calc_sorted_to_unsorted_map(const dbl_vec& data)
{
    const auto data_size = data.size();
    auto sorted_to_unsorted_map = int_vec(data_size);
    std::iota(sorted_to_unsorted_map.begin(), sorted_to_unsorted_map.end(), 0);

    std::sort( sorted_to_unsorted_map.begin(),
	       sorted_to_unsorted_map.end(),
	       [&data](int i, int j) { return data[i] < data[j]; } );

    return sorted_to_unsorted_map;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Sort array in ascending order.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;

namespace unnamed
{
namespace
{

dbl_vec sort_array(dbl_vec data)
{
    std::sort( data.begin(), data.end() );

    return data;
}

} // end of true unnamed namespace
} // end of 'phony' unnamed namespace



// Return index of element 'elem' found in original unsorted array.
namespace NSA1 = std_bhm::ed_1d;

using dbl_vec = std::vector<double>;

int NSA1::sorted_array::where_in_unsorted(double elem, double tol) const
{
    auto it = dbl_vec::const_iterator();
    it = std::find_if( pimpl->sorted_data.begin(),
		       pimpl->sorted_data.end(),
		       [elem, tol](double x) { return fabs(x - elem) < tol; } );
    const auto idx_from_sorted = it - pimpl->sorted_data.begin();

    if (idx_from_sorted == -1) { return -1; }

    const auto idx_from_unsorted = pimpl->sorted_to_unsorted_map[idx_from_sorted];
    return idx_from_unsorted;
}
