#ifndef MyStack_h
#define MyStack_h

#include <iostream>
#include <climits>
using namespace std;

// Node struct templated
template<typename T>
struct Node
{
    T value;
    Node<T>* next;
};

// MyStack class templated
template<typename T>
class MyStack
{
private:
    Node<T> dummy;

public:
    // MyStack() constructor: Initialize the dummy node's next pointer to nullptr
    MyStack()
    {
        dummy.next = nullptr;
    }

    // Copy constructor: Copy the stack from the right-hand side
    MyStack(const MyStack<T>& rhs)
    {
        dummy.next = nullptr;
        Node<T>* current = rhs.dummy.next;     // Start from first real node
        Node<T>* tail = &dummy;                // Build onto this dummy

        // Copy the stack from the right-hand side
        while (current != nullptr)
        {
            Node<T>* newNode = new Node<T>;
            newNode->value = current->value;
            newNode->next = nullptr;

            tail->next = newNode;
            tail = newNode;

            current = current->next;
        }
    }

    // Overloaded assignment operator
    MyStack<T>& operator=(const MyStack<T>& rhs)
    {
        // Check for self-assignment
        if (this == &rhs)
        {
            return *this;
        }

        // Delete all nodes in the current stack
        Node<T>* current = dummy.next; // Start at the top of the stack
        while (current != nullptr)
        {
            Node<T>* toDelete = current;      // Remember the current node
            current = current->next;          // Move to the next node
            delete toDelete;                  // Free the memory
        }

        // Reset the stack to empty
        dummy.next = nullptr;

        // Copy nodes from rhs into this stack
        Node<T>* rhsCurrent = rhs.dummy.next; // Start at the top of rhs
        Node<T>* tail = &dummy;               // Start adding nodes after dummy

        while (rhsCurrent != nullptr)
        {
            // Create a new node
            Node<T>* newNode = new Node<T>;
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

    // push function: Add a new value to the top of the stack
    void push(T v)
    {
        Node<T>* newNode = new Node<T>;
        newNode->value = v; // Set the new node's value to the value being pushed

        newNode->next = dummy.next; // Set the new node's next pointer to the current top of the stack
        dummy.next = newNode; // Add the new node to the top of the stack
    }

    // pop function: Remove and return the top value from the stack
    T pop()
    {
        // Check if the stack is empty
        if (dummy.next == nullptr)
        {
            return T();  // generic default for type T: ie string, int, etc
        }

        // Remove the top node from the stack
        Node<T>* toRemove = dummy.next;
        T value = toRemove->value;

        // Move the dummy node's next pointer to the next node in the stack
        dummy.next = toRemove->next;
        delete toRemove;

        return value;
    }

    // peek function: Return (but don’t remove) the top value from the stack
    T peek()
    {
        if (dummy.next == nullptr)
        {
            return T();
        }

        return dummy.next->value;
    }

    // size function: Return how many nodes are in the stack
    int size()
    {
        int count = 0;
        Node<T>* current = dummy.next;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    // printStack function: Print the entire contents of the stack
    void printStack()
    {
        Node<T>* current = dummy.next;

        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Destructor: Free all dynamically allocated memory
    ~MyStack()
    {
        Node<T>* current = dummy.next;

        while (current != nullptr)
        {
            Node<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }

        dummy.next = nullptr;
    }
};

#endif
