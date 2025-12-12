#include <iostream>
#include "Player.h"

void Player::printPlayerStatus()
{
  cout << "-------------------------------" << endl;
  cout << "* 현재 능력치" << endl;
  cout << "닉네임: " << nickname << endl;
  cout << "Lv. " << level << endl;
  cout << "HP: " << HP << endl;
  cout << "MP: " << MP << endl;
  cout << "공격력: " << power << endl;
  cout << "방어력: " << defence << endl;
  cout << "정확도: " << accuracy << endl;
  cout << "속도: " << speed << endl;
  cout << "-------------------------------" << endl;
}

//getter
string Player::gentJobName() { return job_name; }
string Player::getNickName() { return nickname; }
int Player::getLevel() { return level; }
int Player::getHP() { return HP; }
int Player::getMP() { return MP; }
int Player::getPower() { return power; }
int Player::getDefnece() { return defence; }
int Player::getAccuracy() { return accuracy; }
int Player::getSpeed() { return speed; }

//setter
void Player::setNickname(string name) { nickname = name; }
void Player::setHP(int value) { HP = value; }
void Player::setMP(int value) { MP = value; }
void Player::setPower(int value) { power = value; }
void Player::setDefence(int value) { defence = value; }
void Player::setAccuracy(int value) { accuracy = value; }
void Player::setSpeed(int value) { speed = value; }