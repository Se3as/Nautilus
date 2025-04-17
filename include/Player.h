#pragma once

#include <iostream>



class Player {
private:
  int playerID;
  int actionPoints;
  int coins;

public:
  Player(int p);
  ~Player();
    
  int getScore();
  void setScore(int p);

  int getPlayerID();

  bool purchaseCalc(int cost);

};