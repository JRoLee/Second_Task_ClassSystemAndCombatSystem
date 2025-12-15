#pragma once
#include <string>
#include "Monster.h"
#include "Player.h"

class Orc :public Monster
{
public:
  Orc();
  void attack(Player* player);
};