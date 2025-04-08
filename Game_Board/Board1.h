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

    // TODO: give points every round played
    // void givePoints();
    /**
     * @brief Create a matrix of battle
     * @param rows Rows count of matrix
     * @param cols Cols count of matrix
     */
    void _init(int, int);
    /**
     * @brief Verific if position selected of the board
     * @param row Position x of node to verific
     * @param col Position y of node to verific
     * @return 
     * 0 if position is not valid
     * 1 if position is valid
     */
    int isPositionValid(int, int);
    /**
     * @brief Verific who is the player playing the game
     * @param playerID Player ID to know who is the player
     * @return Current player ID
     */
    bool whoIsPlayer(bool);
  public:
    /**
     * @brief Constructor of board empty
     */
    Board();
    /**
     * @brief Constructor of board with rows and cols
     * @param rows Rows count to create a board
     * @param cols Cols count to create a board
     */
    Board(int, int);
    /**
     * @brief Program main of game 
     */
    void runGame();
    /**
     * @brief Destructor of board
     */
    ~Board();
  
    // actions for players
    /**
     * @brief Start 
     */
    void battle(Board*);
    void attackClicked();
    void buyVesselClicked();
    void buyUpgradePointsClicked();
    void upgradeVesselClicked();
    void moveVesselClicked();
    
    bool attackPositionValid(int, int);
    bool enoughPoints(bool, int);

    void showBoard(Board*, bool);
    void hideBoard(Board*, bool);
    };
#endif