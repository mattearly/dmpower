#ifndef CHARACTERS_H
#define CHARACTERS_H
#pragma once

#include "races.h"
#include "globalfuncts.h"
#include "campaign.h"

class Campaign;

struct cleric_attributes {
  float destroy_undead;

  int channel_divinity;
  int divine_domain_feature;
  int divine_intervention;
  int cleric_cantrips_known;

  bool divine_domain;
  bool arcana_d;
  bool death_d;
  bool knowledge_d;
  bool life_d;
  bool light_d;
  bool nature_d;
  bool tempest_d;
  bool trickery_d;
  bool war_d;

  cleric_attributes() {
    destroy_undead = 0.0f;

    channel_divinity = 0;
    divine_domain_feature = 0;
    divine_intervention = 0;
    cleric_cantrips_known = 0;

    divine_domain = false;
    arcana_d = false;
    death_d = false;
    knowledge_d = false;
    life_d = false;
    light_d = false;
    nature_d = false;
    tempest_d = false;
    trickery_d = false;
    war_d = false;
  }
};

struct fighter_attributes {
  int action_surge;
  int martial_archtype_feature;
  int indomitable;
  int eldritch_spells_known;

  bool second_wind;
  bool martial_archtype;
  bool archery;
  bool two_weapon_fighting;
  bool champion;
  bool battle_master;
  bool eldritch_knight;
  bool purple_dragon_knight;

  fighter_attributes() {
    action_surge = 0;
    martial_archtype_feature = 0;
    indomitable = 0;
    eldritch_spells_known = 0;

    second_wind = false;
    martial_archtype = false;
    archery = false;
    two_weapon_fighting = false;
    champion = false;
    battle_master = false;
    eldritch_knight = false;
    purple_dragon_knight = false;
  }
};

struct barbarian_attributes {
  int rages;
  int rage_damage;
  int path_feature;
  int brutal_critical;

  bool reckless_attack;
  bool danger_sense;
  bool primal_path;
  bool fast_movement;
  bool feral_instinct;
  bool relentless_rage;
  bool persistant_rage;
  bool indomitable_might;
  bool primal_champion;
  bool path_of_the_battlerager;
  bool path_of_the_berseker;
  bool path_of_the_totem_warrior;
  bool bear_totem;
  bool eagle_totem;
  bool wolf_totem;

  barbarian_attributes() {
    rages = 0;
    rage_damage = 0;
    path_feature = 0;
    brutal_critical = 0;

    reckless_attack = false;
    danger_sense = false;
    primal_path = false;
    fast_movement = false;
    feral_instinct = false;
    relentless_rage = false;
    persistant_rage = false;
    indomitable_might = false;
    primal_champion = false;
    path_of_the_battlerager = false;
    path_of_the_berseker = false;
    path_of_the_totem_warrior = false;
    bear_totem = false;
    eagle_totem = false;
    wolf_totem = false;
  }
};

struct bard_attributes {
  int bardic_inspiration;
  int song_of_rest;
  int bard_college_feature;
  int magical_secrets;
  int bard_spells_known;
  int bard_cantrips_known;

  bool jack_of_all_trades;
  bool bard_college;
  bool font_of_inspiration;
  bool countercharm;
  bool superior_inspiration;
  bool college_of_lore;
  bool college_of_valor;
  bool additional_magical_secrets;

  bard_attributes() {
    bardic_inspiration = 0;
    song_of_rest = 0;
    bard_college_feature = 0;
    magical_secrets = 0;
    bard_spells_known = 0;
    bard_cantrips_known = 0;

    jack_of_all_trades = false;
    bard_college = false;
    font_of_inspiration = false;
    countercharm = false;
    superior_inspiration = false;
    college_of_lore = false;
    college_of_valor = false;
    additional_magical_secrets = false;
  }
};

struct druid_attributes {
  float wild_shape_improvement;

  int druid_circle_feature;
  int druid_cantrips_known;
  
  bool wild_shape;
  bool druid_circle;
  bool beast_spells;
  bool archdruid;
  bool circle_of_the_moon;
  bool circle_of_the_land;

  druid_attributes() {
    wild_shape_improvement = 0.0f;

    druid_circle_feature = 0;
    druid_cantrips_known = 0;

    wild_shape = false;
    druid_circle = false;
    beast_spells = false;
    archdruid = false;
    circle_of_the_moon = false;
    circle_of_the_land = false;
  }
};

