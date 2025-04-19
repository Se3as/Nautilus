#pragma once

#include <iostream>



class Player {
private:
    int playerID;
    int actionPoints;
    int coins;
    bool isMyTurn;

public:
    Player(int p);
    ~Player();
    int getPlayerID();

    int getActionPoints();
    void setActionPoints(int actionPoints);
    void subtractActionPoints();

    void habilitateTurn();
    void inhabilitateTurn();
    bool myTurn();

    void addCoins(int coins);
    void showCoins();

    bool enoughCoins(int cost);
    void purchaseCalc(int cost);
};