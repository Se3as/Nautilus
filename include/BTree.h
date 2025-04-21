#pragma once 

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class BTreeNode
{
    int *keys;
    int degree;
    BTreeNode **children;
    int numKeys;
    bool isLeaf;

public:

    BTreeNode(int minDegree, bool isLeafNode);

    void traverse();

    BTreeNode *search(int key, int& iterations);

    int findKey(int key);

    void insertNonFull(int key,int& iterations);

    void splitChild(int index, BTreeNode *child, int& iterations);

    void remove(int key, int& iterations);

    void removeFromLeaf(int index);

    void removeFromNonLeaf(int index, int& iterations);

    int getPred(int index, int& iterations);

    int getSucc(int index, int& iterations);

    void fill(int index);

    void borrowFromPrev(int index);

    void borrowFromNext(int index);

    void merge(int index);

    friend class BTree;
};

class BTree
{
    BTreeNode *root;
    int minDegree;
public:

    BTree(int minDegree)
    {
        root = NULL;
        this->minDegree = minDegree;
    }

    void traverse()
    {
        if (root != NULL) root->traverse();
    }

    BTreeNode* search(int key, int& iterations)
    {
        return (root == NULL) ? NULL : root->search(key, iterations);
    }

    bool insert(int key, int& iterations);

    bool remove(int key, int& iterations);
    
    void printTree() {
        if (root != NULL) {
            std::cout << "Árbol B: ";
            root->traverse();
            std::cout << std::endl;
        }
    }
};