struct monk_attributes {
  int monastic_tradition_feature;
  int ki;
  int unarmored_movement;
  int martial_arts;

  bool monastic_tradition;
  bool deflect_missles;
  bool slow_fall;
  bool stunning_strike;
  bool ki_empowered_strikes;
  bool stillness_of_mind;
  bool purity_of_body;
  bool tongue_of_the_sun_and_moon;
  bool diamond_soul;
  bool empty_body;
  bool perfect_self;
  bool way_of_the_open_hand;
  bool way_of_the_four_elements;
  bool way_of_the_long_death;
  bool way_of_the_shadow;
  bool way_of_the_sun_soul;
  bool unarmored_movement_improvement;

  monk_attributes() {
    monastic_tradition_feature = 0;
    ki = 0;
    unarmored_movement = 0;
    martial_arts = 0;

    monastic_tradition = false;
    deflect_missles = false;
    slow_fall = false;
    stunning_strike = false;
    ki_empowered_strikes = false;
    stillness_of_mind = false;
    purity_of_body = false;
    tongue_of_the_sun_and_moon = false;
    diamond_soul = false;
    empty_body = false;
    perfect_self = false;
    way_of_the_open_hand = false;
    way_of_the_four_elements = false;
    way_of_the_long_death = false;
    way_of_the_shadow = false;
    way_of_the_sun_soul = false;
    unarmored_movement_improvement = false;
  }
};

struct paladin_attributes {
  int sacred_oath_feature;
  int divine_smite;

  bool divine_sense;
  bool lay_on_hands;
  bool divine_health;
  bool sacred_oath;
  bool aura_of_protection;
  bool aura_of_courage;
  bool cleansing_touch;
  bool aura_improvments;
  bool oath_of_devotion;
  bool oath_of_ancients;
  bool oath_of_vengeance;
  bool oathbreaker;
  bool oath_of_the_crown;

  paladin_attributes() {
    sacred_oath_feature = 0;
    divine_smite = 0;

    divine_sense = false;
    lay_on_hands = false;
    divine_health = false;
    sacred_oath = false;
    aura_of_protection = false;
    aura_of_courage = false;
    cleansing_touch = false;
    aura_improvments = false;
    oath_of_devotion = false;
    oath_of_ancients = false;
    oath_of_vengeance = false;
    oathbreaker = false;
    oath_of_the_crown = false;
  }
};

struct ranger_attributes {
  int favored_enemy;
  int natural_explorer;
  int ranger_archetype_feature;
  int ranger_spells_known;

  bool ranger_archetype;
  bool primeval_awareness;
  bool lands_stride;
  bool hide_in_plain_sight;
  bool vanish;
  bool feral_senses;
  bool foe_slayer;
  bool hunter;
  bool beast_master;
  bool favored_enemy_languages;

  ranger_attributes() {
    favored_enemy = 0;
    natural_explorer = 0;
    ranger_archetype_feature = 0;
    ranger_spells_known = 0;

    ranger_archetype = false;
    primeval_awareness = false;
    lands_stride = false;
    hide_in_plain_sight = false;
    vanish = false;
    feral_senses = false;
    foe_slayer = false;
    hunter = false;
    beast_master = false;
    favored_enemy_languages = false;
  }
};

struct rogue_attributes {
  int roguish_archetype_feature;
  int arcane_t_spells_known;

  bool sneak_attack;
  bool thieves_cant;
  bool cunning_action;
  bool roguish_archetype;
  bool uncanny_dodge;
  bool reliable_talent;
  bool blindsense;
  bool slippery_mind;
  bool elusive;
  bool stroke_of_luck;
  bool thief;
  bool assassin;
  bool arcane_trickster;
  bool mastermind;
  bool swashbuckler;

  rogue_attributes() {
    roguish_archetype_feature = 0;
    arcane_t_spells_known = 0;

    sneak_attack = false;
    thieves_cant = false;
    cunning_action = false;
    roguish_archetype = false;
    uncanny_dodge = false;
    reliable_talent = false;
    blindsense = false;
    slippery_mind = false;
    elusive = false;
    stroke_of_luck = false;
    thief = false;
    assassin = false;
    arcane_trickster = false;
    mastermind = false;
    swashbuckler = false;
  }
};

