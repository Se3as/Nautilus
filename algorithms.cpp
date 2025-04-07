
#include "algorithms.h"

using namespace std;


Node* Splay_tree::rightRotate(Node* x, int& iterations) {
    std::cout << "RightRotate at node " << x->data << std::endl;
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* Splay_tree::leftRotate(Node* x, int& iterations) {
    std::cout << "LeftRotate at node " << x->data << std::endl;
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* Splay_tree::splay(Node* root, int data, int& iterations) {
    iterations++;
    if (!root || root->data == data)
        return root;
        std::cout << "Splay at node " << root->data << std::endl;
    if (data < root->data) {
        if (!root->left)
            return root;
        iterations++;
        if (data < root->left->data) {
            iterations++;
            root->left->left = splay(root->left->left, data, iterations);
            root = rightRotate(root, iterations);
        } else if (data > root->left->data) {
            iterations++;
            root->left->right = splay(root->left->right, data, iterations);
            if (root->left->right)
                root->left = leftRotate(root->left, iterations);
        }
        return (root->left) ? rightRotate(root, iterations) : root;
    } else {
        if (!root->right)
            return root;
        iterations++;
        if (data > root->right->data) {
            iterations++;
            root->right->right = splay(root->right->right, data, iterations);
            root = leftRotate(root, iterations);
        } else if (data < root->right->data) {
            iterations++;
            root->right->left = splay(root->right->left, data, iterations);
            if (root->right->left)
                root->right = rightRotate(root->right, iterations);
        }
        return (root->right) ? leftRotate(root, iterations) : root;
    }
}
bool Splay_tree::insert(int data, int& iterations) {
    
    std::cout << "Insert called for " << data << std::endl;
    if (!root) {
        root = new Node(data);
        iterations++;
        return true;
    }

    root = splay(root, data, iterations);
    
    if (root->data == data)
        return false;
    
    Node* newNode = new Node(data);
    if (data < root->data) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    root = newNode;
    return true;
}
bool Splay_tree::search(int data, int& iterations) {
    iterations++;
    if (!root) return false;
    std::cout << "Search called for " << data << std::endl;
    root = splay(root, data, iterations);
    return (root->data == data);
}

bool Splay_tree::remove(int data, int& up_points, int& iterations) {
    iterations++;
    if (!root)
        return false;
    
    root = splay(root, data, iterations);
    if (root->data != data)
        return false;
    
    Node* temp;
    if (!root->left) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, data, iterations);
        root->right = temp->right;
    }
    delete temp;
    return true;
}	

void Splay_tree::preorder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
void Splay_tree::inorder(Node* node) {
    if (!node) return;  
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void Splay_tree::print() {
    cout<< "Inorder"<< endl;
    inorder(root);
    std::cout << std::endl;
    cout<< "Preorder"<< endl;
    preorder(root);
    std::cout << std::endl;

}
	

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

bool Linked_list::remove(int data, int& iterations, int& up_points) {
    if (head == NULL) {
        iterations++;
        return false;
    }

    if (head->data == data) {
        iterations++;
        if (up_points >= iterations) {
            Node* temp = head;
            head = head->right;
            delete temp;
            return true;
        }
        return false;
    }

    Node* curr = head;
    while (curr->right != NULL && curr->right->data != data) {
        iterations++;
        curr = curr->right;
    }

    if (curr->right != NULL) {
        iterations++;
        if (up_points >= iterations) {
            Node* temp = curr->right;
            curr->right = curr->right->right;
            delete temp;
            if (curr->right == NULL) {
                end = curr;
            }
            return true;
        }
    }
    return false;
}


Array::~Array() {
    delete[] arr;
}

bool Array::binary_search(int data, int& iterations, int& index) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        iterations++;

        if (arr[mid] == data) {
            index = mid;
            return true;
        }
        if (arr[mid] < data) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    index = left;
    return false;
}

bool Array::insert(int data, int& iterations) {
    if (size == capacity) {
        resize();
    }
    int index;
    binary_search(data, iterations, index);

    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
        iterations++;
    }
    
    arr[index] = data;
    size++;
    iterations++;

return true;
}

bool Array::remove(int data, int& iterations, int& up_points) {
    int index;
    if (!binary_search(data, iterations, index)) {
        return false;
    }

    for (int i = index; i < size - 1; i++) {
        iterations++;
        if (up_points >= iterations) {
            arr[i] = arr[i + 1];
        }
    }
    size--;
    return true;
}
void Array::resize() {
    capacity *= 2;
    int* newArr = new int[capacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}
