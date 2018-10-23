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
    cout << "A Random Name For Your Character:\n\n    " << random_name << endl
         << endl
         << "1 - accept " << endl
         << "2 - try again" << endl
         << "3 - leave random name generaor and enter your own name\n\n";
    choice = getNumber(1, 3);
    if (choice == 3)
    {
      random_name.clear();
      return;
    }
  }
}