struct sorcerer_attributes {
  int sorcerous_origin_feature;
  int metamagic;
  int sorcery_points;
  int sorcerer_spells_known;
  int sorcerer_cantrips_known;

  bool sorcerous_origin;
  bool font_of_magic;
  bool sorcerous_restoration;
  bool draconic_bloodline;
  bool wild_magic;
  bool storm_sorcery;

  sorcerer_attributes() {
    sorcerous_origin_feature = 0;
    metamagic = 0;
    sorcery_points = 0;
    sorcerer_spells_known = 0;
    sorcerer_cantrips_known = 0;

    sorcerous_origin = false;
    font_of_magic = false;
    sorcerous_restoration = false;
    draconic_bloodline = false;
    wild_magic = false;
    storm_sorcery = false;
  }
};

struct warlock_attributes {
  int warlock_slot_level;
  int eldritch_invocations_known;
  int warlock_spells_known;
  int warlock_spell_slots;
  int warlock_cantrips_known;
  int otherworldly_patron_feature;
  int mystic_arcanum;

  bool otherworldly_patron;
  bool pact_magic;
  bool pact_boon;
  bool eldritch_master;
  bool archfey;
  bool fiend;
  bool great_old_one;
  bool the_undying;

  warlock_attributes() {
    warlock_slot_level = 0;
    eldritch_invocations_known = 0;
    warlock_spells_known = 0;
    warlock_spell_slots = 0;
    warlock_cantrips_known = 0;
    otherworldly_patron_feature = 0;
    mystic_arcanum = 0;

    otherworldly_patron = false;
    pact_magic = false;
    pact_boon = false;
    eldritch_master = false;
    archfey = false;
    fiend = false;
    great_old_one = false;
    the_undying = false;
  }
};

struct wizard_attributes {
  int arcane_tradition_feature;
  int wizard_cantrips_known;

  bool arcane_recovery;
  bool arcane_tradition;
  bool spell_mastery;
  bool signature_spell;
  bool abjuration;
  bool conjuration;
  bool divination;
  bool enchantment;
  bool evocation;
  bool illusion;
  bool necromancy;
  bool transmutation;
  bool bladesinging;

  wizard_attributes() {
    arcane_tradition_feature = 0;
    wizard_cantrips_known = 0;

    arcane_recovery = false;
    arcane_tradition = false;
    spell_mastery = false;
    signature_spell = false;
    abjuration = false;
    conjuration = false;
    divination = false;
    enchantment = false;
    evocation = false;
    illusion = false;
    necromancy = false;
    transmutation = false;
    bladesinging = false;
  }
};

class Generic_Character_Class
{
public:
  Generic_Character_Class();
  virtual ~Generic_Character_Class();

  virtual Generic_Character_Class *Clone() = 0;

  //CLASS //GENERAL (used by 2 or more classes)
  std::string char_name;
  std::string alignment;
  std::string char_class;
  std::string race;
  bool initialSkillsSet;
  bool spellcasting;
  bool timeless_body;
  bool evasion;
  bool unarmored_defense;
  bool fighting_style;
  bool defense;
  bool dueling;
  bool great_weapon_fighting;
  bool protection;
  int level;
  int hitdicesize;
  int move_speed;
  int proficiency_bonus;
  int extra_attack;
  int expertise;

  //LEVEL UP MENU TRACKERS
  int clericlevelupmenus;
  int fighterlevelupmenus;
  int roguelevelupmenus;
  int wizardlevelupmenus;
  int barbarianlevelupmenus;
  int druidlevelupmenus;
  int paladinlevelupmenus;
  int sorcererlevelupmenus;
  int bardlevelupmenus;
  int monklevelupmenus;
  int rangerlevelupmenus;
  int warlocklevelupmenus;

  //Specific class attributes
  cleric_attributes cleric_attr;
  fighter_attributes fighter_attr;
  barbarian_attributes barbarian_attr;
  bard_attributes bard_attr;
  druid_attributes druid_attr;
  monk_attributes monk_attr;
  paladin_attributes paladin_attr;
  ranger_attributes ranger_attr;
  rogue_attributes rogue_attr;
  sorcerer_attributes sorcerer_attr;
  warlock_attributes warlock_attr;
  wizard_attributes wizard_attr;
  

  //landtypes
  bool artic;
  bool coast;
  bool desert;
  bool forest;
  bool grassland;
  bool mountain;
  bool swamp;
  bool underdark;

