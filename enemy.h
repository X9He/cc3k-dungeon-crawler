
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
    virtual ~Enemy();
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
    virtual void attack (PC *target) = 0;
public:
    NormalEnemy(int initHP, int intAtk, int initDef, int Gold, PC * target, bool moved = false);
    virtual ~NormalEnemy();
};

class Elf: public NormalEnemy {
public:
    void attack(PC *target) override;
    Elf(PC *target);
    ~Elf() override;

};

class Dwarf: public NormalEnemy {
public:
    void attack(PC *target) override;
    Dwarf(PC *target);
    ~Dwarf() override;
};

class Halfling: public NormalEnemy {
public:
    void attack(PC *target) override;
    Halfling(PC *target);
    ~Halfling() override;
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
    ~Orcs() override;
};

class Merchant: public Enemy {
    std::vector<Item *> store;
public:
    void attack(PC *target) override;
    Merchant(PC *target);
    ~Merchant() override;
};

class Dragon: public Enemy {
    Treasure * hoard;
public:
    void attack (PC *targte) override;
    Treasure * getHoard();
    Dragon(PC * target, Treasure * t);
    ~Dragon() override;
};

class Human: public Enemy {
public:
    void attack (PC *target) override;
    Human(PC *target);
    ~Human() override;
};

#endif /* enemy_hpp */
