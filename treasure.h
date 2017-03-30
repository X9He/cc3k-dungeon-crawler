#ifndef Treasure_hpp
#define Treasure_hpp

#include "item.h"

class Treasure: public Item {
    int value;
    bool protect;
public:
   ~Treasure();
    Treasure(int, bool, char itemType = 'G');
    int getValue();
    bool isProtect();
    void useItem(int mag=1) override;
    void changeProtect();
};

class Small: public Treasure {
    public:
    Small();
};

class Normal: public Treasure {
    public:
    Normal();
};

class MH: public Treasure {
    public:
    MH();
};

class DH: public Treasure {
    public:
    DH();
};

#endif /* Treasure_hpp */
