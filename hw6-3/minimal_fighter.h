#ifndef MINIMAL_FIGHTER_H
#define MINIMAL_FIGHTER_H

enum class FighterStatus {
    Invalid,
    Alive,
    Dead,
};

class MinimalFighter {
public:
    MinimalFighter();
    MinimalFighter(int _hp, int _power);

    int hp() const;
    int power() const;
    FighterStatus status() const;

    void setHp(int _hp);
    void hit(MinimalFighter* _enemy);
    void attack(MinimalFighter* _target);
    void fight(MinimalFighter* _enemy);

private:
    int mHp;
    int mPower;
    FighterStatus mStatus;
};

#endif
