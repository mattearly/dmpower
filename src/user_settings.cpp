#include "globalfuncts.h"
#include "terminal_colors.h"
#include <fstream>
#include <string>

extern std::string mainMessage;

///
/// \brief insult_mode currently the two valid modes are 'clean' and 'dirty'
///
std::string insult_mode;

///
/// \brief file
///save location for the user settings
std::string file = "./settings/local_user_settings.dat";

///
/// \brief save_insult_preference saves the chosen preference to local file
///
void save_insult_preference()
{
  std::ofstream os;
  os.open(file.c_str());
  if (os.is_open())
  {
    os << "insults=\"" << insult_mode << "\"\n";
    mainMessage = "Insult mode set to -> " + insult_mode;
    os.close();
  }
}

///
/// \brief change_settings allows user to change available program settings
///
void change_settings()
{
  simpleClearScreen();
  mainMessage = "Current settings: \n\n";
  std::ifstream is;
  is.open(file.c_str());
  if (is.is_open())
  {

    std::string tmp;
    while (getline(is, tmp))
    {
      mainMessage += " " + tmp + "\n";
    }
    std::cout << "\n\n";
    is.close();
  }
  int choice = 0;
  bool first_pass = true;
  while (choice != 2)
  {
    if (!first_pass)
      simpleClearScreen();
    std::cout << "> " << mainMessage << std::endl;
    std::cout << "\n-------- SETTINGS MENU --------\n"
            " 1. Insult Mode \n"
            " 2. Back to " << CYAN << "MAIN MENU" << RESET << "\n"
            "-------------------------------\n";
    choice = getNumber("Choice: ", 1, 2);
    switch (choice)
    {
    case 1:
    {
      int innerchoice = getNumber("---\n 1. set to clean\n 2. set to dirty\n---\nChoice: ", 1, 2);
      if (innerchoice == 1)
      {
        insult_mode = "clean";
      }
      else
      { // user entered 2
        insult_mode = "dirty";
      }
      save_insult_preference();
    }
    break;
    default:
      break;
    }
    first_pass = false;
  }
}

///
/// \brief set_user_pref_from_file sets the users settings from their file (if it exists)
/// otherwise, sets everything to default
/// currenlty just insult_mode setting
///
void set_user_pref_from_file()
{

  std::ifstream is;

  is.open(file.c_str());
  if (is.is_open())
  {
    // first line in insult settings
    std::string readinstring;
    getline(is, readinstring);
    insult_mode = readinstring.substr(9, 5);
    std::cout << "insult_mode set to: " << insult_mode;
    if (insult_mode.compare("dirty") != 0 && insult_mode.compare("clean") != 0)
    {
      std::cout << "insult_mode should be set but failed to be a proper std::string 'clean' or 'dirty'\n";
    }
    is.close();
  }
  else
  {
    insult_mode = "clean";
    std::cout << "Insult Mode defaulted to 'clean'\n";
    //more settings later
  }
  //more settings later
}
