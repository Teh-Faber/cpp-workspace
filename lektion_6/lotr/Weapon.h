#pragma once

class Weapon{
    int _damage;

public:
    Weapon(int damage): _damage(damage){}

    int getDamage(){
        return _damage;
    }

    void sharpen(){
        _damage++;
    }

};
