#include "campaign.h"
#include "globalfuncts.h"
#include "charts.h"
#include "gen_reward.h"
#include "gen_experience.h"
#include "gen_name.h"
#include "gen_encounter.h"
#include "gen_insult.h"
#include "terminal_colors.h"
#include <string>
#include <iostream>

using namespace std;

static int choice = 0;

void other_tools();

void menu()
{
  mainMessage = "Dungeon Master Power! (build:" + buildNumber + ")";
  do
  {
    choice = 0;
    if (clearScreens) simpleClearScreen();
    cout << "> " << mainMessage << "\n\n";
    mainMessage = "";
        
    cout << CYAN << "---------- MAIN MENU ----------" << RESET << '\n';
    if (loadedFile.size() > 1)
    {
       cout  << " 1. " << GREEN << "Campaign: '" << loadedFile << "' Characters" << RESET << '\n';
    }
    else  //loadedFile size == 0
    {
       cout  << " 1. " << GREEN << "Build Characters" << RESET << '\n';
    }
    cout << " 2. " << YELLOW << "Generate Loot" << RESET << '\n'
         << " 3. " << MAGENTA << "Other Tools" << RESET << '\n'
         << " 4. Settings\n"
         << " 5. " << RED << "Quit dmpower" << RESET << '\n'
         << CYAN << "-------------------------------" << RESET << '\n';

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
    if (clearScreens) simpleClearScreen();
    cout << ">" << mainMessage << "\n\n";
    mainMessage = "";
    cout << MAGENTA << "------------OTHER TOOLS------------" << RESET << '\n'
         << " 1. Charts\n"
         << " 2. Experience Calculator\n"
         << " 3. Name Generator\n"
         << " 4. Random Encounter\n"
         << " 5. NPC Insult\n"
         << " 6. Back to " << CYAN << "MAIN MENU" << RESET << '\n'
         << MAGENTA << "-----------------------------------" << RESET << '\n';
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

  // reset choice back to 0 after leaving this menu
  if (choice == 6)
  {
    choice = 0;
  }
}
