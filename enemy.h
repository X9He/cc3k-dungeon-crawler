
#ifndef enemy_hpp
#define enemy_hpp

#include "pc.h"
#include "character.h"


class Enemy: public Character {
    PC * Target;
    bool isFrozon;
    bool moved;
public:
    ~Enemy();
    Enemy(int initHP, int intAtk, int initDef, int Gold, PC * target, bool isFrozen = false, bool moved = false} 
    void move();
    virtual void attack(PC *) = 0;
    Enemy(PC *);
    void changeFrozen();
    void changeMoved();
    bool getMoved();
};

class NormalEnemy: public Enemy {
    bool isHostile;
    virtual void attack (PC *) = 0;
};

class Elf: public NormalEnemy {
public:
    void attack(PC *) override;
    Elf(PC *);
};

class Dward: public NormalEnemy {
public:
    void attack(PC *) override;
    Dward(PC *);
};

class Halfing: public NormalEnemy {
public:
    void attack(PC *) override;
    Halfing(PC *);
};

class Orcs: public NormalEnemy {
public:
    void attack(PC *) override;
    Orcs(PC *);
};

class Merchant: public Enemy {
    bool status;
    vector <Item *> store;
public:
    void attack(PC *) override;
    bool IsHostile();
    void changeStatus();
    Merchant(PC *);
};

class Dragon: public Enemy {
    Treasure * hoard;
public:
    void attack (PC *) override;
    Treasure * getHoard();
    Dragon(PC * target, Treasure * t);
};

class Human: public Enemy {
public:
    void attack (PC *) override;
    Human(PC *);
};

#endif /* enemy_hpp */
