/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2017 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#include "campaign.h"
#include "gen_reward.h"
#include "gen_name.h"
#include "gen_insult.h"
#include "gen_encounter.h"
#include "gen_experience.h"
#include "charts.h"
#include <cstdlib>

using namespace std;

extern void load_file(bool &, string &, Campaign &);
extern void save_file(bool &, string &, const Campaign &);

int main()
{
    bool loadSuccess = 0;
    string loadedFile = "";
    simpleClearScreen();
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "|" << YELLOW << "Dungeon Master Power " << RESET << "- " << RED << "Dungeons & Dragons " << RESET << "- " << CYAN << "5e Core Version" << RESET << "|" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "| * Design & Code by:  " << GREEN << "matthewjearly@gmail.com" << RESET << "              |" << endl;
    cout << "| * Repo:  " << GREEN << "github.com/mattearly/DM-Power-Core-Version" << RESET << "       |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    int choice = 0;
    Campaign mygame;
    load_file(loadSuccess, loadedFile, mygame);
    do
    {
        cout << YELLOW << "\n---------- MAIN MENU ----------\n"
             << RESET
             << "1. Characters\n"
             << "2. Magic Item and Loot Generators\n"
             << "3. Charts\n"
             << "4. Experience Calculator\n"
             << "5. Name Generator\n"
             << "6. Random Encounter\n"
             << "7. NPC Insult\n"
             << "8. Save Current\n"
             << "9. Save & Quit\n"
             << "10. Quit without Saving\n"
             << YELLOW << "-------------------------------\n"
             << RESET
             << endl;
        choice = getNumber("Choice: ", 1, 10);

        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
            mygame.pc_menu();
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
            save_file(loadSuccess, loadedFile, mygame);
            break;
        case 9:
            save_file(loadSuccess, loadedFile, mygame);
            cout << "Exiting Program.\n";
            break;
        case 10:
            cout << "Exiting Program.\n";
        default:
            break;
        }
    } while (choice < 9);
    return EXIT_SUCCESS;
}
