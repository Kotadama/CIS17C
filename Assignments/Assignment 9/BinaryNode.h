#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

class BinaryNode
{   
private:
   int item;                   // Data portion
   BinaryNode *leftChildPtr;   // Pointer to left child
   BinaryNode *rightChildPtr;  // Pointer to right child

public:
   BinaryNode();
   BinaryNode(int anItem);
   BinaryNode(int anItem, BinaryNode *leftPtr, BinaryNode *rightPtr);

   void setItem(int anItem);
   int getItem() const;
   
   bool isLeaf() const;

   BinaryNode* getLeftChildPtr() const;
   BinaryNode* getRightChildPtr() const;
   
   void setLeftChildPtr(BinaryNode *leftPtr);
   void setRightChildPtr(BinaryNode *rightPtr);
}; // end BinaryNode

#endif 