  //creaturetype
  int twohumanoids;
  bool aberrations;
  bool beasts;
  bool celestials;
  bool constructs;
  bool dragons;
  bool elementals;
  bool fey;
  bool fiends;
  bool giants;
  bool monstrosities;
  bool oozes;
  bool plants;
  bool undead;

  //SPELLSLOTS
  int first_ss;
  int second_ss;
  int third_ss;
  int forth_ss;
  int fifth_ss;
  int sixth_ss;
  int seventh_ss;
  int eighth_ss;
  int ninth_ss;
  int warlock_ss;

  //BACKGROUNDS  1 nobackground 13 phb 12 scag
  enum characterbackground
  {
    NOBACKGROUND = 0,
    ACOLYTE,
    CHARLATAN,
    CITY_WATCH,
    CLAN_CRAFTER,
    CLOISTERED_SCHOLAR,
    COURTIER,
    CRIMINAL,
    ENTERTAINER,
    FACTION_AGENT,
    FAR_TRAVELER,
    FOLK_HERO,
    GUILD_ARTISAN,
    HERMIT,
    INHERITOR,
    KNIGHT_OF_THE_ORDER,
    MERCENARY_VETERAN,
    NOBLE,
    OUTLANDER,
    SAGE,
    SAILOR,
    SOLDIER,
    URBAN_BOUNTY_HUNTER,
    URCHIN,
    UTHGARDT_TRIBE_MEMBER,
    WATERDHAVIAN_NOBLE
  };
  characterbackground backgroundofpc;

  //ABILITY SCORES
  int strength;
  int dexterity;
  int constitution;
  int intelligence;
  int wisdom;
  int charisma;

  //SAVING THROWS
  bool strSave;
  bool dexSave;
  bool conSave;
  bool intSave;
  bool wisSave;
  bool chaSave;

  //SKILLS
  bool acrobatics;
  bool animal_handling;
  bool arcana;
  bool athletics;
  bool deception;
  bool history;
  bool insight;
  bool intimidation;
  bool investigation;
  bool medicine;
  bool nature;
  bool perception;
  bool performance;
  bool persuasion;
  bool religion;
  bool sleight_of_hand;
  bool stealth;
  bool survival;

  //FEATS
  bool alert;
  bool athlete;
  bool actor;
  bool charger;
  bool crossbow_expert;
  bool defensive_duelist;
  bool dual_wielder;
  bool dungeon_delver;
  bool durable;
  bool elemental_adept;
  bool grappler;
  bool great_weapon_master;
  bool healer;
  bool heavily_armored;
  bool heavy_armor_master;
  bool inspiring_leader;
  bool keen_mind;
  bool lightly_armored;
  bool linguist;
  bool lucky;
  bool mage_slayer;
  bool magic_initiate;
  bool martial_adept;
  bool medium_armor_master;
  bool mobile;
  bool moderately_armored;
  bool mounted_combatant;
  bool observant;
  bool polearm_master;
  bool resilient;
  bool ritual_caster;
  bool savage_attacker;
  bool sentinel;
  bool sharpshooter;
  bool shield_master;
  bool skilled;
  bool skulker;
  bool spell_sniper;
  bool tavern_brawler;
  bool tough;
  bool war_caster;
  bool weapon_master;

  //LANGUAGES
  bool abyssal;
  bool celestial;
  bool common;
  bool deep_speech;
  bool draconic;
  bool druidic;
  bool dwarvish;
  bool elvish;
  bool giant;
  bool gnomish;
  bool goblin;
  bool gnoll;
  bool halfling;
  bool infernal;
  bool orc;
  bool primordial;
  bool sylvan;
  bool undercommon;

  //FEATURES
  bool artificers_lore;
  bool brave;
  bool breath_weapon_acid;
  bool breath_weapon_ltg;
  bool breath_weapon_fire;
  bool breath_weapon_poison;
  bool breath_weapon_cold;
  bool darkvision;
  bool draconic_ancestry_black;
  bool draconic_ancestry_blue;
  bool draconic_ancestry_brass;
  bool draconic_ancestry_bronze;
  bool draconic_ancestry_copper;
  bool draconic_ancestry_gold;
  bool draconic_ancestry_green;
  bool draconic_ancestry_red;
  bool draconic_ancestry_silver;
  bool draconic_ancestry_white;
  bool drow_magic;
  bool drow_weapon_training;
  bool dwarven_armor_training;
  bool dwarven_combat_training;
  bool dwarven_resilience;
  bool dwarven_toughness;
  bool elf_weapon_training;
  bool fey_ancestry;
  bool fleet_of_foot;
  bool halflinglucky;
  bool halfling_nimbleness;
  bool hellish_resistance;
  bool infernal_legacy;
  bool mask_of_the_wild;
  bool natural_illusionist;
  bool naturally_stealthy;
  bool speak_with_small_beasts;
  bool stonecunning;
  bool stout_resilience;
  bool superior_darkvision;
  bool trance;

