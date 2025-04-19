#pragma once

#include "Vessel.h"

class Terrain {
    private:
      int posX;
      int posY;
      bool hasVessel;
      bool underFire;
      bool decoy;
      Vessel* vessel;

    public:
      Terrain();
      Terrain(int, int);
      ~Terrain();
      
      void vesselNuker();

      int getPosX();
      int getPosY();
      void setIsVessel();
      bool isNodeVessel();
      void setVessel(string& vesselName);
      Vessel* getVessel();

      void sendPirates(int& num, int& iterations);
      void callAttack(int& iterations, int damage);
      bool shooted(int damage);
      bool callUpgrade(int& iterations, int& upPoints);

      void setDecoy(bool d);
      bool getDecoy();
      void terrainUnderFire();
      bool isUnderFire();

      void setMovingVessel(Vessel* v);
      
      string getVesselName();

      void setOccupied(bool s);
      bool isOccupied();

    

      bool vesselUnderAttack(Vessel*);
  };