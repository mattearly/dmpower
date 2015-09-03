//
//  campaign.cpp
//  DM-Power
//
//  Created by Matthew Early on 6/22/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#include "campaign.h"

using namespace std;

void Campaign::pc_menu() {
    int choice = 0;
    while (choice != 7) {
        simpleClearScreen();
        cout << "--->Make a Selection<---\n\n"
             << " 1. Create New Player Character" << endl
             << " 2. Display PC's Character Sheet" << endl
             << " 3. Edit a PC" << endl
             << " 4. List all PC's" << endl
             << " 5. Delete a PC" << endl
             << " 6. Delete ALL PC's" << endl
             << " 7. Back to Main Menu" << endl << endl;
        choice = getNumber("Choice(1-7): ", 1, 7);
        switch (choice) {
        case 1:
        {
            simpleClearScreen();
            cout << "Create a New Character!\n\n";
            cout << "Character Class:\n\n"
                 << " 1. Cleric      7. Paladin"
                 << "\n 2. Fighter     8. Sorcerer"
                 << "\n 3. Rogue       9. Bard"
                 << "\n 4. Wizard     10. Monk"
                 << "\n 5. Barbarian  11. Ranger"
                 << "\n 6. Druid      12. Warlock\n\n";
            int select_class = getNumber("Class Choice(1-12): ", 1, 12);
            int starting_level = getNumber("Starting Level(1-20): ", 1, 20);
            switch (select_class) {
            case 1:
            {
                tmp = new Cleric;
                makecharacter(tmp, starting_level);
            }
                break;
            case 2:
            {
                tmp = new Fighter;
                makecharacter(tmp, starting_level);
            }
                break;
            case 3:
            {
                tmp = new Rogue;
                makecharacter(tmp, starting_level);
            }
                break;
            case 4:
            {
                tmp = new Wizard;
                makecharacter(tmp, starting_level);
            }
                break;
            case 5:
            {
                tmp = new Barbarian;
                makecharacter(tmp, starting_level);
            }
                break;
            case 6:
            {
                tmp = new Druid;
                makecharacter(tmp, starting_level);
            }
                break;
            case 7:
            {
                tmp = new Paladin;
                makecharacter(tmp, starting_level);
            }
                break;
            case 8:
            {
                tmp = new Sorcerer;
                makecharacter(tmp, starting_level);
            }
                break;
            case 9:
            {
                tmp = new Bard;
                makecharacter(tmp, starting_level);
            }
                break;
            case 10:
            {
                tmp = new Monk;
                makecharacter(tmp, starting_level);
            }
                break;
            case 11:
            {
                tmp = new Ranger;
                makecharacter(tmp, starting_level);
            }
                break;
            case 12:
            {
                tmp = new Warlock;
                makecharacter(tmp, starting_level);
            }
            default:;
            }
        }
            break;
        case 2: {  //CHARACTER SHEET
            if (character_list.size() < 1) {
                cout << "\nNothing to display. Create characters first.\n";
            } else {
                bool found = false;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string valid_name;
                while (!found) {
                    cout << "Name of Character to Display Character Sheet of: ";
                    getline(cin, valid_name);
                    valid_name[0] = toupper(valid_name[0]);
                    for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                        if ((*it)->name == valid_name) {
                            found = true;
                        }
                    }
                    if (found == false) cout << "No character named " << valid_name << ". List of Charcters:\n";
                    for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                        cout << (*it)->name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << endl;
                    }
                }
                for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                    if (valid_name == (*it)->name) (*it)->character_sheet();
                }
            }
        }
            pressEnterToContinue();
            break;
        case 3: {  //EDIT/UPDATE CHARACTER
                if (character_list.size() < 1) {
                    cout << "No characters to Edit. Create characters first.\n\n";
                } else {
                    bool found = false;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string valid_name;
                    while (!found) {
                        cout << "Name of Character to Edit/Update: ";
                        getline(cin, valid_name);
                        valid_name[0] = toupper(valid_name[0]);
                        for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                            if ((*it)->name == valid_name) {
                                found = true;
                            }
                        }
                        if (found == false) cout << "\nNo character named " << valid_name << ". List of Charcters:\n\n";
                        for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                            cout << (*it)->name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << endl;
                        }
                        cout << endl;
                    }
                    for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                        if (valid_name == (*it)->name) (*it)->updateCharacter(*this);
                    }
                }
            }
            pressEnterToContinue();
            break;
        case 4: {
            if (character_list.size() < 1) {
                cout << "Nothing to list. Create some Characters first.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nCharacters built:\n\n";
                for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                    cout << (*it)->name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << endl;
                }
            }
        }
            pressEnterToContinue();
            break;
        case 5: {   //DELETE CHARACTER
            if (character_list.size() < 1) {
                cout << "Already 0 characters. Nothing to Delete! \n";
            } else {
                string tmp;
                do {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter the name of the PC to Delete(leave blank to exit function): ";
                    getline(cin, tmp);
                    tmp[0] = toupper(tmp[0]);
                    for (list<Generic_Character_Class*>::iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                        if ((*it)->name == tmp) {
                            cout << "Deleting " << tmp << ". Goodbye " << tmp << endl;
                            character_list.erase(it);
                            return;
                        }
                    }
                } while (tmp != "");
            }
        }
            pressEnterToContinue();
            break;
        case 6: {  //DELETE ALL THE THINGS
            char sure = getYorN("Are you Sure you want to Delete All Player Characters?(y/n):");
            if (sure == 'Y') {
                character_list.clear();
                cout << "All Characters Deleted. Press 'Cntl + C' now to make sure this change doesn't save or just Enter to continue.\n\n";
            } else {
                cout << "Nothing Deleted.\n\n";
            }
        }
            pressEnterToContinue();
        default:;
        }
    }
}
bool Campaign::checkname(const string& n) const {
    for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
        if ((*it)->name == n) {
            cout << "Name Already Exists.\n";
            return false;
        }
    }
    return true;
}
void Campaign::makecharacter(Generic_Character_Class *tmp, int& starting_level) {
    bool goodname= false;
    while (!goodname) {
        tmp->setName();
        goodname = checkname(tmp->name);
    }
    tmp->setAllStats();
    tmp->setRace(*tmp);
    tmp->setAlignment();
    tmp->setBackground();
    tmp->setClassDetails(starting_level);
    tmp->setProficiencyBonus();
    character_list.push_back(tmp);
    tmp->initialSkillsSet = true;
    char ans = getYorN("Display Character Sheet now? (Y/N):");
    if (ans == 'Y') character_list.back()->character_sheet();
    pressEnterToContinue();
}
ofstream& Campaign::dumpCharacter(ofstream& os) {
    int charactercount = 0;
    for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
        charactercount++;
        os
                << "saved character: " << charactercount << endl
                   //basics
                << (*it)->char_class << endl
                << (*it)->name << endl
                << (*it)->race << endl
                << (*it)->alignment << endl
                << (*it)->level << endl
                << (*it)->levelupmenus << endl
                << (*it)->backgroundofpc << endl
                << (*it)->move_speed << endl
                << (*it)->hitdicesize << endl
                << (*it)->proficiency_bonus << endl
                << (*it)->strength << endl
                << (*it)->dexterity << endl
                << (*it)->constitution << endl
                << (*it)->intelligence << endl
                << (*it)->wisdom << endl
                << (*it)->charisma << endl
                << (*it)->strSave << endl
                << (*it)->dexSave << endl
                << (*it)->conSave << endl
                << (*it)->intSave << endl
                << (*it)->wisSave << endl
                << (*it)->chaSave << endl
                   //class stuff - general
                << "generalclassstuff" << endl
                << (*it)->extra_attack << endl
                << (*it)->expertise << endl
                << (*it)->spellcasting << endl
                << (*it)->timeless_body << endl
                << (*it)->evasion << endl
                << (*it)->unarmored_defense << endl
                << (*it)->fighting_style << endl
                << (*it)->defense << endl
                << (*it)->dueling << endl
                << (*it)->great_weapon_fighting << endl
                << (*it)->protection << endl
                << "cleric" << endl
                << (*it)->destroy_undead << endl  //cleric
                << (*it)->channel_divinity << endl
                << (*it)->divine_domain_feature << endl
                << (*it)->divine_intervention <<endl
                << (*it)->cleric_cantrips_known << endl
                << (*it)->divine_domain << endl
                << (*it)->knowledge_d << endl
                << (*it)->life_d << endl
                << (*it)->light_d << endl
                << (*it)->nature_d << endl
                << (*it)->tempest_d << endl
                << (*it)->trickery_d << endl
                << (*it)->war_d << endl
                << "fighter" << endl
                << (*it)->action_surge << endl   //fighter
                << (*it)->martial_archtype_feature << endl
                << (*it)->indomitable << endl
                << (*it)->eldritch_spells_known << endl
                << (*it)->second_wind << endl
                << (*it)->martial_archtype << endl
                << (*it)->archery << endl
                << (*it)->two_weapon_fighting << endl
                << (*it)->champion << endl
                << (*it)->battle_master << endl
                << (*it)->eldritch_knight << endl
                << "barbarian" << endl
                << (*it)->rages << endl  //barbarian
                << (*it)->rage_damage << endl
                << (*it)->path_feature << endl
                << (*it)->brutal_critical << endl
                << (*it)->reckless_attack << endl
                << (*it)->danger_sense << endl
                << (*it)->primal_path << endl
                << (*it)->fast_movement << endl
                << (*it)->feral_instinct << endl
                << (*it)->relentless_rage << endl
                << (*it)->persistant_rage << endl
                << (*it)->indomitable_might << endl
                << (*it)->primal_champion << endl
                << (*it)->path_of_the_berseker << endl
                << (*it)->path_of_the_totem_warrior << endl
                << (*it)->bear_totem << endl
                << (*it)->eagle_totem << endl
                << (*it)->wolf_totem << endl
                << "bard" << endl
                << (*it)->bardic_inspiration << endl //bard
                << (*it)->song_of_rest << endl
                << (*it)->bard_college_feature << endl
                << (*it)->magical_secrets << endl
                << (*it)->bard_spells_known << endl
                << (*it)->bard_cantrips_known << endl
                << (*it)->jack_of_all_trades << endl
                << (*it)->bard_college << endl
                << (*it)->font_of_inspiration << endl
                << (*it)->countercharm << endl
                << (*it)->superior_inspiration << endl
                << (*it)->college_of_lore << endl
                << (*it)->college_of_valor << endl
                << (*it)->additional_magical_secrets << endl
                << "druid" << endl
                << (*it)->wild_shape_improvement << endl //druid
                << (*it)->druid_circle_feature << endl
                << (*it)->druid_cantrips_known << endl
                << (*it)->druidic << endl
                << (*it)->wild_shape << endl
                << (*it)->druid_circle << endl
                << (*it)->beast_spells << endl
                << (*it)->archdruid << endl
                << (*it)->circle_of_the_moon << endl
                << (*it)->circle_of_the_land << endl
                << "monk" << endl
                << (*it)->monastic_tradition_feature << endl //monk
                << (*it)->ki << endl
                << (*it)->unarmored_movement << endl
                << (*it)->martial_arts << endl
                << (*it)->monastic_tradition << endl
                << (*it)->deflect_missles << endl
                << (*it)->slow_fall << endl
                << (*it)->stunning_strike << endl
                << (*it)->ki_empowered_strikes << endl
                << (*it)->stillness_of_mind << endl
                << (*it)->purity_of_body << endl
                << (*it)->tongue_of_the_sun_and_moon << endl
                << (*it)->diamond_soul << endl
                << (*it)->empty_body << endl
                << (*it)->perfect_self << endl
                << (*it)->way_of_the_open_hand << endl
                << (*it)->way_of_the_four_elements << endl
                << (*it)->way_of_the_shadow << endl
                << (*it)->unarmored_movement_improvement << endl
                << "paladin" << endl
                << (*it)->sacred_oath_feature << endl //paladin
                << (*it)->divine_smite << endl
                << (*it)->divine_sense << endl
                << (*it)->lay_on_hands << endl
                << (*it)->divine_health << endl
                << (*it)->sacred_oath << endl
                << (*it)->aura_of_protection << endl
                << (*it)->aura_of_courage << endl
                << (*it)->cleansing_touch << endl
                << (*it)->aura_improvments << endl
                << (*it)->oath_of_devotion << endl
                << (*it)->oath_of_ancients << endl
                << (*it)->oath_of_vengence << endl
                << "ranger" << endl
                << (*it)->favored_enemy << endl  //ranger
                << (*it)->natural_explorer << endl
                << (*it)->ranger_archetype_feature << endl
                << (*it)->ranger_spells_known << endl
                << (*it)->ranger_archetype << endl
                << (*it)->primeval_awareness << endl
                << (*it)->lands_stride << endl
                << (*it)->hide_in_plain_sight << endl
                << (*it)->vanish << endl
                << (*it)->feral_senses << endl
                << (*it)->foe_slayer << endl
                << (*it)->hunter << endl
                << (*it)->beast_master << endl
                << "rogue" << endl
                << (*it)->roguish_archetype_feature << endl //rogue
                << (*it)->arcane_t_spells_known << endl
                << (*it)->sneak_attack << endl
                << (*it)->thieves_cant << endl
                << (*it)->cunning_action << endl
                << (*it)->roguish_archetype << endl
                << (*it)->uncanny_dodge << endl
                << (*it)->reliable_talent << endl
                << (*it)->blindsense << endl
                << (*it)->slippery_mind << endl
                << (*it)->elusive << endl
                << (*it)->stroke_of_luck << endl
                << (*it)->thief << endl
                << (*it)->assassin << endl
                << (*it)->arcane_trickster << endl
                << "sorcerer" << endl
                << (*it)->sorcerous_origin_feature << endl  //sorcerer
                << (*it)->metamagic << endl
                << (*it)->sorcery_points << endl
                << (*it)->sorcerer_spells_known << endl
                << (*it)->sorcerer_cantrips_known << endl
                << (*it)->sorcerous_origin << endl
                << (*it)->font_of_magic << endl
                << (*it)->sorcerous_restoration << endl
                << (*it)->draconic_bloodline << endl
                << (*it)->wild_magic << endl
                << "warlock" << endl
                << (*it)->warlock_slot_level << endl //warlock
                << (*it)->eldritch_invocations_known << endl
                << (*it)->warlock_spells_known << endl
                << (*it)->warlock_spell_slots << endl
                << (*it)->warlock_cantrips_known << endl
                << (*it)->otherworldly_patron_feature << endl
                << (*it)->mystic_arcanum << endl
                << (*it)->otherworldly_patron << endl
                << (*it)->pact_magic << endl
                << (*it)->pact_boon << endl
                << (*it)->eldritch_master << endl
                << (*it)->archfey << endl
                << (*it)->fiend << endl
                << (*it)->great_old_one << endl
                << "wizard" << endl
                << (*it)->arcane_tradition_feature << endl //wizard
                << (*it)->wizard_cantrips_known << endl
                << (*it)->arcane_recovery << endl
                << (*it)->arcane_tradition << endl
                << (*it)->spell_mastery << endl
                << (*it)->signature_spell << endl
                << (*it)->abjuration << endl
                << (*it)->conjuration << endl
                << (*it)->divination << endl
                << (*it)->enchantment << endl
                << (*it)->evocation << endl
                << (*it)->illusion << endl
                << (*it)->necromancy << endl
                << (*it)->transmutation << endl
                << "landtypes" << endl //landtypes
                << (*it)->artic << endl
                << (*it)->coast << endl
                << (*it)->desert << endl
                << (*it)->forest << endl
                << (*it)->grassland << endl
                << (*it)->mountain << endl
                << (*it)->swamp << endl
                << (*it)->underdark << endl
                << "creaturetype" << endl   //creaturetype
                << (*it)->twohumanoids << endl
                << (*it)->aberrations << endl
                << (*it)->beasts << endl
                << (*it)->celestials << endl
                << (*it)->constructs << endl
                << (*it)->dragons << endl
                << (*it)->elementals << endl
                << (*it)->fey << endl
                << (*it)->fiends << endl
                << (*it)->giants << endl
                << (*it)->monstrosities << endl
                << (*it)->oozes << endl
                << (*it)->plants << endl
                << (*it)->undead << endl
                << "spellslots" << endl //spellslots
                << (*it)->first_ss << endl
                << (*it)->second_ss << endl
                << (*it)->third_ss << endl
                << (*it)->forth_ss << endl
                << (*it)->fifth_ss << endl
                << (*it)->sixth_ss << endl
                << (*it)->seventh_ss << endl
                << (*it)->eighth_ss << endl
                << (*it)->ninth_ss << endl
                << (*it)->warlock_ss << endl
                << "skills" << endl   //skills
                << (*it)->initialSkillsSet << endl
                << (*it)->acrobatics << endl
                << (*it)->animal_handling << endl
                << (*it)->arcana << endl
                << (*it)->athletics << endl
                << (*it)->deception << endl
                << (*it)->history << endl
                << (*it)->insight << endl
                << (*it)->intimidation << endl
                << (*it)->investigation << endl
                << (*it)->medicine << endl
                << (*it)->nature << endl
                << (*it)->perception << endl
                << (*it)->performance << endl
                << (*it)->persuasion << endl
                << (*it)->religion << endl
                << (*it)->sleight_of_hand << endl
                << (*it)->stealth << endl
                << (*it)->survival << endl
                << "feats" << endl   //feats
                << (*it)->alert << endl
                << (*it)->athlete << endl
                << (*it)->actor << endl
                << (*it)->charger << endl
                << (*it)->crossbow_expert << endl
                << (*it)->defensive_duelist << endl
                << (*it)->dual_wielder << endl
                << (*it)->dungeon_delver << endl
                << (*it)->durable << endl
                << (*it)->elemental_adept << endl
                << (*it)->grappler << endl
                << (*it)->great_weapon_master << endl
                << (*it)->healer << endl
                << (*it)->heavily_armored << endl
                << (*it)->heavy_armor_master << endl
                << (*it)->inspiring_leader << endl
                << (*it)->keen_mind << endl
                << (*it)->lightly_armored << endl
                << (*it)->linguist << endl
                << (*it)->lucky << endl
                << (*it)->mage_slayer << endl
                << (*it)->magic_initiate << endl
                << (*it)->martial_adept << endl
                << (*it)->medium_armor_master << endl
                << (*it)->mobile << endl
                << (*it)->moderately_armored << endl
                << (*it)->mounted_combatant << endl
                << (*it)->observant << endl
                << (*it)->polearm_master << endl
                << (*it)->resilient << endl
                << (*it)->ritual_caster << endl
                << (*it)->savage_attacker << endl
                << (*it)->sentinel << endl
                << (*it)->sharpshooter << endl
                << (*it)->shield_master << endl
                << (*it)->skilled << endl
                << (*it)->skulker << endl
                << (*it)->spell_sniper << endl
                << (*it)->tavern_brawler << endl
                << (*it)->tough << endl
                << (*it)->war_caster << endl
                << (*it)->weapon_master << endl
                << "languages" << endl   //languages
                << (*it)->abyssal << endl
                << (*it)->celestial << endl
                << (*it)->common << endl
                << (*it)->deep_speech << endl
                << (*it)->draconic << endl
                << (*it)->dwarvish << endl
                << (*it)->elvish << endl
                << (*it)->giant << endl
                << (*it)->gnomish << endl
                << (*it)->goblin << endl
                << (*it)->gnoll << endl
                << (*it)->halfling << endl
                << (*it)->infernal << endl
                << (*it)->orc << endl
                << (*it)->primordial << endl
                << (*it)->sylvan << endl
                << (*it)->undercommon << endl
                << "features" << endl   //features
                << (*it)->artificers_lore << endl
                << (*it)->brave << endl
                << (*it)->breath_weapon_acid << endl
                << (*it)->breath_weapon_ltg << endl
                << (*it)->breath_weapon_fire << endl
                << (*it)->breath_weapon_poison << endl
                << (*it)->breath_weapon_cold << endl
                << (*it)->darkvision << endl
                << (*it)->draconic_ancestry_black << endl
                << (*it)->draconic_ancestry_blue << endl
                << (*it)->draconic_ancestry_brass << endl
                << (*it)->draconic_ancestry_bronze << endl
                << (*it)->draconic_ancestry_copper << endl
                << (*it)->draconic_ancestry_gold << endl
                << (*it)->draconic_ancestry_green << endl
                << (*it)->draconic_ancestry_red << endl
                << (*it)->draconic_ancestry_silver << endl
                << (*it)->draconic_ancestry_white << endl
                << (*it)->drow_magic << endl
                << (*it)->drow_weapon_training << endl
                << (*it)->dwarven_armor_training << endl
                << (*it)->dwarven_combat_training << endl
                << (*it)->dwarven_resilience << endl
                << (*it)->dwarven_toughness << endl
                << (*it)->elf_weapon_training << endl
                << (*it)->fey_ancestry << endl
                << (*it)->fleet_of_foot << endl
                << (*it)->halflinglucky << endl
                << (*it)->halfling_nimbleness << endl
                << (*it)->hellish_resistance << endl
                << (*it)->infernal_legacy << endl
                << (*it)->mask_of_the_wild << endl
                << (*it)->natural_illusionist << endl
                << (*it)->naturally_stealthy << endl
                << (*it)->speak_with_small_beasts << endl
                << (*it)->stonecunning << endl
                << (*it)->stout_resilience << endl
                << (*it)->superior_darkvision << endl
                << (*it)->trance << endl
                << "resistances" << endl   //resistances
                << (*it)->damage_resist_acid << endl
                << (*it)->damage_resist_ltg << endl
                << (*it)->damage_resist_fire << endl
                << (*it)->damage_resist_poison << endl
                << (*it)->damage_resist_cold << endl
                << "disadvantages" << endl   //disadvantages
                << (*it)->sunlight_sensitivity << endl
                << "tools" << endl   //artisan tools & supplies
                << (*it)->alchemist << endl
                << (*it)->brewer << endl
                << (*it)->calligrapher << endl
                << (*it)->carpenter << endl
                << (*it)->cartographer << endl
                << (*it)->cobbler << endl
                << (*it)->cook << endl
                << (*it)->glassblower << endl
                << (*it)->jeweler << endl
                << (*it)->leatherworker << endl
                << (*it)->mason << endl
                << (*it)->painter << endl
                << (*it)->potter << endl
                << (*it)->smith << endl
                << (*it)->tinker << endl
                << (*it)->weaver << endl
                << (*it)->woodcarver << endl
                << "kits" << endl   //kits & tools
                << (*it)->disguise << endl
                << (*it)->forgery << endl
                << (*it)->herbalism << endl
                << (*it)->navigator << endl
                << (*it)->poisoner << endl
                << (*it)->thieves << endl
                << (*it)->vehicle << endl
                << "musicalinstruments" << endl   //musical instruments
                << (*it)->bagpipes << endl
                << (*it)->drum << endl
                << (*it)->dulcimer << endl
                << (*it)->flute << endl
                << (*it)->lute << endl
                << (*it)->lyre << endl
                << (*it)->horn << endl
                << (*it)->pan_flute << endl
                << (*it)->shawm << endl
                << (*it)->viol << endl;
    }
    return os;
}
ifstream& Campaign::retrieveCharacter(ifstream& ins) {
    string tmp;
    int processor;
    Generic_Character_Class* v;
    while (!ins.eof()) {
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //   >> "characte count x"

        int len = ins.tellg(); //get current position
        getline(ins, tmp);
        if (tmp == "Cleric") v = new Cleric;
        else if (tmp == "Fighter") v = new Fighter;
        else if (tmp == "Barbarian") v = new Barbarian;
        else if (tmp == "Bard") v = new Bard;
        else if (tmp == "Druid") v = new Druid;
        else if (tmp == "Monk") v = new Monk;
        else if (tmp == "Paladin") v = new Paladin;
        else if (tmp == "Ranger") v = new Ranger;
        else if (tmp == "Rogue") v = new Rogue;
        else if (tmp == "Sorcerer") v = new Sorcerer;
        else if (tmp == "Warlock") v = new Warlock;
        else v = new Wizard;
        ins.seekg(len, ios_base::beg);  //return to position

        getline(ins, v->char_class);  //  >> (*it)->char_class
        getline(ins, v->name);   // >> (*it)->name
        getline(ins, v->race);   // >> (*it)->race
        getline(ins, v->alignment);
        ins >> v->level;
        ins >> v->levelupmenus;
        ins >> processor;
        v->backgroundofpc = static_cast<enum Generic_Character_Class::characterbackground>(processor);
        ins >> v->move_speed;
        ins >> v->hitdicesize;
        ins >> v->proficiency_bonus;
        ins >> v->strength;
        ins >> v->dexterity;
        ins >> v->constitution;
        ins >> v->intelligence;
        ins >> v->wisdom;
        ins >> v->charisma;
        ins >> v->strSave;
        ins >> v->dexSave;
        ins >> v->conSave;
        ins >> v->intSave;
        ins >> v->wisSave;
        ins >> v->chaSave;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');   // >> "gca"  class stuff general
        ins >> v->extra_attack;
        ins >> v->expertise;
        ins >> v->spellcasting;
        ins >> v->timeless_body;
        ins >> v->evasion;
        ins >> v->unarmored_defense;
        ins >> v->fighting_style;
        ins >> v->defense;
        ins >> v->dueling;
        ins >> v->great_weapon_fighting;
        ins >> v->protection;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); // >> "cleric"
        ins >> v->destroy_undead;  //cleric
        ins >> v->channel_divinity;
        ins >> v->divine_domain_feature;
        ins >> v->divine_intervention;
        ins >> v->cleric_cantrips_known;
        ins >> v->divine_domain;
        ins >> v->knowledge_d;
        ins >> v->life_d;
        ins >> v->light_d;
        ins >> v->nature_d;
        ins >> v->tempest_d;
        ins >> v->trickery_d;
        ins >> v->war_d;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); // >> "fighter"
        ins >> v->action_surge;   //fighter
        ins >> v->martial_archtype_feature;
        ins >> v->indomitable;
        ins >> v->eldritch_spells_known;
        ins >> v->second_wind;
        ins >> v->martial_archtype;
        ins >> v->archery;
        ins >> v->two_weapon_fighting;
        ins >> v->champion;
        ins >> v->battle_master;
        ins >> v->eldritch_knight;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); // >> "barbarian"
        ins >> v->rages;  //barbarian
        ins >> v->rage_damage;
        ins >> v->path_feature;
        ins >> v->brutal_critical;
        ins >> v->reckless_attack;
        ins >> v->danger_sense;
        ins >> v->primal_path;
        ins >> v->fast_movement;
        ins >> v->feral_instinct;
        ins >> v->relentless_rage;
        ins >> v->persistant_rage;
        ins >> v->indomitable_might;
        ins >> v->primal_champion;
        ins >> v->path_of_the_berseker;
        ins >> v->path_of_the_totem_warrior;
        ins >> v->bear_totem;
        ins >> v->eagle_totem;
        ins >> v->wolf_totem;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "bard"
        ins >> v->bardic_inspiration; //bard
        ins >> v->song_of_rest;
        ins >> v->bard_college_feature;
        ins >> v->magical_secrets;
        ins >> v->bard_spells_known;
        ins >> v->bard_cantrips_known;
        ins >> v->jack_of_all_trades;
        ins >> v->bard_college;
        ins >> v->font_of_inspiration;
        ins >> v->countercharm;
        ins >> v->superior_inspiration;
        ins >> v->college_of_lore;
        ins >> v->college_of_valor;
        ins >> v->additional_magical_secrets;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "druid"
        ins >> v->wild_shape_improvement; //druid
        ins >> v->druid_circle_feature;
        ins >> v->druid_cantrips_known;
        ins >> v->druidic;
        ins >> v->wild_shape;
        ins >> v->druid_circle;
        ins >> v->beast_spells;
        ins >> v->archdruid;
        ins >> v->circle_of_the_moon;
        ins >> v->circle_of_the_land;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "monk"
        ins >> v->monastic_tradition_feature; //monk
        ins >> v->ki;
        ins >> v->unarmored_movement;
        ins >> v->martial_arts;
        ins >> v->monastic_tradition;
        ins >> v->deflect_missles;
        ins >> v->slow_fall;
        ins >> v->stunning_strike;
        ins >> v->ki_empowered_strikes;
        ins >> v->stillness_of_mind;
        ins >> v->purity_of_body;
        ins >> v->tongue_of_the_sun_and_moon;
        ins >> v->diamond_soul;
        ins >> v->empty_body;
        ins >> v->perfect_self;
        ins >> v->way_of_the_open_hand;
        ins >> v->way_of_the_four_elements;
        ins >> v->way_of_the_shadow;
        ins >> v->unarmored_movement_improvement;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "paladin"
        ins >> v->sacred_oath_feature; //paladin
        ins >> v->divine_smite;
        ins >> v->divine_sense;
        ins >> v->lay_on_hands;
        ins >> v->divine_health;
        ins >> v->sacred_oath;
        ins >> v->aura_of_protection;
        ins >> v->aura_of_courage;
        ins >> v->cleansing_touch;
        ins >> v->aura_improvments;
        ins >> v->oath_of_devotion;
        ins >> v->oath_of_ancients;
        ins >> v->oath_of_vengence;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "ranger"
        ins >> v->favored_enemy;  //ranger
        ins >> v->natural_explorer;
        ins >> v->ranger_archetype_feature;
        ins >> v->ranger_spells_known;
        ins >> v->ranger_archetype;
        ins >> v->primeval_awareness;
        ins >> v->lands_stride;
        ins >> v->hide_in_plain_sight;
        ins >> v->vanish;
        ins >> v->feral_senses;
        ins >> v->foe_slayer;
        ins >> v->hunter;
        ins >> v->beast_master;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "rogue"
        ins >> v->roguish_archetype_feature; //rogue
        ins >> v->arcane_t_spells_known;
        ins >> v->sneak_attack;
        ins >> v->thieves_cant;
        ins >> v->cunning_action;
        ins >> v->roguish_archetype;
        ins >> v->uncanny_dodge;
        ins >> v->reliable_talent;
        ins >> v->blindsense;
        ins >> v->slippery_mind;
        ins >> v->elusive;
        ins >> v->stroke_of_luck;
        ins >> v->thief;
        ins >> v->assassin;
        ins >> v->arcane_trickster;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "sorcerer"
        ins >> v->sorcerous_origin_feature;  //sorcerer
        ins >> v->metamagic;
        ins >> v->sorcery_points;
        ins >> v->sorcerer_spells_known;
        ins >> v->sorcerer_cantrips_known;
        ins >> v->sorcerous_origin;
        ins >> v->font_of_magic;
        ins >> v->sorcerous_restoration;
        ins >> v->draconic_bloodline;
        ins >> v->wild_magic;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "warlock"
        ins >> v->warlock_slot_level; //warlock
        ins >> v->eldritch_invocations_known;
        ins >> v->warlock_spells_known;
        ins >> v->warlock_spell_slots;
        ins >> v->warlock_cantrips_known;
        ins >> v->otherworldly_patron_feature;
        ins >> v->mystic_arcanum;
        ins >> v->otherworldly_patron;
        ins >> v->pact_magic;
        ins >> v->pact_boon;
        ins >> v->eldritch_master;
        ins >> v->archfey;
        ins >> v->fiend;
        ins >> v->great_old_one;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "wizard"
        ins >> v->arcane_tradition_feature; //wizard
        ins >> v->wizard_cantrips_known;
        ins >> v->arcane_recovery;
        ins >> v->arcane_tradition;
        ins >> v->spell_mastery;
        ins >> v->signature_spell;
        ins >> v->abjuration;
        ins >> v->conjuration;
        ins >> v->divination;
        ins >> v->enchantment;
        ins >> v->evocation;
        ins >> v->illusion;
        ins >> v->necromancy;
        ins >> v->transmutation;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "landtypes" //landtypes
        ins >> v->artic;
        ins >> v->coast;
        ins >> v->desert;
        ins >> v->forest;
        ins >> v->grassland;
        ins >> v->mountain;
        ins >> v->swamp;
        ins >> v->underdark;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "creaturetype"   //creaturetype
        ins >> v->twohumanoids;
        ins >> v->aberrations;
        ins >> v->beasts;
        ins >> v->celestials;
        ins >> v->constructs;
        ins >> v->dragons;
        ins >> v->elementals;
        ins >> v->fey;
        ins >> v->fiends;
        ins >> v->giants;
        ins >> v->monstrosities;
        ins >> v->oozes;
        ins >> v->plants;
        ins >> v->undead;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "spellslots" //spellslots
        ins >> v->first_ss;
        ins >> v->second_ss;
        ins >> v->third_ss;
        ins >> v->forth_ss;
        ins >> v->fifth_ss;
        ins >> v->sixth_ss;
        ins >> v->seventh_ss;
        ins >> v->eighth_ss;
        ins >> v->ninth_ss;
        ins >> v->warlock_ss;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "skills"   //skills
        ins >> v->initialSkillsSet;
        ins >> v->acrobatics;
        ins >> v->animal_handling;
        ins >> v->arcana;
        ins >> v->athletics;
        ins >> v->deception;
        ins >> v->history;
        ins >> v->insight;
        ins >> v->intimidation;
        ins >> v->investigation;
        ins >> v->medicine;
        ins >> v->nature;
        ins >> v->perception;
        ins >> v->performance;
        ins >> v->persuasion;
        ins >> v->religion;
        ins >> v->sleight_of_hand;
        ins >> v->stealth;
        ins >> v->survival;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "feats"   //feats
        ins >> v->alert;
        ins >> v->athlete;
        ins >> v->actor;
        ins >> v->charger;
        ins >> v->crossbow_expert;
        ins >> v->defensive_duelist;
        ins >> v->dual_wielder;
        ins >> v->dungeon_delver;
        ins >> v->durable;
        ins >> v->elemental_adept;
        ins >> v->grappler;
        ins >> v->great_weapon_master;
        ins >> v->healer;
        ins >> v->heavily_armored;
        ins >> v->heavy_armor_master;
        ins >> v->inspiring_leader;
        ins >> v->keen_mind;
        ins >> v->lightly_armored;
        ins >> v->linguist;
        ins >> v->lucky;
        ins >> v->mage_slayer;
        ins >> v->magic_initiate;
        ins >> v->martial_adept;
        ins >> v->medium_armor_master;
        ins >> v->mobile;
        ins >> v->moderately_armored;
        ins >> v->mounted_combatant;
        ins >> v->observant;
        ins >> v->polearm_master;
        ins >> v->resilient;
        ins >> v->ritual_caster;
        ins >> v->savage_attacker;
        ins >> v->sentinel;
        ins >> v->sharpshooter;
        ins >> v->shield_master;
        ins >> v->skilled;
        ins >> v->skulker;
        ins >> v->spell_sniper;
        ins >> v->tavern_brawler;
        ins >> v->tough;
        ins >> v->war_caster;
        ins >> v->weapon_master;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "languages"   //languages
        ins >> v->abyssal;
        ins >> v->celestial;
        ins >> v->common;
        ins >> v->deep_speech;
        ins >> v->draconic;
        ins >> v->dwarvish;
        ins >> v->elvish;
        ins >> v->giant;
        ins >> v->gnomish;
        ins >> v->goblin;
        ins >> v->gnoll;
        ins >> v->halfling;
        ins >> v->infernal;
        ins >> v->orc;
        ins >> v->primordial;
        ins >> v->sylvan;
        ins >> v->undercommon;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "features"   //features
        ins >> v->artificers_lore;
        ins >> v->brave;
        ins >> v->breath_weapon_acid;
        ins >> v->breath_weapon_ltg;
        ins >> v->breath_weapon_fire;
        ins >> v->breath_weapon_poison;
        ins >> v->breath_weapon_cold;
        ins >> v->darkvision;
        ins >> v->draconic_ancestry_black;
        ins >> v->draconic_ancestry_blue;
        ins >> v->draconic_ancestry_brass;
        ins >> v->draconic_ancestry_bronze;
        ins >> v->draconic_ancestry_copper;
        ins >> v->draconic_ancestry_gold;
        ins >> v->draconic_ancestry_green;
        ins >> v->draconic_ancestry_red;
        ins >> v->draconic_ancestry_silver;
        ins >> v->draconic_ancestry_white;
        ins >> v->drow_magic;
        ins >> v->drow_weapon_training;
        ins >> v->dwarven_armor_training;
        ins >> v->dwarven_combat_training;
        ins >> v->dwarven_resilience;
        ins >> v->dwarven_toughness;
        ins >> v->elf_weapon_training;
        ins >> v->fey_ancestry;
        ins >> v->fleet_of_foot;
        ins >> v->halflinglucky;
        ins >> v->halfling_nimbleness;
        ins >> v->hellish_resistance;
        ins >> v->infernal_legacy;
        ins >> v->mask_of_the_wild;
        ins >> v->natural_illusionist;
        ins >> v->naturally_stealthy;
        ins >> v->speak_with_small_beasts;
        ins >> v->stonecunning;
        ins >> v->stout_resilience;
        ins >> v->superior_darkvision;
        ins >> v->trance;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "resistances"   //resistances
        ins >> v->damage_resist_acid;
        ins >> v->damage_resist_ltg;
        ins >> v->damage_resist_fire;
        ins >> v->damage_resist_poison;
        ins >> v->damage_resist_cold;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "disadvantages"   //disadvantages
        ins >> v->sunlight_sensitivity;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "tools"   //artisan tools & supplies
        ins >> v->alchemist;
        ins >> v->brewer;
        ins >> v->calligrapher;
        ins >> v->carpenter;
        ins >> v->cartographer;
        ins >> v->cobbler;
        ins >> v->cook;
        ins >> v->glassblower;
        ins >> v->jeweler;
        ins >> v->leatherworker;
        ins >> v->mason;
        ins >> v->painter;
        ins >> v->potter;
        ins >> v->smith;
        ins >> v->tinker;
        ins >> v->weaver;
        ins >> v->woodcarver;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "kits"   //kits & tools
        ins >> v->disguise;
        ins >> v->forgery;
        ins >> v->herbalism;
        ins >> v->navigator;
        ins >> v->poisoner;
        ins >> v->thieves;
        ins >> v->vehicle;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//           >> "musicalinstruments"   //musical instruments
        ins >> v->bagpipes;
        ins >> v->drum;
        ins >> v->dulcimer;
        ins >> v->flute;
        ins >> v->lute;
        ins >> v->lyre;
        ins >> v->horn;
        ins >> v->pan_flute;
        ins >> v->shawm;
        ins >> v->viol;
        character_list.push_back(v);
        ins.get();
        if (ins.peek() == '\n') ins.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.clear();
    return ins;
}


