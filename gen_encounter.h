//
//  gen_encounter.h
//  DM-Power-Core-Version
//
//  Created by Matthew Early on 10/26/16.
//  Copyright (c) 2016 athenstechgiants. All rights reserved.
//

#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H
#include <string>

class Encounter {
public:
    bool testing = true;
    Encounter();
    
    std::string Gen_Encounter();
    
    
private:
    void set_party_level();
    int ave_lvl;
    int partysize;
};



#endif //ENCOUNTERS_H
