#pragma once

#include "globalfuncts.h"

class Gear
{
public:
  Gear();
  Gear(const int &, const std::string &);
  Gear(const std::string &);
  void showItem() const;

protected:
  int quantity = 0;
  std::string item_name = "voidspace - no item";

private:
};
// protected:
// 	std::string item_name;
// 	int item_AC, item_hardness, item_hitpoints;
// }

// Class Coins : Gear {

// 	Coins(cp, sp, ep, gp, pp, item_AC, item_hardness, item_hitpoints) { 0,0,0,0,0,10,5,2 }
// 	int cp, sp, ep, gp, pp;

// }

// Class Gemstones : Gear {
// 	Gemstones();
// 	std::vector<std::pair<std::string, int> gems;
// 	Gemstones operator << (const Gemstones& g);
// }

// Class ArtObjects : Gear {

// }

// Class MagicItems : Gear {

// }

