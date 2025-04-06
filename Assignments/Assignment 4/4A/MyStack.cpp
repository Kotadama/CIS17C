#include "MyStack.h" // Include the class header
#include <climits>
#include <iostream>
using namespace std;


MyStack::MyStack()
{
	dummy.next = nullptr; // Initialize the dummy node's next pointer to nullptr
}

MyStack::MyStack(const MyStack& rhs)
{
	dummy.next = nullptr;
    Node* current = rhs.dummy.next;     // Start from first real node
    Node* tail = &dummy;                //build onto this dummy

	// Copy the stack from the right-hand side
    while (current != nullptr)
    {
        Node* newNode = new Node;
        newNode->value = current->value;
        newNode->next = nullptr;

        tail->next = newNode;
        tail = newNode;

        current = current->next;
    }
}

MyStack& MyStack::operator=(const MyStack& rhs)
{
    //Check for self-assignment
    if (this == &rhs)
    {
        return *this;
    }
	
	//Delete all nodes in the current stack
    Node* current = dummy.next; // Start at the top of the stack
    while (current != nullptr)
    {
        Node* toDelete = current;      // Remember the current node
        current = current->next;       // Move to the next node
        delete toDelete;               // Free the memory
    }

    // Reset the stack to empty
    dummy.next = nullptr;

    //Copy nodes from rhs into this stack
    Node* rhsCurrent = rhs.dummy.next; // Start at the top of rhs
    Node* tail = &dummy;               // Start adding nodes after dummy

    while (rhsCurrent != nullptr)
    {
        // Create a new node
        Node* newNode = new Node;
        newNode->value = rhsCurrent->value;
        newNode->next = nullptr;

        // Attach it to the end of the current list
        tail->next = newNode;
        tail = newNode;

        // Move to the next node in rhs
        rhsCurrent = rhsCurrent->next;
    }
	
    return *this;
}




void MyStack::push(int v) 
{
	Node* newNode = new Node;
    newNode->value = v;// Set the new node's value to the value being pushed

    newNode->next = dummy.next;// Set the new node's next pointer to the current top of the stack
    dummy.next = newNode; // Add the new node to the top of the stack
}

int MyStack::pop()
{
	// Check if the stack is empty
    if (dummy.next == nullptr)
    {
        return INT_MIN;
    }

	// Remove the top node from the stack
    Node* toRemove = dummy.next;
    int value = toRemove->value;

	// Move the dummy node's next pointer to the next node in the stack
    dummy.next = toRemove->next;
    delete toRemove;

    return value;
}

int MyStack::peek()
{
    if (dummy.next == nullptr)
    {
        return INT_MIN;
    }

    return dummy.next->value;
}

int MyStack::size()
{
    int count = 0;
    Node* current = dummy.next;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}


void MyStack::printStack()
{
    Node* current = dummy.next;

    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }

    cout << endl;
}


MyStack::~MyStack()
{
    Node* current = dummy.next;

    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    dummy.next = nullptr;
}
