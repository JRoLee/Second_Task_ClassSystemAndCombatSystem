#pragma once
#include <string>

using namespace std;

class Monster;

class Player
{
public:
  Player(string jobname,string name,int level, int hp,int mp,
          int power,int defence, int accuracy, int speed);

  virtual void attack(Monster* monster) = 0;
  void printPlayerStatus();

  //getter
  string gentJobName();
  string getNickName();
  int getLevel();
  int getHP();
  int getMP();
  int getPower();
  int getDefence();
  int getAccuracy();
  int getSpeed();

  //setter
  void setNickname(string name);
  void setHP(int value);
  void setMP(int value);
  void setPower(int value);
  void setDefence(int value);
  void setAccuracy(int value);
  void setSpeed(int value);

protected:
  string job_name;
  string nickname;
  int level;
  int HP;
  int MP;
  int power;
  int defence;
  int accuracy;
  int speed;
};

