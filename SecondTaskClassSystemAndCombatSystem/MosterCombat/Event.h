#pragma once
#include <memory>
#include "Player.h"
#include "Monster.h"

class Event
{
public:
  shared_ptr<Monster> spawnMonster();
  Player* SetPlayer();
  void victoryEvent(shared_ptr<Monster> monster);
  void defeatEvent(Player* player);
  void fleeEvent();
  void battleEvent(Player* player);
  void battleChoice(Player* player, shared_ptr<Monster> monster);
  void statusCompare(Player* player, shared_ptr<Monster> monster);
};