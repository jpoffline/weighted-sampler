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
#include "tools.h"
#include "random_number_generator.h"
#include "exception.h"
#include "solution_decl.h"


//----------------- Definitions of the solution-class -----------------//

namespace JP{


template<typename CHOICES_t>
inline
nextNum<CHOICES_t>::nextNum()
{
    // Default constructor.
}


template<typename CHOICES_t>
inline
nextNum<CHOICES_t>::nextNum(
    std::vector<CHOICES_t> in_choices, 
    std::vector<NUMERIC> in_pdf
) 
    : choices(in_choices), pdf(in_pdf)
{    
    // Parameterised constructor.

    // Validate the inputted PDF; 
    if(!validate_pdf())
    {
        throw JP::EXCEPTION("Invalid pdf");
    }

    // Validate the PDF against the choices vector; they should be the same length.
    if(!validate_pdf_choices_compatible())
    {
        throw JP::EXCEPTION("Choices and PDF vectors are of different lengths");
    }

    // Calculate the CDF
    calc_cdf();

}


template<typename CHOICES_t>
inline
nextNum<CHOICES_t>::~nextNum()
{
    // Default destructor.
}


template<typename CHOICES_t>
inline
CHOICES_t nextNum<CHOICES_t>::_gen_sample()
{

    // Method to generate a sample from the provided pdf.

    // - get a uniform random number
    // - find the corresponding index in the cdf
    // - return the corresponding choice
    int tgtidx = binary_search<NUMERIC>(
        cdf, 
        rng.get_uniform()
    );

    return choices[tgtidx];
}


template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::_gen_samples(
    int N
){
    // Private method to generate N samples from the PDF.

    // Sanity check the pdf;
    // if it's empty, throw an exception.
    if(pdf.size() == 0)
    {
        throw JP::EXCEPTION("No PDF has been supplied");
    }

    // Generate as many samples as required;
    // Store them in a vector.
    for(auto i = 0; i < N; i++)
    {
        samples.push_back(_gen_sample());
    }
}


template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::_print_choices(
    std::ostream& whereto
){
    // Private method to pretty-print the choices and their probabilities
    // to a provided ostream.
    whereto << "-----------------\n";
    whereto << "Choices:" << "\n";
    for(int i = 0; i < choices.size(); i++)
    {
        whereto << "P(" << choices[i] << ") = " << pdf[i] * 100 << "%"<< "\n";
    }
    whereto << "-----------------\n";
}


template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::print_choices()
{
    // Interface method to pretty-print the choices and their probabilities.

    _print_choices(std::cout);
    
}

template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::analyse_samples()
{
    // Interface method to analyse the samples.
    // Generate the counts of each choice in the samples,
    // then pass to a pretty-printer.
    _pretty_print_sample_frequency(std::cout, _gen_counts_each_choice());
}

template<typename CHOICES_t>
inline
std::vector<int> nextNum<CHOICES_t>::_gen_counts_each_choice()
{
    // Private method to generate the counts of each choice in the samples.
    int nchoices = choices.size();
    std::vector<int> counts(nchoices);
    for(int i = 0; i < nchoices; i++)
    {
        counts[i] = std::count(samples.begin(), samples.end(), choices[i]);
    }
    return counts;
}


template<typename CHOICES_t>
inline
void 
nextNum<CHOICES_t>::_pretty_print_sample_frequency(
    std::ostream& whereto, 
    const std::vector<int>& counts
){
    // Private method to pretty-print the counts of each 
    // available choice to the provided ostream.
    auto nchoices = choices.size();
    auto nsamples = samples.size();
    whereto << "============ SAMPLES ANALYSIS ============\n";
    whereto << "# samples: " << nsamples << "\n";
    for(int i = 0; i < nchoices; i++)
    {
        whereto << choices[i] << " " << counts[i] / static_cast<float>(nsamples) * 100 << "%\n";
    }
    whereto << "==========================================\n";
}

template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::gen_samples(int N)
{
    // Interface method to generate N samples from the supplied PDF.
    _gen_samples(N);
}


template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::print_samples()
{
    // Interface method to pretty-print the samples.
    JP::vprint<CHOICES_t>(std::cout, samples, "Samples");
}


template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::print_cdf()
{
    // Interface method to pretty-print the CDF.
    JP::vprint<NUMERIC>(std::cout, cdf, "CDF");
}


template<typename CHOICES_t>
inline
void nextNum<CHOICES_t>::calc_cdf()
{
    // Interface method to compute the CDF from the PDF.
    cdf = pdftocdf<NUMERIC>(pdf);
}


template<typename CHOICES_t>
inline
bool nextNum<CHOICES_t>::validate_pdf()
{
    // Method to validate the PDF; the sum of all entries in the PDF
    // should equal unity.
    // RETURN: 
    //  true if PDF valid.
    //  false if PDF invalid.

    return JP::test_equalty<NUMERIC>( 1, JP::sumup<NUMERIC>(pdf) );
}

template<typename CHOICES_t>
inline
bool nextNum<CHOICES_t>::validate_pdf_choices_compatible()
{
    return pdf.size() == choices.size();
}

template<typename CHOICES_t>
inline
CHOICES_t nextNum<CHOICES_t>::gen_sample()
{
    // Interface method to generate a sample from the PDF.
    return _gen_sample();
}


}