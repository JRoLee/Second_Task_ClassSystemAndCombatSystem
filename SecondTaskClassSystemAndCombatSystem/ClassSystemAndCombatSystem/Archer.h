#pragma once
#include <string>
#include "Player.h"
class Archer :public Player
{
public:
  Archer(string nickname): level {}
  void attack();
};