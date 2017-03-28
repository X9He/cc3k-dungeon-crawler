
#ifndef potion_hpp
#define potion_hpp

#include "item.h"

class Potion: public Item {
public:
    virtual void useItem(int mag) = 0;
};

class RH: public Potion {
public:
    void useItem(int mag) override;
};

class BA: public Potion {
public:
    void useItem(int mag) override;
};

class BD: public Potion {
public:
    void useItem(int mag) override;
};

class PH: public Potion {
public:
    void useItem(int mag) override;
};

class WA: public Potion {
public:
    void useItem(int mag) override;
};

class WD: public Potion {
public:
    void useItem(int mag) override;
};

#endif /* potion_hpp */
