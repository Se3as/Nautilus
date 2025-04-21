#include "Terrain.h"

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
  decoy = false;
  vessel = nullptr;
}

Terrain::~Terrain() {
  delete vessel;
}

//DELETES VESSEL FROM TERRAINS
void Terrain::vesselNuker() {
  vessel = nullptr;
}

int Terrain::getPosX() {
  return posX;
}

int Terrain::getPosY() {
  return posY;
}

//CREATES VESSEL FOR TERRAIN
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

//USED FOR DEBUFFING
void Terrain::sendPirates(int& num, int& iterations){
  //cout<<vessel->getName()<<" is being filled"<<endl;
  high_resolution_clock::time_point start = high_resolution_clock::now();
  vessel->insert_iterations(num,iterations);
  high_resolution_clock::time_point end = high_resolution_clock::now();
  elapsed = end - start;
  //Log::getInstance().register_insert(iterations, vessel->getName(), elapsed.count());
}

void Terrain::callAttack(int& iterations, int damage){
  cout<<vessel->getName()<<" is attaccking"<<endl;
  int num = vessel->select_random();
  //empezar chrono
  high_resolution_clock::time_point start = high_resolution_clock::now();
  vessel->search_iterations(num, iterations);
  //terminar chrono
  high_resolution_clock::time_point end = high_resolution_clock::now();
  elapsed = end - start;
  //Log::getInstance().register_search(iterations, vessel->getName(), damage, elapsed.count());
}

//HANDLER FOR EVENT OF BEING HIT BY ATACKS
bool Terrain::shooted(int damage) {
  cout<<vessel->getName()<<" is being attaccked"<<endl;
  vessel->setLife(vessel->getLife()-damage);
  cout<<vessel->getLife()<<endl;
  if(vessel->getLife() <= 0){
    delete vessel;
    vessel = nullptr;
    return true;
  }
  return false;
}

//HANDLER FOR UPGRADING VESSLES
bool Terrain::callUpgrade(int& iterations, int& upPoints){
  //cout<<vessel->getName()<<" is being upgrading"<<endl;
  //cout<<vessel->getName()<<endl;
  int num = vessel->select_random();
  //empezar chrono
  high_resolution_clock::time_point start = high_resolution_clock::now();
  return vessel->remove_iterations(num,upPoints,iterations);
  //terminar chrono
  high_resolution_clock::time_point end = high_resolution_clock::now();
  elapsed = end - start;
  //Log::getInstance().register_remove(iterations, vessel->getName(), elapsed.count());
}

duration<double> Terrain::getElapsed(){
  return elapsed;
}

string Terrain::getVesselName(){
  return vessel->getName();
}
Vessel* Terrain::getVessel(){
  return vessel;
}
void Terrain:: setDecoy(bool d){
  decoy = d;
}
bool Terrain::getDecoy(){
  return decoy;
}
void Terrain::setNameDecoy(string nD){
  nameDecoy = nD;
}
string Terrain:: getNameDecoy(){
  return nameDecoy;
}
void Terrain::setMovingVessel(Vessel* v){
  vessel = v;
}
void Terrain::setOccupied(bool s) {
  this->hasVessel = s;
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