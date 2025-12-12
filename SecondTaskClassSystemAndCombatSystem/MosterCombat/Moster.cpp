#include <iostream>
#include <string>
#include "Monster.h"


Monster::Monster(string name, int hp, int power, int defence, int speed)
          :name(name),HP(hp),power(power),defence(defence),speed(speed)
          { }

string Monster::getName() { return name;}
int Monster::getHP() { return HP; }
int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }
int Monster::getSpeed() { return speed; }

void Monster::setName(string Name) { name = Name; }
void Monster::setHP(int Hp) { HP = Hp; }
void Monster::setPower(int Power) { power = Power; }
void Monster::setDefence(int Defence) { defence = Defence; }
void Monster::setSpeed(int Speed) { speed = Speed; }