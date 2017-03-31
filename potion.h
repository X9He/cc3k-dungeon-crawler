
#ifndef potion_hpp
#define potion_hpp

#include "item.h"

class Potion: public Item {
protected:
 std::string potionType;
public:
    Potion(PC* = nullptr, char itemType = 'P');
    ~Potion();
    std::string getPotionType();
    virtual void useItem(int mag) = 0;
};

class RH: public Potion {
public:
    RH(PC*);
    ~RH();
    void useItem(int mag) override;
};

class BA: public Potion {
public:
    BA(PC*);
    ~BA();
    void useItem(int mag) override;
};

class BD: public Potion {
public:
    BD(PC*);
    ~BD();
    void useItem(int mag) override;
};

class PH: public Potion {
public:
     PH(PC*);
    ~PH();
    void useItem(int mag) override;
};

class WA: public Potion {
public:
     WA(PC*);
     ~WA();
    void useItem(int mag) override;
};

class WD: public Potion {
public:
     WD(PC*);
     ~WD();
    void useItem(int mag) override;
};

#endif /* potion_hpp */
