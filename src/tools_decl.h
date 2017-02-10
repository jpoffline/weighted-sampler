//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once
#include <vector>

//----------------- Declarations of the tool helpers -----------------//

namespace JP{

// Turn a PDF into a CDF.
template<typename T>
std::vector<T> pdftocdf(const std::vector<T>& pdf);

// Pretty-print the contents of a vector.
template<typename T>
void vprint(std::ostream& whereto, const std::vector<T>& vec, std::string msg);

// Add the contents of a vector.
template<typename VALUE_T>
VALUE_T sumup(const std::vector<VALUE_T>& values);

// Test equality of two variables.
template<typename T>
bool test_equalty(T v1, T v2);

// Binary search.
template<typename T>
int binary_search(const std::vector<T>& input, T target);


}