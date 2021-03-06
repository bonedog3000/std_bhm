// std_bhm/src/output/vector_to_string.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <string>
#include <complex>

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "output/vector_to_string.h"



// Convert real-valued 1D vector into a string suitable for easy output.
namespace NSA1 = std_bhm::output::vector_to_string_detail;

template <class T>
using vector_1d = std::vector<T>;

template <class T>
std::string NSA1::vector_1d_to_string(vector_1d<T> vec_1d)
{
    std::string str = "(";
    for(const auto& i : vec_1d)
	str += std::to_string(i) + ", ";
    str = str.substr(0, str.size() - 2) + ")";

    return str;
}



// Convert complex-valued 1D vector into a string suitable for easy output.
namespace NSA1 = std_bhm::output::vector_to_string_detail;

template <class T>
using vector_1d = std::vector<T>;

template <class T>
std::string NSA1::vector_1d_to_string(vector_1d< std::complex<T> > vec_1d)
{
    std::string str = "(";
    for(const auto& i : vec_1d)
    {
	str += std::to_string( i.real() ) + "+" ;
	str += std::to_string( i.imag() ) + "i, ";
    }
    str = str.substr(0, str.size() - 2) + ")";

    return str;
}



// Convert 2D vector (i.e. matrix) into a string suitable for easy output.
namespace NSA1 = std_bhm::output::vector_to_string_detail;

template <class T>
using vector_2d = std::vector< std::vector<T> >;

template <class T>
std::string NSA1::vector_2d_to_string(vector_2d<T> vec_2d)
{
    std::string str = "(";
    for(const auto& i : vec_2d)
	str += NSA1::vector_1d_to_string(i) + "\n ";
    str = str.substr(0, str.size() - 2) + ")";

    return str;
}



// Explicit instantiations of the free public functions

// --- Explicit instantions of vector_1d_to_string(...) ---
namespace NSA1 = std_bhm::output::vector_to_string_detail;

template <class T>
using vector_1d = std::vector<T>;

template std::string 
NSA1::vector_1d_to_string(vector_1d<int> vec_1d);
template std::string 
NSA1::vector_1d_to_string(vector_1d<double> vec_1d);
template std::string 
NSA1::vector_1d_to_string(vector_1d< std::complex<int> > vec_1d);
template std::string 
NSA1::vector_1d_to_string(vector_1d< std::complex<double> > vec_1d);

// --- Explicit instantions of vector_2d_to_string(...) ---
namespace NSA1 = std_bhm::output::vector_to_string_detail;

template <class T>
using vector_2d = std::vector< std::vector<T> >;

template std::string 
NSA1::vector_2d_to_string(vector_2d<int> vec_2d);
template std::string 
NSA1::vector_2d_to_string(vector_2d<double> vec_2d);
template std::string 
NSA1::vector_2d_to_string(vector_2d< std::complex<int> > vec_2d);
template std::string 
NSA1::vector_2d_to_string(vector_2d< std::complex<double> > vec_2d);
