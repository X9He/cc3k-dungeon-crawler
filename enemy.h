
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
    void HPchange();
    Enemy(int, int, int, int, int, int, PC *, int, bool isFrozen=false);
};

class NormalEnemy: public Enemy {
    bool IsHostile;
    virtual void attack (PC *) = 0;
};

class Elf: public NormalEnemy {
public:
    void attack(PC *) override;
    Elf(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen);
};

class Dward: public NormalEnemy {
public:
    void attack(PC *) override;
    Dward(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen);
};

class Halfing: public NormalEnemy {
public:
    void attack(PC *) override;
    Halfing(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen);
};

class Orcs: public NormalEnemy {
public:
    void attack(PC *) override;
    Orcs(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen);
};

class Merchant: public Enemy {
    bool status;
    vector <Item *> store;
public:
    void attack(PC *) override;
    bool IsHostile();
    void changeStatus();
    Merchant(int row, int col, PC * target, int Gold, int hitChance, bool isFrozen);
};

class Dragon: public Enemy {
    Treasure * hoard;
public:
    void attack (PC *) override;
    Dragon(int row, int col, PC * target, int hitChance, bool isFrozen, Treasure * t);
};

class Human: public Enemy {
public:
    void attack (PC *) override;
    Human(int row, int col, PC * target, int hitChance, bool isFrozen);
};

#endif /* enemy_hpp */
