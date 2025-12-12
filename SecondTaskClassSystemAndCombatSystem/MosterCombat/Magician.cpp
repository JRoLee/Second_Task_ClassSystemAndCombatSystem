#include <iostream>
#include "Magician.h"

Magician::Magician(string name): Player("¸¶¹ý»ç", name, 1, 70, 130, 60, 7, 80, 8){}

void Magician::attack()
{
  std::cout << "Magic Claw!" << endl;
}