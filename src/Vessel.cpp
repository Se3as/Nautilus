#include "Vessel.h"

int Vessel::select_random(){
    int num = 0;
    bool in_set = false;
    while(!in_set){
        num = rand() % 100 + 1;
        if(search_element(num)){
            in_set = true;
        }
    }
    return num;
}

//PROMARY WEAPON
bool Vessel::search_element(int num){
	return elements.find(num) != elements.end();
}
int Vessel::getLife(){
    return life;
}
void Vessel::setLife(int l){
    life = l;
}
string Vessel::getName(){
    return name;
}
void Vessel::setName(string n){
    name = n;
}

VesselLinkedList::VesselLinkedList(string n, int l, int p): Vessel(n, l, p) {
    linked_list = new Linked_list();
}

bool VesselLinkedList:: search_iterations(int num, int& iterations){	 
    return linked_list->lineal_search(num,iterations);
}
bool VesselLinkedList::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return linked_list->insert(num,iterations);
}
bool VesselLinkedList::remove_iterations(int num, int& up_points, int& iterations){
    int temporal =0;
    bool success = linked_list->remove(num,iterations);
    if(up_points<iterations){
        elements.insert(num);
        linked_list->insert(num,temporal);
        return false;
    }
    elements.erase(num);
    return success;
}



VesselArray::VesselArray(string n, int l, int p): Vessel(n, l, p) {
    array = new Array(200);
}

bool VesselArray::search_iterations(int num, int& iterations){
    int index = 0;
    return array->binary_search(num,iterations,index);
}
bool VesselArray::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return array->insert(num,iterations);
}
bool VesselArray::remove_iterations(int num, int& up_points, int& iterations){
    int temporal =0;
    bool success = array->remove(num,iterations);
    if(up_points<iterations){
        elements.insert(num);
        array->insert(num,temporal);
        return false;
    }
    elements.erase(num);
    return success;
}


//DATA FOR ANALISIS OF ATACKS
bool VesselSet::search_iterations(int num, int& iterations){
    iterations += 1;
    return 1;
}
bool VesselSet::insert_iterations(int num, int& iterations){
    iterations += 1;
    elements.insert(num);
    return 1;
}
bool VesselSet::remove_iterations(int num, int& up_points, int& iterations){
    iterations += 1;
    if(search_element(num)){
        elements.erase(num);
        return 1;
    }
    return 0;
}


VesselRedBlack::VesselRedBlack(string n, int l, int p): Vessel(n, l, p) {
    redblack_tree = new RBTree();
}

bool VesselRedBlack::search_iterations(int num, int& iterations){	
    return redblack_tree->search(num,iterations);
}
bool VesselRedBlack::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return redblack_tree->insert(num,iterations);
}
bool VesselRedBlack::remove_iterations(int num, int& up_points, int& iterations){
    int temporal = 0; 
    bool success = redblack_tree->remove(num,iterations);
    if(up_points<iterations){
        elements.insert(num);
        redblack_tree->insert(num,temporal);
        return false;
    }
    elements.erase(num);
    return success;
}


VesselBTree::VesselBTree(string n, int l, int p): Vessel(n, l, p) {
    b_tree = new BTree(3);
}

bool VesselBTree::search_iterations(int num, int& iterations){
    return b_tree->search(num,iterations);
}
bool VesselBTree::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return b_tree->insert(num,iterations);
}
bool VesselBTree::remove_iterations(int num, int& up_points, int& iterations){
    int temporal = 0; 
    bool success = b_tree->remove(num,iterations);
    if(up_points<iterations){
        elements.insert(num);
        b_tree->insert(num,temporal);
        return false;
    }
    elements.erase(num);
    return success;
}


VesselSplay::VesselSplay(string n, int l, int p): Vessel(n, l, p) {
    splay_tree = new Splay_tree();
}

bool VesselSplay::search_iterations(int num, int& iterations){
    return splay_tree->search(num,iterations);
}
bool VesselSplay::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return splay_tree->insert(num,iterations);
}
bool VesselSplay::remove_iterations(int num, int& up_points, int& iterations){
    int temporal = 0; 
    bool success = splay_tree->remove(num,iterations);
    if(up_points<iterations){
        elements.insert(num);
        splay_tree->insert(num,temporal);
        return false;
    }
    elements.erase(num);
    return success;
}