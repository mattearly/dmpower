#include "gen_name.h"
#include "characters.h"
#include "terminal_colors.h"
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "globalfuncts.h"

using std::cin;
using std::cout;
using std::sort;
using std::string;
using std::vector;

Generic_Character_Class::Generic_Character_Class()
{
  wipeStats();
}

Generic_Character_Class::~Generic_Character_Class() {}

std::string Generic_Character_Class::getRace() const
{
  return race;
}

// mutators
void Generic_Character_Class::setName()
{
  if (is_random)
  {
    string random_name;
    CharacterName name_generator;
    name_generator.grabRandomName(random_name);
    char_name = random_name;
    return;
  }

  cout << "Name Your Character! (can be edited later)\n\n";
  cout << "  " << MAGENTA << "NAME RULES" << RESET << '\n';
  cout << "    Length must be 2 or more characters.\n";
  cout << "    Must be unique, no other characters with this name in the campaign.\n";
  cout << "    First letter is automatically Capitalized.\n";
  cout << "    Enter " << GREEN << "random" << RESET << " or " << GREEN << "ok" << RESET << " to be suggested a random name.\n";
  cout << "    Enter " << GREEN << "no" << RESET << " to be given a random name.\n\n";

  string i_name;
  do
  {
    cout << "Enter Name: ";
    getline(cin, i_name);
    i_name[0] = toupper(i_name[0]); //makes the first letter of the name uppercase
    i_name = reduce(i_name);        //gets rid of leading and trailing whitespace and any extra spaces in between
    if (i_name.size() < 2)
    {
      cout << "Invalid name, try another.\n";
    }
    if (i_name == "Ok" || i_name == "Random")
    {
      suggestRandomName(i_name);
    }
    else if (i_name == "No")
    {
      giveRandomName(i_name);
    }
  } while (i_name.size() < 2);
  char_name = i_name;
  if (clearScreens)
    simpleClearScreen();
}

void Generic_Character_Class::setRace(Generic_Character_Class &v)
{
  if (clearScreens)
    simpleClearScreen();
  const int num_races = 22;
  cout << "Choose a Race for your Character:\n\n";
  cout << " 1. Aarakocra\n";
  cout << " 2. Aasimar\n";
  cout << " 3. Changeling\n";
  cout << " 4. Dragonborn\n";
  cout << " 5. Dwarf\n";
  cout << " 6. Elf\n";
  cout << " 7. Firbolg\n";
  cout << " 8. Genasi\n";
  cout << " 9. Gnome\n";
  cout << " 10. Goliath\n";
  cout << " 11. Half-elf  \n";
  cout << " 12. Halfing\n";
  cout << " 13. Half-orc\n";
  cout << " 14. Human\n";
  cout << " 15. Kenku\n";
  cout << " 16. Lizardfolk\n";
  cout << " 17. Shifter\n";
  cout << " 18. Tabaxi\n";
  cout << " 19. Tiefling\n";
  cout << " 20. Tortle\n";
  cout << " 21. Triton\n";
  cout << " 22. Warforged\n\n";
  int ss = getNumber("Choose Race: ", 1, num_races);
  Races *parent = nullptr;
  switch (ss)
  {
  case 1:
    parent = new Aarakocra;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 2:
    parent = new Aasimar;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 3:
    parent = new Changeling;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 4:
    parent = new Dragonborn;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 5:
    parent = new Dwarf;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 6:
    parent = new Elf;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 7:
    parent = new Firbolg;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 8:
    parent = new Genasi;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 9:
    parent = new Gnome;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 10:
    parent = new Goliath;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 11:
    parent = new Halfelf;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 12:
    parent = new Halfling;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 13:
    parent = new Halforc;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 14:
    parent = new Human;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 15:
    parent = new Kenku;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 16:
    parent = new Lizardfolk;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 17:
    parent = new Shifter;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 18:
    parent = new Tabaxi;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 19:
    parent = new Tiefling;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 20:
    parent = new Tortle;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 21:
    parent = new Triton;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  case 22:
    parent = new Warforged;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
    break;
  default:
    break;
  }

  if (parent != nullptr)
  {
    delete parent;
  }
}

void Generic_Character_Class::setAlignment()
{
  if (clearScreens)
    simpleClearScreen();
  cout << "Pick an Alignment for " << char_name << ".\n\n";
  cout << "1. Chaotic Evil     6. Neutral Good\n";
  cout << "2. Chaotic Neutral  7. Lawful Evil\n";
  cout << "3. Chaotic Good     8. Lawful Neutral\n";
  cout << "4. Neutral Evil     9. Lawful Good\n";
  cout << "5. True Neutral\n\n";
  int c = getNumber("Alignment choice: ", 1, 9);
  if (c == 1)
    alignment = "CE";
  if (c == 2)
    alignment = "CN";
  if (c == 3)
    alignment = "CG";
  if (c == 4)
    alignment = "NE";
  if (c == 5)
    alignment = "TN";
  if (c == 6)
    alignment = "NG";
  if (c == 7)
    alignment = "LE";
  if (c == 8)
    alignment = "LN";
  if (c == 9)
    alignment = "LG";
}

