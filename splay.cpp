#include "splay.h"

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
        //iterations++;
        if (data < root->left->data) {
            //iterations++;
            root->left->left = splay(root->left->left, data, iterations);
            root = rightRotate(root, iterations);
        } else if (data > root->left->data) {
            //iterations++;
            root->left->right = splay(root->left->right, data, iterations);
            if (root->left->right)
                root->left = leftRotate(root->left, iterations);
        }
        return (root->left) ? rightRotate(root, iterations) : root;
    } else {
        if (!root->right)
            return root;
        //iterations++;
        if (data > root->right->data) {
            //iterations++;
            root->right->right = splay(root->right->right, data, iterations);
            root = leftRotate(root, iterations);
        } else if (data < root->right->data) {
            //iterations++;
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
    root = splay(root, data, iterations);
    return (root->data == data);
}

bool Splay_tree::remove(int data, int& iterations) {
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
	