#include "Player.h"


Player::Player(int player): playerID(player), actions(3), credits(12){}



int Player::getID(){
  return playerID;
}



void Player::refreshActions(){
  actions = 3;
}

int Player::getActions(){
  return actions;
}

void Player::deductAction(){
  if(actions > 0){
    actions = actions - 1;
  }
  cout<<"action deducted, remaining: ";
  cout<<actions<<endl;
}



void Player::addCredits(){
  this->credits = credits + 3;
}

int Player::getCredits(){
  return credits;
}

bool Player::verifyCredit(int cost){
  if(credits >= cost){
    cout<<"purchase possible"<<endl;
    return true;
  } else {
    return false;
  }
  
}

void Player::spendCredits(int cost){
  if(credits >= cost){
    credits = credits - cost;
  }
  cout<<"credits deducted, remaining: ";
  cout<<credits<<endl;
}


Player::~Player(){}