#include "characters.h"
#include <string>
#include <iostream>

using namespace std;

extern string mainMessage;

void Generic_Character_Class::updateCharacter(const Campaign &game)
{
  int ss = 0;
  do
  {
    simpleClearScreen();

    character_sheet();

    cout
        << "\nEditing " << GREEN << char_name << RESET << ", level " << level << " " << alignment << " " << char_class << "\n\n"
        << " 1. LEVEL UP!" << endl
        << " 2. Change Name" << endl
        << " 3. Change Alignment" << endl
        << " 4. Custom Ability Stats" << endl
        << " 5. Grant New Skill Proficiency" << endl
        << " 6. Grant New Feat" << endl
        << " 7. Back to " << GREEN << "CHARACTER MANAGER" << RESET << endl
        << endl;
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
      cout << "Current Alignment is: " << alignment << "\n";
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
             << "1. Str: " << strength << endl
             << "2. Dex: " << dexterity << endl
             << "3. Con: " << constitution << endl
             << "4. Int: " << intelligence << endl
             << "5. Wis: " << wisdom << endl
             << "6. Cha: " << charisma << endl
             << endl;
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
             << "1. Str: " << strength << endl
             << "2. Dexterity: " << dexterity << endl
             << "3. Constitution: " << constitution << endl
             << "4. Intelligence: " << intelligence << endl
             << "5. Wisdom: " << wisdom << endl
             << "6. Charisma: " << charisma << endl
             << endl;
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
    if (ss != 7) pressEnterToContinue();
  } while (ss != 7);
  mainMessage = "DON'T FORGET TO SAVE!";
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

void Generic_Character_Class::updateLevel()  {
  if (level == 20)
  {
    cout << "Already max level.\n\n";
  }
  else
  {
    cout << "Current level is " << level << "\n\n";
    int newlvl = getNumber("Enter new higher level: ", level + 1, 20);
    setClassDetails(newlvl);
    setProficiencyBonus();
  }
}
