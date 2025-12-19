#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class Warrior :public Player
{
public:
  Warrior(string name);
  void attack(shared_ptr<Monster> monster);
};