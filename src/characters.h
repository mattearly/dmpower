/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2016 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/


#ifndef dm_power_poly_characters_h
#define dm_power_poly_characters_h
#include "races.h"
#include "globalfuncts.h"
#include "campaign.h"

class Campaign;

class Generic_Character_Class {
public:
    Generic_Character_Class();
    ~Generic_Character_Class();
    //CLASS //GENERAL (used by 2 or more classes)
    std::string name, alignment, char_class, race;
    bool initialSkillsSet, spellcasting, timeless_body, evasion,
    unarmored_defense, fighting_style, defense, dueling,
    great_weapon_fighting, protection;
    int level, hitdicesize, move_speed, proficiency_bonus,
    extra_attack, expertise;
    //LEVEL UP MENU TRACKERS
    int clericlevelupmenus, fighterlevelupmenus, roguelevelupmenus, wizardlevelupmenus,\
    barbarianlevelupmenus, druidlevelupmenus, paladinlevelupmenus, sorcererlevelupmenus,\
    bardlevelupmenus, monklevelupmenus, rangerlevelupmenus, warlocklevelupmenus;
    //CLERIC
    float destroy_undead;
    int channel_divinity, divine_domain_feature, divine_intervention,
    cleric_cantrips_known;
    bool divine_domain, arcana_d, death_d, knowledge_d, life_d, light_d, nature_d,
    tempest_d, trickery_d, war_d;
    //FIGHTER
    int action_surge, martial_archtype_feature, indomitable,
    eldritch_spells_known;
    bool second_wind, martial_archtype, archery, two_weapon_fighting,
    champion, battle_master, eldritch_knight, purple_dragon_knight;
    //BARBARIAN
    int rages, rage_damage, path_feature, brutal_critical;
    bool reckless_attack, danger_sense, primal_path, fast_movement,
    feral_instinct, relentless_rage, persistant_rage,
    indomitable_might, primal_champion, path_of_the_battlerager, path_of_the_berseker,
    path_of_the_totem_warrior, bear_totem, eagle_totem, wolf_totem;
    //BARD
    int bardic_inspiration, song_of_rest, bard_college_feature,
    magical_secrets, bard_spells_known, bard_cantrips_known;
    bool jack_of_all_trades, bard_college, font_of_inspiration,
    countercharm, superior_inspiration, college_of_lore,
    college_of_valor, additional_magical_secrets;
    //DRUID
    float wild_shape_improvement;
    int druid_circle_feature, druid_cantrips_known;
    bool druidic, wild_shape, druid_circle, beast_spells, archdruid,
    circle_of_the_moon, circle_of_the_land;
    //MONK
    int monastic_tradition_feature, ki, unarmored_movement, martial_arts;
    bool monastic_tradition, deflect_missles, slow_fall,
    stunning_strike, ki_empowered_strikes, stillness_of_mind,
    purity_of_body, tongue_of_the_sun_and_moon, diamond_soul,
    empty_body, perfect_self, way_of_the_open_hand,
    way_of_the_four_elements, way_of_the_long_death, way_of_the_shadow,
    way_of_the_sun_soul, unarmored_movement_improvement;
    //PALADIN
    int sacred_oath_feature, divine_smite;
    bool divine_sense, lay_on_hands, divine_health, sacred_oath,
    aura_of_protection, aura_of_courage, cleansing_touch,
    aura_improvments, oath_of_devotion, oath_of_ancients,
    oath_of_vengeance, oathbreaker, oath_of_the_crown;
    //RANGER
    int favored_enemy, natural_explorer, ranger_archetype_feature,
    ranger_spells_known;
    bool ranger_archetype, primeval_awareness, lands_stride,
    hide_in_plain_sight, vanish, feral_senses, foe_slayer,
    hunter, beast_master, favored_enemy_languages;
    //ROGUE
    int roguish_archetype_feature, arcane_t_spells_known;
    bool sneak_attack, thieves_cant, cunning_action, roguish_archetype,
    uncanny_dodge, reliable_talent, blindsense, slippery_mind,
    elusive, stroke_of_luck, thief, assassin, arcane_trickster, mastermind, swashbuckler;
    //SORCERER
    int sorcerous_origin_feature, metamagic, sorcery_points, sorcerer_spells_known, sorcerer_cantrips_known;
    bool sorcerous_origin, font_of_magic, sorcerous_restoration,
    draconic_bloodline, wild_magic, storm_sorcery;
    //WARLOCK
    int warlock_slot_level, eldritch_invocations_known, warlock_spells_known, warlock_spell_slots, warlock_cantrips_known, otherworldly_patron_feature, mystic_arcanum;
    bool otherworldly_patron, pact_magic, pact_boon, eldritch_master,
    archfey, fiend, great_old_one, the_undying;
    //WIZARD
    int arcane_tradition_feature, wizard_cantrips_known;
    bool arcane_recovery, arcane_tradition, spell_mastery,
    signature_spell, abjuration, conjuration, divination,
    enchantment, evocation, illusion, necromancy, transmutation, bladesinging;
    //landtypes
    bool artic, coast, desert, forest, grassland, mountain, swamp, underdark;
    //creaturetype
    int twohumanoids;
    bool aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, undead;
    //SPELLSLOTS
    int first_ss, second_ss, third_ss, forth_ss, fifth_ss, sixth_ss, seventh_ss, eighth_ss, ninth_ss, warlock_ss;
    //BACKGROUNDS  1 nobackground 13 phb 12 scag
    enum characterbackground { NOBACKGROUND, ACOLYTE, CHARLATAN, CITY_WATCH, CLAN_CRAFTER, CLOISTERED_SCHOLAR, COURTIER, CRIMINAL, \
                               ENTERTAINER, FACTION_AGENT, FAR_TRAVELER, FOLK_HERO, GUILD_ARTISAN, HERMIT, INHERITOR, KNIGHT_OF_THE_ORDER, MERCENARY_VETERAN, NOBLE, OUTLANDER, SAGE, \
                               SAILOR, SOLDIER, URBAN_BOUNTY_HUNTER, URCHIN, UTHGARDT_TRIBE_MEMBER, WATERDHAVIAN_NOBLE };
    characterbackground backgroundofpc;
    //ABILITY SCORES
    int strength, dexterity, constitution, intelligence, wisdom, charisma;
    //SAVING THROWS
    bool strSave, dexSave, conSave, intSave, wisSave, chaSave;
    //SKILLS
    bool acrobatics, animal_handling, arcana, athletics, deception, history, insight, intimidation, investigation, medicine, nature, perception, performance, persuasion, religion, sleight_of_hand, stealth, survival;
    //FEATS
    bool alert, athlete, actor, charger, crossbow_expert, defensive_duelist, dual_wielder, dungeon_delver, durable, elemental_adept, grappler, great_weapon_master, healer, heavily_armored, heavy_armor_master, inspiring_leader, keen_mind, lightly_armored, linguist, lucky, mage_slayer, magic_initiate, martial_adept, medium_armor_master, mobile, moderately_armored, mounted_combatant, observant, polearm_master, resilient, ritual_caster, savage_attacker, sentinel, sharpshooter, shield_master, skilled, skulker, spell_sniper, tavern_brawler, tough, war_caster, weapon_master;
    //LANGUAGES
    bool abyssal, celestial, common, deep_speech, draconic, dwarvish, elvish, giant, gnomish, goblin, gnoll, halfling, infernal, orc, primordial, sylvan, undercommon;
    //FEATURES
    bool artificers_lore, brave, breath_weapon_acid, breath_weapon_ltg, breath_weapon_fire, breath_weapon_poison, breath_weapon_cold, darkvision, draconic_ancestry_black, draconic_ancestry_blue, draconic_ancestry_brass, draconic_ancestry_bronze, draconic_ancestry_copper, draconic_ancestry_gold, draconic_ancestry_green,draconic_ancestry_red, draconic_ancestry_silver, draconic_ancestry_white, drow_magic, drow_weapon_training, dwarven_armor_training, dwarven_combat_training, dwarven_resilience, dwarven_toughness, elf_weapon_training, fey_ancestry, fleet_of_foot, halflinglucky, halfling_nimbleness, hellish_resistance, infernal_legacy, mask_of_the_wild, natural_illusionist, naturally_stealthy, speak_with_small_beasts, stonecunning, stout_resilience, superior_darkvision, trance;
    //RESISTANCES
    bool damage_resist_acid, damage_resist_ltg, damage_resist_fire, damage_resist_poison, damage_resist_cold;
    //DISADVANATAGES
    bool sunlight_sensitivity;
    //ARTISAN TOOLS & SUPPLIES
    bool alchemist, brewer, calligrapher, carpenter, cartographer, cobbler, cook, glassblower, jeweler, leatherworker, mason, painter, potter, smith, tinker, weaver, woodcarver;
    //KITS & TOOLS
    bool disguise, forgery, herbalism, navigator, poisoner, thieves, vehicle;
    //MUSICAL INSTRUMENTS
    bool bagpipes, drum, dulcimer, flute, lute, lyre, horn, pan_flute, shawm, viol;
    //sword coast book adds more to do


