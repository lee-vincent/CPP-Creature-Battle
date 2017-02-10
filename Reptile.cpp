//
//  Reptile.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Reptile.h"


Reptile::Reptile() {
    attackDie       = new Die(6);
    defenseDie      = new Die(6);
    strengthPoints  = 18;
    armor           = 7;
    achilles = false;
}

void Reptile::Attack(Creature &opponent) {
    int attack = attackDie->RollDie() + attackDie->RollDie() + attackDie->RollDie();
    
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



void Reptile::DoDamage(int damage, bool achilles) {
    if(achilles)
        this->achilles = true;
    
    int appliedDamage = damage - armor;
    
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    strengthPoints -= appliedDamage;
}



int Reptile::Defense() {
    return defenseDie->RollDie();
}


std::string Reptile::ToString() {
    return "Reptile";
}