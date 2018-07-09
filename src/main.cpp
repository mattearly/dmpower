#include "campaign.h"
#include "globalfuncts.h"
#include <string>
#include <cstdlib>

using namespace std;

extern void load_file();
extern void main_loop();

string mainMessage = "";
bool loadSuccess = false;
string loadedFile = "";
Campaign myGame;

int main()
{

    simpleClearScreen();

    cout << "|-----------------------------------------------------------|" << endl;
    cout << "|" << YELLOW << "DM-Power-Core-Version" << RESET << "- " << RED << "Dungeons & Dragons 5e" << RESET << "- DM's Toolkit" << CYAN << "" << RESET << " |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "| * Design & Code by:  " << GREEN << "matthewjearly@gmail.com" << RESET << "              |" << endl;
    cout << "| * Repo:  " << GREEN << "github.com/mattearly/DM-Power-Core-Version" << RESET << "       |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;

    load_file();

    main_loop();

    return EXIT_SUCCESS;

}