void Generic_Character_Class::setAllStats()
{
  vector<int> stats;
  cout << "Assign Ability Stat style for "
       << GREEN << char_name << RESET << '\n';
  cout << "---------------------------------------\n";

  cout << "1. " << RED
  << "High-Powered " << RESET << "Roll Set : roll " << GREEN << "4d6 6 " << RESET << "times, dropping lowest die each time\n";

  cout << "2. " << YELLOW
  << "Legit " << RESET << "Roll Set        : roll " << GREEN << "3d6 6 " << RESET << "times\n";

  cout << "3. " << BLUE
  << "Standard " << RESET << "Array Set    : " << GREEN << "[15, 14, 13, 12, 10, 8]" << RESET << '\n';

  cout << "4. " << CYAN
  << "Custom " << RESET << "Array Set      : Enter in your own custom stats(starting bounds still apply).\n\n";

  int stat_ver_choice = 0;

  if (is_random)
  {
    // standard array stats with random characters
    stat_ver_choice = 3;
  }
  else
  {
    stat_ver_choice = getNumber("Choice: ", 1, 4);
  }

  switch (stat_ver_choice)
  {
  case 1:
    for (int i = 0; i < 6; i++)
    {
      stats.push_back(rollstats_hi_power());
    }
    break;
  case 2:
    for (int i = 0; i < 6; i++)
    {
      stats.push_back(rollstats_standard());
    }
    break;
  case 3:
    stats = {15, 14, 13, 12, 10, 8};
    break;
  case 4:
    setStr(getNumber("Enter starting Strength(3-18): ", 3, 18));
    setDex(getNumber("Enter starting Dexterity(3-18): ", 3, 18));
    setCon(getNumber("Enter starting Constitution(3-18): ", 3, 18));
    setInt(getNumber("Enter starting Intelligence(3-18): ", 3, 18));
    setWis(getNumber("Enter starting Wisdom(3-18): ", 3, 18));
    setCha(getNumber("Enter starting Charisma(3-18): ", 3, 18));
    break;
  default:
    break;
  }
  if (stat_ver_choice != 4)
  {
    sort(stats.begin(), stats.end(), [](int a, int b) { //sort 6 stats highest to lowest
      return a > b;
    });
    stats.push_back(-1); //final stat control
    char acceptStatsControl;
    do
    {
      cout << "\nStaring Character: \n";
      cout << GREEN << char_name << ", Level " << level << " " << char_class << RESET << '\n';
      for (int i = 0; i < 7; i++) //when i == 6, last iteration is controlled by -1 at end of array
      {
        if (i != 6)
        {
          cout << "Stats Left To Assign to : ";
          for (int j = i; j < 6; j++)
          {
            cout << CYAN << stats[j] << RESET;
            if (j != 5)
              cout << ", ";
          }
          cout << '\n';
        }
        assignStats(stats[i]); //when stats[i] == -1, controlled differently
      }

      acceptStatsControl = getAorRorQ("Stats done. Accept, Redo, or Quit? (a/r/q): ");
      if (acceptStatsControl == 'R')
      {
        setAllStatsAtOnce(0, 0, 0, 0, 0, 0);
      }
      else if (acceptStatsControl == 'Q')
      {
        // reset everything and return to character menu
        quitBuilding = true;
        break;
      }
    } while (acceptStatsControl != 'A');
  }
  // pressEnterToContinue();
}

void Generic_Character_Class::setLanguage(const string &message)
{
  bool success = 0;
  while (!success)
  {
    cout << message << '\n';
    if (auran)
      cout << " 1 - Auran(Already Known)\n";
    else
      cout << " 1 - Auran\n";
    if (abyssal)
      cout << " 2 - Abyssal(Already Known)\n";
    else
      cout << " 2 - Abyssal\n";
    if (celestial)
      cout << " 3 - Celestial(Already Known)\n";
    else
      cout << " 3 - Celestial\n";
    if (deep_speech)
      cout << " 4 - Deep Speech(Already Known)\n";
    else
      cout << " 4 - Deep Speech\n";
    if (draconic)
      cout << " 5 - Draconic(Already Known)\n";
    else
      cout << " 5 - Draconic\n";
    if (druidic)
      cout << " 6 - Druidic(Already Known)\n";
    else
      cout << " 6 - Druidic\n";
    if (dwarvish)
      cout << " 7 - Dwarvish(Already Known)\n";
    else
      cout << " 7 - Dwarvish\n";
    if (elvish)
      cout << " 8 - Elvish(Already Known)\n";
    else
      cout << " 8 - Elvish\n";
    if (giant)
      cout << " 9 - Giant(Already Known)\n";
    else
      cout << " 9 - Giant\n";
    if (gnomish)
      cout << " 10 - Gnomish(Already Known)\n";
    else
      cout << " 10 - Gnomish\n";
    if (goblin)
      cout << " 11 - Goblin(Already Known)\n";
    else
      cout << " 11 - Goblin\n";
    if (gnoll)
      cout << " 12 - Gnoll(Already Known)\n";
    else
      cout << " 12 - Gnoll\n";
    if (halfling)
      cout << " 13 - Halfling(Already Known)\n";
    else
      cout << " 13 - Halfling\n";
    if (infernal)
      cout << " 14 - Infernal(Already Known)\n";
    else
      cout << " 14 - Infernal\n";
    if (orc)
      cout << " 15 - Orc(Already Known)\n";
    else
      cout << " 15 - Orc\n";
    if (primordial)
      cout << " 16 - Primordial(Already Known)\n";
    else
      cout << " 16 - Primordial\n";
    if (sylvan)
      cout << " 17 - Sylvan(Already Known)\n";
    else
      cout << " 17 - Sylvan\n";
    if (undercommon)
      cout << " 18 - Undercommon(Already Known)\n";
    else
      cout << " 18 - Undercommon\n";
    if (aquan)
      cout << " 19 - Aquan(Already Known)\n";
    else
      cout << " 19 - Aquan\n";
    if (aarakocra)
      cout << " 20 - Aarakocra(Already Known)\n\n";
    else
      cout << " 20 - Aarakocra\n\n";
    int ss = getNumber("Language Choice: ", 1, 20);
    if (ss == 1 && auran == 0)
    {
      auran = true;
      cout << "Auran Language learned!\n";
      success = 1;
    }
    if (ss == 2 && abyssal == 0)
    {
      abyssal = true;
      cout << "Abyssal Language learned!\n";
      success = 1;
    }
    if (ss == 3 && celestial == 0)
    {
      celestial = true;
      cout << "Celestial Language learned!\n";
      success = 1;
    }
    if (ss == 4 && deep_speech == 0)
    {
      deep_speech = true;
      cout << "Deep Speech Language learned!\n";
      success = 1;
    }
    if (ss == 5 && draconic == 0)
    {
      draconic = true;
      cout << "Draconic Language learned!\n";
      success = 1;
    }
    if (ss == 6 && druidic == 0)
    {
      druidic = true;
      cout << "Druidic Language learned!\n";
      success = 1;
    }
    if (ss == 7 && dwarvish == 0)
    {
      dwarvish = true;
      cout << "Dwarvish Language learned!\n";
      success = 1;
    }
    if (ss == 8 && elvish == 0)
    {
      elvish = true;
      cout << "Elvish Language learned!\n";
      success = 1;
    }
    if (ss == 9 && giant == 0)
    {
      giant = true;
      cout << "Giant Language learned!\n";
      success = 1;
    }
    if (ss == 10 && gnomish == 0)
    {
      gnomish = true;
      cout << "Gnomish Language learned!\n";
      success = 1;
    }
    if (ss == 11 && goblin == 0)
    {
      goblin = true;
      cout << "Goblin Language learned!\n";
      success = 1;
    }
    if (ss == 12 && gnoll == 0)
    {
      gnoll = true;
      cout << "Gnoll Language learned!\n";
      success = 1;
    }
    if (ss == 13 && halfling == 0)
    {
      halfling = true;
      cout << "Halfling Language learned!\n";
      success = 1;
    }
    if (ss == 14 && infernal == 0)
    {
      infernal = true;
      cout << "Infernal Language learned!\n";
      success = 1;
    }
    if (ss == 15 && orc == 0)
    {
      orc = true;
      cout << "Orc Language learned!\n";
      success = 1;
    }
    if (ss == 16 && primordial == 0)
    {
      primordial = true;
      cout << "Primordial Language learned!\n";
      success = 1;
    }
    if (ss == 17 && sylvan == 0)
    {
      sylvan = true;
      cout << "Sylvan Language learned!\n";
      success = 1;
    }
    if (ss == 18 && undercommon == 0)
    {
      undercommon = true;
      cout << "Undercommon Language learned!\n";
      success = 1;
    }
    if (ss == 19 && aquan == 0)
    {
      aquan = true;
      cout << "Aquan Language learned!\n";
      success = 1;
    }
    if (ss == 20 && aarakocra == 0)
    {
      aarakocra = true;
      cout << "Aarakocra Language learned!\n";
      success = 1;
    }
    if (success == 0)
      cout << "Language already known, choose another.\n\n";
  }
}

