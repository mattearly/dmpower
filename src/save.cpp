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

bool mergeSaves(const std::string &keep, const std::string &mergein);

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
        bool done_first_pass = false;
        bool contains_non_alpha = true;
        do
        {
            if (done_first_pass)
            {
                std::cout << file << " is an invalid name. Use only characters a-z & A-Z & 0-9\n";
                std::cout << "Save As: ";
            }
            std::getline(std::cin, file, '\n');
            reduce(file);
            contains_non_alpha = file.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789") != std::string::npos;
            done_first_pass = true;
        } while (contains_non_alpha);
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

void load_file(bool &ls, std::string &lf, Campaign &game)
{
    //show list of previous saves
    showLoadableFiles("saves");

    std::string file;
    std::cout << "\n|----------------- press enter to skip load ----------------|\n\n"
              << "Load File: ";
    std::getline(std::cin, file, '\n');
    reduce(file);

    ///combine saves option
    //if the word is combine, shoudl be followed by save to combine into, then
    // file to merge, merged file is deleted after completion (ideally)
    if (file.substr(0, 7) == "combine")
    {
        std::cout << "combine function call detected\n";
        std::string keep, mergein;

        if (file.find_first_of(" ", 8) != std::string::npos)
        {
            size_t pos1 = file.find_first_of(" ", 8);
            std::cout << "found a whitespace at " << file.find_first_of(" ", 8) << std::endl;

            keep = file.substr(8, pos1 - 8);
            std::cout << "keep file = " << keep << std::endl;

            mergein = file.substr(pos1 + 1);
            std::cout << "mergein file = " << mergein;

            bool mergesuccess = mergeSaves(keep, mergein);

            if (mergesuccess)
            {
                std::string removestuff = "rm saves/" + mergein + ".save";
                system(removestuff.c_str());
                simpleClearScreen();
                load_file(ls, lf, game);
                // save_file(ls, lf, game);  //to update and correct formatting - to slow doesn't matter(wont hurt anything to not do this) it will update when they save again anyway
            }
        }
    }
    else
    {
        std::ifstream thefile;
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

bool mergeSaves(const std::string &keep, const std::string &mergein)
{
    std::ofstream saveto;
    // open with append ready
    saveto.open(("saves/" + keep + ".save").c_str(), std::ios_base::app);
    if (saveto.is_open())
    {
        std::cout << "\nsaveto is open\n";
    }
    else
        std::cout << "saveto open failed\n";

    // saveto.close();
    std::ifstream readfrom;
    // open for read only
    readfrom.open(("saves/" + mergein + ".save").c_str());
    if (readfrom.is_open())
    {
        std::cout << "readfrom is open\n";
    }
    else
        std::cout << "readfrom open failed\n";

    if (saveto.is_open() && readfrom.is_open())
    {
        //do the transfer update of the save
        std::string tmp;
        do
        {
            std::cout << "writing line from old file to new file\n";
            std::getline(readfrom, tmp);
            if (readfrom.eof())
                break;
            saveto << tmp << "\n";
        } while (!readfrom.eof());
        saveto.close();
        readfrom.close();
        return true;
    }
    else
    {
        std::cout << "both are not open, weird mate\n";
    }
    return false;
}