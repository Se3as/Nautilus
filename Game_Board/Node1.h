#ifndef _NODE_H
#define _NODE_H

#include "Vessel.h"

// Stats of every field in the board
class Node {
  private:
    int posX;
    int posY;
    bool isVessel;
    Vessel* vessel;
  public:
    Node();
    Node(int, int);
    int getPosX();
    int getPosY();
    void setIsVessel();
    bool isNodeVessel();
    // It could change
    Vessel* whichVessel(Vessel*);
    // Function to vessel
    // bool vesselUnderAttack(Vessel*);
    ~Node();
};

#endif