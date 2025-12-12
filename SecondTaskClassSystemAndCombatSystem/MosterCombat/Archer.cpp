#include <iostream>
#include "Archer.h"
Archer::Archer(string name) : Player("±Ã¼ö", name, 1, 90, 110, 50, 10, 100, 15) {}

void Archer::attack()
{
  std::cout << "Power Arrow!" << endl;
}