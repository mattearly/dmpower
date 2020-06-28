#include "charts.h"
#include "globalfuncts.h"
#include "terminal_colors.h"
#include <fstream>
#include <string>

using namespace std;

void Charts::showChartMenu()
{
  const int MAXCHARTCHOICE = 6;
  while (chart_choice != MAXCHARTCHOICE)
  {
    if (clearScreens) simpleClearScreen();
    cout
        << "----------------- CHARTS -----------------\n"
        << " 1. Player Behavioral Problems Flowchart\n"
        << " 2. Poison Sales Chart\n"
        << " 3. Madness Chart\n"
        << " 4. Disease Chart\n"
        << " 5. Level Up Chart\n"
        << " 6. Back to " << MAGENTA << "OTHER TOOLS" << RESET << '\n'
        << "---------------- CHARTS ------------------\n";
    chart_choice = getNumber("Choice: ", 1, MAXCHARTCHOICE);
    switch (chart_choice)
    {
    case 1:
      walkThroughPlayerBehavioralResolutionChart();
      break;
    case 2:
      displayPoisonSalesChart();
      break;
    case 3:
      displayMadnessChart();
      break;
    case 4:
      displayDiseaseChart();
      break;
    case 5:
      displayExperienceChart();
      break;
    case 6:
      return;
    default:
      break;
    }
  }
}

void Charts::displayExperienceChart()
{
  std::cout << "----LEVEL UP CHART----\n"
               "Level   |  EXP requried\n"
               "----------------------\n"
               "   2    |       300\n"
               "   3    |       900\n"
               "   4    |     2,700\n"
               "   5    |     6,500\n"
               "   6    |    14,000\n"
               "   7    |    23,000\n"
               "   8    |    34,000\n"
               "   9    |    48,000\n"
               "  10    |    64,000\n"
               "  11    |    85,000\n"
               "  12    |   100,000\n"
               "  13    |   120,000\n"
               "  14    |   140,000\n"
               "  15    |   165,000\n"
               "  16    |   195,000\n"
               "  17    |   225,000\n"
               "  18    |   265,000\n"
               "  19    |   305,000\n"
               "  20    |   355,000\n\n";
  pressEnterToContinue();
}

void Charts::displayPoisonSalesChart()
{
  fstream poisonfile;
  poisonfile.open(DATA_DIR + "poisonlist.dat");
  if (!poisonfile.is_open())
  {
    cout << "Error Opening poisonlist.dat, check your file.\n\n";
  }
  string poisons = "";
  if (poisonfile.is_open())
  {
    while (!poisonfile.eof())
    {
      poisons += poisonfile.get();
    }
  }
  poisons.erase(poisons.length() - 1, poisons.length()); //erase that last random [box] character
  cout << poisons;
  pressEnterToContinue();
}

void Charts::displayDiseaseChart()
{
  fstream diseasefile;
  diseasefile.open(DATA_DIR + "diseaselist.dat");
  if (!diseasefile.is_open())
  {
    cout << "Error Opening diseaselist.dat, check your file.\n\n";
  }
  else
  {
    string diseases = "";
    if (diseasefile.is_open())
    {
      while (!diseasefile.eof())
      {
        diseases += diseasefile.get();
      }
    }
    diseases.erase(diseases.length() - 1, diseases.length()); //erase that last random [box] character
    cout << diseases;
  }
  pressEnterToContinue();
}

void Charts::displayMadnessChart()
{
  fstream madnessfile;
  madnessfile.open(DATA_DIR + "madnesslist.dat");
  if (!madnessfile.is_open())
  {
    cout << "Error Opening madnesslist.dat, check your file.\n\n";
  }
  string madness = "";
  if (madnessfile.is_open())
  {
    while (!madnessfile.eof())
    {
      madness += madnessfile.get();
    }
  }
  madness.erase(madness.length() - 1, madness.length()); //erase that last random [box] character
  cout << madness;
  pressEnterToContinue();
}

void Charts::walkThroughPlayerBehavioralResolutionChart()
{
  if (clearScreens) simpleClearScreen();
  cout << "So a player is giving you trouble eh?\n"
       << "First, talk to them about it.\n";

  char answer = getYorN("Did they listen and change their behavior? (y/n): ");
  if (answer == 'Y')
  {
    cout << "Excellent! Problem solved. Everyone can move on with their lives.";
    pressEnterToContinue();
    return;
  }

  answer = getYorN("Does this thing that is happening bother anyone else? (y/n): ");
  if (answer == 'Y')
  {
    answer = getYorN("Is this really that big of a deal to the rest of your group? (y/n): ");
    if (answer == 'Y')
    {
      cout << "Sounds like you should consider removing this player from your group. Problem solved.";
    }
    else
    { // 'N'
      cout << "Okay, then it is probably best to just drop it and move on. Problem solved.";
    }
    pressEnterToContinue();
    return;
  }
  else
  { // 'N'
    answer = getYorN("Are you really salty about this and can't get over it? (y/n): ");
    if (answer == 'Y')
    {
      cout << "Sounds like it might be best that you find a new group. Problem solved.";
    }
    else
    { // 'N'
      cout << "It is probably best to just let it go (queue theme song from Disney's Frozen). Problem solved.";
    }
    pressEnterToContinue();
    return;
  }
}
