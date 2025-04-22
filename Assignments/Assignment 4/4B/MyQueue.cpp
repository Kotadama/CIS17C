#include "MyQueue.h"
#include <iostream>
#include <climits> // for INT_MIN

using namespace std;

// Default constructor
MyQueue::MyQueue() 
{
  dummy.next = nullptr;
}

// Copy constructor
MyQueue::MyQueue(const MyQueue& rhs) 
{
  dummy.next = nullptr; // Start with an empty queue

  Node* current = rhs.dummy.next; // Start copying from the first real node

  while (current != nullptr) 
  {
      push(current->value); // Push each value into the new queue
      current = current->next; // Move to next node
  }
}

// Overloaded assignment operator
MyQueue& MyQueue::operator=(const MyQueue& rhs) 
{
  if (this != &rhs) { // protect against self-assignment
      // Delete current nodes
      Node* current = dummy.next;
      while (current != nullptr) 
      {
          Node* toDelete = current;
          current = current->next;
          delete toDelete;
      }
      dummy.next = nullptr;

      // Copy nodes from rhs
      current = rhs.dummy.next;
      while (current != nullptr) 
      {
          push(current->value);
          current = current->next;
      }
  }
  return *this;
}


// Push to the back of the queue
void MyQueue::push(int v) 
{
  Node* newNode = new Node{v, nullptr}; // 1. Create new node

  Node* current = &dummy;               // 2. Start at dummy node

  while (current->next != nullptr) 
  {    // 3. Walk to the end
      current = current->next;
  }

  current->next = newNode;               // 4. Attach new node at the end
}


// Pop from the front of the queue
int MyQueue::pop() {
  if (dummy.next == nullptr) 
  {
      return INT_MIN;
  }

  Node* toDelete = dummy.next;
  int returnValue = toDelete->value;

  dummy.next = dummy.next->next; // move dummy.next to skip over first node

  delete toDelete;

  return returnValue;
}


// Peek at the front item
int MyQueue::peek() {
  if (dummy.next == nullptr) 
  {
      return INT_MIN;
  }
  return dummy.next->value;
}


// Return size of the queue
int MyQueue::size() {
  if (dummy.next == nullptr) 
  {
      return 0;
  }

  int count = 0;
  Node* current = dummy.next;

  while (current != nullptr) 
  {
      count++;
      current = current->next;
  }

  return count;
}


// Print the entire queue
void MyQueue::printQueue() 
{
  Node* current = dummy.next;

  while (current != nullptr) 
  {
      cout << current->value << " ";
      current = current->next;
  }

  cout << endl; // newline after printing all values
}


// Destructor
MyQueue::~MyQueue() {
  Node* current = dummy.next;

  while (current != nullptr) {
      Node* toDelete = current;
      current = current->next;
      delete toDelete;
  }
}

