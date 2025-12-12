#pragma once
#include <string>
#include "Player.h"
class Thief :public Player
{
public:
  Thief(string nickname);
  void attack();
};