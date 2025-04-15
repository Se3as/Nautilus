#include <iostream>
using namespace std;

#include "Board.h"
#include "Node.h"
#include "Player.h"
#include "Vessel.h"

  /**
   * Currently established costs
   * 
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

Board::Board() {
 _init(0, 0);
}

/**
 * Main del board
 */
void Board::runGame() {
  // Rows and Cols of battle board
  const int rows = 6;
  const int cols = 8;
  const int initial_coins = 120;  // initial coins
  int coins_per_rounds = 30;
  int action_points = 3;

  Board board(rows, cols);

  // Start Battle
  // this->rounds = 1;
  /*
  if (rounds == 1) {
    player1->points += points;
    player2->points += points;
    while (!player1->actionPointOver())
      battle(Player::playerID);

  } else {

  }
  */

}

Board::Board(const int rows, const int cols) {
  _init(rows, cols);
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
    this->Player::playerID = 0;  // Start player 1
    this->player1StartCol = 0;
    this->player1EndCol = cols / 2;
    this->player2StartCol = cols / 2;
    this->player2EndCol = cols;
	}
}

Board::~Board(){
  for (int row = rows - 1; rows >= 0 ; --row) {
    delete [] node[row]; 
  }
  delete [] node;
}
 
void Board::battle(Board *board) {
  if (whoIsPlayer(Player::playerID) == 0) {
    showBoard(board, Player::playerID);
    hideBoard(board, Player::playerID);
  } else {
    hideBoard(board, Player::playerID);
    showBoard(board, Player::playerID);
  }
}

bool Board::whoIsPlayer(bool Player::playerID) {
  return Player::playerID;
}

int Board::isPositionValid(int row, int col) {
  int positionValid = 0;
  if (whoIsPlayer(Player::playerID) == 0) {  // player 1 board side
    positionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
      && col < player1EndCol);
  } else {  // player 2 board side
    positionValid = (int) (0 <= row && 0 <= player2StartCol && row < rows 
      && col < player2EndCol);
  }
  return positionValid;
}

bool Board::attackPositionValid(int row, int col) {
  int attackPositionValid = 0;
  if (whoIsPlayer(Player::playerID) == 0) {  // attack player 2 board side
    attackPositionValid = (int) (0 <= row && 0 <= player2StartCol && row < rows 
      && col < player2EndCol);
  } else {  // attack player 1 board side
    attackPositionValid = (int) (0 <= row && 0 <= player1StartCol && row < rows 
      && col < player1EndCol);
  }
  return attackPositionValid;
}

bool Board::enoughPoints(bool Player::playerID, int cost) {
  bool enoughPoints = 0;
  if (whoIsPlayer(Player::playerID) == 0) {
    // Pre-calculate to know if is enough points
    if (Player::CalculatePoints(cost)) { //Def in Player.cpp
      enoughPoints = true;
    }
  }
  return enoughPoints;
}

void Board::placeVesselClicked() {
  int posX = node.getPosX();
  int posY = node.getPosY();
  if (isPositionValid(posX, posY)) {
    if(node.isNodeVessel()) {
      // spray of vessel place on the board
      player->coins = player->coins - cost;
    }
  }
}

void Board::buyVessel1Clicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 1;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

void Board::buyVessel2Clicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 2;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

void Board::buyVessel3Clicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 3;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

void Board::buyVessel4Clicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 4;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

void Board::buyVessel5Clicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 5;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

void Board::buyVessel6Clicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 6;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

// Suppose Decoy vessel is any of 6 vessels
void Board::buyDecoyClicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 7;
  if (enoughPoints(player, cost)) {
    placeVesselClicked();
  }
}

void Board::buyUpgradePointsBottomClicked() {
  bool player = whoIsPlayer(Player::playerID);
  int cost = 20;
  if (enoughPoints(player, cost)) {
    player->coins = player->coins - cost;
  } 
}

void Board::upgradeVesselClicked() {
  int posX = node.getPosX();
  int posY = node.getPosY();
  if (node.isNodeVessel()) {
    upgradeVessel();
  }
}

void Board::moveVesselBottomClicked() {
  selectPlayerVesselOnBoard();
  selectNodePlace();
  if (selectNodePlace()) {
    moveVessel();
  }
  undoAction();
}

void Board::showBoard(Board *board, bool Player::playerID) {
  if (Player::playerID == 0) {
    for (int i = 0; i < rows; ++i) {
      for (int j = player1StartCol; j < player1EndCol; ++j) {
        window->show(node[i][j]);
      }
    }
  } else {
    for (int i = 0; i < rows; ++i) {
      for (int j = player2StartCol; j < player2EndCol; ++j) {
        window->show(node[i][j]);
      }
    }
  }
}

void Board::hideBoard(Board *board, bool Player::playerID) {
  if (Player::playerID == 0) {
    for (int i = 0; i < rows; ++i) {
      for (int j = player1StartCol; j < player1EndCol; ++j) {
        if (node[i][j].isNodeVessel()) {
          // Vessel detected
          Vessel* vessel;
          if(node[i][j].vesselUnderAttack(vessel)) {
            window->show(node[i][j]);
          } 
        } else {
          window->hide(node[i][j]);
        }      
      }
    }
  } else {
    for (int i = 0; i < rows; ++i) {
      for (int j = player2StartCol; j < player2EndCol; ++j) {
        if (node[i][j].isNodeVessel()) {
          // Vessel detected
          Vessel* vessel;
          if(node[i][j].vesselUnderAttack(vessel)) {
            window->show(node[i][j]);
          } 
        } else {
          window->hide(node[i][j]);
        }
      }
    }
  }
}

// Extra point
// bool vesselUnderAttacked Attribute of vessel
// attacked() --> addSpies()

void Board::addSpiesBottomClicked() {
  if enoughPoints()
    if selectedNodeisVessel()
      if vesselUnderAttack()
        addspies()
}
// bool isVesselAttacked()
// showNode()