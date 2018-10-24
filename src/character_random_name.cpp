#include "globalfuncts.h"
#include "characters.h"
#include "gen_name.h"
#include <string>

using namespace std;

// for random name suggestion while building a new character
void Generic_Character_Class::suggestRandomName(std::string& random_name)
{
  CharacterName namegen;
  int choice = 0;
  while (choice != 1)
  {
    random_name.clear();
    namegen.grabRandomName(random_name);
    cout << "Random Name Generated:\n\n  -> " << random_name << endl
         << endl
         << " 1. Accept '" << random_name << "' as this character's name." << endl
         << " 2. Generate another Random name" << endl
         << " 3. Leave Random Name Generator\n\n";
    choice = getNumber("Choice: ", 1, 3);
    if (choice == 1) {
      cout << "Accepted '" << random_name << "' as your character's name.\n";
    }
    if (choice == 3)
    {
      random_name.clear();
      return;
    }
  }
}
