#pragma once
//includes para la ventana

#include "BTree.h"
#include "SplayTree.h"
#include "RedBlackTree.h"
#include "Array.h"  //cambiar A mayuscula
#include "LinkedList.h"
using namespace std;



class Vessel {
private:
    
     //trabajar en estos set y get
    bool upgrading;
    bool weaponCooldown;

    string name;
   
    int life;
    int price;

public:
    Vessel(string n, int l, int p): name(n), life(l), price(p) {}
    virtual ~Vessel() {}

    bool weaponOnCooldown() const;

    virtual bool search_iterations(int num, int& iterations) = 0;
    virtual bool insert_iterations(int num, int& iterations) = 0;
    virtual bool remove_iterations(int num, int& up_points, int& iterations) = 0;
    
    bool search_element(int num);

    //metodo set
    unordered_set<int> elements;

};



class VesselLinkedList: public Vessel{
private:
    //trabajar en estos set y get
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
    RedBlackTree* redblack_tree;
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