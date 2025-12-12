#pragma once
#include <string>
#include "Player.h"
class Warrior :public Player
{
public:
  Warrior(string nickname);
  void attack();
};