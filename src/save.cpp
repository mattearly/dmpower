#include "campaign.h"
#include "globalfuncts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;

extern string mainMessage;
extern string loadedFile;
extern bool loadSuccess;
extern Campaign myGame;

void showLoadableFiles(const std::string &dir);

void truncateSaveForThisVersion(std::string &original, std::string &edited);

bool mergeSaves(const std::string &keep, const std::string &mergein);

void save_file()
{
  if (myGame.character_list.empty())
  {
    mainMessage = "Nothing to save - character list empty";
    return;
  }

  std::string file;
  std::ofstream os;
  if (loadSuccess == false)
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
    file = loadedFile;
  }
  //save into file after above is complete
  os.open(("saves/" + file + ".save").c_str());
  if (os.is_open())
  {
    myGame.dumpCharacter(os);
    mainMessage = "All data saved in file: " + file;
    loadSuccess = true;
    loadedFile = file;
    os.close();
  }
}

void load_file()
{
  //show list of previous saves
  showLoadableFiles("saves");
  std::cout << "\nadditional load commands:\n"
               "   combine 2 files: 'combine SaveToKeep SaveToMergeInAndDelete'\n\n";
  std::string file;
  std::cout << "(leave blank to skip) Load File: ";
  std::getline(std::cin, file, '\n');
  reduce(file);

  ///combine saves option
  //if the word is combine, shoudl be followed by save to combine into, then
  // file to merge, merged file is deleted after completion (ideally)
  if (file.substr(0, 7) == "combine")
  {
    std::string keep, mergein;
    if (file.find_first_of(" ", 8) != std::string::npos)
    {
      size_t pos1 = file.find_first_of(" ", 8);
      keep = file.substr(8, pos1 - 8);
      mergein = file.substr(pos1 + 1);
      bool mergesuccess = mergeSaves(keep, mergein);
      if (mergesuccess)
      {
        char answer = getYorN("Delete old file?(y/n):");
        if (answer == 'Y')
        {
          std::string removestuff = "rm saves/" + mergein + ".save";
          if (!system(removestuff.c_str())) {
            std::cout << "unable to remove file '" << mergein << "'\n";
          }
        }
        load_file();
      }
    }
  }
  else
  {
    std::ifstream thefile;
    thefile.open(("saves/" + file + ".save").c_str());
    if (thefile.is_open())
    {
      bool success = myGame.retrieveCharacter(thefile);

      if (success)
      {
        std::cout << "File '" << file << "' loaded.\n\n";
      }
      else
      {
        std::cout << "The file named '" << file << "' doesn't seem to have much data or is invalid\n\n";
      }
      loadSuccess = true;
      loadedFile = file;
      thefile.close();
    }
    else
    {
      mainMessage = "No file named '" + file + "'. Starting new file.";
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
    std::cout << "List of loadable saves:\n";
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
  std::cout << std::endl;
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
      // std::cout << "writing line from old file to new file\n"; //debug
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
