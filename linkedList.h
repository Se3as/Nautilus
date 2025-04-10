#include "algorithms.h"

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
