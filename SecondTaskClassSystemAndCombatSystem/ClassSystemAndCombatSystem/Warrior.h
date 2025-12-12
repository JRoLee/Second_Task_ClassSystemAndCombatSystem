#pragma once
#include <string>
#include "Player.h"
class Warrior :public Player
{
public:
  Warrior(string name);
  void attack();
};