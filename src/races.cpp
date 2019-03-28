#include "races.h"
#include <string>

using namespace std;

void Aasimar::setRaceDetails(Generic_Character_Class &v)
{
  v.charisma += 2;
  v.move_speed = 30;
  v.darkvision = true;
  v.damage_resist_radiant = true;  //celestial resistance
  v.damage_resist_necrotic = true; //celestial resistance
  v.healing_hands = true;
  v.light_bearer = true;
  v.common = true;
  v.celestial = true;
  cout << "Aasimar race chosen. Gain:\n";
  cout << "  +2 Charisma\n";
  cout << "  30ft move speed\n";
  cout << "  Celestial Resistance (necrotic & radiant)\n";
  cout << "  Healing Hands\n";
  cout << "  Light Bearer\n";
  cout << "  Common and Celestial Languages\n\n";
  cout << "Choose a Celestial Subrace\n\n";
  cout << " 1. Protector\n";
  cout << " 2. Scourge\n";
  cout << " 3. Fallen\n\n";
  int ss = getNumber("Choice: ", 1, 3);
  switch (ss)
  {
  case 1:
    subr = PROTECTOR;
    v.wisdom++;
    v.radiant_soul = true;
    cout << "Protector. Gain:\n";
    cout << "  +1 Wisdom\n";
    cout << "  Radiant Soul\n";
    break;
  case 2:
    subr = SCOURGE;
    v.constitution++;
    v.radiant_consumption = true;
    cout << "Scourge. Gain:\n";
    cout << "  +1 Constitution\n";
    cout << "  Radiant Consumption\n";
    break;
  case 3:
    subr = FALLEN;
    v.strength++;
    v.necrotic_shroud++;
    cout << "Fallen. Gain:\n";
    cout << "  +1 Strength\n";
    cout << "  Necrotic Shroud\n";
    break;
  default:
    break;
  }
  pressEnterToContinue();
}

