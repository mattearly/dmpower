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


#include "races.h"

using namespace std;

//mutators
void Dragonborn::setRaceDetails(Generic_Character_Class &v) {
    v.strength += 2;
    v.charisma++;
    v.move_speed = 30;
    v.draconic = 1;
    v.common = 1;
    cout << "->Dragonborn defaults & bonuses applied:\n +2 STR, +1 CHA, 30ft Move, & Languages(Common, Draconic)\n\n";
    cout << "Pick a type of Draconic Ancestry:\n\n"
         << " 1. Black    6. Gold"
         << "\n 2. Blue     7. Green"
         << "\n 3. Brass    8. Red"
         << "\n 4. Bronze   9. Silver"
         << "\n 5. Copper  10. White\n\n";
    int ss = getNumber("Enter a number to choose(1-10): ", 1, 10);
    if (ss == 1) {
        v.draconic_ancestry_black = true;
        v.breath_weapon_acid = true;
        v.damage_resist_acid = true;
        cout << "->Black Dragon Ancestry. Acid Breath and DR Acid gained!\n";
    } else if (ss == 2) {
        v.draconic_ancestry_blue = true;
        v.breath_weapon_ltg = true;
        v.damage_resist_ltg = true;
        cout << "->Blue Dragon Ancestry. Lightning Breath and DR Lighting gained!\n";
    } else if (ss == 3) {
        v.draconic_ancestry_brass = true;
        v.breath_weapon_fire = true;
        v.damage_resist_fire = true;
        cout << "->Brass Dragon Ancestry. Fire Breath and DR Fire gained!\n";
    } else if (ss == 4) {
        v.draconic_ancestry_bronze = true;
        v.breath_weapon_ltg = true;
        v.damage_resist_ltg = true;
        cout << "->Bronze Dragon Ancestry. Lightning Breath and DR Lightning gained!\n";
    } else if (ss == 5) {
        v.draconic_ancestry_copper = true;
        v.breath_weapon_acid = true;
        v.damage_resist_acid = true;
	cout << "->Copper Dragon Ancestry. Acid Breath and DR Acid gained!\n";
    } else if (ss == 6){
        v.draconic_ancestry_gold = true;
        v.breath_weapon_fire = true;
        v.damage_resist_fire = true;
        cout << "->Gold Dragon Ancestry. Fire Breath and DR Fire gained!\n";
    } else if (ss == 7) {
        v.draconic_ancestry_green = true;
        v.breath_weapon_poison = true;
        v.damage_resist_poison = true;
        cout << "->Green Dragon Ancestry. Poison Breath and DR Poison gained!\n";
    } else if (ss == 8) {
        v.draconic_ancestry_red = true;
        v.breath_weapon_fire = true;
        v.damage_resist_fire = true;
        cout << "->Red Dragon Ancestry. Fire Breath and DR Fire gained!\n";
    } else if (ss == 9) {
        v.draconic_ancestry_silver = true;
        v.breath_weapon_cold = true;
        v.damage_resist_cold = true;
        cout << "->Silver Dragon Ancestry. Cold Breath and DR Cold gained!\n";
    } else if (ss == 10) {
        v.draconic_ancestry_white = true;
        v.breath_weapon_cold = true;
        v.damage_resist_cold = true;
        cout << "->White Dragon Ancestry. Cold Breath and DR Cold gained!\n";
    }
    pressEnterToContinue();

}
void Dwarf::setRaceDetails(Generic_Character_Class &v) {
    v.constitution += 2;
    v.move_speed = 25;
    v.darkvision = true;
    v.dwarven_resilience = true;
    v.damage_resist_poison = true;
    v.dwarven_combat_training = true;
    v.stonecunning = true;
    v.dwarvish = true;
    v.common = true;
    cout << "->Dwarf defaults & bonuses applied:\n"
         << "+2 CON, 25ft Move, Darkvision 60ft, Dwarven Resilience, Stonecunning, Dwarven Weapon Training, Langs(Common, Dwarven)\n\n";
    cout << "Choice of Dwarven Tools:\n\n"
         << " 1. Smith's Tools\n 2. Brewer's Supplies\n 3. Mason's Tools.\n\n";
    int ss = getNumber("Tool Choice: ", 1, 3);
    if (ss == 1) { v.smith = true; cout << "Smith's Tools learned!\n"; }
    if (ss == 2) { v.brewer = true; cout << "Brewer's Supplies learned!\n"; }
    if (ss == 3) { v.mason = true; cout << "Mason's Tools learned!\n"; }
    cout << "\nWhat Kind of Dwarf?\n\n"
         << " 1. Hill Dwarf\n 2. Mountain Dwarf.\n\n";
    subr = static_cast<enum dwarftype>(getNumber("Dwarf type(1-2): ", 1, 2));
    switch (subr) {
    case HILL:
        v.wisdom += 1;
        v.dwarven_toughness = true;
        cout << "Hill Dwarf defaults & bonuses: +1 WIS, Dwarven Toughness(+1 HP/level)\n";
        break;
    case MOUNTAIN:
        v.strength += 2;
        v.dwarven_armor_training = true;
        cout << "Mountain Dwarf defaults & bonuses: +2 STR, Dwarven Armor Training(Proficient in Medium and Light Armor)\n";
        break;
    case NA:
    default:
        break;
    }
    pressEnterToContinue();
}
void Elf::setRaceDetails(Generic_Character_Class &v) {
    v.dexterity += 2;
    v.move_speed = 30;
    v.darkvision = true;
    v.perception = true;   //keen senses
    v.trance = true;
    v.fey_ancestry = true;
    v.common = true;
    v.elvish = true;
    cout << "->Elf defaults & bonuses applied:\n"
         << " +2 DEX, 30ft Move, Darkvision, Perception, Trance, Fey Ancestry, Languages(Common, Elven)\n\n";
    cout << "Elven Subrace:\n\n 1. High\n 2. Wood\n 3. Drow\n\n";
    subr = static_cast<enum elftype>(getNumber("Elf type choice(1-3): ", 1, 3));
    switch (subr) {
    case HIGH:
        v.intelligence += 1;
        v.elf_weapon_training = true;
        v.wizard_cantrips_known++;
        v.setLanguage("High Elf bonus language.\n\n");
        cout << "->High Elf defaults & bonuses applied:\n"
             << " +1 INT, Elven Weapon Training, Wizard Cantrip, Extra language\n";
        break;
    case WOOD:
        v.wisdom += 1;
        v.elf_weapon_training = true;
        v.fleet_of_foot = true;
        v.move_speed += 5;
        v.mask_of_the_wild = true;
        cout << "->Wood Elf defaults & bonuses:\n"
             << "+1 WIS, Elven Weapon Training, +5ft Move, Mask of the Wild.\n";
        break;
    case DROW:
        v.charisma += 1;
        v.darkvision = false;
        v.superior_darkvision = true;
        v.drow_magic = true;
        v.drow_weapon_training = true;
        v.sunlight_sensitivity = true;
        cout << "->Drow Elf defaults & bonuses applied:\n"
             << " +1 CHA, Darkvision 120ft, Drow Magic, Drow Weapon Training.\n";
        break;
    case NA:
    default:
        break;
    }
    cout << endl;
    pressEnterToContinue();
}
void Gnome::setRaceDetails(Generic_Character_Class &v) {
    v.intelligence += 2;
    v.move_speed = 25;
    v.darkvision = true;
    v.common = true;
    v.gnomish = true;
    cout << "->Gnome bonuses and defaults applied:\n"
         << " +2 INT, Darkvision, Languages(Common, Gnome)\n"
         << "Now, which kind of Gnome?\n\n 1. Forest\n 2. Rock\n\n";
    subr = static_cast<enum gnometype>(getNumber("Gnome type(1-2): ", 1, 2));
    switch (subr) {
    case FOREST:
        v.dexterity += 1;
        v.natural_illusionist = true;
        v.speak_with_small_beasts = true;
        cout << "->Forest Gnome bonuses:\n +1 DEX, Natural Illusionist, Speak with Small Beasts\n";
        break;
    case ROCK:
        v.constitution += 1;
        v.tinker = true;
        v.artificers_lore = true;
        cout << "->Rock Gnome bonuses:\n +1 CON, Tinker, Artificers Lore\n";
        break;
    case NA:
        break;
    default:
        break;
    }
    pressEnterToContinue();
}
void Halfelf::setRaceDetails(Generic_Character_Class &v) {
    v.charisma += 2;
    v.move_speed = 30;
    v.darkvision = true;
    cout << "->Halfelf defaults & bonuses applied:\n"
         << " +2 CHA & +1 to two other stats, 30ft Move, Darkvision 60ft\n\n";
    int ss = 0;
    for (int i = 0; i < 2; i++) {
        int tmp = ss;
        if (ss == 0) cout << "Choose a stat to give +1: \n\n";
        if (ss != 0) cout << "Choose another stat to give +1: \n\n";
        if (ss == 0) {
            cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. +1 Constitution"
                 << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
        }
        if (ss == 1) {
            cout << " 1. +1 (can't choose)\n 2. +1 Dexterity\n 3. +1 Constitution"
                 << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
        }
        if (ss == 2) {
            cout << " 1. +1 Strength\n 2. (can't choose)\n 3. +1 Constitution"
                 << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
        }
        if (ss == 3) {
            cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. (can't choose)"
                 << "\n 4. +1 Intelligence\n 5. +1 Wisdom\n\n";
        }
        if (ss == 4) {
            cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. +1 Constitution"
                 << "\n 4. (can't choose)\n 5. +1 Wisdom\n\n";
        }
        if (ss == 5) {
            cout << " 1. +1 Strength\n 2. +1 Dexterity\n 3. +1 Constitution"
                 << "\n 4. +1 Intelligence\n 5. (can't choose)\n\n";
        }
        while ((cout << "Enter a number to choose : " && !(cin >> ss)) || ((ss < 1 || ss > 5) || ss == tmp)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid, try again." << endl;
        }
        if (ss == 1) { v.strength += 1; cout << "Strength Increased by 1!\n"; }
        if (ss == 2) { v.dexterity += 1; cout << "Dexterity Increased by 1!\n"; }
        if (ss == 3) { v.constitution += 1; cout << "Constitution Increased by 1!\n"; }
        if (ss == 4) { v.intelligence += 1; cout << "Intelligence Increased by 1!\n"; }
        if (ss == 5) { v.wisdom += 1; cout << "Wisdom Increased by 1!\n"; }
        cout << endl;
    }
    v.setAnySkill("Half Elfs gain two of any skill:", 2);
    v.common = true;  //only starting lang
    pressEnterToContinue();
}
void Halforc::setRaceDetails(Generic_Character_Class &v) {
    v.strength += 2;
    v.constitution += 2;
    v.move_speed = 30;
    v.darkvision = true;
    v.intimidation = true;
    v.common = true;
    v.orc = true;
    cout << "->Half-orc defaults & bonuses applied:\n"
         << " +2 STR, +1 CON, 30ft Move, Darkvision 60ft, Intimidation, Langs(Common, Orc)\n\n";
    pressEnterToContinue();
}
void Halfling::setRaceDetails(Generic_Character_Class &v) {
    v.dexterity += 2;
    v.move_speed = 25;
    v.halflinglucky = true;
    v.brave = true;
    v.halfling_nimbleness = true;
    v.common = true;
    v.halfling = true;
    cout << "->Halfling defaults & bonuses applied:\n"
         << " +2 DEX, 25ft Move, Lucky, Brave, Nimbleness, Langs(Common, Halfing)\n\n";
    cout << "Which kind of Halfling?\n\n 1. Lightfoot\n 2. Stout.\n\n";
    subr = static_cast<enum halflingtype>(getNumber("Halfling Type(1-2): ", 1, 2));
    switch (subr) {
    case LIGHTFOOT:
        v.charisma += 1;
        v.naturally_stealthy = true;
        cout << "->Lightfoot Halfling bonuses applied:\n"
             << " +1 CHA, Naturally Stealthy\n\n";
        break;
    case STOUT:
        v.constitution += 1;
        v.stout_resilience = true;
        v.damage_resist_poison = true;
        cout << "->Stout Halfling bonuses applied:\n"
             << " +1 CON, Stout Resilience\n\n";
    case NA:
    default:;
    }
    pressEnterToContinue();
}
void Human::setRaceDetails(Generic_Character_Class &v) {
    char rule = getYorN("Would you like to use the Variant Rule on Human Traits? (Y/N): ");
    if (rule == 'N') {
        v.strength += 1;
        v.dexterity += 1;
        v.constitution += 1;
        v.intelligence += 1;
        v.wisdom += 1;
        v.charisma += 1;
        cout << "->Human +1 all stat bonus applied.\n";
    } else {
        cout << "->Human variant, +1 to 2 differnt stats choice.\n";
        v.increase2statsby1();
        v.setAnySkill("->Human variant, choose a skill:", 1);
        cout << "->Human variant, choose one feat.\n";
        v.setAnyFeat();
    }
    v.move_speed = 30;
    cout << "->Human base move speed is " << v.move_speed << ".\n";
    v.common = true;
    v.setLanguage("->Humans gain 'know one language of your choice.'\n\n");
    pressEnterToContinue();
}
void Tiefling::setRaceDetails(Generic_Character_Class &v) {
    v.intelligence += 2;
    v.charisma += 2;
    v.move_speed = 30;
    v.darkvision = true;
    v.hellish_resistance = true;
    v.damage_resist_fire = true;
    v.infernal_legacy = true;
    v.common = true;
    v.infernal = true;
    cout << "->Tiefling defaults & bonuses applied:\n"
         << " +1 INT, +2 CHA, 30ft Move, Darkvision 60ft, Hellish Resistance, Infernal Legacy, Langs(Common, Infernal)\n\n";
    pressEnterToContinue();
}

//accessors
string Tiefling::getRaceString() const {
    return "Tiefling";
}
string Dragonborn::getRaceString() const {
    return "Dragonborn";
}
string Dwarf::getRaceString() const {
    string tmp = "";
    switch (subr) {
    case HILL:
        tmp += "Hill ";
        break;
    case MOUNTAIN:
        tmp += "Mountain ";
        break;
    case NA:
        break;
    default:
        break;

    }
    return tmp + "Dwarf";
}
string Elf::getRaceString() const {
    string tmp = "";
    switch (subr) {
    case HIGH:
        tmp += "High ";
        break;
    case WOOD:
        tmp += "Wood ";
        break;
    case DROW:
        tmp += "Drow ";
        break;
    case NA:
        break;
    default:
        break;
    }
    return tmp + "Elf";
}
string Gnome::getRaceString() const {
    string tmp = "";
    switch (subr) {
    case FOREST:
        tmp += "Forest ";
        break;
    case ROCK:
        tmp += "Rock ";
        break;
    case NA:
        break;
    default:
        break;
    }
    return tmp + "Gnome";
}
string Halfelf::getRaceString() const {
    return "Halfelf";
}
string Halfling::getRaceString() const {
    string tmp = "";
    switch (subr) {
    case LIGHTFOOT:
        tmp += "Lightfoot ";
        break;
    case STOUT:
        tmp += "Stout ";
        break;
    case NA:
        break;
    default:
        break;
    }
    return tmp + "Halfling";

}
string Halforc::getRaceString() const {
    return "Halforc";
}
string Human::getRaceString() const {
    return "Human";
}


