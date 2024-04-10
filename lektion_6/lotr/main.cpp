#include <iostream>
#include <vector>
#include "Character.h"
#include "Weapon.h"

int main(){
    Weapon sword(4);
    Character aragorn("aragorn", 3,20);
    std::cout << "Aragorn attack damage (no weapon): " << aragorn.computeAttackDamage() << std::endl;
    aragorn.giveWeapon(&sword);
    std::cout << "Aragorn attack damage (with sword): " << aragorn.computeAttackDamage() << std::endl;
    sword.sharpen();
    std::cout << "Aragorn attack damage (with sharpened sword: " << aragorn.computeAttackDamage() << std::endl;
    std::cout << std::endl;

    Character orc("orc", 8,17);
    aragorn.attack(&orc);
    aragorn.attack(&orc);
    aragorn.attack(&orc);
    std::cout << std::endl;

    std::vector<Character*> enemies;
    Character e1("wolf", 2,5);
    Character e2("bandit", 10,20);
    Character e3("Sauron",42,9000);
    enemies.push_back(&e1);
    enemies.push_back(&e2);
    enemies.push_back(&e3);
    Character * currentEnemy = enemies[1];

    aragorn.attack(currentEnemy);
    currentEnemy->attack(&aragorn);
    aragorn.attack(currentEnemy);
    std::cout << std::endl;

    Weapon bow(3);
    e2.giveWeapon(&bow);
    currentEnemy->attack(&aragorn);

    return 0;
}
