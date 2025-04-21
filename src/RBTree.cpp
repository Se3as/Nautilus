#include "RBTree.h"
using namespace std;


NodeRB::NodeRB(int value) : value(value) {
    parentNode = leftChild = rightChild = NULL;
    color = RED;
}

NodeRB* NodeRB::uncle() {
    if (parentNode == NULL || parentNode->parentNode == NULL)
        return NULL;

    if (parentNode->isOnLeft())
        return parentNode->parentNode->rightChild;
    else
        return parentNode->parentNode->leftChild;
}

bool NodeRB::isOnLeft() {
    return this == parentNode->leftChild;
}

NodeRB* NodeRB::sibling() {
    if (parentNode == NULL)
        return NULL;

    return isOnLeft() ? parentNode->rightChild : parentNode->leftChild;
}

void NodeRB::moveDown(NodeRB* newParent) {
    if (parentNode != NULL) {
        if (isOnLeft()) {
            parentNode->leftChild = newParent;
        } else {
            parentNode->rightChild = newParent;
        }
    }
    newParent->parentNode = parentNode;
    parentNode = newParent;
}

bool NodeRB::hasRedChild() {
    return (leftChild != NULL && leftChild->color == RED) ||
           (rightChild != NULL && rightChild->color == RED);
}

// RBTree class implementations

RBTree::RBTree() {
    rootNode = NULL;
}

NodeRB* RBTree::getRoot() {
    return rootNode;
}

void RBTree::swapColors(NodeRB* node1, NodeRB* node2) {
    COLOR temp = node1->color;
    node1->color = node2->color;
    node2->color = temp;
}

