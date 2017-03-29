//
//  potion.cpp
//  CC3K
//
//  Created by Li on 2017-03-25.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#include "Potion.h"

void RH::useItem() {
    int max_HP = target->getmax();
    int cur_HP = target->getHP();
    
    if (cur_HP+10 <= max_HP) {
        target->changeHP(cur_HP+10);
    } else {
        target->changeHP(max_HP);
    }
}

void BA::useItem() {
    int cur_Atk = target->getAtk();
    target->changeAtk(cur_Atk+5);
}

void BD::useItem() {
    int cur_Def = target->getDef();
    target->changeDef(cur_Def+5);
}

void PH::useItem() {
    int cur_HP = target->getHP();
    if (cur_HP-10 >= 0) {
        target->changeHP(cur_HP-10);
    } else {
        target->changeHP(0);
    }
}

void WA::useItem() {
    int cur_Atk = target->getAtk();
    target->changeAtk(cur_Atk-5);
}

void WD::useItem() {
    int cur_Def = target->getDef();
    target->changeAtk(cur_Def-5);
}
