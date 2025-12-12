#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Monster
{
public:
  Monster(string name, int hp, int power, int defence, int speed);

  virtual void attack(Player* player) = 0;

  string getName();
  int getHP();
  int getPower();
  int getDefence();
  int getSpeed();

  void setName(string Name);
  void setHP(int Hp);
  void setPower(int Power);
  void setDefence(int Defence);
  void setSpeed(int Speed);

protected:
  string name;
  int HP;
  int power;
  int defence;
  int speed;
};