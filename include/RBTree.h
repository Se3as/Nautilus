#pragma once

#include "Algorithm.h"


enum COLOR { RED, BLACK };

class NodeRB {
public:
    int value;
    COLOR color;
    NodeRB *leftChild, *rightChild, *parentNode;

    NodeRB(int value);

    NodeRB* uncle();
    bool isOnLeft();
    NodeRB* sibling();
    void moveDown(NodeRB* newParent);
    bool hasRedChild();
};

class RBTree {
private:
    NodeRB* rootNode;

    void fixRedRed(NodeRB* currentNode, int& iterations);
    NodeRB* successor(NodeRB* currentNode, int& iterations);
    NodeRB* BSTreplace(NodeRB* currentNode, int& iterations);
    void deleteNode(NodeRB* nodeToDelete, int& iterations);
    void fixDoubleBlack(NodeRB* currentNode, int& iterations);
    void leftRotate(NodeRB* currentNode);
    void rightRotate(NodeRB* currentNode);
    void swapColors(NodeRB* node1, NodeRB* node2);
    void swapValues(NodeRB* node1, NodeRB* node2);

public:
    RBTree();
    NodeRB* getRoot();
    NodeRB* searchNode(int value, int& iterations);
    bool insert(int value, int& iterations);
    bool remove(int value, int& iterations);
    bool search(int value, int& iterations);
};