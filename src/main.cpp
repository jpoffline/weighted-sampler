//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#include "main.h"

int main_flow(int argc, char *argv[])
{
    // The main flow-manager function;
    // Simple parsing functionality of the command-line options,
    // to decide which run-mode to execute.
    // If anything invalid is provided, an error is thrown with a sensible
    // error message, and the expected usage is printed to screen.

    // Validate command line input; make sure there is at least a "mode" given.
    if(argc < 2)
    {
        JP::usage();
        throw JP::EXCEPTION("Not enough command line arguments");
    }


    // Turn the first command line argument into a string; used to define the mode.
    std::string mode(argv[1]);

    if(mode == "-help")
    {
        // Display usage mesage
        JP::usage();
    }
    else if(mode == "-test")
    {
        // Run unit-tests.
        JP::UNIT::run_tests();
    }
    else if(mode == "-sample")
    {
        // Get a user-defined number of samples.
        if(argc < 3)
        {
            JP::usage();
            throw JP::EXCEPTION("Not enough command line arguments; need to specify number of samples");
        }
        JP::run_nextNum_sample(std::stoi(argv[2]));
    }
    else if(mode == "-double")
    {
        // Run the sampler on a hard-coded set of choices and probabilities;
        // run for DOUBLES.
        JP::run_nextNum_doubles(true);
    }
    else if(mode == "-string")
    {
        // Run the sampler on a hard-coded set of choices and probabilities;
        // run for string.
        JP::run_nextNum_strings(true);
    }
    else
    {
        JP::usage();
        throw JP::EXCEPTION("Invalid mode provided");
    }


    return 0;
}


int main(int argc, char *argv[])
{
    // Main entry point into the code.

    // Always print the application banner
    JP::UTILS::banner();

    // Kick off the main flow-manager function;
    // catch any thrown exceptions.
    try{
        main_flow(argc, argv);
        std::cout << "   DONE \n\n";
    }
    catch(JP::EXCEPTION& e)
    {
        std::cerr << "FATAL CUSTOM ERROR" << std::endl;
        std::cerr << "MSG: " << e.what() << std::endl;
        std::cerr << std::endl;
    }
    
    return 0;

}