//mutators
void Dragonborn::setRaceDetails(Generic_Character_Class &v)
{
  v.strength += 2;
  v.charisma++;
  v.move_speed = 30;
  v.draconic = 1;
  v.common = 1;
  cout << "->Dragonborn defaults & bonuses applied:\n +2 STR, +1 CHA, 30ft Move, & Languages(Common, Draconic)\n\n";
  cout << "Pick a type of Draconic Ancestry:\n\n"
       << " 1. Black    6. Gold"
       << "\n 2. Blue     7. Green"
       << "\n 3. Brass    8. Red"
       << "\n 4. Bronze   9. Silver"
       << "\n 5. Copper  10. White\n\n";
  int ss = getNumber("Enter a number to choose(1-10): ", 1, 10);
  if (ss == 1)
  {
    v.draconic_ancestry_black = true;
    v.breath_weapon_acid = true;
    v.damage_resist_acid = true;
    cout << "->Black Dragon Ancestry. Acid Breath and DR Acid gained!\n";
  }
  else if (ss == 2)
  {
    v.draconic_ancestry_blue = true;
    v.breath_weapon_ltg = true;
    v.damage_resist_ltg = true;
    cout << "->Blue Dragon Ancestry. Lightning Breath and DR Lighting gained!\n";
  }
  else if (ss == 3)
  {
    v.draconic_ancestry_brass = true;
    v.breath_weapon_fire = true;
    v.damage_resist_fire = true;
    cout << "->Brass Dragon Ancestry. Fire Breath and DR Fire gained!\n";
  }
  else if (ss == 4)
  {
    v.draconic_ancestry_bronze = true;
    v.breath_weapon_ltg = true;
    v.damage_resist_ltg = true;
    cout << "->Bronze Dragon Ancestry. Lightning Breath and DR Lightning gained!\n";
  }
  else if (ss == 5)
  {
    v.draconic_ancestry_copper = true;
    v.breath_weapon_acid = true;
    v.damage_resist_acid = true;
    cout << "->Copper Dragon Ancestry. Acid Breath and DR Acid gained!\n";
  }
  else if (ss == 6)
  {
    v.draconic_ancestry_gold = true;
    v.breath_weapon_fire = true;
    v.damage_resist_fire = true;
    cout << "->Gold Dragon Ancestry. Fire Breath and DR Fire gained!\n";
  }
  else if (ss == 7)
  {
    v.draconic_ancestry_green = true;
    v.breath_weapon_poison = true;
    v.damage_resist_poison = true;
    cout << "->Green Dragon Ancestry. Poison Breath and DR Poison gained!\n";
  }
  else if (ss == 8)
  {
    v.draconic_ancestry_red = true;
    v.breath_weapon_fire = true;
    v.damage_resist_fire = true;
    cout << "->Red Dragon Ancestry. Fire Breath and DR Fire gained!\n";
  }
  else if (ss == 9)
  {
    v.draconic_ancestry_silver = true;
    v.breath_weapon_cold = true;
    v.damage_resist_cold = true;
    cout << "->Silver Dragon Ancestry. Cold Breath and DR Cold gained!\n";
  }
  else if (ss == 10)
  {
    v.draconic_ancestry_white = true;
    v.breath_weapon_cold = true;
    v.damage_resist_cold = true;
    cout << "->White Dragon Ancestry. Cold Breath and DR Cold gained!\n";
  }
  pressEnterToContinue();
}
void Dwarf::setRaceDetails(Generic_Character_Class &v)
{
  v.constitution += 2;
  v.move_speed = 25;
  v.darkvision = true;
  v.dwarven_resilience = true;
  v.damage_resist_poison = true;
  v.dwarven_combat_training = true;
  v.stonecunning = true;
  v.dwarvish = true;
  v.common = true;
  cout << "->Dwarf defaults & bonuses applied:\n"
       << "+2 CON, 25ft Move, Darkvision 60ft, Dwarven Resilience, Stonecunning, Dwarven Weapon Training, Langs(Common, Dwarven)\n\n";
  cout << "Choice of Dwarven Tools:\n\n"
       << " 1. Smith's Tools\n 2. Brewer's Supplies\n 3. Mason's Tools.\n\n";
  int ss = getNumber("Tool Choice: ", 1, 3);
  if (ss == 1)
  {
    v.smith = true;
    cout << "Smith's Tools learned!\n";
  }
  if (ss == 2)
  {
    v.brewer = true;
    cout << "Brewer's Supplies learned!\n";
  }
  if (ss == 3)
  {
    v.mason = true;
    cout << "Mason's Tools learned!\n";
  }
  cout << "\nWhat Kind of Dwarf?\n"
          "  1. Duergar Dwarf\n"
          "  2. Hill Dwarf\n"
          "  3. Mountain Dwarf.\n\n";
  subr = static_cast<enum dwarftype>(getNumber("Dwarf type(1-3): ", 1, 3));
  switch (subr)
  {
  case DUERGAR:
    v.strength += 1;
    v.superior_darkvision = true;
    v.undercommon = true;
    v.duergar_magic = true;
    v.sunlight_sensitivity = true;
    cout << "Ahh, you's a Gray Dwarf. Gain:\n"
            "  +1 Strength\n"
            "  Superior Darkvision\n"
            "  Undercommon Language\n"
            "  Duergar Resilience\n"
            "  Duergar Magic\n"
            "Disadvantage:\n"
            "  Sunlight Sensitivity\n";
    break;
  case HILL:
    v.wisdom += 1;
    v.dwarven_toughness = true;
    cout << "A Hill Dwarf you are. Gain:\n"
            "  +1 Wisdom\n"
            "  Dwarven Toughness(+1 HP/level)\n";
    break;
  case MOUNTAIN:
    v.strength += 2;
    v.dwarven_armor_training = true;
    cout << "He's one of those beefy Mountain Dwarves! Gain:\n"
            "  +2 Strength\n"
            "  Dwarven Armor Training(Proficient in Medium and Light Armor)\n";
    break;
  case NA:
  default:
    break;
  }
  pressEnterToContinue();
}
void Elf::setRaceDetails(Generic_Character_Class &v)
{
  v.dexterity += 2;
  v.move_speed = 30;
  v.darkvision = true;
  v.perception = true; //keen senses
  v.trance = true;
  v.fey_ancestry = true;
  v.common = true;
  v.elvish = true;
  cout << "->Elf defaults & bonuses applied:\n"
       << " +2 DEX, 30ft Move, Darkvision, Perception, Trance, Fey Ancestry, Languages(Common, Elven)\n\n";
  cout << "Elven Subrace:\n\n 1. High\n 2. Wood\n 3. Drow\n\n";
  subr = static_cast<enum elftype>(getNumber("Elf type choice(1-3): ", 1, 3));
  switch (subr)
  {
  case HIGH:
    v.intelligence += 1;
    v.elf_weapon_training = true;
    v.wizard_cantrips_known++;
    v.setLanguage("High Elf bonus language.\n\n");
    cout << "->High Elf defaults & bonuses applied:\n"
         << " +1 INT, Elven Weapon Training, Wizard Cantrip, Extra language\n";
    break;
  case WOOD:
    v.wisdom += 1;
    v.elf_weapon_training = true;
    v.fleet_of_foot = true;
    v.move_speed += 5;
    v.mask_of_the_wild = true;
    cout << "->Wood Elf defaults & bonuses:\n"
         << "+1 WIS, Elven Weapon Training, +5ft Move, Mask of the Wild.\n";
    break;
  case DROW:
    v.charisma += 1;
    v.darkvision = false;
    v.superior_darkvision = true;
    v.drow_magic = true;
    v.drow_weapon_training = true;
    v.sunlight_sensitivity = true;
    cout << "->Drow Elf defaults & bonuses applied:\n"
         << " +1 CHA, Darkvision 120ft, Drow Magic, Drow Weapon Training.\n";
    break;
  case NA:
  default:
    break;
  }
  cout << endl;
  pressEnterToContinue();
}
void Firbolg::setRaceDetails(Generic_Character_Class &v)
{
  v.wisdom += 2;
  v.strength += 1;
  v.move_speed = 30;
  v.firbolg_magic = true;
  v.hidden_step = true;
  v.powerful_build = true;
  v.speech_of_beast_and_leaf = true;
  v.common = true;
  v.elvish = true;
  v.giant = true;
  cout << "One of them wise Firbolg's eh? Gain:\n"
          "  +2 Wisdom\n"
          "  +1 Strength\n"
          "  30ft Move\n"
          "  Firbolg Magic\n"
          "  Powerful Build\n"
          "  Speech of beast and leaf\n"
          "  Languages(Common, Elvish, Giant)\n\n";
  pressEnterToContinue();
}

