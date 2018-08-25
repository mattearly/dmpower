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

void menu()
{
    mainMessage = "CLI_DUNGEON_MASTER_TOOLKIT build:1";
    choice = 0;
    do
    {
        simpleClearScreen();
        cout << ">";
        cout << mainMessage << endl;
        mainMessage = "";
        cout << CYAN << "\n---------- MAIN MENU ----------" << RESET << "\n"
             << "1. BUILD & MANAGE CHARACTERS\n"
             << "2. LOOT GENERATOR\n"
             << "3. OTHER TOOLS\n"
             << "4. " << RED << "QUIT" << RESET << "\n"
             << CYAN << "-------------------------------" << RESET << "\n";
        choice = getNumber("Enter Choice(1-4): ", 1, 4);

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
            choice = 0;
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
    choice = 0;
    do
    {
        simpleClearScreen();
        cout << mainMessage << endl;
        mainMessage = "";
        cout << YELLOW << "\n---------- SUB  MENU ----------" << RESET << "\n"
             << " 1. Charts\n"
             << " 2. Experience Calculator\n"
             << " 3. Name Generator\n"
             << " 4. Random Encounter\n"
             << " 5. NPC Insult\n"
             << " 6. Back to " << CYAN << "MAIN MENU" << RESET << "\n"
             << YELLOW << "-------------------------------"
             << RESET << "\n";
        choice = getNumber("Enter Choice(1-6): ", 1, 6);
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
            mainMessage = "EXP for Each Party Member = " + to_string((int)rewardXP);
        }
        break;
        case 3:
        {
            CharacterName randomName;
            mainMessage = "A Name: " + randomName.grabRandomName();
        }
        break;
        case 4:
        {
            Encounter encounter;
            mainMessage = encounter.Gen_Encounter();
        }
        break;
        case 5:
        {
            Insult insult;
            mainMessage = "Listen up you " + insult.laydownheat();
        }
        break;
        default:
            break;
        }
    } while (choice < 6);
}