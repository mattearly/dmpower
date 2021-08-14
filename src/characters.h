#pragma once

#include "races.h"
#include "globalfuncts.h"
#include "campaign.h"

class Campaign;

class Generic_Character_Class
{
public:
  Generic_Character_Class();
  virtual ~Generic_Character_Class();

  //Clone the monster, used for generate monsters with a table to monster, think like a spawner
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
  int fly_speed;
  int swim_speed;
  int climb_speed;
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

  //CLERIC
  float destroy_undead;
  int channel_divinity;
  int divine_domain_feature;
  int divine_intervention;
  int cleric_cantrips_known;
  bool divine_domain, arcana_d, death_d, knowledge_d, life_d, light_d, nature_d,
      tempest_d, trickery_d, war_d;

  //FIGHTER
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

  //BARBARIAN
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

  //BARD
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

  //DRUID
  float wild_shape_improvement;
  int druid_circle_feature;
  int druid_cantrips_known;
  bool wild_shape;
  bool druid_circle;
  bool beast_spells;
  bool archdruid;
  bool circle_of_the_moon;
  bool circle_of_the_land;

  //MONK
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

  //PALADIN
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

  //RANGER
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

  //ROGUE
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

  //SORCERER
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

  //WARLOCK
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

  //WIZARD
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
    WATERDHAVIAN_NOBLE,
    CUSTOM
  };
  characterbackground backgroundofpc;
  std::string custom_background_name;

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
  bool svirfneblin_magic;

  //LANGUAGES
  bool aarakocra;
  bool abyssal;
  bool aquan;
  bool auran;
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
  bool devils_tongue; //tiefling variant
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
  bool duergar_magic;      // duergar dwarf
  bool duergar_resilience; // duergar dwarf
  bool elf_weapon_training;
  bool expert_forgery; // kenku
  bool fey_ancestry;
  bool firbolg_magic; //firbolg
  bool fleet_of_foot;
  bool halflinglucky;
  bool halfling_nimbleness;
  bool healing_hands; // aasimar
  bool hellfire;      //tiefling variant
  bool hellish_resistance;
  bool hidden_step; //firbolg
  bool infernal_legacy;
  bool light_bearer; //assimar
  bool mask_of_the_wild;
  bool mimicry; // kenku
  bool natural_illusionist;
  bool naturally_stealthy;
  bool necrotic_shroud;     //assimar
  bool powerful_build;      //firbolg
  bool radiant_consumption; //assimar
  bool radiant_soul;        //assimar
  bool silent_speech;       //ghostwise halfing
  bool speak_with_small_beasts;
  bool speech_of_beast_and_leaf; //firbolg
  bool stonecunning;
  bool stone_camouflage; //svirfneblin gnome
  bool stones_endurance; //goliath
  bool stout_resilience;
  bool superior_darkvision;
  bool trance;
  // lizardfolk
  bool lizardfolk_bite;
  bool cunning_artisan;
  int hold_breath; //and tortle
  int natural_armor;
  bool hungry_jaws;
  // tabaxi
  bool feline_agility;
  bool cats_claws;
  // triton
  bool amphibious;
  bool control_air_and_water;
  bool emissary_of_the_sea;
  bool guardian_of_the_depths;
  // warforged
  bool composite_plating;
  bool living_construct;
  //changeling
  bool shapechanger;
  //shifter
  bool shifting;
  //tortle
  bool shell;
  bool retreat_to_shell;
  bool turtle_snapper;
  bool razorback;
  bool razor_fist;
  bool softshell;
  bool nomad;
  bool shell_master;
  //aarakocra
  bool talons;
  //genasi
  bool unending_breath;
  bool mingle_with_the_wind;
  bool earth_walk;
  bool merge_with_stone;
  bool reach_to_the_blaze;
  bool call_to_the_wave;

  //RESISTANCES
  bool damage_resist_acid;
  bool damage_resist_ltg;
  bool damage_resist_fire;
  bool damage_resist_poison;
  bool damage_resist_cold;
  bool damage_resist_radiant;
  bool damage_resist_necrotic;

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
  void suggestRandomName(std::string &);
  void giveRandomName(std::string &);
  void setRace(Generic_Character_Class &v);
  void setAlignment();
  void setBackground();
  void setAllStats();
  void setAllStatsAtOnce(const int &, const int &, const int &, const int &, const int &, const int &);
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
  void updateName(const Campaign &);
  void updateLevel();
  void setProficiencyBonus();
  void increase2statsby1();
  void increase1statby2();
  void setLandtype();
  void setFavoredEnemy();
  void levelUpStats();
  void assignStats(int &s);
  void wipeStats();

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
  void gainSvirfneblin_magic(bool &s);

  //CHARACTER DISPLAYING FUNCTIONS (ACCESSORS)
  std::string getBackground() const;
  void character_sheet() const;
  void printClassAbilities() const;
  void printCantrips() const;
  void printSpellSlots() const;
  void printSkills() const;
  void printFeats() const;
  void printOtherAbilities() const;
  void printLangs() const;
  void printToolsInstruments() const;
  void printResistances() const;
  void printDisadvantages() const;
  void creaturetype(std::ostream& stream) const;
  void landtype(std::ostream& stream) const;
  virtual int getlevelupmenus() const = 0;
  std::string getRace() const;

  void exportPrint(const std::string &title) const;
};

//Macro for Clone definitions
#define CLONE_CREATE(Type)                 \
  virtual Generic_Character_Class *Clone() \
  {                                        \
    return new Type;                       \
  }

//Macro to create the classes
#define CREATE_CLASS(Type, Name, LevelUpMenu)   \
  class Type : public Generic_Character_Class   \
  {                                             \
    CLONE_CREATE(Type);                         \
    virtual void setInitialClassFeatures()      \
    {                                           \
      char_class = #Name;                       \
    }                                           \
    virtual int getlevelupmenus() const         \
    {                                           \
      return LevelUpMenu;                       \
    }                                           \
    virtual void setClassDetails(const int &l); \
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
