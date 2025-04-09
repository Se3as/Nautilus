#include "Node.h"

Node::Node() {
  posX = 0;
  posY = 0;
  isShip = false;
}

Node::Node(int newPosX, int newPosY) {
  posX = newPosX;
  posY = newPosY;
  isShip = false;
}

Node::~Node() {
  
}

int Node::getPosX() {
  return posX;
}

int Node::getPosY() {
  return posY;
}

bool Node::isNodeShip() {
  return isShip;
}

Vessel Node::whichVessel() {
  return &vessel;
}
