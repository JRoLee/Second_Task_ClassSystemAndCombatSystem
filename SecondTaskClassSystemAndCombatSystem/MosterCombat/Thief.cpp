#include <iostream>
#include <cmath>
#include "Thief.h"
#include "Monster.h"
using namespace std;

Thief::Thief(string name) : Player("도적", name, 1, 90, 110, 65, 5, 90, 20) {}

void Thief::attack(Monster* monster)
{
  int dmg = floor((power - monster->getDefence()) / 5);
  if (dmg <= 0)
  {
    dmg = 1;
  }
  int ObjHPchange = monster->getHP() - dmg * 5;
  if (ObjHPchange < 0)
  {
    ObjHPchange = 0;
  }
  cout << nickname << "이(가) " << monster->getName() << "을(를) 공격 했습니다." << endl;
  cout << "새비지 블로우!" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "!!!" << dmg << "!!!" << endl;
  }
  cout << dmg * 5 << " 만큼 피해를 입혔습니다." << endl;
  cout << "몬스터 HP: " << monster->getHP() << " -> " << ObjHPchange << endl;
  monster->setHP(ObjHPchange);
}