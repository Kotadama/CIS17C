#include <iostream>

// Node structure for the doubly linked list
struct Node
{
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList
{
private:
    // Head and tail dummy nodes
    Node headDummy;
    Node tailDummy;

    // Private member function to delete a node traversing from the front of the list
    bool deleteFromFront(int value)
    {
        Node* current = headDummy.next;
        
        // Traverse the list to find the value
        while (current != &tailDummy)
        {
            // If the value is found, delete the node
            if (current->data == value)
            {
                // Adjust pointers
                current->prev->next = current->next; // Update the previous node's next pointer
                current->next->prev = current->prev; // Update the next node's previous pointer

                // If deleting the first node, update headDummy
                if (headDummy.next == current)
                    headDummy.next = current->next;

                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Private member function to delete a node from the end of the list
    bool deleteFromEnd(int value)
    {
        Node* current = tailDummy.prev;

        // Traverse the list to find the value
        while (current != &headDummy)
        {
            // If the value is found, delete the node
            if (current->data == value)
            {
                // Adjust pointers
                current->prev->next = current->next;
                current->next->prev = current->prev;

                // If deleting the last node, update tailDummy
                if (tailDummy.prev == current)
                    tailDummy.prev = current->prev;

                delete current;
                return true;
            }
            current = current->prev; 
        }
        return false;
    }

    // Private member function to add a node traversing from the front of the list
    void addFromFront(int value)
    {
        Node* newNode = new Node(value);
        Node* current = headDummy.next;

        // Traverse the list to find the correct position to insert the new node
        while (current != &tailDummy && current->data < value)
        {
            current = current->next; 
        }

        // Insert the new node before the current node
        newNode->next = current;
        newNode->prev = current->prev;

        // Update the next node's previous pointer
        if (current->prev != &headDummy)
        {
            current->prev->next = newNode; // Update the previous node's next pointer
        }
        else
        {
            headDummy.next = newNode; // Update headDummy if the new node is the first node
        }
        current->prev = newNode; // Update the current node's previous pointer
    }

    // Private member function to add a node traversing from the end of the list
    void addFromEnd(int value)
    {
        Node* newNode = new Node(value);
        Node* current = tailDummy.prev;

        // Traverse the list to find the correct position to insert the new node
        while (current != &headDummy && current->data > value)
        {
            current = current->prev;
        }

        // Insert the new node before the current node
        newNode->prev = current;
        newNode->next = current->next;

        // If current is not the last node, update the next node's previous pointer
        if (current->next != &tailDummy)
        {
            current->next->prev = newNode; // Update the next node's previous pointer
        }
        else
        {
            tailDummy.prev = newNode; // Update tailDummy if the new node is the last node
        }
        current->next = newNode; // Update the current node's next pointer
    
    }

public:
    // Constructor
    DoublyLinkedList() : headDummy(0), tailDummy(0)
    {
        // Connect head and tail dummy nodes
        headDummy.next = &tailDummy;
        tailDummy.prev = &headDummy;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        // Start from the first node
        Node* current = headDummy.next;

        // Delete all nodes in the list
        while (current != &tailDummy)
        {
            Node* temp = current; 
            current = current->next;
            delete temp;
        }
        headDummy.next = &tailDummy;  // Ensure head points to tail after deletion
        tailDummy.prev = &headDummy;  // Ensure tail points to head after deletion
    }

    // Function to print the elements of the list
    void printList()
    {
        // Start from the first node
        Node* current = headDummy.next;

        // Traverse the list and print the data of each node
        while (current != &tailDummy)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Public function to delete a node based on value
    bool deleteFromList(int value)
    {
        // Determine if the value is closer to the head or tail
        int distanceFromHead = value - headDummy.next->data;
        int distanceFromTail = tailDummy.prev->data - value;

        if (distanceFromHead <= distanceFromTail)
            return deleteFromFront(value);
        else
            return deleteFromEnd(value);
    }

    // Public function to add a node to the ordered list
    void addToOrderedList(int value)
    {
        // Determine if the value is closer to the head or tail
        int distanceFromHead = value - headDummy.next->data;
        int distanceFromTail = tailDummy.prev->data - value;

        if (distanceFromHead <= distanceFromTail)
            addFromFront(value);
        else
            addFromEnd(value);
    }
};

int main() 
{
    // Create a doubly linked list
    DoublyLinkedList myList;
  
    // Add elements to the ordered list
    myList.addToOrderedList(3);
    myList.addToOrderedList(1);
    myList.addToOrderedList(2);
    myList.addToOrderedList(5);
    myList.addToOrderedList(4);
  
    // Print the elements of the list
    std::cout << "Here is the current list:" << std::endl;
    myList.printList();
    std::cout << std::endl;
  
    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 2 from the list." << std::endl;
    bool deleted = myList.deleteFromList(2);
    if (deleted)
        std::cout << "Successfully deleted value from the list." << std::endl;
    else
        std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;
  
    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 4 from the list." << std::endl;
    deleted = myList.deleteFromList(4);
    if (deleted)
      std::cout << "Successfully deleted value from the list." << std::endl;
    else
      std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;
  
    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 4 from the list again.  This should be unsuccessful." << std::endl;
    deleted = myList.deleteFromList(4);
    if (deleted)
      std::cout << "Successfully deleted value from the list." << std::endl;
    else
      std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;
  
    // Print the updated list
    myList.printList();
    std::cout << std::endl;
  
    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 5 from the list" << std::endl;
    deleted = myList.deleteFromList(5);
    if (deleted)
      std::cout << "Successfully deleted value from the list." << std::endl;
    else
      std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;
  
    // Print the updated list
    myList.printList();
    std::cout << std::endl;
  
    // Delete a node from the list and print the updated list
    std::cout << "Trying to delete 1 from the list" << std::endl;
    deleted = myList.deleteFromList(1);
    if (deleted)
      std::cout << "Successfully deleted value from the list." << std::endl;
    else
      std::cout << "Value not found in the list." << std::endl;
    std::cout << std::endl;
  
    // Print the updated list
    myList.printList();
    std::cout << std::endl;
  
    return 0;
  }