    //CHARACTER CREATION FUNCTIONS (MUTATORS)
    void setName();
    void setRace(Generic_Character_Class &v);
    void setRaceBonuses();
    void setAlignment();
    void setBackground();
    void setAllStats();
    void setStr(const int&);
    void setDex(const int&);
    void setCon(const int&);
    void setInt(const int&);
    void setWis(const int&);
    void setCha(const int&);
    void setLanguage(const std::string&);
    void setInstrument(const std::string&, const int&);
    void setTools(const int&);
    virtual void setClassDetails(const int& l) = 0;
    void updateCharacter(const Campaign&);
    void setProficiencyBonus();
    void increase2statsby1();
    void increase1statby2();
    void setLandtype();
    void setFavoredEnemy();
    void levelUpStats();
    void assignStats(int &s);

    //skill gaining functions
    void setAnySkill(const std::string&, const int&);
    void gainAcrobatics(int&);
    void gainAnimal_Handling(int&);
    void gainArcana(int&);
    void gainAthletics(int&);
    void gainDeception(int&);
    void gainHistory(int&);
    void gainInsight(int&);
    void gainIntimidation(int&);
    void gainInvestigation(int&);
    void gainMedicine(int&);
    void gainNature(int&);
    void gainPerception(int&);
    void gainPerformance(int&);
    void gainPersuasion(int&);
    void gainReligion(int&);
    void gainSleight_of_Hand(int&);
    void gainStealth(int&);
    void gainSurvival(int&);
    void knownskill(int&);




