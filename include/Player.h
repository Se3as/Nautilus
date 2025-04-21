#pragma once

#include <iostream>
using namespace std;


class Player {
private:
    int playerID;
    int actions;
    int credits;

public:
    Player(int player);
    ~Player();

    int getID();

    void refreshActions();
    int getActions();
    void deductAction();

    void addCredits();
    int getCredits();
    bool verifyCredit(int cost);
    void spendCredits(int cost);
    

};