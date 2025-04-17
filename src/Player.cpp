#include "Player.h"

#include <iostream>
using namespace std;


Player::Player(int p): playerID(p), actionPoints(3), coins(12){
}


int Player::getPlayerID() {
  return playerID;
}

int Player::getActionPoints() {
  return actionPoints;
}

void Player::setActionPoints(int actualPoints) {
  this->actionPoints = actualPoints;
}

bool Player::myTurn(int turn) {
  return playerID == turn ? true : false;
}

void Player::showCoins() {
  cout << coins << endl;
}

bool Player::purchaseCalc(int cost) {

  if (cost > coins)
  {
    std::cout << "Not enough points" << std::endl;
    return false;
  }
  else
  {
    coins -= cost;
    std::cout << "Points deducted: " << cost << std::endl;
    return true;
  }
}

Player::~Player(){
}