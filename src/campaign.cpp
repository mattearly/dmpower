#include "campaign.h"
#include "globalfuncts.h"
#include "characters.h"
#include "terminal_colors.h"

using namespace std;

bool quitBuilding = false; // for exiting out of the build character at certain points

void Campaign::pc_menu()
{
  int choice = 0;
  while (choice != 8)
  {
    if (clearScreens)
      simpleClearScreen();
    cout << ">" << mainMessage << "\n\n";
    mainMessage = "";
    cout << GREEN << "---------- CHARACTER MANAGER -----------" << RESET << '\n';

    if (myGame.character_list.size() != 0) // there are characters, show options
    {
      std::cout
          << " 1. Create Another Character" << '\n'
          << " 2. Save Work" << '\n'
          << " 3. View Characters" << '\n'
          << " 4. Edit a Character" << '\n'
          << " 5. Delete a Character" << '\n'
          << " 6. Delete All Characters" << '\n';
    }
    else // no characters, show ...
    {
      std::cout
          << " 1. Create Your First Character\n"
          << "    ...\n";
    }

    std::cout << " 7. ";
    if (loadSuccess)
    {
      cout << "Unload current file:[" << GREEN << loadedFile << RESET << "]. You will lose all unsaved changes.\n";
    }
    else
    {
      cout << "Load Campaign" << '\n';
    }

    cout << " 8. Back to " << CYAN << "MAIN MENU" << RESET << '\n';
    cout << GREEN << "----------------------------------------" << RESET << '\n';
    choice = getNumber("Choice: ", 1, 8);
    switch (choice)
    {
    case 1:
    { // CREATE A CHARACTER
      if (clearScreens)
        simpleClearScreen();
      cout << "Create Random Character?\n\n";
      cout << "1. Random Character" << '\n';
      cout << "2. Manual Character" << '\n'
           << '\n';
      int randomized = getNumber("Choice: ", 1, 2);
      is_random = (randomized == 1) ? true : false;

      int starting_level = 0;

      if (is_random)
      {
        cout << "Pick a level for your random character.\n\n";
        is_random = false;
        starting_level = getNumber("Starting Level(1-20): ", 1, 20);
        is_random = true;
      }

      cout << " Create a New Character! \n\n"
           << "Type Legend: " << YELLOW << "ARCANE " << CYAN << "DIVINE " << RED << "NON CASTER" << RESET << "\n\n"
           << "Character Classes Available:\n\n"
           << CYAN << " 1. Cleric" << CYAN << "      7. Paladin\n"
           << RESET
           << RED << " 2. Fighter" << YELLOW << "     8. Sorcerer\n"
           << RESET
           << RED << " 3. Rogue" << YELLOW << "       9. Bard\n"
           << RESET
           << YELLOW << " 4. Wizard" << RED << "     10. Monk\n"
           << RESET
           << RED << " 5. Barbarian" << CYAN << "  11. Ranger\n"
           << RESET
           << CYAN << " 6. Druid" << YELLOW << "      12. Warlock\n\n"
           << RESET;
      int select_class = getNumberOrQ(1, 12);
      if (select_class == -1)
        return;

      if (!is_random)
      {
        starting_level = getNumber("Starting Level(1-20): ", 1, 20);
      }

      if (clearScreens)
        simpleClearScreen();

      Generic_Character_Class *new_character_build = nullptr;
      switch (select_class)
      {
      case 1:
      {
        new_character_build = new Cleric;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 2:
      {
        new_character_build = new Fighter;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 3:
      {
        new_character_build = new Rogue;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 4:
      {
        new_character_build = new Wizard;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 5:
      {
        new_character_build = new Barbarian;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 6:
      {
        new_character_build = new Druid;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 7:
      {
        new_character_build = new Paladin;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 8:
      {
        new_character_build = new Sorcerer;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 9:
      {
        new_character_build = new Bard;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 10:
      {
        new_character_build = new Monk;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 11:
      {
        new_character_build = new Ranger;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      case 12:
      {
        new_character_build = new Warlock;
        new_character_build->setInitialClassFeatures();
        makecharacter(new_character_build, starting_level);
      }
      break;
      default:
        break;
      }

      if (autoSave)
      {
        auto_save();
      }

      is_random = false;
    }
    break;
    case 2:
      save_file();
      break;
    case 3:
    { //VIEW & EXPORT CHARACTER SHEET
      if (character_list.size() < 1)
      {
        mainMessage = "Nothing to display. Create characters first.";
      }
      else
      {
        cout << "Current campaign characters:\n\n";
        showCampaignCharacterList();
        bool found = false;
        string valid_name;
        while (!found)
        {
          cout << "VIEW: Enter the character's " << GREEN << "NAME" << RESET << " (leave blank to exit)\n->";
          getline(cin, valid_name);
          if (valid_name.length() == 0)
            break; //break out of while loop, still hits for loop below but wont find anything. todo: improve
          valid_name[0] = toupper(valid_name[0]);
          for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
          {
            if ((*it)->char_name == valid_name)
            {
              found = true;
              break; //leave loop if we found the name, no need to check more
            }
          }
          if (!found)
          {
            cout << "No character named " << valid_name << '\n';
          }
        }
        for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
        {
          if (valid_name == (*it)->char_name)
          {
            // show character sheet
            (*it)->character_sheet();

            // prompts to export
            char to_export = getYorN("Export/Print Character? (y/n): ");
            if (to_export == 'Y')
            {
              std::string printname = (*it)->char_name + " lvl " + toString((*it)->level) + " " +
                                      (*it)->race + " " + (*it)->char_class;
              (*it)->exportPrint(printname);
              mainMessage = printname + " exported, check exports folder.";
            }

            break; //leave the loop if we found the name, no need to check more
          }
        }
      }
    }
    break;
    case 4:
    { //EDIT/UPDATE CHARACTER
      if (character_list.size() < 1)
      {
        mainMessage = "No characters to Edit. Create some characters first.";
      }
      else
      {
        cout << "Current campaign characters:\n\n";
        showCampaignCharacterList();
        bool found = false;
        string valid_name;
        while (!found)
        {
          cout << "EDIT: Enter the character's " << GREEN << "Name" << RESET << " (leave blank to exit)\n->";
          getline(cin, valid_name);
          if (valid_name.length() == 0)
            break; //break out of while loop, still hits for loop below but wont find anything. todo: improve
          valid_name[0] = toupper(valid_name[0]);
          for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
          {
            if ((*it)->char_name == valid_name)
            {
              found = true;
            }
          }
          if (!found)
            cout << "\nNo character named " << valid_name << ". List of Charcters:\n\n";
        }
        for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
        {
          if (valid_name == (*it)->char_name)
          {
            (*it)->updateCharacter(*this);
            break;
          }
        }
      }
      if (autoSave)
      {
        auto_save();
      }
    }
    break;
    case 5:
    { //DELETE CHARACTER
      if (character_list.size() < 1)
      {
        mainMessage = "No characters. Nothing to Delete!";
      }
      else
      {
        cout << "Current campaign characters:\n\n";
        showCampaignCharacterList();
        string tmp;
        do
        {
          cout << "DELETE: Enter character's " << GREEN << "NAME" << RESET << " (leave blank to exit)\n->";
          getline(cin, tmp);
          if (tmp.length() == 0)
            break; //break out of do-while loop
          tmp[0] = toupper(tmp[0]);
          for (list<Generic_Character_Class *>::iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
          {
            if ((*it)->char_name == tmp)
            {
              mainMessage = "Deleted " + tmp + ". Goodbye " + tmp + ". You might be missed. *sob*";
              character_list.erase(it);
              tmp = "";
              break;
            }
          }
        } while (tmp != "");
      }
    }
    break;
    case 6:
    { //DELETE ALL THE THINGS
      char sure = getYorN("Are you Sure you want to Delete All Player Characters?(y/n):");
      if (sure == 'Y')
      {
        character_list.clear();
        mainMessage = "All Characters Deleted. Your next save will write this change.";
      }
      else
      {
        mainMessage = "Nothing Deleted.\n\n";
      }
    }
    break;
    case 7:
      if (!loadSuccess)
      {
        load_file();
      }
      else
      {
        character_list.clear();
        loadedFile = "";
        loadSuccess = false;
      }
      break;
    default:
      break;
    }
  }
  if (clearScreens)
    simpleClearScreen();
}

bool Campaign::checkname(const string &n) const
{
  for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
  {
    if ((*it)->char_name == n)
    {
      cout << "Name Already Exists.\n";
      return false;
    }
  }
  return true;
}

void Campaign::makecharacter(Generic_Character_Class *new_character, int &starting_level)
{
  new_character->level = starting_level;

  bool goodname = false;

  if (clearScreens)
    simpleClearScreen();
  while (!goodname)
  {
    new_character->setName();
    goodname = checkname(new_character->char_name);
  }

  new_character->setAllStats();

  if (quitBuilding)
  {
    quitBuilding = false;
    delete new_character;
    return;
  }

  new_character->setRace(*new_character);
  new_character->setAlignment();
  new_character->setBackground();
  new_character->setClassDetails(starting_level);
  new_character->setProficiencyBonus();
  new_character->initialSkillsSet = true;
  character_list.push_back(new_character);

  // turn random var back off in case it was on
  is_random = false;

  // show character sheet after building is complete
  character_list.back()->character_sheet();

  //update main message to something useful
  if (!autoSave)
    mainMessage = "note: autosave is not on, don\'t forget to save your work.";
}

ofstream &Campaign::dumpCharacter(ofstream &os) const
{
  os << saveVersion << '\n'; // build number to keep saves working correctly
  int charactercount = 0;
  for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
  {
    charactercount++;
    os
        << "saved character: " << charactercount << '\n'
        //basics
        << (*it)->char_class << '\n'
        << (*it)->char_name << '\n'
        << (*it)->race << '\n'
        << (*it)->alignment << '\n'
        << (*it)->level << '\n'

        //class level up menus prep for multiclass functions
        << (*it)->clericlevelupmenus << '\n'
        << (*it)->fighterlevelupmenus << '\n'
        << (*it)->roguelevelupmenus << '\n'
        << (*it)->wizardlevelupmenus << '\n'
        << (*it)->barbarianlevelupmenus << '\n'
        << (*it)->druidlevelupmenus << '\n'
        << (*it)->paladinlevelupmenus << '\n'
        << (*it)->sorcererlevelupmenus << '\n'
        << (*it)->bardlevelupmenus << '\n'
        << (*it)->monklevelupmenus << '\n'
        << (*it)->rangerlevelupmenus << '\n'
        << (*it)->warlocklevelupmenus << '\n'

        << (*it)->backgroundofpc << '\n'
        << (*it)->custom_background_name << '\n'

        << (*it)->move_speed << '\n'
        << (*it)->fly_speed << '\n'
        << (*it)->swim_speed << '\n'
        << (*it)->climb_speed << '\n'
        << (*it)->hitdicesize << '\n'
        << (*it)->proficiency_bonus << '\n'
        << (*it)->strength << '\n'
        << (*it)->dexterity << '\n'
        << (*it)->constitution << '\n'
        << (*it)->intelligence << '\n'
        << (*it)->wisdom << '\n'
        << (*it)->charisma << '\n'
        << (*it)->strSave << '\n'
        << (*it)->dexSave << '\n'
        << (*it)->conSave << '\n'
        << (*it)->intSave << '\n'
        << (*it)->wisSave << '\n'
        << (*it)->chaSave << '\n'
        //class stuff - general
        << "generalclassstuff" << '\n'
        << (*it)->extra_attack << '\n'
        << (*it)->expertise << '\n'
        << (*it)->spellcasting << '\n'
        << (*it)->timeless_body << '\n'
        << (*it)->evasion << '\n'
        << (*it)->unarmored_defense << '\n'
        << (*it)->fighting_style << '\n'
        << (*it)->defense << '\n'
        << (*it)->dueling << '\n'
        << (*it)->great_weapon_fighting << '\n'
        << (*it)->protection << '\n'
        << "cleric" << '\n'
        << (*it)->destroy_undead << '\n' //cleric
        << (*it)->channel_divinity << '\n'
        << (*it)->divine_domain_feature << '\n'
        << (*it)->divine_intervention << '\n'
        << (*it)->cleric_cantrips_known << '\n'
        << (*it)->divine_domain << '\n'
        << (*it)->arcana_d << '\n'
        << (*it)->death_d << '\n'
        << (*it)->knowledge_d << '\n'
        << (*it)->life_d << '\n'
        << (*it)->light_d << '\n'
        << (*it)->nature_d << '\n'
        << (*it)->tempest_d << '\n'
        << (*it)->trickery_d << '\n'
        << (*it)->war_d << '\n'
        << "fighter" << '\n'
        << (*it)->action_surge << '\n' //fighter
        << (*it)->martial_archtype_feature << '\n'
        << (*it)->indomitable << '\n'
        << (*it)->eldritch_spells_known << '\n'
        << (*it)->second_wind << '\n'
        << (*it)->martial_archtype << '\n'
        << (*it)->archery << '\n'
        << (*it)->two_weapon_fighting << '\n'
        << (*it)->champion << '\n'
        << (*it)->battle_master << '\n'
        << (*it)->eldritch_knight << '\n'
        << (*it)->purple_dragon_knight << '\n'
        << "barbarian" << '\n'
        << (*it)->rages << '\n' //barbarian
        << (*it)->rage_damage << '\n'
        << (*it)->path_feature << '\n'
        << (*it)->brutal_critical << '\n'
        << (*it)->reckless_attack << '\n'
        << (*it)->danger_sense << '\n'
        << (*it)->primal_path << '\n'
        << (*it)->fast_movement << '\n'
        << (*it)->feral_instinct << '\n'
        << (*it)->relentless_rage << '\n'
        << (*it)->persistant_rage << '\n'
        << (*it)->indomitable_might << '\n'
        << (*it)->primal_champion << '\n'
        << (*it)->path_of_the_battlerager << '\n'
        << (*it)->path_of_the_berseker << '\n'
        << (*it)->path_of_the_totem_warrior << '\n'
        << (*it)->bear_totem << '\n'
        << (*it)->eagle_totem << '\n'
        << (*it)->wolf_totem << '\n'
        << "bard" << '\n'
        << (*it)->bardic_inspiration << '\n' //bard
        << (*it)->song_of_rest << '\n'
        << (*it)->bard_college_feature << '\n'
        << (*it)->magical_secrets << '\n'
        << (*it)->bard_spells_known << '\n'
        << (*it)->bard_cantrips_known << '\n'
        << (*it)->jack_of_all_trades << '\n'
        << (*it)->bard_college << '\n'
        << (*it)->font_of_inspiration << '\n'
        << (*it)->countercharm << '\n'
        << (*it)->superior_inspiration << '\n'
        << (*it)->college_of_lore << '\n'
        << (*it)->college_of_valor << '\n'
        << (*it)->additional_magical_secrets << '\n'
        << "druid" << '\n'
        << (*it)->wild_shape_improvement << '\n' //druid
        << (*it)->druid_circle_feature << '\n'
        << (*it)->druid_cantrips_known << '\n'
        << (*it)->wild_shape << '\n'
        << (*it)->druid_circle << '\n'
        << (*it)->beast_spells << '\n'
        << (*it)->archdruid << '\n'
        << (*it)->circle_of_the_moon << '\n'
        << (*it)->circle_of_the_land << '\n'
        << "monk" << '\n'
        << (*it)->monastic_tradition_feature << '\n' //monk
        << (*it)->ki << '\n'
        << (*it)->unarmored_movement << '\n'
        << (*it)->martial_arts << '\n'
        << (*it)->monastic_tradition << '\n'
        << (*it)->deflect_missles << '\n'
        << (*it)->slow_fall << '\n'
        << (*it)->stunning_strike << '\n'
        << (*it)->ki_empowered_strikes << '\n'
        << (*it)->stillness_of_mind << '\n'
        << (*it)->purity_of_body << '\n'
        << (*it)->tongue_of_the_sun_and_moon << '\n'
        << (*it)->diamond_soul << '\n'
        << (*it)->empty_body << '\n'
        << (*it)->perfect_self << '\n'
        << (*it)->way_of_the_open_hand << '\n'
        << (*it)->way_of_the_four_elements << '\n'
        << (*it)->way_of_the_long_death << '\n'
        << (*it)->way_of_the_shadow << '\n'
        << (*it)->way_of_the_sun_soul << '\n'
        << (*it)->unarmored_movement_improvement << '\n'
        << "paladin" << '\n'
        << (*it)->sacred_oath_feature << '\n' //paladin
        << (*it)->divine_smite << '\n'
        << (*it)->divine_sense << '\n'
        << (*it)->lay_on_hands << '\n'
        << (*it)->divine_health << '\n'
        << (*it)->sacred_oath << '\n'
        << (*it)->aura_of_protection << '\n'
        << (*it)->aura_of_courage << '\n'
        << (*it)->cleansing_touch << '\n'
        << (*it)->aura_improvments << '\n'
        << (*it)->oath_of_ancients << '\n'
        << (*it)->oath_of_devotion << '\n'
        << (*it)->oath_of_the_crown << '\n'
        << (*it)->oath_of_vengeance << '\n'
        << (*it)->oathbreaker << '\n'
        << "ranger" << '\n'
        << (*it)->favored_enemy << '\n' //ranger
        << (*it)->favored_enemy_languages << '\n'
        << (*it)->natural_explorer << '\n'
        << (*it)->ranger_archetype_feature << '\n'
        << (*it)->ranger_spells_known << '\n'
        << (*it)->ranger_archetype << '\n'
        << (*it)->primeval_awareness << '\n'
        << (*it)->lands_stride << '\n'
        << (*it)->hide_in_plain_sight << '\n'
        << (*it)->vanish << '\n'
        << (*it)->feral_senses << '\n'
        << (*it)->foe_slayer << '\n'
        << (*it)->hunter << '\n'
        << (*it)->beast_master << '\n'
        << "rogue" << '\n'
        << (*it)->roguish_archetype_feature << '\n' //rogue
        << (*it)->arcane_t_spells_known << '\n'
        << (*it)->sneak_attack << '\n'
        << (*it)->thieves_cant << '\n'
        << (*it)->cunning_action << '\n'
        << (*it)->roguish_archetype << '\n'
        << (*it)->uncanny_dodge << '\n'
        << (*it)->reliable_talent << '\n'
        << (*it)->blindsense << '\n'
        << (*it)->slippery_mind << '\n'
        << (*it)->elusive << '\n'
        << (*it)->stroke_of_luck << '\n'
        << (*it)->thief << '\n'
        << (*it)->assassin << '\n'
        << (*it)->arcane_trickster << '\n'
        << (*it)->mastermind << '\n'
        << (*it)->swashbuckler << '\n'
        << "sorcerer" << '\n'
        << (*it)->sorcerous_origin_feature << '\n' //sorcerer
        << (*it)->metamagic << '\n'
        << (*it)->sorcery_points << '\n'
        << (*it)->sorcerer_spells_known << '\n'
        << (*it)->sorcerer_cantrips_known << '\n'
        << (*it)->sorcerous_origin << '\n'
        << (*it)->font_of_magic << '\n'
        << (*it)->sorcerous_restoration << '\n'
        << (*it)->draconic_bloodline << '\n'
        << (*it)->wild_magic << '\n'
        << (*it)->storm_sorcery << '\n'
        << "warlock" << '\n'
        << (*it)->warlock_slot_level << '\n' //warlock
        << (*it)->eldritch_invocations_known << '\n'
        << (*it)->warlock_spells_known << '\n'
        << (*it)->warlock_spell_slots << '\n'
        << (*it)->warlock_cantrips_known << '\n'
        << (*it)->otherworldly_patron_feature << '\n'
        << (*it)->mystic_arcanum << '\n'
        << (*it)->otherworldly_patron << '\n'
        << (*it)->pact_magic << '\n'
        << (*it)->pact_boon << '\n'
        << (*it)->eldritch_master << '\n'
        << (*it)->archfey << '\n'
        << (*it)->fiend << '\n'
        << (*it)->great_old_one << '\n'
        << (*it)->the_undying << '\n'
        << "wizard" << '\n'
        << (*it)->arcane_tradition_feature << '\n' //wizard
        << (*it)->wizard_cantrips_known << '\n'
        << (*it)->arcane_recovery << '\n'
        << (*it)->arcane_tradition << '\n'
        << (*it)->spell_mastery << '\n'
        << (*it)->signature_spell << '\n'
        << (*it)->abjuration << '\n'
        << (*it)->conjuration << '\n'
        << (*it)->divination << '\n'
        << (*it)->enchantment << '\n'
        << (*it)->evocation << '\n'
        << (*it)->illusion << '\n'
        << (*it)->necromancy << '\n'
        << (*it)->transmutation << '\n'
        << (*it)->bladesinging << '\n'
        << "landtypes" << '\n' //landtypes
        << (*it)->artic << '\n'
        << (*it)->coast << '\n'
        << (*it)->desert << '\n'
        << (*it)->forest << '\n'
        << (*it)->grassland << '\n'
        << (*it)->mountain << '\n'
        << (*it)->swamp << '\n'
        << (*it)->underdark << '\n'
        << "creaturetype" << '\n' //creaturetype
        << (*it)->twohumanoids << '\n'
        << (*it)->aberrations << '\n'
        << (*it)->beasts << '\n'
        << (*it)->celestials << '\n'
        << (*it)->constructs << '\n'
        << (*it)->dragons << '\n'
        << (*it)->elementals << '\n'
        << (*it)->fey << '\n'
        << (*it)->fiends << '\n'
        << (*it)->giants << '\n'
        << (*it)->monstrosities << '\n'
        << (*it)->oozes << '\n'
        << (*it)->plants << '\n'
        << (*it)->undead << '\n'
        << "spellslots" << '\n' //spellslots
        << (*it)->first_ss << '\n'
        << (*it)->second_ss << '\n'
        << (*it)->third_ss << '\n'
        << (*it)->forth_ss << '\n'
        << (*it)->fifth_ss << '\n'
        << (*it)->sixth_ss << '\n'
        << (*it)->seventh_ss << '\n'
        << (*it)->eighth_ss << '\n'
        << (*it)->ninth_ss << '\n'
        << (*it)->warlock_ss << '\n'
        << "skills" << '\n' //skills
        << (*it)->initialSkillsSet << '\n'
        << (*it)->acrobatics << '\n'
        << (*it)->animal_handling << '\n'
        << (*it)->arcana << '\n'
        << (*it)->athletics << '\n'
        << (*it)->deception << '\n'
        << (*it)->history << '\n'
        << (*it)->insight << '\n'
        << (*it)->intimidation << '\n'
        << (*it)->investigation << '\n'
        << (*it)->medicine << '\n'
        << (*it)->nature << '\n'
        << (*it)->perception << '\n'
        << (*it)->performance << '\n'
        << (*it)->persuasion << '\n'
        << (*it)->religion << '\n'
        << (*it)->sleight_of_hand << '\n'
        << (*it)->stealth << '\n'
        << (*it)->survival << '\n'
        << "feats" << '\n' //feats
        << (*it)->alert << '\n'
        << (*it)->athlete << '\n'
        << (*it)->actor << '\n'
        << (*it)->charger << '\n'
        << (*it)->crossbow_expert << '\n'
        << (*it)->defensive_duelist << '\n'
        << (*it)->dual_wielder << '\n'
        << (*it)->dungeon_delver << '\n'
        << (*it)->durable << '\n'
        << (*it)->elemental_adept << '\n'
        << (*it)->grappler << '\n'
        << (*it)->great_weapon_master << '\n'
        << (*it)->healer << '\n'
        << (*it)->heavily_armored << '\n'
        << (*it)->heavy_armor_master << '\n'
        << (*it)->inspiring_leader << '\n'
        << (*it)->keen_mind << '\n'
        << (*it)->lightly_armored << '\n'
        << (*it)->linguist << '\n'
        << (*it)->lucky << '\n'
        << (*it)->mage_slayer << '\n'
        << (*it)->magic_initiate << '\n'
        << (*it)->martial_adept << '\n'
        << (*it)->medium_armor_master << '\n'
        << (*it)->mobile << '\n'
        << (*it)->moderately_armored << '\n'
        << (*it)->mounted_combatant << '\n'
        << (*it)->observant << '\n'
        << (*it)->polearm_master << '\n'
        << (*it)->resilient << '\n'
        << (*it)->ritual_caster << '\n'
        << (*it)->savage_attacker << '\n'
        << (*it)->sentinel << '\n'
        << (*it)->sharpshooter << '\n'
        << (*it)->shield_master << '\n'
        << (*it)->skilled << '\n'
        << (*it)->skulker << '\n'
        << (*it)->spell_sniper << '\n'
        << (*it)->svirfneblin_magic << '\n'
        << (*it)->tavern_brawler << '\n'
        << (*it)->tough << '\n'
        << (*it)->war_caster << '\n'
        << (*it)->weapon_master << '\n'
        << "languages" << '\n' //languages
        << (*it)->abyssal << '\n'
        << (*it)->aquan << '\n'
        << (*it)->auran << '\n'
        << (*it)->celestial << '\n'
        << (*it)->common << '\n'
        << (*it)->deep_speech << '\n'
        << (*it)->draconic << '\n'
        << (*it)->druidic << '\n'
        << (*it)->dwarvish << '\n'
        << (*it)->elvish << '\n'
        << (*it)->giant << '\n'
        << (*it)->gnomish << '\n'
        << (*it)->goblin << '\n'
        << (*it)->gnoll << '\n'
        << (*it)->halfling << '\n'
        << (*it)->infernal << '\n'
        << (*it)->orc << '\n'
        << (*it)->primordial << '\n'
        << (*it)->sylvan << '\n'
        << (*it)->undercommon << '\n'
        << "features" << '\n' //features
        << (*it)->artificers_lore << '\n'
        << (*it)->brave << '\n'
        << (*it)->breath_weapon_acid << '\n'
        << (*it)->breath_weapon_ltg << '\n'
        << (*it)->breath_weapon_fire << '\n'
        << (*it)->breath_weapon_poison << '\n'
        << (*it)->breath_weapon_cold << '\n'
        << (*it)->darkvision << '\n'
        << (*it)->devils_tongue << '\n'
        << (*it)->draconic_ancestry_black << '\n'
        << (*it)->draconic_ancestry_blue << '\n'
        << (*it)->draconic_ancestry_brass << '\n'
        << (*it)->draconic_ancestry_bronze << '\n'
        << (*it)->draconic_ancestry_copper << '\n'
        << (*it)->draconic_ancestry_gold << '\n'
        << (*it)->draconic_ancestry_green << '\n'
        << (*it)->draconic_ancestry_red << '\n'
        << (*it)->draconic_ancestry_silver << '\n'
        << (*it)->draconic_ancestry_white << '\n'
        << (*it)->drow_magic << '\n'
        << (*it)->drow_weapon_training << '\n'
        << (*it)->dwarven_armor_training << '\n'
        << (*it)->dwarven_combat_training << '\n'
        << (*it)->dwarven_resilience << '\n'
        << (*it)->dwarven_toughness << '\n'
        << (*it)->duergar_resilience << '\n'
        << (*it)->duergar_magic << '\n'
        << (*it)->elf_weapon_training << '\n'
        << (*it)->expert_forgery << '\n'
        << (*it)->fey_ancestry << '\n'
        << (*it)->firbolg_magic << '\n'
        << (*it)->fleet_of_foot << '\n'
        << (*it)->halflinglucky << '\n'
        << (*it)->halfling_nimbleness << '\n'
        << (*it)->hidden_step << '\n'
        << (*it)->hellfire << '\n'
        << (*it)->hellish_resistance << '\n'
        << (*it)->hold_breath << '\n'
        << (*it)->infernal_legacy << '\n'
        << (*it)->mask_of_the_wild << '\n'
        << (*it)->mimicry << '\n'
        << (*it)->natural_illusionist << '\n'
        << (*it)->naturally_stealthy << '\n'
        << (*it)->powerful_build << '\n'
        << (*it)->silent_speech << '\n'
        << (*it)->speak_with_small_beasts << '\n'
        << (*it)->speech_of_beast_and_leaf << '\n'
        << (*it)->stonecunning << '\n'
        << (*it)->stone_camouflage << '\n'
        << (*it)->stones_endurance << '\n'
        << (*it)->stout_resilience << '\n'
        << (*it)->superior_darkvision << '\n'
        << (*it)->trance << '\n'
        //aasimar stuff
        << (*it)->healing_hands << '\n'

        << (*it)->light_bearer << '\n'
        << (*it)->necrotic_shroud << '\n'
        << (*it)->radiant_consumption << '\n'
        << (*it)->radiant_soul << '\n'
        //lizardfolk stuff
        << (*it)->lizardfolk_bite << '\n'
        << (*it)->cunning_artisan << '\n'
        << (*it)->natural_armor << '\n'
        << (*it)->hungry_jaws << '\n'
        //tabaxi stuff
        << (*it)->feline_agility << '\n'
        << (*it)->cats_claws << '\n'
        //triton stuff
        << (*it)->amphibious << '\n'
        << (*it)->control_air_and_water << '\n'
        << (*it)->emissary_of_the_sea << '\n'
        << (*it)->guardian_of_the_depths << '\n'
        //warforged stuff
        << (*it)->composite_plating << '\n'
        << (*it)->living_construct << '\n'
        //changeling stuff
        << (*it)->shapechanger << '\n'
        //shifter stuff
        << (*it)->shifting << '\n'
        //tortle stuff
        << (*it)->shell << '\n'
        << (*it)->retreat_to_shell << '\n'
        << (*it)->turtle_snapper << '\n'
        << (*it)->razorback << '\n'
        << (*it)->razor_fist << '\n'
        << (*it)->softshell << '\n'
        << (*it)->nomad << '\n'
        << (*it)->shell_master << '\n'
        //aarakocra stuff
        << (*it)->talons << '\n'
        //genasi stuff
        << (*it)->unending_breath << '\n'
        << (*it)->mingle_with_the_wind << '\n'
        << (*it)->earth_walk << '\n'
        << (*it)->merge_with_stone << '\n'
        << (*it)->reach_to_the_blaze << '\n'
        << (*it)->call_to_the_wave << '\n'

        << "resistances" << '\n' //resistances
        << (*it)->damage_resist_acid << '\n'
        << (*it)->damage_resist_ltg << '\n'
        << (*it)->damage_resist_fire << '\n'
        << (*it)->damage_resist_poison << '\n'
        << (*it)->damage_resist_cold << '\n'
        << (*it)->damage_resist_necrotic << '\n'
        << (*it)->damage_resist_radiant << '\n'
        << "disadvantages" << '\n' //disadvantages
        << (*it)->sunlight_sensitivity << '\n'
        << "tools" << '\n' //artisan tools & supplies
        << (*it)->alchemist << '\n'
        << (*it)->brewer << '\n'
        << (*it)->calligrapher << '\n'
        << (*it)->carpenter << '\n'
        << (*it)->cartographer << '\n'
        << (*it)->cobbler << '\n'
        << (*it)->cook << '\n'
        << (*it)->glassblower << '\n'
        << (*it)->jeweler << '\n'
        << (*it)->leatherworker << '\n'
        << (*it)->mason << '\n'
        << (*it)->painter << '\n'
        << (*it)->potter << '\n'
        << (*it)->smith << '\n'
        << (*it)->tinker << '\n'
        << (*it)->weaver << '\n'
        << (*it)->woodcarver << '\n'
        << "kits" << '\n' //kits & tools
        << (*it)->disguise << '\n'
        << (*it)->forgery << '\n'
        << (*it)->herbalism << '\n'
        << (*it)->navigator << '\n'
        << (*it)->poisoner << '\n'
        << (*it)->thieves << '\n'
        << (*it)->vehicle << '\n'
        << "musicalinstruments" << '\n' //musical instruments
        << (*it)->bagpipes << '\n'
        << (*it)->drum << '\n'
        << (*it)->dulcimer << '\n'
        << (*it)->flute << '\n'
        << (*it)->lute << '\n'
        << (*it)->lyre << '\n'
        << (*it)->horn << '\n'
        << (*it)->pan_flute << '\n'
        << (*it)->shawm << '\n'
        << (*it)->viol << '\n';
  }
  return os;
}

// return 1 for successful load
// return 0 for generic failed load
// return -1 for version mismatch, yours too old
// return -2 for version mismatch, our client to old
int Campaign::retrieveCharacter(ifstream &ins)
{
  bool debugRetrieve = false; // change to true to see the console logs

  static string charClassTempVar;
  static string sbuffer;
  static int charBackgroundProcessor;
  static Generic_Character_Class *v;

  //----------- LOAD IN SAVE VERSION NUMBER --------//
  getline(ins, sbuffer);

  if (debugRetrieve)
  {
    cout << "version of save: " << sbuffer << '\n';
    cout << "version of dmpower: " << saveVersion << '\n';
  }

  if (sbuffer.compare(saveVersion) < 0)
  {
    return -1;
  }
  else if (sbuffer.compare(saveVersion) > 0)
  {
    return -2;
  }
  //else we have a match version, continue.

  //---------- GET WHICH SAVED CHARACTER # ---------//
  getline(ins, sbuffer);

  do
  {
    if (debugRetrieve)
      cout << "Loading in " << sbuffer << '\n';

    //--------- LOAD IN CHARACTER CLASS ----------//
    getline(ins, charClassTempVar);
    if (charClassTempVar == "Cleric")
      v = new Cleric;
    else if (charClassTempVar == "Fighter")
      v = new Fighter;
    else if (charClassTempVar == "Barbarian")
      v = new Barbarian;
    else if (charClassTempVar == "Bard")
      v = new Bard;
    else if (charClassTempVar == "Druid")
      v = new Druid;
    else if (charClassTempVar == "Monk")
      v = new Monk;
    else if (charClassTempVar == "Paladin")
      v = new Paladin;
    else if (charClassTempVar == "Ranger")
      v = new Ranger;
    else if (charClassTempVar == "Rogue")
      v = new Rogue;
    else if (charClassTempVar == "Sorcerer")
      v = new Sorcerer;
    else if (charClassTempVar == "Warlock")
      v = new Warlock;
    else if (charClassTempVar == "Wizard")
      v = new Wizard;
    else
      return false; // character setting failed, don't continue
    v->char_class = charClassTempVar;

    if (debugRetrieve)
      cout << "class set:  " << charClassTempVar << '\n';

    //----- LOAD IN NAME, RACE, ALIGNMENT -------//
    getline(ins, v->char_name);
    getline(ins, v->race);
    getline(ins, v->alignment);

    if (debugRetrieve)
    {
      cout << "name of char: " << v->char_name << '\n';
      cout << "race set: " << v->race << '\n';
    }

    //------ LOAD IN LEVELS SET ----------//
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

    if (debugRetrieve)
      cout << "level up menus set" << '\n';

    //------------- LOAD IN BACKGROUND ------------------//
    ins >> charBackgroundProcessor;
    v->backgroundofpc = static_cast<enum Generic_Character_Class::characterbackground>(charBackgroundProcessor);

    if (debugRetrieve)
    {
      cout << "background set to: " << charBackgroundProcessor << '\n';
    }
    ins.get(); // absorb newline from previous ins >> charBackgroundprocessor
    getline(ins, v->custom_background_name);

    if (debugRetrieve)
    {
      if (v->backgroundofpc == Generic_Character_Class::characterbackground::CUSTOM)
      {
        std::cout << "custom background name: " << v->custom_background_name << '\n';
      }
    }

    //----------- LOAD IN BASIC STAT BLOCK -----------//
    ins >> v->move_speed;
    ins >> v->fly_speed;
    ins >> v->swim_speed;
    ins >> v->climb_speed;
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

    if (debugRetrieve)
      cout << "basic ability stats" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //--------- LOAD IN GENERAL CLASS STUFF ---------//
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

    if (debugRetrieve)
      cout << "general class stuff set" << '\n';

    ins.get();
    getline(ins, sbuffer);

    //--------- LOAD IN CLERIC CLASS ------------//
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
    getline(ins, sbuffer);

    //--------- LOAD IN FIGHTER CLASS -------------//
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
    getline(ins, sbuffer);

    //--------- LOAD IN BARBARIAN CLASS -------------//
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
    getline(ins, sbuffer);

    //---------- LOAD IN BARD CLASS ------------//
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
    getline(ins, sbuffer);

    //----------- LOAD IN DRUID CLASS ----------//
    ins >> v->wild_shape_improvement;
    ins >> v->druid_circle_feature;
    ins >> v->druid_cantrips_known;
    ins >> v->wild_shape;
    ins >> v->druid_circle;
    ins >> v->beast_spells;
    ins >> v->archdruid;
    ins >> v->circle_of_the_moon;
    ins >> v->circle_of_the_land;

    ins.get();
    getline(ins, sbuffer);

    //---------- LOAD IN MONK CLASS -----------//
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
    getline(ins, sbuffer);

    //-------- LOAD IN PALADIN CLASS --------//
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
    getline(ins, sbuffer);

    //-------- LOAD IN RANGER CLASS ----------//
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
    getline(ins, sbuffer);

    //-------- LOAD IN ROGUE CLASS ----------//
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
    getline(ins, sbuffer);

    //-------- LOAD IN SORCERER CLASS ----------//
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
    getline(ins, sbuffer);

    //--------- LOAD IN WARLOCK CLASS --------//
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
    getline(ins, sbuffer);

    //--------- LOAD IN WIZARD CLASS -------//
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

    if (debugRetrieve)
      cout << "precise class stuff set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //------- LOAD IN RANGER LANDTYPES --------//
    ins >> v->artic;
    ins >> v->coast;
    ins >> v->desert;
    ins >> v->forest;
    ins >> v->grassland;
    ins >> v->mountain;
    ins >> v->swamp;
    ins >> v->underdark;

    if (debugRetrieve)
      cout << "landtypes set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //------ LOAD IN FAVORED ENEMY CREATURETYPS ------//
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

    if (debugRetrieve)
      cout << "creaturetype set " << '\n';

    ins.get();
    getline(ins, sbuffer);

    //------- LOAD IN SPELLSLOTS ------//
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

    if (debugRetrieve)
      cout << "spellslots set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //------- LOAD IN SKILLS ------//
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

    if (debugRetrieve)
      cout << "skills set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //------ LOAD IN FEATS ------//
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
    ins >> v->svirfneblin_magic;
    ins >> v->tavern_brawler;
    ins >> v->tough;
    ins >> v->war_caster;
    ins >> v->weapon_master;

    if (debugRetrieve)
      cout << "feats set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //------ LOAD IN LANGUAGES ------//
    ins >> v->abyssal;
    ins >> v->aquan;
    ins >> v->auran;
    ins >> v->celestial;
    ins >> v->common;
    ins >> v->deep_speech;
    ins >> v->draconic;
    ins >> v->druidic;
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

    if (debugRetrieve)
      cout << "languages set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //----- LOAD IN RACE AND OTHER FEATURES -----//
    ins >> v->artificers_lore;
    ins >> v->brave;
    ins >> v->breath_weapon_acid;
    ins >> v->breath_weapon_ltg;
    ins >> v->breath_weapon_fire;
    ins >> v->breath_weapon_poison;
    ins >> v->breath_weapon_cold;
    ins >> v->darkvision;
    ins >> v->devils_tongue;
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
    ins >> v->duergar_resilience;
    ins >> v->duergar_magic;
    ins >> v->elf_weapon_training;
    ins >> v->expert_forgery;
    ins >> v->fey_ancestry;
    ins >> v->firbolg_magic;
    ins >> v->fleet_of_foot;
    ins >> v->halflinglucky;
    ins >> v->halfling_nimbleness;
    ins >> v->hidden_step;
    ins >> v->hellfire;
    ins >> v->hellish_resistance;
    ins >> v->hold_breath;
    ins >> v->infernal_legacy;
    ins >> v->mask_of_the_wild;
    ins >> v->mimicry;
    ins >> v->natural_illusionist;
    ins >> v->naturally_stealthy;
    ins >> v->powerful_build;
    ins >> v->silent_speech;
    ins >> v->speak_with_small_beasts;
    ins >> v->speech_of_beast_and_leaf;
    ins >> v->stonecunning;
    ins >> v->stone_camouflage;
    ins >> v->stones_endurance;
    ins >> v->stout_resilience;
    ins >> v->superior_darkvision;
    ins >> v->trance;
    //aasimar stuff
    ins >> v->healing_hands;
    ins >> v->light_bearer;
    ins >> v->necrotic_shroud;
    ins >> v->radiant_consumption;
    ins >> v->radiant_soul;
    //lizardfolk stuff
    ins >> v->lizardfolk_bite;
    ins >> v->cunning_artisan;
    ins >> v->natural_armor;
    ins >> v->hungry_jaws;
    //tabaxi stuff
    ins >> v->feline_agility;
    ins >> v->cats_claws;
    //triton stuff
    ins >> v->amphibious;
    ins >> v->control_air_and_water;
    ins >> v->emissary_of_the_sea;
    ins >> v->guardian_of_the_depths;
    //warforged stuff
    ins >> v->composite_plating;
    ins >> v->living_construct;
    //changeling stuff
    ins >> v->shapechanger;
    //shifter stuff
    ins >> v->shifting;
    //tortle
    ins >> v->shell;
    ins >> v->retreat_to_shell;
    ins >> v->turtle_snapper;
    ins >> v->razorback;
    ins >> v->razor_fist;
    ins >> v->softshell;
    ins >> v->nomad;
    ins >> v->shell_master;
    //Aarakocra stuff
    ins >> v->talons;
    //genasi stuff
    ins >> v->unending_breath;
    ins >> v->mingle_with_the_wind;
    ins >> v->earth_walk;
    ins >> v->merge_with_stone;
    ins >> v->reach_to_the_blaze;
    ins >> v->call_to_the_wave;

    if (debugRetrieve)
      cout << "character features set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //----- LOAD IN RESISTANCES -----//
    ins >> v->damage_resist_acid;
    ins >> v->damage_resist_ltg;
    ins >> v->damage_resist_fire;
    ins >> v->damage_resist_poison;
    ins >> v->damage_resist_cold;
    ins >> v->damage_resist_necrotic;
    ins >> v->damage_resist_radiant;

    if (debugRetrieve)
      cout << "resistances set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //---- LOAD IN DISADVANTAGES ----//
    ins >> v->sunlight_sensitivity;

    if (debugRetrieve)
      cout << "disadvantages set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //----- LOAD IN ARTISAN TOOLS -----//
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

    if (debugRetrieve)
      cout << "artisan tools and supplies set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //----- LOAD IN KITS ------//
    ins >> v->disguise;
    ins >> v->forgery;
    ins >> v->herbalism;
    ins >> v->navigator;
    ins >> v->poisoner;
    ins >> v->thieves;
    ins >> v->vehicle;

    if (debugRetrieve)
      cout << "kits and tools set" << '\n';
    ins.get();
    getline(ins, sbuffer);

    //----- LOAD IN MUSICAL INSTRUMENTS -----//
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

    if (debugRetrieve)
      cout << "musical instruments set" << '\n';

    character_list.push_back(v);

    ins.get();
  } while (getline(ins, sbuffer));
  return true;
}

void Campaign::showCampaignCharacterList() const
{
  for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
  {
    cout << (*it)->char_name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << '\n';
  }
  cout << '\n';
}
