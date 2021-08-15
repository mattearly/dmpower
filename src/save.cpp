#include "campaign.h"
#include "globalfuncts.h"
#include "terminal_colors.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>

#if defined(_WIN32)
#include <windows.h>
#include <shlobj.h>
#include <objbase.h>
std::filesystem::path get_user_profile_path() {
  wchar_t* p;
  if (S_OK != SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &p))
    return "";
  std::filesystem::path result = p;
  CoTaskMemFree(p);
  return result;
}
const std::filesystem::path user_profile_path = get_user_profile_path();
const std::string os_app_data = "/AppData/Local/dmpower";
const std::string user_document_area = "/Documents/DMpowerExports";
const std::string ROOT_SAVE_DIR = user_profile_path.string();
#include <fileapi.h>
bool create_dir(const char* path) {
  // https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectorya
  // If the function succeeds, the return value is true.
  bool wasSuccessful = CreateDirectoryA(path, NULL);
  if (!wasSuccessful) {
    DWORD last_error = GetLastError();
    if (last_error == ERROR_ALREADY_EXISTS) {
      // perfectly fine option
      wasSuccessful = true;
    } else if (last_error == ERROR_PATH_NOT_FOUND) {
      std::cout << "!!!!!!!!DEBUG!!!!!!!!!!!!!\n";
      std::cout << "path: " << path << " NOT FOUND (not final part only?)\n";
    }
  }
  return wasSuccessful;
}
#elif defined(__linux__)
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>
#include <errno.h>
#include <cstring>
std::filesystem::path get_user_profile_path() {
  std::cout << "getting linux user profile...\n\n\n";
  const char* p = getenv("HOME");
  std::filesystem::path result = p;
  return result;
}
const std::filesystem::path user_profile_path = get_user_profile_path();
const std::string os_app_data = "/.dmpower";
const std::string user_document_area = "/DMpowerExports";
const std::string ROOT_SAVE_DIR = user_profile_path.string();
bool create_dir(const char* path) {
  std::string create_path = "mkdir -p ";
  create_path.append(path);
  //Upon successful completion, mkdir() shall return 0.
  // Otherwise, -1 shall be returned, no directory shall be created, and errno shall be set to indicate the error.
  bool wasSuccessful = system(create_path.c_str()); // call system to make the folder structure to path
  wasSuccessful = !wasSuccessful;                   // flip to make it correct
  if (!wasSuccessful) {
    std::cout << "Error : " << std::strerror(errno) << std::endl;
    if (errno == EEXIST) {
      std::cout << "but dir does exist\n";
      wasSuccessful = true; // fine
    }
  } else {
    std::cout << "Directories are created" << std::endl;
  }
  return wasSuccessful;
}
#endif


const std::string DOCUMENT_SAVE_DIR = ROOT_SAVE_DIR + user_document_area;
const std::string APP_DATA_DIR = ROOT_SAVE_DIR + os_app_data;
const std::string CAMPAIGN_SAVE_DIR = ROOT_SAVE_DIR + os_app_data + "/saves";
const std::string SETTINGS_SAVE_DIR = ROOT_SAVE_DIR + os_app_data + "/settings";


