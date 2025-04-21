#pragma once
//includes para la ventana

#include "BTree.h"
#include "SplayTree.h"
#include "RBTree.h"
#include "Array.h"  //cambiar A mayuscula
#include "LinkedList.h"
using namespace std;



class Vessel {
private:

    bool upgrading;
    bool weaponCooldown;

    string name;
   
    int life;
    int price;

public:
    Vessel(string n, int l, int p): name(n), life(l), price(p) {}
    virtual ~Vessel() {}

    virtual bool search_iterations(int num, int& iterations) = 0;
    virtual bool insert_iterations(int num, int& iterations) = 0;
    virtual bool remove_iterations(int num, int& up_points, int& iterations) = 0;
    
    int getLife();
    void setLife(int l);
    string getName();
    void setName(string n);
    int select_random();
    bool search_element(int num);

    unordered_set<int> elements;
};


class VesselLinkedList: public Vessel{
private:
    
    Linked_list* linked_list;
    
public:
    VesselLinkedList(string n, int l, int p);

	bool search_iterations(int num, int& iterations);
	bool insert_iterations(int num, int& iterations);
	bool remove_iterations(int num, int& up_points, int& iterations);
};



class VesselArray : public Vessel {
public:
    Array* array;
    VesselArray(string n, int l, int p);
    bool search_iterations(int num, int& iterations);
    bool insert_iterations(int num, int& iterations);
    bool remove_iterations(int num, int& up_points, int& iterations);
};
    
class VesselSet : public Vessel {
public:
    VesselSet(string n, int l, int p): Vessel(n, l, p) {}
    bool search_iterations(int num, int& iterations);
    bool insert_iterations(int num, int& iterations);
    bool remove_iterations(int num, int& up_points, int& iterations);
};
    
class VesselRedBlack : public Vessel {
public:
    RBTree* redblack_tree;
    VesselRedBlack(string n, int l, int p);
    bool search_iterations(int num, int& iterations);
    bool insert_iterations(int num, int& iterations);
    bool remove_iterations(int num, int& up_points, int& iterations);
};

class VesselBTree : public Vessel {
public:
    BTree* b_tree;
    VesselBTree(string n, int l, int p);
    bool search_iterations(int num, int& iterations);
    bool insert_iterations(int num, int& iterations);
    bool remove_iterations(int num, int& up_points, int& iterations);
};

class VesselSplay : public Vessel {
public:
    Splay_tree* splay_tree;
    VesselSplay(string n, int l, int p);
    bool search_iterations(int num, int& iterations);
    bool insert_iterations(int num, int& iterations);
    bool remove_iterations(int num, int& up_points, int& iterations);
};