void Generic_Character_Class::setInstrument(const string &message, const int &many)
{
  int count = 0;
  cout << message;
  while (count < many)
  {
    cout << "1. Bagpipes   6.  Lyre\n"
         << "2. Drum       7.  Horn\n"
         << "3. Dulcimer   8.  Pan Flute\n"
         << "4. Flute      9.  Shawm\n"
         << "5. Lute       10. Viol\n\n";
    int ss = getNumber("Choice: ", 1, 10);
    if (ss == 1 && bagpipes == 0)
    {
      bagpipes = true;
      cout << "Bagpipes Instrument learned!\n";
      count++;
    }
    if (ss == 2 && drum == 0)
    {
      drum = true;
      cout << "Drum Instrument learned!\n";
      count++;
    }
    if (ss == 3 && dulcimer == 0)
    {
      dulcimer = true;
      cout << "Dulcimer Instrument learned!\n";
      count++;
    }
    if (ss == 4 && flute == 0)
    {
      flute = true;
      cout << "Flute Instrument learned!\n";
      count++;
    }
    if (ss == 5 && lute == 0)
    {
      lute = true;
      cout << "Lute Instrument learned!\n";
      count++;
    }
    if (ss == 6 && lyre == 0)
    {
      lyre = true;
      cout << "Lyre Instrument learned!\n";
      count++;
    }
    if (ss == 7 && horn == 0)
    {
      horn = true;
      cout << "Horn Instrument learned!\n";
      count++;
    }
    if (ss == 8 && pan_flute == 0)
    {
      pan_flute = true;
      cout << "Pan Flute Instrument learned!\n";
      count++;
    }
    if (ss == 9 && shawm == 0)
    {
      shawm = true;
      cout << "Shawm Instrument learned!\n";
      count++;
    }
    if (ss == 10 && viol == 0)
    {
      viol = true;
      cout << "Viol Instrument learned!\n";
      count++;
    }
    if (count < many)
      cout << "Choose another Instrument.\n\n";
  }
}

void Generic_Character_Class::setTools(const int &many)
{
  int count = 0;
  cout << "Pick " << many << " Tool/Supplies Proficiencie(s).\n\n";
  while (count < many)
  {
    cout << "1. Alchemist Tools          10. Leatherworker's Supplies\n"
         << "2. Brewer's Supplies        11. Mason's Tools\n"
         << "3. Calligrapher's Supplies  12. Painter's Supplies\n"
         << "4. Carpenter's Tools        13. Potter Tools\n"
         << "5. Cartographer's Tools     14. Smith's Tools\n"
         << "6. Cobbler's Tools          15. Tinker's Tools\n"
         << "7. Cook's Utensils          16. Weaver's Tools\n"
         << "8. Glassblower Tools        17. Woodcarver's Tools\n"
         << "9. Jeweler's Tools\n\n";
    int ss = getNumber("Choice: ", 1, 17);
    if (ss == 1 && alchemist == 0)
    {
      alchemist = true;
      cout << "Alchemists Tools learned!\n";
      count++;
    }
    if (ss == 2 && brewer == 0)
    {
      brewer = true;
      cout << "Brewers Tools learned!\n";
      count++;
    }
    if (ss == 3 && calligrapher == 0)
    {
      calligrapher = true;
      cout << "Calligrapher Tools learned!\n";
      count++;
    }
    if (ss == 4 && carpenter == 0)
    {
      carpenter = true;
      cout << "Carpenter Tools learned!\n";
      count++;
    }
    if (ss == 5 && cartographer == 0)
    {
      cartographer = true;
      cout << "Cartographer Tools learned!\n";
      count++;
    }
    if (ss == 6 && cobbler == 0)
    {
      cobbler = true;
      cout << "Cobbler Tools learned!\n";
      count++;
    }
    if (ss == 7 && cook == 0)
    {
      cook = true;
      cout << "Cook Tools learned!\n";
      count++;
    }
    if (ss == 8 && glassblower == 0)
    {
      glassblower = true;
      cout << "Glassblower Tools learned!\n";
      count++;
    }
    if (ss == 9 && jeweler == 0)
    {
      jeweler = true;
      cout << "Jeweler Tools learned!\n";
      count++;
    }
    if (ss == 10 && leatherworker == 0)
    {
      leatherworker = true;
      cout << "Leatherworker Tools learned!\n";
      count++;
    }
    if (ss == 11 && mason == 0)
    {
      mason = true;
      cout << "Mason Tools learned!\n";
      count++;
    }
    if (ss == 12 && painter == 0)
    {
      painter = true;
      cout << "Painter Tools learned!\n";
      count++;
    }
    if (ss == 13 && potter == 0)
    {
      potter = true;
      cout << "Potter Tools learned!\n";
      count++;
    }
    if (ss == 14 && smith == 0)
    {
      smith = true;
      cout << "Smithing Tools learned!\n";
      count++;
    }
    if (ss == 15 && tinker == 0)
    {
      tinker = true;
      cout << "Tinker Tools learned!\n";
      count++;
    }
    if (ss == 16 && weaver == 0)
    {
      weaver = true;
      cout << "Weaver Tools learned!\n";
      count++;
    }
    if (ss == 17 && woodcarver == 0)
    {
      woodcarver = true;
      cout << "Woodcarver Tools learned!\n";
      count++;
    }
    if (count < many)
      cout << "Choose another.\n\n";
  }
}

