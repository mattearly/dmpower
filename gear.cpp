//
//  gear.cpp
//  DM-Power
//
//  Created by Matthew Early on 8/03/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#include "gear.h"

using namespace std;

Gear::Gear() {
	quantity = 0;
	item_name = "";

}
Gear::Gear(const int& q, const string& i){
	quantity = q;
	item_name = i;
	
}

void Gear::showItem(){
	cout << quantity << " " << item_name << endl;
}
