#include <iostream>
#include "Warrior.h"

Warrior::Warrior(string name) : Player("ภüป็", name, 1, 120, 80, 40, 20, 70, 10) {}

void Warrior::attack()
{
    std::cout << "Power strike!" << endl;
}