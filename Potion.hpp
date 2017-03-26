//
//  potion.hpp
//  CC3K
//
//  Created by Li on 2017-03-25.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#ifndef potion_hpp
#define potion_hpp

#include "Item.hpp"

class Potion: public Item {
public:
    virtual void useItem() = 0;
};

#endif /* potion_hpp */
