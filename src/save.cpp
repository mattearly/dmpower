#include "campaign.h"
#include <fstream>

void load_file(bool &ls, std::string &lf, Campaign &game)
{
    std::string file;
    std::ifstream thefile;
    std::cout << "\n|----------------- press enter to skip load ----------------|\n"
         << std::endl;
    std::cout << "Load File: ";
    std::getline(std::cin, file, '\n');
    thefile.open(("saves/" + file + ".save").c_str());
    if (thefile.is_open())
    {
        bool success = game.retrieveCharacter(thefile);

        simpleClearScreen();
        if (success)
        {
            std::cout << "File '" << file << "' loaded.\n\n";
        }
        else
        {
            std::cout << "The file named '" << file << "' doesn't seem to have much data or is invalid\n\n";
        }
        ls = true;
        lf = file;
        thefile.close();
    }
    else
    {
        simpleClearScreen();
        std::cout << "No file named '" << file << "'. Starting new file.\n\n";
    }
}

void save_file(bool &ls, std::string &lf, const Campaign &game)
{
    std::string file;
    std::ofstream os;
    if (ls == false)
    {
        std::cout << "Save As: ";
        std::getline(std::cin, file, '\n');
    }
    else
    {
        file = lf;
    }
    //save into file after above is complete
    os.open(("saves/" + file + ".save").c_str());
    if (os.is_open())
    {
        game.dumpCharacter(os);
        std::cout << "All data saved in file -> " << file << std::endl;
        ls = true;
        lf = file;
        os.close();
    }
    else
    {
        std::cout << "Save failed.\n";
    }
}
