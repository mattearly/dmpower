//
//  gen_encounter.h
//  DM-Power-Core-Version
//
//  Created by Matthew Early on 10/26/15.
//  Copyright (c) 2016 athenstechgiants. All rights reserved.
//

#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H

class Encounter {
public:
    Encounter();
    
    std::string Gen_Encounter();
    
    
private:
    void set_party_level();
    int ave_cr;
    
}



#endif //ENCOUNTERS_H
