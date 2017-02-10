//
//  Goblin.hpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Goblin_h
#define Goblin_h

#include <stdio.h>
#include "Creature.h"


class Goblin : public Creature {
        
public:
    Goblin();
    virtual void            Attack(Creature &opponent);
    virtual void            DoDamage(int damage, bool achilles);
    virtual std::string     ToString();
    virtual int             Defense();
};

#endif /* Goblin_h */
