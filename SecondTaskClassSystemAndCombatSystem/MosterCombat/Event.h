#pragma once
#include "Player.h"
#include "Monster.h"

class Event
{
public:
  void spawnMonster();
  void victoryEvent();
  void defeatEvent();
  void fleeEvent();

protected:
};