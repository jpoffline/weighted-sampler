//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once
#include <vector>

//----------------- Declarations of the solution-class -----------------//

namespace JP{

template<typename CHOICES_t>
class nextNum{

    // Define the data type used for numeric data.
    typedef double NUMERIC;

    public:

        /// CONSTRUCTORS
        // Default.
        nextNum();
       
        // Pass in a vector of choices and probabilities.
        nextNum(std::vector<CHOICES_t> c, std::vector<NUMERIC> p);

        /// DESTRUCTOR
        ~nextNum();

        /// PUBLIC METHODS
        // Given the PDF, calculate the CDF.
        void calc_cdf();      

        // Ensure the PDF is valid (i.e., sums to unity).
        bool validate_pdf();                    
        
        // Ensure the PDF and choices are compatible (i.e., have the same number of elements).
        bool validate_pdf_choices_compatible(); 
        
        // Method to generate and return a single sample from the PDF.
        CHOICES_t gen_sample();                 
        
        // Method to generate and return N-samples from the PDF.
        void gen_samples(int N);                

        // Print the choices, and their associated probabilities.
        void print_choices();                   
        
        // Print all samples.
        void print_samples();                   
        
        // Print the CDF.
        void print_cdf();                       
        
        // Analyse the samples: find out how many of each choice have been chosen.
        void analyse_samples();                 

    private:
        /// DATA STRUCTURES
        std::vector<CHOICES_t> choices;
        std::vector<NUMERIC> pdf;
        std::vector<NUMERIC> cdf;
        std::vector<CHOICES_t> samples;

        /// RANDOM NUMBER GENERATOR
        JP::RNG rng;

        /// PRIVATE METHODS
        CHOICES_t _gen_sample();
        void _gen_samples(int N);
        std::vector<int> _gen_counts_each_choice();
        void _pretty_print_sample_frequency(std::ostream& whereto, const std::vector<int>& counts);
        void _print_choices(std::ostream& whereto);   
    

};
    
}