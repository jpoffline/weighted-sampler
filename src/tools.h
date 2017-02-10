//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once
#include <iostream>
#include <vector>
#include <numeric> 
#include <random>
#include <algorithm>
#include "tools_decl.h"




//----------------- Definitions of the tool helpers -----------------//


namespace JP{

template<typename T>
inline
int binary_search(const std::vector<T>& input, T target)
{
    // Perform a binary search for target on an input vector;
    // Assumes that the input is sorted.
    // Will return the index of the target.
    // If the target can't be found, -1 will be returned.
    int N = input.size() - 1;

    // Sort out special cases first
    if (target < input[0])  return 0;
    if (target >= input[N]) return N;

    int upper = N;
    int low = 0;
    int mid;
    while (upper >= low) 
    {
        mid = low + (upper - low) / 2;
        if (input[mid] == target) return mid;
        if (input[mid] < target && input[mid + 1] > target) return mid+1;
        if (input[mid] < target) low = mid + 1;
        else if (input[mid] > target) upper = mid - 1;
    }

    return -1;

}


template<typename T>
inline
bool test_equalty(T v1, T v2)
{
    // Test equality of two variables.
    return v1 == v2;
}


template<>
inline
bool test_equalty<double>(double v1, double v2)
{
    // Test equality of two variables.
    // Specialisation to the case of DOUBLE.
    return std::abs(v1 - v2) < __DBL_EPSILON__;
}


template<typename T>
std::vector<T> pdftocdf(const std::vector<T>& pdf)
{
    // Helper function to turn a PDF into a CDF.
    std::vector<T> cdf(pdf.size());
    std::partial_sum(pdf.begin(), pdf.end(), cdf.begin());
    return cdf;
}


template<typename VALUE_T>
VALUE_T sumup(const std::vector<VALUE_T>& values)
{  
    // Helper function to add up the values in a vector.
    return std::accumulate(begin(values), end(values), VALUE_T(0));
}

template<>
std::string sumup(const std::vector<std::string>& values)
{  
    // Helper function to add up the values in a vector.
    // Template-specialisation for the case of STRING.
    return std::accumulate(begin(values), end(values), std::string{""});
}


template<typename T>
void vprint(std::ostream& whereto, const std::vector<T>& vec, std::string msg)
{
    // Helper function to pretty-print the contents of a vector.
    whereto << "------------------\n";
    whereto << msg << "\n";
    for(auto& s : vec)
    {
        whereto << s << "\n";
    }
    whereto << "------------------\n";
}


}