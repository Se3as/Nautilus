#include "btree.h"

BTreeNode::BTreeNode(int minDegree, bool isLeafNode)
{
    degree = minDegree;
    isLeaf = isLeafNode;
    keys = new int[2 * degree - 1];
    children = new BTreeNode *[2 * degree];
    numKeys = 0;
}

int BTreeNode::findKey(int key)
{
    int index = 0;
    while (index < numKeys && keys[index] < key)
        ++index;
    return index;
}

void BTreeNode::remove(int key)
{
    int index = findKey(key);

    if (index < numKeys && keys[index] == key)
    {
        if (isLeaf)
            removeFromLeaf(index);
        else
            removeFromNonLeaf(index);
    }
    else
    {
        if (isLeaf)
        {
            cout << "The key " << key << " does not exist in the tree\n";
            return;
        }

        bool flag = ((index == numKeys) ? true : false);

        if (children[index]->numKeys < degree)
            fill(index);

        if (flag && index > numKeys)
            children[index - 1]->remove(key);
        else
            children[index]->remove(key);
    }
    return;
}

void BTreeNode::removeFromLeaf(int index)
{
    for (int i = index + 1; i < numKeys; ++i)
        keys[i - 1] = keys[i];
    numKeys--;
    return;
}

void BTreeNode::removeFromNonLeaf(int index)
{
    int key = keys[index];

    if (children[index]->numKeys >= degree)
    {
        int pred = getPred(index);
        keys[index] = pred;
        children[index]->remove(pred);
    }
    else if (children[index + 1]->numKeys >= degree)
    {
        int succ = getSucc(index);
        keys[index] = succ;
        children[index + 1]->remove(succ);
    }
    else
    {
        merge(index);
        children[index]->remove(key);
    }
    return;
}

int BTreeNode::getPred(int index)
{
    BTreeNode *cur = children[index];
    while (!cur->isLeaf)
        cur = cur->children[cur->numKeys];
    return cur->keys[cur->numKeys - 1];
}

int BTreeNode::getSucc(int index)
{
    BTreeNode *cur = children[index + 1];
    while (!cur->isLeaf)
        cur = cur->children[0];
    return cur->keys[0];
}

void BTreeNode::fill(int index)
{
    if (index != 0 && children[index - 1]->numKeys >= degree)
        borrowFromPrev(index);
    else if (index != numKeys && children[index + 1]->numKeys >= degree)
        borrowFromNext(index);
    else
    {
        if (index != numKeys)
            merge(index);
        else
            merge(index - 1);
    }
    return;
}

void BTreeNode::borrowFromPrev(int index)
{
    BTreeNode *child = children[index];
    BTreeNode *sibling = children[index - 1];

    for (int i = child->numKeys - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->isLeaf)
    {
        for (int i = child->numKeys; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }

    child->keys[0] = keys[index - 1];

    if (!child->isLeaf)
        child->children[0] = sibling->children[sibling->numKeys];

    keys[index - 1] = sibling->keys[sibling->numKeys - 1];

    child->numKeys += 1;
    sibling->numKeys -= 1;

    return;
}

void BTreeNode::borrowFromNext(int index)
{
    BTreeNode *child = children[index];
    BTreeNode *sibling = children[index + 1];

    child->keys[child->numKeys] = keys[index];

    if (!child->isLeaf)
        child->children[child->numKeys + 1] = sibling->children[0];

    keys[index] = sibling->keys[0];

    for (int i = 1; i < sibling->numKeys; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->isLeaf)
    {
        for (int i = 1; i <= sibling->numKeys; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }

    child->numKeys += 1;
    sibling->numKeys -= 1;

    return;
}

void BTreeNode::merge(int index)
{
    BTreeNode *child = children[index];
    BTreeNode *sibling = children[index + 1];

    child->keys[degree - 1] = keys[index];

    for (int i = 0; i < sibling->numKeys; ++i)
        child->keys[i + degree] = sibling->keys[i];

    if (!child->isLeaf)
    {
        for (int i = 0; i <= sibling->numKeys; ++i)
            child->children[i + degree] = sibling->children[i];
    }

    for (int i = index + 1; i < numKeys; ++i)
        keys[i - 1] = keys[i];

    for (int i = index + 2; i <= numKeys; ++i)
        children[i - 1] = children[i];

    child->numKeys += sibling->numKeys + 1;
    numKeys--;

    delete sibling;
    return;
}

void BTreeNode::insertNonFull(int key, int& iterations)
{
    int i = numKeys - 1;

    if (isLeaf)
    {
        while (i >= 0 && keys[i] > key)
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys += 1;
    }
    else
    {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->numKeys == 2 * degree - 1)
        {
            splitChild(i + 1, children[i + 1], iterations);

            if (keys[i + 1] < key)
                i++;
        }
        iterations++;
        children[i + 1]->insertNonFull(key, iterations);
    }
}

void BTreeNode::splitChild(int index, BTreeNode *child, int& iterations)
{
    BTreeNode *newChild = new BTreeNode(child->degree, child->isLeaf);
    newChild->numKeys = degree - 1;

    for (int j = 0; j < degree - 1; j++)
        newChild->keys[j] = child->keys[j + degree];

    if (!child->isLeaf)
    {
        for (int j = 0; j < degree; j++)
            newChild->children[j] = child->children[j + degree];
    }

    child->numKeys = degree - 1;

    for (int j = numKeys; j >= index + 1; j--)
        children[j + 1] = children[j];

    children[index + 1] = newChild;

    for (int j = numKeys - 1; j >= index; j--)
        keys[j + 1] = keys[j];

    keys[index] = child->keys[degree - 1];
    
    iterations++;
    numKeys += 1;
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < numKeys; i++)
    {
        if (!isLeaf)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    if (!isLeaf)
        children[i]->traverse();
}

BTreeNode *BTreeNode::search(int key, int& iterations)
{
    iterations++;
    int i = 0;
    while (i < numKeys && key > keys[i]){
        iterations++;
        i++;
    }
    if (keys[i] == key)
        return this;

    if (isLeaf)
        return NULL;
    
    return children[i]->search(key,iterations);
}

bool BTree::insert(int key, int& iterations)
{
    iterations++;
    
    if (root == NULL)
    {
        root = new BTreeNode(minDegree, true);
        root->keys[0] = key;
        root->numKeys = 1;
    }
    else
    {
        if (root->numKeys == 2 * minDegree - 1)
        {
            BTreeNode *newRoot = new BTreeNode(minDegree, false);
            newRoot->children[0] = root;
            newRoot->splitChild(0, root, iterations);

            int i = 0;
            if (newRoot->keys[0] < key)
                i++;
            iterations++;
            newRoot->children[i]->insertNonFull(key, iterations);

            root = newRoot;
        }
        else
        {   
            iterations++;
            root->insertNonFull(key, iterations);
        }
    }
    return true;
}

bool BTree::remove(int key,int& iterations){
    if (!root)
    {
        cout << "The tree is empty\n";
        return false;
    }

    root->remove(key);

    if (root->numKeys == 0)
    {
        BTreeNode *tmp = root;
        if (root->isLeaf)
            root = NULL;
        else
            root = root->children[0];

        delete tmp;
    }
    return true;
}
