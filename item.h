#ifndef item_hpp
#define item_hpp
#include <string>
#include <iostream>

class PC;

class Item {
    int row;
    int col;
    
public:
    virtual void useItem(int mag=1) = 0;
    
protected:
    PC * target;
};

#endif /* item_hpp */
