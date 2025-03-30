#include "MyStack.h" // Include the class header
#include <climits>

MyStack::MyStack()
{
	head = nullptr; // Initialize head to nullptr
}

MyStack::MyStack(const MyStack& rhs)
{
	head = nullptr; // Initialize head to nullptr
	*this = rhs;    // Use the assignment operator to copy
}
MyStack& MyStack::operator=(const MyStack& rhs)
{
	if (this == &rhs)  // Check for self-assignment
	{
		return *this;
	}

	// Clear the current stack
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	head = nullptr; // Reset head

	// Copy nodes from rhs
	Node* temp = rhs.head;
	while (temp != nullptr)
	{
		push(temp->data); // Use push to add elements to the stack
		temp = temp->next;
	}

	return *this;
}


	

void push(int v) 
{
	Node* newNode = new Node(); // Create a new node
    newNode->data = v;          // Set the data
    newNode->next = head;       // Point the new node to the current head
    head = newNode;  
}

int pop()
{
	//remove the item at the top of the stack
}

int peek()
{
	//print the item at the top of the stack

}

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

void printStack()
{
	 // Start from the first node
	 Node* current = headDummy.next;

	 // Traverse the list and print the data of each node
	 while (current != nullptr)
	 {
		 std::cout << current->data << " ";
		 current = current->next;
	 }
	 std::cout << std::endl;
}

~MyStack()
{
	// Start from the first node
	Node* current = headDummy.next;

	// Delete all nodes in the list
	while (current != nullptr)
	{
		Node* temp = current; 
		current = current->next;
		delete temp;
	}
	headDummy.next = nullptr;  // Ensure head points to tail after deletion
	
}