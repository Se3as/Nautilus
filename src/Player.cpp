#include "Player.h"



Player::Player(int p): actionPoints(3), coins(12){
}


int Player::getPlayerID() {
  return playerID;
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