void RBTree::swapValues(NodeRB* node1, NodeRB* node2) {
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void RBTree::leftRotate(NodeRB* currentNode) {
    NodeRB* newParentNode = currentNode->rightChild;
    if (currentNode == rootNode)
        rootNode = newParentNode;

    currentNode->moveDown(newParentNode);
    currentNode->rightChild = newParentNode->leftChild;
    if (newParentNode->leftChild != NULL)
        newParentNode->leftChild->parentNode = currentNode;

    newParentNode->leftChild = currentNode;
}

void RBTree::rightRotate(NodeRB* currentNode) {
    NodeRB* newParentNode = currentNode->leftChild;
    if (currentNode == rootNode)
        rootNode = newParentNode;

    currentNode->moveDown(newParentNode);
    currentNode->leftChild = newParentNode->rightChild;
    if (newParentNode->rightChild != NULL)
        newParentNode->rightChild->parentNode = currentNode;

    newParentNode->rightChild = currentNode;
}

void RBTree::fixRedRed(NodeRB* currentNode, int& iterations) {
    if (currentNode == rootNode) {
        currentNode->color = BLACK;
        return;
    }

    NodeRB* parentNode = currentNode->parentNode;
    NodeRB* grandParentNode = parentNode->parentNode;
    NodeRB* uncleNode = currentNode->uncle();

    if (parentNode->color != BLACK) {
        iterations++;
        if (uncleNode != NULL && uncleNode->color == RED) {
            parentNode->color = BLACK;
            uncleNode->color = BLACK;
            grandParentNode->color = RED;
            fixRedRed(grandParentNode, iterations);
        } else {
            if (parentNode->isOnLeft()) {
                if (currentNode->isOnLeft()) {
                    swapColors(parentNode, grandParentNode);
                } else {
                    leftRotate(parentNode);
                    swapColors(currentNode, grandParentNode);
                }
                rightRotate(grandParentNode);
            } else {
                if (currentNode->isOnLeft()) {
                    rightRotate(parentNode);
                    swapColors(currentNode, grandParentNode);
                } else {
                    swapColors(parentNode, grandParentNode);
                }
                leftRotate(grandParentNode);
            }
        }
    }
}

NodeRB* RBTree::searchNode(int value, int& iterations) {
    NodeRB* currentNode = rootNode;
    while (currentNode != NULL) {
        iterations++;
        if (value < currentNode->value) {
            if (currentNode->leftChild == NULL)
                break;
            currentNode = currentNode->leftChild;
        } else if (value == currentNode->value) {
            break;
        } else {
            if (currentNode->rightChild == NULL)
                break;
            currentNode = currentNode->rightChild;
        }
    }
    return currentNode;
}

bool RBTree::insert(int value, int& iterations) {
    NodeRB* newNode = new NodeRB(value);
    if (rootNode == NULL) {
        newNode->color = BLACK;
        rootNode = newNode;
    } else {
        NodeRB* parentNode = searchNode(value, iterations);
        if (parentNode->value == value) return true;

        newNode->parentNode = parentNode;
        if (value < parentNode->value)
            parentNode->leftChild = newNode;
        else
            parentNode->rightChild = newNode;

        fixRedRed(newNode, iterations);
    }
    return true;
}

NodeRB* RBTree::successor(NodeRB* currentNode, int& iterations) {
    NodeRB* temp = currentNode;
    while (temp->leftChild != NULL)
        temp = temp->leftChild;
    return temp;
}

NodeRB* RBTree::BSTreplace(NodeRB* currentNode, int& iterations) {
    if (currentNode->leftChild != NULL && currentNode->rightChild != NULL)
        return successor(currentNode->rightChild, iterations);
    if (currentNode->leftChild != NULL)
        return currentNode->leftChild;
    return currentNode->rightChild;
}

void RBTree::deleteNode(NodeRB* nodeToDelete, int& iterations) {
    NodeRB* replacementNode = BSTreplace(nodeToDelete, iterations);
    bool isBothBlack = ((replacementNode == NULL || replacementNode->color == BLACK) && (nodeToDelete->color == BLACK));
    NodeRB* parentNode = nodeToDelete->parentNode;

    if (replacementNode == NULL) {
        if (nodeToDelete == rootNode) {
            rootNode = NULL;
        } else {
            if (isBothBlack) {
                fixDoubleBlack(nodeToDelete, iterations);
            } else {
                if (nodeToDelete->sibling() != NULL)
                    nodeToDelete->sibling()->color = RED;
            }

            if (nodeToDelete->isOnLeft())
                parentNode->leftChild = NULL;
            else
                parentNode->rightChild = NULL;
        }
        delete nodeToDelete;
        return;
    }

    if (nodeToDelete->leftChild == NULL || nodeToDelete->rightChild == NULL) {
        if (nodeToDelete == rootNode) {
            nodeToDelete->value = replacementNode->value;
            nodeToDelete->leftChild = nodeToDelete->rightChild = NULL;
            delete replacementNode;
        } else {
            if (nodeToDelete->isOnLeft())
                parentNode->leftChild = replacementNode;
            else
                parentNode->rightChild = replacementNode;

            replacementNode->parentNode = parentNode;
            delete nodeToDelete;
            if (isBothBlack) {
                fixDoubleBlack(replacementNode, iterations);
            } else {
                replacementNode->color = BLACK;
            }
        }
        return;
    }

    swapValues(replacementNode, nodeToDelete);
    deleteNode(replacementNode, iterations);
}

void RBTree::fixDoubleBlack(NodeRB* currentNode, int& iterations) {
    if (currentNode == rootNode) return;

    NodeRB* siblingNode = currentNode->sibling();
    NodeRB* parentNode = currentNode->parentNode;

    if (siblingNode == NULL) {
        fixDoubleBlack(parentNode, iterations);
    } else {
        if (siblingNode->color == RED) {
            parentNode->color = RED;
            siblingNode->color = BLACK;
            if (siblingNode->isOnLeft()) {
                rightRotate(parentNode);
            } else {
                leftRotate(parentNode);
            }
            fixDoubleBlack(currentNode, iterations);
        } else {
            if (siblingNode->hasRedChild()) {
                if (siblingNode->leftChild != NULL && siblingNode->leftChild->color == RED) {
                    if (siblingNode->isOnLeft()) {
                        siblingNode->leftChild->color = siblingNode->color;
                        siblingNode->color = parentNode->color;
                        rightRotate(parentNode);
                    } else {
                        siblingNode->leftChild->color = parentNode->color;
                        rightRotate(siblingNode);
                        leftRotate(parentNode);
                    }
                } else {
                    if (siblingNode->isOnLeft()) {
                        siblingNode->rightChild->color = parentNode->color;
                        leftRotate(siblingNode);
                        rightRotate(parentNode);
                    } else {
                        siblingNode->rightChild->color = siblingNode->color;
                        siblingNode->color = parentNode->color;
                        leftRotate(parentNode);
                    }
                }
                parentNode->color = BLACK;
            } else {
                siblingNode->color = RED;
                if (parentNode->color == BLACK)
                    fixDoubleBlack(parentNode, iterations);
                else
                    parentNode->color = BLACK;
            }
        }
    }
}

bool RBTree::remove(int value, int& iterations) {
    if (rootNode == NULL) return false;

    NodeRB* nodeToDelete = searchNode(value, iterations);
    if (nodeToDelete->value != value) {
        cout << "No node found to delete with value: " << value << endl;
        return false;
    }

    deleteNode(nodeToDelete, iterations);
    return true;
}
bool RBTree::search(int value, int& iterations) {
    if (rootNode == NULL) return false;

    NodeRB* nodeToSearch= searchNode(value, iterations);
    if (nodeToSearch->value != value) {
        cout << "No node found with value: " << value << endl;
        return false;
    }
    return true;
}