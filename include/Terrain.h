#pragma once

#include "Vessel.h"

class Terrain {
    private:
      int posX;
      int posY;
      bool hasVessel;
      bool underFire;

      Vessel* vessel;

    public:
      Terrain();
      Terrain(int, int);
      ~Terrain();
      
      int getPosX();
      int getPosY();
      void setIsVessel();
      bool isNodeVessel();
      void setVessel(string& vesselName);
      Vessel* getVessel();

      void sendPirates(int& num, int& iterations);
      void callAttack(int& iterations);
      void shooted(int damage);
      void terrainUnderFire();
      bool isUnderFire();


      void setOccupied();
      bool isOccupied();

    

      bool vesselUnderAttack(Vessel*);
  };