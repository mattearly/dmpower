#include "characters.h"
#include "terminal_colors.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "globalfuncts.h"

using namespace std;

void Generic_Character_Class::character_sheet() const
{
  if (clearScreens)
    simpleClearScreen();
  cout << " " << char_name << "'s Character Sheet:\n";
  cout << "->" << GREEN << " Class(Level): " << RESET << char_class << "(" << level << ")\n";
  cout << "->" << GREEN << " Alignment: " << RESET << alignment << '\n';
  cout << "->" << GREEN << " Race: " << RESET << race << '\n';
  cout << "->" << GREEN << " Background: " << RESET << getBackground() << '\n';
  cout << "->" << GREEN << " Hit Dice: " << RESET << level << "d" << hitdicesize
       << "(Ave NPC HP: " << ((((hitdicesize + 2) / 2)) * level) + (getAbilityMod(constitution) * level)
       << " Ave PC HP: " << hitdicesize + ((((hitdicesize + 2) / 2)) * (level - 1)) + (getAbilityMod(constitution) * level)
       << ")\n";
  if (move_speed > 0)
    cout << "->" << GREEN << " Move Speed: " << RESET << move_speed << "ft\n";
  if (fly_speed > 0)
    cout << "->" << GREEN << " Fly Speed: " << RESET << fly_speed << "ft\n";
  if (swim_speed > 0)
    cout << "->" << GREEN << " Swim Speed: " << RESET << swim_speed << "ft\n";
  if (climb_speed > 0)
    cout << "->" << GREEN << " Climb Speed: " << RESET << climb_speed << "ft\n";
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
  cout << '\n';
  printClassAbilities();
  printCantrips();
  printSpellSlots();
  printSkills();
  printOtherAbilities();
  printLangs();
  printToolsInstruments();
  printFeats();
  printResistances();
  printDisadvantages();
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
      landtype(cout);
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
    creaturetype(cout);
    cout << "], ";
  }
  if (favored_enemy_languages)
    cout << "Favored Enemy Languages, ";
  if (natural_explorer > 0)
  {
    cout << "Natural Explorer[";
    landtype(cout);
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
  cout << '\n';
}

void Generic_Character_Class::printCantrips() const
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
  cout << '\n';
}

