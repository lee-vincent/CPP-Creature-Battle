//
//  Barbarian.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Barbarian.h"


Barbarian::Barbarian() {
    attackDie       = new Die(6);
    defenseDie      = new Die(6);
    strengthPoints  = 12;
    armor           = 0;
    achilles = false;
}

void Barbarian::Attack(Creature &opponent) {
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



void Barbarian::DoDamage(int damage, bool achilles) {
    if(achilles)
        this->achilles = true;
    
    int appliedDamage = damage - armor;
    
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    strengthPoints -= appliedDamage;
}



int Barbarian::Defense() {
    return defenseDie->RollDie() + defenseDie->RollDie();
}


std::string Barbarian::ToString() {
    return "Barbarian";
}