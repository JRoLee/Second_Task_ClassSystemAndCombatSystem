#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Event.h"
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include "Goblin.h"
#include "Gargoyle.h"
#include "Orc.h"
using namespace std;

shared_ptr<Monster> Event::spawnMonster()
{
  int rNum = rand() % 100 + 1;
  
  if (rNum >= 90)
  {
    cout << "!!!!!!!!!! 매우 강력한 적 가고일을 만났습니다. !!!!!!!!!!" << endl;
    return make_shared<Gargoyle>();
  }
  else if (rNum >= 60)
  {
    cout << "********** 강력한 적 오크를 만났습니다. **********" << endl;
    return make_shared<Orc>();
  }
  else
  {
    cout << "----------- 적 고블린을 만났습니다. -----------" << endl;
    return make_shared<Goblin>();
  }
}

void Event::victoryEvent(shared_ptr<Monster> monster)
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

void Event::battleChoice(Player* player, shared_ptr<Monster> monster)
{
  int choice;
  
  while (player->getHP() > 0 && monster->getHP() > 0)
  {
    cout << "=========== 행동을 선택해 주세요 =========== \n1) 공격 \n2) 상태창 비교 \n3) 도주 \n선택: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      player->attack(monster);
      victoryEvent(monster);
      if (monster->getHP() > 0)
      {
        monster->attack(player);
      }
      break;

    case 2:
      statusCompare(player, monster);
      break;

    case 3:
      fleeEvent();
      monster->setHP(0);
      break;

    default :
      cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
      break;
    }
  }
}

void Event::battleEvent(Player* player)
{
  auto monster = spawnMonster(); //몬스터 소환
  //shared_ptr<Monster> monster = make_shared<Gargoyle>;

  if (player->getSpeed() >= monster->getSpeed())
  {
    cout << "=========== 플레이어 선공 ===========" << endl;
    battleChoice(player, monster);
  }
  else
  {
    cout << "=========== 몬스터 선공 ===========" << endl;
    monster->attack(player);
    battleChoice(player, monster);
  }
  cout << "******* 전투가 끝났습니다! ********" << endl;
  defeatEvent(player);
}

Player* Event::SetPlayer()
{
  string jobs[] = { "전사","마법사","도적","궁수" };
  int job_choice = 0;
  string nickname;

  cout << "* 닉네임을 입력해주세요: ";
  cin >> nickname;

  cout << "<전직 시스템>" << endl;
  cout << nickname << "님, 환영합니다!" << endl;
  cout << "* 원하시는 직업을 선택해주세요." << endl;

  for (int i = 0; i < 4; i++)
  {
    cout << (i + 1) << ". " << jobs[i] << endl;
  }

  while (true)
  {
    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice)
    {
    case 1:
      return new Warrior(nickname);
    case 2:
      return new Magician(nickname);
    case 3:
      return new Thief(nickname);
    case 4:
      return new Archer(nickname);
    default:
      cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
      break;
    }
  }
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

void Event::statusCompare(Player* player, shared_ptr<Monster> monster)
{
  cout << "-------------------------------" << endl;
  cout << "*" << player->getNickName() << " 능력치" << "         " << "*" << monster->getName() << " 능력치" << endl;
  cout << "HP: " << player->getHP() << "       " << comparePrint(player->getHP(), monster->getHP()) << "      " << "HP: " << monster->getHP() << endl;
  cout << "공격력: " << player->getPower() << "     " << comparePrint(player->getPower(), monster->getPower()) << "     " << "공격력: " << monster->getPower() << endl;
  cout << "방어력: " << player->getDefence() << "     " << comparePrint(player->getDefence(), monster->getDefence()) << "     " << "방어력: " << monster->getDefence() << endl;
  cout << "속도: " << player->getSpeed() << "       " << comparePrint(player->getSpeed(), monster->getSpeed()) << "     " << "속도: " << monster->getSpeed() << endl;
  cout << "-------------------------------" << endl;
}