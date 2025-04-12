#include "Player.h"
#include <iostream>
#include <string>

class Player {
  private:
    bool playerID;
    int actionPoints;
    int coins;
    int score;
  public:
    Player(int numJugador){
        if(int numJugador =! 1){ {
            playerID = true;
        } else {
            playerID = 0;
        }
        this->playerID = false;
        this->actionPoints = 0;
        this->coins = 0;
        this->score = 0;
    }
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
    
    bool calculatePoints(cost){

        if (cost > coins) {
            std::cout << "Not enough points" << std::endl;
            return false;
        } else {
            coins -= cost;
            std::cout << "Points deducted: " << cost << std::endl;
            return true;
        }


    }
    
    



    
    
}