void truncateSaveForThisVersion(std::string& original, std::string& edited) {
  edited.clear();
  std::size_t pos1 = original.find_last_of("/\\");
  std::size_t pos2 = original.find(".dmpsave");

  edited = original.substr(pos1 + 1, pos2 - pos1 - 1);
}
void showLoadableFiles(const std::string& dir) {
  const std::filesystem::path dir_path(dir);

  if (!exists(dir_path)) {
    std::cout << "showLoadableFiles: path to directory (" << dir << ") does not exist\n";
    return;
  } else {
    std::cout << "List of loadable saves:\n";
  }

  std::filesystem::directory_iterator end_itr; // default construction yields past-the-end

  std::string edited_ver;
  int number_of_loadable_saves = 0;

  for (std::filesystem::directory_iterator itr(dir_path); itr != end_itr; ++itr) {
    std::stringstream ss;
    ss << itr->path();
    std::string original_ver;
    ss >> original_ver;

    //ignore anything that is not *.dmpsave
    if (original_ver.find(".dmpsave") == std::string::npos) {
      continue;
    }

    number_of_loadable_saves++;
    truncateSaveForThisVersion(original_ver, edited_ver);

    std::cout << "    " << CYAN << edited_ver << RESET << '\n';
  }
  std::cout << '\n';

  if (number_of_loadable_saves > 0) {
    std::cout << YELLOW << "additional save management commands:" << RESET << '\n';
    std::cout << "   combine 2 files: '" << GREEN << "combine SaveToKeep SaveToMergeIn" << RESET << "'\n";
    std::cout << "   delete a file: '" << GREEN << "delete SaveToDelete" << RESET << "'\n";
    std::cout << '\n';
  }
}
bool mergeSaves(const std::string& keep, const std::string& mergein) {
  std::cout << "mergeSaves function disabled\n";
  //std::ofstream saveto;
  //saveto.open((CAMPAIGN_SAVE_DIR + "/" + keep + ".dmpsave").c_str(), std::ios_base::app); //open write-to file with append

  //std::ifstream readfrom;
  //readfrom.open((CAMPAIGN_SAVE_DIR + "/" + mergein + ".dmpsave").c_str());

  //if (saveto.is_open() && readfrom.is_open()) {
  //  std::string tmp;
  //  getline(readfrom, tmp); // eat the first line which is the save version
  //  do {
  //    std::getline(readfrom, tmp);
  //    if (readfrom.eof())
  //      break;
  //    saveto << tmp << '\n';
  //  } while (!readfrom.eof());
  //  return true;
  //} else {
  //  std::cout << "Error opening both requested files\n";
  //}
  //return false;
  return true;
}
void createUserFolders() {
  // create these directories to make sure they exist
  if (create_dir(ROOT_SAVE_DIR.c_str()))
    std::cout << ROOT_SAVE_DIR << " now exists" << std::endl;

  if (create_dir(APP_DATA_DIR.c_str()))
    std::cout << APP_DATA_DIR << " now exists" << std::endl;

  if (create_dir(CAMPAIGN_SAVE_DIR.c_str()))
    std::cout << CAMPAIGN_SAVE_DIR << " now exists" << std::endl;

  if (create_dir(SETTINGS_SAVE_DIR.c_str()))
    std::cout << SETTINGS_SAVE_DIR << " now exists" << std::endl;

  if (create_dir(DOCUMENT_SAVE_DIR.c_str()))
    std::cout << DOCUMENT_SAVE_DIR << " now exists" << std::endl;
}
void note_last_save(const std::string& save_name) {
  /** Routine to take note of the last save so that load_last_save() func can use it. */
  lastSave = save_name;
  std::ofstream os((SETTINGS_SAVE_DIR + "/lastSave.dat").c_str());
  if (os.is_open()) {
    os << lastSave;
  } else {
    lastSave.clear();
  }
}
void load_file(const std::string& filename) {
  if (filename.length() > 0) {
    std::ifstream thefile;
    thefile.open((CAMPAIGN_SAVE_DIR + "/" + filename + ".dmpsave").c_str());
    if (thefile.fail()) {
      std::cout << "Could not open file (fail triggered)\n";
      return;
    }
    if (thefile.is_open()) {
      int return_code = myGame.retrieveCharacter(thefile);

      // notify user of the result of the load
      switch (return_code) {
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

// called from outside

void load_last_save() {
  /** Routine to check what the user last saved and load it. Variable last_save is cleared if this fails. */
  lastSave.clear();
  std::ifstream fs(SETTINGS_SAVE_DIR + "/lastSave.dat");
  if (fs.is_open()) {
    std::string holder;
    std::getline(fs, holder); // should be the first line
    if (!holder.empty()) {
      lastSave = holder;
    }
    load_file(lastSave);
  }
}
void load_file() {
  if (clearScreens)
    simpleClearScreen();
  //show list of previous saves
  showLoadableFiles(CAMPAIGN_SAVE_DIR); //check

  std::string file;
  std::cout << "(leave blank to skip) Load File: ";
  std::getline(std::cin, file, '\n');
  reduce(file);

  //combine saves option
  // if the word is combine followed by a space,
  // the next 2 words should be the one to keep and the one to merge in
  if (file.substr(0, 8) == "combine ") {
    std::string keep, mergein;
    if (file.find_first_of(" ", 8) != std::string::npos) {
      size_t pos1 = file.find_first_of(" ", 8);
      keep = file.substr(8, pos1 - 8);
      mergein = file.substr(pos1 + 1);
      bool mergesuccess = mergeSaves(keep, mergein);
      if (mergesuccess) {
        std::string removestuff = "rm user/saves/" + mergein + ".dmpsave";
        if (system(removestuff.c_str())) {
          std::cout << "unable to remove file '" << mergein << "'\n";
        }
        load_file();
      }
    }
  }

  // delete saves option
  // if the word is delete followed by a space, the next word should be the file to delete
  else if (file.substr(0, 7) == "delete ") {
    std::cout << "function removed\n";
    /*std::string fileToRemove;
    if (file.find_first_not_of(" ", 7) != std::string::npos) {
      size_t pos1 = file.find_first_of(" ", 7);
      fileToRemove = file.substr(7, pos1 - 7);
      std::string removestuff = "rm saves/" + fileToRemove + ".dmpsave";
      if (system(removestuff.c_str())) {
        std::cout << "unable to remove file '" << fileToRemove << "'\n";
      }
      load_file();
    }*/
  } else if (file.length() > 0) {
    std::ifstream thefile;
    thefile.open((CAMPAIGN_SAVE_DIR + "/" + file + ".dmpsave").c_str());
    if (thefile.fail()) {
      std::cout << "Could not open file (fail triggered)\n";
      return;
    }
    if (thefile.is_open()) {
      int return_code = myGame.retrieveCharacter(thefile);

      // notify user of the result of the load
      switch (return_code) {
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
void auto_save() {
  if (loadedFile.empty()) {
    return; // no file to save too, can't auto-save, load something or save something first
  }

  createUserFolders();

  std::ofstream os;
  //save into file
  os.open((CAMPAIGN_SAVE_DIR + "/" + loadedFile + ".dmpsave").c_str());
  if (os.is_open()) {
    myGame.dumpCharacter(os);

    if (mainMessage.size() < 1) {
      mainMessage.clear();
      mainMessage = "Auto Saved to: ";
      mainMessage += loadedFile;
    } else {
      mainMessage += ". Auto Saved to: ";
      mainMessage += loadedFile;
    }

    loadSuccess = true;
    note_last_save(loadedFile);
    os.close();
  }
}
void save_file() {
  if (myGame.character_list.empty()) {
    mainMessage = "Nothing to save - character list empty";
    return;
  }

  createUserFolders();

  // get file save as (with check and reduce) from user
  std::string file;
  std::ofstream os;
  if (loadSuccess == false) {
    std::cout << "Save As: ";
    bool done_first_pass = false;
    bool contains_non_alpha = true;
    do {
      if (done_first_pass) {
        std::cout << file << " is an invalid name. Use only characters a-z & A-Z & 0-9\n";
        std::cout << "Save As: ";
      }
      std::getline(std::cin, file, '\n');
      reduce(file);
      contains_non_alpha = file.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != std::string::npos;
      done_first_pass = true;
    } while (contains_non_alpha);
  } else {
    file = loadedFile;
  }
  //save into save path after above is complete
  os.open((CAMPAIGN_SAVE_DIR + "/" + file + ".dmpsave").c_str());
  if (os.is_open()) {
    myGame.dumpCharacter(os);
    mainMessage = "All data saved in file: " + file;
    loadSuccess = true;
    loadedFile = file;
    note_last_save(loadedFile);
    os.close();
  }
}
