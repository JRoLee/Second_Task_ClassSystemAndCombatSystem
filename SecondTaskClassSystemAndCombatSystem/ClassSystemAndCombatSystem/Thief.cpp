#include <iostream>
#include "Thief.h"
Thief::Thief(string name) : Player("µµÀû", name, 1, 90, 110, 65, 5, 90, 20) {}

void Thief::attack()
{
  std::cout << "Lucky Seven!" << endl;
}