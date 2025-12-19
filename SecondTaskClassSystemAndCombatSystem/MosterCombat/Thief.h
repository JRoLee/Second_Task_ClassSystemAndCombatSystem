#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class Thief :public Player
{
public:
  Thief(string name);
  void attack(shared_ptr<Monster> monster);
};