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


#include "campaign.h"
#include "globalfuncts.h"

using namespace std;

void Campaign::pc_menu() {
    int choice = 0;
    while (choice != 7) {
        simpleClearScreen();
        cout << "----------Characters-----------\n\n"
             << " 1. " << GREEN << "NEW " << RESET << "Character" << endl
             << " 2. LIST all Characters" << endl
             << " 3. VIEW a Character" << endl
             << " 4. EDIT a Character" << endl
             << " 5. " << RED << "DELETE " << RESET << "a Character" << endl
             << " 6. " << RED << "DELETE ALL " << RESET << "Characters" << endl
             << " 7. BACK to Main Menu" << endl << endl;
        choice = getNumber("Choice(1-7): ", 1, 7);
        switch (choice) {
        case 1:
        {
            simpleClearScreen();  //non-casters - RED | arcane - YELLOW | divine - CYAN
            cout << "Create a New Character! " 
                 << YELLOW << "ARCANE " << CYAN << "DIVINE " << RED << "NON_CASTER" << RESET << "\n\n";
            cout << "Character Class:\n\n"
                 << CYAN << " 1. Cleric" << "      7. Paladin\n\n" << RESET
                 << RED << " 2. Fighter" << YELLOW << "     8. Sorcerer\n\n" << RESET
                 << RED << " 3. Rogue" << YELLOW << "       9. Bard\n\n" << RESET
                 << YELLOW << " 4. Wizard" << RED << "     10. Monk\n\n" << RESET
                 << RED << " 5. Barbarian" << CYAN << "  11. Ranger\n\n" << RESET
                 << CYAN << " 6. Druid" << YELLOW << "      12. Warlock\n\n" << RESET;
            int select_class = getNumber("Class Choice(1-12): ", 1, 12);
            int starting_level = getNumber("\nStarting Level(1-20): ", 1, 20);
            simpleClearScreen();
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
        case 2: {
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
        case 3: {  //CHARACTER SHEET
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
                    if (!found) cout << "No character named " << valid_name << ". List of Charcters:\n";
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
        case 4: {  //EDIT/UPDATE CHARACTER
            cin.get();
            string pwd = "";
            cout << "Enter entrance keyword: ";
            getline(cin, pwd, '\n');
            if (pwd == "password") {
                cout << "entrance allowed\n";
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
                        if (!found) cout << "\nNo character named " << valid_name << ". List of Charcters:\n\n";
                        for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                            cout << (*it)->name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << endl;
                        }
                        cout << endl;
                    }
                    for (list<Generic_Character_Class*>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it) {
                        if (valid_name == (*it)->name) (*it)->updateCharacter(*this);
                    }

                }
            } else {
                cout << "entry denied";
            }
            pressEnterToContinue();
        }
            
            break;
        case 5: {   //DELETE CHARACTER
            if (character_list.size() < 1) {
                cout << "No characters. Nothing to Delete! \n";
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
                cout << "All Characters Deleted. Press 'Cntl + C' now to reverse this.\n\n";
            } else {
                cout << "Nothing Deleted.\n\n";
            }
        }
            pressEnterToContinue();
            break;
        default:
            cout << "Option doesn't exist.\n";
        }
    }
    simpleClearScreen();
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
    bool goodname = false;
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
    char ans = getYorN("Display Character Sheet now[y/n]?");
    if (ans == 'Y') character_list.back()->character_sheet();
    pressEnterToContinue();
}
ofstream& Campaign::dumpCharacter(ofstream& os) const {
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

                    //class level up menus prep for multiclass functions
                << (*it)->clericlevelupmenus << endl
                << (*it)->fighterlevelupmenus << endl
                << (*it)->roguelevelupmenus << endl
                << (*it)->wizardlevelupmenus << endl
                << (*it)->barbarianlevelupmenus << endl
                << (*it)->druidlevelupmenus << endl
                << (*it)->paladinlevelupmenus << endl
                << (*it)->sorcererlevelupmenus << endl
                << (*it)->bardlevelupmenus << endl
                << (*it)->monklevelupmenus << endl
                << (*it)->rangerlevelupmenus << endl
                << (*it)->warlocklevelupmenus << endl

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
                << (*it)->arcana_d << endl
                << (*it)->death_d << endl
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
                << (*it)->purple_dragon_knight << endl
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
                << (*it)->path_of_the_battlerager << endl
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
                << (*it)->way_of_the_long_death << endl
                << (*it)->way_of_the_shadow << endl
                << (*it)->way_of_the_sun_soul << endl
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
                << (*it)->oath_of_ancients << endl
                << (*it)->oath_of_devotion << endl
                << (*it)->oath_of_the_crown << endl
                << (*it)->oath_of_vengeance << endl
                << (*it)->oathbreaker << endl
                << "ranger" << endl
                << (*it)->favored_enemy << endl  //ranger
                << (*it)->favored_enemy_languages << endl
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
                << (*it)->mastermind << endl
                << (*it)->swashbuckler << endl
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
                << (*it)->storm_sorcery << endl
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
                << (*it)->the_undying << endl
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
                << (*it)->bladesinging << endl
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');

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

        getline(ins, v->char_class);
        getline(ins, v->name);
        getline(ins, v->race);
        getline(ins, v->alignment);
        ins >> v->level;
        ins >> v->clericlevelupmenus;
        ins >> v->fighterlevelupmenus;
        ins >> v->roguelevelupmenus;
        ins >> v->wizardlevelupmenus;
        ins >> v->barbarianlevelupmenus;
        ins >> v->druidlevelupmenus;
        ins >> v->paladinlevelupmenus;
        ins >> v->sorcererlevelupmenus;
        ins >> v->bardlevelupmenus;
        ins >> v->monklevelupmenus;
        ins >> v->rangerlevelupmenus;
        ins >> v->warlocklevelupmenus;
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');   //  class stuff general
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //cleric
        ins >> v->destroy_undead;  
        ins >> v->channel_divinity;
        ins >> v->divine_domain_feature;
        ins >> v->divine_intervention;
        ins >> v->cleric_cantrips_known;
        ins >> v->divine_domain;
        ins >> v->arcana_d;
        ins >> v->death_d;
        ins >> v->knowledge_d;
        ins >> v->life_d;
        ins >> v->light_d;
        ins >> v->nature_d;
        ins >> v->tempest_d;
        ins >> v->trickery_d;
        ins >> v->war_d;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //fighter
        ins >> v->action_surge;   
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
        ins >> v->purple_dragon_knight;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //barbarian
        ins >> v->rages;  
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
        ins >> v->path_of_the_battlerager;
        ins >> v->path_of_the_berseker;
        ins >> v->path_of_the_totem_warrior;
        ins >> v->bear_totem;
        ins >> v->eagle_totem;
        ins >> v->wolf_totem;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//bard
        ins >> v->bardic_inspiration; 
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //druid
        ins >> v->wild_shape_improvement;
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//monk
        ins >> v->monastic_tradition_feature; 
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
        ins >> v->way_of_the_long_death;
        ins >> v->way_of_the_shadow;
        ins >> v->way_of_the_sun_soul;
        ins >> v->unarmored_movement_improvement;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//paladin
        ins >> v->sacred_oath_feature; 
        ins >> v->divine_smite;
        ins >> v->divine_sense;
        ins >> v->lay_on_hands;
        ins >> v->divine_health;
        ins >> v->sacred_oath;
        ins >> v->aura_of_protection;
        ins >> v->aura_of_courage;
        ins >> v->cleansing_touch;
        ins >> v->aura_improvments;
        ins >> v->oath_of_ancients;
        ins >> v->oath_of_devotion;
        ins >> v->oath_of_the_crown;
        ins >> v->oath_of_vengeance;
        ins >> v->oathbreaker;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//ranger
        ins >> v->favored_enemy;  
        ins >> v->favored_enemy_languages;
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//rogue
        ins >> v->roguish_archetype_feature; 
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
        ins >> v->mastermind;
        ins >> v->swashbuckler;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//sorcerer
        ins >> v->sorcerous_origin_feature;  
        ins >> v->metamagic;
        ins >> v->sorcery_points;
        ins >> v->sorcerer_spells_known;
        ins >> v->sorcerer_cantrips_known;
        ins >> v->sorcerous_origin;
        ins >> v->font_of_magic;
        ins >> v->sorcerous_restoration;
        ins >> v->draconic_bloodline;
        ins >> v->wild_magic;
        ins >> v->storm_sorcery;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //warlock
        ins >> v->warlock_slot_level; 
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
        ins >> v->the_undying;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //wizard
        ins >> v->arcane_tradition_feature; 
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
        ins >> v->bladesinging;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //landtypes
        ins >> v->artic;
        ins >> v->coast;
        ins >> v->desert;
        ins >> v->forest;
        ins >> v->grassland;
        ins >> v->mountain;
        ins >> v->swamp;
        ins >> v->underdark;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');  //creaturetype
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');//spellslots
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //skills
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');  //feats
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //languages
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //features
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n'); //resistances
        ins >> v->damage_resist_acid;
        ins >> v->damage_resist_ltg;
        ins >> v->damage_resist_fire;
        ins >> v->damage_resist_poison;
        ins >> v->damage_resist_cold;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');  //disadvantages
        ins >> v->sunlight_sensitivity;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');  //artisan tools & supplies
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
        ins.ignore(numeric_limits<streamsize>::max(), '\n');  //kits & tools
        ins >> v->disguise;
        ins >> v->forgery;
        ins >> v->herbalism;
        ins >> v->navigator;
        ins >> v->poisoner;
        ins >> v->thieves;
        ins >> v->vehicle;
        ins.get();
        ins.ignore(numeric_limits<streamsize>::max(), '\n');  //musical instruments
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


