#include <iostream>
#include "Event.h"
#include "Player.h"
#include "Monster.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Goblin.h"
#include "Gargoyle.h"
#include "Orc.h"

using namespace std;

int main()
{
  srand((unsigned)time(nullptr));
  string jobs[] = { "전사","마법사","도적","궁수" };
  int job_choice = 0;
  int eventChoice = 0;
  string nickname;
  Event event;

  Player* player = nullptr;

  cout << "* 닉네임을 입력해주세요: ";
  cin >> nickname;

  cout << "<전직 시스템>" << endl;
  cout << nickname << "님, 환영합니다!" << endl;
  cout << "* 원하시는 직업을 선택해주세요." << endl;

  for (int i = 0; i < 4; i++)
  {
    cout << (i + 1) << ". " << jobs[i] << endl;
  }
  
  cout << "선택: ";
  cin >> job_choice;

  switch (job_choice)
  {
  case 1:
    player = new Warrior(nickname);
    break;
  case 2:
    player = new Magician(nickname);
    break;
  case 3:
    player = new Thief(nickname);
    break;
  case 4:
    player = new Archer(nickname);
    break;
  default:
    cout << "잘못된 입력입니다." << endl;
    return 1;
  }

  cout << "축하합니다! " << player->gentJobName() << "으로 전직 하셨습니다!" << endl;
 
  while (true)
  {
    //선택지 출력
    cout << "다음 활동을 선택해 주세요! \n1) 전투 \n2) 상태창 비교 \n3) 모험 종료" << endl;
    cout << "선택: ";
    cin >> eventChoice;
    switch (eventChoice)
    {
    case 1:
      event.battleEvent(player);
      if (player->getHP() <= 0)
      {
        return 0;
      }
      break;

    case 2:
      player->printPlayerStatus();
      break;

    case 3:
      cout << "모험을 종료합니다!" << endl;
      
      return 0;
    }
  }
 
 
  if (player != nullptr)
    delete player;

  return 0;
}
