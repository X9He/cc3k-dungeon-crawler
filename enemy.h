
#ifndef enemy_hpp
#define enemy_hpp

#include "pc.h"
#include "character.h"
#include "treasure.h"
#include <vector>


class Enemy: public Character {
    PC * Target;
    bool isFrozen;
    bool moved;
public:
    ~Enemy();
    Enemy(int initHP, int intAtk, int initDef, int Gold, PC * target, bool isFrozen = false, bool moved = false); 
    void move();
    virtual void attack(PC *target) = 0;
    Enemy(PC *target);
    void changeFrozen();
    void changeMoved();
    bool getMoved();
    void hurt(Troll *p);
    void hurt(Vampire *p);
    void hurt(Goblin *p);
    void hurt(Drow *p);
};

class NormalEnemy: public Enemy {
    bool IsHostile;
    virtual void attack (PC *target) = 0;
public:
    NormalEnemy(int initHP, int intAtk, int initDef, int Gold, PC * target, bool isFrozen = false, bool moved = false);
};

class Elf: public NormalEnemy {
public:
    void attack(PC *target) override;
    Elf(PC *target);
};

class Dwarf: public NormalEnemy {
public:
    void attack(PC *target) override;
    Dwarf(PC *target);
};

class Halfing: public NormalEnemy {
public:
    void attack(PC *target) override;
    Halfing(PC *target);
};

class Orcs: public NormalEnemy {
public:
    void attack(PC *target) override;
    Orcs(PC *targte);
};

class Merchant: public Enemy {
    bool status;
    std::vector<Item *> store;
public:
    void attack(PC *target) override;
    bool IsHostile();
    void changeStatus();
    Merchant(PC *target);
};

class Dragon: public Enemy {
    Treasure * hoard;
public:
    void attack (PC *targte) override;
    Treasure * getHoard();
    Dragon(PC * target, Treasure * t);
};

class Human: public Enemy {
public:
    void attack (PC *target) override;
    Human(PC *target);
};

#endif /* enemy_hpp */
