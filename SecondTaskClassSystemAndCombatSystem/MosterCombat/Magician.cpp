#include <iostream>
#include <cmath>
#include "Magician.h"
#include "Monster.h"
using namespace std;

Magician::Magician(string name): Player("마법사", name, 1, 70, 130, 60, 7, 80, 8){}

void Magician::attack(Monster* monster)
{

  int dmg = floor(power - monster->getDefence());
  if (dmg <= 0)
  {
    dmg = 1;
  }
  int pHPchange = monster->getHP() - dmg;
  if (pHPchange < 0)
  {
    pHPchange = 0;
  }

  cout << nickname << "이(가) " << monster->getName() << " 을(를) 공격 했습니다." << endl;
  cout << "파이어 볼!" << endl;
  cout << "!!!" << dmg << "!!!" << endl;
  cout << dmg << " 만큼 피해를 입혔습니다." << endl;
  cout << "몬스터 HP: " << monster->getHP() << " -> " << pHPchange << endl;
  monster->setHP(pHPchange);
}