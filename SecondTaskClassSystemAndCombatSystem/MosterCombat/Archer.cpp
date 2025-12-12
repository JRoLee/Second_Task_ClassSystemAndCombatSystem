#include <iostream>
#include <cmath>
#include "Archer.h"
#include "Monster.h"
using namespace std;

Archer::Archer(string name) : Player("궁수", name, 1, 90, 110, 50, 10, 100, 15) {}

void Archer::attack(Monster* monster)
{

  int dmg = floor((power - monster->getDefence()) / 3);
  if (dmg <= 0)
  {
    dmg = 1;
  }
  int pHPchange = monster->getHP() - dmg*3;
  if (pHPchange < 0)
  {
    pHPchange = 0;
  }

  cout << nickname << "이(가) " << monster->getName() << " 을(를) 공격 했습니다." << endl;
  cout << "트리플 샷!" << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << "!!!" << dmg << "!!!" << endl;
  }
  cout << dmg*3 << " 만큼 피해를 입혔습니다." << endl;
  cout << "몬스터 HP: " << monster->getHP() << " -> " << pHPchange << endl;
  monster->setHP(pHPchange);
}