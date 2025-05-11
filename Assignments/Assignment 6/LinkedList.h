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

    // Recursive helper functions
    void deleteRecursive(Node* node);
    Node* copyListRecursive(const Node* node);
    void printItemsRecursive(Node* node) const;
    int getSizeRecursive(Node* node) const;
    void addToRearRecursive(Node*& node, int value);
    void deleteItemRecursive(Node*& node, int value);
    void swapListsRecursive(Node*& a, Node*& b);

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();
    LinkedList& operator=(const LinkedList& other);

    void addToFront(int v);
    void addToRear(int v);
    void deleteItem(int v);
    void swapList(LinkedList& Other);
    void printItems() const;
    int size() const;
};

#endif
