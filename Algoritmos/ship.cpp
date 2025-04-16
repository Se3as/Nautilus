
#include "ship.h"

bool Ship::search_element(int num){
	return elements.find(num) != elements.end();
}
bool Ship1:: search_iterations(int num, int& iterations){	 
    return linked_list->lineal_search(num,iterations);
}
bool Ship1::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return linked_list->insert(num,iterations);
}
bool Ship1::remove_iterations(int num, int& up_points, int& iterations){
    return linked_list->remove(num, up_points, iterations);
}

bool Ship2::search_iterations(int num, int& iterations){
    int index = 0;
    return array->binary_search(num,iterations,index);
}
bool Ship2::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return array->insert(num,iterations);
}
bool Ship2::remove_iterations(int num, int& up_points, int& iterations){
    return array->remove(num, up_points, iterations);
}


bool Ship3::search_iterations(int num, int& iterations){
    iterations += 1;
    return 1;
}
bool Ship3::insert_iterations(int num, int& iterations){
    iterations += 1;
    elements.insert(num);
    return 1;
}
bool Ship3::remove_iterations(int num, int& up_points, int& iterations){
    iterations += 1;
    if(search_element(num)){
        elements.erase(num);
        return 1;
    }
    return 0;
}

bool Ship4::search_iterations(int num, int& iterations){	
    return redblack_tree->search(num,iterations);
}
bool Ship4::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return redblack_tree->insert(num,iterations);
}
bool Ship4::remove_iterations(int num, int& up_points, int& iterations){
    return true;
}
/*
    int temporal = 0; 
    bool success = b_tree->remove(num,iterations);
    if(up_points<iterations){
        elements.insert(num);
        b_tree->insert(num,temporal);
        return false;
    }
    elements.erase(num);
    return success;
}*/


bool Ship5::search_iterations(int num, int& iterations){
    return b_tree->search(num,iterations);
}
bool Ship5::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return b_tree->insert(num,iterations);
}
bool Ship5::remove_iterations(int num, int& up_points, int& iterations){
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

bool Ship6::search_iterations(int num, int& iterations){
    return splay_tree->search(num,iterations);
}
bool Ship6::insert_iterations(int num, int& iterations){
    elements.insert(num);
    return splay_tree->insert(num,iterations);
}
bool Ship6::remove_iterations(int num, int& up_points, int& iterations){
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
