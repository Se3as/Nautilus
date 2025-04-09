#ifndef _BOARD_H
#define _BOARD_H
#include "Game.h"
#include "Node.h"
#include "Player.h"

class Board {
  private:
    int rows;
    int cols;
    Node ** node;

    // zone for player 1
    int player1StartCol;
    int player1EndCol;
    // zone for player 2
    int player2StartCol;
    int player2EndCol;
    bool playerID;  // if false (0) is player 1 else true (1) is player 2

    // int rounds;  // rounds count
    int points; // moneda del juego

    Player* player1;
    Player* player2;

    // void givePoints();
    void _init(int, int, int);
    void battle(bool);
  public:
    Board();
    Board(int, int);
    void runGame();
    int isPositionValid(int, int, bool);
};


#endif