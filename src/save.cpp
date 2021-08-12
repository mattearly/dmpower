#include "campaign.h"
#include "globalfuncts.h"
#include "terminal_colors.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#ifdef __has_include
#  if __has_include(<filesystem>)
#    include <filesystem>
#    define c17_filesystem
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
#    define boost_filesystem
#  else
     define no_filesystem
#  endif
#endif


using namespace std;

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
      contains_non_alpha = file.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != std::string::npos;
      done_first_pass = true;
    } while (contains_non_alpha);
  }
  else
  {
    file = loadedFile;
  }
  //save into file after above is complete
  os.open((SAVE_DIR + file + ".dmpsave").c_str());
  if (os.is_open())
  {
    myGame.dumpCharacter(os);
    mainMessage = "All data saved in file: " + file;
    loadSuccess = true;
    loadedFile = file;
    note_last_save(loadedFile);
    os.close();
  }
}

void load_file()
{
  if (clearScreens)
    simpleClearScreen();
  //show list of previous saves
  showLoadableFiles(SAVE_DIR);  //check

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
        std::string removestuff = "rm user/saves/" + mergein + ".dmpsave";
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
    thefile.open((SAVE_DIR + file + ".dmpsave").c_str());
    if (thefile.fail())
    {
      std::cout << "Could not open file (fail triggered)\n";
      return;
    }
    if (thefile.is_open())
    {
      int return_code = myGame.retrieveCharacter(thefile);

      // notify user of the result of the load
      switch (return_code)
      {
      case 1:
        mainMessage = "File '" + file + "' loaded.";
        loadedFile = file;
        loadSuccess = true;
        break;
      case 0:
        mainMessage = "Failed to load file: " + file + ", failed to set CLASS";
        break;
      case -1:
        mainMessage = "Failed to load file: " + file + ", your save version is too old!";
        break;
      case -2:
        mainMessage = "Failed to load file: " + file + ", this dmpower client is too old!";
        break;
      default:
        mainMessage = "Failed to load file: " + file + ", generic failure";
        break;
      }
    }
  }
}

void showLoadableFiles(const std::string &dir)
{
  // boost way of listing files in a directory - only crossplatform version out there maybe
#if defined(no_filesystem)
  return;
#elif defined(boost_filesystem)
  const boost::filesystem::path dir_path(dir);
#elif defined(c17_filesystem)
  const std::filesystem::path dir_path(dir);
#endif


  if (!exists(dir_path))
  {
    std::cout << "showLoadableFiles: path to directory (" << dir << ") does not exist\n";
    return;
  }
  else
  {
    std::cout << "List of loadable saves:\n";
  }


#if defined(boost_filesystem)
  //magic
#elif defined(c17_filesystem)
  //magic
#endif


#if defined(boost_filesystem)
  boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
#elif defined(c17_filesystem)
  std::filesystem::directory_iterator end_itr; // default construction yields past-the-end
#endif


  std::string edited_ver;
  int number_of_loadable_saves = 0;

#if defined(boost_filesystem)
  for (boost::filesystem::directory_iterator itr(dir_path); itr != end_itr; ++itr)
#elif defined(c17_filesystem)
  for (std::filesystem::directory_iterator itr(dir_path); itr != end_itr; ++itr)
#endif
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

    number_of_loadable_saves++;
    truncateSaveForThisVersion(original_ver, edited_ver);

    std::cout << "    " << CYAN << edited_ver << RESET << '\n';
  }
  std::cout << '\n';

  if (number_of_loadable_saves > 0)
  {
    std::cout << YELLOW << "additional save management commands:" << RESET << '\n';
    cout << "   combine 2 files: '" << GREEN << "combine SaveToKeep SaveToMergeIn" << RESET << "'\n";
    cout << "   delete a file: '" << GREEN << "delete SaveToDelete" << RESET << "'\n";
    std::cout << '\n';
  }
}

void truncateSaveForThisVersion(std::string &original, std::string &edited)
{
  edited.clear();
  std::size_t pos1 = original.find_last_of("/");
  std::size_t pos2 = original.find(".dmpsave");

  edited = original.substr(pos1 + 1, pos2 - pos1 - 1);
}

bool mergeSaves(const std::string &keep, const std::string &mergein)
{
  std::ofstream saveto;
  saveto.open((SAVE_DIR + keep + ".dmpsave").c_str(), std::ios_base::app); //open write-to file with append

  std::ifstream readfrom;
  readfrom.open((SAVE_DIR + mergein + ".dmpsave").c_str());

  if (saveto.is_open() && readfrom.is_open())
  {
    std::string tmp;
    getline(readfrom, tmp); // eat the first line which is the save version
    do
    {
      std::getline(readfrom, tmp);
      if (readfrom.eof())
        break;
      saveto << tmp << '\n';
    } while (!readfrom.eof());
    return true;
  }
  else
  {
    std::cout << "Error opening both requested files\n";
  }
  return false;
}

void load_file(const std::string &filename)
{
  if (filename.length() > 0)
  {
    std::ifstream thefile;
    thefile.open((SAVE_DIR + filename + ".dmpsave").c_str());
    if (thefile.fail())
    {
      std::cout << "Could not open file (fail triggered)\n";
      return;
    }
    if (thefile.is_open())
    {
      int return_code = myGame.retrieveCharacter(thefile);

      // notify user of the result of the load
      switch (return_code)
      {
      case 1:
        mainMessage = "File '" + filename + "' loaded.";
        loadedFile = filename;
        loadSuccess = true;
        break;
      case 0:
        mainMessage = "Failed to load file: " + filename + ", failed to set CLASS";
        break;
      case -1:
        mainMessage = "Failed to load file: " + filename + ", your save version is too old!";
        break;
      case -2:
        mainMessage = "Failed to load file: " + filename + ", this dmpower client is too old!";
        break;
      default:
        mainMessage = "Failed to load file: " + filename + ", generic failure";
        break;
      }
    }
  }
}

/** Routine to check what the user last saved and load it. Variable last_save is cleared if this fails. */
void load_last_save()
{
  lastSave.clear();
  std::ifstream fs("./settings/lastSave.dat");
  if (fs.is_open())
  {
    std::string holder;
    std::getline(fs, holder); // should be the first line
    if (!holder.empty())
    {
      lastSave = holder;
    }

    load_file(lastSave);

    //     we only what the first line this is just here to process the rest of the file for later expansion

    // while (!fs.eof())
    // {
    //     std::getline(fs, holder);
    // }
  }
}

/** Routine to take not of the last save so that load_last_save() func can use it. */
void note_last_save(const std::string &save_name)
{
  lastSave = save_name;
  std::ofstream os("./settings/lastSave.dat");
  if (os.is_open())
  {
    os << lastSave;
  }
  else
  {
    lastSave.clear();
  }
}

void auto_save()
{
  if (loadedFile.empty())
  {
    return; // no file to save too, can't auto-save, load something or save something first
  }
  std::ofstream os;
  //save into file
  os.open((SAVE_DIR + loadedFile + ".dmpsave").c_str());
  if (os.is_open())
  {
    myGame.dumpCharacter(os);

    if (mainMessage.size() < 1)
    {
      mainMessage.clear();
      mainMessage = "Auto Saved to: ";
      mainMessage += loadedFile;
    }
    else
    {
      mainMessage += ". Auto Saved to: ";
      mainMessage += loadedFile;
    }

    loadSuccess = true;
    note_last_save(loadedFile);
    os.close();
  }
}
