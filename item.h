

#ifndef item_hpp
#define item_hpp

#include <stdio.h>


class PC;

class Item {
    int row;
    int col;
    
public:
    virtual void UseItem(int mag=1) = 0;
    
protected:
    PC * target;
};

#endif /* item_hpp */
