//
//  Creature.hpp/Users/Vincent_Lee/Desktop/Oregon State/cs162/assignment3/assignment3/Creature.h
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Creature_h
#define Creature_h

#include <stdio.h>
#include "Die.h"
#include <string>


class Creature {

protected:
    int     strengthPoints;
    bool    achilles;
    int     armor;
    Die     *attackDie;
    Die     *defenseDie;
    
public:
    virtual void            Attack(Creature &opponent)          = 0;
    virtual void            DoDamage(int damage, bool achilles) = 0;
    virtual int             Defense()                           = 0;
    virtual std::string     ToString()                          = 0;
    int                     GetStrengthPoints();
};





#endif /* Creature_h */
