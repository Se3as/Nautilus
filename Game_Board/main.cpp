#include <iostream>
using namespace std;

#include "Node.h"

int main() {
  const int x = 3;
  const int y = 4;
  Node nodo(x, y);
  cout << "El nodo en la posición (" << nodo.getPosX() << ", " << nodo.getPosY()
    << ")" << endl;
  cout << "El nodo es un barco?" << endl;
  if(nodo.isNodeShip()) {
    cout << "Correcto, el nodo es un barco" << endl;
  } else {
    cout << "Incorrecto, el nodo no es un barco" << endl;
  }
  return 0;
}
