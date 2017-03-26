//
//  Treasure.cpp
//  CC3K
//
//  Created by Li on 2017-03-25.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#include "Treasure.hpp"

Treasure::Treasure(int value, bool protect):
value{value}, protect{protect} {}

int Treasure::getValue() {
    return value;
}
bool Treasure::isProtect() {
    return protect;
}

void Treasure::useItem() {
    target->pickupItem(*this);
}

