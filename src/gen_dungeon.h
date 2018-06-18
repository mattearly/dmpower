/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2017 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#ifndef DUNGEONS_GEN_H
#define DUNGEONS_GEN_H
#pragma once

#include "globalfuncts.h"

using std::string;

class Dungeon
{

  public:
    Dungeon();
    //building a dungeon
    //Location
    string determineLocation() const;
    string determineExoticLocation() const;

    //Generate Creator
    string dungeonCreator() const;
    string dungeonCult() const;
    string dungeonCreatorClass() const;
    string dungeonPurpose() const;
    string dungeonHistory() const;
    //Generate Areas
    string genStartingArea() const;
    string genPassage() const;
    string genDoor() const;
    string genChamber() const;
    string genStair() const;
    //Generate Inhabitants
    string dungeonFactions() const;
    string dungeonEcology() const;
    string dungeonDifficulty() const;

  private:
    //Stocking a Dungeon
    string chamberPurpose;
    string otherCharacteristics;

    //Area Map
    //TODO
};

#endif //DUNGEONS_GEN_H
