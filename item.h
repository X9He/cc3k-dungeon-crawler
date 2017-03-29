#ifndef item_hpp
#define item_hpp
#include <string>
#include <iostream>

class PC;

class Item {
    int row;
    int col;
    char itemType;
    
public:
    virtual void useItem(int mag=1) = 0;
    char getType();
    int getRow();
    int getCol();
    
protected:
    PC * target;
};

#endif /* item_hpp */
