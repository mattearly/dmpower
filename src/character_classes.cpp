#include "characters.h"

using std::cout;
using std::endl;

void Cleric::setClassDetails(const int &l)
{

  cout << " ->Set Cleric Details.\n\n";
  level = l;
  hitdicesize = 8;
  wisSave = 1;
  chaSave = 1;
  spellcasting = true;
  if (!cleric_attr.divine_domain)
  {
    cout << "Choose a Divine Domain:\n\n"
         << " 1. Arcane\n 2. Death\n 3. Knowledge\n 4. Life\n 5. Light\n"
         << " 6. Nature\n 7. Tempest\n 8. Trickery\n 9. War\n\n";
    int ss = getNumber("Divine Domain Choice: ", 1, 9);
    switch (ss)
    {
    case 1:
      cleric_attr.arcana_d = true;
      arcana = true; //gain arcana skill
      break;
    case 2:
      cleric_attr.death_d = true;
      //gain martial weapon prof
      break;
    case 3:
      cleric_attr.knowledge_d = true;
      setLanguage("First Knowledge Domain Language.\n\n");
      setLanguage("Second Knowledge Domain Language.\n\n");
      //gain double prof skills from arcana, history, nature, religion
      break;
    case 4:
      cleric_attr.life_d = true;
      break;
    case 5:
      cleric_attr.light_d = true;
      break;
    case 6:
      cleric_attr.nature_d = true;
      break;
    case 7:
      cleric_attr.tempest_d = true;
      break;
    case 8:
      cleric_attr.trickery_d = true;
      break;
    case 9:
      cleric_attr.war_d = true;
      break;
    }
    cleric_attr.divine_domain = true;
  }
  if (cleric_attr.divine_domain_feature == 0 && l >= 2)
    cleric_attr.divine_domain_feature++;
  if (cleric_attr.channel_divinity == 0 && l >= 2)
    cleric_attr.channel_divinity++;
  if (clericlevelupmenus == 0 && l >= 4)
  {

    cout << "Ability Score Increase Menu for Level 4 Cleric.\n\n";
    levelUpStats();
    clericlevelupmenus++;
  }
  if (cleric_attr.destroy_undead == 0 && l >= 5)
    cleric_attr.destroy_undead += .5;
  if (cleric_attr.channel_divinity == 1 && l >= 6)
    cleric_attr.channel_divinity++;
  if (cleric_attr.divine_domain_feature == 1 && l >= 6)
    cleric_attr.divine_domain_feature++;
  if (cleric_attr.destroy_undead == .5 && l >= 8)
    cleric_attr.destroy_undead += .5;
  if (clericlevelupmenus == 1 && l >= 8)
  {

    cout << "Ability Score Increase Menu for Level 8 Cleric.\n\n";
    levelUpStats();
    clericlevelupmenus++;
  }
  if (cleric_attr.divine_domain_feature == 2 && l >= 8)
    cleric_attr.divine_domain_feature++;
  if (cleric_attr.divine_intervention == 0 && l >= 10)
    cleric_attr.divine_intervention++;
  if (cleric_attr.destroy_undead == 1 && l >= 11)
    cleric_attr.destroy_undead++;
  if (clericlevelupmenus == 2 && l >= 12)
  {

    cout << "Ability Score Increase Menu for Level 12 Cleric.\n\n";
    levelUpStats();
    clericlevelupmenus++;
  }
  if (cleric_attr.destroy_undead == 2 && l >= 14)
    cleric_attr.destroy_undead++;
  if (clericlevelupmenus == 3 && l >= 16)
  {

    cout << "Ability Score Increase Menu for Level 16 Cleric.\n\n";
    levelUpStats();
    clericlevelupmenus++;
  }
  if (cleric_attr.destroy_undead == 3 && l >= 17)
    cleric_attr.destroy_undead++;
  if (cleric_attr.divine_domain_feature == 3 && l >= 17)
    cleric_attr.divine_domain_feature++;
  if (cleric_attr.channel_divinity == 2 && l >= 18)
    cleric_attr.channel_divinity++;
  if (clericlevelupmenus == 4 && l >= 19)
  {

    cout << "Ability Score Increase Menu for Level 19 Cleric.\n\n";
    levelUpStats();
    clericlevelupmenus++;
  }
  if (cleric_attr.divine_intervention == 1 && l >= 20)
    cleric_attr.divine_intervention++;
  //cleric spells
  if (l >= 1 && l <= 3)
  {
    cleric_attr.cleric_cantrips_known = 3;
    first_ss = 2;
    if (l == 2)
    {
      first_ss += 1;
    }
    else if (l == 3)
    {
      first_ss += 2;
      second_ss = 2;
    }
  }
  else if (l >= 4 && l <= 9)
  {
    cleric_attr.cleric_cantrips_known = 4;
    first_ss = 4;
    second_ss = 3;
    if (l >= 5)
      third_ss = 2;
    if (l >= 6)
      third_ss += 1;
    if (l >= 7)
      forth_ss = 1;
    if (l == 9)
      fifth_ss = 1;
    if (l == 5)
    {
    }
    else if (l == 6)
    {
      third_ss += 1;
    }
    else if (l == 8)
    {
      forth_ss += 1;
    }
    else if (l == 9)
    {
      forth_ss += 2;
    }
  }
  else if (l >= 10 && l <= 20)
  {
    cleric_attr.cleric_cantrips_known = 5;
    first_ss = 4;
    second_ss = 3;
    third_ss = 3;
    forth_ss = 3;
    fifth_ss = 2;
    if (l >= 11)
      sixth_ss = 1;
    if (l >= 13)
      seventh_ss = 1;
    if (l >= 15)
      eighth_ss = 1;
    if (l >= 17)
      ninth_ss = 1;
    else if (l >= 18 && l <= 20)
    {
      if (l >= 18)
        fifth_ss += 1;
      if (l >= 19)
        sixth_ss += 1;
      if (l == 20)
        seventh_ss += 1;
    }
  }
  //skills
  if (!initialSkillsSet)
  {

    cout << "Clerics start with three Skills.\n";
    for (int i = 0; i < 3; i++)
    {
      if (history)
        cout << "\n 1 - History(Already Known)";
      else
        cout << "\n 1 - History";
      if (insight)
        cout << "\n 2 - Insight(Already Known)";
      else
        cout << "\n 2 - Insight";
      if (medicine)
        cout << "\n 3 - Medicine(Already Known)";
      else
        cout << "\n 3 - Medicine";
      if (persuasion)
        cout << "\n 4 - Persuasion(Already Known)";
      else
        cout << "\n 4 - Persuasion";
      if (religion)
        cout << "\n 5 - Religion(Already Known)\n\n";
      else
        cout << "\n 5 - Religion\n\n";
      int ss = getNumber("Choose a skill(1-5): ", 1, 5);
      if (ss == 1)
      {
        gainHistory(i);
      }
      if (ss == 2)
      {
        gainInsight(i);
      }
      if (ss == 3)
      {
        gainMedicine(i);
      }
      if (ss == 4)
      {
        gainPersuasion(i);
      }
      if (ss == 5)
      {
        gainReligion(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Fighter::setClassDetails(const int &l)
{

  level = l;
  hitdicesize = 10;
  strSave = 1;
  conSave = 1;
  if (!fighting_style)
  {
    cout << "Fighter Fighting Style:\n\n"
         << " 1. Archery      4. Great Weapon Fighting"
         << "\n 2. Defense      5. Protection"
         << "\n 3. Dueling      6. Two-Weapon Fighting\n\n";
    int ss = getNumber("Fighting Style Choice(1-6): ", 1, 6);
    if (ss == 1)
      fighter_attr.archery = true;
    if (ss == 2)
      defense = true;
    if (ss == 3)
      dueling = true;
    if (ss == 4)
      great_weapon_fighting = true;
    if (ss == 5)
      protection = true;
    if (ss == 6)
      fighter_attr.two_weapon_fighting = true;
    fighting_style = true;
  }
  if (!fighter_attr.second_wind)
    fighter_attr.second_wind = true;
  if (fighter_attr.action_surge == 0 && l >= 2)
    fighter_attr.action_surge++;
  if (!fighter_attr.martial_archtype && l >= 3)
  {
    cout << "Figther Martial Archetype:\n\n"
         << " 1. Champion"
         << "\n 2. Battle Master"
         << "\n 3. Eldritch Knight"
         << "\n 4. Purple Dragon Knight\n\n";
    int ss = getNumber("Choose an Archetype(1-4): ", 1, 4);
    switch (ss)
    {
    case 1:
      fighter_attr.champion = true;
      break;
    case 2:
    {
      fighter_attr.battle_master = true;
      setTools(1);
    }
      break;
    case 3:
      fighter_attr.eldritch_knight = true;
      spellcasting = true;
      break;
    case 4:
      fighter_attr.purple_dragon_knight = true;
      break;
    default:
      cout << "Error setting fighter archetype.\n\n";
      break;
    }
    fighter_attr.martial_archtype = true;
  }
  if (fighterlevelupmenus == 0 && l >= 4)
  {
    cout << "Fighter level 4 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (extra_attack == 0 && l >= 5)
    extra_attack++;
  if (fighterlevelupmenus == 1 && l >= 6)
  {
    cout << "Fighter level 6 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (fighter_attr.martial_archtype_feature == 0 && l >= 7)
    fighter_attr.martial_archtype_feature++;
  if (fighterlevelupmenus == 2 && l >= 8)
  {
    cout << "Fighter level 8 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (fighter_attr.indomitable == 0 && l >= 9)
    fighter_attr.indomitable++;
  if (fighter_attr.martial_archtype_feature == 1 && l >= 10)
    fighter_attr.martial_archtype_feature++;
  if (extra_attack == 1 && l >= 11)
    extra_attack++;
  if (fighterlevelupmenus == 3 && l >= 12)
  {
    cout << "Fighter level 12 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (fighter_attr.indomitable == 1 && l >= 13)
    fighter_attr.indomitable++;
  if (fighterlevelupmenus == 4 && l >= 14)
  {
    cout << "Fighter level 14 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (fighter_attr.martial_archtype_feature == 2 && l >= 15)
    fighter_attr.martial_archtype_feature++;
  if (fighterlevelupmenus == 5 && l >= 16)
  {
    cout << "Fighter level 16 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (fighter_attr.action_surge == 1 && l >= 17)
    fighter_attr.action_surge++;
  if (fighter_attr.indomitable == 2 && l >= 17)
    fighter_attr.indomitable++;
  if (fighter_attr.martial_archtype_feature == 3 && l >= 18)
    fighter_attr.martial_archtype_feature++;
  if (fighterlevelupmenus == 6 && l >= 19)
  {
    cout << "Fighter level 19 Level Up Menu: \n\n";
    levelUpStats();
    fighterlevelupmenus++;
  }
  if (extra_attack == 2 && l >= 20)
    extra_attack++;
  //spells
  if (fighter_attr.eldritch_knight)
  {
    if (l >= 3 && l <= 9)
    {
      first_ss = 2;
      wizard_attr.wizard_cantrips_known = 2;
      fighter_attr.eldritch_spells_known = 3;
      if (l >= 4)
        first_ss++;
      if (l >= 7)
        first_ss++;
      if (l >= 7)
        second_ss = 2;
      if (l >= 4)
        fighter_attr.eldritch_spells_known++;
      if (l >= 7)
        fighter_attr.eldritch_spells_known++;
      if (l >= 8)
        fighter_attr.eldritch_spells_known++;
    }
    else if (l >= 10 && l <= 20)
    {
      first_ss = 4;
      second_ss = 3;
      wizard_attr.wizard_cantrips_known = 3;
      fighter_attr.eldritch_spells_known = 7;
      if (l >= 13)
        third_ss = 2;
      if (l >= 16)
        third_ss++;
      if (l >= 19)
        forth_ss = 1;
      if (l >= 11)
        fighter_attr.eldritch_spells_known++;
      if (l >= 13)
        fighter_attr.eldritch_spells_known++;
      if (l >= 14)
        fighter_attr.eldritch_spells_known++;
      if (l >= 16)
        fighter_attr.eldritch_spells_known++;
      if (l >= 19)
        fighter_attr.eldritch_spells_known++;
      if (l >= 20)
        fighter_attr.eldritch_spells_known++;
    }
  }
  if (!initialSkillsSet)
  {

    cout << "Figthers start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (acrobatics)
        cout << "\n 1. Acrobatics(Already Known)";
      else
        cout << "\n 1. Acrobatics";
      if (animal_handling)
        cout << "\n 2. Animal Handling(Already Known)";
      else
        cout << "\n 2. Animal Handling";
      if (athletics)
        cout << "\n 3. Athletics(Already Known)";
      else
        cout << "\n 3. Athletics";
      if (history)
        cout << "\n 4. History(Already Known)";
      else
        cout << "\n 4. History";
      if (insight)
        cout << "\n 5. Insight(Already Known)";
      else
        cout << "\n 5. Insight";
      if (intimidation)
        cout << "\n 6. Intimidation(Already Known)";
      else
        cout << "\n 6. Intimidation";
      if (perception)
        cout << "\n 7. Perception(Already Known)";
      else
        cout << "\n 7. Perception";
      if (survival)
        cout << "\n 8. Survival(Already Known)\n\n";
      else
        cout << "\n 8. Survival\n\n";
      int ss = getNumber("Choose a skill: ", 1, 8);
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
        gainAthletics(i);
      }
      if (ss == 4)
      {
        gainHistory(i);
      }
      if (ss == 5)
      {
        gainInsight(i);
      }
      if (ss == 6)
      {
        gainIntimidation(i);
      }
      if (ss == 7)
      {
        gainPerception(i);
      }
      if (ss == 8)
      {
        gainSurvival(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Rogue::setClassDetails(const int &l)
{
  level = l;
  hitdicesize = 8;
  dexSave = 1;
  intSave = 1;
  if (expertise == 0)
    expertise++;
  if (!rogue_attr.sneak_attack)
    rogue_attr.sneak_attack = true;
  if (!rogue_attr.thieves_cant)
    rogue_attr.thieves_cant = true;
  if (!rogue_attr.cunning_action && l >= 2)
    rogue_attr.cunning_action = true;
  if (!rogue_attr.roguish_archetype && l >= 3)
  {
    cout << "Roguish Archetype:\n\n"
         << " 1. Thief\n"
         << " 2. Assassin\n"
         << " 3. Arcane Trickster\n"
         << " 4. Mastermind\n"
         << " 5. Swashbuckler\n\n";
    int ss = getNumber("Choose an Archetype(1-5): ", 1, 5);
    switch (ss)
    {
    case 1:
      rogue_attr.thief = true;
      break;
    case 2:
      rogue_attr.assassin = true;
      cout << "Assassin: gained proficiency with Disguise & Poisoner kit.\n\n";
      disguise = true;
      poisoner = true;
      break;
    case 3:
      rogue_attr.arcane_trickster = true;
      spellcasting = true;
      break;
    case 4:
      rogue_attr.mastermind = true;
      setLanguage("First bonus Rogue::Mastermind Language:\n\n");
      setLanguage("Second bonus Rogue::Mastermind Language:\n\n");
      cout << "Mastermind: gained proficiency with Disquise & Forgery Kit\n\n";
      disguise = true;
      forgery = true;
      //gain gaming set
      break;
    case 5:
      rogue_attr.swashbuckler = true;
      break;
    default:;
    }
    rogue_attr.roguish_archetype = true;
  }
  if (!rogue_attr.uncanny_dodge && l >= 5)
    rogue_attr.uncanny_dodge = true;
  if (expertise == 1 && l >= 6)
    expertise++;
  if (!evasion && l >= 7)
    evasion = true;
  if (rogue_attr.roguish_archetype_feature == 0 && l >= 9)
    rogue_attr.roguish_archetype_feature++;
  if (!rogue_attr.reliable_talent && l >= 11)
    rogue_attr.reliable_talent = true;
  if (rogue_attr.roguish_archetype_feature == 1 && l >= 13)
    rogue_attr.roguish_archetype_feature++;
  if (!rogue_attr.blindsense && l >= 14)
    rogue_attr.blindsense = true;
  if (!rogue_attr.slippery_mind && l >= 15)
    rogue_attr.slippery_mind = true;
  if (!rogue_attr.roguish_archetype_feature && l >= 17)
    rogue_attr.roguish_archetype_feature++;
  if (!rogue_attr.elusive && l >= 18)
    rogue_attr.elusive = true;
  if (!rogue_attr.stroke_of_luck && l == 20)
    rogue_attr.stroke_of_luck = true;
  if (rogue_attr.arcane_trickster)
  {
    if (l >= 3 && l <= 9)
    {
      first_ss = 2;
      wizard_attr.wizard_cantrips_known = 2;
      if (l >= 4)
        first_ss++;
      if (l >= 7)
        first_ss++;
      if (l >= 7)
        second_ss = 2;
      if (l >= 4)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 7)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 8)
        rogue_attr.arcane_t_spells_known++;
    }
    else if (l >= 10 && l <= 20)
    {
      first_ss = 4;
      second_ss = 3;
      wizard_attr.wizard_cantrips_known = 3;
      fighter_attr.eldritch_spells_known = 7;
      if (l >= 13)
        third_ss = 2;
      if (l >= 16)
        third_ss++;
      if (l >= 19)
        forth_ss = 1;
      if (l >= 11)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 13)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 14)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 16)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 19)
        rogue_attr.arcane_t_spells_known++;
      if (l >= 20)
        rogue_attr.arcane_t_spells_known++;
    }
  }
  if (roguelevelupmenus == 0 && l >= 4)
  {
    cout << "Rogue level 4 Level Up menu:\n\n";
    levelUpStats();
    roguelevelupmenus++;
  }
  if (roguelevelupmenus == 1 && l >= 8)
  {
    cout << "Rogue level 8 Level Up menu:\n\n";
    levelUpStats();
    roguelevelupmenus++;
  }
  if (roguelevelupmenus == 2 && l >= 12)
  {
    cout << "Rogue level 12 Level Up menu:\n\n";
    levelUpStats();
    roguelevelupmenus++;
  }
  if (roguelevelupmenus == 3 && l >= 16)
  {
    cout << "Rogue level 16 Level Up menu:\n\n";
    levelUpStats();
    roguelevelupmenus++;
  }
  if (roguelevelupmenus == 4 && l >= 19)
  {
    cout << "Rogue level 19 Level Up menu:\n\n";
    levelUpStats();
    roguelevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Rogues start with 4 Skills.\n";
    for (int i = 0; i < 4; i++)
    {
      if (acrobatics)
        cout << "\n 1. Acrobatics(Already Known)";
      else
        cout << "\n 1. Acrobatics";
      if (athletics)
        cout << "\n 2. Athletics(Already Known)";
      else
        cout << "\n 2. Athletics";
      if (deception)
        cout << "\n 3. Deception(Already Known)";
      else
        cout << "\n 3. Deception";
      if (insight)
        cout << "\n 4. Insight(Already Known)";
      else
        cout << "\n 4. Insight";
      if (intimidation)
        cout << "\n 5. Intimidation(Already Known)";
      else
        cout << "\n 5. Intimidation";
      if (investigation)
        cout << "\n 6. Investigation(Already Known)";
      else
        cout << "\n 6. Investigation";
      if (perception)
        cout << "\n 7. Perception(Already Known)";
      else
        cout << "\n 7. Perception";
      if (performance)
        cout << "\n 8. Performance(Already Known)";
      else
        cout << "\n 8. Performance";
      if (persuasion)
        cout << "\n 9. Persuasion(Already Known)";
      else
        cout << "\n 9. Persuasion";
      if (sleight_of_hand)
        cout << "\n10. Sleight of Hand(Already Known)";
      else
        cout << "\n10. Sleight of Hand";
      if (stealth)
        cout << "\n11. Stealth(Already Known)\n\n";
      else
        cout << "\n11. Stealth\n\n";
      int ss = getNumber("Pick a skill(1-11): ", 1, 11);
      if (ss == 1)
      {
        gainAcrobatics(i);
      }
      if (ss == 2)
      {
        gainAthletics(i);
      }
      if (ss == 3)
      {
        gainDeception(i);
      }
      if (ss == 4)
      {
        gainInsight(i);
      }
      if (ss == 5)
      {
        gainIntimidation(i);
      }
      if (ss == 6)
      {
        gainInvestigation(i);
      }
      if (ss == 7)
      {
        gainPerception(i);
      }
      if (ss == 8)
      {
        gainPerformance(i);
      }
      if (ss == 9)
      {
        gainPersuasion(i);
      }
      if (ss == 10)
      {
        gainSleight_of_Hand(i);
      }
      if (ss == 11)
      {
        gainStealth(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n";
}
void Wizard::setClassDetails(const int &l)
{

  level = l;
  hitdicesize = 6;
  intSave = 1;
  wisSave = 1;
  if (!spellcasting)
    spellcasting = true;
  if (!wizard_attr.arcane_recovery)
    wizard_attr.arcane_recovery = true;
  if (!wizard_attr.arcane_tradition && l >= 2)
  {
    cout << "Wizard Arcane Tradition:\n\n"
         << " 1. Abjuration\n"
         << " 2. Conjuration\n"
         << " 3. Divination\n"
         << " 4. Enchantment\n"
         << " 5. Evocation\n"
         << " 6. Illusion\n"
         << " 7. Necromancy\n"
         << " 8. Transmutation\n"
         << " 9. Bladesinging (Elf only || check with DM)\n\n";
    int ss = getNumber("Choose Arcane Tradition(1-9): ", 1, 9);
    switch (ss)
    {
    case 1:
      wizard_attr.abjuration = true;
      break;
    case 2:
      wizard_attr.conjuration = true;
      break;
    case 3:
      wizard_attr.divination = true;
      break;
    case 4:
      wizard_attr.enchantment = true;
      break;
    case 5:
      wizard_attr.evocation = true;
      break;
    case 6:
      wizard_attr.illusion = true;
      break;
    case 7:
      wizard_attr.necromancy = true;
      break;
    case 8:
      wizard_attr.transmutation = true;
      break;
    case 9:
      wizard_attr.bladesinging = true;
      performance = true;
      cout << "Bladesinger: gained Performance & proficiency in Light Armor or 1H Weapon\n";
      break;
    default:;
    }
    wizard_attr.arcane_tradition = true;
    cout << endl;
  }
  if (wizard_attr.arcane_tradition_feature == 0 && l >= 6)
    wizard_attr.arcane_tradition_feature++;
  if (wizard_attr.arcane_tradition_feature == 1 && l >= 10)
    wizard_attr.arcane_tradition_feature++;
  if (wizard_attr.arcane_tradition_feature == 2 && l >= 14)
    wizard_attr.arcane_tradition_feature++;
  if (!wizard_attr.spell_mastery && l >= 18)
    wizard_attr.spell_mastery = true;
  if (!wizard_attr.signature_spell && l == 20)
    wizard_attr.signature_spell = true;
  //spellslots
  for (int i = 1; i <= l; i++)
  {
    switch (i)
    {
    case 1:
      wizard_attr.wizard_cantrips_known = 3;
      first_ss = 2;
      break;
    case 2:
      first_ss++;
      break;
    case 3:
      first_ss++;
      second_ss = 2;
      break;
    case 4:
      wizard_attr.wizard_cantrips_known++;
      second_ss++;
      break;
    case 5:
      third_ss = 2;
      break;
    case 6:
      third_ss++;
      break;
    case 7:
      forth_ss = 1;
      break;
    case 8:
      forth_ss++;
      break;
    case 9:
      forth_ss++;
      fifth_ss = 1;
      break;
    case 10:
      wizard_attr.wizard_cantrips_known++;
      fifth_ss++;
      break;
    case 11:
      sixth_ss = 1;
      break;
    case 13:
      seventh_ss = 1;
      break;
    case 15:
      eighth_ss = 1;
      break;
    case 17:
      ninth_ss = 1;
      break;
    case 19:
      sixth_ss++;
      break;
    case 20:
      seventh_ss++;
    default:
      break;
    }
  }
  if (wizardlevelupmenus == 0 && l >= 4)
  {
    cout << "Wizard level 4 Level Up menu:\n\n";
    levelUpStats();
    wizardlevelupmenus++;
  }
  if (wizardlevelupmenus == 1 && l >= 8)
  {
    cout << "Wizard level 8 Level Up menu:\n\n";
    levelUpStats();
    wizardlevelupmenus++;
  }
  if (wizardlevelupmenus == 2 && l >= 12)
  {
    cout << "Wizard level 12 Level Up menu:\n\n";
    levelUpStats();
    wizardlevelupmenus++;
  }
  if (wizardlevelupmenus == 3 && l >= 16)
  {
    cout << "Wizard level 16 Level Up menu:\n\n";
    levelUpStats();
    wizardlevelupmenus++;
  }
  if (wizardlevelupmenus == 4 && l >= 19)
  {
    cout << "Wizard level 19 Level Up menu:\n\n";
    levelUpStats();
    wizardlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Wizards start with 2 Skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (arcana)
        cout << "\n 1. Arcana(Already Known)";
      else
        cout << "\n 1. Arcana";
      if (history)
        cout << "\n 2. History(Already Known)";
      else
        cout << "\n 2. History";
      if (insight)
        cout << "\n 3. Insight(Already Known)";
      else
        cout << "\n 3. Insight";
      if (investigation)
        cout << "\n 4. Investigation(Already Known)";
      else
        cout << "\n 4. Investigation";
      if (medicine)
        cout << "\n 5. Medicine(Already Known)";
      else
        cout << "\n 5. Medicine";
      if (religion)
        cout << "\n 6. Relgion(Already Known)\n\n";
      else
        cout << "\n 6. Religion\n\n";
      int ss = getNumber("Choose a Skill(1-5): ", 1, 6);
      if (ss == 1)
      {
        gainArcana(i);
      }
      if (ss == 2)
      {
        gainHistory(i);
      }
      if (ss == 3)
      {
        gainInsight(i);
      }
      if (ss == 4)
      {
        gainInvestigation(i);
      }
      if (ss == 5)
      {
        gainMedicine(i);
      }
      if (ss == 6)
      {
        gainReligion(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Barbarian::setClassDetails(const int &l)
{

  cout << " ->Set Barbarian Details:\n\n";
  level = l;
  hitdicesize = 12;
  strSave = true;
  conSave = true;
  if (l == 20)
  {
    barbarian_attr.rages = 1000;
  }
  else
  {
    barbarian_attr.rages = 2;
    if (l > 2)
    {
      barbarian_attr.rages++;
      if (l > 5)
      {
        barbarian_attr.rages++;
        if (l > 11)
        {
          barbarian_attr.rages++;
          if (l > 16)
          {
            barbarian_attr.rages++;
          }
        }
      }
    }
  }
  if (l > 0)
  {
    barbarian_attr.rage_damage = 2;
    if (l > 8)
    {
      barbarian_attr.rage_damage++;
      if (l > 15)
      {
        barbarian_attr.rage_damage++;
      }
    }
  }
  if (!unarmored_defense && l >= 1)
    unarmored_defense = true;
  if (!barbarian_attr.reckless_attack && l >= 2)
    barbarian_attr.reckless_attack = true;
  if (!barbarian_attr.danger_sense && l >= 2)
    barbarian_attr.danger_sense = true;
  if (!barbarian_attr.primal_path && l >= 3)
  {
    cout << "Choose a Primal Path:\n\n";
    cout << " 1. Path of the Battlerager (Dwarf Only or check with DM)\n 2. Path of the Berserker\n 3. Path of the Totem Warrior.\n\n";
    int ss = getNumber("Choice(1-3): ", 1, 3);
    switch (ss)
    {
    case 1:
      barbarian_attr.path_of_the_battlerager = true;
      break;
    case 2:
      barbarian_attr.path_of_the_berseker = true;
      break;
    case 3:
      barbarian_attr.path_of_the_totem_warrior = true;
      cout << "Choose a type for your totem Path:\n\n"
           << " 1. Bear\n 2. Eagle\n 3. Wolf\n\n";
      ss = getNumber("Choice(1-3): ", 1, 3);
      if (ss == 1)
      {
        barbarian_attr.bear_totem = true;
        barbarian_attr.eagle_totem = false;
        barbarian_attr.wolf_totem = false;
      }
      if (ss == 2)
      {
        barbarian_attr.eagle_totem = true;
        barbarian_attr.bear_totem = false;
        barbarian_attr.wolf_totem = false;
      }
      if (ss == 3)
      {
        barbarian_attr.wolf_totem = true;
        barbarian_attr.bear_totem = false;
        barbarian_attr.eagle_totem = false;
      }
      //uthgardt totem options need added but they are minimal effect
    }
    barbarian_attr.primal_path = true;
  }
  if (extra_attack == 0 && l >= 5)
  {
    extra_attack++;
  }
  if (!barbarian_attr.fast_movement && l >= 5)
  {
    barbarian_attr.fast_movement = true;
    move_speed += 10;
  }
  if (barbarian_attr.path_feature == 0 && l >= 6)
  {
    barbarian_attr.path_feature++;
  }
  if (!barbarian_attr.feral_instinct && l >= 7)
  {
    barbarian_attr.feral_instinct = true;
  }
  if (barbarian_attr.brutal_critical == 0 && l >= 9)
  {
    barbarian_attr.brutal_critical++;
  }
  if (barbarian_attr.path_feature == 1 && l >= 10)
  {
    if (barbarian_attr.path_of_the_totem_warrior)
    {
      cout << "Change Totem Path option:\n\n"
           << " 1. Bear\n 2. Eagle\n 3. Wolf\n\n";
      int ss = getNumber("Choice: ", 1, 3);
      if (ss == 1)
      {
        barbarian_attr.bear_totem = true;
        barbarian_attr.eagle_totem = false;
        barbarian_attr.wolf_totem = false;
      }
      if (ss == 2)
      {
        barbarian_attr.eagle_totem = true;
        barbarian_attr.bear_totem = false;
        barbarian_attr.wolf_totem = false;
      }
      if (ss == 3)
      {
        barbarian_attr.wolf_totem = true;
        barbarian_attr.bear_totem = false;
        barbarian_attr.eagle_totem = false;
      }
    }
    barbarian_attr.path_feature++;
  }
  if (!barbarian_attr.relentless_rage && l >= 11)
  {
    barbarian_attr.relentless_rage = true;
  }
  if (barbarian_attr.brutal_critical == 1 && l >= 13)
  {
    barbarian_attr.brutal_critical++;
  }
  if (barbarian_attr.path_feature == 2 && l >= 14)
  {
    if (barbarian_attr.path_of_the_totem_warrior)
    {
      cout << "Change Totem Path option:\n\n"
           << " 1. Bear\n 2. Eagle\n 3. Wolf\n\n";
      int ss = getNumber("Choice: ", 1, 3);
      if (ss == 1)
      {
        barbarian_attr.bear_totem = true;
        barbarian_attr.eagle_totem = false;
        barbarian_attr.wolf_totem = false;
      }
      if (ss == 2)
      {
        barbarian_attr.eagle_totem = true;
        barbarian_attr.bear_totem = false;
        barbarian_attr.wolf_totem = false;
      }
      if (ss == 3)
      {
        barbarian_attr.wolf_totem = true;
        barbarian_attr.bear_totem = false;
        barbarian_attr.eagle_totem = false;
      }
    }
    barbarian_attr.path_feature++;
  }
  if (!barbarian_attr.persistant_rage && l >= 15)
  {
    barbarian_attr.persistant_rage = true;
  }
  if (barbarian_attr.brutal_critical == 2 && l >= 17)
  {
    barbarian_attr.brutal_critical++;
  }
  if (!barbarian_attr.indomitable_might && l >= 18)
  {
    barbarian_attr.indomitable_might = true;
  }
  if (!barbarian_attr.primal_champion && l >= 20)
  {
    barbarian_attr.primal_champion = true;
  }
  if (barbarianlevelupmenus == 0 && l >= 4)
  {
    cout << "Barbarian level 4 Level Up menu:\n\n";
    levelUpStats();
    barbarianlevelupmenus++;
  }
  if (barbarianlevelupmenus == 1 && l >= 8)
  {
    cout << "Barbarian level 8 Level Up menu:\n\n";
    levelUpStats();
    barbarianlevelupmenus++;
  }
  if (barbarianlevelupmenus == 2 && l >= 12)
  {
    cout << "Barbarian level 12 Level Up menu:\n\n";
    levelUpStats();
    barbarianlevelupmenus++;
  }
  if (barbarianlevelupmenus == 3 && l >= 16)
  {
    cout << "Barbarian level 16 Level Up menu:\n\n";
    levelUpStats();
    barbarianlevelupmenus++;
  }
  if (barbarianlevelupmenus == 4 && l >= 19)
  {
    cout << "Barbarian level 19 Level Up menu:\n\n";
    levelUpStats();
    barbarianlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Barbarians start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (animal_handling)
        cout << "\n 1. Animal Handling(Already Known)";
      else
        cout << "\n 1. Animal Handling";
      if (athletics)
        cout << "\n 2. Athletics(Already Known)";
      else
        cout << "\n 2. Athletics";
      if (intimidation)
        cout << "\n 3. Intimidation(Already Known)";
      else
        cout << "\n 3. Intimidation";
      if (nature)
        cout << "\n 4. Nature(Already Known)";
      else
        cout << "\n 4. Nature";
      if (perception)
        cout << "\n 5. Perception(Already Known)";
      else
        cout << "\n 5. Perception";
      if (survival)
        cout << "\n 6. Survival(Already Known)\n\n";
      else
        cout << "\n 6. Survival\n\n";
      int ss = getNumber("Choice(1-6): ", 1, 6);
      if (ss == 1)
      {
        gainAnimal_Handling(i);
      }
      if (ss == 2)
      {
        gainAthletics(i);
      }
      if (ss == 3)
      {
        gainIntimidation(i);
      }
      if (ss == 4)
      {
        gainNature(i);
      }
      if (ss == 5)
      {
        gainPerception(i);
      }
      if (ss == 6)
      {
        gainSurvival(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n";
}
void Druid::setClassDetails(const int &l)
{

  cout << " ->Set Druid Details.\n\n";
  level = l;
  hitdicesize = 8;
  intSave = true;
  wisSave = true;
  // if (!druidic)    //now learned earlier (in campaign.cpp) to avoid conflicts
  //     druidic = true;
  if (!spellcasting)
    spellcasting = true;
  if (!druid_attr.wild_shape && l >= 2)
    druid_attr.wild_shape = true;
  if (!druid_attr.druid_circle && l >= 2)
  {
    cout << "Druid Circle:\n\n"
         << " 1. Circle of the Land\n 2. Circle of the Moon\n\n";
    int ss = getNumber("Choice: ", 1, 2);
    if (ss == 1)
    {
      cout << "Circle of the Land type:\n\n";
      setLandtype();
      druid_attr.circle_of_the_land = true;
    }
    if (ss == 2)
      druid_attr.circle_of_the_moon = true;
    druid_attr.druid_circle = true;
  }
  if (druid_attr.wild_shape_improvement == .25 && l >= 4)
    druid_attr.wild_shape_improvement += .25;
  if (druid_attr.druid_circle_feature == 0 && l >= 6)
    druid_attr.druid_circle_feature++;
  if (druid_attr.wild_shape_improvement == .5 && l >= 8)
    druid_attr.wild_shape_improvement += .5;
  if (druid_attr.druid_circle_feature == 1 && l >= 10)
    druid_attr.druid_circle_feature++;
  if (druid_attr.druid_circle_feature == 2 && l >= 14)
    druid_attr.druid_circle_feature++;
  if (!timeless_body && l >= 18)
    timeless_body = true;
  if (!druid_attr.beast_spells && l >= 18)
    druid_attr.beast_spells = true;
  if (!druid_attr.archdruid && l >= 20)
    druid_attr.archdruid = true;
  //druid spells
  if (l >= 1 && l <= 3)
  {
    druid_attr.druid_cantrips_known = 2;
    first_ss = 2;
    if (l == 2)
    {
      first_ss += 1;
    }
    else if (l == 3)
    {
      first_ss += 2;
      second_ss = 2;
    }
  }
  else if (l >= 4 && l <= 9)
  {
    druid_attr.druid_cantrips_known = 3;
    first_ss = 4;
    second_ss = 3;
    if (l >= 5)
      third_ss = 2;
    if (l >= 6)
      third_ss += 1;
    if (l >= 7)
      forth_ss = 1;
    if (l == 9)
      fifth_ss = 1;
    if (l == 8)
    {
      forth_ss += 1;
    }
    else if (l == 9)
    {
      forth_ss += 2;
    }
  }
  else if (l >= 10 && l <= 20)
  {
    druid_attr.druid_cantrips_known = 4;
    first_ss = 4;
    second_ss = 3;
    third_ss = 3;
    forth_ss = 3;
    fifth_ss = 2;
    if (l >= 11)
      sixth_ss = 1;
    if (l >= 13)
      seventh_ss = 1;
    if (l >= 15)
      eighth_ss = 1;
    if (l >= 17)
      ninth_ss = 1;
    else if (l >= 18 && l <= 20)
    {
      if (l >= 18)
        fifth_ss += 1;
      if (l >= 19)
        sixth_ss += 1;
      if (l == 20)
        seventh_ss += 1;
    }
  }
  if (druidlevelupmenus == 0 && l >= 4)
  {
    cout << "Druid level 4 Level Up menu:\n\n";
    levelUpStats();
    druidlevelupmenus++;
  }
  if (druidlevelupmenus == 1 && l >= 8)
  {
    cout << "Druid level 8 Level Up menu:\n\n";
    levelUpStats();
    druidlevelupmenus++;
  }
  if (druidlevelupmenus == 2 && l >= 12)
  {
    cout << "Druid level 12 Level Up menu:\n\n";
    levelUpStats();
    druidlevelupmenus++;
  }
  if (druidlevelupmenus == 3 && l >= 16)
  {
    cout << "Druid level 16 Level Up menu:\n\n";
    levelUpStats();
    druidlevelupmenus++;
  }
  if (druidlevelupmenus == 4 && l >= 19)
  {
    cout << "Druid level 19 Level Up menu:\n\n";
    levelUpStats();
    druidlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Druids start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (arcana)
        cout << "\n 1. Arcana(Already Known)";
      else
        cout << "\n 1. Arcana";
      if (animal_handling)
        cout << "\n 2. Animal Handling(Already Known)";
      else
        cout << "\n 2. Animal Handling";
      if (insight)
        cout << "\n 3. Insight(Already Known)";
      else
        cout << "\n 3. Insight";
      if (medicine)
        cout << "\n 4. Medicine(Already Known)";
      else
        cout << "\n 4. Medicine";
      if (nature)
        cout << "\n 5. Nature(Already Known)";
      else
        cout << "\n 5. Nature";
      if (perception)
        cout << "\n 6. Perception(Already Known)";
      else
        cout << "\n 6. Perception";
      if (religion)
        cout << "\n 7. Religion(Already Known)";
      else
        cout << "\n 7. Religion";
      if (survival)
        cout << "\n 8. Survival(Already Known)\n\n";
      else
        cout << "\n 8. Survival\n\n";
      int ss = getNumber("Choice: ", 1, 8);
      if (ss == 1)
      {
        gainArcana(i);
      }
      if (ss == 2)
      {
        gainAnimal_Handling(i);
      }
      if (ss == 3)
      {
        gainInsight(i);
      }
      if (ss == 4)
      {
        gainMedicine(i);
      }
      if (ss == 5)
      {
        gainNature(i);
      }
      if (ss == 6)
      {
        gainPerception(i);
      }
      if (ss == 7)
      {
        gainReligion(i);
      }
      if (ss == 8)
      {
        gainSurvival(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Paladin::setClassDetails(const int &l)
{

  cout << " ->Set Paladin Details.\n\n";
  level = l;
  hitdicesize = 10;
  wisSave = true;
  chaSave = true;
  if (!paladin_attr.divine_sense)
    paladin_attr.divine_sense = true;
  if (!paladin_attr.lay_on_hands)
    paladin_attr.lay_on_hands = true;
  if (!fighting_style && l >= 2)
  {
    cout << "Pick a Paladin Fighting Style:\n\n"
         << " 1. Defense\n 2. Dueling\n"
         << " 3. Great Weapon Fighting\n 4. Protection\n\n";
    int ss = getNumber("Choice: ", 1, 4);
    if (ss == 1)
      defense = true;
    if (ss == 2)
      dueling = true;
    if (ss == 3)
      great_weapon_fighting = true;
    if (ss == 4)
      protection = true;
    fighting_style = true;
  }
  if (!spellcasting && l >= 2)
    spellcasting = true;
  if (paladin_attr.divine_smite == 0 && l >= 2)
    paladin_attr.divine_smite++;
  if (!paladin_attr.divine_health && l >= 3)
    paladin_attr.divine_health = true;
  if (!paladin_attr.sacred_oath && l >= 3)
  {
    cout << "Pick a Paladin Oath Path:\n\n"
         << " 1. Oath of Ancients\n"
         << " 2. Oath of Devotion\n"
         << " 3. Oath of the Crown\n"
         << " 4. Oath of Vengeance\n"
         << " 5. Oathbreaker\n\n";
    int ss = getNumber("Choice: ", 1, 5);
    switch (ss)
    {
    case 1:
      paladin_attr.oath_of_ancients = true;
      break;
    case 2:
      paladin_attr.oath_of_devotion = true;
      break;
    case 3:
      paladin_attr.oath_of_the_crown = true;
      break;
    case 4:
      paladin_attr.oath_of_vengeance = true;
      break;
    case 5:
      paladin_attr.oathbreaker = true;
      break;
    default:
      cout << "Error setting Paladin Oath - check code\n\n";
      break;
    }
    paladin_attr.sacred_oath = true;
  }
  if (extra_attack == 0 && l >= 5)
    extra_attack++;
  if (!paladin_attr.aura_of_protection && l >= 6)
    paladin_attr.aura_of_protection = true;
  if (paladin_attr.sacred_oath_feature == 0 && l >= 7)
    paladin_attr.sacred_oath_feature++;
  if (!paladin_attr.aura_of_courage && l >= 10)
    paladin_attr.aura_of_courage = true;
  if (paladin_attr.divine_smite == 1 && l >= 11)
    paladin_attr.divine_smite++;
  if (!paladin_attr.cleansing_touch && l >= 14)
    paladin_attr.cleansing_touch = true;
  if (paladin_attr.sacred_oath_feature == 1 && l >= 15)
    paladin_attr.sacred_oath_feature++;
  if (!paladin_attr.aura_improvments && l >= 18)
    paladin_attr.aura_improvments = true;
  if (paladin_attr.sacred_oath_feature == 2 && l == 20)
    paladin_attr.sacred_oath_feature++;
  //spells
  if (l >= 2)
    first_ss = 2;
  if (l >= 3)
    first_ss++;
  if (l >= 5)
    first_ss++;
  if (l >= 5)
    second_ss = 2;
  if (l >= 7)
    second_ss++;
  if (l >= 9)
    third_ss = 2;
  if (l >= 11)
    third_ss++;
  if (l >= 13)
    forth_ss = 1;
  if (l >= 15)
    forth_ss++;
  if (l >= 17)
  {
    forth_ss++;
    fifth_ss = 1;
  }
  if (l >= 19)
    fifth_ss++;
  //level up menus
  if (paladinlevelupmenus == 0 && l >= 4)
  {
    cout << "Paladin level 4 Level Up menu:\n\n";
    levelUpStats();
    paladinlevelupmenus++;
  }
  if (paladinlevelupmenus == 1 && l >= 8)
  {
    cout << "Paladin level 8 Level Up menu:\n\n";
    levelUpStats();
    paladinlevelupmenus++;
  }
  if (paladinlevelupmenus == 2 && l >= 12)
  {
    cout << "Paladin level 12 Level Up menu:\n\n";
    levelUpStats();
    paladinlevelupmenus++;
  }
  if (paladinlevelupmenus == 3 && l >= 16)
  {
    cout << "Paladin level 16 Level Up menu:\n\n";
    levelUpStats();
    paladinlevelupmenus++;
  }
  if (paladinlevelupmenus == 4 && l >= 19)
  {
    cout << "Paladin level 19 Level Up menu:\n\n";
    levelUpStats();
    paladinlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Paladins start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (athletics)
        cout << "\n 1. Athletics(Already Known)";
      else
        cout << "\n 1. Athletics";
      if (insight)
        cout << "\n 2. Insight(Already Known)";
      else
        cout << "\n 2. Insight";
      if (intimidation)
        cout << "\n 3. Intimidation(Already Known)";
      else
        cout << "\n 3. Intimidation";
      if (medicine)
        cout << "\n4. Medicine(Already Known)";
      else
        cout << "\n 4. Medicine";
      if (persuasion)
        cout << "\n 5. Persuasion(Already Known)";
      else
        cout << "\n 5. Persuasion";
      if (religion)
        cout << "\n 6. Religion(Already Known)\n\n";
      else
        cout << "\n 6. Religion\n\n";
      int ss = getNumber("Choose a Skill: ", 1, 6);
      if (ss == 1)
      {
        gainAthletics(i);
      }
      if (ss == 2)
      {
        gainInsight(i);
      }
      if (ss == 3)
      {
        gainIntimidation(i);
      }
      if (ss == 4)
      {
        gainMedicine(i);
      }
      if (ss == 5)
      {
        gainPersuasion(i);
      }
      if (ss == 6)
      {
        gainReligion(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n";
}
void Sorcerer::setClassDetails(const int &l)
{

  cout << " ->Set Sorcerer details.\n\n";
  level = l;
  hitdicesize = 6;
  conSave = true;
  chaSave = true;
  if (!spellcasting)
    spellcasting = true;
  if (!sorcerer_attr.sorcerous_origin)
  {
    cout << "Sorcerous Origin:\n\n"
         << " 1. Draconic Bloodline\n 2. Wild Magic\n 3. Storm Sorcery\n\n";
    int ss = getNumber("Sorcerous Origin choice: ", 1, 3);
    switch (ss)
    {
    case 1:
      draconic = true;
      sorcerer_attr.draconic_bloodline = true;
      break;
    case 2:
      sorcerer_attr.wild_magic = true;
      break;
    case 3:
      sorcerer_attr.storm_sorcery = true;
      break;
    default:;
    }
    sorcerer_attr.sorcerous_origin = true;
  }
  if (!sorcerer_attr.font_of_magic && l >= 2)
    sorcerer_attr.font_of_magic = true;
  if (sorcerer_attr.metamagic == 0 && l >= 3)
    sorcerer_attr.metamagic++;
  if (sorcerer_attr.sorcerous_origin_feature == 0 && l >= 6)
    sorcerer_attr.sorcerous_origin_feature++;
  if (sorcerer_attr.metamagic == 1 && l >= 10)
    sorcerer_attr.metamagic++;
  if (sorcerer_attr.sorcerous_origin_feature == 1 && l >= 14)
    sorcerer_attr.sorcerous_origin_feature++;
  if (sorcerer_attr.metamagic == 2 && l >= 17)
    sorcerer_attr.metamagic++;
  if (sorcerer_attr.sorcerous_origin_feature == 2 && l >= 18)
    sorcerer_attr.sorcerous_origin_feature++;
  if (!sorcerer_attr.sorcerous_restoration && l == 20)
    sorcerer_attr.sorcerous_restoration = true;
  //spells
  if (l >= 1)
  {
    sorcerer_attr.sorcerer_cantrips_known = 4;
    sorcerer_attr.sorcerer_spells_known = 2;
    first_ss = 2;
  }
  if (l >= 2)
  {
    sorcerer_attr.sorcerer_spells_known++;
    first_ss++;
    sorcerer_attr.sorcery_points = l;
  }
  if (l >= 3)
  {
    sorcerer_attr.sorcerer_spells_known++;
    first_ss++;
    second_ss += 2;
  }
  if (l >= 4)
  {
    sorcerer_attr.sorcerer_cantrips_known++;
    sorcerer_attr.sorcerer_spells_known++;
    second_ss++;
  }
  if (l >= 5)
  {
    sorcerer_attr.sorcerer_spells_known++;
    third_ss += 2;
  }
  if (l >= 6)
  {
    sorcerer_attr.sorcerer_spells_known++;
    third_ss++;
  }
  if (l >= 7)
  {
    sorcerer_attr.sorcerer_spells_known++;
    forth_ss++;
  }
  if (l >= 8)
  {
    sorcerer_attr.sorcerer_spells_known++;
    forth_ss++;
  }
  if (l >= 9)
  {
    sorcerer_attr.sorcerer_spells_known++;
    forth_ss++;
    fifth_ss++;
  }
  if (l >= 10)
  {
    sorcerer_attr.sorcerer_cantrips_known++;
    sorcerer_attr.sorcerer_spells_known++;
    fifth_ss++;
  }
  if (l >= 11)
  {
    sorcerer_attr.sorcerer_spells_known++;
    sixth_ss++;
  }
  if (l >= 13)
  {
    sorcerer_attr.sorcerer_spells_known++;
    seventh_ss++;
  }
  if (l >= 15)
  {
    sorcerer_attr.sorcerer_spells_known++;
    eighth_ss++;
  }
  if (l >= 17)
  {
    sorcerer_attr.sorcerer_spells_known++;
    ninth_ss++;
  }
  if (l >= 18)
    fifth_ss++;
  if (l >= 19)
    sixth_ss++;
  if (l == 20)
    seventh_ss++;
  if (sorcererlevelupmenus == 0 && l >= 4)
  {
    cout << "Sorcerer level 4 Level Up menu:\n\n";
    levelUpStats();
    sorcererlevelupmenus++;
  }
  if (sorcererlevelupmenus == 1 && l >= 8)
  {
    cout << "Sorcerer level 8 Level Up menu:\n\n";
    levelUpStats();
    sorcererlevelupmenus++;
  }
  if (sorcererlevelupmenus == 2 && l >= 12)
  {
    cout << "Sorcerer level 12 Level Up menu:\n\n";
    levelUpStats();
    sorcererlevelupmenus++;
  }
  if (sorcererlevelupmenus == 3 && l >= 16)
  {
    cout << "Sorcerer level 16 Level Up menu:\n\n";
    levelUpStats();
    sorcererlevelupmenus++;
  }
  if (sorcererlevelupmenus == 4 && l >= 19)
  {
    cout << "Sorcerer level 19 Level Up menu:\n\n";
    levelUpStats();
    sorcererlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Sorcerers start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (arcana)
        cout << "\n 1. Aracana(Already Known)";
      else
        cout << "\n 1. Arcana";
      if (deception)
        cout << "\n 2. Deception(Already Known)";
      else
        cout << "\n 2. Deception";
      if (insight)
        cout << "\n 3. Insight(Already Known)";
      else
        cout << "\n 3. Insight";
      if (intimidation)
        cout << "\n 4. Intimidation(Already Known)";
      else
        cout << "\n 4. Intimidation";
      if (persuasion)
        cout << "\n 5. Persuasion(Already Known)";
      else
        cout << "\n 5. Persuasion";
      if (religion)
        cout << "\n 6. Religion(Already Known)\n\n";
      else
        cout << "\n 6. Religion\n\n";
      int ss = getNumber("Choose a skill: ", 1, 6);
      if (ss == 1)
      {
        gainArcana(i);
      }
      if (ss == 2)
      {
        gainDeception(i);
      }
      if (ss == 3)
      {
        gainInsight(i);
      }
      if (ss == 4)
      {
        gainIntimidation(i);
      }
      if (ss == 5)
      {
        gainPersuasion(i);
      }
      if (ss == 6)
      {
        gainReligion(i);
      }
      cout << endl;
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Bard::setClassDetails(const int &l)
{

  cout << "->Set Bard Details:\n\n";
  level = l;
  hitdicesize = 8;
  chaSave = true;
  dexSave = true;
  if (!spellcasting)
  {
    spellcasting = true;
  }
  if (bard_attr.bardic_inspiration == 0)
  {
    bard_attr.bardic_inspiration = 6;
  }
  if (!bard_attr.jack_of_all_trades && l >= 2)
  {
    bard_attr.jack_of_all_trades = true;
  }
  if (bard_attr.song_of_rest == 0 && l >= 2)
  {
    bard_attr.song_of_rest = 6;
  }
  if (!bard_attr.bard_college && l >= 3)
  {
    cout << "Bard College:\n\n"
         << " 1. College of Lore\n 2. College of Valor\n\n";
    int ss = getNumber("Choice(1-2):  ", 1, 2);
    if (ss == 1)
    {
      setAnySkill("College of Lore Skills:", 3);
      bard_attr.college_of_lore = true;
    }
    if (ss == 2)
      bard_attr.college_of_valor = true;
    bard_attr.bard_college = true;
  }
  if (expertise == 0 && l >= 3)
  {
    expertise++;
  }
  if (bard_attr.bardic_inspiration <= 6 && l >= 5)
  {
    bard_attr.bardic_inspiration = 8;
  }
  if (!bard_attr.font_of_inspiration && l >= 5)
  {
    bard_attr.font_of_inspiration = true;
  }
  if (!bard_attr.countercharm && l >= 6)
  {
    bard_attr.countercharm = true;
  }
  if (bard_attr.bard_college_feature <= 0 && l >= 6)
  {
    bard_attr.bard_college_feature++;
    if (bard_attr.college_of_lore)
      bard_attr.additional_magical_secrets = true;
    if (bard_attr.college_of_valor && extra_attack == 0)
      extra_attack++;
  }
  if (bard_attr.song_of_rest <= 6 && l >= 9)
  {
    bard_attr.song_of_rest = 8;
  }
  if (bard_attr.bardic_inspiration <= 8 && l >= 10)
  {
    bard_attr.bardic_inspiration = 10;
  }
  if (expertise <= 1 && l >= 10)
  {
    expertise++;
  }
  if (bard_attr.magical_secrets == 0 && l >= 10)
  {
    bard_attr.magical_secrets++;
  }
  if (bard_attr.song_of_rest <= 8 && l >= 13)
  {
    bard_attr.song_of_rest = 10;
  }
  if (bard_attr.bard_college_feature <= 1 && l >= 14)
  {
    bard_attr.bard_college_feature++;
  }
  if (bard_attr.magical_secrets <= 1 && l >= 14)
  {
    bard_attr.magical_secrets++;
  }
  if (bard_attr.bardic_inspiration <= 10 && l >= 15)
  {
    bard_attr.bardic_inspiration = 12;
  }
  if (bard_attr.song_of_rest <= 10 && l >= 17)
  {
    bard_attr.song_of_rest = 12;
  }
  if (bard_attr.magical_secrets <= 2 && l >= 18)
  {
    bard_attr.magical_secrets++;
  }
  if (!bard_attr.superior_inspiration && l >= 20)
  {
    bard_attr.superior_inspiration = true;
  }
  //bard spells
  for (int i = 1; i <= l; i++)
  {
    switch (i)
    {
    case 1:
      bard_attr.bard_cantrips_known = 2;
      bard_attr.bard_spells_known = 4;
      first_ss = 2;
      break;
    case 2:
      bard_attr.bard_spells_known++;
      first_ss++;
      break;
    case 3:
      bard_attr.bard_spells_known++;
      first_ss++;
      second_ss = 2;
      break;
    case 4:
      bard_attr.bard_cantrips_known++;
      bard_attr.bard_spells_known++;
      second_ss++;
      break;
    case 5:
      bard_attr.bard_spells_known++;
      third_ss = 2;
      break;
    case 6:
      bard_attr.bard_spells_known++;
      third_ss++;
      if (bard_attr.additional_magical_secrets)
        bard_attr.bard_spells_known += 2;
      break;
    case 7:
      bard_attr.bard_spells_known++;
      forth_ss = 1;
      break;
    case 8:
      bard_attr.bard_spells_known++;
      forth_ss++;
      break;
    case 9:
      bard_attr.bard_spells_known++;
      forth_ss++;
      fifth_ss = 1;
      break;
    case 10:
      bard_attr.bard_cantrips_known++;
      bard_attr.bard_spells_known += 2;
      fifth_ss++;
      break;
    case 11:
      bard_attr.bard_spells_known++;
      sixth_ss = 1;
      break;
    case 13:
      bard_attr.bard_spells_known++;
      seventh_ss = 1;
      break;
    case 14:
      bard_attr.bard_spells_known += 2;
      break;
    case 15:
      bard_attr.bard_spells_known++;
      eighth_ss = 1;
      break;
    case 17:
      bard_attr.bard_spells_known++;
      ninth_ss = 1;
      break;
    case 18:
      bard_attr.bard_spells_known += 2;
      break;
    case 19:
      sixth_ss++;
      break;
    case 20:
      seventh_ss++;
    default:
      break;
    }
  }
  if (bardlevelupmenus == 0 && l >= 4)
  {
    levelUpStats();
    bardlevelupmenus++;
  }
  if (bardlevelupmenus == 1 && l >= 8)
  {
    levelUpStats();
    bardlevelupmenus++;
  }
  if (bardlevelupmenus == 2 && l >= 12)
  {
    levelUpStats();
    bardlevelupmenus++;
  }
  if (bardlevelupmenus == 3 && l >= 16)
  {
    levelUpStats();
    bardlevelupmenus++;
  }
  if (bardlevelupmenus == 4 && l >= 19)
  {
    levelUpStats();
    bardlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    setInstrument("Choose 3 Bard instruments.\n\n", 3);
    setAnySkill("Bards start with 4 skills:", 4);
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n";
}
void Monk::setClassDetails(const int &l)
{

  cout << " ->Set Monk details.\n\n";
  level = l;
  hitdicesize = 8;
  strSave = true;
  dexSave = true;
  if (!unarmored_defense)
    unarmored_defense = true;
  if (l >= 1 && l <= 4)
    monk_attr.martial_arts = 4;
  else if (l >= 5 && l <= 10)
    monk_attr.martial_arts = 6;
  else if (l >= 11 && l <= 16)
    monk_attr.martial_arts = 8;
  else if (l >= 17 && l <= 20)
    monk_attr.martial_arts = 10;
  if (l >= 2)
    monk_attr.ki = l;
  if (l >= 2 && l <= 5)
    monk_attr.unarmored_movement = 10;
  else if (l >= 6 && l <= 9)
    monk_attr.unarmored_movement = 15;
  else if (l >= 10 && l <= 13)
    monk_attr.unarmored_movement = 20;
  else if (l >= 14 && l <= 17)
    monk_attr.unarmored_movement = 25;
  else if (l > -18 && l <= 20)
    monk_attr.unarmored_movement = 30;
  if (!monk_attr.monastic_tradition && l >= 3)
  {
    cout << "Monastic Tradition:\n\n"
         << " 1. Way of the Open Hand\n 2. Way of the Four Elements\n"
         << " 3. Way of the Long Death\n 4. Way of the Shadow\n"
         << " 5. Way of the Sun Soul\n\n";
    int ss = getNumber("Tradition choice(1-3): ", 1, 5);
    switch (ss)
    {
    case 1:
      monk_attr.way_of_the_open_hand = true;
      break;
    case 2:
      monk_attr.way_of_the_four_elements = true;
      break;
    case 3:
      monk_attr.way_of_the_long_death = true;
      break;
    case 4:
      monk_attr.way_of_the_shadow = true;
      break;
    case 5:
      monk_attr.way_of_the_sun_soul = true;
      break;
    default:
      cout << "Error setting monk tradition - check code\n\n";
    }
    monk_attr.monastic_tradition = true;
  }
  if (!monk_attr.deflect_missles && l >= 3)
    monk_attr.deflect_missles = true;
  if (!monk_attr.slow_fall && l >= 4)
    monk_attr.slow_fall = true;
  if (extra_attack == 0 && l >= 5)
    extra_attack++;
  if (!monk_attr.stunning_strike && l >= 5)
    monk_attr.stunning_strike = true;
  if (!monk_attr.ki_empowered_strikes && l >= 6)
    monk_attr.ki_empowered_strikes = true;
  if (monk_attr.monastic_tradition_feature == 0 && l >= 6)
    monk_attr.monastic_tradition_feature++;
  if (!evasion && l >= 7)
    evasion = true;
  if (!monk_attr.stillness_of_mind && l >= 7)
    monk_attr.stillness_of_mind = true;
  if (!monk_attr.unarmored_movement_improvement && l >= 9)
    monk_attr.unarmored_movement_improvement = true;
  if (!monk_attr.purity_of_body && l >= 10)
    monk_attr.purity_of_body = true;
  if (monk_attr.monastic_tradition_feature == 1 && l >= 11)
   monk_attr. monastic_tradition_feature++;
  if (!monk_attr.tongue_of_the_sun_and_moon && l >= 13)
    monk_attr.tongue_of_the_sun_and_moon = true;
  if (!monk_attr.diamond_soul && l >= 14)
    monk_attr.diamond_soul = true;
  if (!timeless_body && l >= 15)
    timeless_body = true;
  if (monk_attr.monastic_tradition_feature == 2 && l >= 17)
    monk_attr.monastic_tradition_feature++;
  if (!monk_attr.empty_body && l >= 18)
    monk_attr.empty_body = true;
  if (!monk_attr.perfect_self && l == 20)
    monk_attr.perfect_self = true;
  if (monklevelupmenus == 0 && l >= 4)
  {
    cout << "Monk level 4 Level Up menu:\n\n";
    levelUpStats();
    monklevelupmenus++;
  }
  if (monklevelupmenus == 1 && l >= 8)
  {
    cout << "Monk level 8 Level Up menu:\n\n";
    levelUpStats();
    monklevelupmenus++;
  }
  if (monklevelupmenus == 2 && l >= 12)
  {
    cout << "Monk level 12 Level Up menu:\n\n";
    levelUpStats();
    monklevelupmenus++;
  }
  if (monklevelupmenus == 3 && l >= 16)
  {
    cout << "Monk level 16 Level Up menu:\n\n";
    levelUpStats();
    monklevelupmenus++;
  }
  if (monklevelupmenus == 4 && l >= 19)
  {
    cout << "Monk level 19 Level Up menu:\n\n";
    levelUpStats();
    monklevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Monks start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (acrobatics)
        cout << "\n 1. Acrobatics(Already Known)";
      else
        cout << "\n 1. Acrobatics";
      if (athletics)
        cout << "\n 2. Athletics(Already Known)";
      else
        cout << "\n 2. Athletics";
      if (history)
        cout << "\n 3. History(Already Known)";
      else
        cout << "\n 3. History";
      if (insight)
        cout << "\n 4. Insight(Already Known)";
      else
        cout << "\n 4. Insight";
      if (religion)
        cout << "\n 5. Religion(Already Known)";
      else
        cout << "\n 5. Religion";
      if (stealth)
        cout << "\n 6. Stealth(Already Known)\n\n";
      else
        cout << "\n 6. Stealth\n\n";
      int ss = getNumber("Skill choice(1-6): ", 1, 6);
      if (ss == 1)
      {
        gainAcrobatics(i);
      }
      if (ss == 2)
      {
        gainAthletics(i);
      }
      if (ss == 3)
      {
        gainHistory(i);
      }
      if (ss == 4)
      {
        gainInsight(i);
      }
      if (ss == 5)
      {
        gainReligion(i);
      }
      if (ss == 6)
      {
        gainStealth(i);
      }
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Ranger::setClassDetails(const int &l)
{

  cout << " ->Set Ranger details.\n\n";
  level = l;
  hitdicesize = 10;
  strSave = true;
  dexSave = true;
  if (ranger_attr.favored_enemy == 0)
  {
    cout << "Ranger Favored Enemy:\n\n";
    setFavoredEnemy();
    ranger_attr.favored_enemy++;
  }
  if (ranger_attr.natural_explorer == 0)
  {
    cout << "Natural Explorer land type:\n\n";
    setLandtype();
    ranger_attr.natural_explorer++;
  }
  if (!fighting_style && l >= 2)
  {
    cout << "Ranger Fighting Style:\n\n"
         << " 1. Archery\n 2. Defense\n 3. Dueling\n 4. Two Weapon Fighting\n\n";
    int ss = getNumber("Fight Style choice: ", 1, 4);
    if (ss == 1)
      fighter_attr.archery = true;
    if (ss == 2)
      defense = true;
    if (ss == 3)
      dueling = true;
    if (ss == 4)
      fighter_attr.two_weapon_fighting = true;
    fighting_style = true;
  }
  if (!spellcasting && l >= 2)
    spellcasting = true;
  if (!ranger_attr.ranger_archetype && l >= 3)
  {
    cout << "Ranger Archetype:\n\n"
         << " 1. Hunter\n 2. Beast Master\n\n";
    int ss = getNumber("Archetype choice(1-2): ", 1, 2);
    if (ss == 1)
      ranger_attr.hunter = true;
    if (ss == 2)
      ranger_attr.beast_master = true;
    ranger_attr.ranger_archetype = true;
  }
  if (!ranger_attr.primeval_awareness && l >= 3)
    ranger_attr.primeval_awareness = true;
  if (extra_attack == 0 && l >= 5)
    extra_attack++;
  if (ranger_attr.favored_enemy == 1 && l >= 6)
  {
    cout << "Ranger Favored Enemy:\n\n";
    setFavoredEnemy();
    ranger_attr.favored_enemy++;
  }
  if (ranger_attr.natural_explorer == 1 && l >= 6)
  {
    cout << "Natural Explorer land type:\n\n";
    setLandtype();
    ranger_attr.natural_explorer++;
  }
  if (ranger_attr.ranger_archetype_feature == 0 && l >= 7)
    ranger_attr.ranger_archetype_feature++;
  if (!ranger_attr.lands_stride && l >= 8)
    ranger_attr.lands_stride = true;
  if (ranger_attr.natural_explorer == 2 && l >= 10)
  {
    cout << "Natural Explorer land type:\n\n";
    setLandtype();
    ranger_attr.natural_explorer++;
  }
  if (!ranger_attr.hide_in_plain_sight && l >= 10)
   ranger_attr.hide_in_plain_sight = true;
  if (ranger_attr.ranger_archetype_feature == 1 && l >= 11)
    ranger_attr.ranger_archetype_feature++;
  if (ranger_attr.favored_enemy == 2 && l >= 14)
  {
    cout << "Ranger Favored Enemy:\n\n";
    setFavoredEnemy();
    ranger_attr.favored_enemy++;
  }
  if (!ranger_attr.vanish && l >= 14)
    ranger_attr.vanish = true;
  if (ranger_attr.ranger_archetype_feature == 2 && l >= 15)
    ranger_attr.ranger_archetype_feature++;
  if (!ranger_attr.feral_senses && l >= 18)
    ranger_attr.feral_senses = true;
  if (!ranger_attr.foe_slayer && l == 20)
    ranger_attr.foe_slayer = true;
  // spells
  if (l >= 2)
  {
    ranger_attr.ranger_spells_known = 2;
    first_ss = 2;
  }
  if (l >= 3)
  {
    ranger_attr.ranger_spells_known++;
    first_ss++;
  }
  if (l >= 5)
  {
    ranger_attr.ranger_spells_known++;
    first_ss++;
    second_ss = 2;
  }
  if (l >= 7)
  {
    ranger_attr.ranger_spells_known++;
    second_ss++;
  }
  if (l >= 9)
  {
    ranger_attr.ranger_spells_known++;
    third_ss = 2;
  }
  if (l >= 11)
  {
    ranger_attr.ranger_spells_known++;
    third_ss++;
  }
  if (l >= 13)
  {
    ranger_attr.ranger_spells_known++;
    forth_ss = 1;
  }
  if (l >= 15)
  {
    ranger_attr.ranger_spells_known++;
    forth_ss++;
  }
  if (l >= 17)
  {
    ranger_attr.ranger_spells_known++;
    forth_ss++;
    fifth_ss = 1;
  }
  if (l >= 19)
  {
    ranger_attr.ranger_spells_known++;
    fifth_ss++;
  }
  if (rangerlevelupmenus == 0 && l >= 4)
  {
    cout << "Ranger level 4 Level Up menu:\n\n";
    levelUpStats();
    rangerlevelupmenus++;
  }
  if (rangerlevelupmenus == 1 && l >= 8)
  {
    cout << "Ranger level 8 Level Up menu:\n\n";
    levelUpStats();
    rangerlevelupmenus++;
  }
  if (rangerlevelupmenus == 2 && l >= 12)
  {
    cout << "Ranger level 12 Level Up menu:\n\n";
    levelUpStats();
    rangerlevelupmenus++;
  }
  if (rangerlevelupmenus == 3 && l >= 16)
  {
    cout << "Ranger level 16 Level Up menu:\n\n";
    levelUpStats();
    rangerlevelupmenus++;
  }
  if (rangerlevelupmenus == 4 && l >= 19)
  {
    cout << "Ranger level 19 Level Up menu:\n\n";
    levelUpStats();
    rangerlevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Rangers start with 3 skills.\n";
    for (int i = 0; i < 3; i++)
    {
      if (animal_handling)
        cout << "\n 1. Animal Handling(Already Known)";
      else
        cout << "\n 1. Animal Handling";
      if (athletics)
        cout << "\n 2. Athletics(Already Known)";
      else
        cout << "\n 2. Athletics";
      if (insight)
        cout << "\n 3. Insight(Already Known)";
      else
        cout << "\n 3. Insight";
      if (investigation)
        cout << "\n 4. Investigation(Already Known)";
      else
        cout << "\n 4. Investigation";
      if (nature)
        cout << "\n 5. Nature(Already Known)";
      else
        cout << "\n 5. Nature";
      if (perception)
        cout << "\n 6. Perception(Already Known)";
      else
        cout << "\n 6. Perception";
      if (stealth)
        cout << "\n 7. Stealth(Already Known)";
      else
        cout << "\n 7. Stealth";
      if (survival)
        cout << "\n 8. Survival(Already Known)\n\n";
      else
        cout << "\n 8. Survival\n\n";
      int ss = getNumber("Choice(1-8): ", 1, 8);
      if (ss == 1)
      {
        gainAnimal_Handling(i);
      }
      if (ss == 2)
      {
        gainAthletics(i);
      }
      if (ss == 3)
      {
        gainInsight(i);
      }
      if (ss == 4)
      {
        gainInvestigation(i);
      }
      if (ss == 5)
      {
        gainNature(i);
      }
      if (ss == 6)
      {
        gainPerception(i);
      }
      if (ss == 7)
      {
        gainStealth(i);
      }
      if (ss == 8)
      {
        gainSurvival(i);
      }
      cout << endl;
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
void Warlock::setClassDetails(const int &l)
{

  cout << " ->Set Warlock details.\n\n";
  level = l;
  hitdicesize = 8;
  intSave = true;
  chaSave = true;
  if (!warlock_attr.pact_magic)
    warlock_attr.pact_magic = true;
  if (!warlock_attr.otherworldly_patron)
  {
    cout << "Choose Warlock Otherworldly Patron:\n\n"
         << " 1. Archfey\n 2. Fiend\n 3. Great Old One\n 4. The Undying\n\n";
    int ss = getNumber("Patron choice: ", 1, 4);
    switch (ss)
    {
    case 1:
      warlock_attr.archfey = true;
      break;
    case 2:
      warlock_attr.fiend = true;
      break;
    case 3:
      warlock_attr.great_old_one = true;
      break;
    case 4:
      warlock_attr.the_undying = true;
      break;
    default:;
    }
    warlock_attr.otherworldly_patron = true;
  }
  if (!warlock_attr.pact_boon && l >= 3)
    warlock_attr.pact_boon = true;
  if (warlock_attr.otherworldly_patron_feature == 0 && l >= 6)
    warlock_attr.otherworldly_patron_feature++;
  if (warlock_attr.otherworldly_patron_feature == 1 && l >= 10)
    warlock_attr.otherworldly_patron_feature++;
  if (warlock_attr.mystic_arcanum == 0 && l >= 11)
    warlock_attr.mystic_arcanum += 6;
  if (warlock_attr.mystic_arcanum == 6 && l >= 13)
    warlock_attr.mystic_arcanum++;
  if (warlock_attr.otherworldly_patron_feature == 2 && l >= 14)
    warlock_attr.otherworldly_patron_feature++;
  if (warlock_attr.mystic_arcanum == 7 && l >= 15)
    warlock_attr.mystic_arcanum++;
  if (warlock_attr.mystic_arcanum == 8 && l >= 17)
    warlock_attr.mystic_arcanum++;
  if (!warlock_attr.eldritch_master && l == 20)
    warlock_attr.eldritch_master = true;
  //spells
  if (l >= 1)
  {
    warlock_attr.warlock_cantrips_known += 2;
    warlock_attr.warlock_spells_known += 2;
    warlock_attr.warlock_spell_slots++;
    warlock_attr.warlock_slot_level++;
  }
  if (l >= 2)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_spell_slots++;
    warlock_attr.eldritch_invocations_known += 2;
  }
  if (l >= 3)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_slot_level++;
  }
  if (l >= 4)
  {
    warlock_attr.warlock_cantrips_known++;
    warlock_attr.warlock_spells_known++;
  }
  if (l >= 5)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_slot_level++;
    warlock_attr.eldritch_invocations_known++;
  }
  if (l >= 6)
  {
    warlock_attr.warlock_spells_known++;
  }
  if (l >= 7)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_slot_level++;
    warlock_attr.eldritch_invocations_known++;
  }
  if (l >= 8)
  {
    warlock_attr.warlock_spells_known++;
  }
  if (l >= 9)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_slot_level++;
    warlock_attr.eldritch_invocations_known++;
  }
  if (l >= 10)
  {
    warlock_attr.warlock_cantrips_known++;
  }
  if (l >= 11)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_spell_slots++;
  }
  if (l >= 12)
  {
    warlock_attr.eldritch_invocations_known++;
  }
  if (l >= 13)
  {
    warlock_attr.warlock_spells_known++;
  }
  if (l >= 15)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.eldritch_invocations_known++;
  }
  if (l >= 17)
  {
    warlock_attr.warlock_spells_known++;
    warlock_attr.warlock_spell_slots++;
  }
  if (l >= 18)
  {
    warlock_attr.eldritch_invocations_known++;
  }
  if (l >= 19)
  {
    warlock_attr.warlock_spells_known++;
  }
  if (warlocklevelupmenus == 0 && l >= 4)
  {
    cout << "Warlock level 4 Level Up menu:\n\n";
    levelUpStats();
    warlocklevelupmenus++;
  }
  if (warlocklevelupmenus == 1 && l >= 8)
  {
    cout << "Warlock level 8 Level Up menu:\n\n";
    levelUpStats();
    warlocklevelupmenus++;
  }
  if (warlocklevelupmenus == 2 && l >= 12)
  {
    cout << "Warlock level 12 Level Up menu:\n\n";
    levelUpStats();
    warlocklevelupmenus++;
  }
  if (warlocklevelupmenus == 3 && l >= 16)
  {
    cout << "Warlock level 16 Level Up menu:\n\n";
    levelUpStats();
    warlocklevelupmenus++;
  }
  if (warlocklevelupmenus == 4 && l >= 19)
  {
    cout << "Warlock level 19 Level Up menu:\n\n";
    levelUpStats();
    warlocklevelupmenus++;
  }
  if (!initialSkillsSet)
  {

    cout << "Warlocks start with 2 skills.\n";
    for (int i = 0; i < 2; i++)
    {
      if (arcana)
        cout << "\n 1. Arcana(Already Known)";
      else
        cout << "\n 1. Arcana";
      if (deception)
        cout << "\n 2. Deception(Already Known)";
      else
        cout << "\n 2. Deception";
      if (history)
        cout << "\n 3. History(Already Known)";
      else
        cout << "\n 3. History";
      if (intimidation)
        cout << "\n 4. Intimidation(Already Known)";
      else
        cout << "\n 4. Intimidation";
      if (investigation)
        cout << "\n 5. Investigation(Already Known)";
      else
        cout << "\n 5. Investigation";
      if (nature)
        cout << "\n 6. Nature(Already Known)";
      else
        cout << "\n 6. Nature";
      if (religion)
        cout << "\n 7. Religion(Already Known)\n\n";
      else
        cout << "\n 7. Religion\n\n";
      int ss = getNumber("Skill choice(1-7): ", 1, 7);
      if (ss == 1)
      {
        gainArcana(i);
      }
      if (ss == 2)
      {
        gainDeception(i);
      }
      if (ss == 3)
      {
        gainHistory(i);
      }
      if (ss == 4)
      {
        gainIntimidation(i);
      }
      if (ss == 5)
      {
        gainInvestigation(i);
      }
      if (ss == 6)
      {
        gainNature(i);
      }
      if (ss == 7)
      {
        gainReligion(i);
      }
      cout << endl;
    }
  }
  cout << "\nNew  " << char_class << " named '" << char_name << "' created.\n\n";
}
