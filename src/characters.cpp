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


#include <iomanip>
#include "characters.h"
#include <cmath>
using namespace std;

//mutators
Generic_Character_Class::Generic_Character_Class()
{
    name = "";
    alignment = "";
    char_class = "";
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
    destroy_undead = 0;
    wild_shape_improvement = 0;
}
void Cleric::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Cleric Details.\n\n";
    char_class = "Cleric";
    level = l;
    hitdicesize = 8;
    wisSave = 1;
    chaSave = 1;
    spellcasting = true;
    if (!divine_domain)
    {
	cout << "Choose a Divine Domain:\n\n"
	     << " 1. Arcane\n 2. Death\n 3. Knowledge\n 4. Life\n 5. Light\n"
	     << " 6. Nature\n 7. Tempest\n 8. Trickery\n 9. War\n\n";
	int ss = getNumber("Divine Domain Choice(1-8): ", 1, 9);
	switch (ss)
	{
	case 1:
	    arcana_d = true;
	    arcana = true; //gain arcana skill
	    break;
	case 2:
	    death_d = true;
	    //gain martial weapon prof
	    break;
	case 3:
	    knowledge_d = true;
	    setLanguage("First Knowledge Domain Language.\n\n");
	    setLanguage("Second Knowledge Domain Language.\n\n");
	    //gain double prof skills from arcana, history, nature, religion
	    break;
	case 4:
	    life_d = true;
	    break;
	case 5:
	    light_d = true;
	    break;
	case 6:
	    nature_d = true;
	    break;
	case 7:
	    tempest_d = true;
	    break;
	case 8:
	    trickery_d = true;
	    break;
	case 9:
	    war_d = true;
	    break;
	}
	divine_domain = true;
    }
    if (divine_domain_feature == 0 && l >= 2)
	divine_domain_feature++;
    if (channel_divinity == 0 && l >= 2)
	channel_divinity++;
    if (clericlevelupmenus == 0 && l >= 4)
    {
	simpleClearScreen();
	cout << "Ability Score Increase Menu for Level 4 Cleric.\n\n";
	levelUpStats();
	clericlevelupmenus++;
    }
    if (destroy_undead == 0 && l >= 5)
	destroy_undead += .5;
    if (channel_divinity == 1 && l >= 6)
	channel_divinity++;
    if (divine_domain_feature == 1 && l >= 6)
	divine_domain_feature++;
    if (destroy_undead == .5 && l >= 8)
	destroy_undead += .5;
    if (clericlevelupmenus == 1 && l >= 8)
    {
	simpleClearScreen();
	cout << "Ability Score Increase Menu for Level 8 Cleric.\n\n";
	levelUpStats();
	clericlevelupmenus++;
    }
    if (divine_domain_feature == 2 && l >= 8)
	divine_domain_feature++;
    if (divine_intervention == 0 && l >= 10)
	divine_intervention++;
    if (destroy_undead == 1 && l >= 11)
	destroy_undead++;
    if (clericlevelupmenus == 2 && l >= 12)
    {
	simpleClearScreen();
	cout << "Ability Score Increase Menu for Level 12 Cleric.\n\n";
	levelUpStats();
	clericlevelupmenus++;
    }
    if (destroy_undead == 2 && l >= 14)
	destroy_undead++;
    if (clericlevelupmenus == 3 && l >= 16)
    {
	simpleClearScreen();
	cout << "Ability Score Increase Menu for Level 16 Cleric.\n\n";
	levelUpStats();
	clericlevelupmenus++;
    }
    if (destroy_undead == 3 && l >= 17)
	destroy_undead++;
    if (divine_domain_feature == 3 && l >= 17)
	divine_domain_feature++;
    if (channel_divinity == 2 && l >= 18)
	channel_divinity++;
    if (clericlevelupmenus == 4 && l >= 19)
    {
	simpleClearScreen();
	cout << "Ability Score Increase Menu for Level 19 Cleric.\n\n";
	levelUpStats();
	clericlevelupmenus++;
    }
    if (divine_intervention == 1 && l >= 20)
	divine_intervention++;
    //cleric spells
    if (l >= 1 && l <= 3)
    {
	cleric_cantrips_known = 3;
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
	cleric_cantrips_known = 4;
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
	cleric_cantrips_known = 5;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Fighter::setClassDetails(const int &l)
{
    simpleClearScreen();
    char_class = "Fighter";
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
	    archery = true;
	if (ss == 2)
	    defense = true;
	if (ss == 3)
	    dueling = true;
	if (ss == 4)
	    great_weapon_fighting = true;
	if (ss == 5)
	    protection = true;
	if (ss == 6)
	    two_weapon_fighting = true;
	fighting_style = true;
    }
    if (!second_wind)
	second_wind = true;
    if (action_surge == 0 && l >= 2)
	action_surge++;
    if (!martial_archtype && l >= 3)
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
	    champion = true;
	    break;
	case 2:
	{
	    battle_master = true;
	    setTools(1);
	}
	break;
	case 3:
	    eldritch_knight = true;
	    spellcasting = true;
	    break;
	case 4:
	    purple_dragon_knight = true;
	    break;
	default:
	    cout << "Error setting fighter archetype.\n\n";
	    break;
	}
	martial_archtype = true;
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
    if (martial_archtype_feature == 0 && l >= 7)
	martial_archtype_feature++;
    if (fighterlevelupmenus == 2 && l >= 8)
    {
	cout << "Fighter level 8 Level Up Menu: \n\n";
	levelUpStats();
	fighterlevelupmenus++;
    }
    if (indomitable == 0 && l >= 9)
	indomitable++;
    if (martial_archtype_feature == 1 && l >= 10)
	martial_archtype_feature++;
    if (extra_attack == 1 && l >= 11)
	extra_attack++;
    if (fighterlevelupmenus == 3 && l >= 12)
    {
	cout << "Fighter level 12 Level Up Menu: \n\n";
	levelUpStats();
	fighterlevelupmenus++;
    }
    if (indomitable == 1 && l >= 13)
	indomitable++;
    if (fighterlevelupmenus == 4 && l >= 14)
    {
	cout << "Fighter level 14 Level Up Menu: \n\n";
	levelUpStats();
	fighterlevelupmenus++;
    }
    if (martial_archtype_feature == 2 && l >= 15)
	martial_archtype_feature++;
    if (fighterlevelupmenus == 5 && l >= 16)
    {
	cout << "Fighter level 16 Level Up Menu: \n\n";
	levelUpStats();
	fighterlevelupmenus++;
    }
    if (action_surge == 1 && l >= 17)
	action_surge++;
    if (indomitable == 2 && l >= 17)
	indomitable++;
    if (martial_archtype_feature == 3 && l >= 18)
	martial_archtype_feature++;
    if (fighterlevelupmenus == 6 && l >= 19)
    {
	cout << "Fighter level 19 Level Up Menu: \n\n";
	levelUpStats();
	fighterlevelupmenus++;
    }
    if (extra_attack == 2 && l >= 20)
	extra_attack++;
    //spells
    if (eldritch_knight)
    {
	if (l >= 3 && l <= 9)
	{
	    first_ss = 2;
	    wizard_cantrips_known = 2;
	    eldritch_spells_known = 3;
	    if (l >= 4)
		first_ss++;
	    if (l >= 7)
		first_ss++;
	    if (l >= 7)
		second_ss = 2;
	    if (l >= 4)
		eldritch_spells_known++;
	    if (l >= 7)
		eldritch_spells_known++;
	    if (l >= 8)
		eldritch_spells_known++;
	}
	else if (l >= 10 && l <= 20)
	{
	    first_ss = 4;
	    second_ss = 3;
	    wizard_cantrips_known = 3;
	    eldritch_spells_known = 7;
	    if (l >= 13)
		third_ss = 2;
	    if (l >= 16)
		third_ss++;
	    if (l >= 19)
		forth_ss = 1;
	    if (l >= 11)
		eldritch_spells_known++;
	    if (l >= 13)
		eldritch_spells_known++;
	    if (l >= 14)
		eldritch_spells_known++;
	    if (l >= 16)
		eldritch_spells_known++;
	    if (l >= 19)
		eldritch_spells_known++;
	    if (l >= 20)
		eldritch_spells_known++;
	}
    }
    if (!initialSkillsSet)
    {
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Rogue::setClassDetails(const int &l)
{
    char_class = "Rogue";
    level = l;
    hitdicesize = 8;
    dexSave = 1;
    intSave = 1;
    if (expertise == 0)
	expertise++;
    if (!sneak_attack)
	sneak_attack = true;
    if (!thieves_cant)
	thieves_cant = true;
    if (!cunning_action && l >= 2)
	cunning_action = true;
    if (!roguish_archetype && l >= 3)
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
	    thief = true;
	    break;
	case 2:
	    assassin = true;
	    cout << "Assassin: gained proficiency with Disguise & Poisoner kit.\n\n";
	    disguise = true;
	    poisoner = true;
	    break;
	case 3:
	    arcane_trickster = true;
	    spellcasting = true;
	    break;
	case 4:
	    mastermind = true;
	    setLanguage("First bonus Rogue::Mastermind Language:\n\n");
	    setLanguage("Second bonus Rogue::Mastermind Language:\n\n");
	    cout << "Mastermind: gained proficiency with Disquise & Forgery Kit\n\n";
	    disguise = true;
	    forgery = true;
	    //gain gaming set
	    break;
	case 5:
	    swashbuckler = true;
	    break;
	default:;
	}
	roguish_archetype = true;
    }
    if (!uncanny_dodge && l >= 5)
	uncanny_dodge = true;
    if (expertise == 1 && l >= 6)
	expertise++;
    if (!evasion && l >= 7)
	evasion = true;
    if (roguish_archetype_feature == 0 && l >= 9)
	roguish_archetype_feature++;
    if (!reliable_talent && l >= 11)
	reliable_talent = true;
    if (roguish_archetype_feature == 1 && l >= 13)
	roguish_archetype_feature++;
    if (!blindsense && l >= 14)
	blindsense = true;
    if (!slippery_mind && l >= 15)
	slippery_mind = true;
    if (!roguish_archetype_feature && l >= 17)
	roguish_archetype_feature++;
    if (!elusive && l >= 18)
	elusive = true;
    if (!stroke_of_luck && l == 20)
	stroke_of_luck = true;
    if (arcane_trickster)
    {
	if (l >= 3 && l <= 9)
	{
	    first_ss = 2;
	    wizard_cantrips_known = 2;
	    if (l >= 4)
		first_ss++;
	    if (l >= 7)
		first_ss++;
	    if (l >= 7)
		second_ss = 2;
	    if (l >= 4)
		arcane_t_spells_known++;
	    if (l >= 7)
		arcane_t_spells_known++;
	    if (l >= 8)
		arcane_t_spells_known++;
	}
	else if (l >= 10 && l <= 20)
	{
	    first_ss = 4;
	    second_ss = 3;
	    wizard_cantrips_known = 3;
	    eldritch_spells_known = 7;
	    if (l >= 13)
		third_ss = 2;
	    if (l >= 16)
		third_ss++;
	    if (l >= 19)
		forth_ss = 1;
	    if (l >= 11)
		arcane_t_spells_known++;
	    if (l >= 13)
		arcane_t_spells_known++;
	    if (l >= 14)
		arcane_t_spells_known++;
	    if (l >= 16)
		arcane_t_spells_known++;
	    if (l >= 19)
		arcane_t_spells_known++;
	    if (l >= 20)
		arcane_t_spells_known++;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n";
}
void Wizard::setClassDetails(const int &l)
{
    simpleClearScreen();
    char_class = "Wizard";
    level = l;
    hitdicesize = 6;
    intSave = 1;
    wisSave = 1;
    if (!spellcasting)
	spellcasting = true;
    if (!arcane_recovery)
	arcane_recovery = true;
    if (!arcane_tradition && l >= 2)
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
	    abjuration = true;
	    break;
	case 2:
	    conjuration = true;
	    break;
	case 3:
	    divination = true;
	    break;
	case 4:
	    enchantment = true;
	    break;
	case 5:
	    evocation = true;
	    break;
	case 6:
	    illusion = true;
	    break;
	case 7:
	    necromancy = true;
	    break;
	case 8:
	    transmutation = true;
	    break;
	case 9:
	    bladesinging = true;
	    performance = true;
	    cout << "Bladesinger: gained Performance & proficiency in Light Armor or 1H Weapon\n";
	    break;
	default:;
	}
	arcane_tradition = true;
	cout << endl;
    }
    if (arcane_tradition_feature == 0 && l >= 6)
	arcane_tradition_feature++;
    if (arcane_tradition_feature == 1 && l >= 10)
	arcane_tradition_feature++;
    if (arcane_tradition_feature == 2 && l >= 14)
	arcane_tradition_feature++;
    if (!spell_mastery && l >= 18)
	spell_mastery = true;
    if (!signature_spell && l == 20)
	signature_spell = true;
    //spellslots
    for (int i = 1; i <= l; i++)
    {
	switch (i)
	{
	case 1:
	    wizard_cantrips_known = 3;
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
	    wizard_cantrips_known++;
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
	    wizard_cantrips_known++;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Barbarian::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Barbarian Details:\n\n";
    char_class = "Barbarian";
    level = l;
    hitdicesize = 12;
    strSave = true;
    conSave = true;
    if (l == 20)
    {
	rages = 1000;
    }
    else
    {
	rages = 2;
	if (l > 2)
	{
	    rages++;
	    if (l > 5)
	    {
		rages++;
		if (l > 11)
		{
		    rages++;
		    if (l > 16)
		    {
			rages++;
		    }
		}
	    }
	}
    }
    if (l > 0)
    {
	rage_damage = 2;
	if (l > 8)
	{
	    rage_damage++;
	    if (l > 15)
	    {
		rage_damage++;
	    }
	}
    }
    if (!unarmored_defense && l >= 1)
	unarmored_defense = true;
    if (!reckless_attack && l >= 2)
	reckless_attack = true;
    if (!danger_sense && l >= 2)
	danger_sense = true;
    if (!primal_path && l >= 3)
    {
	cout << "Choose a Primal Path:\n\n";
	cout << " 1. Path of the Battlerager (Dwarf Only or check with DM)\n 2. Path of the Berserker\n 3. Path of the Totem Warrior.\n\n";
	int ss = getNumber("Choice(1-3): ", 1, 3);
	switch (ss)
	{
	case 1:
	    path_of_the_battlerager = true;
	    break;
	case 2:
	    path_of_the_berseker = true;
	    break;
	case 3:
	    path_of_the_totem_warrior = true;
	    cout << "Choose a type for your totem Path:\n\n"
		 << " 1. Bear\n 2. Eagle\n 3. Wolf\n\n";
	    ss = getNumber("Choice(1-3): ", 1, 3);
	    if (ss == 1)
	    {
		bear_totem = true;
		eagle_totem = false;
		wolf_totem = false;
	    }
	    if (ss == 2)
	    {
		eagle_totem = true;
		bear_totem = false;
		wolf_totem = false;
	    }
	    if (ss == 3)
	    {
		wolf_totem = true;
		bear_totem = false;
		eagle_totem = false;
	    }
	    //uthgardt totem options need added but they are minimal effect
	}
	primal_path = true;
    }
    if (extra_attack == 0 && l >= 5)
    {
	extra_attack++;
    }
    if (!fast_movement && l >= 5)
    {
	fast_movement = true;
	move_speed += 10;
    }
    if (path_feature == 0 && l >= 6)
    {
	path_feature++;
    }
    if (!feral_instinct && l >= 7)
    {
	feral_instinct = true;
    }
    if (brutal_critical == 0 && l >= 9)
    {
	brutal_critical++;
    }
    if (path_feature == 1 && l >= 10)
    {
	if (path_of_the_totem_warrior)
	{
	    cout << "Change Totem Path option:\n\n"
		 << " 1. Bear\n 2. Eagle\n 3. Wolf\n\n";
	    int ss = getNumber("Choice: ", 1, 3);
	    if (ss == 1)
	    {
		bear_totem = true;
		eagle_totem = false;
		wolf_totem = false;
	    }
	    if (ss == 2)
	    {
		eagle_totem = true;
		bear_totem = false;
		wolf_totem = false;
	    }
	    if (ss == 3)
	    {
		wolf_totem = true;
		bear_totem = false;
		eagle_totem = false;
	    }
	}
	path_feature++;
    }
    if (!relentless_rage && l >= 11)
    {
	relentless_rage = true;
    }
    if (brutal_critical == 1 && l >= 13)
    {
	brutal_critical++;
    }
    if (path_feature == 2 && l >= 14)
    {
	if (path_of_the_totem_warrior)
	{
	    cout << "Change Totem Path option:\n\n"
		 << " 1. Bear\n 2. Eagle\n 3. Wolf\n\n";
	    int ss = getNumber("Choice: ", 1, 3);
	    if (ss == 1)
	    {
		bear_totem = true;
		eagle_totem = false;
		wolf_totem = false;
	    }
	    if (ss == 2)
	    {
		eagle_totem = true;
		bear_totem = false;
		wolf_totem = false;
	    }
	    if (ss == 3)
	    {
		wolf_totem = true;
		bear_totem = false;
		eagle_totem = false;
	    }
	}
	path_feature++;
    }
    if (!persistant_rage && l >= 15)
    {
	persistant_rage = true;
    }
    if (brutal_critical == 2 && l >= 17)
    {
	brutal_critical++;
    }
    if (!indomitable_might && l >= 18)
    {
	indomitable_might = true;
    }
    if (!primal_champion && l >= 20)
    {
	primal_champion = true;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n";
}
void Druid::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Druid Details.\n\n";
    char_class = "Druid";
    level = l;
    hitdicesize = 8;
    intSave = true;
    wisSave = true;
    if (!druidic)
	druidic = true; //learn druidic lang
    if (!spellcasting)
	spellcasting = true;
    if (!wild_shape && l >= 2)
	wild_shape = true;
    if (!druid_circle && l >= 2)
    {
	cout << "Druid Circle:\n\n"
	     << " 1. Circle of the Land\n 2. Circle of the Moon\n\n";
	int ss = getNumber("Choice: ", 1, 2);
	if (ss == 1)
	{
	    cout << "Circle of the Land type:\n\n";
	    setLandtype();
	    circle_of_the_land = true;
	}
	if (ss == 2)
	    circle_of_the_moon = true;
	druid_circle = true;
    }
    if (wild_shape_improvement == .25 && l >= 4)
	wild_shape_improvement += .25;
    if (druid_circle_feature == 0 && l >= 6)
	druid_circle_feature++;
    if (wild_shape_improvement == .5 && l >= 8)
	wild_shape_improvement += .5;
    if (druid_circle_feature == 1 && l >= 10)
	druid_circle_feature++;
    if (druid_circle_feature == 2 && l >= 14)
	druid_circle_feature++;
    if (!timeless_body && l >= 18)
	timeless_body = true;
    if (!beast_spells && l >= 18)
	beast_spells = true;
    if (!archdruid && l >= 20)
	archdruid = true;
    //druid spells
    if (l >= 1 && l <= 3)
    {
	druid_cantrips_known = 2;
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
	druid_cantrips_known = 3;
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
	druid_cantrips_known = 4;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Paladin::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Paladin Details.\n\n";
    char_class = "Paladin";
    level = l;
    hitdicesize = 10;
    wisSave = true;
    chaSave = true;
    if (!divine_sense)
	divine_sense = true;
    if (!lay_on_hands)
	lay_on_hands = true;
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
    if (divine_smite == 0 && l >= 2)
	divine_smite++;
    if (!divine_health && l >= 3)
	divine_health = true;
    if (!sacred_oath && l >= 3)
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
	    oath_of_ancients = true;
	    break;
	case 2:
	    oath_of_devotion = true;
	    break;
	case 3:
	    oath_of_the_crown = true;
	    break;
	case 4:
	    oath_of_vengeance = true;
	    break;
	case 5:
	    oathbreaker = true;
	    break;
	default:
	    cout << "Error setting Paladin Oath - check code\n\n";
	    break;
	}
	sacred_oath = true;
    }
    if (extra_attack == 0 && l >= 5)
	extra_attack++;
    if (!aura_of_protection && l >= 6)
	aura_of_protection = true;
    if (sacred_oath_feature == 0 && l >= 7)
	sacred_oath_feature++;
    if (!aura_of_courage && l >= 10)
	aura_of_courage = true;
    if (divine_smite == 1 && l >= 11)
	divine_smite++;
    if (!cleansing_touch && l >= 14)
	cleansing_touch = true;
    if (sacred_oath_feature == 1 && l >= 15)
	sacred_oath_feature++;
    if (!aura_improvments && l >= 18)
	aura_improvments = true;
    if (sacred_oath_feature == 2 && l == 20)
	sacred_oath_feature++;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n";
}
void Sorcerer::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Sorcerer details.\n\n";
    char_class = "Sorcerer";
    level = l;
    hitdicesize = 6;
    conSave = true;
    chaSave = true;
    if (!spellcasting)
	spellcasting = true;
    if (!sorcerous_origin)
    {
	cout << "Sorcerous Origin:\n\n"
	     << " 1. Draconic Bloodline\n 2. Wild Magic\n 3. Storm Sorcery\n\n";
	int ss = getNumber("Sorcerous Origin choice: ", 1, 3);
	switch (ss)
	{
	case 1:
	    draconic = true;
	    draconic_bloodline = true;
	    break;
	case 2:
	    wild_magic = true;
	    break;
	case 3:
	    storm_sorcery = true;
	    break;
	default:;
	}
	sorcerous_origin = true;
    }
    if (!font_of_magic && l >= 2)
	font_of_magic = true;
    if (metamagic == 0 && l >= 3)
	metamagic++;
    if (sorcerous_origin_feature == 0 && l >= 6)
	sorcerous_origin_feature++;
    if (metamagic == 1 && l >= 10)
	metamagic++;
    if (sorcerous_origin_feature == 1 && l >= 14)
	sorcerous_origin_feature++;
    if (metamagic == 2 && l >= 17)
	metamagic++;
    if (sorcerous_origin_feature == 2 && l >= 18)
	sorcerous_origin_feature++;
    if (!sorcerous_restoration && l == 20)
	sorcerous_restoration = true;
    //spells
    if (l >= 1)
    {
	sorcerer_cantrips_known = 4;
	sorcerer_spells_known = 2;
	first_ss = 2;
    }
    if (l >= 2)
    {
	sorcerer_spells_known++;
	first_ss++;
	sorcery_points = l;
    }
    if (l >= 3)
    {
	sorcerer_spells_known++;
	first_ss++;
	second_ss += 2;
    }
    if (l >= 4)
    {
	sorcerer_cantrips_known++;
	sorcerer_spells_known++;
	second_ss++;
    }
    if (l >= 5)
    {
	sorcerer_spells_known++;
	third_ss += 2;
    }
    if (l >= 6)
    {
	sorcerer_spells_known++;
	third_ss++;
    }
    if (l >= 7)
    {
	sorcerer_spells_known++;
	forth_ss++;
    }
    if (l >= 8)
    {
	sorcerer_spells_known++;
	forth_ss++;
    }
    if (l >= 9)
    {
	sorcerer_spells_known++;
	forth_ss++;
	fifth_ss++;
    }
    if (l >= 10)
    {
	sorcerer_cantrips_known++;
	sorcerer_spells_known++;
	fifth_ss++;
    }
    if (l >= 11)
    {
	sorcerer_spells_known++;
	sixth_ss++;
    }
    if (l >= 13)
    {
	sorcerer_spells_known++;
	seventh_ss++;
    }
    if (l >= 15)
    {
	sorcerer_spells_known++;
	eighth_ss++;
    }
    if (l >= 17)
    {
	sorcerer_spells_known++;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Bard::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << "->Set Bard Details:\n\n";
    char_class = "Bard";
    level = l;
    hitdicesize = 8;
    chaSave = true;
    dexSave = true;
    if (!spellcasting)
    {
	spellcasting = true;
    }
    if (bardic_inspiration == 0)
    {
	bardic_inspiration = 6;
    }
    if (!jack_of_all_trades && l >= 2)
    {
	jack_of_all_trades = true;
    }
    if (song_of_rest == 0 && l >= 2)
    {
	song_of_rest = 6;
    }
    if (!bard_college && l >= 3)
    {
	cout << "Bard College:\n\n"
	     << " 1. College of Lore\n 2. College of Valor\n\n";
	int ss = getNumber("Choice(1-2):  ", 1, 2);
	if (ss == 1)
	{
	    setAnySkill("College of Lore Skills:", 3);
	    college_of_lore = true;
	}
	if (ss == 2)
	    college_of_valor = true;
	bard_college = true;
    }
    if (expertise == 0 && l >= 3)
    {
	expertise++;
    }
    if (bardic_inspiration <= 6 && l >= 5)
    {
	bardic_inspiration = 8;
    }
    if (!font_of_inspiration && l >= 5)
    {
	font_of_inspiration = true;
    }
    if (!countercharm && l >= 6)
    {
	countercharm = true;
    }
    if (bard_college_feature <= 0 && l >= 6)
    {
	bard_college_feature++;
	if (college_of_lore)
	    additional_magical_secrets = true;
	if (college_of_valor && extra_attack == 0)
	    extra_attack++;
    }
    if (song_of_rest <= 6 && l >= 9)
    {
	song_of_rest = 8;
    }
    if (bardic_inspiration <= 8 && l >= 10)
    {
	bardic_inspiration = 10;
    }
    if (expertise <= 1 && l >= 10)
    {
	expertise++;
    }
    if (magical_secrets == 0 && l >= 10)
    {
	magical_secrets++;
    }
    if (song_of_rest <= 8 && l >= 13)
    {
	song_of_rest = 10;
    }
    if (bard_college_feature <= 1 && l >= 14)
    {
	bard_college_feature++;
    }
    if (magical_secrets <= 1 && l >= 14)
    {
	magical_secrets++;
    }
    if (bardic_inspiration <= 10 && l >= 15)
    {
	bardic_inspiration = 12;
    }
    if (song_of_rest <= 10 && l >= 17)
    {
	song_of_rest = 12;
    }
    if (magical_secrets <= 2 && l >= 18)
    {
	magical_secrets++;
    }
    if (!superior_inspiration && l >= 20)
    {
	superior_inspiration = true;
    }
    //bard spells
    for (int i = 1; i <= l; i++)
    {
	switch (i)
	{
	case 1:
	    bard_cantrips_known = 2;
	    bard_spells_known = 4;
	    first_ss = 2;
	    break;
	case 2:
	    bard_spells_known++;
	    first_ss++;
	    break;
	case 3:
	    bard_spells_known++;
	    first_ss++;
	    second_ss = 2;
	    break;
	case 4:
	    bard_cantrips_known++;
	    bard_spells_known++;
	    second_ss++;
	    break;
	case 5:
	    bard_spells_known++;
	    third_ss = 2;
	    break;
	case 6:
	    bard_spells_known++;
	    third_ss++;
	    if (additional_magical_secrets)
		bard_spells_known += 2;
	    break;
	case 7:
	    bard_spells_known++;
	    forth_ss = 1;
	    break;
	case 8:
	    bard_spells_known++;
	    forth_ss++;
	    break;
	case 9:
	    bard_spells_known++;
	    forth_ss++;
	    fifth_ss = 1;
	    break;
	case 10:
	    bard_cantrips_known++;
	    fifth_ss++;
	    bard_spells_known += 2;
	    break;
	case 11:
	    bard_spells_known++;
	    sixth_ss = 1;
	    break;
	case 13:
	    bard_spells_known++;
	    seventh_ss = 1;
	    break;
	case 14:
	    bard_spells_known += 2;
	    break;
	case 15:
	    bard_spells_known++;
	    eighth_ss = 1;
	    break;
	case 17:
	    bard_spells_known++;
	    ninth_ss = 1;
	    break;
	case 18:
	    bard_spells_known += 2;
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
	simpleClearScreen();
	setInstrument("Choose 3 Bard instruments.\n\n", 3);
	setAnySkill("Bards start with 4 skills:", 4);
    }
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n";
}
void Monk::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Monk details.\n\n";
    char_class = "Monk";
    level = l;
    hitdicesize = 8;
    strSave = true;
    dexSave = true;
    if (!unarmored_defense)
	unarmored_defense = true;
    if (l >= 1 && l <= 4)
	martial_arts = 4;
    else if (l >= 5 && l <= 10)
	martial_arts = 6;
    else if (l >= 11 && l <= 16)
	martial_arts = 8;
    else if (l >= 17 && l <= 20)
	martial_arts = 10;
    if (l >= 2)
	ki = l;
    if (l >= 2 && l <= 5)
	unarmored_movement = 10;
    else if (l >= 6 && l <= 9)
	unarmored_movement = 15;
    else if (l >= 10 && l <= 13)
	unarmored_movement = 20;
    else if (l >= 14 && l <= 17)
	unarmored_movement = 25;
    else if (l > -18 && l <= 20)
	unarmored_movement = 30;
    if (!monastic_tradition && l >= 3)
    {
	cout << "Monastic Tradition:\n\n"
	     << " 1. Way of the Open Hand\n 2. Way of the Four Elements\n"
	     << " 3. Way of the Long Death\n 4. Way of the Shadow\n"
	     << " 5. Way of the Sun Soul\n\n";
	int ss = getNumber("Tradition choice(1-3): ", 1, 5);
	switch (ss)
	{
	case 1:
	    way_of_the_open_hand = true;
	    break;
	case 2:
	    way_of_the_four_elements = true;
	    break;
	case 3:
	    way_of_the_long_death = true;
	    break;
	case 4:
	    way_of_the_shadow = true;
	    break;
	case 5:
	    way_of_the_sun_soul = true;
	    break;
	default:
	    cout << "Error setting monk tradition - check code\n\n";
	}
	monastic_tradition = true;
    }
    if (!deflect_missles && l >= 3)
	deflect_missles = true;
    if (!slow_fall && l >= 4)
	slow_fall = true;
    if (extra_attack == 0 && l >= 5)
	extra_attack++;
    if (!stunning_strike && l >= 5)
	stunning_strike = true;
    if (!ki_empowered_strikes && l >= 6)
	ki_empowered_strikes = true;
    if (monastic_tradition_feature == 0 && l >= 6)
	monastic_tradition_feature++;
    if (!evasion && l >= 7)
	evasion = true;
    if (!stillness_of_mind && l >= 7)
	stillness_of_mind = true;
    if (!unarmored_movement_improvement && l >= 9)
	unarmored_movement_improvement = true;
    if (!purity_of_body && l >= 10)
	purity_of_body = true;
    if (monastic_tradition_feature == 1 && l >= 11)
	monastic_tradition_feature++;
    if (!tongue_of_the_sun_and_moon && l >= 13)
	tongue_of_the_sun_and_moon = true;
    if (!diamond_soul && l >= 14)
	diamond_soul = true;
    if (!timeless_body && l >= 15)
	timeless_body = true;
    if (monastic_tradition_feature == 2 && l >= 17)
	monastic_tradition_feature++;
    if (!empty_body && l >= 18)
	empty_body = true;
    if (!perfect_self && l == 20)
	perfect_self = true;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Ranger::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Ranger details.\n\n";
    char_class = "Ranger";
    level = l;
    hitdicesize = 10;
    strSave = true;
    dexSave = true;
    if (favored_enemy == 0)
    {
	cout << "Ranger Favored Enemy:\n\n";
	setFavoredEnemy();
	favored_enemy++;
    }
    if (natural_explorer == 0)
    {
	cout << "Natural Explorer land type:\n\n";
	setLandtype();
	natural_explorer++;
    }
    if (!fighting_style && l >= 2)
    {
	cout << "Ranger Fighting Style:\n\n"
	     << " 1. Archery\n 2. Defense\n 3. Dueling\n 4. Two Weapon Fighting\n\n";
	int ss = getNumber("Fight Style choice: ", 1, 4);
	if (ss == 1)
	    archery = true;
	if (ss == 2)
	    defense = true;
	if (ss == 3)
	    dueling = true;
	if (ss == 4)
	    two_weapon_fighting = true;
	fighting_style = true;
    }
    if (!spellcasting && l >= 2)
	spellcasting = true;
    if (!ranger_archetype && l >= 3)
    {
	cout << "Ranger Archetype:\n\n"
	     << " 1. Hunter\n 2. Beast Master\n\n";
	int ss = getNumber("Archetype choice(1-2): ", 1, 2);
	if (ss == 1)
	    hunter = true;
	if (ss == 2)
	    beast_master = true;
	ranger_archetype = true;
    }
    if (!primeval_awareness && l >= 3)
	primeval_awareness = true;
    if (extra_attack == 0 && l >= 5)
	extra_attack++;
    if (favored_enemy == 1 && l >= 6)
    {
	cout << "Ranger Favored Enemy:\n\n";
	setFavoredEnemy();
	favored_enemy++;
    }
    if (natural_explorer == 1 && l >= 6)
    {
	cout << "Natural Explorer land type:\n\n";
	setLandtype();
	natural_explorer++;
    }
    if (ranger_archetype_feature == 0 && l >= 7)
	ranger_archetype_feature++;
    if (!lands_stride && l >= 8)
	lands_stride = true;
    if (natural_explorer == 2 && l >= 10)
    {
	cout << "Natural Explorer land type:\n\n";
	setLandtype();
	natural_explorer++;
    }
    if (!hide_in_plain_sight && l >= 10)
	hide_in_plain_sight = true;
    if (ranger_archetype_feature == 1 && l >= 11)
	ranger_archetype_feature++;
    if (favored_enemy == 2 && l >= 14)
    {
	cout << "Ranger Favored Enemy:\n\n";
	setFavoredEnemy();
	favored_enemy++;
    }
    if (!vanish && l >= 14)
	vanish = true;
    if (ranger_archetype_feature == 2 && l >= 15)
	ranger_archetype_feature++;
    if (!feral_senses && l >= 18)
	feral_senses = true;
    if (!foe_slayer && l == 20)
	foe_slayer = true;
    // spells
    if (l >= 2)
    {
	ranger_spells_known = 2;
	first_ss = 2;
    }
    if (l >= 3)
    {
	ranger_spells_known++;
	first_ss++;
    }
    if (l >= 5)
    {
	ranger_spells_known++;
	first_ss++;
	second_ss = 2;
    }
    if (l >= 7)
    {
	ranger_spells_known++;
	second_ss++;
    }
    if (l >= 9)
    {
	ranger_spells_known++;
	third_ss = 2;
    }
    if (l >= 11)
    {
	ranger_spells_known++;
	third_ss++;
    }
    if (l >= 13)
    {
	ranger_spells_known++;
	forth_ss = 1;
    }
    if (l >= 15)
    {
	ranger_spells_known++;
	forth_ss++;
    }
    if (l >= 17)
    {
	ranger_spells_known++;
	forth_ss++;
	fifth_ss = 1;
    }
    if (l >= 19)
    {
	ranger_spells_known++;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}
void Warlock::setClassDetails(const int &l)
{
    simpleClearScreen();
    cout << " ->Set Warlock details.\n\n";
    char_class = "Warlock";
    level = l;
    hitdicesize = 8;
    intSave = true;
    chaSave = true;
    if (!pact_magic)
	pact_magic = true;
    if (!otherworldly_patron)
    {
	cout << "Choose Warlock Otherworldly Patron:\n\n"
	     << " 1. Archfey\n 2. Fiend\n 3. Great Old One\n 4. The Undying\n\n";
	int ss = getNumber("Patron choice: ", 1, 4);
	switch (ss)
	{
	case 1:
	    archfey = true;
	    break;
	case 2:
	    fiend = true;
	    break;
	case 3:
	    great_old_one = true;
	    break;
	case 4:
	    the_undying = true;
	    break;
	default:;
	}
	otherworldly_patron = true;
    }
    if (!pact_boon && l >= 3)
	pact_boon = true;
    if (otherworldly_patron_feature == 0 && l >= 6)
	otherworldly_patron_feature++;
    if (otherworldly_patron_feature == 1 && l >= 10)
	otherworldly_patron_feature++;
    if (mystic_arcanum == 0 && l >= 11)
	mystic_arcanum += 6;
    if (mystic_arcanum == 6 && l >= 13)
	mystic_arcanum++;
    if (otherworldly_patron_feature == 2 && l >= 14)
	otherworldly_patron_feature++;
    if (mystic_arcanum == 7 && l >= 15)
	mystic_arcanum++;
    if (mystic_arcanum == 8 && l >= 17)
	mystic_arcanum++;
    if (!eldritch_master && l == 20)
	eldritch_master = true;
    //spells
    if (l >= 1)
    {
	warlock_cantrips_known += 2;
	warlock_spells_known += 2;
	warlock_spell_slots++;
	warlock_slot_level++;
    }
    if (l >= 2)
    {
	warlock_spells_known++;
	warlock_spell_slots++;
	eldritch_invocations_known += 2;
    }
    if (l >= 3)
    {
	warlock_spells_known++;
	warlock_slot_level++;
    }
    if (l >= 4)
    {
	warlock_cantrips_known++;
	warlock_spells_known++;
    }
    if (l >= 5)
    {
	warlock_spells_known++;
	warlock_slot_level++;
	eldritch_invocations_known++;
    }
    if (l >= 6)
    {
	warlock_spells_known++;
    }
    if (l >= 7)
    {
	warlock_spells_known++;
	warlock_slot_level++;
	eldritch_invocations_known++;
    }
    if (l >= 8)
    {
	warlock_spells_known++;
    }
    if (l >= 9)
    {
	warlock_spells_known++;
	warlock_slot_level++;
	eldritch_invocations_known++;
    }
    if (l >= 10)
    {
	warlock_cantrips_known++;
    }
    if (l >= 11)
    {
	warlock_spells_known++;
	warlock_spell_slots++;
    }
    if (l >= 12)
    {
	eldritch_invocations_known++;
    }
    if (l >= 13)
    {
	warlock_spells_known++;
    }
    if (l >= 15)
    {
	warlock_spells_known++;
	eldritch_invocations_known++;
    }
    if (l >= 17)
    {
	warlock_spells_known++;
	warlock_spell_slots++;
    }
    if (l >= 18)
    {
	eldritch_invocations_known++;
    }
    if (l >= 19)
    {
	warlock_spells_known++;
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
	simpleClearScreen();
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
    cout << "\nNew  " << char_class << " named '" << name << "' created.\n\n";
}

void Generic_Character_Class::setName()
{
    string tmp;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do
    {
	cout << "Character Name: ";
	getline(cin, tmp);
	tmp[0] = toupper(tmp[0]);
	if (tmp.size() < 2 || tmp[0] == ' ')
	{
	    cout << "Invalid name, try another.\n";
	}
    } while (tmp.size() < 2 || tmp[0] == ' ');
    name = tmp;
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
    if (ss == 1)
    {
	Dragonborn *tmp = new Dragonborn;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	// delete tmp;
    }
    else if (ss == 2)
    {
	Dwarf *tmp = new Dwarf;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//delete tmp;
    }
    else if (ss == 3)
    {
	Elf *tmp = new Elf;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	// delete tmp;
    }
    else if (ss == 4)
    {
	Gnome *tmp = new Gnome;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//    delete tmp;
    }
    else if (ss == 5)
    {
	Halfelf *tmp = new Halfelf;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//    delete tmp;
    }
    else if (ss == 6)
    {
	Halfling *tmp = new Halfling;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//     delete tmp;
    }
    else if (ss == 7)
    {
	Halforc *tmp = new Halforc;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//    delete tmp;
    }
    else if (ss == 8)
    {
	Human *tmp = new Human;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//    delete tmp;
    }
    else
    {
	Tiefling *tmp = new Tiefling;
	tmp->setRaceDetails(v);
	race = tmp->getRaceString();
	//    delete tmp;
    }
}
void Generic_Character_Class::setAlignment()
{
    simpleClearScreen();
    cout << "Pick an Alignment for " << name << ".\n\n"
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

    int ss = getNumber("Background choice(1-25): ", 1, 25);
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
    simpleClearScreen();
    char ans = getYorN("Roll Stats? (y/n) ");
    if (ans == 'Y')
    {
	int stats[6];
	int ss = getNumber("Roll Style:\n\n 1. 4d6 drop lowest\n 2. 3d6 standard\n\nChoice: ", 1, 2);
	simpleClearScreen();
	for (int i = 0; i < 6; i++)
	{
	    if (ss == 1)
	    {
		stats[i] = rollstats_hi_power();
	    }
	    else
	    {
		stats[i] = rollstats_standard();
	    }
	    if (i == 5)
	    {
		cout << "\n\n  Your 6 Stats: \n";
		for (int j = 0; j < 6; j++)
		{
		    cout << "\n " << stats[j];
		}
		cout << endl;
		pressEnterToContinue();
		simpleClearScreen();
	    }
	}
	for (int i = 0; i < 6; i++)
	{
	    cout << "Stats Left: \n\n";
	    for (int j = i; j < 6; j++)
	    {
		if (j == i)
		    cout << CYAN << stats[j] << GREEN << " <-Currently assigning" << RESET << ", ";
		else
		    cout << stats[j] << ", ";
	    }
	    assignStats(stats[i]);
	    simpleClearScreen();
	}
    }
    else
    {
	ans = getYorN("Use generic starting stats(15,14,13,12,10,8)? (y/n) ");
	if (ans == 'Y')
	{
	    int stats[6] = {15, 14, 13, 12, 10, 8};
	    for (int i = 0; i < 6; i++)
	    {
		cout << "Stats Left: \n\n";
		for (int j = i; j < 6; j++)
		{
		    if (j == i)
			cout << CYAN << stats[j] << GREEN << " <-Currently assigning" << RESET << ", ";
		    else
			cout << stats[j] << ", ";
		}
		assignStats(stats[i]);
		simpleClearScreen();
	    }
	}
	else
	{
	    setStr(getNumber("Enter starting Strength(3-18): ", 3, 18));
	    setDex(getNumber("Enter starting Dexterity(3-18): ", 3, 18));
	    setCon(getNumber("Enter starting Constitution(3-18): ", 3, 18));
	    setInt(getNumber("Enter starting Intelligence(3-18): ", 3, 18));
	    setWis(getNumber("Enter starting Wisdom(3-18): ", 3, 18));
	    setCha(getNumber("Enter starting Charisma(3-18): ", 3, 18));
	}
	pressEnterToContinue();
    }
    cout << " Final Stats are -\n  ->Str: ";
    if (strength != 0)
	cout << GREEN << strength << RESET << endl;
    else
	cout << RED << "Not Set" << RESET << endl;
    cout << "  ->Dex: ";
    if (dexterity != 0)
	cout << GREEN << dexterity << RESET << endl;
    else
	cout << RED << "Not Set" << RESET << endl;
    cout << "  ->Con: ";
    if (constitution != 0)
	cout << GREEN << constitution << RESET << endl;
    else
	cout << RED << "Not Set" << RESET << endl;
    cout << "  ->Int: ";
    if (intelligence != 0)
	cout << GREEN << intelligence << RESET << endl;
    else
	cout << RED << "Not Set" << RESET << endl;
    cout << "  ->Wis: ";
    if (wisdom != 0)
	cout << GREEN << wisdom << RESET << endl;
    else
	cout << RED << "Not Set" << RESET << endl;
    cout << "  ->Cha: ";
    if (charisma != 0)
	cout << GREEN << charisma << RESET << endl;
    else
	cout << RED << "Not Set" << RESET << endl;
    cout << "------" << endl;

    pressEnterToContinue();
}
void Generic_Character_Class::setStr(const int &s) { strength = s; }
void Generic_Character_Class::setDex(const int &d) { dexterity = d; }
void Generic_Character_Class::setCon(const int &c) { constitution = c; }
void Generic_Character_Class::setInt(const int &i) { intelligence = i; }
void Generic_Character_Class::setWis(const int &w) { wisdom = w; }
void Generic_Character_Class::setCha(const int &ch) { charisma = ch; }
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
void Generic_Character_Class::setAnySkill(const string &message, const int &many)
{
    int ss(0);
    cout << message << "\n";
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
	ss = getNumber("Skill choice: ", 1, 18);
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
    cin.get();
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
    favored_enemy_languages = true;
}
void Generic_Character_Class::setAnyFeat()
{
    bool set = false;
    cout << "List of Feats to choose from:\n\n";
    while (!set)
    {
	cout << " 1. Alert               15. Heavy Armor Master   29. Polearm Master"
	     << "\n 2. Athlete             16. Inspiring Leader     30. Resilient"
	     << "\n 3. Actor               17. Keen Mind            31. Ritual Caster"
	     << "\n 4. Charger             18. Lightly Armored      32. Savage Attacker"
	     << "\n 5. Crossbow Expert     19. Linguist             33. Sentinel"
	     << "\n 6. Defensive Duelist   20. Lucky                34. Sharpshooter"
	     << "\n 7. Dual Wielder        21. Mage Slayer          35. Shield Master"
	     << "\n 8. Dungeon Delver      22. Magic Initiate       36. Skilled"
	     << "\n 9. Durable             23. Martial Adept        37. Skulker"
	     << "\n10. Elemental Adapt     24. Medium Armor Master  38. Spell Sniper"
	     << "\n11. Grappler            25. Mobile               39. Tavern Brawler"
	     << "\n12. Great Weapon Master 26. Moderately Armored   40. Tough"
	     << "\n13. Healer              27. Mounted Combat       41. War Caster"
	     << "\n14. Heavily Armored     28. Observant            42. Weapon Master\n\n";
	int ss = getNumber("Feat Choice(1-42):", 1, 42);
	if (ss == 1)
	{
	    gainAlert(set);
	}
	if (ss == 2)
	{
	    gainAthlete(set);
	}
	if (ss == 3)
	{
	    gainActor(set);
	}
	if (ss == 4)
	{
	    gainCharger(set);
	}
	if (ss == 5)
	{
	    gainCrossbow_expert(set);
	}
	if (ss == 6)
	{
	    gainDefensive_duelist(set);
	}
	if (ss == 7)
	{
	    gainDual_wielder(set);
	}
	if (ss == 8)
	{
	    gainDungeon_delver(set);
	}
	if (ss == 9)
	{
	    gainDurable(set);
	}
	if (ss == 10)
	{
	    gainElemental_adept(set);
	}
	if (ss == 11)
	{
	    gainGrappler(set);
	}
	if (ss == 12)
	{
	    gainGreat_weapon_master(set);
	}
	if (ss == 13)
	{
	    gainHealer(set);
	}
	if (ss == 14)
	{
	    gainHeavily_armored(set);
	}
	if (ss == 15)
	{
	    gainHeavy_armor_master(set);
	}
	if (ss == 16)
	{
	    gainInspiring_leader(set);
	}
	if (ss == 17)
	{
	    gainKeen_mind(set);
	}
	if (ss == 18)
	{
	    gainLightly_armored(set);
	}
	if (ss == 19)
	{
	    gainLinguist(set);
	}
	if (ss == 20)
	{
	    gainLucky(set);
	}
	if (ss == 21)
	{
	    gainMage_slayer(set);
	}
	if (ss == 22)
	{
	    gainMagic_initiate(set);
	}
	if (ss == 23)
	{
	    gainMartial_adept(set);
	}
	if (ss == 24)
	{
	    gainMedium_armor_master(set);
	}
	if (ss == 25)
	{
	    gainMobile(set);
	}
	if (ss == 26)
	{
	    gainModerately_armored(set);
	}
	if (ss == 27)
	{
	    gainMounted_combatant(set);
	}
	if (ss == 28)
	{
	    gainObservant(set);
	}
	if (ss == 29)
	{
	    gainPolearm_master(set);
	}
	if (ss == 30)
	{
	    gainResilient(set);
	}
	if (ss == 31)
	{
	    gainRitual_caster(set);
	}
	if (ss == 32)
	{
	    gainRavage_attaker(set);
	}
	if (ss == 33)
	{
	    gainSentinel(set);
	}
	if (ss == 34)
	{
	    gainSharpshooter(set);
	}
	if (ss == 35)
	{
	    gainShield_master(set);
	}
	if (ss == 36)
	{
	    gainSkilled(set);
	}
	if (ss == 37)
	{
	    gainSkulker(set);
	}
	if (ss == 38)
	{
	    gainSpell_sniper(set);
	}
	if (ss == 39)
	{
	    gainTavern_brawler(set);
	}
	if (ss == 40)
	{
	    gainTough(set);
	}
	if (ss == 41)
	{
	    gainWar_caster(set);
	}
	if (ss == 42)
	{
	    gainWeapon_master(set);
	}
    }
}
void Generic_Character_Class::gainAlert(bool &s)
{
    if (!alert)
    {
	alert = true;
	cout << "Alert feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainAthlete(bool &s)
{
    if (!athlete)
    {
	athlete = true;
	cout << "Athlete feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainActor(bool &s)
{
    if (!actor)
    {
	actor = true;
	cout << "Actor feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainCharger(bool &s)
{
    if (!charger)
    {
	charger = true;
	cout << "Charger feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainCrossbow_expert(bool &s)
{
    if (!crossbow_expert)
    {
	crossbow_expert = true;
	cout << "Crossbow Expert feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainDefensive_duelist(bool &s)
{
    if (!defensive_duelist)
    {
	defensive_duelist = true;
	cout << "Defensive Dualist feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainDual_wielder(bool &s)
{
    if (!dual_wielder)
    {
	dual_wielder = true;
	cout << "Dual Wielder feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainDungeon_delver(bool &s)
{
    if (!dungeon_delver)
    {
	dungeon_delver = true;
	cout << "Dungeon Delver feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainDurable(bool &s)
{
    if (!durable)
    {
	durable = true;
	cout << "Durable feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainElemental_adept(bool &s)
{
    if (!elemental_adept)
    {
	elemental_adept = true;
	cout << "Elemental Adept feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainGrappler(bool &s)
{
    if (!grappler)
    {
	grappler = true;
	cout << "Grappler feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainGreat_weapon_master(bool &s)
{
    if (!great_weapon_master)
    {
	great_weapon_master = true;
	cout << "Great Weapon Master feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainHealer(bool &s)
{
    if (!healer)
    {
	healer = true;
	cout << "Healer feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainHeavily_armored(bool &s)
{
    if (!heavily_armored)
    {
	heavily_armored = true;
	cout << "Heavily Armored feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainHeavy_armor_master(bool &s)
{
    if (!heavy_armor_master)
    {
	heavy_armor_master = true;
	cout << "Heavy Armor Master feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainInspiring_leader(bool &s)
{
    if (!inspiring_leader)
    {
	inspiring_leader = true;
	cout << "Inspiring Leader feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainKeen_mind(bool &s)
{
    if (!keen_mind)
    {
	keen_mind = true;
	cout << "Keen Mind feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainLightly_armored(bool &s)
{
    if (!lightly_armored)
    {
	lightly_armored = true;
	cout << "Lightly Armored feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainLinguist(bool &s)
{
    if (!linguist)
    {
	linguist = true;
	cout << "Linguist feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainLucky(bool &s)
{
    if (!lucky)
    {
	lucky = true;
	cout << "Lucky feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainMage_slayer(bool &s)
{
    if (!mage_slayer)
    {
	mage_slayer = true;
	cout << "Mage Slayer feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainMagic_initiate(bool &s)
{
    if (!magic_initiate)
    {
	magic_initiate = true;
	cout << "Magic Initiate feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainMartial_adept(bool &s)
{
    if (!martial_adept)
    {
	martial_adept = true;
	cout << "Martial Adept feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainMedium_armor_master(bool &s)
{
    if (!medium_armor_master)
    {
	medium_armor_master = true;
	cout << "Medium Armor Master feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainMobile(bool &s)
{
    if (!mobile)
    {
	mobile = true;
	cout << "Mobile feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainModerately_armored(bool &s)
{
    if (!moderately_armored)
    {
	moderately_armored = true;
	cout << "Moderately Armored feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainMounted_combatant(bool &s)
{
    if (!mounted_combatant)
    {
	mounted_combatant = true;
	cout << "Mounted Combatant feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainObservant(bool &s)
{
    if (!observant)
    {
	observant = true;
	cout << "Observant feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known\n.";
    }
}
void Generic_Character_Class::gainPolearm_master(bool &s)
{
    if (!polearm_master)
    {
	polearm_master = true;
	cout << "Polearm Master feat learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainResilient(bool &s)
{
    if (!resilient)
    {
	resilient = true;
	cout << "Resilient learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainRitual_caster(bool &s)
{
    if (!ritual_caster)
    {
	ritual_caster = true;
	cout << "Ritual Caster learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainRavage_attaker(bool &s)
{
    if (!savage_attacker)
    {
	savage_attacker = true;
	cout << "Ravage Attacker learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainSentinel(bool &s)
{
    if (!sentinel)
    {
	sentinel = true;
	cout << "Sentinel learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainSharpshooter(bool &s)
{
    if (!sharpshooter)
    {
	sharpshooter = true;
	cout << "Sharpshooter learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainShield_master(bool &s)
{
    if (!shield_master)
    {
	shield_master = true;
	cout << "Sheild Master learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainSkilled(bool &s)
{
    if (!skilled)
    {
	skilled = true;
	cout << "Skilled learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainSkulker(bool &s)
{
    if (!skulker)
    {
	skulker = true;
	cout << "Skulker learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainSpell_sniper(bool &s)
{
    if (!spell_sniper)
    {
	spell_sniper = true;
	cout << "Spell Sniper learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainTavern_brawler(bool &s)
{
    if (!tavern_brawler)
    {
	tavern_brawler = true;
	cout << "Tavern Brawler learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainTough(bool &s)
{
    if (!tough)
    {
	tough = true;
	cout << "Tough learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainWar_caster(bool &s)
{
    if (!war_caster)
    {
	war_caster = true;
	cout << "War Caster learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
}
void Generic_Character_Class::gainWeapon_master(bool &s)
{
    if (!weapon_master)
    {
	weapon_master = true;
	cout << "Weapon Master learned!\n";
	s = true;
    }
    else
    {
	cout << "Feat already known.\n";
    }
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
void Generic_Character_Class::assignStats(int &s)
{

    cout << "\n------\n";
    cout << " Stats are currently -\n  ->Str: ";
    if (strength != 0)
	cout << GREEN << strength << RESET << "\n";
    else
	cout << RED << "Not Set" << RESET << "\n";
    cout << "  ->Dex: ";
    if (dexterity != 0)
	cout << GREEN << dexterity << RESET << "\n";
    else
	cout << RED << "Not Set" << RESET << "\n";
    cout << "  ->Con: ";
    if (constitution != 0)
	cout << GREEN << constitution << RESET << "\n";
    else
	cout << RED << "Not Set" << RESET << "\n";
    cout << "  ->Int: ";
    if (intelligence != 0)
	cout << GREEN << intelligence << RESET << "\n";
    else
	cout << RED << "Not Set" << RESET << "\n";
    cout << "  ->Wis: ";
    if (wisdom != 0)
	cout << GREEN << wisdom << RESET << "\n";
    else
	cout << RED << "Not Set" << RESET << "\n";
    cout << "  ->Cha: ";
    if (charisma != 0)
	cout << GREEN << charisma << RESET << "\n";
    else
	cout << RED << "Not Set" << RESET << "\n";
    cout << "------"
	 << "\n";

    cout << "Assign " << CYAN << s << RESET << " to: \n\n";

    if (strength == 0)
	cout << " 1. Strength\n";
    else
	cout << RED << " 1. Strength(DONE)" << RESET << "\n";

    if (dexterity == 0)
	cout << " 2. Dexterity\n";
    else
	cout << RED << " 2. Dexterity(DONE)" << RESET << "\n";

    if (constitution == 0)
	cout << " 3. Constitution\n";
    else
	cout << RED << " 3. Constitution(DONE)" << RESET << "\n";

    if (intelligence == 0)
	cout << " 4. Intelligence\n";
    else
	cout << RED << " 4. Intelligence(DONE)" << RESET << "\n";

    if (wisdom == 0)
	cout << " 5. Wisdom\n";
    else
	cout << RED << " 5. Wisdom(DONE)" << RESET << "\n";

    if (charisma == 0)
	cout << " 6. Charisma\n\n";
    else
	cout << RED << " 6. Charisma(DONE)" << RESET << "\n\n";
    bool okchoice = false;
    do
    {
	int ss = getNumber("Stat Choice: ", 1, 6);
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
void Generic_Character_Class::updateCharacter(const Campaign &game)
{
    int ss = 0;
    do
    {
	simpleClearScreen();
	cout << "Update what about " << name << ", the level " << level << " " << char_class << "?\n\n"
	     << "1. Change Name" << endl
	     << "2. LEVEL UP!" << endl
	     << "3. Change Alignment" << endl
	     << "4. Update Ability Stats" << endl
	     << "5. Add a new Skill Proficiency" << endl
	     << "6. Add a new Feat" << endl
	     << "7. Quit the PC editor" << endl
	     << endl;
	ss = getNumber("Choice(1-5): ", 1, 7);
	switch (ss)
	{
	case 1:
	{
	    bool goodname = false;
	    string tmp;
	    while (!goodname)
	    {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		do
		{
		    cout << "Current Name: " << name << "\n New Name: ";
		    getline(cin, tmp);
		    tmp[0] = toupper(tmp[0]);
		    if (tmp.size() < 2 || tmp[0] == ' ')
		    {
			cout << "Invalid name, try another.\n";
		    }
		} while (tmp.size() < 2 || tmp[0] == ' ');
		goodname = game.checkname(tmp);
	    }
	    cout << name << " has been renamed to " << tmp << "\n\n";
	    name = tmp;
	}
	break;
	case 2:
	{
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
	break;
	case 3:
	{
	    cout << "Current Alignment is: " << alignment << "\n";
	    cout << "Pick new Alignment for " << name << ".\n\n"
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
    } while (ss != 7);
}
//accessors
void Generic_Character_Class::character_sheet() const
{
    simpleClearScreen();
    cout << " " << name << "'s Character Sheet:\n";
    cout << "->" << GREEN << " Class(Level): " << RESET << char_class << "(" << level << ")\n";
    cout << "->" << GREEN << " Alignment: " << RESET << alignment << "\n";
    cout << "->" << GREEN << " Race: " << RESET << race << "\n";
    cout << "->" << GREEN << " Background: " << RESET << getBackground() << "\n";
    cout << "->" << GREEN << " Hit Dice: " << RESET << level << "d" << hitdicesize 
	<< "(Ave NPC HP: " << ((((hitdicesize+2)/2))*level) + (getAbilityMod(constitution)*level)
	<< " Ave PC HP: " << hitdicesize + ((((hitdicesize+2)/2))*(level-1)) + (getAbilityMod(constitution)*level)
	<< ")\n";
    cout << "->" << GREEN << " Move Speed: " << RESET << move_speed << "ft\n";
    cout << "->" << GREEN << " Proficiency Bonus:" << RESET << " +" << proficiency_bonus;
    cout << "\n->" << MAGENTA << " Str: " << RESET << setw(2) << strength << " " << D_D_Ability_Modifier(strength);
    if (strSave)
	cout << GREEN << "  <-SaveProficient" << RESET;
    cout << "\n->" << MAGENTA << " Dex: " << RESET << setw(2) << dexterity << " " << D_D_Ability_Modifier(dexterity);
    if (dexSave)
	cout << GREEN << "  <-SaveProficient" << RESET;
    cout << "\n->" << MAGENTA << " Con: " << RESET << setw(2) << constitution << " " << D_D_Ability_Modifier(constitution);
    if (conSave)
	cout << GREEN << "  <-SaveProficient" << RESET;
    cout << "\n->" << MAGENTA << " Int: " << RESET << setw(2) << intelligence << " " << D_D_Ability_Modifier(intelligence);
    if (intSave)
	cout << GREEN << "  <-SaveProficient" << RESET;
    cout << "\n->" << MAGENTA << " Wis: " << RESET << setw(2) << wisdom << " " << D_D_Ability_Modifier(wisdom);
    if (wisSave)
	cout << GREEN << "  <-SaveProficient" << RESET;
    cout << "\n->" << MAGENTA << " Cha: " << RESET << setw(2) << charisma << " " << D_D_Ability_Modifier(charisma);
    if (chaSave)
	cout << GREEN << "  <-SaveProficient" << RESET;
    cout << endl;
    printClassAbilities();
    printSpellSlots();
    printSkills();
    printOtherAbilities();
    printLangs();
    printToolsInstruments();
    printFeats();
    printResistances();
    printDisadvantages();
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
void Generic_Character_Class::printClassAbilities() const
{
    cout << "->" << GREEN << " Class Abilities: " << RESET;
    //general
    if (extra_attack > 0)
	cout << "Extra Attack(" << extra_attack << "), ";
    if (spellcasting)
	cout << "Spellcasting, ";
    if (evasion)
	cout << "Evasion, ";
    if (expertise > 0)
	cout << "Expertise(" << expertise << "), ";
    if (timeless_body)
	cout << "Timeless Body, ";
    //barbarians
    if (brutal_critical > 0)
	cout << "Brutal Critical(" << brutal_critical << " dice), ";
    if (danger_sense)
	cout << "Danger Sense, ";
    if (fast_movement)
	cout << "Fast Movement(+10), ";
    if (feral_instinct)
	cout << "Feral Instinct, ";
    if (indomitable_might)
	cout << "Indomintable Might, ";
    if (persistant_rage)
	cout << "Persistant Rage, ";
    if (primal_champion)
	cout << "Primal Champion, ";
    if (rage_damage > 0)
	cout << "Rage Damage(+" << rage_damage << "), ";
    if (rages > 0)
	cout << "Rage(" << rages << "/day), ";
    if (reckless_attack)
	cout << "Reckless Attack, ";
    if (primal_path)
    {
	if (path_of_the_battlerager)
	{
	    cout << "Path of the Battlerager[Battlerager Armor";
	    if (path_feature >= 1)
		cout << ", Reckless Abandon";
	    if (path_feature >= 2)
		cout << ", Battlerager Charge";
	    if (path_feature >= 3)
		cout << ", Spiked Retribution";
	}
	else if (path_of_the_berseker)
	{
	    cout << "Path of the Berserker[Frenzy";
	    if (path_feature >= 1)
		cout << ", Mindless Rage";
	    if (path_feature >= 2)
		cout << ", Intimidating Prescense";
	    if (path_feature >= 3)
		cout << ", Retaliation";
	}
	else
	{
	    cout << "Path of the Totem Warrior";
	    if (bear_totem)
		cout << "(Bear)";
	    if (eagle_totem)
		cout << "(Eagle)";
	    if (wolf_totem)
		cout << "(Wolf)";
	    cout << "[Spirit Seeker, Totem Spirit";
	    if (path_feature >= 1)
		cout << ", Spirit Walker";
	    if (path_feature >= 2)
		cout << ", Aspect of the Beast";
	    if (path_feature >= 3)
		cout << ", Totemic Attunement, ";
	}
	cout << "], ";
    }
    if (relentless_rage)
	cout << "Relentless Rage, ";
    //bards
    if (bardic_inspiration > 0)
	cout << "Bardic Inspiration(d" << bardic_inspiration << "), ";
    if (jack_of_all_trades)
	cout << "Jack of All Trades, ";
    if (song_of_rest > 0)
	cout << "Song of Rest(d" << song_of_rest << "), ";
    if (bard_college)
    {
	cout << "Bard College[";
	if (college_of_lore)
	{
	    cout << "3 Bonus Skills, Cutting Words";
	    if (bard_college_feature >= 1)
		cout << ", Additional Magical Secrets";
	    if (bard_college_feature == 2)
		cout << ", Peerless Skill";
	}
	else
	{
	    cout << "Med Armor, Shields, Martial Weapons, Combat Inspirtation";
	    if (bard_college_feature >= 1)
		cout << ", Extra Attack";
	    if (bard_college_feature == 2)
		cout << ", Battle Magic";
	}
	cout << "], ";
    }
    if (font_of_inspiration)
	cout << "Font of Inspiration, ";
    if (countercharm)
	cout << "Countercharm, ";
    if (magical_secrets > 0)
	cout << "Magical Secrets(" << magical_secrets << "), ";
    if (superior_inspiration)
	cout << "Superior Inspiration, ";
    //clerics
    if (divine_domain)
    {
	cout << "Divine Domain(";
	if (arcana_d)
	    cout << "Arcana), ";
	if (death_d)
	    cout << "Death), ";
	if (knowledge_d)
	    cout << "Knowledge), ";
	if (life_d)
	    cout << "Life), ";
	if (light_d)
	    cout << "Light), ";
	if (nature_d)
	    cout << "Nature), ";
	if (tempest_d)
	    cout << "Tempest), ";
	if (trickery_d)
	    cout << "Trickery), ";
	if (war_d)
	    cout << "War), ";
    }
    if (divine_domain_feature > 0)
    {
	cout << "Domain Features[";
	if (arcana_d)
	{
	    cout << "Arcane Initiate";
	    if (divine_domain_feature >= 1)
		cout << ", Arcane Abjuration";
	    if (divine_domain_feature >= 2)
		cout << ", Spell Breaker";
	    if (divine_domain_feature >= 3)
		cout << ", Potent Spellcasting";
	    if (divine_domain_feature >= 4)
		cout << ", Arcane Mastery";
	}
	else if (death_d)
	{
	    //gain martial weapons
	    cout << "Reaper";
	    if (divine_domain_feature >= 1)
		cout << ", Touch of Death";
	    if (divine_domain_feature >= 2)
		cout << ", Inescapable Destruction";
	    if (divine_domain_feature >= 3)
		cout << ", Divine Strike";
	    if (divine_domain_feature >= 4)
		cout << ", Improved Reaper";
	}
	else if (knowledge_d)
	{
	    //gain blessings of knowledge - gain 2 langs - gain any 2 skills
	    if (divine_domain_feature >= 1)
		cout << "Knowledge of the Ages";
	    if (divine_domain_feature >= 2)
		cout << ", Read Thoughts";
	    if (divine_domain_feature >= 3)
		cout << ", Potent Spellcasting";
	    if (divine_domain_feature >= 4)
		cout << ", Visions of the Past";
	}
	else if (life_d)
	{
	    //gain heavy armor prof
	    cout << "Disciple of Life";
	    if (divine_domain_feature >= 1)
		cout << ", Preserve Life";
	    if (divine_domain_feature >= 2)
		cout << ", Blessed Healer";
	    if (divine_domain_feature >= 3)
		cout << ", Divine Strike";
	    if (divine_domain_feature >= 4)
		cout << ", Supreme Healing";
	}
	else if (light_d)
	{
	    cout << "Light Cantrip, Warding Flare";
	    if (divine_domain_feature >= 1)
		cout << ", Radiance of the Dawn";
	    if (divine_domain_feature >= 2)
		cout << ", Improved Flare";
	    if (divine_domain_feature >= 3)
		cout << ", Potent Spellcasting";
	    if (divine_domain_feature >= 4)
		cout << ", Corona of Light";
	}
	else if (nature_d)
	{
	    //gain 1 skill - heavy armor prof
	    cout << "Druid Cantrip";
	    if (divine_domain_feature >= 1)
		cout << ", Charm Animals & Plants";
	    if (divine_domain_feature >= 2)
		cout << ", Dampen Elements";
	    if (divine_domain_feature >= 3)
		cout << ", Divine Strike";
	    if (divine_domain_feature >= 4)
		cout << ", Master of Nature";
	}
	else if (tempest_d)
	{
	    //gain heavy armor, martial weapons
	    cout << "Wrath of the Storm";
	    if (divine_domain_feature >= 1)
		cout << ", Destructive Wrath";
	    if (divine_domain_feature >= 2)
		cout << ", Thunderbolt Strike";
	    if (divine_domain_feature >= 3)
		cout << ", Divine Strike";
	    if (divine_domain_feature >= 4)
		cout << ", Stormborn";
	}
	else if (trickery_d)
	{
	    cout << "Blessing of the Trickster";
	    if (divine_domain_feature >= 1)
		cout << ", Invoke Duplicity";
	    if (divine_domain_feature >= 2)
		cout << ", Cloak of Shadows";
	    if (divine_domain_feature >= 3)
		cout << ", Divine Strike";
	    if (divine_domain_feature >= 4)
		cout << ", Improved Duplicity";
	}
	else if (war_d)
	{
	    //gain heavy armor, martial weapons
	    cout << "War Priest";
	    if (divine_domain_feature >= 1)
		cout << ", Guided Strike";
	    if (divine_domain_feature >= 2)
		cout << ", War God's Blessing";
	    if (divine_domain_feature >= 3)
		cout << ", Divine Strike";
	    if (divine_domain_feature >= 4)
		cout << ", Avatar of Battle";
	}
	cout << "], ";
    }
    if (channel_divinity > 0)
	cout << "Channel Divinity(" << channel_divinity << "/rest), ";
    if (destroy_undead > 0)
	cout << "Destroy Undead(CR" << destroy_undead << "), ";
    if (divine_intervention > 0)
    {
	if (divine_intervention >= 1)
	    cout << "Divine Intervention";
	if (divine_intervention == 2)
	    cout << " Improved";
	cout << ", ";
    }
    //druids
    if (druidic)
	cout << "Druidic, ";
    if (wild_shape)
	cout << "Wild Shape(CR" << wild_shape_improvement << "), ";
    if (druid_circle)
    {
	cout << "Druid Circle(";
	if (circle_of_the_moon)
	{
	    cout << "Moon)[Combat Wild Shape, Circle Forms";
	    if (druid_circle_feature >= 1)
		cout << ", Primal Strike";
	    if (druid_circle_feature >= 2)
		cout << ", Elemental Wild Shape";
	    if (druid_circle_feature == 3)
		cout << ", Thousand Forms";
	}
	else
	{
	    cout << "Land)[Bonus Cantrip, Natural Recovery, Circle Spells(";
	    landtype();
	    cout << ")";
	    if (druid_circle_feature >= 1)
		cout << ", Land's Stride";
	    if (druid_circle_feature >= 2)
		cout << ", Nature's Ward";
	    if (druid_circle_feature == 3)
		cout << ", Nautre's Sactuary";
	}
	cout << "], ";
    }
    if (beast_spells)
	cout << "Beast Spells, ";
    if (archdruid)
	cout << "Archdruid, ";
    if (fighting_style)
    {
	cout << "Fighting Style(";
	if (archery)
	    cout << "Archery";
	if (defense)
	    cout << "Defense";
	if (dueling)
	    cout << "Dueling";
	if (great_weapon_fighting)
	    cout << "Great Weapon Fighting";
	if (protection)
	    cout << "Protection";
	if (two_weapon_fighting)
	    cout << "Two-Weapon Fighting";
	cout << "), ";
    }
    if (second_wind)
	cout << "Second Wind, ";
    if (martial_archtype)
    {
	cout << "Martial Archetype(";
	if (champion)
	{
	    cout << "Champion)[Improved Critical";
	    if (martial_archtype_feature >= 1)
		cout << ", Remarkable Athlete";
	    if (martial_archtype_feature >= 2)
		cout << ", Additonal Fighting Style";
	    if (martial_archtype_feature >= 3)
		cout << ", Superior Critical";
	    if (martial_archtype_feature >= 4)
		cout << ", Survivor";
	}
	else if (battle_master)
	{
	    cout << "Battle Master)[Combat Superiority";
	    if (martial_archtype_feature >= 1)
		cout << ", Know Your Enemy";
	    if (martial_archtype_feature >= 2)
		cout << ", Improved Combat Superiority(d10)";
	    if (martial_archtype_feature >= 3)
		cout << ", Relentless";
	    if (martial_archtype_feature >= 4)
		cout << ", Improved Combat Superiority(d12)";
	}
	else if (eldritch_knight)
	{
	    cout << "Eldritch Knight)[Spells, Bonded Weapon";
	    if (martial_archtype_feature >= 1)
		cout << ", War Magic";
	    if (martial_archtype_feature >= 2)
		cout << ", Eldritch Strike";
	    if (martial_archtype_feature >= 3)
		cout << ", Arcane Charge";
	    if (martial_archtype_feature >= 4)
		cout << ", Improved War Magic";
	}
	else
	{ //purple dragon knight
	    cout << "Purple Dragon Knight)[Restriction: Knighthood, Rallying Cry";
	    if (martial_archtype_feature >= 1)
		cout << ", Royal Envoy";
	    if (martial_archtype_feature >= 2)
		cout << ", Inspiring Surge";
	    if (martial_archtype_feature >= 3)
		cout << ", Bulwark";
	    if (martial_archtype_feature >= 4)
		cout << ", Final Archtype feature uspecified in Sword Coast Adventurer's Guide book";
	}
	cout << "], ";
    }
    //monk
    if (martial_arts > 0)
	cout << "Martial Arts(1d" << martial_arts << "), ";
    if (ki > 0)
	cout << "Ki Points(" << ki << ")[Flurry of Blows, Patient Defense, Step of the Wind], ";
    if (unarmored_movement > 0)
	cout << "Unarmored Movement(+" << unarmored_movement << "ft), ";
    if (monastic_tradition)
    {
	cout << "Monastic Tradition(";
	if (way_of_the_open_hand)
	{
	    cout << "Way of the Open Hand)[Open Hand Technique";
	    if (monastic_tradition_feature >= 1)
		cout << ", Wholeness of Body";
	    if (monastic_tradition_feature >= 2)
		cout << ", Tranquility";
	    if (monastic_tradition_feature >= 3)
		cout << ", Quivering Palm";
	}
	else if (way_of_the_shadow)
	{
	    cout << "Way of the Shadow)[Shadow Arts";
	    if (monastic_tradition_feature >= 1)
		cout << ", Shadow Step";
	    if (monastic_tradition_feature >= 2)
		cout << ", Cloak of Shadows";
	    if (monastic_tradition_feature >= 3)
		cout << ", Opportunist";
	}
	else if (way_of_the_four_elements)
	{
	    cout << "Way of the Four Elements)[Disciple of the Elements, Elemental Disciplines(Elemental Attunement, Fangs of the Fire Snake, Fist of Four Thunders, Fist of Unbroken Air, Rush of the Gale Spirits, Shape the Flowing River, Sweeping Cinder Strike, Water Whip";
	    if (monastic_tradition_feature >= 1)
		cout << ", Clench of the North Wind, Gong of the Summit";
	    if (monastic_tradition_feature >= 2)
		cout << ", Eternal Mountain Defense, Flames of the Phoenix, Mist Stance, Ride the Wind";
	    if (monastic_tradition_feature >= 3)
		cout << ", Breath of Winter, River of Hungry Flame, Wave of Rolling Earth";
	    cout << ")";
	}
	else if (way_of_the_long_death)
	{
	    cout << "Way of the Long Death)[Touch of Death";
	    if (monastic_tradition_feature >= 1)
		cout << ", Hour of Reaping";
	    if (monastic_tradition_feature >= 2)
		cout << ", Mastery of Death";
	    if (monastic_tradition_feature >= 3)
		cout << ", Touch of thet Long Death";
	}
	else if (way_of_the_sun_soul)
	{
	    cout << "Way of the Sun Soul)[Radiant Sun Bolt";
	    if (monastic_tradition_feature >= 1)
		cout << ", Searing Arc Striket";
	    if (monastic_tradition_feature >= 2)
		cout << ", Searing Sunburst";
	    if (monastic_tradition_feature >= 3)
		cout << ", Sun Shield";
	}
	cout << "], ";
    }
    if (deflect_missles)
	cout << "Deflect Missles, ";
    if (slow_fall)
	cout << "Slow Fall, ";
    if (stunning_strike)
	cout << "Stunning Strike, ";
    if (ki_empowered_strikes)
	cout << "Ki-Empowered Strikes, ";
    if (stillness_of_mind)
	cout << "Stillness of Mind, ";
    if (unarmored_movement_improvement)
	cout << "Vertical Movement, ";
    if (purity_of_body)
	cout << "Purity of Body, ";
    if (tongue_of_the_sun_and_moon)
	cout << "Tongue of the Sun & Moon, ";
    if (diamond_soul)
	cout << "Diamond Soul, ";
    if (empty_body)
	cout << "Empty Body, ";
    if (perfect_self)
	cout << "Perfect Self, ";
    //paladin
    if (divine_sense)
	cout << "Divine Sense, ";
    if (lay_on_hands)
	cout << "Lay on Hands, ";
    if (divine_smite > 0)
    {
	if (divine_smite == 2)
	    cout << "Improved ";
	cout << "Divine Smite, ";
    }
    if (divine_health)
	cout << "Divine Health, ";
    if (sacred_oath)
    {
	if (oath_of_devotion)
	{
	    cout << "Oath of Devotion[Tenets, Oath Spells, Channel Divinity(Sacred Weapon, Turn the Unholy)";
	    if (sacred_oath_feature >= 1)
		cout << ", Aura of Devotion";
	    if (sacred_oath_feature >= 2)
		cout << ", Purity of Spirit";
	    if (sacred_oath_feature == 3)
		cout << ", Holy Nimbus";
	}
	else if (oath_of_ancients)
	{
	    cout << "Oath of the Ancients[Tenets, Oath Spells, Channel Divinity(Nature's Wrath, Turn the Faithless)";
	    if (sacred_oath_feature >= 1)
		cout << ", Aura of Warding";
	    if (sacred_oath_feature >= 2)
		cout << ", Undying Sentinel";
	    if (sacred_oath_feature == 3)
		cout << ", Elder Champion";
	}
	else if (oath_of_vengeance)
	{
	    cout << "Oath of Vengeance[Tenets, Oath Spells, Channel Divinity(Abjure Enemy, Vow of Enmity)";
	    if (sacred_oath_feature >= 1)
		cout << ", Relentless Avenger";
	    if (sacred_oath_feature >= 2)
		cout << ", Soul of Vengeance";
	    if (sacred_oath_feature == 3)
		cout << ", Avenging Angel";
	}
	else if (oathbreaker)
	{
	    cout << "Oathbreaker[Oath Spells, Channel Divinity(Control Undead, Dreadful Aspect)";
	    if (sacred_oath_feature >= 1)
		cout << ", Aura of Hate";
	    if (sacred_oath_feature >= 2)
		cout << ", Supernatural Resistance";
	    if (sacred_oath_feature == 3)
		cout << ", Dread Lord";
	}
	else
	{ //oath of the crown
	    cout << "Oath of the Crown(Tenets, Oath Spells, Channel Divinity(Champion Challenge, Turn the Tide)";
	    if (sacred_oath_feature >= 1)
		cout << ", Divine Allegiance";
	    if (sacred_oath_feature >= 2)
		cout << ", Unyielding Spirit";
	    if (sacred_oath_feature == 3)
		cout << ", Exalted Champion";
	}
	cout << "], ";
    }
    if (aura_of_protection)
	cout << "Aura of Protection, ";
    if (aura_of_courage)
	cout << "Aura of Courage, ";
    if (cleansing_touch)
	cout << "Cleansing Touch, ";
    if (aura_improvments)
	cout << "Aura Improvements, ";
    //ranger
    if (favored_enemy > 0)
    {
	cout << "Favored Enemy[";
	creaturetype();
	cout << "], ";
    }
    if (favored_enemy_languages)
	cout << "Favored Enemy Languages, ";
    if (natural_explorer > 0)
    {
	cout << "Natural Explorer[";
	landtype();
	cout << "], ";
    }
    if (ranger_archetype)
    {
	cout << "Ranger Archetype(";
	if (hunter)
	{
	    cout << "Hunter)[Hunter's Prey";
	    if (ranger_archetype_feature >= 1)
		cout << ", Defensive Tactics";
	    if (ranger_archetype_feature >= 2)
		cout << ", Multiattack";
	    if (ranger_archetype_feature == 3)
		cout << ", Superior Hunter's Defense";
	}
	else if (beast_master)
	{
	    cout << "Beast Master)[Ranger's Companion";
	    if (ranger_archetype_feature >= 1)
		cout << ", Exceptional Training";
	    if (ranger_archetype_feature >= 2)
		cout << ", Bestial Fury";
	    if (ranger_archetype_feature == 3)
		cout << ", Share Spells";
	}
	cout << "], ";
    }
    if (primeval_awareness)
	cout << "Primeval Awareness, ";
    if (lands_stride)
	cout << "Land's Stride, ";
    if (hide_in_plain_sight)
	cout << "Hide in Plain Sight, ";
    if (feral_senses)
	cout << "Feral Senses, ";
    if (foe_slayer)
	cout << "Foe Slayer, ";
    //rogue
    if (sneak_attack)
	cout << "Sneak Attack, ";
    if (thieves_cant)
	cout << "Thieves' Cant, ";
    if (cunning_action)
	cout << "Cunning Action, ";
    if (roguish_archetype)
    {
	cout << "Roguish Archetype(";
	if (thief)
	{
	    cout << "Thief)[Fast Hands, Second-Story Work";
	    if (roguish_archetype_feature > 0)
		cout << ", Supreme Sneak";
	    if (roguish_archetype_feature > 1)
		cout << ", Use Magic Device";
	    if (roguish_archetype_feature > 2)
		cout << ", Thief's Reflexes";
	}
	else if (assassin)
	{
	    cout << "Assassin)[Assassinate";
	    if (roguish_archetype_feature > 0)
		cout << ", Infiltration Expertise";
	    if (roguish_archetype_feature > 1)
		cout << ", Impostor";
	    if (roguish_archetype_feature > 2)
		cout << ", Death Strike";
	}
	else if (arcane_trickster)
	{
	    cout << "Arcane Trickster)[Spellcasting, Mage Hand Legerdemain";
	    if (roguish_archetype_feature > 0)
		cout << ", Magical Ambush";
	    if (roguish_archetype_feature > 1)
		cout << ", Versatile Trickerster";
	    if (roguish_archetype_feature > 2)
		cout << ", Spell Theif";
	}
	else if (mastermind)
	{
	    cout << "Mastermind)[Master of Intrigue, Master of Tactics";
	    if (roguish_archetype_feature > 0)
		cout << ", Insightful Manipulation";
	    if (roguish_archetype_feature > 1)
		cout << ", Misdirection";
	    if (roguish_archetype_feature > 2)
		cout << ", Soul of Deceit";
	}
	else
	{ //swashbuckler
	    cout << "Swashbuckler)[Fancy Footwork, Rakish Audacity";
	    if (roguish_archetype_feature > 0)
		cout << ", Panache";
	    if (roguish_archetype_feature > 1)
		cout << ", Elegant Maneuver";
	    if (roguish_archetype_feature > 2)
		cout << ", Master Duelist";
	}
	cout << "], ";
    }
    if (uncanny_dodge)
	cout << "Uncanny Dodge, ";
    if (reliable_talent)
	cout << "Reliable Talent, ";
    if (blindsense)
	cout << "Blindsense, ";
    if (slippery_mind)
	cout << "Slippery Mind, ";
    if (elusive)
	cout << "Elusive, ";
    if (stroke_of_luck)
	cout << "Stroke of Luck, ";
    //sorcerer
    if (sorcerous_origin)
    {
	cout << "Sorcerous Origin(";
	if (draconic_bloodline)
	{
	    cout << "Draconic Bloodline)[Draconic Resilience";
	    if (sorcerous_origin_feature >= 1)
		cout << ", Elemental Affinity";
	    if (sorcerous_origin_feature >= 2)
		cout << ", Draconic Wings";
	    if (sorcerous_origin_feature == 3)
		cout << ", Draconic Presence";
	}
	else if (wild_magic)
	{
	    cout << "Wild Magic)[Surge, Tides of Chaos";
	    if (sorcerous_origin_feature >= 1)
		cout << ", Bend Luck";
	    if (sorcerous_origin_feature >= 2)
		cout << ", Controlled Chaos";
	    if (sorcerous_origin_feature == 3)
		cout << ", Spell Bombardment";
	}
	else
	{ //storm sorcery
	    cout << "Storm Sorcery)[Wind Speaker, Tempestuous Magic";
	    if (sorcerous_origin_feature >= 1)
		cout << ", Heart of the Storm, Storm Guide";
	    if (sorcerous_origin_feature >= 2)
		cout << ", Storm's Fury";
	    if (sorcerous_origin_feature == 3)
		cout << ", Wind Soul";
	}
	cout << "], ";
    }
    if (font_of_magic)
	cout << "Font of Magic, ";
    if (sorcery_points > 0)
	cout << "Sorcery Points(" << sorcery_points << "), ";
    if (metamagic > 0)
    {
	if (metamagic == 1)
	    cout << "Metamagic(2), ";
	if (metamagic == 2)
	    cout << "Metamagic(3), ";
	if (metamagic == 3)
	    cout << "Metamagic(4), ";
    }
    if (sorcerous_restoration)
	cout << "Sorcerous Restoration, ";
    //warlock
    if (otherworldly_patron)
    {
	cout << "Otherworldly Patron(";
	if (archfey)
	{
	    cout << "Archfey)[Expanded Spell List, Fey Presence";
	    if (otherworldly_patron_feature >= 1)
		cout << ", Misty Escape";
	    if (otherworldly_patron_feature >= 2)
		cout << ", Beguiling Defenses";
	    if (otherworldly_patron_feature == 3)
		cout << ", Dark Delrium";
	}
	else if (fiend)
	{
	    cout << "The Fiend)[Expanded Spell List, Dark One's Blessing";
	    if (otherworldly_patron_feature >= 1)
		cout << ", Dark One’s Own Luck";
	    if (otherworldly_patron_feature >= 2)
		cout << ", Fiendish Resilience";
	    if (otherworldly_patron_feature == 3)
		cout << ", Hurl Through Hell";
	}
	else if (great_old_one)
	{
	    cout << "Great Old One)[Expanded Spell List, Awakened Mind";
	    if (otherworldly_patron_feature >= 1)
		cout << ", Entropic Ward";
	    if (otherworldly_patron_feature >= 2)
		cout << ", Thought Shield";
	    if (otherworldly_patron_feature == 3)
		cout << ", Create Thrall";
	}
	else
	{ //the_undying
	    cout << "The Undying)[Expanded Spell List, Among the Dead";
	    if (otherworldly_patron_feature >= 1)
		cout << ", Defy Death";
	    if (otherworldly_patron_feature >= 2)
		cout << ", Undying Nature";
	    if (otherworldly_patron_feature == 3)
		cout << ", Indestructable Life";
	}
	cout << "], ";
    }
    if (pact_magic)
	cout << "Pact Magic, ";
    if (pact_boon)
	cout << "Pact Boon, ";
    if (eldritch_master)
	cout << "Eldritch Master, ";
    //wizard
    if (arcane_recovery)
	cout << "Arcane Recovery, ";
    if (arcane_tradition)
    {
	cout << "Arcane Tradition(";
	if (abjuration)
	{
	    cout << "Abjurer)[Savant, Arcane Ward";
	    if (arcane_tradition_feature >= 1)
		cout << ", Projected Ward";
	    if (arcane_tradition_feature >= 2)
		cout << ", Improved Abjuration";
	    if (arcane_tradition_feature == 3)
		cout << ", Spell Resistance";
	}
	else if (conjuration)
	{
	    cout << "Conjurer[Savant, Minor Conjuration";
	    if (arcane_tradition_feature >= 1)
		cout << ", Benign Transposition";
	    if (arcane_tradition_feature >= 2)
		cout << ", Focused Conjuration";
	    if (arcane_tradition_feature == 3)
		cout << ", Durable Summons";
	}
	else if (divination)
	{
	    cout << "Diviner[Savant, Portent";
	    if (arcane_tradition_feature >= 1)
		cout << ", Expert Divination";
	    if (arcane_tradition_feature >= 2)
		cout << ", Third Eye";
	    if (arcane_tradition_feature == 3)
		cout << ", Greater Portent";
	}
	else if (enchantment)
	{
	    cout << "Enchanter[Savant, Hypnotic Gaze";
	    if (arcane_tradition_feature >= 1)
		cout << ", Instinctive Charm";
	    if (arcane_tradition_feature >= 2)
		cout << ", Split Enchantment";
	    if (arcane_tradition_feature == 3)
		cout << ", Alter Memories";
	}
	else if (evocation)
	{
	    cout << "Evoker[Savant, Sculpt Spells";
	    if (arcane_tradition_feature >= 1)
		cout << ", Potent Cantrip";
	    if (arcane_tradition_feature >= 2)
		cout << ", Empowered Evocation";
	    if (arcane_tradition_feature == 3)
		cout << ", Overchannel";
	}
	else if (illusion)
	{
	    cout << "Illusionist[Savant, Improved Minor Illusion";
	    if (arcane_tradition_feature >= 1)
		cout << ", Malleable Illusions";
	    if (arcane_tradition_feature >= 2)
		cout << ", Illusory Self";
	    if (arcane_tradition_feature == 3)
		cout << ", Illusory Reality";
	}
	else if (necromancy)
	{
	    cout << "Necromancer[Savant, Grim Harvest";
	    if (arcane_tradition_feature >= 1)
		cout << ", Undead Thralls";
	    if (arcane_tradition_feature >= 2)
		cout << ", Inured to Undeath";
	    if (arcane_tradition_feature == 3)
		cout << ", Command Undead";
	}
	else if (transmutation)
	{
	    cout << "Tranmuter[Savant, Minor Alchemy";
	    if (arcane_tradition_feature >= 1)
		cout << ", Transmuter's Stone";
	    if (arcane_tradition_feature >= 2)
		cout << ", Shapechanger";
	    if (arcane_tradition_feature == 3)
		cout << ", Master Transmuter";
	}
	else
	{ // bladesinging
	    cout << "Bladesinger[Training in War or Song, Blade Song";
	    if (arcane_tradition_feature >= 1)
		cout << ", Extra Attack";
	    if (arcane_tradition_feature >= 2)
		cout << ", Song of Defense";
	    if (arcane_tradition_feature == 3)
		cout << ", Song of Victory";
	}
	cout << "], ";
    }
    if (spell_mastery)
	cout << "Spell Mastery, ";
    if (signature_spell)
	cout << "Signature Spell, ";
    cout << endl;
}
void Generic_Character_Class::printSpellSlots() const
{
    if (spellcasting || pact_magic)
    {
	cout << "->" << MAGENTA << " Cantrips: " << RESET;
	if (bard_cantrips_known > 0)
	    cout << "Bard(" << bard_cantrips_known << ")";
	if (cleric_cantrips_known > 0)
	    cout << "Cleric(" << cleric_cantrips_known << ")";
	if (druid_cantrips_known > 0)
	    cout << "Druid(" << druid_cantrips_known << ")";
	if (wizard_cantrips_known > 0)
	    cout << "Wizard(" << wizard_cantrips_known << ")";
	if (sorcerer_cantrips_known > 0)
	    cout << "Sorcerer(" << sorcerer_cantrips_known << ")";
	if (warlock_cantrips_known > 0)
	    cout << "Warlock(" << warlock_cantrips_known << ")";
	cout << "\n->" << MAGENTA << " Spell Slots: " << RESET;
	if (warlock_slot_level > 0)
	    cout << "Warlock Slot Level(" << warlock_slot_level << ")";
	if (first_ss > 0)
	    cout << first_ss;
	if (second_ss > 0)
	    cout << "/" << second_ss;
	if (third_ss > 0)
	    cout << "/" << third_ss;
	if (forth_ss > 0)
	    cout << "/" << forth_ss;
	if (fifth_ss > 0)
	    cout << "/" << fifth_ss;
	if (sixth_ss > 0)
	    cout << "/" << sixth_ss;
	if (seventh_ss > 0)
	    cout << "/" << seventh_ss;
	if (eighth_ss > 0)
	    cout << "/" << eighth_ss;
	if (ninth_ss > 0)
	    cout << "/" << ninth_ss;
	cout << "\n->" << MAGENTA << " Spells Known: " << RESET;
	if (bard_spells_known > 0)
	    cout << "Bard(" << bard_spells_known << ")";
	if (eldritch_spells_known > 0)
	    cout << "Eldritch Knight(" << eldritch_spells_known << ")";
	if (ranger_spells_known > 0)
	    cout << "Ranger(" << ranger_spells_known << ")";
	if (arcane_t_spells_known > 0)
	    cout << "Arcane Trickster(" << arcane_t_spells_known << ")";
	if (sorcerer_spells_known > 0)
	    cout << "Sorcerer(" << sorcerer_spells_known << ")";
	if (warlock_spells_known > 0)
	    cout << "Warlock(" << warlock_spells_known << ")";
	if (eldritch_invocations_known > 0)
	    cout << ", Eldritch Invocations(" << eldritch_invocations_known << "), ";
	if (mystic_arcanum >= 6)
	{
	    cout << "Mystic Arcanum[6th";
	    if (mystic_arcanum >= 7)
		cout << ", 7th";
	    if (mystic_arcanum >= 8)
		cout << ", 8th";
	    if (mystic_arcanum >= 9)
		cout << ", 9th";
	    cout << "], ";
	}
	cout << endl;
    }
}
void Generic_Character_Class::printSkills() const
{
    cout << "->" << CYAN << " Skills: " << RESET;
    if (acrobatics)
	cout << "Acrobatics, ";
    if (animal_handling)
	cout << "Animal Handling, ";
    if (arcana)
	cout << "Arcana, ";
    if (athletics)
	cout << "Athletics, ";
    if (deception)
	cout << "Deception, ";
    if (history)
	cout << "History, ";
    if (insight)
	cout << "Insight, ";
    if (intimidation)
	cout << "Intimidation, ";
    if (investigation)
	cout << "Investigation, ";
    if (medicine)
	cout << "Medicine, ";
    if (nature)
	cout << "Nature, ";
    if (perception)
	cout << "Perception, ";
    if (performance)
	cout << "Performance, ";
    if (persuasion)
	cout << "Persuasion, ";
    if (religion)
	cout << "Religion, ";
    if (sleight_of_hand)
	cout << "Sleight of Hand, ";
    if (stealth)
	cout << "Stealth, ";
    if (survival)
	cout << "Survival";
    cout << endl;
}
void Generic_Character_Class::printFeats() const
{
    cout << "->" << GREEN << " Feats: " << RESET;
    if (alert)
	cout << "Alert, ";
    if (athlete)
	cout << "Athlete, ";
    if (actor)
	cout << "Actor, ";
    if (charger)
	cout << "Charger, ";
    if (crossbow_expert)
	cout << "Crossbow Expert, ";
    if (defensive_duelist)
	cout << "Defensive Duelist, ";
    if (dual_wielder)
	cout << "Dual Wielder, ";
    if (dungeon_delver)
	cout << "Dungeon Delver, ";
    if (durable)
	cout << "Durable, ";
    if (elemental_adept)
	cout << "Elemental Adept, ";
    if (grappler)
	cout << "Grappler, ";
    if (great_weapon_master)
	cout << "Great Weapon Master, ";
    if (healer)
	cout << "Healer, ";
    if (heavily_armored)
	cout << "Heavily Armored, ";
    if (heavy_armor_master)
	cout << "Heavy Armor Master, ";
    if (inspiring_leader)
	cout << "Inspiring Leader, ";
    if (keen_mind)
	cout << "Keen Mind, ";
    if (lightly_armored)
	cout << "Lightly Armored, ";
    if (linguist)
	cout << "Linguist, ";
    if (lucky)
	cout << "Lucky, ";
    if (mage_slayer)
	cout << "Mage Slayer, ";
    if (magic_initiate)
	cout << "Magic Initiate, ";
    if (martial_adept)
	cout << "Martial Adept, ";
    if (medium_armor_master)
	cout << "Medium Armor Master, ";
    if (mobile)
	cout << "Mobile, ";
    if (moderately_armored)
	cout << "Moderately Armored, ";
    if (mounted_combatant)
	cout << "Mounted Combatant, ";
    if (observant)
	cout << "Observant, ";
    if (polearm_master)
	cout << "Polearm Master, ";
    if (resilient)
	cout << "Resilient, ";
    if (ritual_caster)
	cout << "Ritual Caster, ";
    if (savage_attacker)
	cout << "Savage Attacker, ";
    if (sentinel)
	cout << "Sentinel, ";
    if (sharpshooter)
	cout << "Sharpshooter, ";
    if (shield_master)
	cout << "Shield Master, ";
    if (skilled)
	cout << "Skilled, ";
    if (skulker)
	cout << "Skulker, ";
    if (spell_sniper)
	cout << "Spell Sniper, ";
    if (tavern_brawler)
	cout << "Tavern Brawler, ";
    if (tough)
	cout << "Tough, ";
    if (war_caster)
	cout << "War Caster, ";
    if (weapon_master)
	cout << "Weapon Master.";
    cout << endl;
}
void Generic_Character_Class::printOtherAbilities() const
{
    cout << "->" << CYAN << " Other Abilities: " << RESET;
    if (artificers_lore)
	cout << "Artificer's Lore, ";
    if (brave)
	cout << "Brave, ";
    if (breath_weapon_acid)
	cout << "Acid Breath Weapon, ";
    if (breath_weapon_cold)
	cout << "Cold Breath Weapon, ";
    if (breath_weapon_fire)
	cout << "Fire Breath Weapon, ";
    if (breath_weapon_ltg)
	cout << "Lighting Breath Weapon, ";
    if (breath_weapon_poison)
	cout << "Poison Breath Weapon, ";
    if (darkvision)
	cout << "Darkvision, ";
    if (draconic_ancestry_black)
	cout << "Draconic Ancestry(black), ";
    if (draconic_ancestry_blue)
	cout << "Draconic Ancestry(blue), ";
    if (draconic_ancestry_brass)
	cout << "Draconic Ancestry(brass), ";
    if (draconic_ancestry_bronze)
	cout << "Draconic Ancestry(bronze), ";
    if (draconic_ancestry_copper)
	cout << "Draconic Ancestry(copper), ";
    if (draconic_ancestry_gold)
	cout << "Draconic Ancestry(gold), ";
    if (draconic_ancestry_green)
	cout << "Draconic Ancestry(green), ";
    if (draconic_ancestry_red)
	cout << "Draconic Ancestry(red), ";
    if (draconic_ancestry_silver)
	cout << "Draconic Ancestry(silver), ";
    if (draconic_ancestry_white)
	cout << "Draconic Ancestry(white), ";
    if (drow_magic)
	cout << "Drow Magic, ";
    if (drow_weapon_training)
	cout << "Drow Weapon Training, ";
    if (dwarven_armor_training)
	cout << "Dwarven Armor Training, ";
    if (dwarven_combat_training)
	cout << "Dwarven Combat Training, ";
    if (dwarven_resilience)
	cout << "Dwarven Resilience, ";
    if (dwarven_toughness)
	cout << "Dwarven Toughness, ";
    if (elf_weapon_training)
	cout << "Elf Weapon Training, ";
    if (fey_ancestry)
	cout << "Fey Ancestry, ";
    if (fleet_of_foot)
	cout << "Fleet of Foot, ";
    if (halflinglucky)
	cout << "Lucky(halfling), ";
    if (halfling_nimbleness)
	cout << "Halfling Nimbleness, ";
    if (hellish_resistance)
	cout << "Hellish Resistance, ";
    if (infernal_legacy)
	cout << "Infernal Legacy, ";
    if (mask_of_the_wild)
	cout << "Mask of the Wild, ";
    if (natural_illusionist)
	cout << "Natural Illusionist, ";
    if (naturally_stealthy)
	cout << "Naturally Stealthy, ";
    if (speak_with_small_beasts)
	cout << "Speak With Small Beasts, ";
    if (stonecunning)
	cout << "Stonecunning, ";
    if (stout_resilience)
	cout << "Stout Resilience, ";
    if (superior_darkvision)
	cout << "Superior Darkvision, ";
    if (trance)
	cout << "Trance, ";
    cout << endl;
}
void Generic_Character_Class::printLangs() const
{
    cout << "->" << CYAN << " Languages: " << RESET;
    if (abyssal)
	cout << "Abyssal, ";
    if (celestial)
	cout << "Celestial, ";
    if (common)
	cout << "Common, ";
    if (deep_speech)
	cout << "Deep Speech, ";
    if (draconic)
	cout << "Draconic, ";
    if (druidic)
	cout << "Druidic, ";
    if (dwarvish)
	cout << "Dwarvish, ";
    if (elvish)
	cout << "Elvish, ";
    if (giant)
	cout << "Giant, ";
    if (gnomish)
	cout << "Gnomish, ";
    if (goblin)
	cout << "Goblin, ";
    if (gnoll)
	cout << "Gnoll, ";
    if (halfling)
	cout << "Halfling, ";
    if (infernal)
	cout << "Infernal, ";
    if (orc)
	cout << "Orc, ";
    if (primordial)
	cout << "Primordial, ";
    if (sylvan)
	cout << "Sylvan, ";
    if (undercommon)
	cout << "Undercommon.";
    cout << endl;
}
void Generic_Character_Class::printToolsInstruments() const
{
    cout << "->" << CYAN << " Artisan's Tools: " << RESET;
    if (alchemist)
	cout << "Alchemist's supplies, ";
    if (brewer)
	cout << "Brewer's supplies, ";
    if (calligrapher)
	cout << "Calligrapher's supplies, ";
    if (carpenter)
	cout << "Carpenter's tools, ";
    if (cartographer)
	cout << "Cartographer's tools, ";
    if (cobbler)
	cout << "Cobbler's tools, ";
    if (cook)
	cout << "Cook's utensils, ";
    if (glassblower)
	cout << "Glassblower's tools, ";
    if (jeweler)
	cout << "Jeweler's tools, ";
    if (leatherworker)
	cout << "Leatherwoker's tools, ";
    if (mason)
	cout << "Mason's tools, ";
    if (painter)
	cout << "Painter's supplies, ";
    if (potter)
	cout << "Potter's tools, ";
    if (smith)
	cout << "Smith's tools, ";
    if (tinker)
	cout << "Tinker's tools, ";
    if (weaver)
	cout << "Weaver's tools, ";
    if (woodcarver)
	cout << "Woodcarver's tools.";
    cout << endl;
    cout << "->" << CYAN << " Other Kits and Tools: " << RESET;
    if (disguise)
	cout << "Disguise kit, ";
    if (forgery)
	cout << "Forgery kit, ";
    if (herbalism)
	cout << "Herbalism kit, ";
    if (navigator)
	cout << "Navigator's tools, ";
    if (poisoner)
	cout << "Poisoner's kit, ";
    if (thieves)
	cout << "Thieves' tools, ";
    if (vehicle)
	cout << "Vehicle(land or water).";
    cout << endl;
    cout << "->" << CYAN << " Musical Instrument(s): " << RESET;
    if (bagpipes)
	cout << "Bagpipes, ";
    if (drum)
	cout << "Drums, ";
    if (dulcimer)
	cout << "Dulcimer, ";
    if (flute)
	cout << "Flute, ";
    if (lute)
	cout << "Lute, ";
    if (lyre)
	cout << "Lyre, ";
    if (horn)
	cout << "Horn, ";
    if (pan_flute)
	cout << "Pan flute, ";
    if (shawm)
	cout << "Shawm, ";
    if (viol)
	cout << "Viol.";
    cout << endl;
}
void Generic_Character_Class::printResistances() const
{
    cout << "->" << GREEN << " Resistances: " << RESET;
    if (damage_resist_acid)
	cout << "Acid, ";
    if (damage_resist_ltg)
	cout << "Lightning, ";
    if (damage_resist_fire)
	cout << "Fire, ";
    if (damage_resist_poison)
	cout << "Poison, ";
    if (damage_resist_cold)
	cout << "Cold";
    cout << endl;
}
void Generic_Character_Class::printDisadvantages() const
{
    cout << "->" << RED << " Disadvantages: " << RESET;
    if (sunlight_sensitivity)
	cout << "Sunlight Sensitivty" << endl;
}
