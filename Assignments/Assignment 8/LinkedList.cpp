#include "LinkedList.h"
#include <iostream>
using namespace std;

// deleteRecursive
void LinkedList::deleteRecursive(Node* node) 
{
    if (node == nullptr) // Base case
    return;
    // Recursively delete the next node
    deleteRecursive(node->next);
    delete node;
}

// copyListRecursive
Node* LinkedList::copyListRecursive(const Node* node) 
{
    if (node == nullptr) // Base case
    return nullptr;
    // Create a new node with the same value
    Node* newNode = new Node{node->value, nullptr};

    // Recursively copy the next node
    newNode->next = copyListRecursive(node->next);
    return newNode;
}

// printItemsRecursive
void LinkedList::printItemsRecursive(Node* node) const 
{
    if (node == nullptr) return; // Base case
    cout << node->value << " ";
    // Recursively print the next node
    printItemsRecursive(node->next);
}

// getSizeRecursive
int LinkedList::getSizeRecursive(Node* node) const 
{
    if (node == nullptr) // Base case
    return 0; 
    // Recursively get the size of the next node
    return 1 + getSizeRecursive(node->next);
}

// addToRearRecursive
void LinkedList::addToRearRecursive(Node*& node, int v) 
{
    if (node == nullptr) // Base case
    {
        node = new Node{v, nullptr};
        return;
    }
    addToRearRecursive(node->next, v);
}

// deleteItemRecursive
void LinkedList::deleteItemRecursive(Node*& node, int v) 
{
    if (node == nullptr) // Base case
    return; 
    
    // If the item to delete is at the head
    if (node->value == v) 
    {
        Node* temp = node;
        node = node->next;
        delete temp;
        deleteItemRecursive(node, v);
    } 
    // move on
    else 
    {
        deleteItemRecursive(node->next, v);
    }
}

// swapListsRecursive
void LinkedList::swapListsRecursive(Node*& a, Node*& b) 
{
    Node* temp = a;
    a = b;
    b = temp;
}

// Constructor
LinkedList::LinkedList() 
{
    head = nullptr;
}

// Copy Constructor
LinkedList::LinkedList(const LinkedList& other) 
{
    head = copyListRecursive(other.head);
}

// Destructor
LinkedList::~LinkedList() 
{
    deleteRecursive(head);
    head = nullptr;
}

// Assignment Operator
LinkedList& LinkedList::operator=(const LinkedList& other) 
{
    if (this != &other) 
    {
        // Delete the current list
        deleteRecursive(head);
        // Create a new list
        head = copyListRecursive(other.head);
    }
    return *this;
}

// addToFront
void LinkedList::addToFront(int v) 
{
    Node* newNode = new Node{v, head};
    head = newNode;
}

// addToRear
void LinkedList::addToRear(int v) 
{
    addToRearRecursive(head, v);
}

// deleteItem
void LinkedList::deleteItem(int v) 
{
    deleteItemRecursive(head, v);
}

// swapList
void LinkedList::swapList(LinkedList& Other) 
{
    swapListsRecursive(this->head, Other.head);
}

// printItems
void LinkedList::printItems() const 
{
    printItemsRecursive(head);
    cout << endl;
}

// size
int LinkedList::size() const 
{
    return getSizeRecursive(head);
}

// sort
void LinkedList::sort()
{
    //check if the list is empty or has only one element
    if (head == nullptr || head->next == nullptr)
    return;

    bool swapped;

    Node* ptr1;
    Node* ptr2 = nullptr;

    // Bubble sort algorithm
    do 
    {
        // Initially, no elements have been swapped
        swapped = false;
        ptr1 = head;

        // Traverse the list until the last unsorted element
        while (ptr1->next != ptr2) 
        {
            if (ptr1->value > ptr1->next->value) 
            {
                // Swap the values of the nodes
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }while (swapped);
}
