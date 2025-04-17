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
    int getPlayerID();

    int getActionPoints();
    void setActionPoints(int actualPoints);

    bool myTurn(int turn);
    void showCoins();

    bool purchaseCalc(int cost);

};