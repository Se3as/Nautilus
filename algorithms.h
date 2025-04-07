#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#define NUM_OF_ELEMENTS 100
#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>


using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class Splay_tree {
	public:
    Node* root;
    Splay_tree() : root(NULL) {}
    Node* rightRotate(Node* x, int& iterations);
    Node* leftRotate(Node* x, int& iterations);
    Node* splay(Node* root, int data, int& iterations);
    bool insert(int data, int& iterations);
	bool search(int data, int& iterations);
    bool remove(int data, int& up_points, int& iterations);
    void preorder(Node* node);
    void inorder(Node* node);
    void print();
};
	
class Linked_list {
	public:
    Node* head;
    Node* end;
    Linked_list() : head(NULL), end(NULL) {}
    ~Linked_list();
    bool lineal_search(int data, int& iterations);
    bool insert(int data, int& iterations);
    bool remove(int data, int& iterations, int& up_points);
};



class Array {
public:
    int* arr;
    int capacity;
    int size;
    Array(int c) : capacity(c), size(0) {
        arr = new int[capacity];
    }
    ~Array();
    bool binary_search(int data, int& iterations, int& index);
    bool insert(int data, int& iterations);
    bool remove(int data, int& iterations, int& up_points);
    void resize();
};
#endif