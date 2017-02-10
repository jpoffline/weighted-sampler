//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once
#include <vector>
#include <numeric>
#include <iostream>

#include "solution.h"
#include "tools.h"

namespace JP{

namespace UNIT{

    struct UNIT_TEST_RETURN;

    // Declare unit tests...
    UNIT_TEST_RETURN TEST_pdftocdf();
    UNIT_TEST_RETURN TEST_notfind_binary_search();
    UNIT_TEST_RETURN TEST_find_binary_search();
    UNIT_TEST_RETURN TEST_find_near_top_binary_search();
    UNIT_TEST_RETURN TEST_find_end_binary_search();
    UNIT_TEST_RETURN TEST_find_start_binary_search();
    UNIT_TEST_RETURN TEST_find_start_idx_binary_search();
    UNIT_TEST_RETURN TEST_find_end_idx_binary_search();
    UNIT_TEST_RETURN TEST_validate_pdf();
    UNIT_TEST_RETURN TEST_validate_fail_pdf();
    UNIT_TEST_RETURN TEST_find_2_binary_search();
    UNIT_TEST_RETURN TEST_equality_doubles();
    UNIT_TEST_RETURN TEST_equality_string();
    UNIT_TEST_RETURN TEST_equality_int();
    UNIT_TEST_RETURN TEST_inequality_doubles();
    UNIT_TEST_RETURN TEST_inequality_string();
    UNIT_TEST_RETURN TEST_inequality_int();
    UNIT_TEST_RETURN TEST_sumup();
    UNIT_TEST_RETURN TEST_sumup_fail();
    UNIT_TEST_RETURN TEST_sumup_string_fail();
    UNIT_TEST_RETURN TEST_sumup_string();


    bool analyse_test_results(
        std::ostream& whereto, 
        std::vector<UNIT::UNIT_TEST_RETURN> results
    );

    bool run_tests(std::ostream& whereto);
    bool run_tests();

}

}


namespace JP{

class UNIT::UNIT_TEST_RETURN
{
    private:
        bool pass;
        std::string description;
    public:    
        UNIT_TEST_RETURN(bool status, std::string desc) : pass(status), description(desc){}
        UNIT_TEST_RETURN(std::string desc, bool status) : pass(status), description(desc){}
        bool is_pass(){return pass;}
        std::string get_desc(){return description;}
};

// Definitions of the unit tests...

UNIT::UNIT_TEST_RETURN UNIT::TEST_pdftocdf()
{
    std::vector<double> pdf = {0.1,0.5,0.4};
    auto cdf = pdftocdf<double>(pdf);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_pdftocdf",
        cdf[cdf.size() - 1] == 1
    );
}


UNIT::UNIT_TEST_RETURN UNIT::TEST_notfind_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 0.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_notfind_binary_search",
        result == 0
    );
}


UNIT::UNIT_TEST_RETURN UNIT::TEST_find_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 6.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_binary_search",
        result == 1
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_find_2_binary_search()
{
    std::vector<double> values = {0.01, 0.3, 0.58, 0.1, 1};
    auto result = binary_search<double>(values, 0.02);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_2_binary_search",
        result == 1
    );
}


UNIT::UNIT_TEST_RETURN UNIT::TEST_find_near_top_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 49.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_near_top_binary_search",
        result == 3
    );
}


UNIT::UNIT_TEST_RETURN UNIT::TEST_find_end_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 50.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_end_binary_search",
        result == 3
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_find_start_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 1.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_start_binary_search",
        result == 0 
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_find_start_idx_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 1.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_start_idx_binary_search",
        result == 0
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_find_end_idx_binary_search()
{
    std::vector<double> values = {1.0, 10.0, 20.0, 50.0};
    auto result = binary_search<double>(values, 50.0);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_find_end_idx_binary_search",
        result == 3
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_validate_pdf()
{
    std::vector<double> values {0.01, 0.3, 0.58, 0.1, 0.01};
    auto result = sumup<double>(values);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_validate_pdf",
        test_equalty<double>(result,1)
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_validate_fail_pdf()
{
    std::vector<double> values {0.01, 0.3, 0.58, 0.1, 0.1};
    auto result = sumup<double>(values);
    return UNIT::UNIT_TEST_RETURN(
        "TEST_validate_fail_pdf",
        !test_equalty<double>(result,1)
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_equality_doubles()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_equality_doubles",
        test_equalty<double>(1.0,1.0)
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_inequality_doubles()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_inequality_doubles",
        !test_equalty<double>(1.0,0.0)        
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_equality_string()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_equality_string",
        test_equalty<std::string>("hello", "hello")
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_inequality_string()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_inequality_string",
        !test_equalty<std::string>("hello", "world")
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_equality_int()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_equality_int",
        test_equalty<int>(1,1)
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_inequality_int()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_inequality_int",
        !test_equalty<int>(1,2)
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_sumup()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_sumup",
        JP::sumup<double>(std::vector<double>{1.0,2.0}) == 3.0
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_sumup_fail()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_sumup_fail",
        !(JP::sumup<double>(std::vector<double>{1.0,2.0}) == 4.0)
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_sumup_string_fail()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_sumup_string_fail",
        !(JP::sumup<std::string>(std::vector<std::string>{"hello", " world"}) == "hello world me")
    );
}

UNIT::UNIT_TEST_RETURN UNIT::TEST_sumup_string()
{
    return UNIT::UNIT_TEST_RETURN(
        "TEST_sumup_string",
        JP::sumup<std::string>(std::vector<std::string>{"hello", " world"}) == "hello world"
    );
}

bool UNIT::run_tests(
    
){
    return run_tests(std::cout);
}

bool UNIT::run_tests(
    std::ostream& whereto
){
    return(
        analyse_test_results(
            whereto,
            std::vector<UNIT::UNIT_TEST_RETURN>{
                TEST_pdftocdf(),
                TEST_notfind_binary_search(),
                TEST_find_binary_search(),
                TEST_find_end_binary_search(),
                TEST_find_start_binary_search(),
                TEST_find_near_top_binary_search(),
                TEST_find_start_idx_binary_search(),
                TEST_find_end_idx_binary_search(),
                TEST_validate_pdf(),
                TEST_validate_fail_pdf(),
                TEST_find_2_binary_search(),
                TEST_equality_int(),
                TEST_equality_doubles(),
                TEST_equality_string(),
                TEST_inequality_int(),
                TEST_inequality_doubles(),
                TEST_inequality_string(),
                TEST_sumup(),
                TEST_sumup_fail(),
                TEST_sumup_string_fail(),
                TEST_sumup_string()
            }
        )
    );
}

bool 
UNIT::analyse_test_results(
    std::ostream& whereto, 
    std::vector<UNIT::UNIT_TEST_RETURN> results
){
    int nfail = 0;
    int npass = 0;
    for(auto & r : results)
    {
        if(!r.is_pass())
        {
            nfail++;
            whereto << "FAIL: " << r.get_desc() << "\n";
        }
        else
        {
            npass++;
        }
    }

    whereto << "---------------------------------\n";
    whereto << "TESTS run" << "\n";
    whereto << "   #tests: " << npass + nfail << "\n";
    whereto << "   #fails: " << nfail << "\n";
    whereto << "   #pass:  " << npass << "\n";

    if(nfail == 0)
    {
        whereto << "SUCCESS!\n";        
    }
    else
    {
        whereto << "FAIL!\n";      
    }
    whereto << "---------------------------------\n";

    return nfail == 0;

}


}