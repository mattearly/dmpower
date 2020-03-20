#include "globalfuncts.h"
#include "terminal_colors.h"
#include <fstream>
#include <string>

///
/// \brief insult_mode currently the two valid modes are 'clean' and 'dirty'
///
std::string insult_mode;

/**
 * clear screens during usage or not
 */
bool clearScreens = true;

///
/// \brief file
/// save location for the user settings
std::string userSettingsFile = "./settings/userSettings.dat";

bool saveUserSettings() {
  std::ofstream saveFileStream(userSettingsFile.c_str());
  if (saveFileStream.is_open()) {
    saveFileStream << "insults=\"" << insult_mode << "\"" << '\n';
    saveFileStream << clearScreens << '\n';
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
  while (choice != 3) {
    if (!first_pass && clearScreens)
      simpleClearScreen();
    std::cout << 
      "\n-------- SETTINGS MENU --------"
      "\n 1. Insult Mode: " << insult_mode << 
      "\n 2. Clear Screens: " << (clearScreens ? "On" : "Off") <<
      "\n 3. Save and exit to " << CYAN << "MAIN MENU" << RESET << 
      "\n-------------------------------\n";
    choice = getNumber("Choice: ", 1, 3);
    switch (choice) {
    case 1: {
      insult_mode = insult_mode.compare("dirty") == 0 ? "clean" : "dirty"; // toggle
    } break;
    case 2:
      clearScreens = clearScreens ? false : true; // toggle
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
  is.open(userSettingsFile.c_str());
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
    // get second variable in insult settings
    is >> clearScreens;
    std::cout << "User settings loaded!\n";
  } else {
    insult_mode = "clean";
    clearScreens = true;
  }
}
