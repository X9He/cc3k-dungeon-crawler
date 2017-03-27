
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
    void useItem(int mag=1) override;
};

#endif /* Treasure_hpp */
