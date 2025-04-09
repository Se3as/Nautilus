#ifndef _NODE_H
#define _NODE_H

#include "Vessel.h"

// Stats of every field in the board
class Node {
  private:
    int posX;
    int posY;
    bool isShip;
    Vessel* vessel;
  public:
    Node();
    Node(int, int);
    int getPosX();
    int getPosY();
    bool isNodeShip();
    Vessel whichVessel();
    ~Node();
};

#endif