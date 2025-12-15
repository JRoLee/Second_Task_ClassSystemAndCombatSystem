#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Event.h"
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "Gargoyle.h"
#include "Orc.h"
using namespace std;

unique_ptr<Monster> Event::spawnMonster()
{
  int rNum = rand() % 100 + 1;
  
  if (rNum >= 90)
  {
    cout << "!!!!!!!!!! 매우 강력한 적 가고일을 만났습니다. !!!!!!!!!!" << endl;
    return make_unique<Gargoyle>();
  }
  else if (rNum >= 60)
  {
    cout << "********** 강력한 적 오크를 만났습니다. **********" << endl;
    return make_unique<Orc>();
  }
  else
  {
    cout << "----------- 적 고블린을 만났습니다. -----------" << endl;
    return make_unique<Goblin>();
  }
}

void Event::victoryEvent(Monster* monster)
{
  if (monster->getHP() <= 0)
  {
    cout << monster->getName() << "을(를) 잡았습니다!" << endl;
  }
}

void Event::defeatEvent(Player* player)
{
  if (player->getHP() <= 0)
  {
    cout << player->getNickName() << "이(가) 죽었습니다..! \n =========== GAME OVER ===========" << endl;
  }
}

void Event::fleeEvent()
{
  cout << "도망쳤습니다...!" << endl;
}


void Event::battleEvent(Player* player)
{
  unique_ptr<Monster> a = make_unique<Gargoyle>();
  auto monster = spawnMonster();

  if (player->getSpeed() >= monster->getSpeed())
  {
    cout << "========= 플레이어 선공 ========= " << endl;
    while (player->getHP() > 0 && monster->getHP() > 0)
    {
      player->attack(monster.get());
      victoryEvent(monster.get());
      monster->attack(player);
      defeatEvent(player);
    }

  }
  else
  {
    cout << "========= 몬스터 선공 ========= " << endl;
    while (player->getHP() > 0 && monster->getHP() > 0)
    {
      player->attack(monster.get());
      victoryEvent(monster.get());
      monster->attack(player);
      defeatEvent(player);
    }
  }
}