//
//  Treasure.hpp
//  CC3K
//
//  Created by Li on 2017-03-25.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#ifndef Treasure_hpp
#define Treasure_hpp

#include "Item.h"

class Treasure: public Item {
    int value;
    bool protect;
public:
    Treasure(int, bool);
    int getValue();
    bool isProtect();
    void useItem();
};

#endif /* Treasure_hpp */
