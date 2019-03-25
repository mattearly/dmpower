#include "campaign.h"
#include "globalfuncts.h"
#include "terminal_colors.h"
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
extern bool clearScreens;

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
  os.open(("saves/" + file + ".dmpsave").c_str());
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
  if (clearScreens) simpleClearScreen();
  //show list of previous saves
  showLoadableFiles("saves");
  std::cout << YELLOW << "additional load commands:" << RESET << "\n";
  cout << "   combine 2 files: 'combine SaveToKeep SaveToMergeIn'\n";
  cout << "   delete a file: 'delete SaveToDelete'\n";
  std::cout << std::endl;
  std::string file;
  std::cout << "(leave blank to skip) Load File: ";
  std::getline(std::cin, file, '\n');
  reduce(file);

  //combine saves option
  // if the word is combine followed by a space,
  // the next 2 words should be the one to keep and the one to merge in
  if (file.substr(0, 8) == "combine ")
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
        std::string removestuff = "rm saves/" + mergein + ".dmpsave";
        if (system(removestuff.c_str()))
        {
          std::cout << "unable to remove file '" << mergein << "'\n";
        }
        load_file();
      }
    }
  }

  // delete saves option
  // if the word is delete followed by a space, the next word should be the file to delete
  else if (file.substr(0, 7) == "delete ")
  {
    std::string fileToRemove;
    if (file.find_first_not_of(" ", 7) != std::string::npos)
    {
      size_t pos1 = file.find_first_of(" ", 7);
      fileToRemove = file.substr(7, pos1 - 7);
      std::string removestuff = "rm saves/" + fileToRemove + ".dmpsave";
      if (system(removestuff.c_str()))
      {
        std::cout << "unable to remove file '" << fileToRemove << "'\n";
      }
      load_file();
    }
  }
  else if (file.length() > 0)
  {
    std::ifstream thefile;
    thefile.open(("saves/" + file + ".dmpsave").c_str());
    if (thefile.fail()) {
      std::cout << "Could not open file (fail triggered)\n";
      return;
    } 
    if (thefile.is_open())
    {
      bool success = myGame.retrieveCharacter(thefile);

      if (success)
      {
        mainMessage = "File '" + file + "' loaded.";
        loadedFile = file;
        loadSuccess = true;
      } else {
        mainMessage = "Failed to load file: " + file + " - check code.";
      }
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

    //ignore anything that is not *.dmpsave
    if (original_ver.find(".dmpsave") == std::string::npos)
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
  edited.clear();
  std::size_t pos2 = original.find(".dmpsave");

  edited = original.substr(7, pos2 - 7);
}

bool mergeSaves(const std::string &keep, const std::string &mergein)
{
  std::ofstream saveto;
  saveto.open(("saves/" + keep + ".dmpsave").c_str(), std::ios_base::app);  //open write-to file with append

  std::ifstream readfrom;
  readfrom.open(("saves/" + mergein + ".dmpsave").c_str());

  if (saveto.is_open() && readfrom.is_open())
  {
    std::string tmp;
    do
    {
      std::getline(readfrom, tmp);
      if (readfrom.eof())
        break;
      saveto << tmp << "\n";
    } while (!readfrom.eof());
    return true;
  }
  else
  {
    std::cout << "Error opening both requested files\n";
  }
  return false;
}
