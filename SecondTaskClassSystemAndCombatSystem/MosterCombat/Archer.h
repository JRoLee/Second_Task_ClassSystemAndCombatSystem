#pragma once
#include <string>
#include "Player.h"
class Archer :public Player
{
public:
  Archer(string name);
  void attack();
};