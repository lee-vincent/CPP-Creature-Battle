//
//  Reptile.hpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Reptile_h
#define Reptile_h

#include <stdio.h>
#include "Creature.h"


class Reptile : public Creature {
    
public:
    Reptile();
    virtual void            Attack(Creature &opponent);
    virtual void            DoDamage(int damage, bool achilles);
    virtual int             Defense();
    virtual std::string     ToString();
};

#endif /* Reptile_h */