void Generic_Character_Class::printSpellSlots() const
{
  if (spellcasting || pact_magic)
  {
    cout << "->" << MAGENTA << " Spell Slots: " << RESET;
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
    cout << '\n';
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
  cout << '\n';
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
  if (svirfneblin_magic)
    cout << "Svirfneblin Magic, ";
  if (tavern_brawler)
    cout << "Tavern Brawler, ";
  if (tough)
    cout << "Tough, ";
  if (war_caster)
    cout << "War Caster, ";
  if (weapon_master)
    cout << "Weapon Master.";
  cout << '\n';
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
  if (devils_tongue)
    cout << "Devil's Tongue, ";
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
  if (duergar_resilience)
    cout << "Duergar Resilience, ";
  if (duergar_magic)
    cout << "Duergar Magic, ";
  if (elf_weapon_training)
    cout << "Elf Weapon Training, ";
  if (expert_forgery)
    cout << "Expert Forgery, ";
  if (fey_ancestry)
    cout << "Fey Ancestry, ";
  if (fleet_of_foot)
    cout << "Fleet of Foot, ";
  if (halflinglucky)
    cout << "Lucky(halfling), ";
  if (halfling_nimbleness)
    cout << "Halfling Nimbleness, ";
  if (healing_hands)
    cout << "Healing Hands, ";
  if (hellfire)
    cout << "Hellfire, ";
  if (hellish_resistance)
    cout << "Hellish Resistance, ";
  if (infernal_legacy)
    cout << "Infernal Legacy, ";
  if (light_bearer)
    cout << "Light Bearer, ";
  if (mask_of_the_wild)
    cout << "Mask of the Wild, ";
  if (mimicry)
    cout << "Mimicry, ";
  if (natural_illusionist)
    cout << "Natural Illusionist, ";
  if (naturally_stealthy)
    cout << "Naturally Stealthy, ";
  if (necrotic_shroud)
    cout << "Necrotic Shroud, ";
  if (radiant_consumption)
    cout << "Radiant Consumption, ";
  if (radiant_soul)
    cout << "Radiant Soul, ";
  if (speak_with_small_beasts)
    cout << "Speak With Small Beasts, ";
  if (stonecunning)
    cout << "Stonecunning, ";
  if (stone_camouflage)
    cout << "Stone Camouflage, ";
  if (stones_endurance)
    cout << "Stone's Endurance, ";
  if (stout_resilience)
    cout << "Stout Resilience, ";
  if (superior_darkvision)
    cout << "Superior Darkvision, ";
  if (trance)
    cout << "Trance, ";
  if (firbolg_magic)
    cout << "Firbolg Magic, ";
  if (hidden_step)
    cout << "Hidden Step, ";
  if (powerful_build)
    cout << "Powerful Build, ";
  if (speech_of_beast_and_leaf)
    cout << "Speech of Beast and Leaf, ";
  if (silent_speech)
    cout << "Silent Speech, ";
  // lizardfolk stuff
  if (lizardfolk_bite)
    cout << "Bite, ";
  if (cunning_artisan)
    cout << "Cunning Artisan, ";
  if (hold_breath)
    cout << "Hold Breath(" << hold_breath << "m), ";
  if (natural_armor)
    cout << "Natural Armor(" << natural_armor << "AC), ";
  if (hungry_jaws)
    cout << "Hungry Jaws, ";
  // tabaxi stuff
  if (feline_agility)
    cout << "Feline Agility, ";
  if (cats_claws)
    cout << "Cat's Claws, ";
  // Triton stuff
  if (amphibious)
    cout << "Amphibious, ";
  if (control_air_and_water)
    cout << "Control Air and Water, ";
  if (emissary_of_the_sea)
    cout << "Emissary of the Sea, ";
  if (guardian_of_the_depths)
    cout << "Guardian of the Depths, ";
  // Warforged stuff
  if (composite_plating)
    cout << "Composite Plating, ";
  if (living_construct)
    cout << "Living Construct, ";
  // changeling stuff
  if (shapechanger)
    cout << "Shapechanger, ";
  // shifter stuff
  if (shifting)
    cout << "Shifting, ";
  // tortle package stuff
  if (shell)
    cout << "Shell, ";
  if (retreat_to_shell)
    cout << "Retreat to Shell, ";
  if (turtle_snapper)
    cout << "Turtle Snapper, ";
  if (razorback)
    cout << "Razorback, ";
  if (softshell)
    cout << "Softshell, ";
  if (nomad)
    cout << "Nomad, ";
  if (shell_master)
    cout << "Shell Master, ";
  //aarakocra stuff
  if (talons)
    cout << "Talons, ";
  //genasi stuff
  if (unending_breath)
    cout << "Unending Breath, ";
  if (mingle_with_the_wind)
    cout << "Mingle with the Wind, ";
  if (earth_walk)
    cout << "Earth Walk, ";
  if (merge_with_stone)
    cout << "Merge with Stone, ";
  if (reach_to_the_blaze)
    cout << "Reach to the Blaze, ";
  if (call_to_the_wave)
    cout << "Call to the Wave, ";

  cout << '\n';
}
void Generic_Character_Class::printLangs() const
{
  cout << "->" << CYAN << " Languages: " << RESET;
  if (aarakocra)
    cout << "Aarakocra, ";
  if (abyssal)
    cout << "Abyssal, ";
  if (aquan)
    cout << "Aquan, ";
  if (auran)
    cout << "Auran, ";
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
  cout << '\n';
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
  cout << '\n';
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
  cout << '\n';
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
  cout << '\n';
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
    cout << "Cold, ";
  if (damage_resist_necrotic)
    cout << "Necrotic, ";
  if (damage_resist_radiant)
    cout << "Radiant";
  cout << '\n';
}
void Generic_Character_Class::printDisadvantages() const
{
  cout << "->" << RED << " Disadvantages: " << RESET;
  if (sunlight_sensitivity)
    cout << "Sunlight Sensitivty" << '\n';
  cout << '\n';
}
