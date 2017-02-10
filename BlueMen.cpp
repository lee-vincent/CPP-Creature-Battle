//
//  BlueMen.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "BlueMen.h"


BlueMen::BlueMen() {
    attackDie       = new Die(10);
    defenseDie      = new Die(10);
    strengthPoints  = 12;
    armor           = 3;
    achilles = false;
}

void BlueMen::Attack(Creature &opponent) {
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



void BlueMen::DoDamage(int damage, bool achilles) {
    if(achilles)
        this->achilles = true;
    
    int appliedDamage = damage - armor;
    
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    strengthPoints -= appliedDamage;
}



int BlueMen::Defense() {
    return defenseDie->RollDie() + defenseDie->RollDie() + defenseDie->RollDie();
}


std::string BlueMen::ToString() {
    return "BlueMen";
}