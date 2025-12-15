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
    cout << player->getNickName() << "이(가) 죽었습니다..! \n=========== GAME OVER ===========" << endl;
  }
}

void Event::fleeEvent()
{
  cout << "도망쳤습니다...!" << endl;
}

int Event::battleChoice()
{
  int choice;
  cout << "=========== 행동을 선택해 주세요 =========== \n1) 공격 \n2) 상태창 \n3) 도주 \n선택: ";
  cin >> choice;
 
  return choice;
}

void Event::battleEvent(Player* player)
{
  auto monster = spawnMonster(); //몬스터 소환

  if (player->getSpeed() >= monster->getSpeed())
  {
    cout << "=========== 플레이어 선공 ===========" << endl;
    while (player->getHP() > 0 && monster->getHP() > 0)
    {
      switch (battleChoice())
      {
      case 1:
        player->attack(monster.get());
        victoryEvent(monster.get());
        if (monster->getHP() > 0)
        {
          monster->attack(player);
        }
        break;

      case 2:
        statusCompare(player, monster.get());
        break;

      case 3:
        fleeEvent();
        monster->setHP(0);
        break;
      }
    }
  }
  else
  {
    cout << "=========== 몬스터 선공 ===========" << endl;
    monster->attack(player);
    while (player->getHP() > 0 && monster->getHP() > 0)
    {
      switch (battleChoice())
      {
      case 1:
        player->attack(monster.get());
        victoryEvent(monster.get());
        if (monster->getHP() > 0)
        {
          monster->attack(player);
        }
        break;

      case 2:
        statusCompare(player, monster.get());
        break;

      case 3:
        fleeEvent();
        monster->setHP(0);
        break;
      }
    }
  }
  cout << "******* 전투가 끝났습니다! ********" << endl;
  defeatEvent(player);
}

string comparePrint(int a, int b)
{
  if (a > b)
  {
    return ">";
  }
  else if (a < b)
  {
    return "<";
  }
  else
  {
    return "=";
  }
}

void Event::statusCompare(Player* player, Monster* monster)
{
  cout << "-------------------------------" << endl;
  cout << "*" << player->getNickName() << " 능력치" << "         " << "*" << monster->getName() << " 능력치" << endl;
  cout << "HP: " << player->getHP() << "       " << comparePrint(player->getHP(), monster->getHP()) << "      " << "HP: " << monster->getHP() << endl;
  cout << "공격력: " << player->getPower() << "     " << comparePrint(player->getPower(), monster->getPower()) << "     " << "공격력: " << monster->getPower() << endl;
  cout << "방어력: " << player->getDefence() << "     " << comparePrint(player->getDefence(), monster->getDefence()) << "     " << "방어력: " << monster->getDefence() << endl;
  cout << "속도: " << player->getSpeed() << "       " << comparePrint(player->getSpeed(), monster->getSpeed()) << "     " << "속도: " << monster->getSpeed() << endl;
  cout << "-------------------------------" << endl;
}