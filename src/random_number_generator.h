//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once
#include <random>

namespace JP{

class RNG{

    private:
        // Random number seed: time; every call will hence be different.
        std::random_device random{}; 
        std::mt19937 gen{static_cast<unsigned int>(time(0))};
        std::uniform_real_distribution<double> random_unit_uniform{0,1};
        
    public:

        RNG(){}
        double get_uniform()
        {
            // Return a uniformly distributed random number, on the unit-interval.
            return random_unit_uniform(gen);
        }
};

}