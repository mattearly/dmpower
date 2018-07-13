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

using namespace std;

extern Campaign myGame;
extern string mainMessage;
int choice = 0;

void submenu();

void main_loop()
{
    choice = 0;
    simpleClearScreen();
    do
    {
        cout << mainMessage << endl;
        mainMessage = "";
        cout << YELLOW << "\n---------- MAIN MENU ----------" << RESET << "\n"
             << "1. CHARACTERS\n"
             << "2. LOOT GENERATOR\n"
             << "3. OTHER TOOLS\n"
             << "4. QUIT\n"
             << YELLOW << "-------------------------------" << RESET << "\n";
        choice = getNumber("Choice: ", 1, 4);
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
            submenu();
        }
        break;
        default:
            break;
        }
    } while (choice < 4);
    cout << "Exiting Program.\n";
}

void submenu()
{
    simpleClearScreen();
    choice = 0;
    do
    {
        cout << mainMessage << endl;
        mainMessage = "";
        cout << YELLOW << "\n---------- SUB  MENU ----------" << RESET << "\n"
             << " 1. Charts\n"
             << " 2. Experience Calculator\n"
             << " 3. Name Generator\n"
             << " 4. Random Encounter\n"
             << " 5. NPC Insult\n"
             << " 6. Back to " << CYAN << "MAIN MENU" << RESET << "\n"
             << YELLOW << "-------------------------------\n"
             << RESET << "\n";
        choice = getNumber("Choice: ", 1, 6);
        switch (choice)
        {

        case 1:
        {
            Charts chart;
            chart.showChartMenu();
        }
        break;
        case 2:
        {
            Gen_Experience gen;
            float rewardXP = gen.xpgenerator();
            cout << "EXP for Each Party Member = " << GREEN << rewardXP << RESET << "\n\n";
        }
        break;
        case 3:
        {
            CharacterName randomName;
            simpleClearScreen();
            cout << "Here is a name: " << randomName.grabRandomName() << "\n\n";
        }
        break;
        case 4:
        {
            Encounter encounter;
            cout << encounter.Gen_Encounter();
            pressEnterToContinue();
        }
        break;
        case 5:
        {
            Insult insult;
            simpleClearScreen();
            cout << "Maybe this will make the PCs mad: " << insult.laydownheat() << "\n\n";
        }
        break;
        default:
            break;
        }
    } while (choice < 6);
    cout << "Exiting Program.\n";
}