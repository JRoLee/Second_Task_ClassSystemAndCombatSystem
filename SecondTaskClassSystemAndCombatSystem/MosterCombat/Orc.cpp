#include <iostream>
#include <string>
#include "Orc.h"
#include "Player.h"

Orc::Orc() :Monster("오크", 200, 40, 20, 10) {}

void Orc::attack(Player* player)
{

  int dmg = power - player->getDefence();
  if (dmg <= 0)
  {
    dmg = 1;
  }
  int ObjHPchange = player->getHP() - dmg;
  if (ObjHPchange < 0)
  {
    ObjHPchange = 0;
  }

  cout << name << "이 " << player->getNickName() << " 을(를) 공격 했습니다." << endl;
  cout << "!!!" << dmg << "!!!" << endl;
  cout << dmg << "만큼 피해를 입었습니다." << endl;
  cout << "플레이어 HP: " << player->getHP() << " -> " << ObjHPchange << endl;
  player->setHP(ObjHPchange);
}