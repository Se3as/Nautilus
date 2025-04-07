#ifndef SHIP_H
#define SHIP_H
#include "algorithms.h"
using namespace std; 

class Ship {
	public:
	string name;
	unordered_set<int> elements;
	int life;
	int price;
	virtual bool search_iterations(int num, int& iterations) = 0;
	virtual bool insert_iterations(int num, int& iterations) = 0;
    virtual bool remove_iterations(int num, int& up_points, int& iterations) = 0;
	bool search_element(int num);
    virtual ~Ship() {}
	Ship(string n, int l, int p): name(n), life(l), price(p){}
};
class Ship1 : public Ship{
	public:
	Linked_list* linked_list;
	Ship1(string n, int l, int p): Ship(n, l, p){
		linked_list = new Linked_list();
	}
	bool search_iterations(int num, int& iterations);
	bool insert_iterations(int num, int& iterations);
	bool remove_iterations(int num, int& up_points, int& iterations);
};
class Ship2 : public Ship{
	public:
	Array* array;
	Ship2(string n, int l, int p): Ship(n, l, p){
		array = new Array(200);
	}
	bool search_iterations(int num, int& iterations);
	bool insert_iterations(int num, int& iterations);
	
	bool remove_iterations(int num, int& up_points, int& iterations);
};
class Ship3 : public Ship{
	public:
	Ship3(string n, int l, int p): Ship(n, l, p){
	}
	bool search_iterations(int num, int& iterations);
	bool insert_iterations(int num, int& iterations);
	bool remove_iterations(int num, int& up_points, int& iterations);
};
/*class Ship4 : public Ship{
	public:
	Redblack_tree* redblack_tree;
	Ship4(string n, int l, int p): Ship(n, l, p){
		redblack_tree = new Redblack_tree();
	}
	bool search_iterations(int num, int& iterations){	
		return redblack_tree->search(num,iterations);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return redblack_tree->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return redblack_tree->remove(num, up_points, iterations);
	}
};
class Ship5 : public Ship{
	public:
	B_tree* b_tree;
	Ship5(string n, int l, int p): Ship(n, l, p){
		b_tree = new B_tree();
	}
	bool search_iterations(int num, int& iterations){
		return b_tree->search(num,iterations);
	}
	bool insert_iterations(int num, int& iterations){
		elements.insert(num);
		return b_tree->insert(num,iterations);
	}
	bool remove_iterations(int num, int& up_points, int& iterations){
		return b_tree->remove(num, up_points, iterations);
	}
};*/
class Ship6 : public Ship{
	public:
	Splay_tree* splay_tree;
	Ship6(string n, int l, int p): Ship(n, l, p){
		splay_tree = new Splay_tree();
	}
	bool search_iterations(int num, int& iterations);
	bool insert_iterations(int num, int& iterations);
	bool remove_iterations(int num, int& up_points, int& iterations);
};
#endif