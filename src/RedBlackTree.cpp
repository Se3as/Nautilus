#include "RedBlackTree.h"

NodeRB::NodeRB(int value)
  : value(value), color("RED"), left(nullptr), right(nullptr), parent(nullptr) {}

RedBlackTree::RedBlackTree()
{
  NIL = new NodeRB(0);
  NIL->color = "BLACK";
  NIL->left = NIL->right = NIL;
  root = NIL;
}

void RedBlackTree::leftRotate(NodeRB* node, int& iterations)
{
  NodeRB* y = node->right;
  node->right = y->left;
  if (y->left != NIL) {
    y->left->parent = node;
  }
  y->parent = node->parent;
  if (node->parent == nullptr) {
    root = y;
  }
  else if (node == node->parent->left) {
    node->parent->left = y;
  }
  else {
    node->parent->right = y;
  }
  y->left = node;
  node->parent = y;
}

void RedBlackTree::rightRotate(NodeRB* node, int& iterations)
{
  NodeRB* y = node->left;
  node->left = y->right;
  if (y->right != NIL) {
    y->right->parent = node;
  }
  y->parent = node->parent;
  if (node->parent == nullptr) {
    root = y;
  }
  else if (node == node->parent->right) {
    node->parent->right = y;
  }
  else {
    node->parent->left = y;
  }
  y->right = node;
  node->parent = y;
}

void RedBlackTree::fixInsert(NodeRB* node, int& iterations)
{
  while (node != root && node->parent->color == "RED") {
    if (node->parent == node->parent->parent->left) {
      NodeRB* uncle = node->parent->parent->right;
      if (uncle->color == "RED") {
        node->parent->color = "BLACK";
        uncle->color = "BLACK";
        node->parent->parent->color = "RED";
        node = node->parent->parent;
      }
      else {
        if (node == node->parent->right) {
          node = node->parent;
          leftRotate(node, iterations);
        }
        node->parent->color = "BLACK";
        node->parent->parent->color = "RED";
        rightRotate(node->parent->parent, iterations);
      }
    }
    else {
      NodeRB* uncle = node->parent->parent->left;
      if (uncle->color == "RED") {
        node->parent->color = "BLACK";
        uncle->color = "BLACK";
        node->parent->parent->color = "RED";
        node = node->parent->parent;
      }
      else {
        if (node == node->parent->left) {
          node = node->parent;
          rightRotate(node, iterations);
        }
        node->parent->color = "BLACK";
        node->parent->parent->color = "RED";
        leftRotate(node->parent->parent, iterations);
      }
    }
  }
  root->color = "BLACK";
}

void RedBlackTree::inorderTraversal(NodeRB* node)
{
  if (node != NIL) {
    inorderTraversal(node->left);
    cout << node->value << " ";
    inorderTraversal(node->right);
  }
}

NodeRB* RedBlackTree::searchTree(NodeRB* node, int value, int& iterations)
{
  iterations++;
  if (node == NIL || value == node->value) {
    return node;
  }
  if (value < node->value) {
    return searchTree(node->left, value, iterations);
  }
  return searchTree(node->right, value, iterations);
}

bool RedBlackTree::insert(int value, int& iterations)
{
  NodeRB* newNode = new NodeRB(value);
  newNode->left = NIL;
  newNode->right = NIL;

  NodeRB* parent = nullptr;
  NodeRB* current = root;
  if (root == NIL) {
    iterations++;
  }
  while (current != NIL) {
    iterations++;
    parent = current;
    if (newNode->value < current->value) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }

  newNode->parent = parent;

  if (parent == nullptr) {
    root = newNode;
  }
  else if (newNode->value < parent->value) {
    parent->left = newNode;
  }
  else {
    parent->right = newNode;
  }

  if (newNode->parent == nullptr) {
    newNode->color = "BLACK";
    return true;
  }

  if (newNode->parent->parent == nullptr) {
    return true;
  }

  fixInsert(newNode, iterations);
  return true;
}

void RedBlackTree::inorder() { inorderTraversal(root); }

bool RedBlackTree::search(int value, int& iterations)
{
  searchTree(root, value, iterations);
  return true;
}
bool RedBlackTree::remove(int num, int& up_points, int& iterations){
  return true;
}