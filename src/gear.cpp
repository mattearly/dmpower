#include "gear.h"

using namespace std;

Gear::Gear() {}

Gear::Gear(const int &q, const string &i)
{
  quantity = q;
  item_name = i;
}

Gear::Gear(const string &i)
{
  quantity = 1;
  item_name = i;
}

void Gear::showItem() const
{
  cout << quantity << " " << item_name << '\n';
}
