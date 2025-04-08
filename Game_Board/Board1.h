#ifndef _BOARD_H
#define _BOARD_H
#include "Game.h"
#include "Node.h"
#include "Player.h"

// command of compile the program
// g++ -Iinclude src/*.cpp -o nautilus -lfltk -lfltk_images -lSDL2 -lSDL2_mixer
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
     * @brief Main program of game 
     */
    void runGame();

    /**
     * @brief Destructor of board
     */
    ~Board();
  
    // actions for players
    /**
     * @brief Decide which player start the game
     * @param board Need a board to know where to start
     */
    void battle(Board*);
    
    /**
     * @brief Buy vessel 1 bottom and do the action
     */
    void buyVessel1Clicked();

    /**
     * @brief Buy vessel 2 bottom and do the action
     */
    void buyVessel2Clicked();

    /**
     * @brief Buy vessel 3 bottom and do the action
     */
    void buyVessel3Clicked();

    /**
     * @brief Buy vessel 4 bottom and do the action
     */
    void buyVessel4Clicked();

    /**
     * @brief Buy vessel 5 bottom and do the action
     */
    void buyVessel5Clicked();

    /**
     * @brief Buy vessel 6 bottom and do the action
     */
    void buyVessel6Clicked();

    /**
     * @brief Buy decoy bottom and do the action
     */
    void buyDecoyClicked();

    /**
     * @brief Buy upgrade points bottom
     */
    void buyUpgradePointsBottomClicked();

    /**
     * @brief Upgrade vessel bottom and do the action
     */
    void upgradeVesselBottomClicked();

    /**
     * @brief Move vessel bottom and do the action
     */
    void moveVesselBottomClicked();
    
    /**
     * @brief Check attack position is valid
     * @param row Position row of enemy board
     * @param col Position col of enemy board
     * @return 
     * 0 if is not valid
     * 1 if is valid
     */
    bool attackPositionValid(int, int);

    /**
     * @brief Check player points
     * @param playerID Which player current play
     * @param coins Player current coins
     * @return
     * 0 if is not enough
     * 1 if is enough
     */
    bool enoughPoints(bool, int);

    /**
     * @brief Verific place vessel of the player
     */
    void placeVesselClicked();

    /**
     * @brief Show half of the board in current player
     * @param board Which board to apply
     * @param playerID Who is the player
     */
    void showBoard(Board*, bool);

    /**
     * @brief Hide half of the board the other player
     * @param board Which board to apply
     * @param playerID Who is the player
     */
    void hideBoard(Board*, bool);
    };

    void addSpiesBottomClicked();
#endif