#pragma once

#include "Algorithm.h"

// Estructura de un nodo en el árbol rojo-negro
struct NodeRB {
  int value;               // Valor almacenado en el nodo
  std::string color;       // Color del nodo (RED o BLACK)
  NodeRB* left;          // Hijo izquierdo
  NodeRB* right;         // Hijo derecho
  NodeRB* parent;        // Padre del nodo

  NodeRB(int value);
};

// Clase que representa un Árbol Rojo-Negro
class RedBlackTree {
public:
  NodeRB* root;          // Raíz del árbol
  NodeRB* NIL;           // Nodo NIL (nulo) que se utiliza en los nodos vacíos

  RedBlackTree();           // Constructor del árbol

  // Funciones públicas de rotación
  void leftRotate(NodeRB* node, int& iterations);
  void rightRotate(NodeRB* node, int& iterations);
  bool remove(int num, int& up_points, int& iterations);
  // Función para arreglar la inserción en el árbol
  void fixInsert(NodeRB* node, int& iterations);

  // Función para recorrer el árbol en orden
  void inorderTraversal(NodeRB* node);

  // Función de búsqueda en el árbol
  NodeRB* searchTree(NodeRB* node, int value, int& iterations);

  // Funciones públicas de la clase RedBlackTree
  bool insert(int value, int& iterations);    // Inserción de nodo
  void inorder();                                     // Realiza un recorrido en orden

  bool search(int value, int& iterations);   // Búsqueda de un valor en el árbol
};