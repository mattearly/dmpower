#include "characters.h"
#include "terminal_colors.h"
#include <string>
#include <iostream>
#include "globalfuncts.h"

using namespace std;

void Generic_Character_Class::updateCharacter(const Campaign &game)
{
  int ss = 0;
  do
  {
    if (clearScreens)
      simpleClearScreen();

    character_sheet();

    cout
        << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
        << " 1. LEVEL UP!" << '\n'
        << " 2. Change Name" << '\n'
        << " 3. Change Alignment" << '\n'
        << " 4. Custom Ability Stats" << '\n'
        << " 5. Grant New Skill Proficiency" << '\n'
        << " 6. Grant New Feat" << '\n'
        << " 7. Back to " << GREEN << "CHARACTER MANAGER" << RESET << '\n'
        << '\n';
    ss = getNumber("Choice: ", 1, 7);
    switch (ss)
    {
    case 1:
      updateLevel();
      break;
    case 2:
      updateName(game);
      break;
    case 3:
    {
      cout << "Current Alignment is: " << alignment << '\n';
      cout << "Pick new Alignment for " << char_name << ".\n\n"
           << "1. Chaotic Evil     6. Neutral Good"
           << "\n2. Chaotic Neutral  7. Lawful Evil"
           << "\n3. Chaotic Good     8. Lawful Neutral"
           << "\n4. Neutral Evil     9. Lawful Good"
           << "\n5. True Neutral\n\n";
      int c = getNumber("Alignment choice(1-9): ", 1, 9);
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
    break;
    case 4:
    {
      int ss;
      char answ;
      do
      {
        cout << "Current Ability Stats: \n\n"
             << "1. Str: " << strength << '\n'
             << "2. Dex: " << dexterity << '\n'
             << "3. Con: " << constitution << '\n'
             << "4. Int: " << intelligence << '\n'
             << "5. Wis: " << wisdom << '\n'
             << "6. Cha: " << charisma << '\n'
             << '\n';
        ss = getNumber("Choose a stat to edit(1-6): ", 1, 6);
        switch (ss)
        {
        case 1:
          setStr(getNumber("Enter new Strength(1-30): ", 1, 30));
          break;
        case 2:
          setDex(getNumber("Enter new Dexterity(1-30): ", 1, 30));
          break;
        case 3:
          setCon(getNumber("Enter new Constitution(1-30): ", 1, 30));
          break;
        case 4:
          setInt(getNumber("Enter new Intelligence(1-30): ", 1, 30));
          break;
        case 5:
          setWis(getNumber("Enter new Wisdom(1-30): ", 1, 30));
          break;
        case 6:
          setCha(getNumber("Enter new Charisma(1-30): ", 1, 30));
          break;
        default:
          break;
        }
        cout << "New Stats: \n\n"
             << "1. Str: " << strength << '\n'
             << "2. Dexterity: " << dexterity << '\n'
             << "3. Constitution: " << constitution << '\n'
             << "4. Intelligence: " << intelligence << '\n'
             << "5. Wisdom: " << wisdom << '\n'
             << "6. Charisma: " << charisma << '\n'
             << '\n';
        answ = getYorN("Would you like to change more stats?(y/n):");
      } while (answ != 'N');
    }
    break;
    case 5:
      setAnySkill("Updating Character", 1);
      break;
    case 6:
      setAnyFeat();
      break;
    default:;
    }
    if (ss != 7)
      pressEnterToContinue();
  } while (ss != 7);
  if (!autoSave) mainMessage = "DON'T FORGET TO SAVE!";
}

void Generic_Character_Class::updateName(const Campaign &game)
{
  bool goodname = false;
  string tmp;
  while (!goodname)
  {
    do
    {
      cout << "Current Name: " << char_name << "\n New Name: ";
      getline(cin, tmp);
      tmp[0] = toupper(tmp[0]);
      if (tmp.size() < 2 || tmp[0] == ' ')
      {
        cout << "Invalid name, try another.\n";
      }
    } while (tmp.size() < 2 || tmp[0] == ' ');
    goodname = game.checkname(tmp);
  }
  cout << char_name << " has been renamed to " << tmp << "\n\n";
  char_name = tmp;
}

void Generic_Character_Class::updateLevel()
{
  if (level == 20)
  {
    cout << "Already max level.\n\n";
  }
  else
  {
    cout << "Current level is " << level << " choose a higher one to level up to.\n\n";
    int newlvl = getNumberOrQ(level + 1, 20);
    if (newlvl > level)
    {
      setClassDetails(newlvl);
      setProficiencyBonus();
    }
  }
}