void Generic_Character_Class::setProficiencyBonus()
{
  proficiency_bonus = (2 + ((level - 1) / 4));
}

void Generic_Character_Class::increase2statsby1()
{
  int ss = 0, tmp = 0;
  cout << "Give two differnt stats +1: \n\n";
  for (int i = 0; i < 2; ++i)
  {
    switch (ss)
    {
    case 0:
      cout << " 1. +1 Str\n 2. +1 Dex\n 3. +1 Con\n"
           << " 4. +1 Int\n 5. +1 Wis\n 6. +1 Cha\n\n";
      break;
    case 1:
      cout << " 1. (can't choose)\n 2. +1 Dex\n 3. +1 Con\n"
           << " 4. +1 Int\n 5. +1 Wis\n 6. +1 Cha\n\n";
      break;
    case 2:
      cout << " 1. +1 Str\n 2. (can't choose)\n 3. +1 Con\n"
           << " 4. +1 Int\n 5. +1 Wis\n 6. +1 Cha\n\n";
      break;
    case 3:
      cout << " 1. +1 Str\n 2. +1 Dex\n 3. (can't choose)\n"
           << " 4. +1 Int\n 5. +1 Wis\n 6. +1 Cha\n\n";
      break;
    case 4:
      cout << " 1. +1 Str\n 2. +1 Dex\n 3. +1 Con\n"
           << " 4. (can't choose)\n 5. +1 Wis\n 6. +1 Cha\n\n";
      break;
    case 5:
      cout << " 1. +1 Str\n 2. +1 Dex\n 3. +1 Con\n"
           << " 4. +1 Int\n 5. (can't choose)\n 6. +1 Cha\n\n";
      break;
    case 6:
      cout << " 1. +1 Str\n 2. +1 Dex\n 3. +1 Con\n"
           << " 4. +1 Int\n 5. +1 Wis\n 6. (can't choose)\n\n";
    default:;
    }

    do
    {
      ss = getNumber("Enter a number to choose: ", 1, 6);
    } while (ss == tmp);

    if (ss == 1)
    {
      if (strength < 20)
      {
        strength += 1;
        cout << "Strength Increased by 1!\n\n";
      }
      else
      {
        cout << "Strength is already 20 or greater you beefcake. Pick something else.\n\n";
        i--;
      }
      tmp = 1;
    }
    if (ss == 2)
    {
      if (dexterity < 20)
      {
        dexterity += 1;
        cout << "Dexterity Increased by 1!\n\n";
      }
      else
      {
        cout << "Dexterity is already 20 or greater, what are you some kind of cheetah? Pick something else.\n\n";
        i--;
      }
      tmp = 2;
    }
    if (ss == 3)
    {
      if (constitution < 20)
      {
        constitution += 1;
        cout << "Constitution Increased by 1!\n\n";
      }
      else
      {
        cout << "Constitution is already 20 or greater, mountain man. Pick something else.\n\n";
        i--;
      }
      tmp = 3;
    }
    if (ss == 4)
    {
      if (intelligence < 20)
      {
        intelligence += 1;
        cout << "Intelligence Increased by 1!\n\n";
      }
      else
      {
        cout << "Intelligence is already 20 or greater, Einstien. Pick something else.\n\n";
        i--;
      }
      tmp = 4;
    }
    if (ss == 5)
    {
      if (wisdom < 20)
      {
        wisdom += 1;
        cout << "Wisdom Increased by 1!\n\n";
      }
      else
      {
        cout << "Wisdom is already 20 or greater, you see. Pick something else.\n\n";
        i--;
      }
      tmp = 5;
    }
    if (ss == 6)
    {
      if (charisma < 20)
      {
        charisma += 1;
        cout << "Charisma Increased by 1!\n\n";
      }
      else
      {
        cout << "Charisma is already 20 or greater and you can't talk your way into making it higher. Pick something else.\n\n";
        i--;
      }
      tmp = 6;
    }
    if (i < 1)
      cout << "Choose Another.\n\n";
  }
}

