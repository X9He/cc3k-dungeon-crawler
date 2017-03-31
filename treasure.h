#ifndef Treasure_hpp
#define Treasure_hpp

#include "item.h"

class Treasure: public Item {
    int value;
    bool protect;
public:
   ~Treasure();
    Treasure(int, bool, PC* player, char itemType = 'G');
    int getValue();
    bool isProtect();
    void useItem(int mag=1) override;
    void changeProtect();
};

class Small: public Treasure {
    public:
    Small(PC* player);
};

class Normal: public Treasure {
    public:
    Normal(PC* player);
};

class MH: public Treasure {
    public:
    MH(PC* player);
};

class DH: public Treasure {
    public:
    DH(PC* player);
};

#endif /* Treasure_hpp */
