// std_bhm/src/n_k/write_n_k_array_to_file.cpp

// -----------------------------------------------------------------------

// Insert summary of file

// -----------------------------------------------------------------------


/* Include standard libraries */
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <fstream>
#include <limits>

/* Include standard libraries */

/* Non-standard third-party libraries */

/* Include user-defined header files */
#include "n_k/write_n_k_array_to_file.h"
#include "os/mkdir_p.h"



// Write quasi-momentum distribution time series to file from n_k array.
namespace NSA1 = std_bhm::n_k::write_n_k_array_to_file_detail;
namespace NSA2 = std_bhm::os;

using dbl_vec = std::vector<double>;

void NSA1::write_n_k_array_to_file(const std::string& abs_filename,
				   const dbl_vec& n_k_array,
				   double ds)
{
    const auto substr_index = abs_filename.find_last_of("/\\");
    const auto abs_directory_name = abs_filename.substr(0, substr_index);

    ::NSA2::mkdir_p( abs_directory_name.c_str() );

    std::ofstream n_k_ofstream(abs_filename);
    typedef std::numeric_limits<double> dbl_lim;
    n_k_ofstream.precision(dbl_lim::max_digits10);

    n_k_ofstream << "time" << "\t" << "n_k" << std::endl;
    n_k_ofstream << std::scientific;

    auto t = 0.0;
    for(const auto& n_k_value : n_k_array)
    {
	n_k_ofstream << t << "\t" << n_k_value << std::endl;
	t += ds;
    }

    n_k_ofstream.close();
}
