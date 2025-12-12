#include <iostream>
#include <string>
#include "Goblin.h"
#include "Player.h"

Goblin::Goblin():Monster("고블린",50,30,10,10){}

void Goblin::attack(Player* player)
{

  int dmg = power - player->getDefence();
  if (dmg <= 0)
  {
    dmg = 1;
  }
  int pHPchange = player->getHP() - dmg;
  if (pHPchange < 0)
  {
    pHPchange = 0;
  }

  cout << name << "이 " << player->getNickName() << " 을(를) 공격 했습니다." << endl;
  cout << "!!!" << dmg << "!!!" << endl;
  cout << dmg << "만큼 피해를 입었습니다." << endl;
  cout << "플레이어 HP: " << player->getHP() << " -> " << pHPchange << endl;
  player->setHP(pHPchange);
}