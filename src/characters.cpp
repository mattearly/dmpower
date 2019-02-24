#include <iomanip>
#include <cmath>
#include <vector>
#include "gen_name.h"
#include "characters.h"

using namespace std;

Generic_Character_Class::Generic_Character_Class()
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
  druidic = 0;
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
  abyssal = 0;
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
  elf_weapon_training = 0;
  fey_ancestry = 0;
  fleet_of_foot = 0;
  halflinglucky = 0;
  halfling_nimbleness = 0;
  hellish_resistance = 0;
  infernal_legacy = 0;
  mask_of_the_wild = 0;
  natural_illusionist = 0;
  naturally_stealthy = 0;
  speak_with_small_beasts = 0;
  stonecunning = 0;
  stout_resilience = 0;
  superior_darkvision = 0;
  trance = 0;
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
  proficiency_bonus = 0;
  extra_attack = 0;
  expertise = 0;

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
}

Generic_Character_Class::~Generic_Character_Class() { }

std::string Generic_Character_Class::getRace() const
{
  return race;
}

// mutators
void Generic_Character_Class::setName()
{
  cout << "Name Your Character! (can be edited later)\n\n"

       " -> " << RED << "RULES" << RESET << "\n"
       "    + Length: 2 or more characters\n"
       "    + Must be Unique\n"
       "    + First letter is automatically Capitalized\n"
       " -> Enter '" << GREEN << "random" << RESET << "' (without the quotes) to be suggested a random name!\n\n";

  string i_name;
  do
  {
    cout << "Enter Name: ";
    getline(cin, i_name);
    i_name[0] = toupper(i_name[0]); //makes the first letter of the name uppercase
    i_name = reduce(i_name);		//gets rid of leading and trailing whitespace and any extra spaces in between
    if (i_name.size() < 2 || i_name[0] == ' ')
    {
      cout << "Invalid name, try another.\n";
    }
     if (i_name == "Random")
     {
       suggestRandomName(i_name);
     }
  } while (i_name.size() < 2);
  char_name = i_name;
  simpleClearScreen();
}