void Gnome::setRaceDetails(Generic_Character_Class &v)
{
  v.intelligence += 2;
  v.move_speed = 25;
  v.darkvision = true;
  v.common = true;
  v.gnomish = true;
  cout << "->Gnome bonuses and defaults applied:\n"
       << " +2 INT, Darkvision, Languages(Common, Gnome)\n"
       << "Now, which kind of Gnome?\n\n 1. Forest\n 2. Rock\n 3. Svirfneblin\n\n";
  subr = static_cast<enum gnometype>(getNumber("Gnome type(1-3): ", 1, 3));
  switch (subr)
  {
  case FOREST:
    v.dexterity += 1;
    v.natural_illusionist = true;
    v.speak_with_small_beasts = true;
    cout << "->Forest Gnome bonuses:\n +1 DEX, Natural Illusionist, Speak with Small Beasts\n";
    break;
  case ROCK:
    v.constitution += 1;
    v.tinker = true;
    v.artificers_lore = true;
    cout << "->Rock Gnome bonuses:\n +1 CON, Tinker, Artificers Lore\n";
    break;
  case SVIRFNEBLIN:
    v.dexterity++;
    v.superior_darkvision = true;
    v.stone_camouflage = true;
    v.undercommon = true;
    // can also take a new deep gnome feat: Svirfneblin Magic
    cout << "A Svirfneblin Gnome! Gain:\n";
    cout << "  +1 Dexterity\n";
    cout << "  Superior Darkvision\n";
    cout << "  Stone Camouflage\n";
    cout << "  Undercommon Language\n";
    cout << "  you may take the feat 'Svirfneblin Magic' if desired\n";
    break;
  case NA:
    break;
  default:
    break;
  }
  pressEnterToContinue();
}

