
#ifndef enemy_hpp
#define enemy_hpp

class Character;
class PC;


class Enemy: public Character {
    PC * Target;
    int hitChance;
    bool isFrozon;
    
public:
    void move();
    virtual void attack(PC *) = 0;
    Enemy(PC *);
};

class NormalEnemy: public Enemy {
    bool IsHostile;
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
    Dragon(PC * target, Treasure * t);
};

class Human: public Enemy {
public:
    void attack (PC *) override;
    Human(PC *);
};

#endif /* enemy_hpp */
