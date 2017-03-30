
#ifndef potion_hpp
#define potion_hpp

#include "item.h"

class Potion: public Item {
public:
    potion(char itemType = 'P')£»
  ~potion();
    virtual void useItem(int mag) = 0;
};

class RH: public Potion {
public:
    RH();
    ~RH();
    void useItem(int mag) override;
};

class BA: public Potion {
public:
    BA();
    ~BA();
    void useItem(int mag) override;
};

class BD: public Potion {
public:
    BD();
    ~BD();
    void useItem(int mag) override;
};

class PH: public Potion {
public:
     PH();
    ~PD();
    void useItem(int mag) override;
};

class WA: public Potion {
public:
     WA();
     ~WA();
    void useItem(int mag) override;
};

class WD: public Potion {
public:
     WD();
     ~WD();
    void useItem(int mag) override;
};

#endif /* potion_hpp */