    //feat gaining functions
    void setAnyFeat();
    void gainAlert(bool& s);
    void gainAthlete(bool& s);
    void gainActor(bool& s);
    void gainCharger(bool& s);
    void gainCrossbow_expert(bool& s);
    void gainDefensive_duelist(bool& s);
    void gainDual_wielder(bool& s);
    void gainDungeon_delver(bool& s);
    void gainDurable(bool& s);
    void gainElemental_adept(bool& s);
    void gainGrappler(bool& s);
    void gainGreat_weapon_master(bool& s);
    void gainHealer(bool& s);
    void gainHeavily_armored(bool& s);
    void gainHeavy_armor_master(bool& s);
    void gainInspiring_leader(bool& s);
    void gainKeen_mind(bool& s);
    void gainLightly_armored(bool& s);
    void gainLinguist(bool& s);
    void gainLucky(bool& s);
    void gainMage_slayer(bool& s);
    void gainMagic_initiate(bool& s);
    void gainMartial_adept(bool& s);
    void gainMedium_armor_master(bool& s);
    void gainMobile(bool& s);
    void gainModerately_armored(bool& s);
    void gainMounted_combatant(bool& s);
    void gainObservant(bool& s);
    void gainPolearm_master(bool& s);
    void gainResilient(bool& s);
    void gainRitual_caster(bool& s);
    void gainSavage_attaker(bool& s);
    void gainSentinel(bool& s);
    void gainSharpshooter(bool& s);
    void gainShield_master(bool& s);
    void gainSkilled(bool& s);
    void gainSkulker(bool& s);
    void gainSpell_sniper(bool& s);
    void gainTavern_brawler(bool& s);
    void gainTough(bool& s);
    void gainWar_caster(bool& s);
    void gainWeapon_master(bool& s);




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

};

class Cleric : public Generic_Character_Class {
public:
    Cleric() {};
    virtual int getlevelupmenus() const {
        return clericlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Fighter : public Generic_Character_Class {
public:
    Fighter() {};
    virtual int getlevelupmenus() const {
        return fighterlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Rogue : public Generic_Character_Class {
public:
    Rogue() {};
    virtual int getlevelupmenus() const {
        return roguelevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Wizard : public Generic_Character_Class {
public:
    Wizard() {};
    virtual int getlevelupmenus() const {
        return wizardlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Barbarian : public Generic_Character_Class {
public:
    Barbarian() {};
    virtual int getlevelupmenus() const {
        return barbarianlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Druid : public Generic_Character_Class {
public:
    Druid() {};
    virtual int getlevelupmenus() const {
        return druidlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Paladin : public Generic_Character_Class {
public:
    Paladin() {};
    virtual int getlevelupmenus() const {
        return paladinlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Sorcerer : public Generic_Character_Class {
public:
    Sorcerer() {};
    virtual int getlevelupmenus() const {
        return sorcererlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Bard : public Generic_Character_Class {
public:
    Bard() {};
    virtual int getlevelupmenus() const {
        return bardlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Monk : public Generic_Character_Class {
public:
    Monk() {};
    virtual int getlevelupmenus() const {
        return monklevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Ranger : public Generic_Character_Class {
public:
    Ranger() {};
    virtual int getlevelupmenus() const {
        return rangerlevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

class Warlock : public Generic_Character_Class {
public:
    Warlock() {};
    virtual int getlevelupmenus() const {
        return warlocklevelupmenus;
    };

    virtual void setClassDetails(const int& l);
};

#endif
