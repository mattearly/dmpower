#include "globalfuncts.h"
#include <fstream>

using namespace std;

extern string mainMessage;

///
/// \brief insult_mode currently the two valid modes are 'clean' and 'dirty'
///
string insult_mode;


///
/// \brief save_insult_preference saves the chosen preference to local file
///
void save_insult_preference() {

  std::string file = "./settings/local_user_settings.dat";
  std::ofstream os;

  os.open(file.c_str());
  if (os.is_open())
  {
    os << "insults=\"" << insult_mode << "\"\n";
    mainMessage = "Insult mode (\"" + insult_mode + "\") set and saved locally.";
    os.close();
  }
}

///
/// \brief change_settings allows user to change available program settings
///
void change_settings() {
  simpleClearScreen();
  cout << "-------- LOCAL SETTINGS --------\n"
          " 1. Change Insult Mode \n"
          " 2. Back to " << CYAN << "MAIN MENU" << RESET << "\n"
          "--------------------------------\n";

  int choice = getNumber("Choice: ", 1, 2);
  switch (choice) {
  case 1:
  {
    int innerchoice = getNumber("1=clean, 2=dirty; Choice: ", 1, 2);
    if (innerchoice == 1) {
      insult_mode = "clean";
    } else { // user entered 2
      insult_mode = "dirty";
    }
    save_insult_preference();
  }
    break;
  default:
    break;
  }
}

///
/// \brief set_user_pref_from_file sets the users settings from their file (if it exists)
/// otherwise, sets everything to default
/// currenlty just insult_mode setting
///
void set_user_pref_from_file() {

  std::string file = "./settings/local_user_settings.dat";
  std::ifstream os;

  os.open(file.c_str());
  if (os.is_open())
  {
    // first line in insult settings
    std::string readinstring;
    getline(os, readinstring);
    // insults="clean"
    // insults="dirty"
    insult_mode = readinstring.substr(9, 5);
    cout << "insult_mode set to: " << insult_mode;
    if (insult_mode.compare("dirty") != 0 && insult_mode.compare("clean") != 0) {
      cout << "insult_mode should be set but failed to be a proper string 'clean' or 'dirty'\n";
    }
    os.close();
  } else {
    insult_mode = "clean";
    cout << "Insult Mode defaulted to 'clean'\n";

    //more settings later
  }
  //more settings later
}
