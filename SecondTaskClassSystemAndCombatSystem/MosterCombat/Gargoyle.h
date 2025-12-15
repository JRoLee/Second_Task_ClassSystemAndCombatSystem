#pragma once
#include <string>
#include "Monster.h"
#include "Player.h"

class Gargoyle :public Monster
{
public:
  Gargoyle();
  void attack(Player* player);
};