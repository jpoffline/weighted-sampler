//
// nextNum
//  J. A. Pearson, jon@jpoffline.com
//  Feb 2017
//
#pragma once


namespace JP{
namespace UTILS{

void banner(std::ostream& whereto)
{
    whereto << "                                    \n";
    whereto << "<><><><><><><><><><><><><><><><><><>\n";
    whereto << "                                    \n";
    whereto << "     nextNum sampler                \n";
    whereto << "          J.A.Pearson               \n";
    whereto << "                                    \n";
    whereto << "<><><><><><><><><><><><><><><><><><>\n";
    whereto << "                                    \n";
}

void banner()
{
    banner(std::cout);
}

}
}