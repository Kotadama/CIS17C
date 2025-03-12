#include <iostream>
using namespace std;

struct Node
{
  int value;
  Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;  // Initializes the list as empty
    }

    // Copy Constructor
    LinkedList(const LinkedList &Old)
    {
        head = nullptr;  // Start with an empty list
        Node *temp = Old.head;  // Pointer to the original list's head

        // Traverse the original list and copy its nodes
        while (temp != nullptr)
        {
            addToRear(temp->value);  // Add each value to the new list
            temp = temp->next;  // Move to the next node
        }
    }

    // Destructor
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *toDelete = temp;  // Node to delete
            temp = temp->next;  // Move to the next node
            delete toDelete;  // Deallocate memory for the current node
        }
        head = nullptr;  // Ensure head is null after deleting all nodes
    }

    // Assignment operator
    LinkedList &operator=(const LinkedList &src)
    {
        if (this != &src)  // Avoid self-assignment
        {
            // Delete the current list if it exists
            this->~LinkedList();

            head = nullptr;  // Start with an empty list
            Node *temp = src.head;  // Pointer to the source list's head

            // Traverse the source list and copy its nodes
            while (temp != nullptr)
            {
                addToRear(temp->value);  // Add each value to the new list
                temp = temp->next;  // Move to the next node
            }
        }
        return *this;  // Return the current list (for chained assignment)
    }

    // Add to the front of the list
    void addToFront(int v)
    {
        Node *newNode = new Node;  // Create a new node
        newNode->value = v;  // Set its value
        newNode->next = head;  // Point to the current head
        head = newNode;  // Update head to the new node
    }

    // Add to the rear (end) of the list
    void addToRear(int v)
    {
        Node *newNode = new Node;  // Create a new node
        newNode->value = v;  // Set its value
        newNode->next = nullptr;  // It will be the last node, so next is null

        if (head == nullptr)  // If the list is empty
        {
            head = newNode;  // New node becomes the head
        }
        else
        {
            Node *temp = head;  // Start at the head
            while (temp->next != nullptr)  // Traverse until the last node
            {
                temp = temp->next;
            }
            temp->next = newNode;  // Link the last node to the new node
        }
    }

    // Delete an item from the list
    void deleteItem(int v)
    {
        if (head == nullptr) 
        {
        return;  // If the list is empty, do nothing
        }
        
        // If the item to delete is at the head
        if (head->value == v)
        {
            Node *temp = head;
            head = head->next;  // Update head to the next node
            delete temp;  // Deallocate memory of the node
            return;
        }

        // Traverse the list to find the node to delete
        Node *temp = head;
        while (temp->next != nullptr && temp->next->value != v)
        {
            temp = temp->next;  // Move to the next node
        }

        if (temp->next != nullptr)  // If the node is found
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;  // Skip over the node to delete
            delete toDelete;  // Deallocate memory
        }
    }

    // Swap contents of two lists
    void swapList(LinkedList &Other)
    {
        Node *temp = head;
        head = Other.head;
        Other.head = temp;  // Swap the heads of the two lists
    }

    // Print the items in the list
    void printItems()
    {
        Node *temp = head;  // Start at the head
        while (temp != nullptr)
        {
            cout << temp->value << " ";  // Print the value of the current node
            temp = temp->next;  // Move to the next node
        }
        cout << endl;  // Print a newline at the end
    }

    // Return the size of the list
    int size()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;  // Increment count for each node
            temp = temp->next;  // Move to the next node
        }
        return count;  // Return the number of nodes in the list
    }
};

int main() 
{
  //LEAVE MAIN ALONE PLEASE!!!  <--NO REALLY...I MEAN IT!!!

  //Testing the addToRear function
  LinkedList L;
  L.addToRear(1);
  L.addToRear(2);
  L.addToRear(3);
  L.addToRear(5);
  L.addToRear(6);
  cout << "Testing addToRear()" << endl;
  L.printItems();
  cout << endl;
  cout << endl;

  //Testing the addToFront function
  L.addToFront(7);
  L.addToFront(8);
  cout << "Testing addToFront()" << endl;
  L.printItems();
  cout << endl;
  cout << endl;

  //Testing the size function
  cout << "The size of the list L is " << L.size() << endl;
  cout << endl;
  cout << endl;

  //Testing the copy constructor
  LinkedList LL(L);
  cout << "Testing the copy constructor" << endl;
  LL.printItems();
  cout << endl;
  cout << endl;

  //Testing the swapList function
  LinkedList LLL;
  LLL.addToFront(20);
  LLL.addToFront(30);
  LLL.addToFront(40);
  LLL.addToFront(50);
  LL.swapList(LLL);
  cout << "Testing swapList()" << endl;
  cout << "This is the output of LL" << endl;
  LL.printItems();
  cout << endl;
  cout << "This is the output of LLL" << endl;
  LLL.printItems();
  cout << endl;
  cout << endl;

  //Testing the assignment "=" operator
  L = LL = LLL;
  cout << "Testing the assignment \"=\" operator" << endl;
  cout << "This is the output of L" << endl;
  L.printItems();
  cout << endl;
  cout << "This is the output of LL" << endl;
  LL.printItems();
  cout << endl;
  cout << "This is the output of LLL" << endl;
  LLL.printItems();
  cout << endl;
  cout << endl;

  //Testing the deleteItem function
  LLL.deleteItem(3);
  LLL.deleteItem(5);
  cout << "Testing deleteItem()" << endl;
  LLL.printItems();
  cout << endl;
  cout << endl;

  //Testing the remainder of the deleteItem function
  LLL.deleteItem(1);
  LLL.deleteItem(2);
  LLL.deleteItem(6);
  LLL.deleteItem(7);
  LLL.deleteItem(8);
  cout << "This list should be empty" << endl;
  LLL.printItems();
  cout << "Yep...the list was empty" << endl;
  cout << endl;
  cout << endl;

  //Testing the destructor operator
  cout << "Testing the destructor" << endl;
  L.~LinkedList();
  cout << "Destructor called.  This program still runs." << endl;
  return 0;
}