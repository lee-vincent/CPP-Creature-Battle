//
//  BlueMen.hpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef BlueMen_h
#define BlueMen_h

#include <stdio.h>
#include "Creature.h"


class BlueMen : public Creature {
    
public:
    BlueMen();
    virtual void            Attack(Creature &opponent);
    virtual void            DoDamage(int damage, bool achilles);
    virtual int             Defense();
    virtual std::string     ToString();
};

#endif /* BlueMen_h */