void Generic_Character_Class::setRace(Generic_Character_Class &v)
{
  simpleClearScreen();
  cout << "Choose a Race for your Character:\n\n"
       << "1. Dragonborn   6. Halfing"
       << "\n2. Dwarf        7. Half-orc"
       << "\n3. Elf          8. Human"
       << "\n4. Gnome        9. Tiefling"
       << "\n5. Half-elf\n\n";
  int ss = getNumber("Choose Race(1-9): ", 1, 9);
  simpleClearScreen();

  Races *parent = nullptr;
  if (ss == 1)
  {
    parent = new Dragonborn;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 2)
  {
    parent = new Dwarf;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 3)
  {
    parent = new Elf;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 4)
  {
    parent = new Gnome;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 5)
  {
    parent = new Halfelf;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 6)
  {
    parent = new Halfling;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 7)
  {
    parent = new Halforc;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else if (ss == 8)
  {
    parent = new Human;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }
  else
  {
    parent = new Tiefling;
    parent->setRaceDetails(v);
    race = parent->getRaceString();
  }

  if(parent != nullptr) {
    delete parent;
  }
}

void Generic_Character_Class::setAlignment()
{
  simpleClearScreen();
  cout << "Pick an Alignment for " << char_name << ".\n\n"
       << "1. Chaotic Evil     6. Neutral Good"
       << "\n2. Chaotic Neutral  7. Lawful Evil"
       << "\n3. Chaotic Good     8. Lawful Neutral"
       << "\n4. Neutral Evil     9. Lawful Good"
       << "\n5. True Neutral\n\n";
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

void Generic_Character_Class::setBackground()
{
  simpleClearScreen();
  cout << "Pick a background for your character.\n\n"
       << " 1. Acolyte             14. Inheritor\n"
       << " 2. Charlatan           15. Knight of the Order\n"
       << " 3. City Watch          16. Mercenary Veteran\n"
       << " 4. Clan Crafter        17. Noble\n"
       << " 5. Cloistered Scholar  18. Outlander\n"
       << " 6. Courtier            19. Sage\n"
       << " 7. Criminal            20. Sailor\n"
       << " 8. Entertainer         21. Soldier\n"
       << " 9. Faction Agent       22. Urban Bounty Hunter\n"
       << "10. Far Traveler        23. Urchin\n"
       << "11. Folk Hero           24. Uthgardt Tribe Member\n"
       << "12. Guild Artisan       25. Waterdhavian Noble\n"
       << "13. Hermit\n\n";

  int ss = getNumber("Background choice: ", 1, 25);
  backgroundofpc = static_cast<enum characterbackground>(ss);
  switch (ss)
  {
  case 1: //acolyte
    insight = true;
    religion = true;
    setLanguage("First Acolyte bonus language.\n\n");
    setLanguage("Second Acolyte bonus language.\n\n");
    cout << "Acolyte background: \n ->gained Insight, Religion, & 2 Langs.\n";
    break;
  case 2: //charlatan
    deception = true;
    sleight_of_hand = true;
    disguise = true;
    forgery = true;
    cout << "Charlatan background: \n ->gained Deception, Sleight of Hand, Disquise, & Forgery.\n";
    break;
  case 3: //city watch
    athletics = true;
    insight = true;
    setLanguage("First City Watch bonus language.\n\n");
    setLanguage("Second City Watch bonus language.\n\n");
    cout << "City Watch background: \n ->gained Athletics, Insight, & 2 Langs.\n";
    break;
  case 4: //clan crafter
    history = true;
    insight = true;
    setTools(1);
    if (!dwarvish)
      dwarvish = true;
    else
      setLanguage("Clan Crafter bonus language.\n\n");
    cout << "Clan Crafter background: \n ->gained History, Insight, 1 Artisan Tool & 1 Langs.\n";
    break;
  case 5: //cloistered scholar
  {
    history = true;
    cout << "Skill for Cloistered Scholar Background\n\n Pick from\n"
         << " 1. Arcana\n 2. Nature\n 3. Religion\n\n";
    int tmp = getNumber("Choice: ", 1, 3);
    switch (tmp)
    {
    case 1:
      arcana = true;
      break;
    case 2:
      nature = true;
      break;
    case 3:
      religion = true;
      break;
    default:
      break;
    }
    setLanguage("First Cloistered Scholar bonus language.\n\n");
    setLanguage("Second Cloistered Scholar bonus language.\n\n");
    cout << "Cloistered Scholar background: \n ->gained History, Choice Skill, & 2 Langs.\n";
  }
    break;
  case 6: //courtier
    insight = true;
    persuasion = true;
    setLanguage("First Courtier bonus language.\n\n");
    setLanguage("Second Courtier bonus language.\n\n");
    cout << "Courtier background: \n ->gained Insight, Persuasion, & 2 Langs.\n";
    break;
  case 7: //criminal
    deception = true;
    stealth = true;
    thieves = true;
    //gaming kit here
    cout << "Criminal background: \n ->gained Deception, Stealth, Thieve's Tools, & Gaming Tool.\n";
    break;
  case 8: //entertainer
    acrobatics = true;
    performance = true;
    disguise = true;
    setInstrument("Choose an Entertainer's instrument.\n\n", 1);
    cout << "Entertainer background:\n ->Acrobatics, Performance, Disguise Kit, & Musical Instrument.\n";
    break;
  case 9: //faction agent
    insight = true;
    setAnySkill("Faction Agent background bonus skill.\n\n", 1); //should be int,wis,cha skill choice only
    setLanguage("First Faction Agent bonus language.\n\n");
    setLanguage("Second Faction Agent bonus language.\n\n");
    cout << "Faction Agent background: \n ->gained Insight, int/wis/cha skill, & 2 Langs.\n";
    break;
  case 10: //far traveler
    insight = true;
    perception = true;
    //any instrument or gaming set
    setLanguage("Far Traveler background bonus language.\n\n");
    cout << "Acolyte background: \n ->gained Insight, Religion, & 2 Langs.\n";
    break;
  case 11: //folk hero
    animal_handling = true;
    survival = true;
    setTools(1);
    vehicle = true;
    cout << "Folk Hero background:\n ->gained Animal Handling, Survival, Artisan's Tool, & Land Vehicle.\n";

    break;
  case 12: //guild artisan
    insight = true;
    persuasion = true;
    setTools(1);
    setLanguage("Guild Artisan bonus language.\n\n");
    cout << "Guild Artisan background:\n ->gained Insight, Persuasion, Artisan's Tools, & a Language.\n";

    break;
  case 13: //hermit
    medicine = true;
    religion = true;
    herbalism = true;
    setLanguage("Hermit bonus language.\n\n");
    cout << "Hermit background:\n ->gained Medicine, Religion, Herbalism, & a Language.\n";

    break;
  case 14: //inheritor
  {
    survival = true;
    cout << "Pick a Skill for Inheritor Background:\n\n"
         << " 1. Arcana\n 2. History\n 3. Religion\n\n";
    int tmp = getNumber(" Choice: ", 1, 3);
    switch (tmp)
    {
    case 1:
      arcana = true;
      break;
    case 2:
      history = true;
      break;
    case 3:
      religion = true;
      break;
    default:
      break;
    }
    //gain musical instrument or gaming tool
    setLanguage("Inheritor bonus language.\n\n");
    cout << "Inheritor background: \n ->gained Survival, Choice Skill, Musical Instrument or Gaming set, & 1 Lang.\n";
  }
    break;
  case 15: //knight of the order
  {
    persuasion = true;
    cout << "Skill for Knight of the Order Background\n\n Pick from\n"
         << " 1. Arcana\n 2. History\n 3. Nature \n 4. Religion\n\n";
    int tmp = getNumber("Choice: ", 1, 4);
    switch (tmp)
    {
    case 1:
      arcana = true;
      break;
    case 2:
      history = true;
      break;
    case 3:
      nature = true;
      break;
    case 4:
      religion = true;
      break;
    default:
      break;
    }
    //gain musical instrument or gaming tool
    setLanguage("Knight of the Order bonus language.\n\n");
    cout << "Knight of the Order background: \n ->gained Persuasion, Choice Skill, Musical Instrument or Gaming set, & 1 Lang.\n";
  }
    break;
  case 16: //mercenary veteran
    athletics = true;
    persuasion = true;
    //gain gaming or vehicle
    //something else i must be missing
    cout << "Mercenary Veteran background: \n ->gained Athletics, Persuasion, & gaming set or land vehicle";
    break;
  case 17: //noble
    history = true;
    persuasion = true;
    //gaming kit here
    setLanguage("Noble bonus language.\n\n");
    cout << "Noble background:\n ->gained History, Persuasion, Gaming Kit, & a Language.\n";

    break;
  case 18: //outlander
    athletics = true;
    survival = true;
    setInstrument("Outlander instrument.\n\n", 1);
    setLanguage("Outlander bonus language.\n\n");
    cout << "Outlander background:\n ->gained Atheltics, Survival, Musical Instrument, & a Language.\n";

    break;
  case 19: //sage
    arcana = true;
    history = true;
    setLanguage("First Sage bonus language.\n\n");
    setLanguage("Second Sage bonus language.\n\n");
    cout << "Sage background:\n ->gained Arcana, History, & two Languages.\n";

    break;
  case 20: //sailor
    athletics = true;
    perception = true;
    navigator = true;
    vehicle = true;
    cout << "Sailor background:\n ->gained Athletics, Perception, Navigator's Tools, & Water Vehicle.\n";

    break;
  case 21: //soldier
    athletics = true;
    intimidation = true;
    //gaming set here;
    vehicle = true;
    cout << "Soilder background:\n ->gained Athletics, Intimidation, Gaming Set, & Land Vehicle.\n";

    break;
  case 22: //urban bounty hunter
  {
    for (int i = 0; i < 2; i++)
    {
      cout << "\n";
      if (i == 0)
        cout << "First ";
      else
        cout << "Second ";
      cout << "Skill for Urban Bounty Hunter Background\n\n Pick from:\n\n";

      if (deception)
        cout << " 1. Deception(Already Known)\n";
      else
        cout << " 1. Deception\n";
      if (insight)
        cout << " 2. Insight(Already Known)\n";
      else
        cout << " 2. Insight\n";
      if (persuasion)
        cout << " 3. Persuasion(Already Known)\n";
      else
        cout << " 3. Persuasion\n";
      if (stealth)
        cout << " 4. Stealth(Already Known)\n";
      else
        cout << " 4. Stealth\n";

      int tmp = getNumber("\nChoice: ", 1, 4);
      switch (tmp)
      {
      case 1:
        if (!deception)
          deception = true;
        else
        {
          cout << "Deception Already Known, Choose Another Skill.\n";
          i--;
        }
        break;
      case 2:
        if (!insight)
          insight = true;
        else
        {
          cout << "Insight Already Known, Choose Another Skill.\n";
          i--;
        }
        break;
      case 3:
        if (!persuasion)
          persuasion = true;
        else
        {
          cout << "Persuasion Already Known, Choose Another Skill.\n";
          i--;
        }
        break;
      case 4:
        if (!stealth)
          stealth = true;
        else
        {
          cout << "Stealth Already Known, Choose Another Skill.\n";
          i--;
        }
        break;
      default:
        break;
      }
    }
    thieves = true; //thieves tools
    setInstrument("Gain any instrument for the Urban Bounty Hunter background.\n", 1);
    //gain one gaming set
    cout << "Urban Bounty Hunter background: \n ->gained 2 Choice Skills, Choice instrument, gaming set(not programmed in yet), and thieves tools.\n";
  }
    break;
  case 23: //urchin
    sleight_of_hand = true;
    stealth = true;
    disguise = true;
    thieves = true;
    cout << "Urchin background:\n ->gained Sleight of hand, Stealth, Disguise Kit, & Thieves' Tools.\n";

    break;
  case 24: //uthgardt tribe member
    athletics = true;
    survival = true;
    //gain tool or musical instrument
    setLanguage("Uthgardt Tribe Member bonus Language.\n\n");
    cout << "Uthgardt Tribe Member background: \n ->gained Athletics, Survival, Artisan tool or Musical instrument, & 1 Lang.\n";
    break;
  case 25: //waterdhavian noble
    history = true;
    persuasion = true;
    //gain musical or gaming
    setLanguage("Waterdhavain Noble bonus Language.\n\n");
    cout << "Waterdhavian Noble background: \n ->gained History, Persuasion, Musical or Gaming, & 1 Langs.\n";
    break;
  default:
    cout << "Error setting background\n\n";
    break;
  }
  pressEnterToContinue();
}

void Generic_Character_Class::setAllStats()
{
  vector<int> stats;

  // display stat menu system to end user
  int stat_ver_choice = 0;
  cout << "How would you like to do Ability Stats?\n"
          "---------------------------------------\n\n"
       << "1. " << RED << "Hi-Powered Legit" << RESET << "Roll Set : roll " << GREEN << "4d6 6 " << RESET << "times, dropping lowest die each time\n"
       << "2. " << YELLOW << "Legit " << RESET << "Roll Set : roll " << GREEN << "3d6 6 " << RESET << "times\n"
       << "3. " << BLUE << "Standard " << RESET << "Array Set : " << GREEN << "[15, 14, 13, 12, 10, 8]" << RESET << "\n"
       << "4. " << CYAN << "Custom " << RESET << "Array Set : Enter in your own custom stats.\n\n";
  stat_ver_choice = getNumber("Choice: ", 1, 4);

  // process end user choice
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

  // if not already custom assigned, prompt to assign each score to an ability
  if (stat_ver_choice != 4)
  {
    // display 6 results ready for assignment
    cout << "\n\n  Your 6 Starting Ability Rolls To Assign:\n";
    for (int j = 0; j < 6; j++)
    {
      cout << GREEN << stats[j] << RESET;
      if (j != 5)
        cout << ", ";
    }
    cout << "\nWe are now assigning your 6 core stats...\n";
    // prompt for all 6 ability score assignments
    for (int i = 0; i < 6; i++)
    {
      cout << "Stats Left: ";
      for (int j = i; j < 6; j++)
      {
        cout << CYAN << stats[j] << RESET;
        if (j != 5)
          cout << ", ";
      }
      cout << endl;
      assignStats(stats[i]);
    }
  }

  cout << "YOUR ASSIGNED ABILITY STATS (before any bonuses)\n\n"
       << "------\n"
       << "  STR: ";
  if (strength != 0)
    cout << GREEN << strength << RESET << endl;
  else
    cout << RED << "Not Set(error check code)" << RESET << endl;
  cout << "  DEX: ";
  if (dexterity != 0)
    cout << GREEN << dexterity << RESET << endl;
  else
    cout << RED << "Not Set(error check code)" << RESET << endl;
  cout << "  CON: ";
  if (constitution != 0)
    cout << GREEN << constitution << RESET << endl;
  else
    cout << RED << "Not Set(error check code)" << RESET << endl;
  cout << "  INT: ";
  if (intelligence != 0)
    cout << GREEN << intelligence << RESET << endl;
  else
    cout << RED << "Not Set(error check code)" << RESET << endl;
  cout << "  WIS: ";
  if (wisdom != 0)
    cout << GREEN << wisdom << RESET << endl;
  else
    cout << RED << "Not Set(error check code)" << RESET << endl;
  cout << "  CHA: ";
  if (charisma != 0)
    cout << GREEN << charisma << RESET << endl;
  else
    cout << RED << "Not Set(error check code)" << RESET << endl;
  cout << "------" << endl;

  pressEnterToContinue();
}

void Generic_Character_Class::setLanguage(const string &message)
{
  bool success = 0;
  while (!success)
  {
    cout << message;
    if (abyssal)
      cout << " 1 - Abyssal(Already Known)";
    else
      cout << " 1 - Abyssal";
    if (celestial)
      cout << "\n 2 - Celestial(Already Known)";
    else
      cout << "\n 2 - Celestial";
    if (deep_speech)
      cout << "\n 3 - Deep Speech(Already Known)";
    else
      cout << "\n 3 - Deep Speech";
    if (draconic)
      cout << "\n 4 - Draconic(Already Known)";
    else
      cout << "\n 4 - Draconic";
    if (druidic)
      cout << "\n 5 - Druidic(Already Known)";
    else
      cout << "\n 5 - Druidic";
    if (dwarvish)
      cout << "\n 6 - Dwarvish(Already Known)";
    else
      cout << "\n 6 - Dwarvish";
    if (elvish)
      cout << "\n 7 - Elvish(Already Known)";
    else
      cout << "\n 7 - Elvish";
    if (giant)
      cout << "\n 8 - Giant(Already Known)";
    else
      cout << "\n 8 - Giant";
    if (gnomish)
      cout << "\n 9 - Gnomish(Already Known)";
    else
      cout << "\n 9 - Gnomish";
    if (goblin)
      cout << "\n 10 - Goblin(Already Known)";
    else
      cout << "\n 10 - Goblin";
    if (gnoll)
      cout << "\n 11 - Gnoll(Already Known)";
    else
      cout << "\n 11 - Gnoll";
    if (halfling)
      cout << "\n 12 - Halfling(Already Known)";
    else
      cout << "\n 12 - Halfling";
    if (infernal)
      cout << "\n 13 - Infernal(Already Known)";
    else
      cout << "\n 13 - Infernal";
    if (orc)
      cout << "\n 14 - Orc(Already Known)";
    else
      cout << "\n 14 - Orc";
    if (primordial)
      cout << "\n 15 - Primordial(Already Known)";
    else
      cout << "\n 15 - Primordial";
    if (sylvan)
      cout << "\n 16 - Sylvan(Already Known)";
    else
      cout << "\n 16 - Sylvan";
    if (undercommon)
      cout << "\n 17 - Undercommon(Already Known)\n\n";
    else
      cout << "\n 17 - Undercommon\n\n";
    int ss = getNumber("Language Choice: ", 1, 17);
    if (ss == 1 && abyssal == 0)
    {
      abyssal = true;
      cout << "Abyssal Language learned!\n";
      success = 1;
    }
    if (ss == 2 && celestial == 0)
    {
      celestial = true;
      cout << "Celestial Language learned!\n";
      success = 1;
    }
    if (ss == 3 && deep_speech == 0)
    {
      deep_speech = true;
      cout << "Deep Speech Language learned!\n";
      success = 1;
    }
    if (ss == 4 && draconic == 0)
    {
      draconic = true;
      cout << "Draconic Language learned!\n";
      success = 1;
    }
    if (ss == 5 && druidic == 0)
    {
      druidic = true;
      cout << "Druidic Language learned!\n";
      success = 1;
    }
    if (ss == 6 && dwarvish == 0)
    {
      dwarvish = true;
      cout << "Dwarvish Language learned!\n";
      success = 1;
    }
    if (ss == 7 && elvish == 0)
    {
      elvish = true;
      cout << "Elvish Language learned!\n";
      success = 1;
    }
    if (ss == 8 && giant == 0)
    {
      giant = true;
      cout << "Giant Language learned!\n";
      success = 1;
    }
    if (ss == 9 && gnomish == 0)
    {
      gnomish = true;
      cout << "Gnomish Language learned!\n";
      success = 1;
    }
    if (ss == 10 && goblin == 0)
    {
      goblin = true;
      cout << "Goblin Language learned!\n";
      success = 1;
    }
    if (ss == 11 && gnoll == 0)
    {
      gnoll = true;
      cout << "Gnoll Language learned!\n";
      success = 1;
    }
    if (ss == 12 && halfling == 0)
    {
      halfling = true;
      cout << "Halfling Language learned!\n";
      success = 1;
    }
    if (ss == 13 && infernal == 0)
    {
      infernal = true;
      cout << "Infernal Language learned!\n";
      success = 1;
    }
    if (ss == 14 && orc == 0)
    {
      orc = true;
      cout << "Orc Language learned!\n";
      success = 1;
    }
    if (ss == 15 && primordial == 0)
    {
      primordial = true;
      cout << "Primordial Language learned!\n";
      success = 1;
    }
    if (ss == 16 && sylvan == 0)
    {
      sylvan = true;
      cout << "Sylvan Language learned!\n";
      success = 1;
    }
    if (ss == 17 && undercommon == 0)
    {
      undercommon = true;
      cout << "Undercommon Language learned!\n";
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
    cout << " 1. Bagpipes   6. Lyre"
         << "\n 2. Drum       7. Horn"
         << "\n 3. Dulcimer   8. Pan Flute"
         << "\n 4. Flute      9. Shawm"
         << "\n 5. Lute      10. Viol\n\n";
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
    cout << "1. Alchemist Tools          10. Leatherworker's Supplies"
         << "\n2. Brewer's Supplies        11. Mason's Tools"
         << "\n3. Calligrapher's Supplies  12. Painter's Supplies"
         << "\n4. Carpenter's Tools        13. Potter Tools"
         << "\n5. Cartographer's Tools     14. Smith's Tools"
         << "\n6. Cobbler's Tools          15. Tinker's Tools"
         << "\n7. Cook's Utensils          16. Weaver's Tools"
         << "\n8. Glassblower Tools        17. Woodcarver's Tools"
         << "\n9. Jeweler's Tools\n\n";
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
    while ((cout << "Enter a number to choose: " && !(cin >> ss)) || ((ss < 1 || ss > 6) || ss == tmp))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Invalid, try again." << endl;
    }
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
    while ((cout << "Enter a number to choose: " && !(cin >> ss)) || ((ss < 1 || ss > 6) || ss == tmp))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Invalid, try again." << endl;
    }
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
  cout << "1. Artic    5. Grassland"
       << "\n2. Coast    6. Mountain"
       << "\n3. Desert   7. Swamp"
       << "\n4. Forest   8. Underdark\n\n";
  int ss = getNumber("Select Land Type: ", 1, 8);
  if (ss == 1)
    artic = true;
  if (ss == 2)
    coast = true;
  if (ss == 3)
    desert = true;
  if (ss == 4)
    forest = true;
  if (ss == 5)
    grassland = true;
  if (ss == 6)
    mountain = true;
  if (ss == 7)
    swamp = true;
  if (ss == 8)
    underdark = true;
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
  ranger_attr.favored_enemy_languages = true;
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
  pressEnterToContinue();
}

// displayers
void Generic_Character_Class::landtype() const
{
  if (artic)
    cout << "Artic, ";
  if (coast)
    cout << "Coast, ";
  if (desert)
    cout << "Desert, ";
  if (forest)
    cout << "Forest, ";
  if (grassland)
    cout << "Grassland, ";
  if (mountain)
    cout << "Mountain, ";
  if (swamp)
    cout << "Swamp, ";
  if (underdark)
    cout << "Underdark";
}

void Generic_Character_Class::creaturetype() const
{
  if (aberrations)
    cout << "Aberration, ";
  if (beasts)
    cout << "Beasts, ";
  if (celestials)
    cout << "Celestials, ";
  if (constructs)
    cout << "Constructs, ";
  if (dragons)
    cout << "Dragons, ";
  if (elementals)
    cout << "Elementals, ";
  if (fey)
    cout << "Fey, ";
  if (fiends)
    cout << "Fiends, ";
  if (giants)
    cout << "Giants, ";
  if (monstrosities)
    cout << "Monstrosities, ";
  if (oozes)
    cout << "Oozes, ";
  if (plants)
    cout << "Plants, ";
  if (undead)
    cout << "Undead, ";
  if (twohumanoids > 0)
    cout << "Humanoids(" << twohumanoids * 2 << ")";
}

string Generic_Character_Class::getBackground() const
{
  string tmp = "";
  switch (backgroundofpc)
  {
  case NOBACKGROUND:
    break;
  case ACOLYTE:
    tmp = "Acolyte";
    break;
  case CHARLATAN:
    tmp = "Charlatan";
    break;
  case CRIMINAL:
    tmp = "Criminal";
    break;
  case ENTERTAINER:
    tmp = "Entertainer";
    break;
  case FOLK_HERO:
    tmp = "Folk Hero";
    break;
  case GUILD_ARTISAN:
    tmp = "Guild Artisan";
    break;
  case HERMIT:
    tmp = "Hermit";
    break;
  case NOBLE:
    tmp = "Noble";
    break;
  case OUTLANDER:
    tmp = "Outlander";
    break;
  case SAGE:
    tmp = "Sage";
    break;
  case SAILOR:
    tmp = "Sailor";
    break;
  case SOLDIER:
    tmp = "Soldier";
    break;
  case URCHIN:
    tmp = "Urchin";
    break;
  case CITY_WATCH:
    tmp = "City Watch";
    break;
  case CLAN_CRAFTER:
    tmp = "Clan Crafter";
    break;
  case CLOISTERED_SCHOLAR:
    tmp = "Cloistered Scholar";
    break;
  case COURTIER:
    tmp = "Courtier";
    break;
  case FACTION_AGENT:
    tmp = "Faction Agent";
    break;
  case FAR_TRAVELER:
    tmp = "Far Traveler";
    break;
  case INHERITOR:
    tmp = "Inheritoir";
    break;
  case KNIGHT_OF_THE_ORDER:
    tmp = "Knight of the Order";
    break;
  case MERCENARY_VETERAN:
    tmp = "Mercenary Veteran";
    break;
  case URBAN_BOUNTY_HUNTER:
    tmp = "Urban Bounty Hunter";
    break;
  case UTHGARDT_TRIBE_MEMBER:
    tmp = "Uthgardt Tribe Member";
    break;
  case WATERDHAVIAN_NOBLE:
    tmp = "Waterdhavain Noble";
    break;
  default:
    tmp = "Error Displaying Background - Check Code";
    break;
  }
  return tmp;
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
  cout << "\n-----" << GREEN << "Stats Set So Far" << RESET << "-----\n";
  cout << "  Strength: ";
  if (strength != 0)
    cout << GREEN << strength << RESET << "\n";
  else
    cout << RED << "Not Set" << RESET << "\n";
  cout << "  Dexterity: ";
  if (dexterity != 0)
    cout << GREEN << dexterity << RESET << "\n";
  else
    cout << RED << "Not Set" << RESET << "\n";
  cout << "  Constitution: ";
  if (constitution != 0)
    cout << GREEN << constitution << RESET << "\n";
  else
    cout << RED << "Not Set" << RESET << "\n";
  cout << "  Intelligence: ";
  if (intelligence != 0)
    cout << GREEN << intelligence << RESET << "\n";
  else
    cout << RED << "Not Set" << RESET << "\n";
  cout << "  Wisdom: ";
  if (wisdom != 0)
    cout << GREEN << wisdom << RESET << "\n";
  else
    cout << RED << "Not Set" << RESET << "\n";
  cout << "  Charisma: ";
  if (charisma != 0)
    cout << GREEN << charisma << RESET << "\n";
  else
    cout << RED << "Not Set" << RESET << "\n";
  cout << "--------------------------"
       << "\n\n";

  cout << "Chosen Character Class: " << char_class << endl;
  cout << "Assign NEXT Stat -> " << GREEN << s << RESET << " <- to: \n\n";

  if (strength == 0)
    cout << " 1. Strength\n";
  else
    cout << YELLOW << " 1. Strength(DONE)" << RESET << "\n";

  if (dexterity == 0)
    cout << " 2. Dexterity\n";
  else
    cout << YELLOW << " 2. Dexterity(DONE)" << RESET << "\n";

  if (constitution == 0)
    cout << " 3. Constitution\n";
  else
    cout << YELLOW << " 3. Constitution(DONE)" << RESET << "\n";

  if (intelligence == 0)
    cout << " 4. Intelligence\n";
  else
    cout << YELLOW << " 4. Intelligence(DONE)" << RESET << "\n";

  if (wisdom == 0)
    cout << " 5. Wisdom\n";
  else
    cout << YELLOW << " 5. Wisdom(DONE)" << RESET << "\n";

  if (charisma == 0)
    cout << " 6. Charisma\n\n";
  else
    cout << YELLOW << " 6. Charisma(DONE)" << RESET << "\n\n";
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
  simpleClearScreen();
}
