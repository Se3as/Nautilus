#include "Player.h"

#include <iostream>
using namespace std;


Player::Player(int p): playerID(p), actionPoints(3), coins(12), isMyTurn(false){
}


int Player::getPlayerID() {
  return playerID;
}

int Player::getActionPoints() {
  return actionPoints;
}

void Player::setActionPoints(int actionPoints) {
  this->actionPoints = actionPoints;
}

void Player::subtractActionPoints() {
  this->actionPoints -= 1;
}

void Player::habilitateTurn() {
  cout << "Entre a habilitar" << endl;
  this->isMyTurn = true;
}

void Player::inhabilitateTurn() {
  cout << "Entre a inhabilitar" << endl;
  this->isMyTurn = false;
}

bool Player::myTurn() {
  return this->isMyTurn;
}

void Player::addCoins(int coins) {
  cout << "Añadir monedas" << endl;
  this->coins += coins;
}

void Player::showCoins() {
  cout << coins << endl;
}

bool Player::enoughCoins(int cost) {
  if (cost > coins) {
    cout << "Not enough coins" << endl;
    return false;
  } else {
    cout << "Enough coins" << endl;
    return true;
  }
}

void Player::purchaseCalc(int cost) {
  this->coins -= cost;
}

Player::~Player(){
}