#include "characters.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "globalfuncts.h"

/**
 * Exports a printer fri'\n'y version of your character sheet
 *   This is not a Load/Save file
 * @param[in] title  the name of the file, suggest name, race, class, level
 */
void Generic_Character_Class::exportPrint(const std::string& title) const {
  createUserFolders();
  std::ofstream os(DOCUMENT_SAVE_DIR + "/" + title + ".txt");
  if (os.is_open()) {

    //--------------------------PRNIT CORE CHARACTER SHEE STUFF-------------------//

    os << " " << char_name << "'s Character Sheet:\n";
    os << "-> Class(Level): " << char_class << "(" << level << ")\n";
    os << "-> Alignment: " << alignment << '\n';
    os << "-> Race: " << race << '\n';
    os << "-> Background: " << getBackground() << '\n';
    os << "-> Hit Dice: " << level << "d" << hitdicesize
      << "(Ave NPC HP: " << ((((hitdicesize + 2) / 2)) * level) + (getAbilityMod(constitution) * level)
      << " Ave PC HP: " << hitdicesize + ((((hitdicesize + 2) / 2)) * (level - 1)) + (getAbilityMod(constitution) * level)
      << ")\n";
    if (move_speed > 0)
      os << "-> Move Speed: " << move_speed << "ft\n";
    if (fly_speed > 0)
      os << "-> Fly Speed: " << fly_speed << "ft\n";
    if (swim_speed > 0)
      os << "-> Swim Speed: " << swim_speed << "ft\n";
    if (climb_speed > 0)
      os << "-> Climb Speed: " << climb_speed << "ft\n";
    os << "-> Proficiency Bonus:" << " +" << proficiency_bonus;
    os << "\n-> Str: " << std::setw(2) << strength << " " << D_D_Ability_Modifier(strength);
    if (strSave)
      os << "  <-SaveProficient";
    os << "\n-> Dex: " << std::setw(2) << dexterity << " " << D_D_Ability_Modifier(dexterity);
    if (dexSave)
      os << "  <-SaveProficient";
    os << "\n-> Con: " << std::setw(2) << constitution << " " << D_D_Ability_Modifier(constitution);
    if (conSave)
      os << "  <-SaveProficient";
    os << "\n-> Int: " << std::setw(2) << intelligence << " " << D_D_Ability_Modifier(intelligence);
    if (intSave)
      os << "  <-SaveProficient";
    os << "\n-> Wis: " << std::setw(2) << wisdom << " " << D_D_Ability_Modifier(wisdom);
    if (wisSave)
      os << "  <-SaveProficient";
    os << "\n-> Cha: " << std::setw(2) << charisma << " " << D_D_Ability_Modifier(charisma);
    if (chaSave)
      os << "  <-SaveProficient";
    os << '\n';

    //-----------------------PRINT CLASS ABILITIES------------------------//

    os << "-> Class Abilities: ";
    //general
    if (extra_attack > 0)
      os << "Extra Attack(" << extra_attack << "), ";
    if (spellcasting)
      os << "Spellcasting, ";
    if (evasion)
      os << "Evasion, ";
    if (expertise > 0)
      os << "Expertise(" << expertise << "), ";
    if (timeless_body)
      os << "Timeless Body, ";
    //barbarians
    if (brutal_critical > 0)
      os << "Brutal Critical(" << brutal_critical << " dice), ";
    if (danger_sense)
      os << "Danger Sense, ";
    if (fast_movement)
      os << "Fast Movement(+10), ";
    if (feral_instinct)
      os << "Feral Instinct, ";
    if (indomitable_might)
      os << "Indomintable Might, ";
    if (persistant_rage)
      os << "Persistant Rage, ";
    if (primal_champion)
      os << "Primal Champion, ";
    if (rage_damage > 0)
      os << "Rage Damage(+" << rage_damage << "), ";
    if (rages > 0)
      os << "Rage(" << rages << "/day), ";
    if (reckless_attack)
      os << "Reckless Attack, ";
    if (primal_path) {
      if (path_of_the_battlerager) {
        os << "Path of the Battlerager[Battlerager Armor";
        if (path_feature >= 1)
          os << ", Reckless Abandon";
        if (path_feature >= 2)
          os << ", Battlerager Charge";
        if (path_feature >= 3)
          os << ", Spiked Retribution";
      } else if (path_of_the_berseker) {
        os << "Path of the Berserker[Frenzy";
        if (path_feature >= 1)
          os << ", Mindless Rage";
        if (path_feature >= 2)
          os << ", Intimidating Prescense";
        if (path_feature >= 3)
          os << ", Retaliation";
      } else {
        os << "Path of the Totem Warrior";
        if (bear_totem)
          os << "(Bear)";
        if (eagle_totem)
          os << "(Eagle)";
        if (wolf_totem)
          os << "(Wolf)";
        os << "[Spirit Seeker, Totem Spirit";
        if (path_feature >= 1)
          os << ", Spirit Walker";
        if (path_feature >= 2)
          os << ", Aspect of the Beast";
        if (path_feature >= 3)
          os << ", Totemic Attunement, ";
      }
      os << "], ";
    }
    if (relentless_rage)
      os << "Relentless Rage, ";
    //bards
    if (bardic_inspiration > 0)
      os << "Bardic Inspiration(d" << bardic_inspiration << "), ";
    if (jack_of_all_trades)
      os << "Jack of All Trades, ";
    if (song_of_rest > 0)
      os << "Song of Rest(d" << song_of_rest << "), ";
    if (bard_college) {
      os << "Bard College[";
      if (college_of_lore) {
        os << "3 Bonus Skills, Cutting Words";
        if (bard_college_feature >= 1)
          os << ", Additional Magical Secrets";
        if (bard_college_feature == 2)
          os << ", Peerless Skill";
      } else {
        os << "Med Armor, Shields, Martial Weapons, Combat Inspirtation";
        if (bard_college_feature >= 1)
          os << ", Extra Attack";
        if (bard_college_feature == 2)
          os << ", Battle Magic";
      }
      os << "], ";
    }
    if (font_of_inspiration)
      os << "Font of Inspiration, ";
    if (countercharm)
      os << "Countercharm, ";
    if (magical_secrets > 0)
      os << "Magical Secrets(" << magical_secrets << "), ";
    if (superior_inspiration)
      os << "Superior Inspiration, ";
    //clerics
    if (divine_domain) {
      os << "Divine Domain(";
      if (arcana_d)
        os << "Arcana), ";
      if (death_d)
        os << "Death), ";
      if (knowledge_d)
        os << "Knowledge), ";
      if (life_d)
        os << "Life), ";
      if (light_d)
        os << "Light), ";
      if (nature_d)
        os << "Nature), ";
      if (tempest_d)
        os << "Tempest), ";
      if (trickery_d)
        os << "Trickery), ";
      if (war_d)
        os << "War), ";
    }
    if (divine_domain_feature > 0) {
      os << "Domain Features[";
      if (arcana_d) {
        os << "Arcane Initiate";
        if (divine_domain_feature >= 1)
          os << ", Arcane Abjuration";
        if (divine_domain_feature >= 2)
          os << ", Spell Breaker";
        if (divine_domain_feature >= 3)
          os << ", Potent Spellcasting";
        if (divine_domain_feature >= 4)
          os << ", Arcane Mastery";
      } else if (death_d) {
        //gain martial weapons
        os << "Reaper";
        if (divine_domain_feature >= 1)
          os << ", Touch of Death";
        if (divine_domain_feature >= 2)
          os << ", Inescapable Destruction";
        if (divine_domain_feature >= 3)
          os << ", Divine Strike";
        if (divine_domain_feature >= 4)
          os << ", Improved Reaper";
      } else if (knowledge_d) {
        //gain blessings of knowledge - gain 2 langs - gain any 2 skills
        if (divine_domain_feature >= 1)
          os << "Knowledge of the Ages";
        if (divine_domain_feature >= 2)
          os << ", Read Thoughts";
        if (divine_domain_feature >= 3)
          os << ", Potent Spellcasting";
        if (divine_domain_feature >= 4)
          os << ", Visions of the Past";
      } else if (life_d) {
        //gain heavy armor prof
        os << "Disciple of Life";
        if (divine_domain_feature >= 1)
          os << ", Preserve Life";
        if (divine_domain_feature >= 2)
          os << ", Blessed Healer";
        if (divine_domain_feature >= 3)
          os << ", Divine Strike";
        if (divine_domain_feature >= 4)
          os << ", Supreme Healing";
      } else if (light_d) {
        os << "Light Cantrip, Warding Flare";
        if (divine_domain_feature >= 1)
          os << ", Radiance of the Dawn";
        if (divine_domain_feature >= 2)
          os << ", Improved Flare";
        if (divine_domain_feature >= 3)
          os << ", Potent Spellcasting";
        if (divine_domain_feature >= 4)
          os << ", Corona of Light";
      } else if (nature_d) {
        //gain 1 skill - heavy armor prof
        os << "Druid Cantrip";
        if (divine_domain_feature >= 1)
          os << ", Charm Animals & Plants";
        if (divine_domain_feature >= 2)
          os << ", Dampen Elements";
        if (divine_domain_feature >= 3)
          os << ", Divine Strike";
        if (divine_domain_feature >= 4)
          os << ", Master of Nature";
      } else if (tempest_d) {
        //gain heavy armor, martial weapons
        os << "Wrath of the Storm";
        if (divine_domain_feature >= 1)
          os << ", Destructive Wrath";
        if (divine_domain_feature >= 2)
          os << ", Thunderbolt Strike";
        if (divine_domain_feature >= 3)
          os << ", Divine Strike";
        if (divine_domain_feature >= 4)
          os << ", Stormborn";
      } else if (trickery_d) {
        os << "Blessing of the Trickster";
        if (divine_domain_feature >= 1)
          os << ", Invoke Duplicity";
        if (divine_domain_feature >= 2)
          os << ", Cloak of Shadows";
        if (divine_domain_feature >= 3)
          os << ", Divine Strike";
        if (divine_domain_feature >= 4)
          os << ", Improved Duplicity";
      } else if (war_d) {
        //gain heavy armor, martial weapons
        os << "War Priest";
        if (divine_domain_feature >= 1)
          os << ", Guided Strike";
        if (divine_domain_feature >= 2)
          os << ", War God's Blessing";
        if (divine_domain_feature >= 3)
          os << ", Divine Strike";
        if (divine_domain_feature >= 4)
          os << ", Avatar of Battle";
      }
      os << "], ";
    }
    if (channel_divinity > 0)
      os << "Channel Divinity(" << channel_divinity << "/rest), ";
    if (destroy_undead > 0)
      os << "Destroy Undead(CR" << destroy_undead << "), ";
    if (divine_intervention > 0) {
      if (divine_intervention >= 1)
        os << "Divine Intervention";
      if (divine_intervention == 2)
        os << " Improved";
      os << ", ";
    }
    //druids
    if (wild_shape)
      os << "Wild Shape(CR" << wild_shape_improvement << "), ";
    if (druid_circle) {
      os << "Druid Circle(";
      if (circle_of_the_moon) {
        os << "Moon)[Combat Wild Shape, Circle Forms";
        if (druid_circle_feature >= 1)
          os << ", Primal Strike";
        if (druid_circle_feature >= 2)
          os << ", Elemental Wild Shape";
        if (druid_circle_feature == 3)
          os << ", Thousand Forms";
      } else {
        os << "Land)[Bonus Cantrip, Natural Recovery, Circle Spells(";
        landtype(os);
        os << ")";
        if (druid_circle_feature >= 1)
          os << ", Land's Stride";
        if (druid_circle_feature >= 2)
          os << ", Nature's Ward";
        if (druid_circle_feature == 3)
          os << ", Nautre's Sactuary";
      }
      os << "], ";
    }
    if (beast_spells)
      os << "Beast Spells, ";
    if (archdruid)
      os << "Archdruid, ";
    if (fighting_style) {
      os << "Fighting Style(";
      if (archery)
        os << "Archery";
      if (defense)
        os << "Defense";
      if (dueling)
        os << "Dueling";
      if (great_weapon_fighting)
        os << "Great Weapon Fighting";
      if (protection)
        os << "Protection";
      if (two_weapon_fighting)
        os << "Two-Weapon Fighting";
      os << "), ";
    }
    if (second_wind)
      os << "Second Wind, ";
    if (martial_archtype) {
      os << "Martial Archetype(";
      if (champion) {
        os << "Champion)[Improved Critical";
        if (martial_archtype_feature >= 1)
          os << ", Remarkable Athlete";
        if (martial_archtype_feature >= 2)
          os << ", Additonal Fighting Style";
        if (martial_archtype_feature >= 3)
          os << ", Superior Critical";
        if (martial_archtype_feature >= 4)
          os << ", Survivor";
      } else if (battle_master) {
        os << "Battle Master)[Combat Superiority";
        if (martial_archtype_feature >= 1)
          os << ", Know Your Enemy";
        if (martial_archtype_feature >= 2)
          os << ", Improved Combat Superiority(d10)";
        if (martial_archtype_feature >= 3)
          os << ", Relentless";
        if (martial_archtype_feature >= 4)
          os << ", Improved Combat Superiority(d12)";
      } else if (eldritch_knight) {
        os << "Eldritch Knight)[Spells, Bonded Weapon";
        if (martial_archtype_feature >= 1)
          os << ", War Magic";
        if (martial_archtype_feature >= 2)
          os << ", Eldritch Strike";
        if (martial_archtype_feature >= 3)
          os << ", Arcane Charge";
        if (martial_archtype_feature >= 4)
          os << ", Improved War Magic";
      } else { //purple dragon knight
        os << "Purple Dragon Knight)[Restriction: Knighthood, Rallying Cry";
        if (martial_archtype_feature >= 1)
          os << ", Royal Envoy";
        if (martial_archtype_feature >= 2)
          os << ", Inspiring Surge";
        if (martial_archtype_feature >= 3)
          os << ", Bulwark";
        if (martial_archtype_feature >= 4)
          os << ", Final Archtype feature uspecified in Sword Coast Adventurer's Guide book";
      }
      os << "], ";
    }
    //monk
    if (martial_arts > 0)
      os << "Martial Arts(1d" << martial_arts << "), ";
    if (ki > 0)
      os << "Ki Points(" << ki << ")[Flurry of Blows, Patient Defense, Step of the Wind], ";
    if (unarmored_movement > 0)
      os << "Unarmored Movement(+" << unarmored_movement << "ft), ";
    if (monastic_tradition) {
      os << "Monastic Tradition(";
      if (way_of_the_open_hand) {
        os << "Way of the Open Hand)[Open Hand Technique";
        if (monastic_tradition_feature >= 1)
          os << ", Wholeness of Body";
        if (monastic_tradition_feature >= 2)
          os << ", Tranquility";
        if (monastic_tradition_feature >= 3)
          os << ", Quivering Palm";
      } else if (way_of_the_shadow) {
        os << "Way of the Shadow)[Shadow Arts";
        if (monastic_tradition_feature >= 1)
          os << ", Shadow Step";
        if (monastic_tradition_feature >= 2)
          os << ", Cloak of Shadows";
        if (monastic_tradition_feature >= 3)
          os << ", Opportunist";
      } else if (way_of_the_four_elements) {
        os << "Way of the Four Elements)[Disciple of the Elements, Elemental Disciplines(Elemental Attunement, Fangs of the Fire Snake, Fist of Four Thunders, Fist of Unbroken Air, Rush of the Gale Spirits, Shape the Flowing River, Sweeping Cinder Strike, Water Whip";
        if (monastic_tradition_feature >= 1)
          os << ", Clench of the North Wind, Gong of the Summit";
        if (monastic_tradition_feature >= 2)
          os << ", Eternal Mountain Defense, Flames of the Phoenix, Mist Stance, Ride the Wind";
        if (monastic_tradition_feature >= 3)
          os << ", Breath of Winter, River of Hungry Flame, Wave of Rolling Earth";
        os << ")";
      } else if (way_of_the_long_death) {
        os << "Way of the Long Death)[Touch of Death";
        if (monastic_tradition_feature >= 1)
          os << ", Hour of Reaping";
        if (monastic_tradition_feature >= 2)
          os << ", Mastery of Death";
        if (monastic_tradition_feature >= 3)
          os << ", Touch of thet Long Death";
      } else if (way_of_the_sun_soul) {
        os << "Way of the Sun Soul)[Radiant Sun Bolt";
        if (monastic_tradition_feature >= 1)
          os << ", Searing Arc Striket";
        if (monastic_tradition_feature >= 2)
          os << ", Searing Sunburst";
        if (monastic_tradition_feature >= 3)
          os << ", Sun Shield";
      }
      os << "], ";
    }
    if (deflect_missles)
      os << "Deflect Missles, ";
    if (slow_fall)
      os << "Slow Fall, ";
    if (stunning_strike)
      os << "Stunning Strike, ";
    if (ki_empowered_strikes)
      os << "Ki-Empowered Strikes, ";
    if (stillness_of_mind)
      os << "Stillness of Mind, ";
    if (unarmored_movement_improvement)
      os << "Vertical Movement, ";
    if (purity_of_body)
      os << "Purity of Body, ";
    if (tongue_of_the_sun_and_moon)
      os << "Tongue of the Sun & Moon, ";
    if (diamond_soul)
      os << "Diamond Soul, ";
    if (empty_body)
      os << "Empty Body, ";
    if (perfect_self)
      os << "Perfect Self, ";
    //paladin
    if (divine_sense)
      os << "Divine Sense, ";
    if (lay_on_hands)
      os << "Lay on Hands, ";
    if (divine_smite > 0) {
      if (divine_smite == 2)
        os << "Improved ";
      os << "Divine Smite, ";
    }
    if (divine_health)
      os << "Divine Health, ";
    if (sacred_oath) {
      if (oath_of_devotion) {
        os << "Oath of Devotion[Tenets, Oath Spells, Channel Divinity(Sacred Weapon, Turn the Unholy)";
        if (sacred_oath_feature >= 1)
          os << ", Aura of Devotion";
        if (sacred_oath_feature >= 2)
          os << ", Purity of Spirit";
        if (sacred_oath_feature == 3)
          os << ", Holy Nimbus";
      } else if (oath_of_ancients) {
        os << "Oath of the Ancients[Tenets, Oath Spells, Channel Divinity(Nature's Wrath, Turn the Faithless)";
        if (sacred_oath_feature >= 1)
          os << ", Aura of Warding";
        if (sacred_oath_feature >= 2)
          os << ", Undying Sentinel";
        if (sacred_oath_feature == 3)
          os << ", Elder Champion";
      } else if (oath_of_vengeance) {
        os << "Oath of Vengeance[Tenets, Oath Spells, Channel Divinity(Abjure Enemy, Vow of Enmity)";
        if (sacred_oath_feature >= 1)
          os << ", Relentless Avenger";
        if (sacred_oath_feature >= 2)
          os << ", Soul of Vengeance";
        if (sacred_oath_feature == 3)
          os << ", Avenging Angel";
      } else if (oathbreaker) {
        os << "Oathbreaker[Oath Spells, Channel Divinity(Control Undead, Dreadful Aspect)";
        if (sacred_oath_feature >= 1)
          os << ", Aura of Hate";
        if (sacred_oath_feature >= 2)
          os << ", Supernatural Resistance";
        if (sacred_oath_feature == 3)
          os << ", Dread Lord";
      } else { //oath of the crown
        os << "Oath of the Crown(Tenets, Oath Spells, Channel Divinity(Champion Challenge, Turn the Tide)";
        if (sacred_oath_feature >= 1)
          os << ", Divine Allegiance";
        if (sacred_oath_feature >= 2)
          os << ", Unyielding Spirit";
        if (sacred_oath_feature == 3)
          os << ", Exalted Champion";
      }
      os << "], ";
    }
    if (aura_of_protection)
      os << "Aura of Protection, ";
    if (aura_of_courage)
      os << "Aura of Courage, ";
    if (cleansing_touch)
      os << "Cleansing Touch, ";
    if (aura_improvments)
      os << "Aura Improvements, ";
    //ranger
    if (favored_enemy > 0) {
      os << "Favored Enemy[";
      creaturetype(os);
      os << "], ";
    }
    if (favored_enemy_languages)
      os << "Favored Enemy Languages, ";
    if (natural_explorer > 0) {
      os << "Natural Explorer[";
      landtype(os);
      os << "], ";
    }
    if (ranger_archetype) {
      os << "Ranger Archetype(";
      if (hunter) {
        os << "Hunter)[Hunter's Prey";
        if (ranger_archetype_feature >= 1)
          os << ", Defensive Tactics";
        if (ranger_archetype_feature >= 2)
          os << ", Multiattack";
        if (ranger_archetype_feature == 3)
          os << ", Superior Hunter's Defense";
      } else if (beast_master) {
        os << "Beast Master)[Ranger's Companion";
        if (ranger_archetype_feature >= 1)
          os << ", Exceptional Training";
        if (ranger_archetype_feature >= 2)
          os << ", Bestial Fury";
        if (ranger_archetype_feature == 3)
          os << ", Share Spells";
      }
      os << "], ";
    }
    if (primeval_awareness)
      os << "Primeval Awareness, ";
    if (lands_stride)
      os << "Land's Stride, ";
    if (hide_in_plain_sight)
      os << "Hide in Plain Sight, ";
    if (feral_senses)
      os << "Feral Senses, ";
    if (foe_slayer)
      os << "Foe Slayer, ";
    //rogue
    if (sneak_attack)
      os << "Sneak Attack, ";
    if (thieves_cant)
      os << "Thieves' Cant, ";
    if (cunning_action)
      os << "Cunning Action, ";
    if (roguish_archetype) {
      os << "Roguish Archetype(";
      if (thief) {
        os << "Thief)[Fast Hands, Second-Story Work";
        if (roguish_archetype_feature > 0)
          os << ", Supreme Sneak";
        if (roguish_archetype_feature > 1)
          os << ", Use Magic Device";
        if (roguish_archetype_feature > 2)
          os << ", Thief's Reflexes";
      } else if (assassin) {
        os << "Assassin)[Assassinate";
        if (roguish_archetype_feature > 0)
          os << ", Infiltration Expertise";
        if (roguish_archetype_feature > 1)
          os << ", Impostor";
        if (roguish_archetype_feature > 2)
          os << ", Death Strike";
      } else if (arcane_trickster) {
        os << "Arcane Trickster)[Spellcasting, Mage Hand Legerdemain";
        if (roguish_archetype_feature > 0)
          os << ", Magical Ambush";
        if (roguish_archetype_feature > 1)
          os << ", Versatile Trickerster";
        if (roguish_archetype_feature > 2)
          os << ", Spell Theif";
      } else if (mastermind) {
        os << "Mastermind)[Master of Intrigue, Master of Tactics";
        if (roguish_archetype_feature > 0)
          os << ", Insightful Manipulation";
        if (roguish_archetype_feature > 1)
          os << ", Misdirection";
        if (roguish_archetype_feature > 2)
          os << ", Soul of Deceit";
      } else { //swashbuckler
        os << "Swashbuckler)[Fancy Footwork, Rakish Audacity";
        if (roguish_archetype_feature > 0)
          os << ", Panache";
        if (roguish_archetype_feature > 1)
          os << ", Elegant Maneuver";
        if (roguish_archetype_feature > 2)
          os << ", Master Duelist";
      }
      os << "], ";
    }
    if (uncanny_dodge)
      os << "Uncanny Dodge, ";
    if (reliable_talent)
      os << "Reliable Talent, ";
    if (blindsense)
      os << "Blindsense, ";
    if (slippery_mind)
      os << "Slippery Mind, ";
    if (elusive)
      os << "Elusive, ";
    if (stroke_of_luck)
      os << "Stroke of Luck, ";
    //sorcerer
    if (sorcerous_origin) {
      os << "Sorcerous Origin(";
      if (draconic_bloodline) {
        os << "Draconic Bloodline)[Draconic Resilience";
        if (sorcerous_origin_feature >= 1)
          os << ", Elemental Affinity";
        if (sorcerous_origin_feature >= 2)
          os << ", Draconic Wings";
        if (sorcerous_origin_feature == 3)
          os << ", Draconic Presence";
      } else if (wild_magic) {
        os << "Wild Magic)[Surge, Tides of Chaos";
        if (sorcerous_origin_feature >= 1)
          os << ", Bend Luck";
        if (sorcerous_origin_feature >= 2)
          os << ", Controlled Chaos";
        if (sorcerous_origin_feature == 3)
          os << ", Spell Bombardment";
      } else { //storm sorcery
        os << "Storm Sorcery)[Wind Speaker, Tempestuous Magic";
        if (sorcerous_origin_feature >= 1)
          os << ", Heart of the Storm, Storm Guide";
        if (sorcerous_origin_feature >= 2)
          os << ", Storm's Fury";
        if (sorcerous_origin_feature == 3)
          os << ", Wind Soul";
      }
      os << "], ";
    }
    if (font_of_magic)
      os << "Font of Magic, ";
    if (sorcery_points > 0)
      os << "Sorcery Points(" << sorcery_points << "), ";
    if (metamagic > 0) {
      if (metamagic == 1)
        os << "Metamagic(2), ";
      if (metamagic == 2)
        os << "Metamagic(3), ";
      if (metamagic == 3)
        os << "Metamagic(4), ";
    }
    if (sorcerous_restoration)
      os << "Sorcerous Restoration, ";
    //warlock
    if (otherworldly_patron) {
      os << "Otherworldly Patron(";
      if (archfey) {
        os << "Archfey)[Expanded Spell List, Fey Presence";
        if (otherworldly_patron_feature >= 1)
          os << ", Misty Escape";
        if (otherworldly_patron_feature >= 2)
          os << ", Beguiling Defenses";
        if (otherworldly_patron_feature == 3)
          os << ", Dark Delrium";
      } else if (fiend) {
        os << "The Fiend)[Expanded Spell List, Dark One's Blessing";
        if (otherworldly_patron_feature >= 1)
          os << ", Dark One’s Own Luck";
        if (otherworldly_patron_feature >= 2)
          os << ", Fiendish Resilience";
        if (otherworldly_patron_feature == 3)
          os << ", Hurl Through Hell";
      } else if (great_old_one) {
        os << "Great Old One)[Expanded Spell List, Awakened Mind";
        if (otherworldly_patron_feature >= 1)
          os << ", Entropic Ward";
        if (otherworldly_patron_feature >= 2)
          os << ", Thought Shield";
        if (otherworldly_patron_feature == 3)
          os << ", Create Thrall";
      } else { //the_undying
        os << "The Undying)[Expanded Spell List, Among the Dead";
        if (otherworldly_patron_feature >= 1)
          os << ", Defy Death";
        if (otherworldly_patron_feature >= 2)
          os << ", Undying Nature";
        if (otherworldly_patron_feature == 3)
          os << ", Indestructable Life";
      }
      os << "], ";
    }
    if (pact_magic)
      os << "Pact Magic, ";
    if (pact_boon)
      os << "Pact Boon, ";
    if (eldritch_master)
      os << "Eldritch Master, ";
    //wizard
    if (arcane_recovery)
      os << "Arcane Recovery, ";
    if (arcane_tradition) {
      os << "Arcane Tradition(";
      if (abjuration) {
        os << "Abjurer)[Savant, Arcane Ward";
        if (arcane_tradition_feature >= 1)
          os << ", Projected Ward";
        if (arcane_tradition_feature >= 2)
          os << ", Improved Abjuration";
        if (arcane_tradition_feature == 3)
          os << ", Spell Resistance";
      } else if (conjuration) {
        os << "Conjurer[Savant, Minor Conjuration";
        if (arcane_tradition_feature >= 1)
          os << ", Benign Transposition";
        if (arcane_tradition_feature >= 2)
          os << ", Focused Conjuration";
        if (arcane_tradition_feature == 3)
          os << ", Durable Summons";
      } else if (divination) {
        os << "Diviner[Savant, Portent";
        if (arcane_tradition_feature >= 1)
          os << ", Expert Divination";
        if (arcane_tradition_feature >= 2)
          os << ", Third Eye";
        if (arcane_tradition_feature == 3)
          os << ", Greater Portent";
      } else if (enchantment) {
        os << "Enchanter[Savant, Hypnotic Gaze";
        if (arcane_tradition_feature >= 1)
          os << ", Instinctive Charm";
        if (arcane_tradition_feature >= 2)
          os << ", Split Enchantment";
        if (arcane_tradition_feature == 3)
          os << ", Alter Memories";
      } else if (evocation) {
        os << "Evoker[Savant, Sculpt Spells";
        if (arcane_tradition_feature >= 1)
          os << ", Potent Cantrip";
        if (arcane_tradition_feature >= 2)
          os << ", Empowered Evocation";
        if (arcane_tradition_feature == 3)
          os << ", Overchannel";
      } else if (illusion) {
        os << "Illusionist[Savant, Improved Minor Illusion";
        if (arcane_tradition_feature >= 1)
          os << ", Malleable Illusions";
        if (arcane_tradition_feature >= 2)
          os << ", Illusory Self";
        if (arcane_tradition_feature == 3)
          os << ", Illusory Reality";
      } else if (necromancy) {
        os << "Necromancer[Savant, Grim Harvest";
        if (arcane_tradition_feature >= 1)
          os << ", Undead Thralls";
        if (arcane_tradition_feature >= 2)
          os << ", Inured to Undeath";
        if (arcane_tradition_feature == 3)
          os << ", Command Undead";
      } else if (transmutation) {
        os << "Tranmuter[Savant, Minor Alchemy";
        if (arcane_tradition_feature >= 1)
          os << ", Transmuter's Stone";
        if (arcane_tradition_feature >= 2)
          os << ", Shapechanger";
        if (arcane_tradition_feature == 3)
          os << ", Master Transmuter";
      } else { // bladesinging
        os << "Bladesinger[Training in War or Song, Blade Song";
        if (arcane_tradition_feature >= 1)
          os << ", Extra Attack";
        if (arcane_tradition_feature >= 2)
          os << ", Song of Defense";
        if (arcane_tradition_feature == 3)
          os << ", Song of Victory";
      }
      os << "], ";
    }
    if (spell_mastery)
      os << "Spell Mastery, ";
    if (signature_spell)
      os << "Signature Spell, ";
    os << '\n';

    //-------------------------PRINT CANTRIPS------------------------//

    os << "-> Cantrips: ";
    if (bard_cantrips_known > 0)
      os << "Bard(" << bard_cantrips_known << ")";
    if (cleric_cantrips_known > 0)
      os << "Cleric(" << cleric_cantrips_known << ")";
    if (druid_cantrips_known > 0)
      os << "Druid(" << druid_cantrips_known << ")";
    if (wizard_cantrips_known > 0)
      os << "Wizard(" << wizard_cantrips_known << ")";
    if (sorcerer_cantrips_known > 0)
      os << "Sorcerer(" << sorcerer_cantrips_known << ")";
    if (warlock_cantrips_known > 0)
      os << "Warlock(" << warlock_cantrips_known << ")";
    os << '\n';
  }

  //-----------------------PRINT SPELL SLOTS-----------------------//

  if (spellcasting || pact_magic) {
    os << "-> Spell Slots: ";
    if (warlock_slot_level > 0)
      os << "Warlock Slot Level(" << warlock_slot_level << ")";
    if (first_ss > 0)
      os << first_ss;
    if (second_ss > 0)
      os << "/" << second_ss;
    if (third_ss > 0)
      os << "/" << third_ss;
    if (forth_ss > 0)
      os << "/" << forth_ss;
    if (fifth_ss > 0)
      os << "/" << fifth_ss;
    if (sixth_ss > 0)
      os << "/" << sixth_ss;
    if (seventh_ss > 0)
      os << "/" << seventh_ss;
    if (eighth_ss > 0)
      os << "/" << eighth_ss;
    if (ninth_ss > 0)
      os << "/" << ninth_ss;

    os << "\n-> Spells Known: ";
    if (bard_spells_known > 0)
      os << "Bard(" << bard_spells_known << ")";
    if (eldritch_spells_known > 0)
      os << "Eldritch Knight(" << eldritch_spells_known << ")";
    if (ranger_spells_known > 0)
      os << "Ranger(" << ranger_spells_known << ")";
    if (arcane_t_spells_known > 0)
      os << "Arcane Trickster(" << arcane_t_spells_known << ")";
    if (sorcerer_spells_known > 0)
      os << "Sorcerer(" << sorcerer_spells_known << ")";
    if (warlock_spells_known > 0)
      os << "Warlock(" << warlock_spells_known << ")";
    if (eldritch_invocations_known > 0)
      os << ", Eldritch Invocations(" << eldritch_invocations_known << "), ";
    if (mystic_arcanum >= 6) {
      os << "Mystic Arcanum[6th";
      if (mystic_arcanum >= 7)
        os << ", 7th";
      if (mystic_arcanum >= 8)
        os << ", 8th";
      if (mystic_arcanum >= 9)
        os << ", 9th";
      os << "], ";
    }
    os << '\n';
  }

  //----------------------PRINT SKILLS------------------------//

  os << "-> Skills: ";
  if (acrobatics)
    os << "Acrobatics, ";
  if (animal_handling)
    os << "Animal Handling, ";
  if (arcana)
    os << "Arcana, ";
  if (athletics)
    os << "Athletics, ";
  if (deception)
    os << "Deception, ";
  if (history)
    os << "History, ";
  if (insight)
    os << "Insight, ";
  if (intimidation)
    os << "Intimidation, ";
  if (investigation)
    os << "Investigation, ";
  if (medicine)
    os << "Medicine, ";
  if (nature)
    os << "Nature, ";
  if (perception)
    os << "Perception, ";
  if (performance)
    os << "Performance, ";
  if (persuasion)
    os << "Persuasion, ";
  if (religion)
    os << "Religion, ";
  if (sleight_of_hand)
    os << "Sleight of Hand, ";
  if (stealth)
    os << "Stealth, ";
  if (survival)
    os << "Survival";
  os << '\n';

  //------------------------PRINT FEATS----------------------------//

  os << "-> Feats: ";
  if (alert)
    os << "Alert, ";
  if (athlete)
    os << "Athlete, ";
  if (actor)
    os << "Actor, ";
  if (charger)
    os << "Charger, ";
  if (crossbow_expert)
    os << "Crossbow Expert, ";
  if (defensive_duelist)
    os << "Defensive Duelist, ";
  if (dual_wielder)
    os << "Dual Wielder, ";
  if (dungeon_delver)
    os << "Dungeon Delver, ";
  if (durable)
    os << "Durable, ";
  if (elemental_adept)
    os << "Elemental Adept, ";
  if (grappler)
    os << "Grappler, ";
  if (great_weapon_master)
    os << "Great Weapon Master, ";
  if (healer)
    os << "Healer, ";
  if (heavily_armored)
    os << "Heavily Armored, ";
  if (heavy_armor_master)
    os << "Heavy Armor Master, ";
  if (inspiring_leader)
    os << "Inspiring Leader, ";
  if (keen_mind)
    os << "Keen Mind, ";
  if (lightly_armored)
    os << "Lightly Armored, ";
  if (linguist)
    os << "Linguist, ";
  if (lucky)
    os << "Lucky, ";
  if (mage_slayer)
    os << "Mage Slayer, ";
  if (magic_initiate)
    os << "Magic Initiate, ";
  if (martial_adept)
    os << "Martial Adept, ";
  if (medium_armor_master)
    os << "Medium Armor Master, ";
  if (mobile)
    os << "Mobile, ";
  if (moderately_armored)
    os << "Moderately Armored, ";
  if (mounted_combatant)
    os << "Mounted Combatant, ";
  if (observant)
    os << "Observant, ";
  if (polearm_master)
    os << "Polearm Master, ";
  if (resilient)
    os << "Resilient, ";
  if (ritual_caster)
    os << "Ritual Caster, ";
  if (savage_attacker)
    os << "Savage Attacker, ";
  if (sentinel)
    os << "Sentinel, ";
  if (sharpshooter)
    os << "Sharpshooter, ";
  if (shield_master)
    os << "Shield Master, ";
  if (skilled)
    os << "Skilled, ";
  if (skulker)
    os << "Skulker, ";
  if (spell_sniper)
    os << "Spell Sniper, ";
  if (svirfneblin_magic)
    os << "Svirfneblin Magic, ";
  if (tavern_brawler)
    os << "Tavern Brawler, ";
  if (tough)
    os << "Tough, ";
  if (war_caster)
    os << "War Caster, ";
  if (weapon_master)
    os << "Weapon Master.";
  os << '\n';

  //---------------------------PRINT OTHER ABILITES----------------------//

  os << "-> Other Abilities: ";
  if (artificers_lore)
    os << "Artificer's Lore, ";
  if (brave)
    os << "Brave, ";
  if (breath_weapon_acid)
    os << "Acid Breath Weapon, ";
  if (breath_weapon_cold)
    os << "Cold Breath Weapon, ";
  if (breath_weapon_fire)
    os << "Fire Breath Weapon, ";
  if (breath_weapon_ltg)
    os << "Lighting Breath Weapon, ";
  if (breath_weapon_poison)
    os << "Poison Breath Weapon, ";
  if (darkvision)
    os << "Darkvision, ";
  if (devils_tongue)
    os << "Devil's Tongue, ";
  if (draconic_ancestry_black)
    os << "Draconic Ancestry(black), ";
  if (draconic_ancestry_blue)
    os << "Draconic Ancestry(blue), ";
  if (draconic_ancestry_brass)
    os << "Draconic Ancestry(brass), ";
  if (draconic_ancestry_bronze)
    os << "Draconic Ancestry(bronze), ";
  if (draconic_ancestry_copper)
    os << "Draconic Ancestry(copper), ";
  if (draconic_ancestry_gold)
    os << "Draconic Ancestry(gold), ";
  if (draconic_ancestry_green)
    os << "Draconic Ancestry(green), ";
  if (draconic_ancestry_red)
    os << "Draconic Ancestry(red), ";
  if (draconic_ancestry_silver)
    os << "Draconic Ancestry(silver), ";
  if (draconic_ancestry_white)
    os << "Draconic Ancestry(white), ";
  if (drow_magic)
    os << "Drow Magic, ";
  if (drow_weapon_training)
    os << "Drow Weapon Training, ";
  if (dwarven_armor_training)
    os << "Dwarven Armor Training, ";
  if (dwarven_combat_training)
    os << "Dwarven Combat Training, ";
  if (dwarven_resilience)
    os << "Dwarven Resilience, ";
  if (dwarven_toughness)
    os << "Dwarven Toughness, ";
  if (duergar_resilience)
    os << "Duergar Resilience, ";
  if (duergar_magic)
    os << "Duergar Magic, ";
  if (elf_weapon_training)
    os << "Elf Weapon Training, ";
  if (expert_forgery)
    os << "Expert Forgery, ";
  if (fey_ancestry)
    os << "Fey Ancestry, ";
  if (fleet_of_foot)
    os << "Fleet of Foot, ";
  if (halflinglucky)
    os << "Lucky(halfling), ";
  if (halfling_nimbleness)
    os << "Halfling Nimbleness, ";
  if (healing_hands)
    os << "Healing Hands, ";
  if (hellfire)
    os << "Hellfire, ";
  if (hellish_resistance)
    os << "Hellish Resistance, ";
  if (infernal_legacy)
    os << "Infernal Legacy, ";
  if (light_bearer)
    os << "Light Bearer, ";
  if (mask_of_the_wild)
    os << "Mask of the Wild, ";
  if (mimicry)
    os << "Mimicry, ";
  if (natural_illusionist)
    os << "Natural Illusionist, ";
  if (naturally_stealthy)
    os << "Naturally Stealthy, ";
  if (necrotic_shroud)
    os << "Necrotic Shroud, ";
  if (radiant_consumption)
    os << "Radiant Consumption, ";
  if (radiant_soul)
    os << "Radiant Soul, ";
  if (speak_with_small_beasts)
    os << "Speak With Small Beasts, ";
  if (stonecunning)
    os << "Stonecunning, ";
  if (stone_camouflage)
    os << "Stone Camouflage, ";
  if (stones_endurance)
    os << "Stone's Endurance, ";
  if (stout_resilience)
    os << "Stout Resilience, ";
  if (superior_darkvision)
    os << "Superior Darkvision, ";
  if (trance)
    os << "Trance, ";
  if (firbolg_magic)
    os << "Firbolg Magic, ";
  if (hidden_step)
    os << "Hidden Step, ";
  if (powerful_build)
    os << "Powerful Build, ";
  if (speech_of_beast_and_leaf)
    os << "Speech of Beast and Leaf, ";
  if (silent_speech)
    os << "Silent Speech, ";
  // lizardfolk stuff
  if (lizardfolk_bite)
    os << "Bite, ";
  if (cunning_artisan)
    os << "Cunning Artisan, ";
  if (hold_breath)
    os << "Hold Breath(" << hold_breath << "m), ";
  if (natural_armor)
    os << "Natural Armor(" << natural_armor << "AC), ";
  if (hungry_jaws)
    os << "Hungry Jaws, ";
  // tabaxi stuff
  if (feline_agility)
    os << "Feline Agility, ";
  if (cats_claws)
    os << "Cat's Claws, ";
  // Triton stuff
  if (amphibious)
    os << "Amphibious, ";
  if (control_air_and_water)
    os << "Control Air and Water, ";
  if (emissary_of_the_sea)
    os << "Emissary of the Sea, ";
  if (guardian_of_the_depths)
    os << "Guardian of the Depths, ";
  // Warforged stuff
  if (composite_plating)
    os << "Composite Plating, ";
  if (living_construct)
    os << "Living Construct, ";
  // changeling stuff
  if (shapechanger)
    os << "Shapechanger, ";
  // shifter stuff
  if (shifting)
    os << "Shifting, ";
  // tortle package stuff
  if (shell)
    os << "Shell, ";
  if (retreat_to_shell)
    os << "Retreat to Shell, ";
  if (turtle_snapper)
    os << "Turtle Snapper, ";
  if (razorback)
    os << "Razorback, ";
  if (softshell)
    os << "Softshell, ";
  if (nomad)
    os << "Nomad, ";
  if (shell_master)
    os << "Shell Master, ";
  //aarakocra stuff
  if (talons)
    os << "Talons, ";
  //genasi stuff
  if (unending_breath)
    os << "Unending Breath, ";
  if (mingle_with_the_wind)
    os << "Mingle with the Wind, ";
  if (earth_walk)
    os << "Earth Walk, ";
  if (merge_with_stone)
    os << "Merge with Stone, ";
  if (reach_to_the_blaze)
    os << "Reach to the Blaze, ";
  if (call_to_the_wave)
    os << "Call to the Wave, ";

  os << '\n';

  //-------------------------PRINT LANGUAGES------------------------//

  os << "-> Languages: ";
  if (aarakocra)
    os << "Aarakocra, ";
  if (abyssal)
    os << "Abyssal, ";
  if (aquan)
    os << "Aquan, ";
  if (auran)
    os << "Auran, ";
  if (celestial)
    os << "Celestial, ";
  if (common)
    os << "Common, ";
  if (deep_speech)
    os << "Deep Speech, ";
  if (draconic)
    os << "Draconic, ";
  if (druidic)
    os << "Druidic, ";
  if (dwarvish)
    os << "Dwarvish, ";
  if (elvish)
    os << "Elvish, ";
  if (giant)
    os << "Giant, ";
  if (gnomish)
    os << "Gnomish, ";
  if (goblin)
    os << "Goblin, ";
  if (gnoll)
    os << "Gnoll, ";
  if (halfling)
    os << "Halfling, ";
  if (infernal)
    os << "Infernal, ";
  if (orc)
    os << "Orc, ";
  if (primordial)
    os << "Primordial, ";
  if (sylvan)
    os << "Sylvan, ";
  if (undercommon)
    os << "Undercommon.";
  os << '\n';

  //---------------------ARTISAN TOOLS------------------------------//

  os << "-> Artisan's Tools: ";
  if (alchemist)
    os << "Alchemist's supplies, ";
  if (brewer)
    os << "Brewer's supplies, ";
  if (calligrapher)
    os << "Calligrapher's supplies, ";
  if (carpenter)
    os << "Carpenter's tools, ";
  if (cartographer)
    os << "Cartographer's tools, ";
  if (cobbler)
    os << "Cobbler's tools, ";
  if (cook)
    os << "Cook's utensils, ";
  if (glassblower)
    os << "Glassblower's tools, ";
  if (jeweler)
    os << "Jeweler's tools, ";
  if (leatherworker)
    os << "Leatherwoker's tools, ";
  if (mason)
    os << "Mason's tools, ";
  if (painter)
    os << "Painter's supplies, ";
  if (potter)
    os << "Potter's tools, ";
  if (smith)
    os << "Smith's tools, ";
  if (tinker)
    os << "Tinker's tools, ";
  if (weaver)
    os << "Weaver's tools, ";
  if (woodcarver)
    os << "Woodcarver's tools.";
  os << '\n';

  //-----------------------PRINT OTHER KITS AND TOOLS-------------------//
  os << "-> Other Kits and Tools: ";
  if (disguise)
    os << "Disguise kit, ";
  if (forgery)
    os << "Forgery kit, ";
  if (herbalism)
    os << "Herbalism kit, ";
  if (navigator)
    os << "Navigator's tools, ";
  if (poisoner)
    os << "Poisoner's kit, ";
  if (thieves)
    os << "Thieves' tools, ";
  if (vehicle)
    os << "Vehicle(land or water).";
  os << '\n';
  os << "-> Musical Instrument(s): ";
  if (bagpipes)
    os << "Bagpipes, ";
  if (drum)
    os << "Drums, ";
  if (dulcimer)
    os << "Dulcimer, ";
  if (flute)
    os << "Flute, ";
  if (lute)
    os << "Lute, ";
  if (lyre)
    os << "Lyre, ";
  if (horn)
    os << "Horn, ";
  if (pan_flute)
    os << "Pan flute, ";
  if (shawm)
    os << "Shawm, ";
  if (viol)
    os << "Viol.";
  os << '\n';

  //------------------------PRINT RESISTANCES----------------------//

  os << "-> Resistances: ";
  if (damage_resist_acid)
    os << "Acid, ";
  if (damage_resist_ltg)
    os << "Lightning, ";
  if (damage_resist_fire)
    os << "Fire, ";
  if (damage_resist_poison)
    os << "Poison, ";
  if (damage_resist_cold)
    os << "Cold, ";
  if (damage_resist_necrotic)
    os << "Necrotic, ";
  if (damage_resist_radiant)
    os << "Radiant";
  os << '\n';

  //-------------------PRINT DISADVANTAGES-------------------------//
  os << "-> Disadvantages: ";
  if (sunlight_sensitivity)
    os << "Sunlight Sensitivty" << '\n';

  os << '\n';

}