#pragma once
#include <memory>
#include "Player.h"
#include "Monster.h"

class Event
{
public:
  unique_ptr<Monster> spawnMonster();
  void victoryEvent(Monster* monster);
  void defeatEvent(Player* player);
  void fleeEvent();
  void battleEvent(Player* player);
  int battleChoice();
  void statusCompare(Player* player, Monster* monster);
};