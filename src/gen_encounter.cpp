#include "gen_encounter.h"
#include "globalfuncts.h"
#include <iostream>
#include <cmath>

using namespace std;

Encounter::Encounter()
{
  ave_lvl = partysize = 0;
}

std::string Encounter::Gen_Encounter()
{
  set_party_level();

  int seed = (randomNumber(1, 5) - 3);

  //very easy, easy, average, hard, very hard
  if (testing)
    cout << "Seed (random difficulty CR: -2 to +2): " << seed << " (" << getDifficulty(seed) << ")\n";
  if (testing)
    cout << "Party Size additional CR: +" << floor((partysize - 2) / 2) << '\n';
  if (testing)
    cout << "Average Party Level: " + toString(ave_lvl) << "\n\n";

  return ("Give " + getDifficulty(seed) + " encounter of " + "CR: " + toString(ave_lvl + seed + floor((partysize - 2) / 2)));
}

void Encounter::set_party_level()
{
  ave_lvl = 0;
  int tmp(0);
  cout << "Enter the Total Number of party members (max=10): ";
  partysize = getNumber(1, 10);
  for (int i = 0; i < partysize; i++)
  {
    cout << "Enter level of party member #" << i + 1 << "(max=20):";
    tmp += getNumber(1, 20);
  }
  ave_lvl = static_cast<int>(floor(tmp / static_cast<float>(partysize)));
}

std::string Encounter::getDifficulty(const int &val)
{
  switch (val)
  {
  case -2:
    return "Very Easy";
  case -1:
    return "Easy";
  case 0:
    return "Average";
  case 1:
    return "Hard";
  case 2:
    return "Very Hard";
  default:
    return ("error in Encounter::getDifficulty. val = " + val);
  }
}
