#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"

class Character{
    std::string _name;
    int _strength;
    int _maxHP;
    int _currentHP;
    Weapon *_weapon;

public:

    Character(std::string name, int strength, int maxHP): _name(name), _strength(strength), _maxHP(maxHP){
        _currentHP = _maxHP;
        _weapon = nullptr;
    }

    void giveWeapon(Weapon *w){
        _weapon = w;
    }


    int computeAttackDamage(){
        if(_weapon != nullptr)  return _weapon->getDamage() + _strength;
        else                    return 0;
    }

    void takeDamage(int damage){
        _currentHP -= damage;

        _currentHP < 1  ? std::cout << " IS DEAD!" << std::endl
                        : std::cout << _name << " has " << _currentHP << " left" << std::endl;
    }

    void attack(Character * anotherChar){

        std::cout << _name << " attacks " << anotherChar->_name << std::endl;

        anotherChar->takeDamage(computeAttackDamage());
    }

};
