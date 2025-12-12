#pragma once
#include <string>
#include "Player.h"

class Magician :public Player
{
public:
  Magician(string name);
  void attack();
};