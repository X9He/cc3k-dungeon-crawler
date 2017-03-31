
#ifndef enemy_hpp
#define enemy_hpp

#include "pc.h"
#include "character.h"
#include "treasure.h"
#include <vector>

class Troll;
class Vampire;
class Goblin;
class Drow;
class Elf;

class Enemy: public Character {
    PC * Target;
    bool moved;
public:
    ~Enemy();
    Enemy(int initHP, int intAtk, int initDef, int Gold, PC * target, bool moved = false); 
    void move();
    virtual void attack(PC *target) = 0;
    Enemy(PC *target);
    void changeMoved();
    bool getMoved();
    virtual void hurt(Troll *p);
    virtual void hurt(Vampire *p);
    virtual void hurt(Goblin *p);
    virtual void hurt(Drow *p);
    virtual void hurt(PC *p);
};

class NormalEnemy: public Enemy {
    bool IsHostile;
    virtual void attack (PC *target) = 0;
public:
    NormalEnemy(int initHP, int intAtk, int initDef, int Gold, PC * target, bool moved = false);
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

class Halfling: public NormalEnemy {
public:
    void attack(PC *target) override;
    Halfling(PC *target);
    void hurt(Troll *p) override;
    void hurt(Drow *p) override;
    void hurt(Vampire *p) override;
    void hurt(PC *p) override;
    void hurt(Goblin *p) override;
       
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
    bool isHostile();
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
