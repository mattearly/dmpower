#pragma once

#include <iostream>
#include <sstream>
#include <random>
#include <type_traits>
#include <string>
#include "campaign.h"

extern Campaign myGame;
extern std::string mainMessage;
extern void change_settings();
extern bool clearScreens;
extern bool autoSave;
extern bool autoLoad;
extern std::string buildNumber;
extern bool is_random; // for random character gen
extern bool quitBuilding;
extern std::string lastSave;
extern std::string mainMessage;
extern std::string loadedFile;
extern const std::string DATA_DIR;
extern const std::string CAMPAIGN_SAVE_DIR;
extern const std::string SETTINGS_SAVE_DIR;
extern const std::string DOCUMENT_SAVE_DIR;
extern bool loadSuccess;
extern std::string saveVersion;
extern std::string insult_mode;
extern void menu();
extern void set_user_pref_from_file();
extern std::string insult_mode;
extern bool clearScreens;

extern void createUserFolders();
extern void load_last_save();
extern void load_file();
extern void auto_save();
extern void save_file();

const int LARGEST_INPUT_DIGITS = 3;

static std::random_device rgen;
static std::mt19937 mgen(rgen());
static std::uniform_int_distribution<int> rolld4(1, 4);
static std::uniform_int_distribution<int> rolld6(1, 6);
static std::uniform_int_distribution<int> rolld8(1, 8);
static std::uniform_int_distribution<int> rolld10(1, 10);
static std::uniform_int_distribution<int> rolld12(1, 12);
static std::uniform_int_distribution<int> rolld20(1, 20);
static std::uniform_int_distribution<int> rolld100(1, 100);

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
std::string toString(const T& a) {
  std::string tmp = "";
  std::stringstream stringconverter;
  stringconverter << a;
  tmp += stringconverter.str();
  return tmp;
}

/** Returns an integer result from start to end
 * @param start the bottom of the possibility of the random result
 * @param end the top end possibility of the random result
 */
int randomNumber(const int& start, const int& end);

/** Prompts the user with the custom message for a number between a and b
 * @param message Message given to the end user every prompt including retrys
 * @param a Lower end of the valid numbers accepted. Must be less than b.
 * @param b Higher end of the valid numbers accepted. Must be greater than a.
 * @return the valid user choice
 */
int getNumber(const std::string& message, const int& a, const int& b);

/** Asks for the user to enter a number between a and b
 * @param a Lower end of the valid numbers accepted. Must be less than b.
 * @param b Higher end of the valid numbers accepted. Must be greater than a.
 * @return the valid user choice
 */
int getNumber(const int& a, const int& b);

/** Asks for the user to enter a number between a and b or the character 'q'
 * @param a Lower end of the valid numbers accepted. Must be less than b.
 * @param b Higher end of the valid numbers accepted. Must be greater than a.
 * @return the valid user choice or -1 if the user chose to quit
 */
int getNumberOrQ(const int& a, const int& b);

/** Calculates the ability modifier of a start ready for printing
 * @param a the original stat
 * @return a string of the modifier with a + or - prepended accordingly
 */
template <class T>
std::string D_D_Ability_Modifier(const T& a) {
  std::string tmp = "";
  int mod = ((a - 10) / 2);
  if (mod > 0) {
    tmp += "+";
    tmp += toString(mod);
  }
  if (mod <= 0) {
    if (a < 10 && a % 2 == 1) {
      mod--;
    }
    if (mod < 0) {
      tmp += toString(mod);
    } else {
      tmp = "  ";
    }
  }
  return tmp;
}

int getAbilityMod(const int&);

void simpleClearScreen();

/** show end user the message and accepts a 'y' or 'n' (or capital versions of)
 * character from the input stream. Will keep repeating until valid input is given.
 * @param message output message to end user before input prompt
 * @return character 'Y' or 'N' based on user's answer
 */
char getYorN(const std::string& message);

/** show end user the message and accepts a 'y' or 'r' (or capital versions of)
 * character from the input stream. Will keep repeating until valid input is given.
 * @param message output message to end user before input prompt
 * @return character 'Y' or 'R' based on user's answer
 */
char getYorR(const std::string& message);

/** 'yes' or 'retry' or 'quit' - show end user the message and
 * accepts a 'y' or 'r' or 'q' (or capital versions of) character from the input stream.
 * Will keep repeating until valid input is given.
 * @param message output message to end user before input prompt
 * @return character 'Y' or 'R' or 'Q' based on user's answer
 */
char getAorRorQ(const std::string& message);

/** flow control. used to halt the continuation of scrolling, program continues after a newline entry
 */
void pressEnterToContinue();

/** rolls 4d6 drop lowest
 * @return result of highest 3d6 of the 4d6
 */
int rollstats_hi_power();

/** rolls 3d6
 * @return result of the 3d6 roll
 */
int rollstats_standard();

/** Trims whitespace
 * from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 */
std::string trim(const std::string& str, const std::string& whitespace = " \t");

/** Reduces whitespace
 * from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 */
std::string reduce(const std::string& str,
  const std::string& fill = " ",
  const std::string& whitespace = " \t");
