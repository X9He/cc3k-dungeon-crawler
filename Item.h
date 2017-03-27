//
//  item.hpp
//  CC3K
//
//  Created by Li on 2017-03-25.
//  Copyright © 2017 Wanxin Li. All rights reserved.
//

#ifndef item_hpp
#define item_hpp

#include <stdio.h>



class Item {
    int row;
    int col;
    
public:
    virtual void UseItem(int mag=1) = 0;
    
protected:
    PC * target;
};

#endif /* item_hpp */
