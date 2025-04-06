#include <iostream>
using namespace std;

#include "Board.h"
#include "Node.h"
#include "Player.h"

Board::Board() {
 _init(0, 0, 0);
}

/**
 * Main del board
 */
void Board::runGame() {
  // Filas y Columnas fijas
  const int rows = 8;
  const int cols = 12;
  const int coins_initial = 120;  // coins initial
  int coins = 30;
  int action_points = 3;
  /**
   * Upgrade cost: 20
   * 
   * Spies cost: 10
   * 
   * Vessel cost: 
   * Decoy: 10
   * Set: 120
   * Splay: 40
   * List: 20
   * Array: 60
   * Red-Black tree: 100
   * Btree: 80
   */
  Board board(rows, cols, points);

  // Start Battle
  this->rounds = 1;
  /*
  if (rounds == 1) {
    player1->points += points;
    player2->points += points;
    while (!player1->actionPointOver())
      battle(playerID);

  } else {

  }
  */

}

Board::Board(const int rows, const int cols) {
  _init(rows, cols, points);
}

void Board::_init(const int rows, const int cols) {
  node = 0;
  this->rows = rows;
  this->cols = cols;
  if(rows > 0 && cols > 0) {
    node = new Node * [rows];
		for(int row = 0; row < rows ; ++row) {
      node[row] = new Node[cols];
		   for(int col = 0; col < cols; ++col) {
        node[row][col] = Node(row, col);
      }
		}
		this->rows = rows;
		this->cols = cols;
    this->playerID = 0;
    if (cols % 2 == 0) {
      this->player1StartCol = 0;
      this->player1EndCol = cols / 2;
      this->player2StartCol = cols / 2;
      this->player2EndCol = cols;
    } else {
      cerr << "Error: Cols must be odd numbers" << endl;
    }
	}
}

Board::~Board(){
  for(int row = rows - 1; rows >= 0 ; --row){
    delete [] node[row]; 
  }
  delete [] node;
}
 
void Board::battle(bool playerID) {
  if (whoIsPlayer(playerID)) {
    player1->showBoard();
    player2->hideBoard();
  } else {
    player1->hideBoard();   
    player2->showBoard();
  }
}

bool whoIsPlayer(bool playerID) {
  return playerID;
}

int Board::isPositionValid(int row, int col, bool playerID) {
  int positionValid = 0;
  if(whoIsPlayer(playerID)) {
    positionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
      && col < player1EndCol);
  } else {
    positionValid = (int) (0 <= row && 0 <= player2StartCol && row < rows 
      && col < player2EndCol);
  }
  return positionValid;
}

// attackPositionValid()
// attackClicked()
// addShipClicked()
// enoughPoints()
// placeShipOnBoardClicked()
// buyUpgradePointsClicked()
// upgradeShipClicked()
// showBoard(whoIsPlayer())
// hideBoard(whoIsPlayer())
// moveShipClicked()

// Extra point
// bool vesselUnderAttacked() Attribute of vessel
// attacked() --> addSpies()
// bool isVesselAttacked()
// showNode()