  //RESISTANCES
  bool damage_resist_acid;
  bool damage_resist_ltg;
  bool damage_resist_fire;
  bool damage_resist_poison;
  bool damage_resist_cold;

  //DISADVANATAGES
  bool sunlight_sensitivity;

  //ARTISAN TOOLS & SUPPLIES
  bool alchemist;
  bool brewer;
  bool calligrapher;
  bool carpenter;
  bool cartographer;
  bool cobbler;
  bool cook;
  bool glassblower;
  bool jeweler;
  bool leatherworker;
  bool mason;
  bool painter;
  bool potter;
  bool smith;
  bool tinker;
  bool weaver;
  bool woodcarver;

  //KITS & TOOLS
  bool disguise;
  bool forgery;
  bool herbalism;
  bool navigator;
  bool poisoner;
  bool thieves;
  bool vehicle;

  //MUSICAL INSTRUMENTS
  bool bagpipes;
  bool drum;
  bool dulcimer;
  bool flute;
  bool lute;
  bool lyre;
  bool horn;
  bool pan_flute;
  bool shawm;
  bool viol;

  //CHARACTER CREATION FUNCTIONS (MUTATORS)
  void setName();
  void suggestRandomName(std::string& );
  void setRace(Generic_Character_Class &v);
  void setRaceBonuses();
  void setAlignment();
  void setBackground();
  void setAllStats();
  void setStr(const int &);
  void setDex(const int &);
  void setCon(const int &);
  void setInt(const int &);
  void setWis(const int &);
  void setCha(const int &);
  void setLanguage(const std::string &);
  void setInstrument(const std::string &, const int &);
  void setTools(const int &);
  virtual void setInitialClassFeatures() = 0;
  virtual void setClassDetails(const int &l) = 0;
  void updateCharacter(const Campaign &);
  void updateName(const Campaign &);  //used in updateCharacter
  void updateLevel(const Campaign &);  //used in updateCharacter
  void setProficiencyBonus();
  void increase2statsby1();
  void increase1statby2();
  void setLandtype();
  void setFavoredEnemy();
  void levelUpStats();
  void assignStats(int &s);

  //skill gaining functions
  void setAnySkill(const std::string &, const int &);
  void gainAcrobatics(int &);
  void gainAnimal_Handling(int &);
  void gainArcana(int &);
  void gainAthletics(int &);
  void gainDeception(int &);
  void gainHistory(int &);
  void gainInsight(int &);
  void gainIntimidation(int &);
  void gainInvestigation(int &);
  void gainMedicine(int &);
  void gainNature(int &);
  void gainPerception(int &);
  void gainPerformance(int &);
  void gainPersuasion(int &);
  void gainReligion(int &);
  void gainSleight_of_Hand(int &);
  void gainStealth(int &);
  void gainSurvival(int &);
  void knownskill(int &);

  //feat gaining functions
  void setAnyFeat();
  void gainAlert(bool &s);
  void gainAthlete(bool &s);
  void gainActor(bool &s);
  void gainCharger(bool &s);
  void gainCrossbow_expert(bool &s);
  void gainDefensive_duelist(bool &s);
  void gainDual_wielder(bool &s);
  void gainDungeon_delver(bool &s);
  void gainDurable(bool &s);
  void gainElemental_adept(bool &s);
  void gainGrappler(bool &s);
  void gainGreat_weapon_master(bool &s);
  void gainHealer(bool &s);
  void gainHeavily_armored(bool &s);
  void gainHeavy_armor_master(bool &s);
  void gainInspiring_leader(bool &s);
  void gainKeen_mind(bool &s);
  void gainLightly_armored(bool &s);
  void gainLinguist(bool &s);
  void gainLucky(bool &s);
  void gainMage_slayer(bool &s);
  void gainMagic_initiate(bool &s);
  void gainMartial_adept(bool &s);
  void gainMedium_armor_master(bool &s);
  void gainMobile(bool &s);
  void gainModerately_armored(bool &s);
  void gainMounted_combatant(bool &s);
  void gainObservant(bool &s);
  void gainPolearm_master(bool &s);
  void gainResilient(bool &s);
  void gainRitual_caster(bool &s);
  void gainSavage_attaker(bool &s);
  void gainSentinel(bool &s);
  void gainSharpshooter(bool &s);
  void gainShield_master(bool &s);
  void gainSkilled(bool &s);
  void gainSkulker(bool &s);
  void gainSpell_sniper(bool &s);
  void gainTavern_brawler(bool &s);
  void gainTough(bool &s);
  void gainWar_caster(bool &s);
  void gainWeapon_master(bool &s);

