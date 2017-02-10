//
//  Shadow.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Shadow.h"
#include <stdlib.h>


Shadow::Shadow() {
    attackDie       = new Die(10);
    defenseDie      = new Die(6);
    strengthPoints  = 12;
    armor           = 0;
    achilles = false;
}

void Shadow::Attack(Creature &opponent) {
    int attack = attackDie->RollDie() + attackDie->RollDie();
    
    if (achilles)
        attack /= 2;
    
    int opponentDefense = opponent.Defense();
    
    if(opponentDefense == 0) {
        //use 0 as special value only Shadow can produce
        //we fought a Shadow and we missed
        return;
        
    } else {
        int damage = attack - opponentDefense;
        
        if(damage < 0)
            damage = 0;
        
        opponent.DoDamage(damage, false);
    }
}



void Shadow::DoDamage(int damage, bool achilles) {
    if(achilles)
        this->achilles = true;
    
    int appliedDamage = damage - armor;
    
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    strengthPoints -= appliedDamage;
}



int Shadow::Defense() {
    if(rand() % 2 == 0) {
        return 0;
    } else {
         return defenseDie->RollDie();
    }
}


std::string Shadow::ToString() {
    return "Shadow";
}