void Goliath::setRaceDetails(Generic_Character_Class &v)
{
  v.strength += 2;
  v.constitution++;
  v.move_speed = 30;
  v.athletics = true; //natural athlete
  v.stones_endurance = true;
  v.powerful_build = true;
  v.common = true;
  v.giant = true;
  cout << "You are a big guy... a Goliath. Gain: \n";
  cout << "  +2 Strength\n";
  cout << "  +1 Constitution\n";
  cout << "  30ft Move Speed\n";
  cout << "  Natural Athlete (free athletics skill)\n";
  cout << "  Stone's Endurance\n";
  cout << "  Powerful Build\n";
  cout << "  Giant and Common Languages\n";
  pressEnterToContinue();
}
void Halfelf::setRaceDetails(Generic_Character_Class &v)
{
  v.charisma += 2;
  v.move_speed = 30;
  v.darkvision = true;
  v.common = true;
  v.elvish = true;
  cout << "->Halfelf, half... human? Let's face it, this race is OP. Gain: \n";
  cout << "  +2 Charisma\n";
  cout << "  30ft move\n";
  cout << "  Darkvision\n";
  cout << "  Common and Elven Languages known\n";
  cout << "  +1 to two other stats\n";
  cout << "  ... and there is more after you choose the +1 stats\n\n";
  int ss = 0;
  for (int i = 0; i < 2; i++)
  {
    int tmp = ss;
    if (ss == 0)
      cout << "First +1 stat: \n\n";
    if (ss != 0)
      cout << "Second +1 stat: \n\n";
    if (ss == 0)
    {
      cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. +1 Constitution"
           << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
    }
    if (ss == 1)
    {
      cout << " 1. +1 (can't choose)\n 2. +1 Dexterity\n 3. +1 Constitution"
           << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
    }
    if (ss == 2)
    {
      cout << " 1. +1 Strength\n 2. (can't choose)\n 3. +1 Constitution"
           << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
    }
    if (ss == 3)
    {
      cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. (can't choose)"
           << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
    }
    if (ss == 4)
    {
      cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. +1 Constitution"
           << "\n 4. (can't choose)\n 5. +1 Wisdom\n\n";
    }
    if (ss == 5)
    {
      cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. +1 Constitution"
           << "\n 4. +1 Intelligence\n 5. (can't choose)\n\n";
    }
    while ((cout << "Enter a number to choose : " && !(cin >> ss)) || ((ss < 1 || ss > 5) || ss == tmp))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid, try again." << endl;
    }
    if (ss == 1)
    {
      v.strength += 1;
      cout << "Strength Increased by 1!\n";
    }
    if (ss == 2)
    {
      v.dexterity += 1;
      cout << "Dexterity Increased by 1!\n";
    }
    if (ss == 3)
    {
      v.constitution += 1;
      cout << "Constitution Increased by 1!\n";
    }
    if (ss == 4)
    {
      v.intelligence += 1;
      cout << "Intelligence Increased by 1!\n";
    }
    if (ss == 5)
    {
      v.wisdom += 1;
      cout << "Wisdom Increased by 1!\n";
    }
    cout << endl;
    cout << endl;
  }
  cout << "Halfelfs' can also choose one of the following:\n\n";
  cout << "  1. Two skill proficiencies\n";
  cout << "  2. Keen Senses    <-option 1. is directly better (WotC wut why?)\n";
  cout << "  3. Elf Weapon Training   (Wood, Moon, or Sun elf heritage)\n";
  cout << "  4. Fleet of Foot         (Wood elf heritage)\n";
  cout << "  5. Mask of the Wild      (Wood elf heritage)\n";
  cout << "  6. Cantrip               (Moon or Sun elf heritage)\n";
  cout << "  7. Drow Magic            (Drow elf heritage)\n";
  cout << "  8. 30ft Swim Speed       (Aquatic elf heritage)\n\n";
  ss = getNumber("Choice: ", 1, 8);
  switch (ss)
  {
  case 1:
    v.setAnySkill("Gain any two skills:", 2);
    break;
  case 2:
    v.perception = true; // keen senses
    v.setAnySkill("We'll just pretend you picked option 1 and chose the first skill as Perception. Pick one more skill", 1);
    break;
  case 3:
    v.elf_weapon_training = true;
    cout << "Which elf heritage are you?\n\n";
    cout << "1. Wood elf\n";
    cout << "2. Moon elf\n";
    cout << "3. Sun elf\n";
    ss = getNumber("Choice: ", 1, 3);
    switch (ss)
    {
    case 1:
      elfheritage = WOOD;
      break;
    case 2:
      elfheritage = MOON;
      break;
    case 3:
      elfheritage = SUN;
      break;
    default:
      break;
    }
    cout << "Elf Weapon Training gained!";
    break;
  case 4:
    v.fleet_of_foot = true;
    elfheritage = WOOD;
    cout << "Fleet of Foot gained!";
    break;
  case 5:
    v.mask_of_the_wild = true;
    elfheritage = WOOD;
    cout << "Mask of the Wild gained!";
    break;
  case 6:
    v.wizard_cantrips_known++;
    cout << "Which elf heritage are you?\n\n";
    cout << "1. Moon elf\n";
    cout << "2. Sun elf\n";
    ss = getNumber("Choice: ", 1, 2);
    switch (ss)
    {
    case 1:
      elfheritage = MOON;
      break;
    case 2:
      elfheritage = SUN;
      break;
    default:
      break;
    }
    cout << "Cantrip gained!";
    break;
  case 7:
    v.drow_magic = true;
    elfheritage = DROW;
    cout << "Drow magic gained!";
    break;
  case 8:
    v.swim_speed = 30;
    elfheritage = AQUATIC;
    cout << "swim speed gained (30ft)";
    break;
  default:
    break;
  }
  pressEnterToContinue();
}
void Halforc::setRaceDetails(Generic_Character_Class &v)
{
  v.strength += 2;
  v.constitution += 2;
  v.move_speed = 30;
  v.darkvision = true;
  v.intimidation = true;
  v.common = true;
  v.orc = true;
  cout << "->Half-orc defaults & bonuses applied:\n"
       << " +2 STR, +1 CON, 30ft Move, Darkvision 60ft, Intimidation, Langs(Common, Orc)\n\n";
  pressEnterToContinue();
}
void Halfling::setRaceDetails(Generic_Character_Class &v)
{
  v.dexterity += 2;
  v.move_speed = 25;
  v.halflinglucky = true;
  v.brave = true;
  v.halfling_nimbleness = true;
  v.common = true;
  v.halfling = true;
  cout << "->Halfling defaults & bonuses applied:\n"
       << " +2 DEX, 25ft Move, Lucky, Brave, Nimbleness, Langs(Common, Halfing)\n\n";
  cout << "Which kind of Halfling?\n\n 1. Ghostwise\n 2. Lightfoot\n 3. Stout.\n\n";
  subr = static_cast<enum halflingtype>(getNumber("Halfling Type(1-3): ", 1, 3));
  switch (subr)
  {
  case GHOSTWISE:
    v.wisdom += 1;
    v.silent_speech = true;
    cout << "A Ghostwise halfing! Very rare indeed. Gain: \n"
            "  +1 Wisdom\n"
            "  Silent Speech\n\n";
    break;
  case LIGHTFOOT:
    v.charisma += 1;
    v.naturally_stealthy = true;
    cout << "->Lightfoot Halfling bonuses applied:\n"
         << " +1 CHA, Naturally Stealthy\n\n";
    break;
  case STOUT:
    v.constitution += 1;
    v.stout_resilience = true;
    v.damage_resist_poison = true;
    cout << "->Stout Halfling bonuses applied:\n"
         << " +1 CON, Stout Resilience\n\n";
  case NA:
  default:;
  }
  pressEnterToContinue();
}
void Human::setRaceDetails(Generic_Character_Class &v)
{
  cout << "------------------------\n"
          "Variant: Humans gain +1 to two different stats, a bonus skill, and a bonus feat.\n"
          "Normal: +1 to all stats\n"
          "------------------------\n";
  char rule = getYorN("Would you like to use the Variant Rule on Human Traits? (y/n): ");
  if (rule == 'N')
  {
    v.strength += 1;
    v.dexterity += 1;
    v.constitution += 1;
    v.intelligence += 1;
    v.wisdom += 1;
    v.charisma += 1;
    cout << "->Human +1 all stat bonus applied.\n";
  }
  else
  {
    cout << "->Human variant, +1 to 2 different stats choice.\n";
    v.increase2statsby1();
    v.setAnySkill("->Human variant, choose a skill:", 1);
    cout << "->Human variant, choose one feat.\n";
    v.setAnyFeat();
  }
  v.move_speed = 30;
  cout << "->Human base move speed is " << v.move_speed << ".\n";
  v.common = true;
  v.setLanguage("->Humans gain 'know one language of your choice.'\n\n");
  pressEnterToContinue();
}
void Kenku::setRaceDetails(Generic_Character_Class &v)
{
  v.dexterity += 2;
  v.wisdom++;
  v.move_speed = 30;
  v.expert_forgery = true;
  v.mimicry = true;
  v.common = true;
  v.auran = true;
  cout << "babababababirdbirdbird... bird with no words. A Kenku, master of mimicry. Gain: \n";
  cout << "  +2 Dexterity\n";
  cout << "  +1 Wisdom\n";
  cout << "  30ft Move Speed\n";
  cout << "  Expert Forgery\n";
  cout << "  Mimicry\n";
  cout << "  Common and Auran Languages\n";
  int ss = getNumber("Kenku Training. Gain one of these skills: \n  1. Acrobatics\n  2. Deception\n  3. Stealth\n  4. Sleight of Hand.\n\nChoice: ", 1, 4);
  switch (ss)
  {
  case 1:
    v.acrobatics = true;
    break;
  case 2:
    v.deception = true;
    break;
  case 3:
    v.stealth = true;
    break;
  case 4:
    v.sleight_of_hand = true;
    break;
  default:
    break;
  }
  pressEnterToContinue();
}
void Lizardfolk::setRaceDetails(Generic_Character_Class &v)
{
  v.constitution += 2;
  v.wisdom++;
  v.move_speed = 30;
  v.swim_speed = 30;
  v.lizardfolk_bite = true;
  v.cunning_artisan = true;
  v.hold_breath = 15;
  v.natural_armor = 13;
  v.hungry_jaws = true;
  v.common = true;
  v.draconic = true;
  int ss = getNumber("Hunter's Lore. Gain one of these skills: \n  1. Animal Handling\n  2. Nature\n  3. Perception\n  4. Stealth\n  5. Survival\n\nChoice: ", 1, 5);
  switch (ss)
  {
  case 1:
    v.animal_handling = true;
    break;
  case 2:
    v.nature = true;
    break;
  case 3:
    v.perception = true;
    break;
  case 4:
    v.stealth = true;
    break;
  case 5:
    v.survival = true;
    break;
  default:
    break;
  }
  pressEnterToContinue();
}
void Tabaxi::setRaceDetails(Generic_Character_Class &v)
{
  v.dexterity += 2;
  v.charisma++;
  v.move_speed = 30;
  v.darkvision = true;
  v.feline_agility = true;
  v.cats_claws = true; //climb speed 20ft + slashing attack
  v.climb_speed = 20;
  v.perception = true;
  v.stealth = true;
  v.common = true;
  cout << "A Tabaxi you are... Meow. Gain: \n";
  cout << "  +2 Dexterity\n";
  cout << "  +1 Charisma\n";
  cout << "  Darkvision\n";
  cout << "  Feline Agility\n";
  cout << "  Cat's Claws\n";
  cout << "  Cat's Talent(Perception & Stealth)\n";
  cout << "  Common Lang and.. \n";
  v.setLanguage("Tabaxi know one language of your choice.");
  pressEnterToContinue();
}
void Tiefling::setRaceDetails(Generic_Character_Class &v)
{
  v.intelligence += 1;
  v.move_speed = 30;
  v.darkvision = true;
  v.hellish_resistance = true;
  v.damage_resist_fire = true;
  v.common = true;
  v.infernal = true;
  cout << "->A Tiefling!?! Gain:\n";
  cout << "  +1 Intelligence\n";
  cout << "  30ft Move\n";
  cout << "  Darkvision\n";
  cout << "  Hellish Resistance\n";
  cout << "  Common and Infernal Languages\n\n";

  cout << "Choose one of the four abilities: \n\n";
  cout << "  1. Infernal Legacy\n";
  cout << "  2. Devil's Tongue\n";
  cout << "  3. Hellfire\n";
  cout << "  4. Winged\n\n";
  int ss = getNumber("Choice: ", 1, 4);
  switch (ss)
  {
  case 1:
    v.infernal_legacy = true;
    cout << "Infernal Legacy gained.";
    break;
  case 2:
    v.devils_tongue = true;
    cout << "Devil's Tongue gained.";
    break;
  case 3:
    v.hellfire = true;
    cout << "Hellfire gained.";
    break;
  case 4:
    v.fly_speed = 30; // winged
    cout << "You have bat-like wings. Gain 30ft fly speed.";
    break;
  default:
    break;
  }
  cout << endl
       << endl;

  cout << "Are you a Feral(+2 dex) or Not(+2 charisma)?\n\n";
  ss = getNumber(" 1. Feral\n 2. Not\n\nChoice:", 1, 2);
  switch (ss)
  {
  case 1:
    v.dexterity += 2;
    type = FERAL;
    cout << "  +2 Dexterity gained. You are a Feral Tiefling.\n";
    break;
  case 2:
    v.charisma += 2;
    cout << "  +2 Charisma gained.\n";
    break;
  default:
    break;
  }

  pressEnterToContinue();
}
void Triton::setRaceDetails(Generic_Character_Class &v)
{
  v.strength++;
  v.constitution++;
  v.charisma++;
  v.move_speed = 30;
  v.swim_speed = 30;
  v.amphibious = true;
  v.control_air_and_water = true;
  v.emissary_of_the_sea = true;
  v.guardian_of_the_depths = true;
  v.damage_resist_cold = true;
  cout << "You are a TRITON!? Gain: \n";
  cout << "  +1 Strength, Constitution, & Charisma\n";
  cout << "  30ft Move Speed & Swim Speed\n";
  cout << "  Amphibious\n";
  cout << "  Control Air and Water\n";
  cout << "  Emissary of the Sea\n";
  cout << "  Guardian of the Depths (Cold Resistance + more)\n";
  pressEnterToContinue();
}

