#include "campaign.h"
#include "globalfuncts.h"
#include "characters.h"

using namespace std;

extern void save_file();
extern void load_file();

string mainMessage;
bool loadSuccess = false;
string loadedFile = "";
Campaign myGame;

void Campaign::pc_menu()
{
  int choice = 0;
  while (choice != 8)
  {
    simpleClearScreen();
    cout << ">" << mainMessage << "\n\n";
    mainMessage = "";
    cout << GREEN << "---------- CHARACTER MANAGER -----------" << RESET << endl
         << " 1. Build a New Character" << endl
         << " 2. View Characters" << endl
         << " 3. Edit a Character" << endl
         << " 4. Delete a Character" << endl
         << " 5. Delete All Characters" << endl
         << " 6. Save Current Work" << endl
         << " 7. ";
    if (loadSuccess)
    {
      cout << GREEN << loadedFile << RESET << " file loaded - " << RED << "unload?" << RESET << endl;
    }
    else
    {
      cout << "Load a Saved File" << endl;
    }
    cout << " 8. Back to " << CYAN << "MAIN MENU" << RESET << endl;
    cout << GREEN << "----------------------------------------" << RESET << endl;
    choice = getNumber("Choice: ", 1, 8);
    switch (choice)
    {
    case 1:
    {
      simpleClearScreen();
      cout << " Create a New Character! \n\n"
           << "Type Legend: " << YELLOW << "ARCANE " << CYAN << "DIVINE " << RED << "NON CASTER" << RESET << "\n\n"
           << "Character Classes Available:\n\n"
           << CYAN << " 1. Cleric" << CYAN << "      7. Paladin\n\n"
           << RESET
           << RED << " 2. Fighter" << YELLOW << "     8. Sorcerer\n\n"
           << RESET
           << RED << " 3. Rogue" << YELLOW << "       9. Bard\n\n"
           << RESET
           << YELLOW << " 4. Wizard" << RED << "     10. Monk\n\n"
           << RESET
           << RED << " 5. Barbarian" << CYAN << "  11. Ranger\n\n"
           << RESET
           << CYAN << " 6. Druid" << YELLOW << "      12. Warlock\n\n"
           << RESET;
      int select_class = getNumber("Your Class Choice(1-12): ", 1, 12);
      int starting_level = getNumber("\nStarting Character Level(1-20): ", 1, 20);

      simpleClearScreen();

      Generic_Character_Class *new_character_build = nullptr;
      new_character_build = ClassClonner::GetClassClonner().GetNewClass(select_class);
      new_character_build->setInitialClassFeatures();
      makecharacter(new_character_build, starting_level);

      if(new_character_build != nullptr) {
          delete new_character_build;
      }

    }
      break;
    case 2:
    { //VIEW CHARACTER SHEET
      if (character_list.size() < 1)
      {
        cout << "\nNothing to display. Create characters first.\n";
      }
      else
      {
        cout << "Current campaign characters:\n\n";
        showCampaignCharacterList();
        bool found = false;
        string valid_name;
        while (!found)
        {
          cout << "Name of Character to Display Character Sheet of: ";
          getline(cin, valid_name);
          valid_name[0] = toupper(valid_name[0]);
          for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
          {
            if ((*it)->char_name == valid_name)
            {
              found = true;
            }
          }
          if (!found)
            cout << "No character named " << valid_name << ". List of Charcters:\n";
          for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
          {
            cout << (*it)->char_name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << endl;
          }
        }
        for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
        {
          if (valid_name == (*it)->char_name)
            (*it)->character_sheet();
        }
      }
    }
      pressEnterToContinue();
      break;
    case 3:
    { //EDIT/UPDATE CHARACTER
      if (character_list.size() < 1)
      {
        cout << "No characters to Edit. Create characters first.\n\n";

        pressEnterToContinue();
      }
      else
      {
        cout << "Current campaign characters:\n\n";
        showCampaignCharacterList();

        bool found = false;
        string valid_name;
        while (!found)
        {
          cout << "Enter the " << CYAN << "Name" << RESET << " of Character you wish to edit: ";
          getline(cin, valid_name);
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
          showCampaignCharacterList();
        }
        for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
        {
          if (valid_name == (*it)->char_name)
            (*it)->updateCharacter(*this);
        }
      }
    }
      break;
    case 4:
    { //DELETE CHARACTER
      if (character_list.size() < 1)
      {
        cout << "No characters. Nothing to Delete! \n";
      }
      else
      {
        cout << "Current campaign characters:\n\n";
        showCampaignCharacterList();
        string tmp;
        do
        {
          cout << "Enter the name of the PC to Delete(leave blank to exit function): ";
          getline(cin, tmp);
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
    case 5:
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
    case 6:
      save_file();
      break;
    case 7:
      if (!loadSuccess)
      {
        load_file();
      }
      else
      {
        char answer = getYorN("Unload " + loadedFile + "?(y/n):");
        if (answer == 'Y')
        {
          character_list.clear();
          loadedFile = "";
          loadSuccess = false;
        }
      }
      break;
    default:
      cout << "Option doesn't exist.\n";
    }
  }
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
  bool goodname = false;

  simpleClearScreen();
  while (!goodname)
  {
    new_character->setName();
    goodname = checkname(new_character->char_name);
  }

  new_character->setAllStats();
  new_character->setRace(*new_character);
  new_character->setAlignment();
  new_character->setBackground();
  new_character->setClassDetails(starting_level);
  new_character->setProficiencyBonus();

  character_list.push_back(new_character);
  new_character->initialSkillsSet = true;

  char ans = getYorN("Display Character Sheet now[y/n]?");

  if (ans == 'Y')
  {
    character_list.back()->character_sheet();
    pressEnterToContinue();
  }
}

ofstream &Campaign::dumpCharacter(ofstream &os) const
{
  int charactercount = 0;
  for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
  {
    charactercount++;
    os
        << "saved character: " << charactercount << endl
           //basics
        << (*it)->char_class << endl
        << (*it)->char_name << endl
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
        << (*it)->cleric_attr.destroy_undead << endl //cleric
        << (*it)->cleric_attr.channel_divinity << endl
        << (*it)->cleric_attr.divine_domain_feature << endl
        << (*it)->cleric_attr.divine_intervention << endl
        << (*it)->cleric_attr.cleric_cantrips_known << endl
        << (*it)->cleric_attr.divine_domain << endl
        << (*it)->cleric_attr.arcana_d << endl
        << (*it)->cleric_attr.death_d << endl
        << (*it)->cleric_attr.knowledge_d << endl
        << (*it)->cleric_attr.life_d << endl
        << (*it)->cleric_attr.light_d << endl
        << (*it)->cleric_attr.nature_d << endl
        << (*it)->cleric_attr.tempest_d << endl
        << (*it)->cleric_attr.trickery_d << endl
        << (*it)->cleric_attr.war_d << endl
        << "fighter" << endl
        << (*it)->fighter_attr.action_surge << endl //fighter
        << (*it)->fighter_attr.martial_archtype_feature << endl
        << (*it)->fighter_attr.indomitable << endl
        << (*it)->fighter_attr.eldritch_spells_known << endl
        << (*it)->fighter_attr.second_wind << endl
        << (*it)->fighter_attr.martial_archtype << endl
        << (*it)->fighter_attr.archery << endl
        << (*it)->fighter_attr.two_weapon_fighting << endl
        << (*it)->fighter_attr.champion << endl
        << (*it)->fighter_attr.battle_master << endl
        << (*it)->fighter_attr.eldritch_knight << endl
        << (*it)->fighter_attr.purple_dragon_knight << endl
        << "barbarian" << endl
        << (*it)->barbarian_attr.rages << endl //barbarian
        << (*it)->barbarian_attr.rage_damage << endl
        << (*it)->barbarian_attr.path_feature << endl
        << (*it)->barbarian_attr.brutal_critical << endl
        << (*it)->barbarian_attr.reckless_attack << endl
        << (*it)->barbarian_attr.danger_sense << endl
        << (*it)->barbarian_attr.primal_path << endl
        << (*it)->barbarian_attr.fast_movement << endl
        << (*it)->barbarian_attr.feral_instinct << endl
        << (*it)->barbarian_attr.relentless_rage << endl
        << (*it)->barbarian_attr.persistant_rage << endl
        << (*it)->barbarian_attr.indomitable_might << endl
        << (*it)->barbarian_attr.primal_champion << endl
        << (*it)->barbarian_attr.path_of_the_battlerager << endl
        << (*it)->barbarian_attr.path_of_the_berseker << endl
        << (*it)->barbarian_attr.path_of_the_totem_warrior << endl
        << (*it)->barbarian_attr.bear_totem << endl
        << (*it)->barbarian_attr.eagle_totem << endl
        << (*it)->barbarian_attr.wolf_totem << endl
        << "bard" << endl
        << (*it)->bard_attr.bardic_inspiration << endl //bard
        << (*it)->bard_attr.song_of_rest << endl
        << (*it)->bard_attr.bard_college_feature << endl
        << (*it)->bard_attr.magical_secrets << endl
        << (*it)->bard_attr.bard_spells_known << endl
        << (*it)->bard_attr.bard_cantrips_known << endl
        << (*it)->bard_attr.jack_of_all_trades << endl
        << (*it)->bard_attr.bard_college << endl
        << (*it)->bard_attr.font_of_inspiration << endl
        << (*it)->bard_attr.countercharm << endl
        << (*it)->bard_attr.superior_inspiration << endl
        << (*it)->bard_attr.college_of_lore << endl
        << (*it)->bard_attr.college_of_valor << endl
        << (*it)->bard_attr.additional_magical_secrets << endl
        << "druid" << endl
        << (*it)->druid_attr.wild_shape_improvement << endl //druid
        << (*it)->druid_attr.druid_circle_feature << endl
        << (*it)->druid_attr.druid_cantrips_known << endl
        << (*it)->druidic << endl
        << (*it)->druid_attr.wild_shape << endl
        << (*it)->druid_attr.druid_circle << endl
        << (*it)->druid_attr.beast_spells << endl
        << (*it)->druid_attr.archdruid << endl
        << (*it)->druid_attr.circle_of_the_moon << endl
        << (*it)->druid_attr.circle_of_the_land << endl
        << "monk" << endl
        << (*it)->monk_attr.monastic_tradition_feature << endl //monk
        << (*it)->monk_attr.ki << endl
        << (*it)->monk_attr.unarmored_movement << endl
        << (*it)->monk_attr.martial_arts << endl
        << (*it)->monk_attr.monastic_tradition << endl
        << (*it)->monk_attr.deflect_missles << endl
        << (*it)->monk_attr.slow_fall << endl
        << (*it)->monk_attr.stunning_strike << endl
        << (*it)->monk_attr.ki_empowered_strikes << endl
        << (*it)->monk_attr.stillness_of_mind << endl
        << (*it)->monk_attr.purity_of_body << endl
        << (*it)->monk_attr.tongue_of_the_sun_and_moon << endl
        << (*it)->monk_attr.diamond_soul << endl
        << (*it)->monk_attr.empty_body << endl
        << (*it)->monk_attr.perfect_self << endl
        << (*it)->monk_attr.way_of_the_open_hand << endl
        << (*it)->monk_attr.way_of_the_four_elements << endl
        << (*it)->monk_attr.way_of_the_long_death << endl
        << (*it)->monk_attr.way_of_the_shadow << endl
        << (*it)->monk_attr.way_of_the_sun_soul << endl
        << (*it)->monk_attr.unarmored_movement_improvement << endl
        << "paladin" << endl
        << (*it)->paladin_attr.sacred_oath_feature << endl //paladin
        << (*it)->paladin_attr.divine_smite << endl
        << (*it)->paladin_attr.divine_sense << endl
        << (*it)->paladin_attr.lay_on_hands << endl
        << (*it)->paladin_attr.divine_health << endl
        << (*it)->paladin_attr.sacred_oath << endl
        << (*it)->paladin_attr.aura_of_protection << endl
        << (*it)->paladin_attr.aura_of_courage << endl
        << (*it)->paladin_attr.cleansing_touch << endl
        << (*it)->paladin_attr.aura_improvments << endl
        << (*it)->paladin_attr.oath_of_ancients << endl
        << (*it)->paladin_attr.oath_of_devotion << endl
        << (*it)->paladin_attr.oath_of_the_crown << endl
        << (*it)->paladin_attr.oath_of_vengeance << endl
        << (*it)->paladin_attr.oathbreaker << endl
        << "ranger" << endl
        << (*it)->ranger_attr.favored_enemy << endl //ranger
        << (*it)->ranger_attr.favored_enemy_languages << endl
        << (*it)->ranger_attr.natural_explorer << endl
        << (*it)->ranger_attr.ranger_archetype_feature << endl
        << (*it)->ranger_attr.ranger_spells_known << endl
        << (*it)->ranger_attr.ranger_archetype << endl
        << (*it)->ranger_attr.primeval_awareness << endl
        << (*it)->ranger_attr.lands_stride << endl
        << (*it)->ranger_attr.hide_in_plain_sight << endl
        << (*it)->ranger_attr.vanish << endl
        << (*it)->ranger_attr.feral_senses << endl
        << (*it)->ranger_attr.foe_slayer << endl
        << (*it)->ranger_attr.hunter << endl
        << (*it)->ranger_attr.beast_master << endl
        << "rogue" << endl
        << (*it)->rogue_attr.roguish_archetype_feature << endl //rogue
        << (*it)->rogue_attr.arcane_t_spells_known << endl
        << (*it)->rogue_attr.sneak_attack << endl
        << (*it)->rogue_attr.thieves_cant << endl
        << (*it)->rogue_attr.cunning_action << endl
        << (*it)->rogue_attr.roguish_archetype << endl
        << (*it)->rogue_attr.uncanny_dodge << endl
        << (*it)->rogue_attr.reliable_talent << endl
        << (*it)->rogue_attr.blindsense << endl
        << (*it)->rogue_attr.slippery_mind << endl
        << (*it)->rogue_attr.elusive << endl
        << (*it)->rogue_attr.stroke_of_luck << endl
        << (*it)->rogue_attr.thief << endl
        << (*it)->rogue_attr.assassin << endl
        << (*it)->rogue_attr.arcane_trickster << endl
        << (*it)->rogue_attr.mastermind << endl
        << (*it)->rogue_attr.swashbuckler << endl
        << "sorcerer" << endl
        << (*it)->sorcerer_attr.sorcerous_origin_feature << endl //sorcerer
        << (*it)->sorcerer_attr.metamagic << endl
        << (*it)->sorcerer_attr.sorcery_points << endl
        << (*it)->sorcerer_attr.sorcerer_spells_known << endl
        << (*it)->sorcerer_attr.sorcerer_cantrips_known << endl
        << (*it)->sorcerer_attr.sorcerous_origin << endl
        << (*it)->sorcerer_attr.font_of_magic << endl
        << (*it)->sorcerer_attr.sorcerous_restoration << endl
        << (*it)->sorcerer_attr.draconic_bloodline << endl
        << (*it)->sorcerer_attr.wild_magic << endl
        << (*it)->sorcerer_attr.storm_sorcery << endl
        << "warlock" << endl
        << (*it)->warlock_attr.warlock_slot_level << endl //warlock
        << (*it)->warlock_attr.eldritch_invocations_known << endl
        << (*it)->warlock_attr.warlock_spells_known << endl
        << (*it)->warlock_attr.warlock_spell_slots << endl
        << (*it)->warlock_attr.warlock_cantrips_known << endl
        << (*it)->warlock_attr.otherworldly_patron_feature << endl
        << (*it)->warlock_attr.mystic_arcanum << endl
        << (*it)->warlock_attr.otherworldly_patron << endl
        << (*it)->warlock_attr.pact_magic << endl
        << (*it)->warlock_attr.pact_boon << endl
        << (*it)->warlock_attr.eldritch_master << endl
        << (*it)->warlock_attr.archfey << endl
        << (*it)->warlock_attr.fiend << endl
        << (*it)->warlock_attr.great_old_one << endl
        << (*it)->warlock_attr.the_undying << endl
        << "wizard" << endl
        << (*it)->wizard_attr.arcane_tradition_feature << endl //wizard
        << (*it)->wizard_attr.wizard_cantrips_known << endl
        << (*it)->wizard_attr.arcane_recovery << endl
        << (*it)->wizard_attr.arcane_tradition << endl
        << (*it)->wizard_attr.spell_mastery << endl
        << (*it)->wizard_attr.signature_spell << endl
        << (*it)->wizard_attr.abjuration << endl
        << (*it)->wizard_attr.conjuration << endl
        << (*it)->wizard_attr.divination << endl
        << (*it)->wizard_attr.enchantment << endl
        << (*it)->wizard_attr.evocation << endl
        << (*it)->wizard_attr.illusion << endl
        << (*it)->wizard_attr.necromancy << endl
        << (*it)->wizard_attr.transmutation << endl
        << (*it)->wizard_attr.bladesinging << endl
        << "landtypes" << endl //landtypes
        << (*it)->artic << endl
        << (*it)->coast << endl
        << (*it)->desert << endl
        << (*it)->forest << endl
        << (*it)->grassland << endl
        << (*it)->mountain << endl
        << (*it)->swamp << endl
        << (*it)->underdark << endl
        << "creaturetype" << endl //creaturetype
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
        << "skills" << endl //skills
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
        << "feats" << endl //feats
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
        << "languages" << endl //languages
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
        << "features" << endl //features
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
        << "resistances" << endl //resistances
        << (*it)->damage_resist_acid << endl
        << (*it)->damage_resist_ltg << endl
        << (*it)->damage_resist_fire << endl
        << (*it)->damage_resist_poison << endl
        << (*it)->damage_resist_cold << endl
        << "disadvantages" << endl //disadvantages
        << (*it)->sunlight_sensitivity << endl
        << "tools" << endl //artisan tools & supplies
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
        << "kits" << endl //kits & tools
        << (*it)->disguise << endl
        << (*it)->forgery << endl
        << (*it)->herbalism << endl
        << (*it)->navigator << endl
        << (*it)->poisoner << endl
        << (*it)->thieves << endl
        << (*it)->vehicle << endl
        << "musicalinstruments" << endl //musical instruments
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

bool Campaign::retrieveCharacter(ifstream &ins)
{
  string tmp;
  int processor;
  Generic_Character_Class *v;
  while (!ins.eof())
  {
    ins.ignore(numeric_limits<streamsize>::max(), '\n');
    int len = ins.tellg(); //get current position
    getline(ins, tmp);
    if (tmp == "Cleric")
      v = new Cleric;
    else if (tmp == "Fighter")
      v = new Fighter;
    else if (tmp == "Barbarian")
      v = new Barbarian;
    else if (tmp == "Bard")
      v = new Bard;
    else if (tmp == "Druid")
      v = new Druid;
    else if (tmp == "Monk")
      v = new Monk;
    else if (tmp == "Paladin")
      v = new Paladin;
    else if (tmp == "Ranger")
      v = new Ranger;
    else if (tmp == "Rogue")
      v = new Rogue;
    else if (tmp == "Sorcerer")
      v = new Sorcerer;
    else if (tmp == "Warlock")
      v = new Warlock;
    else if (tmp == "Wizard")
      v = new Wizard;
    else
      return false;
    ins.seekg(len, ios_base::beg); //return to position

    getline(ins, v->char_class);
    getline(ins, v->char_name);
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
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //  class stuff general
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
    ins >> v->cleric_attr.destroy_undead;
    ins >> v->cleric_attr.channel_divinity;
    ins >> v->cleric_attr.divine_domain_feature;
    ins >> v->cleric_attr.divine_intervention;
    ins >> v->cleric_attr.cleric_cantrips_known;
    ins >> v->cleric_attr.divine_domain;
    ins >> v->cleric_attr.arcana_d;
    ins >> v->cleric_attr.death_d;
    ins >> v->cleric_attr.knowledge_d;
    ins >> v->cleric_attr.life_d;
    ins >> v->cleric_attr.light_d;
    ins >> v->cleric_attr.nature_d;
    ins >> v->cleric_attr.tempest_d;
    ins >> v->cleric_attr.trickery_d;
    ins >> v->cleric_attr.war_d;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //fighter
    ins >> v->fighter_attr.action_surge;
    ins >> v->fighter_attr.martial_archtype_feature;
    ins >> v->fighter_attr.indomitable;
    ins >> v->fighter_attr.eldritch_spells_known;
    ins >> v->fighter_attr.second_wind;
    ins >> v->fighter_attr.martial_archtype;
    ins >> v->fighter_attr.archery;
    ins >> v->fighter_attr.two_weapon_fighting;
    ins >> v->fighter_attr.champion;
    ins >> v->fighter_attr.battle_master;
    ins >> v->fighter_attr.eldritch_knight;
    ins >> v->fighter_attr.purple_dragon_knight;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //barbarian
    ins >> v->barbarian_attr.rages;
    ins >> v->barbarian_attr.rage_damage;
    ins >> v->barbarian_attr.path_feature;
    ins >> v->barbarian_attr.brutal_critical;
    ins >> v->barbarian_attr.reckless_attack;
    ins >> v->barbarian_attr.danger_sense;
    ins >> v->barbarian_attr.primal_path;
    ins >> v->barbarian_attr.fast_movement;
    ins >> v->barbarian_attr.feral_instinct;
    ins >> v->barbarian_attr.relentless_rage;
    ins >> v->barbarian_attr.persistant_rage;
    ins >> v->barbarian_attr.indomitable_might;
    ins >> v->barbarian_attr.primal_champion;
    ins >> v->barbarian_attr.path_of_the_battlerager;
    ins >> v->barbarian_attr.path_of_the_berseker;
    ins >> v->barbarian_attr.path_of_the_totem_warrior;
    ins >> v->barbarian_attr.bear_totem;
    ins >> v->barbarian_attr.eagle_totem;
    ins >> v->barbarian_attr.wolf_totem;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //bard
    ins >> v->bard_attr.bardic_inspiration;
    ins >> v->bard_attr.song_of_rest;
    ins >> v->bard_attr.bard_college_feature;
    ins >> v->bard_attr.magical_secrets;
    ins >> v->bard_attr.bard_spells_known;
    ins >> v->bard_attr.bard_cantrips_known;
    ins >> v->bard_attr.jack_of_all_trades;
    ins >> v->bard_attr.bard_college;
    ins >> v->bard_attr.font_of_inspiration;
    ins >> v->bard_attr.countercharm;
    ins >> v->bard_attr.superior_inspiration;
    ins >> v->bard_attr.college_of_lore;
    ins >> v->bard_attr.college_of_valor;
    ins >> v->bard_attr.additional_magical_secrets;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //druid
    ins >> v->druid_attr.wild_shape_improvement;
    ins >> v->druid_attr.druid_circle_feature;
    ins >> v->druid_attr.druid_cantrips_known;
    ins >> v->druidic;
    ins >> v->druid_attr.wild_shape;
    ins >> v->druid_attr.druid_circle;
    ins >> v->druid_attr.beast_spells;
    ins >> v->druid_attr.archdruid;
    ins >> v->druid_attr.circle_of_the_moon;
    ins >> v->druid_attr.circle_of_the_land;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //monk
    ins >> v->monk_attr.monastic_tradition_feature;
    ins >> v->monk_attr.ki;
    ins >> v->monk_attr.unarmored_movement;
    ins >> v->monk_attr.martial_arts;
    ins >> v->monk_attr.monastic_tradition;
    ins >> v->monk_attr.deflect_missles;
    ins >> v->monk_attr.slow_fall;
    ins >> v->monk_attr.stunning_strike;
    ins >> v->monk_attr.ki_empowered_strikes;
    ins >> v->monk_attr.stillness_of_mind;
    ins >> v->monk_attr.purity_of_body;
    ins >> v->monk_attr.tongue_of_the_sun_and_moon;
    ins >> v->monk_attr.diamond_soul;
    ins >> v->monk_attr.empty_body;
    ins >> v->monk_attr.perfect_self;
    ins >> v->monk_attr.way_of_the_open_hand;
    ins >> v->monk_attr.way_of_the_four_elements;
    ins >> v->monk_attr.way_of_the_long_death;
    ins >> v->monk_attr.way_of_the_shadow;
    ins >> v->monk_attr.way_of_the_sun_soul;
    ins >> v->monk_attr.unarmored_movement_improvement;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //paladin
    ins >> v->paladin_attr.sacred_oath_feature;
    ins >> v->paladin_attr.divine_smite;
    ins >> v->paladin_attr.divine_sense;
    ins >> v->paladin_attr.lay_on_hands;
    ins >> v->paladin_attr.divine_health;
    ins >> v->paladin_attr.sacred_oath;
    ins >> v->paladin_attr.aura_of_protection;
    ins >> v->paladin_attr.aura_of_courage;
    ins >> v->paladin_attr.cleansing_touch;
    ins >> v->paladin_attr.aura_improvments;
    ins >> v->paladin_attr.oath_of_ancients;
    ins >> v->paladin_attr.oath_of_devotion;
    ins >> v->paladin_attr.oath_of_the_crown;
    ins >> v->paladin_attr.oath_of_vengeance;
    ins >> v->paladin_attr.oathbreaker;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //ranger
    ins >> v->ranger_attr.favored_enemy;
    ins >> v->ranger_attr.favored_enemy_languages;
    ins >> v->ranger_attr.natural_explorer;
    ins >> v->ranger_attr.ranger_archetype_feature;
    ins >> v->ranger_attr.ranger_spells_known;
    ins >> v->ranger_attr.ranger_archetype;
    ins >> v->ranger_attr.primeval_awareness;
    ins >> v->ranger_attr.lands_stride;
    ins >> v->ranger_attr.hide_in_plain_sight;
    ins >> v->ranger_attr.vanish;
    ins >> v->ranger_attr.feral_senses;
    ins >> v->ranger_attr.foe_slayer;
    ins >> v->ranger_attr.hunter;
    ins >> v->ranger_attr.beast_master;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //rogue
    ins >> v->rogue_attr.roguish_archetype_feature;
    ins >> v->rogue_attr.arcane_t_spells_known;
    ins >> v->rogue_attr.sneak_attack;
    ins >> v->rogue_attr.thieves_cant;
    ins >> v->rogue_attr.cunning_action;
    ins >> v->rogue_attr.roguish_archetype;
    ins >> v->rogue_attr.uncanny_dodge;
    ins >> v->rogue_attr.reliable_talent;
    ins >> v->rogue_attr.blindsense;
    ins >> v->rogue_attr.slippery_mind;
    ins >> v->rogue_attr.elusive;
    ins >> v->rogue_attr.stroke_of_luck;
    ins >> v->rogue_attr.thief;
    ins >> v->rogue_attr.assassin;
    ins >> v->rogue_attr.arcane_trickster;
    ins >> v->rogue_attr.mastermind;
    ins >> v->rogue_attr.swashbuckler;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //sorcerer
    ins >> v->sorcerer_attr.sorcerous_origin_feature;
    ins >> v->sorcerer_attr.metamagic;
    ins >> v->sorcerer_attr.sorcery_points;
    ins >> v->sorcerer_attr.sorcerer_spells_known;
    ins >> v->sorcerer_attr.sorcerer_cantrips_known;
    ins >> v->sorcerer_attr.sorcerous_origin;
    ins >> v->sorcerer_attr.font_of_magic;
    ins >> v->sorcerer_attr.sorcerous_restoration;
    ins >> v->sorcerer_attr.draconic_bloodline;
    ins >> v->sorcerer_attr.wild_magic;
    ins >> v->sorcerer_attr.storm_sorcery;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //warlock
    ins >> v->warlock_attr.warlock_slot_level;
    ins >> v->warlock_attr.eldritch_invocations_known;
    ins >> v->warlock_attr.warlock_spells_known;
    ins >> v->warlock_attr.warlock_spell_slots;
    ins >> v->warlock_attr.warlock_cantrips_known;
    ins >> v->warlock_attr.otherworldly_patron_feature;
    ins >> v->warlock_attr.mystic_arcanum;
    ins >> v->warlock_attr.otherworldly_patron;
    ins >> v->warlock_attr.pact_magic;
    ins >> v->warlock_attr.pact_boon;
    ins >> v->warlock_attr.eldritch_master;
    ins >> v->warlock_attr.archfey;
    ins >> v->warlock_attr.fiend;
    ins >> v->warlock_attr.great_old_one;
    ins >> v->warlock_attr.the_undying;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //wizard
    ins >> v->wizard_attr.arcane_tradition_feature;
    ins >> v->wizard_attr.wizard_cantrips_known;
    ins >> v->wizard_attr.arcane_recovery;
    ins >> v->wizard_attr.arcane_tradition;
    ins >> v->wizard_attr.spell_mastery;
    ins >> v->wizard_attr.signature_spell;
    ins >> v->wizard_attr.abjuration;
    ins >> v->wizard_attr.conjuration;
    ins >> v->wizard_attr.divination;
    ins >> v->wizard_attr.enchantment;
    ins >> v->wizard_attr.evocation;
    ins >> v->wizard_attr.illusion;
    ins >> v->wizard_attr.necromancy;
    ins >> v->wizard_attr.transmutation;
    ins >> v->wizard_attr.bladesinging;
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
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //creaturetype
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
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //spellslots
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
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //feats
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
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //disadvantages
    ins >> v->sunlight_sensitivity;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //artisan tools & supplies
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
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //kits & tools
    ins >> v->disguise;
    ins >> v->forgery;
    ins >> v->herbalism;
    ins >> v->navigator;
    ins >> v->poisoner;
    ins >> v->thieves;
    ins >> v->vehicle;
    ins.get();
    ins.ignore(numeric_limits<streamsize>::max(), '\n'); //musical instruments
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
    if (ins.peek() == '\n')
      ins.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return true;
}

void Campaign::showCampaignCharacterList()
{
  for (list<Generic_Character_Class *>::const_iterator it = this->character_list.begin(); it != this->character_list.end(); ++it)
  {
    cout << (*it)->char_name << " - " << (*it)->race << " " << (*it)->char_class << "(" << (*it)->level << ")" << endl;
  }
  cout << endl;
}
