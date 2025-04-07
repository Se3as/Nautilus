#include "Node.h"

#include <iostream>
using namespace std;

Node::Node() {
  posX = 0;
  posY = 0;
  isVessel = false;
}

Node::Node(int newPosX, int newPosY) {
  posX = newPosX;
  posY = newPosY;
  isVessel = false;
}

Node::~Node() {
  delete vessel;
}

int Node::getPosX() {
  return posX;
}

int Node::getPosY() {
  return posY;
}

void Node::setIsVessel() {
  this->isVessel = true;
}

bool Node::isNodeVessel() {
  return isVessel;
}

// It could change
Vessel* Node::whichVessel(Vessel* vessel) {
  return vessel;
}

// Attibutes of vessel isUnderAttack()
/*
bool Node::vesselUnderAttack(Vessel* vessel) {
  return Vessel->isUnderAttack();
}*/
