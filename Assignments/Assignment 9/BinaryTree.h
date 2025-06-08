#ifndef BINARY_TREE_
#define BINARY_TREE_

#include<iostream>
#include"BinaryNode.h"

class BinaryTree
{
private:
      BinaryNode *root;     // Pointer to the root of the tree

   // Various helper member functions.
   void insert(BinaryNode *&, int);
   void destroySubtree(BinaryNode *);
   void remove(BinaryNode *, int);
   void makeDeletion(BinaryNode *&);
   void displayInOrder(BinaryNode *) const;
   void displayPreOrder(BinaryNode *) const;
   void displayPostOrder(BinaryNode *) const;

public:
   // These member functions are the public interface.
   BinaryTree()		// Constructor
   {
      root = nullptr;
   }
   ~BinaryTree()		// Destructor
   {
      destroySubtree(root);
   }
   void insert(int num)
   {
      insert(root, num);
   }
   bool search(int) const;
   void remove(int num)
   {
      remove(root, num);
   }
   void showInOrder() const
   {
      displayInOrder(root);
   }
   void showPreOrder() const
   {
      displayPreOrder(root);
   }
   void showPostOrder() const
   {
      displayPostOrder(root);
   }
};

#endif