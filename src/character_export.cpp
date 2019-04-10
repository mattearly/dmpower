#include "characters.h"
#include <fstream>
#include <string>
#include <iomanip>

/**
 * Exports a printer friendly version of your character sheet
 *   This is not a Load/Save file
 * ! in development, not ready
 * @param[in] title  the name of the file, suggest name, race, class, level
 */
void Generic_Character_Class::exportPrint(const std::string &title) const
{

  std::ofstream os("exports/" + title + ".txt");
  if (os.is_open()) {
  os << " " << char_name << "'s Character Sheet:\n";
  os << "-> Class(Level): " << char_class << "(" << level << ")\n";
  os << "-> Alignment: " << alignment << "\n";
  os << "-> Race: " << race << "\n";
  os << "-> Background: " << getBackground() << "\n";
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
    os  << "  <-SaveProficient";
  os << "\n-> Dex: " << std::setw(2) << dexterity << " " << D_D_Ability_Modifier(dexterity);
  if (dexSave)
    os  << "  <-SaveProficient";
  os << "\n-> Con: " << std::setw(2) << constitution << " " << D_D_Ability_Modifier(constitution);
  if (conSave)
    os  << "  <-SaveProficient";
  os << "\n-> Int: " << std::setw(2) << intelligence << " " << D_D_Ability_Modifier(intelligence);
  if (intSave)
    os  << "  <-SaveProficient";
  os << "\n-> Wis: " << std::setw(2) << wisdom << " " << D_D_Ability_Modifier(wisdom);
  if (wisSave)
    os  << "  <-SaveProficient";
  os << "\n-> Cha: " << std::setw(2) << charisma << " " << D_D_Ability_Modifier(charisma);
  if (chaSave)
    os  << "  <-SaveProficient";
  os << std::endl;


  // todo
  // printClassAbilities();
  // printCantrips();
  // printSpellSlots();
  // printSkills();
  // printOtherAbilities();
  // printLangs();
  // printToolsInstruments();
  // printFeats();
  // printResistances();
  // printDisadvantages();

  os << std::endl;
  }

}