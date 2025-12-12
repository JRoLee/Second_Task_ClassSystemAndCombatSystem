#pragma once
#include <string>
#include "Monster.h"
#include "Player.h"

class Goblin :public Monster
{
public:
  Goblin();
  void attack(Player* player);
};