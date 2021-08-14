#include "globalfuncts.h"
#include "terminal_colors.h"
#include <fstream>
#include <string>


bool saveUserSettings() {
  createUserFolders();
  std::ofstream saveFileStream(SETTINGS_SAVE_DIR + "/userSettings.dat");
  if (saveFileStream.is_open()) {
    saveFileStream << "insults=\"" << insult_mode << "\"" << '\n';
    saveFileStream << clearScreens << '\n';
    saveFileStream << autoSave << '\n';
    saveFileStream << autoLoad << '\n';
    return true;
  }
  return false;
}

///
/// \brief change_settings allows user to change available program settings
///
void change_settings() {
  if (clearScreens)
    simpleClearScreen();
  int choice = 0;
  bool first_pass = true;
  int NUMCHOICES = 5;
  while (choice != NUMCHOICES) {
    if (!first_pass && clearScreens)
      simpleClearScreen();
    std::cout <<
      "\n-------- SETTINGS MENU --------"
      "\n 1. Insult Mode: " << insult_mode <<
      "\n 2. Clear Screens: " << (clearScreens ? "On" : "Off") <<
      "\n 3. Auto Save: " << (autoSave ? "On" : "Off") <<
      "\n 4. Auto Load: " << (autoLoad ? "On" : "Off") <<
      "\n 5. Save and exit to " << CYAN << "MAIN MENU" << RESET <<
      "\n-------------------------------\n";
    choice = getNumber("Choice: ", 1, NUMCHOICES);
    switch (choice) {
    case 1:
    {
      insult_mode = insult_mode.compare("dirty") == 0 ? "clean" : "dirty"; // toggle
    } break;
    case 2:
      clearScreens = !clearScreens; // toggle
      break;
    case 3:
      autoSave = !autoSave; //toggle
      break;
    case 4:
      autoLoad = !autoLoad; //toggle
      break;
    case 5:
      break;
    default:
      break;
    }
    first_pass = false;
  }
  if (!saveUserSettings()) {
    std::cout << "ERROR, SETTINGS SAVE FAILED";
  }
}

///
/// \brief set_user_pref_from_file sets the users settings from their file (if
/// it exists) otherwise, sets everything to default currenlty just insult_mode
/// setting
///
void set_user_pref_from_file() {
  std::ifstream is;
  is.open((SETTINGS_SAVE_DIR + "/userSettings.dat").c_str());
  if (is.is_open()) {
    std::string readinstring;

    // first line in insult settings
    getline(is, readinstring);
    insult_mode = readinstring.substr(9, 5);
    if (insult_mode.compare("dirty") != 0 &&
      insult_mode.compare("clean") != 0) {
      std::cout << "insult_mode should be set but failed to be a proper string "
        "'clean' or 'dirty'\n";
    }
    // get second clearScreens boolean setting
    is >> clearScreens;
    is >> autoSave;
    is >> autoLoad;
    std::cout << "User settings loaded!\n";
  } else {
    insult_mode = "clean";
    clearScreens = true;
    autoSave = false;
  }
}