void Generic_Character_Class::increase1statby2()
{
  int ss = 0, tmp = 0;
  cout << "Choose a stat to give +2: \n\n";
  for (int i = 0; i < 1; i++)
  {
    switch (ss)
    {
    case 0:
      cout << " 1. +2 Str\n 2. +2 Dex\n 3. +2 Con"
           << "\n 4. +2 Int\n 5. +2 Wis\n 6. +2 Cha\n\n";
      break;
    case 1:
      cout << " 1. (can't choose)\n 2. +2 Dex\n 3. +2 Con"
           << "\n 4. +2 Int\n 5. +2 Wis\n 6. +2 Cha\n\n";
      ;
      break;
    case 2:
      cout << " 1. +2 Str\n 2. (can't choose)\n 3. +2 Con"
           << "\n 4. +2 Int\n 5. +2 Wis\n 6. +2 Cha\n\n";
      break;
    case 3:
      cout << " 1. +2 Str\n 2. +2 Dex\n 3. (can't choose)"
           << "\n 4. +2 Int\n 5. +2 Wis\n 6. +2 Cha\n\n";
      break;
    case 4:
      cout << " 1. +2 Str\n 2. +2 Dex\n 3. +2 Con"
           << "\n 4. (can't choose)\n 5. +2 Wis\n 6. +2 Cha\n\n";
      break;
    case 5:
      cout << " 1. +2 Str\n 2. +2 Dex\n 3. +2 Con"
           << "\n 4. +2 Int\n 5. (can't choose)\n 6. +2 Cha\n\n";
      break;
    case 6:
      cout << " 1. +2 Str\n 2. +2 Dex\n 3. +2 Con"
           << "\n 4. +2 Int\n 5. +2 Wis\n 6. (can't choose)\n\n";
    default:;
    }

    do
    {
      ss = getNumber("Enter a number to choose: ", 1, 6);
    } while (ss == tmp);

    if (ss == 1)
    {
      if (strength < 19)
      {
        strength += 2;
        cout << "Strength Increased by 2!\n\n";
      }
      else
      {
        cout << "Strength is already 19 or greater you beefcake. Pick something else.\n\n";
        i--;
      }
      tmp = 1;
    }
    if (ss == 2)
    {
      if (dexterity < 19)
      {
        dexterity += 2;
        cout << "Dexterity Increased by 2!\n\n";
      }
      else
      {
        cout << "Dexterity is already 19 or greater, what are you some kind of cheetah? Pick something else.\n\n";
        i--;
      }
      tmp = 2;
    }
    if (ss == 3)
    {
      if (constitution < 19)
      {
        constitution += 2;
        cout << "Constitution Increased by 2!\n\n";
      }
      else
      {
        cout << "Constitution is already 19 or greater, mountain man. Pick something else.\n\n";
        i--;
      }
      tmp = 3;
    }
    if (ss == 4)
    {
      if (intelligence < 19)
      {
        intelligence += 2;
        cout << "Intelligence Increased by 2!\n\n";
      }
      else
      {
        cout << "Intelligence is already 19 or greater, Einstien. Pick something else.\n\n";
        i--;
      }
      tmp = 4;
    }
    if (ss == 5)
    {
      if (wisdom < 19)
      {
        wisdom += 2;
        cout << "Wisdom Increased by 2!\n\n";
      }
      else
      {
        cout << "Wisdom is already 19 or greater, you see. Pick something else.\n\n";
        i--;
      }
      tmp = 5;
    }
    if (ss == 6)
    {
      if (charisma < 19)
      {
        charisma += 2;
        cout << "Charisma Increased by 2!\n\n";
      }
      else
      {
        cout << "Charisma is already 19 or greater and you can't talk your way into making it higher. Pick something else.\n\n";
        i--;
      }
      tmp = 6;
    }
  }
}

void Generic_Character_Class::setLandtype()
{
  bool valid_choice = false;
  while (!valid_choice)
  {
    // show landtype menu
    if (!artic)
      cout << "1. Artic";
    else
      cout << "1. " << RED << "Artic (already known)" << RESET;
    cout << '\n';

    if (!coast)
      cout << "2. Coast";
    else
      cout << "2. " << RED << "Coast (already known)" << RESET;
    cout << '\n';

    if (!desert)
      cout << "3. Desert";
    else
      cout << "3. " << RED << "Desert (already known)" << RESET;
    cout << '\n';

    if (!forest)
      cout << "4. Forest";
    else
      cout << "4. " << RED << "Forest (already known)" << RESET;
    cout << '\n';

    if (!grassland)
      cout << "5. Grassland";
    else
      cout << "5. " << RED << "Grassland (already known)" << RESET;
    cout << '\n';

    if (!mountain)
      cout << "6. Mountain";
    else
      cout << "6. " << RED << "Mountain (already known)" << RESET;
    cout << '\n';

    if (!swamp)
      cout << "7. Swamp";
    else
      cout << "7. " << RED << "Swamp (already known)" << RESET;
    cout << '\n';

    if (!underdark)
      cout << "8. Underdark";
    else
      cout << "8. " << RED << "Underdark (already known)" << RESET;
    cout << "\n\n";

    // get player's choice
    int ss = getNumber("Select Land Type: ", 1, 8);

    // gain landtype or retry if invalid
    if (ss == 1 && !artic)
      artic = valid_choice = true;
    if (ss == 2 && !coast)
      coast = valid_choice = true;
    if (ss == 3 && !desert)
      desert = valid_choice = true;
    if (ss == 4 && !forest)
      forest = valid_choice = true;
    if (ss == 5 && !grassland)
      grassland = valid_choice = true;
    if (ss == 6 && !mountain)
      mountain = valid_choice = true;
    if (ss == 7 && !swamp)
      swamp = valid_choice = true;
    if (ss == 8 && !underdark)
      underdark = valid_choice = true;

    if (!valid_choice)
      cout << "Already known, choose another.\n";
  }
}

void Generic_Character_Class::setFavoredEnemy()
{
  bool done = false;
  cout << " 1. Abberations    8. Fiends"
       << "\n 2. Beasts         9. Giants"
       << "\n 3. Celestials    10. Monstrosities"
       << "\n 4. Constructs    11. Oozes"
       << "\n 5. Dragons       12. Plants"
       << "\n 6. Elementals    13. Undead"
       << "\n 7. Fey           14. Two Humanoids\n\n";
  while (!done)
  {
    int ss = getNumber("Choice(1-14): ", 1, 14);
    if (ss == 14)
    {
      twohumanoids++;
      done = true;
      continue;
    }
    if (ss == 1 && !aberrations)
    {
      aberrations = true;
      done = true;
    }
    else if (ss == 2 && !beasts)
    {
      beasts = true;
      done = true;
    }
    else if (ss == 3 && !celestials)
    {
      celestials = true;
      done = true;
    }
    else if (ss == 4 && !constructs)
    {
      constructs = true;
      done = true;
    }
    else if (ss == 5 && !dragons)
    {
      dragons = true;
      done = true;
    }
    else if (ss == 6 && !elementals)
    {
      elementals = true;
      done = true;
    }
    else if (ss == 7 && !fey)
    {
      fey = true;
      done = true;
    }
    else if (ss == 8 && !fiends)
    {
      fiends = true;
      done = true;
    }
    else if (ss == 9 && !giants)
    {
      giants = true;
      done = true;
    }
    else if (ss == 10 && !monstrosities)
    {
      monstrosities = true;
      done = true;
    }
    else if (ss == 11 && !oozes)
    {
      oozes = true;
      done = true;
    }
    else if (ss == 12 && !plants)
    {
      plants = true;
      done = true;
    }
    else if (ss == 13 && !undead)
    {
      undead = true;
      done = true;
    }
    else
      cout << "Already a Favored Enemy - Try again.";
  }
  favored_enemy_languages = true;
}

