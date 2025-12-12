#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class Archer :public Player
{
public:
  Archer(string name);
  void attack(Monster* monster);
};