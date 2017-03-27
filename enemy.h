
#ifndef enemy_hpp
#define enemy_hpp

class Character;
class PC;

class Enemy: public Character {
    int dropAmount;
    PC * Target;
    int hitChance;
    bool isFrozon;
    
public:
    void move();
    void virtual attack(PC *) = 0;
    void HPchange();
    Enemy(int, int, int, int, int, int, int, PC *, int, bool);
};

class NormalEnemy: public Enemy {
    bool IsHostile;
    virtual void attack (PC *) = 0;
};

class Elf: public NormalEnemy {
public:
    void attack(PC *) override;
};

class Dward: public NormalEnemy {
public:
    void attack(PC *) override;
};

class Halfing: public NormalEnemy {
public:
    void attack(PC *) override;
};

class Orcs: public NormalEnemy {
public:
    void attack(PC *) override;
};

class Merchant: public Enemy {
    bool status;
    vector <Item *> store;
public:
    void attack(PC *) override;
    bool IsHostile();
    void changeStatus();
};

class Dragon: public Enemy {
    Treasure * hoard;
public:
    void attack (PC *) override;
};

class Human: public Enemy {
public:
    void attack (PC *) override;
};

#endif /* enemy_hpp */
