#include <iostream>
#include "BinaryTree.h"
using namespace std;

// 1️⃣ insert
void BinaryTree::insert(BinaryNode* &tree, int num)
{
    if (tree == nullptr)
    {
        tree = new BinaryNode(num);
    }
    else if (num < tree->getItem())
    {
        BinaryNode* left = tree->getLeftChildPtr();
        insert(left, num);
        tree->setLeftChildPtr(left);
    }
    else if (num > tree->getItem())
    {
        BinaryNode* right = tree->getRightChildPtr();
        insert(right, num);
        tree->setRightChildPtr(right);
    }
    else
    {
        // Duplicate, do nothing
    }
}

// 2️⃣ destroySubtree
void BinaryTree::destroySubtree(BinaryNode *tree)
{
    if (tree != nullptr)
    {
        destroySubtree(tree->getLeftChildPtr());
        destroySubtree(tree->getRightChildPtr());
        delete tree;
    }
}

// 3️⃣ remove
void BinaryTree::remove(BinaryNode *tree, int num)
{
    if (tree == nullptr)
    {
        return;
    }
    if (num < tree->getItem())
    {
        BinaryNode* left = tree->getLeftChildPtr();
        remove(left, num);
        tree->setLeftChildPtr(left);
    }
    else if (num > tree->getItem())
    {
        BinaryNode* right = tree->getRightChildPtr();
        remove(right, num);
        tree->setRightChildPtr(right);
    }
    else
    {
        makeDeletion(tree);
    }
}

// 4️⃣ makeDeletion
void BinaryTree::makeDeletion(BinaryNode *&tree)
{
    BinaryNode *nodeToDelete = tree;

    if (tree->getLeftChildPtr() == nullptr)
    {
        tree = tree->getRightChildPtr();
    }
    else if (tree->getRightChildPtr() == nullptr)
    {
        tree = tree->getLeftChildPtr();
    }
    else
    {
        BinaryNode* successorParent = tree;
        BinaryNode* successor = tree->getRightChildPtr();

        while (successor->getLeftChildPtr() != nullptr)
        {
            successorParent = successor;
            successor = successor->getLeftChildPtr();
        }

        tree->setItem(successor->getItem());

        if (successorParent == tree)
        {
            successorParent->setRightChildPtr(successor->getRightChildPtr());
        }
        else
        {
            successorParent->setLeftChildPtr(successor->getRightChildPtr());
        }

        nodeToDelete = successor;
    }

    delete nodeToDelete;
}

// 5️⃣ displayInOrder
void BinaryTree::displayInOrder(BinaryNode *tree) const
{
    if (tree != nullptr)
    {
        displayInOrder(tree->getLeftChildPtr());
        cout << tree->getItem() << " ";
        displayInOrder(tree->getRightChildPtr());
    }
}

// 6️⃣ displayPreOrder
void BinaryTree::displayPreOrder(BinaryNode *tree) const
{
    if (tree != nullptr)
    {
        cout << tree->getItem() << " ";
        displayPreOrder(tree->getLeftChildPtr());
        displayPreOrder(tree->getRightChildPtr());
    }
}

// 7️⃣ displayPostOrder
void BinaryTree::displayPostOrder(BinaryNode *tree) const
{
    if (tree != nullptr)
    {
        displayPostOrder(tree->getLeftChildPtr());
        displayPostOrder(tree->getRightChildPtr());
        cout << tree->getItem() << " ";
    }
}

// 8️⃣ search
bool BinaryTree::search(int num) const
{
    BinaryNode* tree = root;

    while (tree != nullptr)
    {
        if (num == tree->getItem())
        {
            return true;
        }
        else if (num < tree->getItem())
        {
            tree = tree->getLeftChildPtr();
        }
        else
        {
            tree = tree->getRightChildPtr();
        }
    }

    return false;
}