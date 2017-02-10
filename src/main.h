//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once

#include <vector>
#include <iostream>
#include <string>
#include "tools.h"
#include "solution.h"
#include "tests.h"
#include "exception.h"
#include "utils.h"

//----------------- Declarations -----------------//

namespace JP{

// Run the sampler with choices which are doubles.
void run_nextNum_doubles(bool verbose);

// Run the sampler with choices which are strings.
void run_nextNum_strings(bool verbose);

// Run the sampler for manual sample extraction.
void run_nextNum_sample(int N);

// Factory function to run the sampler for a generic data-type for the choices.
template<typename CHOICES_TYPE>
void run_sampler(std::vector<CHOICES_TYPE>& choices, std::vector<double> pdf, int nsamples, bool verbose);

// Function to print the command-line usage to screen,
void usage();

}

//----------------- Definitions -----------------//

namespace JP{

void run_nextNum_doubles(bool verbose)
{    
    //////////////////////////////////////////////////////////////
    //
    // Driver function for the nextNum class
    // 
    // This example shows the use case with a set of choices
    // which are DOUBLEs, and a set of probabilities that each
    // choice is selected.
    //
    typedef double CHOICES_TYPE;
    //
    //////////////////////////////////////////////////////////////
    

    // Define the input:
    // choices, their probabilities, and the number of samples
    std::vector<CHOICES_TYPE> choices {  -1,  0,     1,   2,    3};
    std::vector<double> pdf           {0.01, 0.3, 0.58, 0.1, 0.01};
    int nsamples = 1000000;

    run_sampler<CHOICES_TYPE>(choices, pdf, nsamples, verbose);
}


void run_nextNum_strings(bool verbose)
{    
    //////////////////////////////////////////////////////////////
    //
    // Driver function for the nextNum class
    // 
    // This example shows the use case with a set of choices
    // which are STRINGs, and a set of probabilities that each
    // choice is selected.
    //
    typedef std::string CHOICES_TYPE;
    //
    //////////////////////////////////////////////////////////////
    

    // Here define the input:
    // choices, their probabilities, and the number of samples.
    std::vector<CHOICES_TYPE> choices {  "j",  "p",  "a", "i", "jp"};
    std::vector<double> pdf            {0.01,  0.3, 0.58, 0.1, 0.01};
    int nsamples = 1000000;

    run_sampler<CHOICES_TYPE>(choices, pdf, nsamples, verbose);

}


void run_nextNum_sample(int N)
{
    // Driver function for manual sample extraction.
    // Shows the use of direct extraction; prints to screen in this example implementation.
    typedef double CHOICES_TYPE;

    std::vector<CHOICES_TYPE> choices {  -1,  0,     1,   2,    3};
    std::vector<double> pdf           {0.01, 0.3, 0.58, 0.1, 0.01};

    JP::nextNum<CHOICES_TYPE> nextNum(choices, pdf);
    nextNum.print_choices();
    std::cout << "Requested samples:" << std::endl;
    for(int i = 0; i < N; i++)
    {
        auto sample = nextNum.gen_sample();
        std::cout << i+1 << "/" << N << ": " << sample << std::endl;
    }


}


template<typename CHOICES_TYPE>
void run_sampler(std::vector<CHOICES_TYPE>& choices, std::vector<double> pdf, int nsamples, bool verbose)
{
    // Factory function to run the sampler with an arbitrary data-type of choices,
    // for the provided choices, pdf, nsamples, and an option to give a verbose output.
    JP::nextNum<CHOICES_TYPE> nextNum(choices, pdf);
    if(verbose) nextNum.print_choices();
    nextNum.gen_samples(nsamples);
    nextNum.analyse_samples();
}


void usage()
{
    // Function to print the command-line usage of the application to screen.
    std::cout << "nextNum sampler useage\n";
    std::cout << "-------------------------------------------------------------------------------\n";
    std::cout << "Options: -help             Display this help message.                          \n";
    std::cout << "         -test             Run unit tests.                                     \n";
    std::cout << "         -double           Run example sampler with doubles as the data type.  \n";
    std::cout << "         -string           Run example sampler with strings as the data type.  \n";
    std::cout << "         -sample NSAMPLES  Run sampler and yield back NSAMPLES samples.        \n";
    std::cout << "-------------------------------------------------------------------------------\n";
    std::cout << "\n";
}

}