  //CHARACTER DISPLAYING FUNCTIONS (ACCESSORS)
  std::string getBackground() const;
  void character_sheet() const;
  void printClassAbilities() const;
  void printSpellSlots() const;
  void printSkills() const;
  void printFeats() const;
  void printOtherAbilities() const;
  void printLangs() const;
  void printToolsInstruments() const;
  void printResistances() const;
  void printDisadvantages() const;
  void creaturetype() const;
  void landtype() const;
  virtual int getlevelupmenus() const = 0;
  std::string getRace() const;
};

//Define a macro for Clone definitions
#define CLONE_CREATE(Type) virtual Generic_Character_Class *Clone() \
                                   {                                \
                                     return new Type;               \
                                   }

//Define a macro to create the classes
#define CREATE_CLASS(Type, Name, LevelUpMenu) class Type : public Generic_Character_Class \
                                 {                                             \
                                   CLONE_CREATE(Type);                         \
                                   virtual void setInitialClassFeatures()      \
                                   {                                           \
                                       char_class = #Name;                     \
                                   }                                           \
                                                                               \
                                   virtual int getlevelupmenus() const         \
                                   {                                           \
                                       return LevelUpMenu;                     \
                                   }                                           \
                                                                               \
                                   virtual void setClassDetails(const int& l); \
                                 };


CREATE_CLASS(Cleric, Cleric, clericlevelupmenus);
CREATE_CLASS(Fighter, Fighter, fighterlevelupmenus);
CREATE_CLASS(Rogue, Rogue, roguelevelupmenus);
CREATE_CLASS(Wizard, Wizard, wizardlevelupmenus);
CREATE_CLASS(Barbarian, Barbarian, barbarianlevelupmenus);
CREATE_CLASS(Druid, Druid, druidlevelupmenus);
CREATE_CLASS(Paladin, Paladin, paladinlevelupmenus);
CREATE_CLASS(Sorcerer, Sorcerer, sorcererlevelupmenus);
CREATE_CLASS(Bard, Bard, bardlevelupmenus);
CREATE_CLASS(Monk, Monk, monklevelupmenus);
CREATE_CLASS(Ranger, Ranger, rangerlevelupmenus);
CREATE_CLASS(Warlock, Warlock, warlocklevelupmenus);

class ClassClonner {
public:
    static ClassClonner& GetClassClonner() {
      static ClassClonner instance;
      return instance;
    }

    ~ClassClonner() { }

    Generic_Character_Class *GetNewClass(unsigned int index) {
        return ClassTable[index - 1]->Clone();
    }

    void CleanResources() {
        for(unsigned int i = 0; i < sizeof(ClassTable) / sizeof(ClassTable[0]); i++) {
            delete ClassTable[i];
        }
    }

    void operator=(ClassClonner const&) = delete;
    ClassClonner(ClassClonner const&) = delete;
private:
    ClassClonner() {
        ClassTable[0] = new Cleric;
        ClassTable[1] = new Fighter;
        ClassTable[2] = new Rogue;
        ClassTable[3] = new Wizard;
        ClassTable[4] = new Barbarian;
        ClassTable[5] = new Druid;
        ClassTable[6] = new Paladin;
        ClassTable[7] = new Sorcerer;
        ClassTable[8] = new Bard;
        ClassTable[9] = new Monk;
        ClassTable[10] = new Ranger;
        ClassTable[11] = new Warlock;
    }

    Generic_Character_Class *ClassTable[12];
};

#endif
