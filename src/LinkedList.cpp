#include "LinkedList.h"

Linked_list::~Linked_list(){
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->right;
        delete curr;
        curr = next;
    }
}

bool Linked_list::lineal_search(int data, int& iterations) {
    Node* curr = head;
    while (curr != NULL) {
        iterations++;
        if (curr->data == data) {
            return true;
        }
        curr = curr->right;
    }
    return false;
}

bool Linked_list::insert(int data, int& iterations) {
    Node* new_node = new Node(data);
    new_node->right = head;
    head = new_node;
    if (end == NULL) {
        end = new_node;
    }
    iterations++;
    return true;
}

bool Linked_list::remove(int data, int& iterations) {
    if (head == NULL) {
        iterations++;
        return false;
    }
    
    if (head->data == data) {
        iterations++;
        Node* temp = head;
        head = head->right;
        delete temp;
        return true;
    }
    
    Node* curr = head;
    while (curr->right != NULL && curr->right->data != data) {
        iterations++;
        curr = curr->right;
    }
    
    if (curr->right != NULL) {
        iterations++;
        Node* temp = curr->right;
        curr->right = curr->right->right;
        delete temp;
        if (curr->right == NULL) {
            end = curr;
        }
        return true;
    }
    
    return false;
}