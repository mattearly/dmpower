#pragma once

#include "gear.h"

/// This class relies on the artObjects.dat and gems.dat files
class Gear;

class Magic_Items
{

public:
  void treasure_menu();

private:
  std::vector<Gear> full_gear_list;

  void GenerateIndividualTreasureCR_0_4();
  void GenerateIndividualTreasureCR_5_10();
  void GenerateIndividualTreasureCR_11_16();
  void GenerateIndividualTreasureCR_17();

  void GenerateHoardTreasureCR_0_4();
  void GenerateHoardTreasureCR_5_10();
  void GenerateHoardTreasureCR_11_16();
  void GenerateHoardTreasureCR_17();

  Gear TableA(const char &);
  Gear TableB(const char &);
  Gear TableC(const char &);
  Gear TableD(const char &);
  Gear TableE(const char &);
  Gear TableF(const char &);
  Gear TableG(const char &);
  Gear TableH(const char &);
  Gear TableI(const char &);

  std::string GenerateScroll(const int &) const;
  std::string GenerateGemstone(const int &, const int &) const;
  std::string GenerateArt(const int &, const int &) const;

  void MakeSpellbook() const;
  void SingleScroll(const int &) const;

};

