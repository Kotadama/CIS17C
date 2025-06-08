#include "BinaryNode.h"
#include <cstddef>


BinaryNode::BinaryNode()
      : item(0), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end default constructor

BinaryNode::BinaryNode(int anItem)
      : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end constructor

BinaryNode::BinaryNode(int anItem,
                                    BinaryNode *leftPtr,
                                    BinaryNode *rightPtr)
      : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{ }  // end constructor

void BinaryNode::setItem(int anItem) 
{
  item = anItem;
}  // end setItem

int BinaryNode::getItem() const 
{
  return item;
}  // end getItem

bool BinaryNode::isLeaf() const 
{
  return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

void BinaryNode::setLeftChildPtr(BinaryNode *leftPtr) 
{
  leftChildPtr = leftPtr;
}  // end setLeftChildPtr

void BinaryNode::setRightChildPtr(BinaryNode *rightPtr) 
{
  rightChildPtr = rightPtr;
}  // end setRightChildPtr

BinaryNode* BinaryNode::getLeftChildPtr() const 
{
  return leftChildPtr;
}  // end getLeftChildPtr		

BinaryNode* BinaryNode::getRightChildPtr() const 
{
  return rightChildPtr;
}  // end getRightChildPtr		

