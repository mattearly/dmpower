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
static int choice = 0;
extern void change_settings();

void other_tools();

void menu()
{
  mainMessage = "Dungeon Master Power! (build:5)";
  choice = 0;
  do
  {
    simpleClearScreen();
    cout << "> " << mainMessage << "\n\n";
    mainMessage = "";
    cout << CYAN << "---------- MAIN MENU ----------" << RESET << "\n"
         << " 1. " << GREEN << "BUILD & MANAGE CHARACTERS" << RESET << "\n"
         << " 2. " << YELLOW << "LOOT GENERATION" << RESET << "\n"
         << " 3. " << MAGENTA << "OTHER TOOLS" << RESET << "\n"
         << " 4. SETTINGS\n"
         << " 5. " << RED << "QUIT" << RESET << "\n"
         << CYAN << "-------------------------------" << RESET << "\n";
    choice = getNumber("Choice: ", 1, 5);
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
      other_tools();
      choice = 0;
      break;
    case 4:
      change_settings();
      break;
    default:
      break;
    }
  } while (choice < 5);

  cout << "Exiting Program.\n";
}

void other_tools()
{
  choice = 0;
  do
  {
    simpleClearScreen();
    cout << ">" << mainMessage << "\n\n";
    mainMessage = "";
    cout << MAGENTA << "------------OTHER TOOLS------------" << RESET << "\n"
         << " 1. Charts\n"
         << " 2. Experience Calculator\n"
         << " 3. Name Generator\n"
         << " 4. Random Encounter\n"
         << " 5. NPC Insult\n"
         << " 6. Back to " << CYAN << "MAIN MENU" << RESET << "\n"
         << MAGENTA << "-----------------------------------" << RESET << "\n";
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
      randomName.grabRandomName(mainMessage);
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
      mainMessage = "INSULT: Listen up you" + insult.laydownheat();
    }
      break;
    default:
      break;
    }
  } while (choice < 6);
}