void Generic_Character_Class::levelUpStats()
{
  int ss = getNumber(" 1 - Increase a Stat by 2\n 2 - Increase two Stats by 1\n 3 - Gain a Feat\n\nLevel Up Choice(1-3): ", 1, 3);
  switch (ss)
  {
  case 1:
    increase1statby2();
    break;
  case 2:
    increase2statsby1();
    break;
  case 3:
    setAnyFeat();
  default:;
  }
  // pressEnterToContinue();
}

// displayers
void Generic_Character_Class::landtype(std::ostream& stream) const
{
  if (artic)
    stream << "Artic, ";
  if (coast)
    stream << "Coast, ";
  if (desert)
    stream << "Desert, ";
  if (forest)
    stream << "Forest, ";
  if (grassland)
    stream << "Grassland, ";
  if (mountain)
    stream << "Mountain, ";
  if (swamp)
    stream << "Swamp, ";
  if (underdark)
    stream << "Underdark";
}

void Generic_Character_Class::creaturetype(std::ostream& stream) const
{
  if (aberrations)
    stream << "Aberration, ";
  if (beasts)
    stream << "Beasts, ";
  if (celestials)
    stream << "Celestials, ";
  if (constructs)
    stream << "Constructs, ";
  if (dragons)
    stream << "Dragons, ";
  if (elementals)
    stream << "Elementals, ";
  if (fey)
    stream << "Fey, ";
  if (fiends)
    stream << "Fiends, ";
  if (giants)
    stream << "Giants, ";
  if (monstrosities)
    stream << "Monstrosities, ";
  if (oozes)
    stream << "Oozes, ";
  if (plants)
    stream << "Plants, ";
  if (undead)
    stream << "Undead, ";
  if (twohumanoids > 0)
    stream << "Humanoids(" << twohumanoids * 2 << ")";
}

// helpers
void Generic_Character_Class::setStr(const int &s) { strength = s; }

void Generic_Character_Class::setDex(const int &d) { dexterity = d; }

void Generic_Character_Class::setCon(const int &c) { constitution = c; }

void Generic_Character_Class::setInt(const int &i) { intelligence = i; }

void Generic_Character_Class::setWis(const int &w) { wisdom = w; }

void Generic_Character_Class::setCha(const int &ch) { charisma = ch; }

void Generic_Character_Class::assignStats(int &s)
{
  if (s != -1)
    cout << "Assign Stat -> " << MAGENTA << s << RESET << " <- to: \n\n";
  else
    cout << "\nFinal Stats:\n\n";
  if (strength == 0)
    cout << " 1. Strength\n";
  else
    cout << YELLOW << " 1. Strength(DONE)" << RESET << "     STR: " << strength << '\n';

  if (dexterity == 0)
    cout << " 2. Dexterity\n";
  else
    cout << YELLOW << " 2. Dexterity(DONE)" << RESET << "    DEX: " << dexterity << '\n';

  if (constitution == 0)
    cout << " 3. Constitution\n";
  else
    cout << YELLOW << " 3. Constitution(DONE)" << RESET << " CON: " << constitution << '\n';

  if (intelligence == 0)
    cout << " 4. Intelligence\n";
  else
    cout << YELLOW << " 4. Intelligence(DONE)" << RESET << " INT: " << intelligence << '\n';

  if (wisdom == 0)
    cout << " 5. Wisdom\n";
  else
    cout << YELLOW << " 5. Wisdom(DONE)" << RESET << "       WIS: " << wisdom << '\n';

  if (charisma == 0)
    cout << " 6. Charisma\n\n";
  else
    cout << YELLOW << " 6. Charisma(DONE)" << RESET << "     CHA: " << charisma << "\n\n";
  if (s != -1)
  {
    bool okchoice = false;
    do
    {
      int ss = getNumber("Assignment Choice(1-6): ", 1, 6);
      switch (ss)
      {
      case 1:
        if (strength == 0)
        {
          setStr(s);
          okchoice = true;
        }
        else
          cout << "Strength already set, choose another.\n";
        break;
      case 2:
        if (dexterity == 0)
        {
          setDex(s);
          okchoice = true;
        }
        else
          cout << "Dexterity already set, choose another.\n";
        break;
      case 3:
        if (constitution == 0)
        {
          setCon(s);
          okchoice = true;
        }
        else
          cout << "Constitution already set, choose another.\n";
        break;
      case 4:
        if (intelligence == 0)
        {
          setInt(s);
          okchoice = true;
        }
        else
          cout << "Intelligence already set, choose another.\n";
        break;
      case 5:
        if (wisdom == 0)
        {
          setWis(s);
          okchoice = true;
        }
        else
          cout << "Wisdom already set, choose another.\n";
        break;
      case 6:
        if (charisma == 0)
        {
          setCha(s);
          okchoice = true;
        }
        else
          cout << "Charisma already set, choose another.\n";
        break;
      default:;
      }
    } while (!okchoice);
  }
}

void Generic_Character_Class::setAllStatsAtOnce(const int &s, const int &d, const int &c, const int &i, const int &w, const int &ch)
{
  strength = s;
  dexterity = d;
  constitution = c;
  intelligence = i;
  wisdom = w;
  charisma = ch;
}

