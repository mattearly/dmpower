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

#include "gear.h"

using namespace std;

Gear::Gear() {}

Gear::Gear(const int& q, const string& i){
    quantity = q;
    item_name = i;

}

Gear::Gear(const string& i) {
    quantity = 1;
    item_name = i;
}

void Gear::showItem() const {
    cout << quantity << " " << item_name << endl;
}
