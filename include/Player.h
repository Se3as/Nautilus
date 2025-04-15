#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>


class Player {
  private:
    std::string name;
    int actionPoints;
    int coins;
    int score;
  public:
    Player();
    Player(std::string);
    std::string getName();
    int getScore();
    void setScore(int);
    ~Player();
}

#endif