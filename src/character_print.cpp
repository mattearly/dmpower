#include "characters.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

void Generic_Character_Class::character_sheet() const
{
  simpleClearScreen();
  cout << " " << char_name << "'s Character Sheet:\n";
  cout << "->" << GREEN << " Class(Level): " << RESET << char_class << "(" << level << ")\n";
  cout << "->" << GREEN << " Alignment: " << RESET << alignment << "\n";
  cout << "->" << GREEN << " Race: " << RESET << race << "\n";
  cout << "->" << GREEN << " Background: " << RESET << getBackground() << "\n";
  cout << "->" << GREEN << " Hit Dice: " << RESET << level << "d" << hitdicesize
       << "(Ave NPC HP: " << ((((hitdicesize + 2) / 2)) * level) + (getAbilityMod(constitution) * level)
       << " Ave PC HP: " << hitdicesize + ((((hitdicesize + 2) / 2)) * (level - 1)) + (getAbilityMod(constitution) * level)
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
  cout << endl;
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
  if (barbarian_attr.brutal_critical > 0)
    cout << "Brutal Critical(" << barbarian_attr.brutal_critical << " dice), ";
  if (barbarian_attr.danger_sense)
    cout << "Danger Sense, ";
  if (barbarian_attr.fast_movement)
    cout << "Fast Movement(+10), ";
  if (barbarian_attr.feral_instinct)
    cout << "Feral Instinct, ";
  if (barbarian_attr.indomitable_might)
    cout << "Indomintable Might, ";
  if (barbarian_attr.persistant_rage)
    cout << "Persistant Rage, ";
  if (barbarian_attr.primal_champion)
    cout << "Primal Champion, ";
  if (barbarian_attr.rage_damage > 0)
    cout << "Rage Damage(+" << barbarian_attr.rage_damage << "), ";
  if (barbarian_attr.rages > 0)
    cout << "Rage(" << barbarian_attr.rages << "/day), ";
  if (barbarian_attr.reckless_attack)
    cout << "Reckless Attack, ";
  if (barbarian_attr.primal_path)
  {
    if (barbarian_attr.path_of_the_battlerager)
    {
      cout << "Path of the Battlerager[Battlerager Armor";
      if (barbarian_attr.path_feature >= 1)
        cout << ", Reckless Abandon";
      if (barbarian_attr.path_feature >= 2)
        cout << ", Battlerager Charge";
      if (barbarian_attr.path_feature >= 3)
        cout << ", Spiked Retribution";
    }
    else if (barbarian_attr.path_of_the_berseker)
    {
      cout << "Path of the Berserker[Frenzy";
      if (barbarian_attr.path_feature >= 1)
        cout << ", Mindless Rage";
      if (barbarian_attr.path_feature >= 2)
        cout << ", Intimidating Prescense";
      if (barbarian_attr.path_feature >= 3)
        cout << ", Retaliation";
    }
    else
    {
      cout << "Path of the Totem Warrior";
      if (barbarian_attr.bear_totem)
        cout << "(Bear)";
      if (barbarian_attr.eagle_totem)
        cout << "(Eagle)";
      if (barbarian_attr.wolf_totem)
        cout << "(Wolf)";
      cout << "[Spirit Seeker, Totem Spirit";
      if (barbarian_attr.path_feature >= 1)
        cout << ", Spirit Walker";
      if (barbarian_attr.path_feature >= 2)
        cout << ", Aspect of the Beast";
      if (barbarian_attr.path_feature >= 3)
        cout << ", Totemic Attunement, ";
    }
    cout << "], ";
  }
  if (barbarian_attr.relentless_rage)
    cout << "Relentless Rage, ";
  //bards
  if (bard_attr.bardic_inspiration > 0)
    cout << "Bardic Inspiration(d" << bard_attr.bardic_inspiration << "), ";
  if (bard_attr.jack_of_all_trades)
    cout << "Jack of All Trades, ";
  if (bard_attr.song_of_rest > 0)
    cout << "Song of Rest(d" << bard_attr.song_of_rest << "), ";
  if (bard_attr.bard_college)
  {
    cout << "Bard College[";
    if (bard_attr.college_of_lore)
    {
      cout << "3 Bonus Skills, Cutting Words";
      if (bard_attr.bard_college_feature >= 1)
        cout << ", Additional Magical Secrets";
      if (bard_attr.bard_college_feature == 2)
        cout << ", Peerless Skill";
    }
    else
    {
      cout << "Med Armor, Shields, Martial Weapons, Combat Inspirtation";
      if (bard_attr.bard_college_feature >= 1)
        cout << ", Extra Attack";
      if (bard_attr.bard_college_feature == 2)
        cout << ", Battle Magic";
    }
    cout << "], ";
  }
  if (bard_attr.font_of_inspiration)
    cout << "Font of Inspiration, ";
  if (bard_attr.countercharm)
    cout << "Countercharm, ";
  if (bard_attr.magical_secrets > 0)
    cout << "Magical Secrets(" << bard_attr.magical_secrets << "), ";
  if (bard_attr.superior_inspiration)
    cout << "Superior Inspiration, ";
  //clerics
  if (cleric_attr.divine_domain)
  {
    cout << "Divine Domain(";
    if (cleric_attr.arcana_d)
      cout << "Arcana), ";
    if (cleric_attr.death_d)
      cout << "Death), ";
    if (cleric_attr.knowledge_d)
      cout << "Knowledge), ";
    if (cleric_attr.life_d)
      cout << "Life), ";
    if (cleric_attr.light_d)
      cout << "Light), ";
    if (cleric_attr.nature_d)
      cout << "Nature), ";
    if (cleric_attr.tempest_d)
      cout << "Tempest), ";
    if (cleric_attr.trickery_d)
      cout << "Trickery), ";
    if (cleric_attr.war_d)
      cout << "War), ";
  }
  if (cleric_attr.divine_domain_feature > 0)
  {
    cout << "Domain Features[";
    if (cleric_attr.arcana_d)
    {
      cout << "Arcane Initiate";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Arcane Abjuration";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Spell Breaker";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Potent Spellcasting";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Arcane Mastery";
    }
    else if (cleric_attr.death_d)
    {
      //gain martial weapons
      cout << "Reaper";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Touch of Death";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Inescapable Destruction";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Divine Strike";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Improved Reaper";
    }
    else if (cleric_attr.knowledge_d)
    {
      //gain blessings of knowledge - gain 2 langs - gain any 2 skills
      if (cleric_attr.divine_domain_feature >= 1)
        cout << "Knowledge of the Ages";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Read Thoughts";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Potent Spellcasting";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Visions of the Past";
    }
    else if (cleric_attr.life_d)
    {
      //gain heavy armor prof
      cout << "Disciple of Life";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Preserve Life";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Blessed Healer";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Divine Strike";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Supreme Healing";
    }
    else if (cleric_attr.light_d)
    {
      cout << "Light Cantrip, Warding Flare";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Radiance of the Dawn";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Improved Flare";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Potent Spellcasting";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Corona of Light";
    }
    else if (cleric_attr.nature_d)
    {
      //gain 1 skill - heavy armor prof
      cout << "Druid Cantrip";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Charm Animals & Plants";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Dampen Elements";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Divine Strike";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Master of Nature";
    }
    else if (cleric_attr.tempest_d)
    {
      //gain heavy armor, martial weapons
      cout << "Wrath of the Storm";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Destructive Wrath";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Thunderbolt Strike";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Divine Strike";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Stormborn";
    }
    else if (cleric_attr.trickery_d)
    {
      cout << "Blessing of the Trickster";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Invoke Duplicity";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", Cloak of Shadows";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Divine Strike";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Improved Duplicity";
    }
    else if (cleric_attr.war_d)
    {
      //gain heavy armor, martial weapons
      cout << "War Priest";
      if (cleric_attr.divine_domain_feature >= 1)
        cout << ", Guided Strike";
      if (cleric_attr.divine_domain_feature >= 2)
        cout << ", War God's Blessing";
      if (cleric_attr.divine_domain_feature >= 3)
        cout << ", Divine Strike";
      if (cleric_attr.divine_domain_feature >= 4)
        cout << ", Avatar of Battle";
    }
    cout << "], ";
  }
  if (cleric_attr.channel_divinity > 0)
    cout << "Channel Divinity(" << cleric_attr.channel_divinity << "/rest), ";
  if (cleric_attr.destroy_undead > 0)
    cout << "Destroy Undead(CR" << cleric_attr.destroy_undead << "), ";
  if (cleric_attr.divine_intervention > 0)
  {
    if (cleric_attr.divine_intervention >= 1)
      cout << "Divine Intervention";
    if (cleric_attr.divine_intervention == 2)
      cout << " Improved";
    cout << ", ";
  }
  //druids
  if (druid_attr.wild_shape)
    cout << "Wild Shape(CR" << druid_attr.wild_shape_improvement << "), ";
  if (druid_attr.druid_circle)
  {
    cout << "Druid Circle(";
    if (druid_attr.circle_of_the_moon)
    {
      cout << "Moon)[Combat Wild Shape, Circle Forms";
      if (druid_attr.druid_circle_feature >= 1)
        cout << ", Primal Strike";
      if (druid_attr.druid_circle_feature >= 2)
        cout << ", Elemental Wild Shape";
      if (druid_attr.druid_circle_feature == 3)
        cout << ", Thousand Forms";
    }
    else
    {
      cout << "Land)[Bonus Cantrip, Natural Recovery, Circle Spells(";
      landtype();
      cout << ")";
      if (druid_attr.druid_circle_feature >= 1)
        cout << ", Land's Stride";
      if (druid_attr.druid_circle_feature >= 2)
        cout << ", Nature's Ward";
      if (druid_attr.druid_circle_feature == 3)
        cout << ", Nautre's Sactuary";
    }
    cout << "], ";
  }
  if (druid_attr.beast_spells)
    cout << "Beast Spells, ";
  if (druid_attr.archdruid)
    cout << "Archdruid, ";
  if (fighting_style)
  {
    cout << "Fighting Style(";
    if (fighter_attr.archery)
      cout << "Archery";
    if (defense)
      cout << "Defense";
    if (dueling)
      cout << "Dueling";
    if (great_weapon_fighting)
      cout << "Great Weapon Fighting";
    if (protection)
      cout << "Protection";
    if (fighter_attr.two_weapon_fighting)
      cout << "Two-Weapon Fighting";
    cout << "), ";
  }
  if (fighter_attr.second_wind)
    cout << "Second Wind, ";
  if (fighter_attr.martial_archtype)
  {
    cout << "Martial Archetype(";
    if (fighter_attr.champion)
    {
      cout << "Champion)[Improved Critical";
      if (fighter_attr.martial_archtype_feature >= 1)
        cout << ", Remarkable Athlete";
      if (fighter_attr.martial_archtype_feature >= 2)
        cout << ", Additonal Fighting Style";
      if (fighter_attr.martial_archtype_feature >= 3)
        cout << ", Superior Critical";
      if (fighter_attr.martial_archtype_feature >= 4)
        cout << ", Survivor";
    }
    else if (fighter_attr.battle_master)
    {
      cout << "Battle Master)[Combat Superiority";
      if (fighter_attr.martial_archtype_feature >= 1)
        cout << ", Know Your Enemy";
      if (fighter_attr.martial_archtype_feature >= 2)
        cout << ", Improved Combat Superiority(d10)";
      if (fighter_attr.martial_archtype_feature >= 3)
        cout << ", Relentless";
      if (fighter_attr.martial_archtype_feature >= 4)
        cout << ", Improved Combat Superiority(d12)";
    }
    else if (fighter_attr.eldritch_knight)
    {
      cout << "Eldritch Knight)[Spells, Bonded Weapon";
      if (fighter_attr.martial_archtype_feature >= 1)
        cout << ", War Magic";
      if (fighter_attr.martial_archtype_feature >= 2)
        cout << ", Eldritch Strike";
      if (fighter_attr.martial_archtype_feature >= 3)
        cout << ", Arcane Charge";
      if (fighter_attr.martial_archtype_feature >= 4)
        cout << ", Improved War Magic";
    }
    else
    { //purple dragon knight
      cout << "Purple Dragon Knight)[Restriction: Knighthood, Rallying Cry";
      if (fighter_attr.martial_archtype_feature >= 1)
        cout << ", Royal Envoy";
      if (fighter_attr.martial_archtype_feature >= 2)
        cout << ", Inspiring Surge";
      if (fighter_attr.martial_archtype_feature >= 3)
        cout << ", Bulwark";
      if (fighter_attr.martial_archtype_feature >= 4)
        cout << ", Final Archtype feature uspecified in Sword Coast Adventurer's Guide book";
    }
    cout << "], ";
  }
  //monk
  if (monk_attr.martial_arts > 0)
    cout << "Martial Arts(1d" << monk_attr.martial_arts << "), ";
  if (monk_attr.ki > 0)
    cout << "Ki Points(" << monk_attr.ki << ")[Flurry of Blows, Patient Defense, Step of the Wind], ";
  if (monk_attr.unarmored_movement > 0)
    cout << "Unarmored Movement(+" << monk_attr.unarmored_movement << "ft), ";
  if (monk_attr.monastic_tradition)
  {
    cout << "Monastic Tradition(";
    if (monk_attr.way_of_the_open_hand)
    {
      cout << "Way of the Open Hand)[Open Hand Technique";
      if (monk_attr.monastic_tradition_feature >= 1)
        cout << ", Wholeness of Body";
      if (monk_attr.monastic_tradition_feature >= 2)
        cout << ", Tranquility";
      if (monk_attr.monastic_tradition_feature >= 3)
        cout << ", Quivering Palm";
    }
    else if (monk_attr.way_of_the_shadow)
    {
      cout << "Way of the Shadow)[Shadow Arts";
      if (monk_attr.monastic_tradition_feature >= 1)
        cout << ", Shadow Step";
      if (monk_attr.monastic_tradition_feature >= 2)
        cout << ", Cloak of Shadows";
      if (monk_attr.monastic_tradition_feature >= 3)
        cout << ", Opportunist";
    }
    else if (monk_attr.way_of_the_four_elements)
    {
      cout << "Way of the Four Elements)[Disciple of the Elements, Elemental Disciplines(Elemental Attunement, Fangs of the Fire Snake, Fist of Four Thunders, Fist of Unbroken Air, Rush of the Gale Spirits, Shape the Flowing River, Sweeping Cinder Strike, Water Whip";
      if (monk_attr.monastic_tradition_feature >= 1)
        cout << ", Clench of the North Wind, Gong of the Summit";
      if (monk_attr.monastic_tradition_feature >= 2)
        cout << ", Eternal Mountain Defense, Flames of the Phoenix, Mist Stance, Ride the Wind";
      if (monk_attr.monastic_tradition_feature >= 3)
        cout << ", Breath of Winter, River of Hungry Flame, Wave of Rolling Earth";
      cout << ")";
    }
    else if (monk_attr.way_of_the_long_death)
    {
      cout << "Way of the Long Death)[Touch of Death";
      if (monk_attr.monastic_tradition_feature >= 1)
        cout << ", Hour of Reaping";
      if (monk_attr.monastic_tradition_feature >= 2)
        cout << ", Mastery of Death";
      if (monk_attr.monastic_tradition_feature >= 3)
        cout << ", Touch of thet Long Death";
    }
    else if (monk_attr.way_of_the_sun_soul)
    {
      cout << "Way of the Sun Soul)[Radiant Sun Bolt";
      if (monk_attr.monastic_tradition_feature >= 1)
        cout << ", Searing Arc Striket";
      if (monk_attr.monastic_tradition_feature >= 2)
        cout << ", Searing Sunburst";
      if (monk_attr.monastic_tradition_feature >= 3)
        cout << ", Sun Shield";
    }
    cout << "], ";
  }
  if (monk_attr.deflect_missles)
    cout << "Deflect Missles, ";
  if (monk_attr.slow_fall)
    cout << "Slow Fall, ";
  if (monk_attr.stunning_strike)
    cout << "Stunning Strike, ";
  if (monk_attr.ki_empowered_strikes)
    cout << "Ki-Empowered Strikes, ";
  if (monk_attr.stillness_of_mind)
    cout << "Stillness of Mind, ";
  if (monk_attr.unarmored_movement_improvement)
    cout << "Vertical Movement, ";
  if (monk_attr.purity_of_body)
    cout << "Purity of Body, ";
  if (monk_attr.tongue_of_the_sun_and_moon)
    cout << "Tongue of the Sun & Moon, ";
  if (monk_attr.diamond_soul)
    cout << "Diamond Soul, ";
  if (monk_attr.empty_body)
    cout << "Empty Body, ";
  if (monk_attr.perfect_self)
    cout << "Perfect Self, ";
  //paladin
  if (paladin_attr.divine_sense)
    cout << "Divine Sense, ";
  if (paladin_attr.lay_on_hands)
    cout << "Lay on Hands, ";
  if (paladin_attr.divine_smite > 0)
  {
    if (paladin_attr.divine_smite == 2)
      cout << "Improved ";
    cout << "Divine Smite, ";
  }
  if (paladin_attr.divine_health)
    cout << "Divine Health, ";
  if (paladin_attr.sacred_oath)
  {
    if (paladin_attr.oath_of_devotion)
    {
      cout << "Oath of Devotion[Tenets, Oath Spells, Channel Divinity(Sacred Weapon, Turn the Unholy)";
      if (paladin_attr.sacred_oath_feature >= 1)
        cout << ", Aura of Devotion";
      if (paladin_attr.sacred_oath_feature >= 2)
        cout << ", Purity of Spirit";
      if (paladin_attr.sacred_oath_feature == 3)
        cout << ", Holy Nimbus";
    }
    else if (paladin_attr.oath_of_ancients)
    {
      cout << "Oath of the Ancients[Tenets, Oath Spells, Channel Divinity(Nature's Wrath, Turn the Faithless)";
      if (paladin_attr.sacred_oath_feature >= 1)
        cout << ", Aura of Warding";
      if (paladin_attr.sacred_oath_feature >= 2)
        cout << ", Undying Sentinel";
      if (paladin_attr.sacred_oath_feature == 3)
        cout << ", Elder Champion";
    }
    else if (paladin_attr.oath_of_vengeance)
    {
      cout << "Oath of Vengeance[Tenets, Oath Spells, Channel Divinity(Abjure Enemy, Vow of Enmity)";
      if (paladin_attr.sacred_oath_feature >= 1)
        cout << ", Relentless Avenger";
      if (paladin_attr.sacred_oath_feature >= 2)
        cout << ", Soul of Vengeance";
      if (paladin_attr.sacred_oath_feature == 3)
        cout << ", Avenging Angel";
    }
    else if (paladin_attr.oathbreaker)
    {
      cout << "Oathbreaker[Oath Spells, Channel Divinity(Control Undead, Dreadful Aspect)";
      if (paladin_attr.sacred_oath_feature >= 1)
        cout << ", Aura of Hate";
      if (paladin_attr.sacred_oath_feature >= 2)
        cout << ", Supernatural Resistance";
      if (paladin_attr.sacred_oath_feature == 3)
        cout << ", Dread Lord";
    }
    else
    { //oath of the crown
      cout << "Oath of the Crown(Tenets, Oath Spells, Channel Divinity(Champion Challenge, Turn the Tide)";
      if (paladin_attr.sacred_oath_feature >= 1)
        cout << ", Divine Allegiance";
      if (paladin_attr.sacred_oath_feature >= 2)
        cout << ", Unyielding Spirit";
      if (paladin_attr.sacred_oath_feature == 3)
        cout << ", Exalted Champion";
    }
    cout << "], ";
  }
  if (paladin_attr.aura_of_protection)
    cout << "Aura of Protection, ";
  if (paladin_attr.aura_of_courage)
    cout << "Aura of Courage, ";
  if (paladin_attr.cleansing_touch)
    cout << "Cleansing Touch, ";
  if (paladin_attr.aura_improvments)
    cout << "Aura Improvements, ";
  //ranger
  if (ranger_attr.favored_enemy > 0)
  {
    cout << "Favored Enemy[";
    creaturetype();
    cout << "], ";
  }
  if (ranger_attr.favored_enemy_languages)
    cout << "Favored Enemy Languages, ";
  if (ranger_attr.natural_explorer > 0)
  {
    cout << "Natural Explorer[";
    landtype();
    cout << "], ";
  }
  if (ranger_attr.ranger_archetype)
  {
    cout << "Ranger Archetype(";
    if (ranger_attr.hunter)
    {
      cout << "Hunter)[Hunter's Prey";
      if (ranger_attr.ranger_archetype_feature >= 1)
        cout << ", Defensive Tactics";
      if (ranger_attr.ranger_archetype_feature >= 2)
        cout << ", Multiattack";
      if (ranger_attr.ranger_archetype_feature == 3)
        cout << ", Superior Hunter's Defense";
    }
    else if (ranger_attr.beast_master)
    {
      cout << "Beast Master)[Ranger's Companion";
      if (ranger_attr.ranger_archetype_feature >= 1)
        cout << ", Exceptional Training";
      if (ranger_attr.ranger_archetype_feature >= 2)
        cout << ", Bestial Fury";
      if (ranger_attr.ranger_archetype_feature == 3)
        cout << ", Share Spells";
    }
    cout << "], ";
  }
  if (ranger_attr.primeval_awareness)
    cout << "Primeval Awareness, ";
  if (ranger_attr.lands_stride)
    cout << "Land's Stride, ";
  if (ranger_attr.hide_in_plain_sight)
    cout << "Hide in Plain Sight, ";
  if (ranger_attr.feral_senses)
    cout << "Feral Senses, ";
  if (ranger_attr.foe_slayer)
    cout << "Foe Slayer, ";
  //rogue
  if (rogue_attr.sneak_attack)
    cout << "Sneak Attack, ";
  if (rogue_attr.thieves_cant)
    cout << "Thieves' Cant, ";
  if (rogue_attr.cunning_action)
    cout << "Cunning Action, ";
  if (rogue_attr.roguish_archetype)
  {
    cout << "Roguish Archetype(";
    if (rogue_attr.thief)
    {
      cout << "Thief)[Fast Hands, Second-Story Work";
      if (rogue_attr.roguish_archetype_feature > 0)
        cout << ", Supreme Sneak";
      if (rogue_attr.roguish_archetype_feature > 1)
        cout << ", Use Magic Device";
      if (rogue_attr.roguish_archetype_feature > 2)
        cout << ", Thief's Reflexes";
    }
    else if (rogue_attr.assassin)
    {
      cout << "Assassin)[Assassinate";
      if (rogue_attr.roguish_archetype_feature > 0)
        cout << ", Infiltration Expertise";
      if (rogue_attr.roguish_archetype_feature > 1)
        cout << ", Impostor";
      if (rogue_attr.roguish_archetype_feature > 2)
        cout << ", Death Strike";
    }
    else if (rogue_attr.arcane_trickster)
    {
      cout << "Arcane Trickster)[Spellcasting, Mage Hand Legerdemain";
      if (rogue_attr.roguish_archetype_feature > 0)
        cout << ", Magical Ambush";
      if (rogue_attr.roguish_archetype_feature > 1)
        cout << ", Versatile Trickerster";
      if (rogue_attr.roguish_archetype_feature > 2)
        cout << ", Spell Theif";
    }
    else if (rogue_attr.mastermind)
    {
      cout << "Mastermind)[Master of Intrigue, Master of Tactics";
      if (rogue_attr.roguish_archetype_feature > 0)
        cout << ", Insightful Manipulation";
      if (rogue_attr.roguish_archetype_feature > 1)
        cout << ", Misdirection";
      if (rogue_attr.roguish_archetype_feature > 2)
        cout << ", Soul of Deceit";
    }
    else
    { //swashbuckler
      cout << "Swashbuckler)[Fancy Footwork, Rakish Audacity";
      if (rogue_attr.roguish_archetype_feature > 0)
        cout << ", Panache";
      if (rogue_attr.roguish_archetype_feature > 1)
        cout << ", Elegant Maneuver";
      if (rogue_attr.roguish_archetype_feature > 2)
        cout << ", Master Duelist";
    }
    cout << "], ";
  }
  if (rogue_attr.uncanny_dodge)
    cout << "Uncanny Dodge, ";
  if (rogue_attr.reliable_talent)
    cout << "Reliable Talent, ";
  if (rogue_attr.blindsense)
    cout << "Blindsense, ";
  if (rogue_attr.slippery_mind)
    cout << "Slippery Mind, ";
  if (rogue_attr.elusive)
    cout << "Elusive, ";
  if (rogue_attr.stroke_of_luck)
    cout << "Stroke of Luck, ";
  //sorcerer
  if (sorcerer_attr.sorcerous_origin)
  {
    cout << "Sorcerous Origin(";
    if (sorcerer_attr.draconic_bloodline)
    {
      cout << "Draconic Bloodline)[Draconic Resilience";
      if (sorcerer_attr.sorcerous_origin_feature >= 1)
        cout << ", Elemental Affinity";
      if (sorcerer_attr.sorcerous_origin_feature >= 2)
        cout << ", Draconic Wings";
      if (sorcerer_attr.sorcerous_origin_feature == 3)
        cout << ", Draconic Presence";
    }
    else if (sorcerer_attr.wild_magic)
    {
      cout << "Wild Magic)[Surge, Tides of Chaos";
      if (sorcerer_attr.sorcerous_origin_feature >= 1)
        cout << ", Bend Luck";
      if (sorcerer_attr.sorcerous_origin_feature >= 2)
        cout << ", Controlled Chaos";
      if (sorcerer_attr.sorcerous_origin_feature == 3)
        cout << ", Spell Bombardment";
    }
    else
    { //storm sorcery
      cout << "Storm Sorcery)[Wind Speaker, Tempestuous Magic";
      if (sorcerer_attr.sorcerous_origin_feature >= 1)
        cout << ", Heart of the Storm, Storm Guide";
      if (sorcerer_attr.sorcerous_origin_feature >= 2)
        cout << ", Storm's Fury";
      if (sorcerer_attr.sorcerous_origin_feature == 3)
        cout << ", Wind Soul";
    }
    cout << "], ";
  }
  if (sorcerer_attr.font_of_magic)
    cout << "Font of Magic, ";
  if (sorcerer_attr.sorcery_points > 0)
    cout << "Sorcery Points(" << sorcerer_attr.sorcery_points << "), ";
  if (sorcerer_attr.metamagic > 0)
  {
    if (sorcerer_attr.metamagic == 1)
      cout << "Metamagic(2), ";
    if (sorcerer_attr.metamagic == 2)
      cout << "Metamagic(3), ";
    if (sorcerer_attr.metamagic == 3)
      cout << "Metamagic(4), ";
  }
  if (sorcerer_attr.sorcerous_restoration)
    cout << "Sorcerous Restoration, ";
  //warlock
  if (warlock_attr.otherworldly_patron)
  {
    cout << "Otherworldly Patron(";
    if (warlock_attr.archfey)
    {
      cout << "Archfey)[Expanded Spell List, Fey Presence";
      if (warlock_attr.otherworldly_patron_feature >= 1)
        cout << ", Misty Escape";
      if (warlock_attr.otherworldly_patron_feature >= 2)
        cout << ", Beguiling Defenses";
      if (warlock_attr.otherworldly_patron_feature == 3)
        cout << ", Dark Delrium";
    }
    else if (warlock_attr.fiend)
    {
      cout << "The Fiend)[Expanded Spell List, Dark One's Blessing";
      if (warlock_attr.otherworldly_patron_feature >= 1)
        cout << ", Dark One’s Own Luck";
      if (warlock_attr.otherworldly_patron_feature >= 2)
        cout << ", Fiendish Resilience";
      if (warlock_attr.otherworldly_patron_feature == 3)
        cout << ", Hurl Through Hell";
    }
    else if (warlock_attr.great_old_one)
    {
      cout << "Great Old One)[Expanded Spell List, Awakened Mind";
      if (warlock_attr.otherworldly_patron_feature >= 1)
        cout << ", Entropic Ward";
      if (warlock_attr.otherworldly_patron_feature >= 2)
        cout << ", Thought Shield";
      if (warlock_attr.otherworldly_patron_feature == 3)
        cout << ", Create Thrall";
    }
    else
    { //the_undying
      cout << "The Undying)[Expanded Spell List, Among the Dead";
      if (warlock_attr.otherworldly_patron_feature >= 1)
        cout << ", Defy Death";
      if (warlock_attr.otherworldly_patron_feature >= 2)
        cout << ", Undying Nature";
      if (warlock_attr.otherworldly_patron_feature == 3)
        cout << ", Indestructable Life";
    }
    cout << "], ";
  }
  if (warlock_attr.pact_magic)
    cout << "Pact Magic, ";
  if (warlock_attr.pact_boon)
    cout << "Pact Boon, ";
  if (warlock_attr.eldritch_master)
    cout << "Eldritch Master, ";
  //wizard
  if (wizard_attr.arcane_recovery)
    cout << "Arcane Recovery, ";
  if (wizard_attr.arcane_tradition)
  {
    cout << "Arcane Tradition(";
    if (wizard_attr.abjuration)
    {
      cout << "Abjurer)[Savant, Arcane Ward";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Projected Ward";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Improved Abjuration";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Spell Resistance";
    }
    else if (wizard_attr.conjuration)
    {
      cout << "Conjurer[Savant, Minor Conjuration";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Benign Transposition";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Focused Conjuration";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Durable Summons";
    }
    else if (wizard_attr.divination)
    {
      cout << "Diviner[Savant, Portent";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Expert Divination";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Third Eye";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Greater Portent";
    }
    else if (wizard_attr.enchantment)
    {
      cout << "Enchanter[Savant, Hypnotic Gaze";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Instinctive Charm";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Split Enchantment";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Alter Memories";
    }
    else if (wizard_attr.evocation)
    {
      cout << "Evoker[Savant, Sculpt Spells";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Potent Cantrip";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Empowered Evocation";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Overchannel";
    }
    else if (wizard_attr.illusion)
    {
      cout << "Illusionist[Savant, Improved Minor Illusion";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Malleable Illusions";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Illusory Self";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Illusory Reality";
    }
    else if (wizard_attr.necromancy)
    {
      cout << "Necromancer[Savant, Grim Harvest";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Undead Thralls";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Inured to Undeath";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Command Undead";
    }
    else if (wizard_attr.transmutation)
    {
      cout << "Tranmuter[Savant, Minor Alchemy";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Transmuter's Stone";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Shapechanger";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Master Transmuter";
    }
    else
    { // bladesinging
      cout << "Bladesinger[Training in War or Song, Blade Song";
      if (wizard_attr.arcane_tradition_feature >= 1)
        cout << ", Extra Attack";
      if (wizard_attr.arcane_tradition_feature >= 2)
        cout << ", Song of Defense";
      if (wizard_attr.arcane_tradition_feature == 3)
        cout << ", Song of Victory";
    }
    cout << "], ";
  }
  if (wizard_attr.spell_mastery)
    cout << "Spell Mastery, ";
  if (wizard_attr.signature_spell)
    cout << "Signature Spell, ";
  cout << endl;
}
void Generic_Character_Class::printSpellSlots() const
{
  if (spellcasting || warlock_attr.pact_magic)
  {
    cout << "->" << MAGENTA << " Cantrips: " << RESET;
    if (bard_attr.bard_cantrips_known > 0)
      cout << "Bard(" << bard_attr.bard_cantrips_known << ")";
    if (cleric_attr.cleric_cantrips_known > 0)
      cout << "Cleric(" << cleric_attr.cleric_cantrips_known << ")";
    if (druid_attr.druid_cantrips_known > 0)
      cout << "Druid(" << druid_attr.druid_cantrips_known << ")";
    if (wizard_attr.wizard_cantrips_known > 0)
      cout << "Wizard(" << wizard_attr.wizard_cantrips_known << ")";
    if (sorcerer_attr.sorcerer_cantrips_known > 0)
      cout << "Sorcerer(" << sorcerer_attr.sorcerer_cantrips_known << ")";
    if (warlock_attr.warlock_cantrips_known > 0)
      cout << "Warlock(" << warlock_attr.warlock_cantrips_known << ")";
    cout << "\n->" << MAGENTA << " Spell Slots: " << RESET;
    if (warlock_attr.warlock_slot_level > 0)
      cout << "Warlock Slot Level(" << warlock_attr.warlock_slot_level << ")";
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
    if (bard_attr.bard_spells_known > 0)
      cout << "Bard(" << bard_attr.bard_spells_known << ")";
    if (fighter_attr.eldritch_spells_known > 0)
      cout << "Eldritch Knight(" << fighter_attr.eldritch_spells_known << ")";
    if (ranger_attr.ranger_spells_known > 0)
      cout << "Ranger(" << ranger_attr.ranger_spells_known << ")";
    if (rogue_attr.arcane_t_spells_known > 0)
      cout << "Arcane Trickster(" << rogue_attr.arcane_t_spells_known << ")";
    if (sorcerer_attr.sorcerer_spells_known > 0)
      cout << "Sorcerer(" << sorcerer_attr.sorcerer_spells_known << ")";
    if (warlock_attr.warlock_spells_known > 0)
      cout << "Warlock(" << warlock_attr.warlock_spells_known << ")";
    if (warlock_attr.eldritch_invocations_known > 0)
      cout << ", Eldritch Invocations(" << warlock_attr.eldritch_invocations_known << "), ";
    if (warlock_attr.mystic_arcanum >= 6)
    {
      cout << "Mystic Arcanum[6th";
      if (warlock_attr.mystic_arcanum >= 7)
        cout << ", 7th";
      if (warlock_attr.mystic_arcanum >= 8)
        cout << ", 8th";
      if (warlock_attr.mystic_arcanum >= 9)
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
