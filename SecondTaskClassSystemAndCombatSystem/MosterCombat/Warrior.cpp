#include <iostream>
#include <cmath>
#include "Warrior.h"
#include "Monster.h"
using namespace std;

Warrior::Warrior(string name) : Player("전사", name, 1, 120, 80, 40, 20, 70, 10) {}

void Warrior::attack(Monster* monster)
{
  int dmg = floor(power - monster->getDefence());
  if (dmg <= 0)
  {
    dmg = 1;
  }
  int ObjHPchange = monster->getHP() - dmg;
  if (ObjHPchange < 0)
  {
    ObjHPchange = 0;
  }
  cout << nickname << "이(가) " << monster->getName() << "을(를) 공격 했습니다." << endl;
  cout << "파워 스트라이크!" << endl;
  cout << "!!!" << dmg << "!!!" << endl;
  cout << dmg << " 만큼 피해를 입혔습니다." << endl;
  cout << "몬스터 HP: " << monster->getHP() << " -> " << ObjHPchange << endl;
  monster->setHP(ObjHPchange);
}