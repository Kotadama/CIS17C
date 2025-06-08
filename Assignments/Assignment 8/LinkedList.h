#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int value;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

    // deleteRecursive
    void deleteRecursive(Node* node);

    // copyListRecursive
    Node* copyListRecursive(const Node* node);

    // printItemsRecursive
    void printItemsRecursive(Node* node) const;

    // getSizeRecursive
    int getSizeRecursive(Node* node) const;

    // addToRearRecursive
    void addToRearRecursive(Node*& node, int v);

    // deleteItemRecursive
    void deleteItemRecursive(Node*& node, int v);

    // swapListsRecursive
    void swapListsRecursive(Node*& a, Node*& b);

public:
    // Constructor
    LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList& other);

    // Destructor
    ~LinkedList();

    // Assignment Operator
    LinkedList& operator=(const LinkedList& other);

    // addToFront
    void addToFront(int v);

    // addToRear
    void addToRear(int v);

    // deleteItem
    void deleteItem(int v);

    // swapList
    void swapList(LinkedList& Other);

    // printItems
    void printItems() const;

    // size
    int size() const;

    // sort
    void sort();
};

#endif
