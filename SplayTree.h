#include "algorithms.h"

class Splay_tree {
	public:
    Node* root;
    Splay_tree() : root(NULL) {}
    Node* rightRotate(Node* x, int& iterations);
    Node* leftRotate(Node* x, int& iterations);
    Node* splay(Node* root, int data, int& iterations);
    bool insert(int data, int& iterations);
	bool search(int data, int& iterations);
    bool remove(int data, int& iterations);
    void preorder(Node* node);
    void inorder(Node* node);
    void print();
};