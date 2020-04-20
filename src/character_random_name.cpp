#include "globalfuncts.h"
#include "characters.h"
#include "gen_name.h"
#include <string>

using namespace std;

void Generic_Character_Class::suggestRandomName(std::string &random_name)
{
  CharacterName namegen;
  int choice = 0;
  while (choice != 1)
  {
    random_name.clear();
    namegen.grabRandomName(random_name);
    cout << "Random Name Generated:\n\n  -> " << random_name << '\n'
         << '\n'
         << " 1. Accept '" << random_name << "' as this character's name." << '\n'
         << " 2. Generate another Random name" << '\n'
         << " 3. Leave Random Name Generator\n\n";
    choice = getNumber("Choice: ", 1, 3);
    if (choice == 1)
    {
      cout << "Accepted '" << random_name << "' as your character's name.\n";
    }
    if (choice == 3)
    {
      random_name.clear();
      return;
    }
  }
}

void Generic_Character_Class::giveRandomName(std::string &random_name)
{
  random_name.clear();
  CharacterName namegen;
  namegen.grabRandomName(random_name);
}
