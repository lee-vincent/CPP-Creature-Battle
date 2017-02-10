//
//  Goblin.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Goblin.h"
#include <iostream>

Goblin::Goblin() {
    attackDie       = new Die(6);
    defenseDie      = new Die(6);
    strengthPoints  = 8;
    armor           = 3;
    achilles = false;
}

void Goblin::Attack(Creature &opponent) {
    int attack = attackDie->RollDie() + attackDie->RollDie();
    int opponentDefense = opponent.Defense();
    
    if(opponentDefense == 0) {
        //use 0 as special value only Shadow can produce
        //we fought a Shadow and we missed
        return;
        
    } else {
        int damage = attack - opponentDefense;
        
        if(damage < 0)
            damage = 0;
        
        bool handicap = (attack == 12) ? true : false;
        opponent.DoDamage(damage, handicap);
    }
}



void Goblin::DoDamage(int damage, bool achilles) {
    int appliedDamage = damage - armor;
    
    //dont apply negative damage
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    strengthPoints -= appliedDamage;
}



int Goblin::Defense() {
    return defenseDie->RollDie();
}

std::string Goblin::ToString() {
    return "Goblin";
}