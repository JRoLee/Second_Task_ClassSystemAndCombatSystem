#pragma once
#include <iostream>
#include "Player.h"
using namespace std;
class Monster
{
public:
  Monster(string name, int hp, int power, int defence, int speed);

  void attack(Player* player);

  string getName();
  int getHP();
  int getPower();
  int getDefence();
  int getspeed();

  void setName(string name);
  void setHP(int HP);
  void setPower(int power);
  void setDefence(int defence);
  int setSpeed(int speed);

private:
  string name;
  int HP;
  int power;
  int defence;
  int speed;
};