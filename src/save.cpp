#include "campaign.h"
#include "globalfuncts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
// #include <filesystem>
#include <boost/filesystem.hpp>

using namespace boost::filesystem; // for ease of tutorial presentation;

void showLoadableFiles(const std::string &dir);

void truncateSaveForThisVersion(std::string &original, std::string &edited);

void load_file(bool &ls, std::string &lf, Campaign &game)
{
    //list of saves
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

        // simpleClearScreen();
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
        // simpleClearScreen();
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

    /* c++ 17 way
    namespace fs = std::filesystem;
    std::string path = "../saves";
    for (auto &p : fs::directory_iterator(path))
        std::cout << p << std::endl;
        */

    /* older c++ std way on windows with #include dirent.h
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("c:\\src\\")) != NULL)
    {
        // print all the files and directories within directory
        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        //  could not open directory 
        perror("");
        return EXIT_FAILURE;
    }
    */

    //linux way of listing files in a directory

    // auto name = "../saves";
    // auto len = strlen(name);
    // auto dirp = opendir(".");

    // while ((dp = readdir(dirp)) != NULL)
    //     if (dp->d_namlen == len && !strcmp(dp->d_name, name))
    //     {
    //         (void)closedir(dirp);
    //         return FOUND;
    //     }
    // (void)closedir(dirp);
    // return NOT_FOUND;

    // boost way of listing files in a directory - only crossplatform version out there maybe

    // bool find_file(const path &dir_path,         // in this directory,
    //                const std::string &file_name, // search for this name,
    //                path &path_found)             // placing path here if found
    // {
    // std::cout << "checking path...\n";

    const path dir_path(dir);

    if (!exists(dir_path))
    {
        // return false;
        std::cout << "path to list everything does not exist\n";
    } else {
        std::cout << "\n| Loadable Files:\n\n";
    }

    directory_iterator end_itr; // default construction yields past-the-end

    std::string edited_ver;

    // std::cout << "checking path...2...\n";

    for (directory_iterator itr(dir_path); itr != end_itr; ++itr)
    {
        // std::cout << itr->path() << "...\n";

        std::stringstream ss;
        ss << itr->path();
        std::string original_ver;
        ss >> original_ver;

        //ignore the readme.md file
        if (original_ver.find("readme.md") != std::string::npos) {
            continue;
        }

        truncateSaveForThisVersion(original_ver, edited_ver);

        // std::cout << itr->path() << "\n";

        std::cout << "    " << CYAN << edited_ver << RESET << "\n";

        // if (is_directory(itr->status()))
        // {
        //     if (find_file(itr->path(), file_name, path_found))
        //         return true;
        // }
        // else if (itr->leaf() == file_name) // see below
        // {
        //     path_found = itr->path();
        //     return true;
        // }
    }
    // return false;
    // }

    //list of saves end
}

void truncateSaveForThisVersion(std::string &original, std::string &edited)
{
    // std::cout << "truncating...\n";
    edited.clear();
    // std::size_t pos1 = original.find("");
    std::size_t pos2 = original.find(".save");

    edited = original.substr(7, pos2 - 7);
}