void Campaign::treasure_menu() {
    int choice = 0;
    Gear item;
    while (choice != 5) {
        simpleClearScreen();
        cout << "--->Make a Selection<---\n\n"
             << " 1. Generate Individual Treasure\n"
             << " 2. Generate Treasure Hoard\n"
             // << " 3. See All Gear\n"
             // << " 4. Clear All Gear\n"
             << " 5. Back to Main Menu\n\n";
        choice = getNumber("Choice(1-5): ", 1, 5);
        switch (choice) {
        case 1: 
            cout << "Individual Treasure\n\n"
                 << " 1. Challenge 0-4 \n"
                 << " 2. Challenge 5-10 \n"
                 << " 3. Challenge 11-16 \n"
                 << " 4. Challenge 17+ \n\n";
            choice = getNumber("Choice(1-4): ", 1, 4);
            switch (choice) {
            case 1: GenerateIndividualTreasureCR_0_4(); break;
            case 2: GenerateIndividualTreasureCR_5_10(); break;
            case 3: GenerateIndividualTreasureCR_11_16(); break;
            case 4: GenerateIndividualTreasureCR_17();
            default: break;
            }
            pressEnterToContinue();
            break;
        case 2:
            cout << "Treasure Hoard\n\n"
                 << " 1. Challenge 0-4 \n"
                 << " 2. Challenge 5-10 \n"
                 << " 3. Challenge 11-16 \n"
                 << " 4. Challenge 17+ \n\n";
            choice = getNumber("Choice(1-4): ", 1, 4);
            switch (choice) {
            case 1: GenerateHoardTreasureCR_0_4(); break;
            case 2: GenerateHoardTreasureCR_5_10(); break;
            case 3: GenerateHoardTreasureCR_11_16(); break;
            case 4: GenerateHoardTreasureCR_17();
            default: break;
            }
            pressEnterToContinue();
            break;
        case 3:
            cout << "\nNOT DONE:build gear output loop here\n";
            pressEnterToContinue();
            break;
        case 4:
            cout << "\nNOT DONE:build gear vector deleter here\n";
            pressEnterToContinue();
        default: break;
        }
    }
}
void Campaign::GenerateIndividualTreasureCR_0_4(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Gold Roll = " << gr << endl;
    if (gr <= 30) { 
        int copper = 0;
        for (int i(0); i < 5; i++) copper += rolld6(mgen);
        Gear tmp(copper, "cp");
        tmplist.push_back(tmp);
    } else if (gr <= 60) { 
        int silver = 0;
        for (int i(0); i < 4; i++) silver += rolld6(mgen);
        Gear tmp(silver, "sp");
        tmplist.push_back(tmp);
    } else if (gr <= 70) {
        int elec = 0;
        for (int i(0); i < 3; i++) elec += rolld6(mgen);
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
    } else if (gr <= 95) {
        int gold = 0;
        for (int i(0); i < 3; i++) gold += rolld6(mgen);
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
    } else {
        int plat = 0;
        plat += rolld6(mgen);
        Gear tmp(plat, "pp");
        tmplist.push_back(tmp);
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Campaign::GenerateIndividualTreasureCR_5_10(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Gold Roll: " << gr << endl;
    if (gr <= 30) { 
        int copper = 0;
        for (int i(0); i < 4; i++) copper += rolld6(mgen);
        copper *= 100;
        Gear tmp(copper, "cp");
        tmplist.push_back(tmp);
        int elec = (rolld6(mgen) * 10);
        Gear tmp1(elec, "ep");
        tmplist.push_back(tmp1);
    } else if (gr <= 60) {
        int silver = 0;
        for (int i(0); i < 6; i++) silver += rolld6(mgen);
        silver *= 10;
        Gear tmp(silver, "sp");
        tmplist.push_back(tmp);
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 70) {
        int elec = 0;
        for (int i(0); i < 3; i++) elec += rolld6(mgen);
        elec *= 10;
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 95) {
        int gold = 0;
        for (int i(0); i < 4; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
    } else {
        int gold = 0; 
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 10;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = 0;
        for (int i(0); i < 3; i++) plat += rolld6(mgen);
        plat *= 10;
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Campaign::GenerateIndividualTreasureCR_11_16(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);    cout << "Gold Roll: " << gr << endl;
    if (gr <= 20) { 
        int silver = 0;
        for (int i(0); i < 4; i++) silver += rolld6(mgen);
        silver *= 100;
        Gear tmp(silver, "sp");
        tmplist.push_back(tmp);
        int gold = (rolld6(mgen) * 100);
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 35) {
        int elec = (rolld6(mgen) * 100);
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
        int gold = (rolld6(mgen) * 100);
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 75) {
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 100;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = (rolld6(mgen) * 10);
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    } else {
        int gold = 0;
        for (int i(0); i < 2; i++) gold += rolld6(mgen);
        gold *= 100;
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = 0;
        for (int i(0); i < 2; i++) plat += rolld6(mgen);
        plat *= 10;
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    } 
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Campaign::GenerateIndividualTreasureCR_17(){
    vector<Gear> tmplist;
    int gr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') gr = rolld100(mgen);
    else gr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Gold Roll: " << gr << endl;
    if (gr <= 15) { 
        int elec = 0;
        for (int i(0); i < 2; i++) elec += rolld6(mgen);
        elec *= 100;
        Gear tmp(elec, "ep");
        tmplist.push_back(tmp);
        int gold = 0;
        for (int i(0); i < 8; i++) gold += rolld6(mgen);
        gold *= 100;
        Gear tmp1(gold, "gp");
        tmplist.push_back(tmp1);
    } else if (gr <= 55) {
        int gold = (rolld6(mgen) * 1000);
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = (rolld6(mgen) * 100);
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    } else {
        int gold = (rolld6(mgen) * 1000);
        Gear tmp(gold, "gp");
        tmplist.push_back(tmp);
        int plat = 0;
        for (int i(0); i < 2; i++) plat += rolld6(mgen);
        plat *= 100;
        Gear tmp1(plat, "pp");
        tmplist.push_back(tmp1);
    } 
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}

void Campaign::GenerateHoardTreasureCR_0_4(){
    vector<Gear> tmplist;
    int copper(0), silver(0), gold(0);
    for (int i(0); i < 6; i++) copper += rolld6(mgen);
    for (int i(0); i < 3; i++) silver += rolld6(mgen);
    for (int i(0); i < 2; i++) gold += rolld6(mgen);
    copper *= 100;
    silver *= 100;
    gold *= 10;
    Gear tmp(copper, "cp");
    Gear tmp1(silver, "sp");
    Gear tmp2(gold, "gp");
    tmplist.push_back(tmp);
    tmplist.push_back(tmp1);
    tmplist.push_back(tmp2);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);
    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 6) {
        cout << "shittiest roll ever.\n";
    } else if (mr <= 16) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "10gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 26) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
    } else if (mr <= 36) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 44) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "10gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 52) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 60) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 65) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "10gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 70) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25p art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 75) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 78) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "10gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 80) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 85) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 92) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableF());
    } else if (mr <= 97) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableF());
    } else if (mr <= 99) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableG());
    } else {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableG());
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
void Campaign::GenerateHoardTreasureCR_5_10(){
    vector<Gear> tmplist;
    int copper(0), silver(0), gold(0), plat(0);
    for (int i(0); i < 2; i++) copper += rolld6(mgen);
    for (int i(0); i < 2; i++) silver += rolld6(mgen);
    for (int i(0); i < 6; i++) gold += rolld6(mgen);
    for (int i(0); i < 3; i++) plat += rolld6(mgen);
    copper *= 100;
    silver *= 1000;
    gold *= 100;
    plat *= 10;
    Gear tmp(copper, "cp");
    Gear tmp1(silver, "sp");
    Gear tmp2(gold, "gp");
    Gear tmp3(plat, "pp");
    tmplist.push_back(tmp);
    tmplist.push_back(tmp1);
    tmplist.push_back(tmp2);
    tmplist.push_back(tmp3);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 4) {
        cout << "crappiest roll ever :|\n";
    } else if (mr <= 10) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
    } else if (mr <= 16) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 22) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 28) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
    } else if (mr <= 32) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 36) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 40) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 44) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
    } else if (mr <= 49) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 54) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 59) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 63) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 66) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 69) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 72) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 74) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 76) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableD());
    } else if (mr <= 78) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableD());
    } else if (mr <= 79) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableD());
    } else if (mr <= 80) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableD());;
    } else if (mr <= 84) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "25gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableF());
    } else if (mr <= 88) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "50gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableF());
    } else if (mr <= 91) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableF());
    } else if (mr <= 94) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableF());
    } else if (mr <= 96) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 98) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 99) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "100gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableH());
    } else {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableH());
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }

}
void Campaign::GenerateHoardTreasureCR_11_16(){
    vector<Gear> tmplist;
    int gold(0), plat(0);
    for (int i(0); i < 4; i++) gold += rolld6(mgen);
    for (int i(0); i < 5; i++) plat += rolld6(mgen);
    gold *= 1000;
    plat *= 100;
    Gear tmp2(gold, "gp");
    Gear tmp3(plat, "pp");
    tmplist.push_back(tmp2);
    tmplist.push_back(tmp3);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 3) {
        cout << "crappiest roll ever :|\n";
    } else if (mr <= 6) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
    } else if (mr <= 9) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 12) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 15) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
    } else if (mr <= 19) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 23) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 26) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 29) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableA());
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableB());
    } else if (mr <= 35) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 40) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 45) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 50) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 54) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 58) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 62) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 66) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 68) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableE());
    } else if (mr <= 70) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableE());
    } else if (mr <= 72) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableE());
    } else if (mr <= 74) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableE());;
    } else if (mr <= 76) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableF());
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 78) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableF());
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 80) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableF());
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 82) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableF());
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 85) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 88) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 90) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 92) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 94) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "250gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableI());
    } else if (mr <= 96) {
        int c = 0;
        for (int i(0); i < 2; i++) c += rolld4(mgen);
        Gear tmp(c, "750gp art objects");
        tmplist.push_back(tmp);
        tmplist.push_back(tableI());
    } else if (mr <= 98) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "500gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableI());
    } else {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        tmplist.push_back(tableI());
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }

}
void Campaign::GenerateHoardTreasureCR_17(){
    vector<Gear> tmplist;
    int gold(0), plat(0);
    for (int i(0); i < 12; i++) gold += rolld6(mgen);
    for (int i(0); i < 8; i++) plat += rolld6(mgen);
    gold *= 1000;
    plat *= 1000;
    Gear tmp2(gold, "gp");
    Gear tmp3(plat, "pp");
    tmplist.push_back(tmp2);
    tmplist.push_back(tmp3);
    int mr = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') mr = rolld100(mgen);
    else mr = getNumber("Roll d100 result: ", 1, 100);    
    cout << "Magic Item Roll = " << mr << endl;
    if (mr <= 2) {
        cout << "crappiest roll ever :|\n";
    } else if (mr <= 5) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 8) {
        int c = rolld10(mgen);
        Gear tmp(c, "2500gp art objects");
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 11) {
        int c = rolld4(mgen);
        Gear tmp(c, "7500gp art objects");
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 14) {
        int c = rolld8(mgen);
        Gear tmp(c, "5000gp gems");
        tmplist.push_back(tmp);
        c = rolld8(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableC());
    } else if (mr <= 22) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 30) {
        int c = rolld10(mgen);
        Gear tmp(c, "2500gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 38) {
        int c = rolld4(mgen);
        Gear tmp(c, "7500gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 46) {
        int c = rolld8(mgen);
        Gear tmp(c, "5000gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableD());
    } else if (mr <= 52) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableE());
    } else if (mr <= 58) {
        int c = rolld10(mgen);
        Gear tmp(c, "2500gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableE());
    } else if (mr <= 63) {
        int c = rolld4(mgen);
        Gear tmp(c, "7500gp art objects");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableE());
    } else if (mr <= 68) {
        int c = rolld8(mgen);
        Gear tmp(c, "5000gp gems");
        tmplist.push_back(tmp);
        c = rolld6(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableE());
    } else if (mr <= 69) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 70) {
        int c = rolld10(mgen);
        Gear tmp(c, "2500gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 71) {
        int c = rolld4(mgen);
        Gear tmp(c, "7500gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 72) {
        int c = rolld8(mgen);
        Gear tmp(c, "5000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableG());
    } else if (mr <= 74) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 76) {
        int c = rolld10(mgen);
        Gear tmp(c, "2500gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 78) {
        int c = rolld4(mgen);
        Gear tmp(c, "7500gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 80) {
        int c = rolld8(mgen);
        Gear tmp(c, "5000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableH());
    } else if (mr <= 85) {
        int c = 0;
        for (int i(0); i < 3; i++) c += rolld6(mgen);
        Gear tmp(c, "1000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableI());
    } else if (mr <= 90) {
        int c = rolld10(mgen);
        Gear tmp(c, "2500gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableI());
    } else if (mr <= 95) {
        int c = rolld4(mgen);
        Gear tmp(c, "7500gp art objects");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableI());
    } else {
        int c = rolld8(mgen);
        Gear tmp(c, "5000gp gems");
        tmplist.push_back(tmp);
        c = rolld4(mgen);
        for (int i(0); i < c; i++) tmplist.push_back(tableI());
    }
    cout << endl;
    for (auto& it : tmplist) { it.showItem(); }
}
Gear Campaign::tableA(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table A Roll = " << roll << endl;
    if (roll <= 50) {
        Gear tmp(1, "Potion of Healing");
        return tmp;
    } else if (roll <= 60) {
        Gear tmp(1, "Spell Scroll(cantrip)");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Potion of Climbing");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Spell Scroll(1st level)");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Spell Scroll(2nd level)");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Bag of holding");
        return tmp;
    } else {
        Gear tmp(1, "Driftglobe");
        return tmp;
    }
}
Gear Campaign::tableB() {
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table B Roll = " << roll << endl;
    if (roll <= 15) {
        Gear tmp(1, "Potion of greater healing");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Potion of fire breath");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Potion of resistance");
        return tmp;
    } else if (roll <= 34) {
        Gear tmp(1, "Ammunition, +1");
        return tmp;
    } else if (roll <= 39) {
        Gear tmp(1, "Potion of animal friendship");
        return tmp;
    } else if (roll <= 44) {
        Gear tmp(1, "Potion of hill giant strength");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Potion of growth");
        return tmp;
    } else if (roll <= 54) {
        Gear tmp(1, "Potion of water breathing");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Spell Scroll(2nd level)");
        return tmp;
    } else if (roll <= 64) {
        Gear tmp(1, "Spell Scroll(3rd level)");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Bag of holding");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Keoghtom's ointment");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Oil of slipperiness");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Dust of disappearance");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Dust of dryness");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Dust of sneezing and choking");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Elemental gem");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Philter of love");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Alchemy jug");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Cap of water breathing");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Cloak of the manta ray");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Driftglobe");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Goggles of night");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Helm of comprehending languages");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Immovable rod");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "lantern of revealing");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Mariner's armor");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Mithral armor");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Potion of poison");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Ring of swimming");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Robe of useful items");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Ring of climbing");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Saddle of the cavalier");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Wand of magic detection");
        return tmp;
    } else {
        Gear tmp(1, "Wand of secrets");
        return tmp;
    }
}
Gear Campaign::tableC(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table C Roll = " << roll << endl;
    if (roll <= 15) {
        Gear tmp(1, "Potion of superior healing");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Spell scroll(4th level)");
        return tmp;
    } else if (roll <= 27) {
        Gear tmp(1, "Ammunition, +2");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Potion of clairvoyance");
        return tmp;
    } else if (roll <= 37) {
        Gear tmp(1, "Potion of diminution");
        return tmp;
    } else if (roll <= 42) {
        Gear tmp(1, "Potion of gaseous form");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Potion of frost giant strength");
        return tmp;
    } else if (roll <= 52) {
        Gear tmp(1, "Potion of stone giant strength");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Potion of Heroism");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Potion of invulnerability");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Potion of mind reading");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Spell scroll(5th level)");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Elixir of health");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Oil of etherealness");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Potion of fire giant strength");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Quaal's feather token");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Scroll of protection");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Bag of beans");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Bead of force");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Chime of opening");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Decanter of endless water");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Eyes of minute seeing");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Folding boat");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Heward's handy haversack");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Horseshoes of speed");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Neckalace of fireballs");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Periapt of health");
        return tmp;
    } else {
        Gear tmp(1, "Sending stones");
        return tmp;
    }
}
Gear Campaign::tableD(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table D Roll = " << roll << endl;
    if (roll <= 20) {
        Gear tmp(1, "Potion of supreme healing");
        return tmp;
    } else if (roll <= 30) {
        Gear tmp(1, "Potion of invisibility");
        return tmp;
    } else if (roll <= 40) {
        Gear tmp(1, "Potion of speed");
        return tmp;
    } else if (roll <= 50) {
        Gear tmp(1, "Spell scroll(6th level)");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Spell scroll(7th level)");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Ammunition, +3");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Oil of sharpness");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Potion of flying");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Potion of cloud giant strength");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Potion of longevity");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Potion of vitality");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Spell scroll(8th level)");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Horseshoes of a zephyr");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Nolzur's marvelous pigments");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Bag of devouring");
        return tmp;
    } else {
        Gear tmp(1, "Portable hole");
        return tmp;
    }
}
Gear Campaign::tableE(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table E Roll = " << roll << endl;
    if (roll <= 30) {
        Gear tmp(1, "Spell scroll(8th level)");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Potion of storm giant strength");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Potion of supreme healing");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Spell scroll(9th level)");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Universal solvent");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Arrow of slaying");
        return tmp;
    } else {
        Gear tmp(1, "Sovereign glue");
        return tmp;
    }
}
Gear Campaign::tableF(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table F Roll = " << roll << endl;
    if (roll <= 15) {
        Gear tmp(1, "Weapon, +1");
        return tmp;
    } else if (roll <= 18) {
        Gear tmp(1, "Shield, +1");
        return tmp;
    } else if (roll <= 21) {
        Gear tmp(1, "Sentinel Shield");
        return tmp;
    } else if (roll <= 23) {
        Gear tmp(1, "Amulet of proof against detection and location");
        return tmp;
    } else if (roll <= 25) {
        Gear tmp(1, "Boots of elvenkind");
        return tmp;
    } else if (roll <= 27) {
        Gear tmp(1, "Boots of striding of springing");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Bracers of archery");
        return tmp;
    } else if (roll <= 31) {
        Gear tmp(1, "Brooch of shielding");
        return tmp;
    } else if (roll <= 33) {
        Gear tmp(1, "Broom of flying");
        return tmp;
    } else if (roll <= 35) {
        Gear tmp(1, "Cloak of elvenkind");
        return tmp;
    } else if (roll <= 37) {
        Gear tmp(1, "Cloak of protection");
        return tmp;
    } else if (roll <= 39) {
        Gear tmp(1, "Gauntlets of ogre power");
        return tmp;
    } else if (roll <= 41) {
        Gear tmp(1, "Hat of disguise");
        return tmp;
    } else if (roll <= 43) {
        Gear tmp(1, "Javelin of lightning");
        return tmp;
    } else if (roll <= 45) {
        Gear tmp(1, "Pearl of power");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Rod of the pact keeper, +1");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Slippers of spider climbing");
        return tmp;
    } else if (roll <= 51) {
        Gear tmp(1, "Staff of the adder");
        return tmp;
    } else if (roll <= 53) {
        Gear tmp(1, "Staff of the python");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Sword of vengeance");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Trident of fish command");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Wand of magic missles");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Wand of the war mage, +1");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Wand of web");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Weapon of warning");
        return tmp;
    } else if (roll <= 66) {
        Gear tmp(1, "Adamantine armor(chain mail)");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Adamantine armor(chain shirt)");
        return tmp;
    } else if (roll <= 68) {
        Gear tmp(1, "Adamantine armor(scale mail");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Bag of tricks(grey)");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Bag of tricks(rust)");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Bag of tricks(tan)");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Boots of the winterlands");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Circlet of blasting");
        return tmp;
    } else if (roll <= 74) {
        Gear tmp(1, "Deck of illusions");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Eversmoking bottle");
        return tmp;
    } else if (roll <= 76) {
        Gear tmp(1, "Eyes of charming");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Eyes of the eagle");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Figurine of wondrous power(silver raven)");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Gem of brightness");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Gem of missile snaring");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Gloves of swimming and climbing");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Gloves of thievery");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Headband of intellect");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Helm of telepathy");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Instrument of the bards(Doss lute)");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Instrument of the bards(Fochlucan bandore)");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Instrument of the bards(Mac-Fuimidh cittern)");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Medallion of thoughts");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Necklace of adaptation");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Periapt of wound closure");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Pipes of haunting");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Pipes of the sewers");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Ring of jumping");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Ring of mind shielding");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Ring of warmth");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Ring of water walking");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Quiver of Ehlonna");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Stone of good luck");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Wind fan");
        return tmp;
    } else {
        Gear tmp(1, "Winged boots");
        return tmp;
    }
}
Gear Campaign::tableG(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table G Roll = " << roll << endl;
    if (roll <= 11) {
        Gear tmp(1, "Weapon, +2");
        return tmp;
    } else if (roll <= 14) {
        string loader = "Figurine of wonderous power";
        int d8 = rolld8(mgen);
        if (d8 == 1) {
            loader += "(Bronze griffon)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 2) {
            loader += "(Ebony fly)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 3) {
            loader += "(Golden lions)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 4) {
            loader += "(Ivory goats)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 == 5) {
            loader += "(Marble elephant)";
            Gear tmp(1, loader);
            return tmp;
        } else if (d8 <= 7) {
            loader += "(Onyx dog)";
            Gear tmp(1, loader);
            return tmp;
        } else {
            loader += "(Serpentine owl)";
            Gear tmp(1, loader);
            return tmp;
        }
    } else if (roll <= 15) {
        Gear tmp(1, "Adamantine armor(breastplate)");
        return tmp;
    } else if (roll <= 16) {
        Gear tmp(1, "Adamantine armor(splint)");
        return tmp;
    } else if (roll <= 17) {
        Gear tmp(1, "Amulet of health");
        return tmp;
    } else if (roll <= 18) {
        Gear tmp(1, "Armor of vulnerability");
        return tmp;
    } else if (roll <= 19) {
        Gear tmp(1, "Arrow-catching shield");
        return tmp;
    } else if (roll <= 20) {
        Gear tmp(1, "Belt of dwarvenkind");
        return tmp;
    } else if (roll <= 21) {
        Gear tmp(1, "Belt of hill giant strength");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Berserker axe");
        return tmp;
    } else if (roll <= 23) {
        Gear tmp(1, "Boots of levitation");
        return tmp;
    } else if (roll <= 24) {
        Gear tmp(1, "Boots of speed");
        return tmp;
    } else if (roll <= 25) {
        Gear tmp(1, "Bowl of commanding water elementals");
        return tmp;
    } else if (roll <= 26) {
        Gear tmp(1, "Bracers of defense");
        return tmp;
    } else if (roll <= 27) {
        Gear tmp(1, "Brazier of commanding fire elementals");
        return tmp;
    } else if (roll <= 28) {
        Gear tmp(1, "Cape of the mountebank");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Censer of controlling air elementals");
        return tmp;
    } else if (roll <= 30) {
        Gear tmp(1, "Armor, +1 chain mail");
        return tmp;
    } else if (roll <= 31) {
        Gear tmp(1, "Armor of resistance(chain mail)");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Armor, +1 chain shirt");
        return tmp;
    } else if (roll <= 33) {
        Gear tmp(1, "Armor of resistance(chain shirt)");
        return tmp;
    } else if (roll <= 34) {
        Gear tmp(1, "Cloak of displacement");
        return tmp;
    } else if (roll <= 35) {
        Gear tmp(1, "Cloak of the bat");
        return tmp;
    } else if (roll <= 36) {
        Gear tmp(1, "Cube of force");
        return tmp;
    } else if (roll <= 37) {
        Gear tmp(1, "Daern's instant fortress");
        return tmp;
    } else if (roll <= 38) {
        Gear tmp(1, "Dagger of venom");
        return tmp;
    } else if (roll <= 39) {
        Gear tmp(1, "Dimensional shackles");
        return tmp;
    } else if (roll <= 40) {
        Gear tmp(1, "Dragon slayer");
        return tmp;
    } else if (roll <= 41) {
        Gear tmp(1, "Elven chain");
        return tmp;
    } else if (roll <= 42) {
        Gear tmp(1, "Flame tongue");
        return tmp;
    } else if (roll <= 43) {
        Gear tmp(1, "Gem of seeing");
        return tmp;
    } else if (roll <= 44) {
        Gear tmp(1, "Giant slayer");
        return tmp;
    } else if (roll <= 45) {
        Gear tmp(1, "Glammoured studded leather");
        return tmp;
    } else if (roll <= 46) {
        Gear tmp(1, "Helm of teleportation");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Horn of blasting");
        return tmp;
    } else if (roll <= 48) {
        Gear tmp(1, "Horn of Valhalla(silver or brass)");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Instrument of the bards(Canaith Mandolin");
        return tmp;
    } else if (roll <= 50) {
        Gear tmp(1, "Instrument of the bards(Cli lyre)");
        return tmp;
    } else if (roll <= 51) {
        Gear tmp(1, "Ioun stone(awareness)");
        return tmp;
    } else if (roll <= 52) {
        Gear tmp(1, "Ioun stone(protection)");
        return tmp;
    } else if (roll <= 53) {
        Gear tmp(1, "Ioun stone(reverse)");
        return tmp;
    } else if (roll <= 54) {
        Gear tmp(1, "Ioun stone(sustenance)");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Iron bands of Bilarro");
        return tmp;
    } else if (roll <= 56) {
        Gear tmp(1, "Armor, +1 leather");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Armor of resistance(leather)");
        return tmp;
    } else if (roll <= 58) {
        Gear tmp(1, "Mace of disruption");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Mace of smiting");
        return tmp;
    } else if (roll <= 60) {
        Gear tmp(1, "Mace of terror");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Mantle of spell resistance");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Necklace of prayer beads");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Periapt of proof against poison");
        return tmp;
    } else if (roll <= 64) {
        Gear tmp(1, "Ring of animal influence");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Ring of evasion");
        return tmp;
    } else if (roll <= 66) {
        Gear tmp(1, "Ring of feather falling");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Ring of free action");
        return tmp;
    } else if (roll <= 68) {
        Gear tmp(1, "Ring of protection");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Ring of resistance");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Ring of spell storing");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Ring of the ram");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Ring of X-ray vision");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Rob of eyes");
        return tmp;
    } else if (roll <= 74) {
        Gear tmp(1, "Rod of rulership");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Rod of the pact keeper, +2");
        return tmp;
    } else if (roll <= 76) {
        Gear tmp(1, "Rope of entanglement");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Armor, +1 scale mail");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Armor of resistance(scale mail)");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Shield, +2");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Shield of missle attraction");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Staff of charming");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Staff of healing");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Staff of swarming insects");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Staff of the woodlands");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Staff of the withering");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Stone of controlling earth elementals");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Sun blade");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Sword of life stealing");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Sword of wounding");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Tentacle rod");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Vicious weapon");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Wand of binding");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Wand of enemy detection");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Wand of fear");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Wand of fireballs");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Wand of lightning bolts");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Wand of paralysis");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Wand of the war mage, +2");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Wand of wonder");
        return tmp;
    } else {
        Gear tmp(1, "Wings of flying");
        return tmp;
    }
}
Gear Campaign::tableH(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table H Roll = " << roll << endl;
    if (roll <= 10) {
        Gear tmp(1, "Weapon, +3");
        return tmp;
    } else if (roll <= 12) {
        Gear tmp(1, "Amulet of the planes");
        return tmp;
    } else if (roll <= 14) {
        Gear tmp(1, "Carpet of flying");
        return tmp;
    } else if (roll <= 16) {
        Gear tmp(1, "Crystal ball(very rare version)");
        return tmp;
    } else if (roll <= 18) {
        Gear tmp(1, "Ring of regeneration");
        return tmp;
    } else if (roll <= 20) {
        Gear tmp(1, "Ring of shooting stars");
        return tmp;
    } else if (roll <= 22) {
        Gear tmp(1, "Ring of telekinesis");
        return tmp;
    } else if (roll <= 24) {
        Gear tmp(1, "Robe of scintillating colors");
        return tmp;
    } else if (roll <= 26) {
        Gear tmp(1, "Robe of stars");
        return tmp;
    } else if (roll <= 28) {
        Gear tmp(1, "Rod of absorption");
        return tmp;
    } else if (roll <= 30) {
        Gear tmp(1, "Rod of alertness");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Rod of security");
        return tmp;
    } else if (roll <= 34) {
        Gear tmp(1, "Rod of the pact keeper, +3");
        return tmp;
    } else if (roll <= 36) {
        Gear tmp(1, "Scimitar of speed");
        return tmp;
    } else if (roll <= 38) {
        Gear tmp(1, "Shield, +3");
        return tmp;
    } else if (roll <= 40) {
        Gear tmp(1, "Staff of fire");
        return tmp;
    } else if (roll <= 42) {
        Gear tmp(1, "Staff of frost");
        return tmp;
    } else if (roll <= 44) {
        Gear tmp(1, "Staff of power");
        return tmp;
    } else if (roll <= 46) {
        Gear tmp(1, "Staff of striking");
        return tmp;
    } else if (roll <= 48) {
        Gear tmp(1, "Staff of thunder and lightning");
        return tmp;
    } else if (roll <= 50) {
        Gear tmp(1, "Sword of sharpness");
        return tmp;
    } else if (roll <= 52) {
        Gear tmp(1, "Wand of polymorph");
        return tmp;
    } else if (roll <= 54) {
        Gear tmp(1, "Wand of the war mage, +3");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Adamantine armor(half plate)");
        return tmp;
    } else if (roll <= 56) {
        Gear tmp(1, "Adamantine armor(plate)");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Animated shield");
        return tmp;
    } else if (roll <= 58) {
        Gear tmp(1, "Belt of fire giant strength");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Belt of stone giant strength");
        return tmp;
    } else if (roll <= 60) {
        Gear tmp(1, "Armor, +1 breastplate");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Armor of resistance(breastplate)");
        return tmp;
    } else if (roll <= 62) {
        Gear tmp(1, "Candle of invocation");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Armor, +2 chain mail");
        return tmp;
    } else if (roll <= 64) {
        Gear tmp(1, "Armor, +2 chain shirt");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Cloak of arachnida");
        return tmp;
    } else if (roll <= 66) {
        Gear tmp(1, "Dancing sword");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Demon armor");
        return tmp;
    } else if (roll <= 68) {
        Gear tmp(1, "Dragon scale mail");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Dwarven plate");
        return tmp;
    } else if (roll <= 70) {
        Gear tmp(1, "Dwarven thrower");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Efreeti bottle");
        return tmp;
    } else if (roll <= 72) {
        Gear tmp(1, "Figurine of wondrous power(obsidian steed)");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Frost brand");
        return tmp;
    } else if (roll <= 74) {
        Gear tmp(1, "Helm of brilliance");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Horn of Valhalla(bronze)");
        return tmp;
    } else if (roll <= 76) {
        Gear tmp(1, "Instrument of the bards(Anstruth harp)");
        return tmp;
    } else if (roll <= 77) {
        Gear tmp(1, "Ioun stone(absorption)");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Ioun stone(agility)");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Ioun stone(fortitude)");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Ioun stone(insight)");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Ioun stone(intellect)");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Ioun stone(leadership)");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Ioun stone(strength)");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Armor, +2 leather");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Manual of bodily health");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Manual of gainful exercise");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Manual of golems");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Manual of quickness of action");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Mirror of life trapping");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Nine lives stealer");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Oathbow");
        return tmp;
    } else if (roll <= 92) {
        Gear tmp(1, "Armor, +2 scale mail");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Spellguard shield");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Armor, +1 splint");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Armor of resistance(splint)");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Armor, +1 studded leather");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Armor of resistance(studded leather)");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Tome of clear thought");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Tome of leadership and influecne");
        return tmp;
    } else {
        Gear tmp(1, "Tome of understanding");
        return tmp;
    }
}
Gear Campaign::tableI(){
    int roll = 0;
    char ans = getYorN("Have system roll for you?(y/n): ");
    if (ans == 'Y') roll = rolld100(mgen);
    else roll = getNumber("Roll d100 result: ", 1, 100);
    cout << "Table I Roll = " << roll << endl;
    if (roll <= 5) {
        Gear tmp(1, "Defender");
        return tmp;
    } else if (roll <= 10) {
        Gear tmp(1, "Hammer of thunderbolts");
        return tmp;
    } else if (roll <= 15) {
        Gear tmp(1, "Luck blade");
        return tmp;
    } else if (roll <= 20) {
        Gear tmp(1, "Sword of answering");
        return tmp;
    } else if (roll <= 23) {
        Gear tmp(1, "Holy Avenger");
        return tmp;
    } else if (roll <= 26) {
        Gear tmp(1, "Ring of djinni summoning");
        return tmp;
    } else if (roll <= 29) {
        Gear tmp(1, "Ring of invisibility");
        return tmp;
    } else if (roll <= 32) {
        Gear tmp(1, "Ring of spell turning");
        return tmp;
    } else if (roll <= 35) {
        Gear tmp(1, "Rod of lordly might");
        return tmp;
    } else if (roll <= 38) {
        Gear tmp(1, "Staff of the magi");
        return tmp;
    } else if (roll <= 41) {
        Gear tmp(1, "Vorpal sword");
        return tmp;
    } else if (roll <= 43) {
        Gear tmp(1, "Belt of cloud giant strength");
        return tmp;
    } else if (roll <= 45) {
        Gear tmp(1, "Armor, +2 breastplate");
        return tmp;
    } else if (roll <= 47) {
        Gear tmp(1, "Armor, +3 chain mail");
        return tmp;
    } else if (roll <= 49) {
        Gear tmp(1, "Armor, +3 chain shirt");
        return tmp;
    } else if (roll <= 51) {
        Gear tmp(1, "Cloak of invisibility");
        return tmp;
    } else if (roll <= 53) {
        Gear tmp(1, "Crystal ball(legendary version)");
        return tmp;
    } else if (roll <= 55) {
        Gear tmp(1, "Armor, +1 half plate");
        return tmp;
    } else if (roll <= 57) {
        Gear tmp(1, "Iron flask");
        return tmp;
    } else if (roll <= 59) {
        Gear tmp(1, "Armor, +3 leather");
        return tmp;
    } else if (roll <= 61) {
        Gear tmp(1, "Armor, +1 plate");
        return tmp;
    } else if (roll <= 63) {
        Gear tmp(1, "Robe of the archmagi");
        return tmp;
    } else if (roll <= 65) {
        Gear tmp(1, "Rod of resurrection");
        return tmp;
    } else if (roll <= 67) {
        Gear tmp(1, "Armor, +1 scale mail");
        return tmp;
    } else if (roll <= 69) {
        Gear tmp(1, "Scarab of protection");
        return tmp;
    } else if (roll <= 71) {
        Gear tmp(1, "Armor, +2 splint");
        return tmp;
    } else if (roll <= 73) {
        Gear tmp(1, "Armor, +2 studded leather");
        return tmp;
    } else if (roll <= 75) {
        Gear tmp(1, "Well of many worlds");
        return tmp;
    } else if (roll <= 76) {
        string loader = "Armor, ";
        int d12 = rolld12(mgen);
        if (d12 <= 2) {
            loader += "+2 half plate";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 <= 4) {
            loader += "+2 plate";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 <= 6) {
            loader += "+3 studded leather";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 == 8) {
            loader += "+3 breastplate";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 == 10) {
            loader += "+3 splint";
            Gear tmp(1, loader);
            return tmp;
        } else if (d12 <= 11) {
            loader += "+3 half plate";
            Gear tmp(1, loader);
            return tmp;
        } else {
            loader += "+3 plate";
            Gear tmp(1, loader);
            return tmp;
        }
    } else if (roll <= 77) {
        Gear tmp(1, "Apparatus of Kwalish");
        return tmp;
    } else if (roll <= 78) {
        Gear tmp(1, "Amor of invulnerability");
        return tmp;
    } else if (roll <= 79) {
        Gear tmp(1, "Belt of storm giant strength");
        return tmp;
    } else if (roll <= 80) {
        Gear tmp(1, "Cubic gate");
        return tmp;
    } else if (roll <= 81) {
        Gear tmp(1, "Deck of many things");
        return tmp;
    } else if (roll <= 82) {
        Gear tmp(1, "Efreeti chain");
        return tmp;
    } else if (roll <= 83) {
        Gear tmp(1, "Armor of resistance(half plate)");
        return tmp;
    } else if (roll <= 84) {
        Gear tmp(1, "Horn of Valhalla(iron)");
        return tmp;
    } else if (roll <= 85) {
        Gear tmp(1, "Instrument of the bards(Ollamh harp)");
        return tmp;
    } else if (roll <= 86) {
        Gear tmp(1, "Ioun stone(greater absorption)");
        return tmp;
    } else if (roll <= 87) {
        Gear tmp(1, "Ioun stone(mastery)");
        return tmp;
    } else if (roll <= 88) {
        Gear tmp(1, "Ioun stone(regeneration)");
        return tmp;
    } else if (roll <= 89) {
        Gear tmp(1, "Plate armor of etherealness");
        return tmp;
    } else if (roll <= 90) {
        Gear tmp(1, "Plate armor of resistance");
        return tmp;
    } else if (roll <= 91) {
        Gear tmp(1, "Ring of air elemetnal command");
        return tmp;
    } else if (roll <= 93) {
        Gear tmp(1, "Ring of fire elemental command");
        return tmp;
    } else if (roll <= 94) {
        Gear tmp(1, "Ring of three wishes");
        return tmp;
    } else if (roll <= 95) {
        Gear tmp(1, "Ring of water elemental command");
        return tmp;
    } else if (roll <= 96) {
        Gear tmp(1, "Sphere of annihilation");
        return tmp;
    } else if (roll <= 97) {
        Gear tmp(1, "Talisman of pure good");
        return tmp;
    } else if (roll <= 98) {
        Gear tmp(1, "Talisman of the sphere");
        return tmp;
    } else if (roll <= 99) {
        Gear tmp(1, "Talisman of ultimate evil");
        return tmp;
    } else {
        Gear tmp(1, "Tome of stilled tongue");
        return tmp;
    }
}
