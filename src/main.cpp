#include "campaign.h"
#include <string>
#include <iostream>
#include "globalfuncts.h"

extern void main_loop();

using std::string;

int main()
{
    /* Program Header */
    std::cout << "|-------------------------------------------------------|" << std::endl;
    std::cout << "|-----[CLI DUNGEON MASTER TOOLKIT] [v000] [build:1]-----|" << std::endl;
    std::cout << "|----------your terminal should fit this block----------|" << std::endl;
    std::cout << "|-----------without wrapping for best results-----------|" << std::endl;
    std::cout << "|------------------58 character block-------------------|" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;

    pressEnterToContinue();

    /* Initiate Main Program Menu */
    main_loop();

    return EXIT_SUCCESS;

}
