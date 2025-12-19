#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class Magician :public Player
{
public:
  Magician(string name);
  void attack(shared_ptr<Monster> monster);
};