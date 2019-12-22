#include "characters.h"
#include <string>

using std::cout;
using std::string;


void Generic_Character_Class::setAnySkill(const string &message, const int &many)
{
  int ss(0);
  cout << message << '\n';
  for (int i = 0; i < many; i++)
  {
    if (acrobatics)
      cout << "\n 1. Acrobatics(Already Known)";
    else
      cout << "\n 1. Acrobatics";
    if (animal_handling)
      cout << "\n 2. Animal Handling(Already Known)";
    else
      cout << "\n 2. Animal Handling";
    if (arcana)
      cout << "\n 3. Arcana(Already Known)";
    else
      cout << "\n 3. Arcana";
    if (athletics)
      cout << "\n 4. Athletics(Already Known)";
    else
      cout << "\n 4. Athletics";
    if (deception)
      cout << "\n 5. Deception(Already Known)";
    else
      cout << "\n 5. Deception";
    if (history)
      cout << "\n 6. History(Already Known)";
    else
      cout << "\n 6. History";
    if (insight)
      cout << "\n 7. Insight(Already Known)";
    else
      cout << "\n 7. Insight";
    if (intimidation)
      cout << "\n 8. Intimidation(Already Known)";
    else
      cout << "\n 8. Intimidation";
    if (investigation)
      cout << "\n 9. Investigation(Already Known)";
    else
      cout << "\n 9. Investigation";
    if (medicine)
      cout << "\n10. Medicine(Already Known)";
    else
      cout << "\n10. Medicine";
    if (nature)
      cout << "\n11. Nature(Already Known)";
    else
      cout << "\n11. Nature";
    if (perception)
      cout << "\n12. Perception(Already Known)";
    else
      cout << "\n12. Perception";
    if (performance)
      cout << "\n13. Performance(Already Known)";
    else
      cout << "\n13. Performance";
    if (persuasion)
      cout << "\n14. Persuasion(Already Known)";
    else
      cout << "\n14. Persuasion";
    if (religion)
      cout << "\n15. Religion(Already Known)";
    else
      cout << "\n15. Religion";
    if (sleight_of_hand)
      cout << "\n16. Sleight of Hand(Already Known)";
    else
      cout << "\n16. Sleight of Hand";
    if (stealth)
      cout << "\n17. Stealth(Already Known)";
    else
      cout << "\n17. Stealth";
    if (survival)
      cout << "\n18. Survival(Already Known)\n\n";
    else
      cout << "\n18. Survival\n\n";
    ss = getNumber("Skill Choice: ", 1, 18);
    if (ss == 1)
    {
      gainAcrobatics(i);
    }
    if (ss == 2)
    {
      gainAnimal_Handling(i);
    }
    if (ss == 3)
    {
      gainArcana(i);
    }
    if (ss == 4)
    {
      gainAthletics(i);
    }
    if (ss == 5)
    {
      gainDeception(i);
    }
    if (ss == 6)
    {
      gainHistory(i);
    }
    if (ss == 7)
    {
      gainInsight(i);
    }
    if (ss == 8)
    {
      gainIntimidation(i);
    }
    if (ss == 9)
    {
      gainInvestigation(i);
    }
    if (ss == 10)
    {
      gainMedicine(i);
    }
    if (ss == 11)
    {
      gainNature(i);
    }
    if (ss == 12)
    {
      gainPerception(i);
    }
    if (ss == 13)
    {
      gainPerformance(i);
    }
    if (ss == 14)
    {
      gainPersuasion(i);
    }
    if (ss == 15)
    {
      gainReligion(i);
    }
    if (ss == 16)
    {
      gainSleight_of_Hand(i);
    }
    if (ss == 17)
    {
      gainStealth(i);
    }
    if (ss == 18)
    {
      gainSurvival(i);
    }
    if (i < many - 1)
      cout << "Choose Another.\n";
  }
}

void Generic_Character_Class::gainAcrobatics(int &i)
{
  if (!acrobatics)
  {
    acrobatics = true;
    cout << "Acrobatics skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainAnimal_Handling(int &i)
{
  if (!animal_handling)
  {
    animal_handling = true;
    cout << "Animal Handling skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainArcana(int &i)
{
  if (!arcana)
  {
    arcana = true;
    cout << "Arcana skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainAthletics(int &i)
{
  if (!athletics)
  {
    athletics = true;
    cout << "Athletics skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainDeception(int &i)
{
  if (!deception)
  {
    deception = true;
    cout << "Deception skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainHistory(int &i)
{
  if (!history)
  {
    history = true;
    cout << "History skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainInsight(int &i)
{
  if (!insight)
  {
    insight = true;
    cout << "Insight skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainIntimidation(int &i)
{
  if (!intimidation)
  {
    intimidation = true;
    cout << "Initimdation skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainInvestigation(int &i)
{
  if (!investigation)
  {
    investigation = true;
    cout << "Investigation skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainMedicine(int &i)
{
  if (!medicine)
  {
    medicine = true;
    cout << "Medicine skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainNature(int &i)
{
  if (!nature)
  {
    nature = true;
    cout << "Nature skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainPerception(int &i)
{
  if (!perception)
  {
    perception = true;
    cout << "Perception skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainPerformance(int &i)
{
  if (!performance)
  {
    performance = true;
    cout << "Performance skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainPersuasion(int &i)
{
  if (!persuasion)
  {
    persuasion = true;
    cout << "Persuasion skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainReligion(int &i)
{
  if (!religion)
  {
    religion = true;
    cout << "Religion skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainSleight_of_Hand(int &i)
{
  if (!sleight_of_hand)
  {
    sleight_of_hand = true;
    cout << "Sleight of Hand skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainStealth(int &i)
{
  if (!stealth)
  {
    stealth = true;
    cout << "Stealth skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::gainSurvival(int &i)
{
  if (!survival)
  {
    survival = true;
    cout << "Survival skill learned!\n";
  }
  else
  {
    knownskill(i);
  }
}

void Generic_Character_Class::knownskill(int &i)
{
  i--;
  cout << "Already know this skill.\n";
}