void Generic_Character_Class::wipeStats()
{
  char_name = "";
  alignment = "";
  race = "";
  initialSkillsSet = 0;
  spellcasting = 0;
  timeless_body = 0;
  evasion = 0;
  unarmored_defense = 0;
  fighting_style = 0;
  defense = dueling = 0;
  great_weapon_fighting = 0;
  protection = 0;
  arcana_d = 0;
  divine_domain = 0;
  death_d = 0;
  knowledge_d = 0;
  life_d = 0;
  light_d = 0;
  nature_d = 0;
  tempest_d = 0;
  trickery_d = 0;
  war_d = 0;
  second_wind = 0;
  martial_archtype = 0;
  archery = 0;
  two_weapon_fighting = 0;
  champion = 0;
  battle_master = 0;
  eldritch_knight = 0;
  purple_dragon_knight = 0;
  reckless_attack = 0;
  danger_sense = 0;
  primal_path = 0;
  fast_movement = 0;
  feral_instinct = 0;
  relentless_rage = 0;
  persistant_rage = 0;
  indomitable_might = 0;
  primal_champion = 0;
  path_of_the_battlerager = 0;
  path_of_the_berseker = 0;
  path_of_the_totem_warrior = 0;
  bear_totem = 0;
  eagle_totem = 0;
  wolf_totem = 0;
  jack_of_all_trades = 0;
  bard_college = 0;
  font_of_inspiration = 0;
  countercharm = 0;
  superior_inspiration = 0;
  college_of_lore = 0;
  college_of_valor = 0;
  additional_magical_secrets = 0;
  druidic = 0;
  wild_shape = 0;
  druid_circle = 0;
  beast_spells = 0;
  archdruid = 0;
  circle_of_the_moon = 0;
  circle_of_the_land = 0;
  monastic_tradition = 0;
  deflect_missles = 0;
  slow_fall = 0;
  stunning_strike = 0;
  ki_empowered_strikes = 0;
  stillness_of_mind = 0;
  purity_of_body = 0;
  tongue_of_the_sun_and_moon = 0;
  diamond_soul = 0;
  empty_body = 0;
  perfect_self = 0;
  way_of_the_open_hand = 0;
  way_of_the_four_elements = 0;
  way_of_the_long_death = 0;
  way_of_the_shadow = 0;
  way_of_the_sun_soul = 0;
  unarmored_movement_improvement = 0;
  divine_sense = 0;
  lay_on_hands = 0;
  divine_health = 0;
  divine_health = 0;
  sacred_oath = 0;
  aura_of_protection = 0;
  aura_of_courage = 0;
  cleansing_touch = 0;
  aura_improvments = 0;
  oath_of_devotion = 0;
  oath_of_ancients = 0;
  oath_of_vengeance = 0;
  oath_of_the_crown = 0;
  oathbreaker = 0;
  ranger_archetype = 0;
  primeval_awareness = 0;
  lands_stride = 0;
  hide_in_plain_sight = 0;
  vanish = 0;
  feral_senses = 0;
  foe_slayer = 0;
  hunter = 0;
  beast_master = 0;
  sneak_attack = 0;
  thieves_cant = 0;
  cunning_action = 0;
  roguish_archetype = 0;
  uncanny_dodge = 0;
  reliable_talent = 0;
  blindsense = 0;
  slippery_mind = 0;
  elusive = 0;
  stroke_of_luck = 0;
  thief = 0;
  assassin = 0;
  arcane_trickster = 0;
  mastermind = 0;
  swashbuckler = 0;
  sorcerous_origin = 0;
  font_of_magic = 0;
  sorcerous_restoration = 0;
  draconic_bloodline = 0;
  wild_magic = 0;
  storm_sorcery = 0;
  otherworldly_patron = 0;
  pact_magic = 0;
  pact_boon = 0;
  eldritch_master = 0;
  archfey = 0;
  fiend = 0;
  great_old_one = 0;
  the_undying = 0;
  arcane_recovery = 0;
  arcane_tradition = 0;
  spell_mastery = 0;
  signature_spell = 0;
  abjuration = 0;
  conjuration = 0;
  divination = 0;
  enchantment = 0;
  evocation = 0;
  illusion = 0;
  necromancy = 0;
  transmutation = 0;
  bladesinging = 0;
  artic = 0;
  coast = 0;
  desert = 0;
  forest = 0;
  grassland = 0;
  mountain = 0;
  swamp = 0;
  underdark = 0;
  aberrations = 0;
  beasts = 0;
  celestials = 0;
  constructs = 0;
  dragons = 0;
  elementals = 0;
  fey = 0;
  fiends = 0;
  giants = 0;
  monstrosities = 0;
  oozes = 0;
  plants = 0;
  undead = 0;
  strSave = 0;
  dexSave = 0;
  conSave = 0;
  intSave = 0;
  wisSave = 0;
  chaSave = 0;
  acrobatics = 0;
  animal_handling = 0;
  arcana = 0;
  athletics = 0;
  deception = 0;
  history = 0;
  insight = 0;
  intimidation = 0;
  investigation = 0;
  medicine = 0;
  nature = 0;
  perception = 0;
  performance = 0;
  persuasion = 0;
  religion = 0;
  sleight_of_hand = 0;
  stealth = 0;
  survival = 0;
  alert = 0;
  athlete = 0;
  actor = 0;
  charger = 0;
  crossbow_expert = 0;
  defensive_duelist = 0;
  dual_wielder = 0;
  dungeon_delver = 0;
  durable = 0;
  elemental_adept = 0;
  grappler = 0;
  great_weapon_master = 0;
  healer = 0;
  heavily_armored = 0;
  heavy_armor_master = 0;
  inspiring_leader = 0;
  keen_mind = 0;
  lightly_armored = 0;
  linguist = 0;
  lucky = 0;
  mage_slayer = 0;
  magic_initiate = 0;
  martial_adept = 0;
  medium_armor_master = 0;
  mobile = 0;
  moderately_armored = 0;
  mounted_combatant = 0;
  observant = 0;
  polearm_master = 0;
  resilient = 0;
  ritual_caster = 0;
  savage_attacker = 0;
  sentinel = 0;
  sharpshooter = 0;
  shield_master = 0;
  skilled = 0;
  skulker = 0;
  spell_sniper = 0;
  tavern_brawler = 0;
  tough = 0;
  war_caster = 0;
  weapon_master = 0;
  svirfneblin_magic = 0;
  auran = 0;
  abyssal = 0;
  aarakocra = 0;
  aquan = 0;
  celestial = 0;
  common = 0;
  deep_speech = 0;
  draconic = 0;
  dwarvish = 0;
  elvish = 0;
  giant = 0;
  gnomish = 0;
  goblin = 0;
  gnoll = 0;
  halfling = 0;
  infernal = 0;
  orc = 0;
  primordial = 0;
  sylvan = 0;
  undercommon = 0;
  artificers_lore = 0;
  brave = 0;
  breath_weapon_acid = 0;
  breath_weapon_ltg = 0;
  breath_weapon_fire = 0;
  breath_weapon_poison = 0;
  breath_weapon_cold = 0;
  darkvision = 0;
  devils_tongue = 0;
  draconic_ancestry_black = 0;
  draconic_ancestry_blue = 0;
  draconic_ancestry_brass = 0;
  draconic_ancestry_bronze = 0;
  draconic_ancestry_copper = 0;
  draconic_ancestry_gold = 0;
  draconic_ancestry_green = 0;
  draconic_ancestry_red = 0;
  draconic_ancestry_silver = 0;
  draconic_ancestry_white = 0;
  drow_magic = 0;
  drow_weapon_training = 0;
  dwarven_armor_training = 0;
  dwarven_combat_training = 0;
  dwarven_resilience = 0;
  dwarven_toughness = 0;
  duergar_magic = 0;
  duergar_resilience = 0;
  elf_weapon_training = 0;
  fey_ancestry = 0;
  fleet_of_foot = 0;
  halflinglucky = 0;
  halfling_nimbleness = 0;
  hellfire = 0;
  hellish_resistance = 0;
  infernal_legacy = 0;
  mask_of_the_wild = 0;
  natural_illusionist = 0;
  naturally_stealthy = 0;
  speak_with_small_beasts = 0;
  stone_camouflage = 0;
  stonecunning = 0;
  stout_resilience = 0;
  superior_darkvision = 0;
  trance = 0;
  firbolg_magic = 0;
  hidden_step = 0;
  powerful_build = 0;
  speech_of_beast_and_leaf = 0;
  silent_speech = 0;
  damage_resist_acid = 0;
  damage_resist_ltg = 0;
  damage_resist_fire = 0;
  damage_resist_poison = 0;
  damage_resist_cold = 0;
  sunlight_sensitivity = 0;
  alchemist = 0;
  brewer = 0;
  calligrapher = 0;
  carpenter = 0;
  cartographer = 0;
  cobbler = 0;
  cook = 0;
  glassblower = 0;
  jeweler = 0;
  leatherworker = 0;
  mason = 0;
  painter = 0;
  potter = 0;
  smith = 0;
  tinker = 0;
  weaver = 0;
  woodcarver = 0;
  disguise = 0;
  forgery = 0;
  herbalism = 0;
  navigator = 0;
  poisoner = 0;
  thieves = 0;
  vehicle = 0;
  disguise = 0;
  forgery = 0;
  herbalism = 0;
  navigator = 0;
  poisoner = 0;
  thieves = 0;
  vehicle = 0;
  bagpipes = 0;
  drum = 0;
  dulcimer = 0;
  flute = 0;
  lute = 0;
  lyre = 0;
  horn = 0;
  pan_flute = 0;
  shawm = 0;
  viol = 0;
  rages = 0;
  level = 0;
  clericlevelupmenus = 0;
  fighterlevelupmenus = 0;
  roguelevelupmenus = 0;
  wizardlevelupmenus = 0;
  barbarianlevelupmenus = 0;
  druidlevelupmenus = 0;
  paladinlevelupmenus = 0;
  sorcererlevelupmenus = 0;
  bardlevelupmenus = 0;
  monklevelupmenus = 0;
  rangerlevelupmenus = 0;
  warlocklevelupmenus = 0;
  hitdicesize = 0;
  move_speed = 0;
  fly_speed = 0;
  swim_speed = 0;
  climb_speed = 0;
  proficiency_bonus = 0;
  extra_attack = 0;
  expertise = 0;
  channel_divinity = 0;
  divine_domain_feature = 0;
  divine_intervention = 0;
  cleric_cantrips_known = 0;
  action_surge = 0;
  martial_archtype_feature = 0;
  indomitable = 0;
  eldritch_spells_known = 0;
  rage_damage = 0;
  path_feature = 0;
  brutal_critical = 0;
  bardic_inspiration = 0;
  song_of_rest = 0;
  bard_college_feature = 0;
  magical_secrets = 0;
  bard_spells_known = 0;
  bard_cantrips_known = 0;
  druid_circle_feature = 0;
  druid_cantrips_known = 0;
  monastic_tradition_feature = 0;
  ki = 0;
  unarmored_movement = 0;
  martial_arts = 0;
  sacred_oath_feature = 0;
  divine_smite = 0;
  favored_enemy = 0;
  favored_enemy_languages = 0;
  natural_explorer = 0;
  ranger_archetype_feature = 0;
  ranger_spells_known = 0;
  roguish_archetype_feature = 0;
  arcane_t_spells_known = 0;
  sorcerous_origin_feature = 0;
  metamagic = 0;
  sorcery_points = 0;
  sorcerer_spells_known = 0;
  sorcerer_cantrips_known = 0;
  warlock_slot_level = 0;
  eldritch_invocations_known = 0;
  warlock_spells_known = 0;
  warlock_spell_slots = 0;
  warlock_cantrips_known = 0;
  otherworldly_patron_feature = 0;
  mystic_arcanum = 0;
  arcane_tradition_feature = 0;
  wizard_cantrips_known = 0;
  strength = 0;
  dexterity = 0;
  constitution = 0;
  intelligence = 0;
  wisdom = 0;
  charisma = 0;
  first_ss = 0;
  second_ss = 0;
  third_ss = 0;
  forth_ss = 0;
  fifth_ss = 0;
  sixth_ss = 0;
  seventh_ss = 0;
  eighth_ss = 0;
  ninth_ss = 0;
  warlock_ss = 0;
  twohumanoids = 0;
  backgroundofpc = NOBACKGROUND;
  custom_background_name = "na";
  destroy_undead = 0;
  wild_shape_improvement = 0;
  radiant_soul = 0;
  radiant_consumption = 0;
  necrotic_shroud = 0;
  light_bearer = 0;
  healing_hands = 0;
  damage_resist_necrotic = 0;
  damage_resist_radiant = 0;
  stones_endurance = 0;
  expert_forgery = 0;
  mimicry = 0;
  lizardfolk_bite = 0;
  cunning_artisan = 0;
  hold_breath = 0;
  natural_armor = 0;
  hungry_jaws = 0;
  amphibious = 0;
  control_air_and_water = 0;
  emissary_of_the_sea = 0;
  guardian_of_the_depths = 0;
  composite_plating = 0;
  living_construct = 0;
  shapechanger = 0;
  shifting = 0;
  shell = 0;
  retreat_to_shell = 0;
  turtle_snapper = 0;
  razorback = 0;
  razor_fist = 0;
  softshell = 0;
  nomad = 0;
  shell_master = 0;
  feline_agility = 0;
  cats_claws = 0;
  talons = 0;
  unending_breath = 0;
  mingle_with_the_wind = 0;
  earth_walk = 0;
  merge_with_stone = 0;
  reach_to_the_blaze = 0;
  call_to_the_wave = 0;
}
