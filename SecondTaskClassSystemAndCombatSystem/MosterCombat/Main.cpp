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
  int eventChoice = 0;
  string nickname;
  Event event;

  Player* player = nullptr;

  player = event.SetPlayer();
  cout << "축하합니다! " << player->gentJobName() << "으로 전직 하셨습니다!" << endl;
 
  while (true)
  {
    //선택지 출력
    cout << "다음 활동을 선택해 주세요! \n1) 전투 \n2) 상태창 \n3) 모험 종료" << endl;
    cout << "선택: ";
    cin >> eventChoice;
    switch (eventChoice)
    {
    case 1:
      event.battleEvent(player);
      if (player->getHP() <= 0)
      {
        if (player != nullptr)
          delete player;

        return 0;
      }

      break;

    case 2:
      player->printPlayerStatus();
      break;

    case 3:
      cout << "모험을 종료합니다!" << endl;
      if (player != nullptr)
        delete player;

      return 0;
    }
  }
 
  if (player != nullptr)
    delete player;

  return 0;
}
