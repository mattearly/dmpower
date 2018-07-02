#include "campaign.h"
#include "globalfuncts.h"
#include "charts.h"
#include "gen_reward.h"
#include "gen_experience.h"
#include "gen_name.h"
#include "gen_encounter.h"
#include "gen_insult.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;

extern void save_file(bool &, string &, const Campaign &);

void main_loop(bool &loadSuccess, string &loadedFile, Campaign &myGame)
{
    simpleClearScreen();
    int choice = 0;
    do
    {
        cout << YELLOW << "\n---------- MAIN MENU ----------" << RESET << "\n"
             << "1. CHARACTERS\n"
             << "2. LOOT\n"
             << "3. Charts\n"
             << "4. Experience Calculator\n"
             << "5. Name Generator\n"
             << "6. Random Encounter\n"
             << "7. NPC Insult\n"
             << "8. Save Current\n"
             << "9. Save & Quit\n"
             << "10. Quit without Saving\n"
             << YELLOW << "-------------------------------\n"
             << RESET << "\n";
        choice = getNumber("Choice: ", 1, 10);
        switch (choice)
        {
        case 1:
            myGame.pc_menu();
            break;
        case 2:
        {
            Magic_Items gen;
            gen.treasure_menu();
        }
        break;
        case 3:
        {
            Charts chart;
            chart.showChartMenu();
        }
        break;
        case 4:
        {
            Gen_Experience gen;
            float rewardXP = gen.xpgenerator();
            cout << "EXP for Each Party Member = " << GREEN << rewardXP << RESET << "\n\n";
        }
        break;
        case 5:
        {
            CharacterName randomName;
            simpleClearScreen();
            cout << "Here is a name: " << randomName.grabRandomName() << "\n\n";
        }
        break;
        case 6:
        {
            Encounter encounter;
            simpleClearScreen();
            cout << encounter.Gen_Encounter();
            pressEnterToContinue();
        }
        break;
        case 7:
        {
            Insult insult;
            simpleClearScreen();
            cout << "Maybe this will make the PCs mad: " << insult.laydownheat() << "\n\n";
        }
        break;
        case 8:
            save_file(loadSuccess, loadedFile, myGame);
            break;
        case 9:
            save_file(loadSuccess, loadedFile, myGame);
            cout << "Exiting Program.\n";
            break;
        case 10:
            cout << "Exiting Program.\n";
        default:
            break;
        }
    } while (choice < 9);
}