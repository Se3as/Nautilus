#include "Player.h"
#include <iostream>
#include <string>

class Player {
  private:
    std::string name;
    int actionPoints;
    int money;
    int score;
  public:
    Player();
    Player(std::string);
    std::string getName();
    int getScore(){
        return score;
    }
    void setScore(int){
        std::cout << "Score set to: " << score << std::endl;
        this->score = score;
    }

    ~Player();
};