//accessors
string Aasimar::getRaceString() const
{
  string tmp = "";
  switch (subr)
  {
  case PROTECTOR:
    tmp += "Protector ";
    break;
  case SCOURGE:
    tmp += "Scourge ";
    break;
  case FALLEN:
    tmp += "Fallen ";
    break;
  default:
    break;
  }
  return tmp + "Aasimar";
}
string Dragonborn::getRaceString() const
{
  return "Dragonborn";
}
string Dwarf::getRaceString() const
{
  string tmp = "";
  switch (subr)
  {
  case DUERGAR:
    tmp += "Duergar";
    break;
  case HILL:
    tmp += "Hill";
    break;
  case MOUNTAIN:
    tmp += "Mountain";
    break;
  case NA:
    break;
  default:
    break;
  }
  return tmp + " Dwarf";
}
string Elf::getRaceString() const
{
  string tmp = "";
  switch (subr)
  {
  case HIGH:
    tmp += "High ";
    break;
  case WOOD:
    tmp += "Wood ";
    break;
  case DROW:
    tmp += "Drow ";
    break;
  case NA:
    break;
  default:
    break;
  }
  return tmp + "Elf";
}
string Firbolg::getRaceString() const
{
  return "Firbolg";
}
string Gnome::getRaceString() const
{
  string tmp = "";
  switch (subr)
  {
  case FOREST:
    tmp += "Forest ";
    break;
  case ROCK:
    tmp += "Rock ";
    break;
  case SVIRFNEBLIN:
    tmp += "Svirfneblin ";
  case NA:
    break;
  default:
    break;
  }
  return tmp + "Gnome";
}
string Goliath::getRaceString() const
{
  return "Goliath";
}
string Halfelf::getRaceString() const
{
  string tmp = "";
  switch (elfheritage)
  {
  case AQUATIC:
    tmp += " (Aquatic Elf Heritage)";
    break;
  case DROW:
    tmp += " (Drow Elf Heritage)";
    break;
  case MOON:
    tmp += " (Moon Elf Heritage)";
    break;
  case SUN:
    tmp += " (Sun Elf Heritage)";
    break;
  case WOOD:
    tmp += " (Wood Elf Heritage)";
    break;
  case NA:
  default:
    break;
  }
  return "Halfelf" + tmp;
}
string Halfling::getRaceString() const
{
  string tmp = "";
  switch (subr)
  {
  case GHOSTWISE:
    tmp += "Ghostwise ";
    break;
  case LIGHTFOOT:
    tmp += "Lightfoot ";
    break;
  case STOUT:
    tmp += "Stout ";
    break;
  case NA:
    break;
  default:
    break;
  }
  return tmp + "Halfling";
}
string Halforc::getRaceString() const
{
  return "Halforc";
}
string Human::getRaceString() const
{
  return "Human";
}
string Kenku::getRaceString() const
{
  return "Kenku";
}
string Lizardfolk::getRaceString() const
{
  return "Lizardfolk";
}
string Tabaxi::getRaceString() const
{
  return "Tabaxi";
}
string Tiefling::getRaceString() const
{
  string tmp = "";
  switch (type)
  {
  case FERAL:
    tmp += "Feral ";
    break;
  default:
    break;
  }
  return tmp + "Tiefling";
}
string Triton::getRaceString() const
{
  return "Triton";
}