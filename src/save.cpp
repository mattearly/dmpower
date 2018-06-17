#include "campaign.h"
#include "globalfuncts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

void showLoadableFiles(const std::string &dir);

void truncateSaveForThisVersion(std::string &original, std::string &edited);

void load_file(bool &ls, std::string &lf, Campaign &game)
{
    //show list of previous saves
    showLoadableFiles("saves");

    std::string file;
    std::ifstream thefile;
    std::cout << "\n|----------------- press enter to skip load ----------------|\n\n"
              << "Load File: ";
    std::getline(std::cin, file, '\n');
    thefile.open(("saves/" + file + ".save").c_str());
    if (thefile.is_open())
    {
        bool success = game.retrieveCharacter(thefile);

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
        std::cout << "No file named '" << file << "'. Starting new file.\n\n";
    }
}

void save_file(bool &ls, std::string &lf, const Campaign &game)
{
    if (game.character_list.empty())
    {
        std::cout << "nothing to save - character list empty\n";
        return;
    }

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

void showLoadableFiles(const std::string &dir)
{
    // boost way of listing files in a directory - only crossplatform version out there maybe

    const path dir_path(dir);

    if (!exists(dir_path))
    {
        std::cout << "showLoadableFiles: path to directory (" << dir << ") does not exist\n";
        return;
    }
    else
    {
        std::cout << "\n| Loadable Files:\n\n";
    }

    directory_iterator end_itr; // default construction yields past-the-end

    std::string edited_ver;

    for (directory_iterator itr(dir_path); itr != end_itr; ++itr)
    {
        std::stringstream ss;
        ss << itr->path();
        std::string original_ver;
        ss >> original_ver;

        //ignore the readme.md file
        if (original_ver.find("readme.md") != std::string::npos)
        {
            continue;
        }

        truncateSaveForThisVersion(original_ver, edited_ver);

        std::cout << "    " << CYAN << edited_ver << RESET << "\n";
    }
}

void truncateSaveForThisVersion(std::string &original, std::string &edited)
{
    // std::cout << "truncating...\n";
    edited.clear();
    // std::size_t pos1 = original.find("");
    std::size_t pos2 = original.find(".save");

    edited = original.substr(7, pos2 - 7);
}
