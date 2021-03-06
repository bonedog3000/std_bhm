// std_bhm/src/n_k/load_n_k_data_array.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------

/* Include standard libraries */
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/load_n_k_data_array.h"



// Load quasi-momentum distribution (i.e. n_k) data file for a given sequence
// of k-integers.
namespace NSA1 = std_bhm::n_k::load_n_k_data_array_detail;

using int_vec = std::vector<int>;
using dbl_vec = std::vector<double>;

dbl_vec NSA1::load_n_k_data_array(const int_vec& k_ints,
				  const std::string& abs_sys_data_set_dir_name)
{
    auto abs_filename = abs_sys_data_set_dir_name + "/n_k data/k-vector";
    for(const auto& k_int : k_ints)
	abs_filename += " " + std::to_string(k_int);
    abs_filename += ".txt";

    std::ifstream n_k_ifstream( abs_filename.c_str() );

    auto n_k_array = dbl_vec();
    auto line = std::string();
    std::getline(n_k_ifstream, line); // skip first line: no data
    while( getline(n_k_ifstream, line) )
    {
	std::istringstream ss(line);
	auto time = double();
	auto n_k_value = double();
	ss >> time;
	ss >> n_k_value;
	n_k_array.push_back(n_k_value);
    }

    return n_k_array;
}
