#include "Terrain.h"

#include <iostream>
using namespace std;

Terrain::Terrain() {
  posX = 0;
  posY = 0;
  hasVessel = false;
}

Terrain::Terrain(int newPosX, int newPosY) {
  posX = newPosX;
  posY = newPosY;
  hasVessel = false;
  underFire = false;

  vessel = nullptr;
}

Terrain::~Terrain() {
  delete vessel;
}

int Terrain::getPosX() {
  return posX;
}

int Terrain::getPosY() {
  return posY;
}
void Terrain::setVessel(string& vesselName) {
  if (vesselName == "venture") {
      vessel = new VesselLinkedList("venture", 100, 3);
  }
  else if (vesselName == "typhon") {
      vessel = new VesselArray("typhon", 100, 12);  
  }
  else if (vesselName == "dugong") {
    vessel = new VesselSet("dugong", 100, 12);  
  }
  else if (vesselName == "camel") {
    vessel = new VesselRedBlack("camel", 100, 12);  
  }
  else if (vesselName == "remora") {
    vessel = new VesselBTree("remora", 100, 12);  
  } 
  else if (vesselName == "winterhalter") {
    vessel = new VesselSplay("winterhalter", 100, 12);  
  }
}
void Terrain::sendPirates(int& num, int& iterations){
  vessel->insert_iterations(num,iterations);
}

void Terrain::callAttack(int& iterations){
  int num = vessel->select_random();
  vessel->search_iterations(num, iterations);
}
void Terrain::shooted(int damage){
  vessel->setLife(vessel->getLife()-damage);
  cout<<"Aqui4"<<vessel->getLife()<<endl;
}

void Terrain::setOccupied() {
  this->hasVessel = true;
}

bool Terrain::isOccupied() {
  return hasVessel;
}

void Terrain::terrainUnderFire(){
    underFire = true;
}

bool Terrain::isUnderFire(){
    return underFire;
}