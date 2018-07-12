#include "campaign.h"
#include <string>
#include <iostream>
#include "terminal_colors.h"

extern void load_file();
extern void main_loop();

using std::string;

string mainMessage = "";
bool loadSuccess = false;
string loadedFile = "";
Campaign myGame;

int main()
{
    /* Program Header */
    std::cout << "|-------------------------------------------------------|" << std::endl;
    std::cout << "|-----[CLI DUNGEON MASTER TOOLKIT] [v000] [build:1]-----|" << std::endl;
    std::cout << "|----------your terminal should fit this block----------|" << std::endl;
    std::cout << "|-----------without wrapping for best results-----------|" << std::endl;
    std::cout << "|------------------58 character block-------------------|" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;

    load_file();

    /* Initiate Main Program Menu */
    main_loop();

    return EXIT_SUCCESS;

}
