#pragma once
#include <string>
#include "Player.h"
class Thief :public Player
{
public:
  Thief(string name);
  void attack();
};