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

void Player::setActionPoints(int actualPoints) {
  this->actionPoints = actualPoints;
}

void Player::subtractActionPoints() {
  this->actionPoints -= 1;
}

void Player::habilitateTurn() {
  cout << "Entre a habilitar" << endl;
  this->isMyTurn = true;
}

void Player::inhabilitateTurn() {
  cout << "Entre a inhabilidar" << endl;
  this->isMyTurn = false;
}

bool Player::myTurn(int turn) {
  return this->isMyTurn == turn;
}

void Player::addCoins(int coins) {
  cout << "Añadir monedas" << endl;
  this->coins = coins;
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