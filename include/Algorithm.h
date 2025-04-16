#pragma once

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

//bool search_element(int num);