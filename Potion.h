//
//  potion.hpp
//  CC3K
//
//  Created by Li on 2017-03-25.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#ifndef potion_hpp
#define potion_hpp

#include "Item.h"

class Potion: public Item {
public:
    virtual void useItem() = 0;
};

class RH: public Potion {
public:
    void useItem() override;
};

class BA: public Potion {
public:
    void useItem() override;
};

class BD: public Potion {
public:
    void useItem() override;
};

class PH: public Potion {
public:
    void useItem() override;
};

class WA: public Potion {
public:
    void useItem() override;
};

class WD: public Potion {
public:
    void useItem() override;
};

#endif /* potion_hpp */
