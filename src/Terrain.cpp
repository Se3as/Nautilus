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