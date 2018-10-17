#include "minimal_fighter.h"

MinimalFighter::MinimalFighter() : 
    mHp(0), mPower(0), mStatus(FighterStatus::Dead) 
{
    // Do Nothing
}

MinimalFighter::MinimalFighter(int _hp, int _power) :
    mHp(_hp), mPower(_power), mStatus(_hp > 0 ? FighterStatus::Alive : FighterStatus::Dead)
{
    // Do Nothing
}

int MinimalFighter::hp() const {
    return mHp;
}

int MinimalFighter::power() const {
    return mPower;
}

FighterStatus MinimalFighter::status() const {
    return mStatus;
}

void MinimalFighter::setHp(int _hp) {
    mHp = _hp;
    if (mHp <= 0) {
        mStatus = FighterStatus::Dead;
    }
}

void MinimalFighter::hit(MinimalFighter* _enemy) {
    int enemy_hp = _enemy->hp() - mPower;
    _enemy->setHp(enemy_hp);

    setHp(mHp - _enemy->power());
}

void MinimalFighter::attack(MinimalFighter* _target) {
    _target->setHp(_target->hp() - mPower);
    mPower = 0;
}

void MinimalFighter::fight(MinimalFighter* _enemy) {
    while (mStatus != FighterStatus::Dead 
        && _enemy->status() != FighterStatus::Dead) 
    {
        hit(_enemy);
    }
}
