#include <iostream>
#include "MyStack.h"
#include "swap.h"

using namespace std;

int main()
{
    //Test the MyStack() constructor and the printStack() & push(T) member functions
    cout << "I am testing MyStack(), printStack(), and push(T)" << endl;
    MyStack<int> A;
    cout << "I am printing out the empty MyStack object A" << endl;
    A.printStack();
    cout << endl;

    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);
    A.push(6);
    cout << "I am printing out MyStack object A containing 6 5 4 3 2 1" << endl;
    A.printStack();
    cout << endl;
    cout << endl;

    //Test the copy constructor
    cout << "I am testing the MyStack copy constructor" << endl;
    MyStack<int> B = A;
    cout << "I am printing out MyStack Object B containing 6 5 4 3 2 1" << endl;
    B.printStack();
    cout << endl;
    cout << endl;

    //Test the peek(), pop(), and size() member functions
    cout << "I am testing peek: the top of the stack is " << A.peek() << endl;
    cout << "I didn't remove anything from the stack though...see" << endl;
    A.printStack();
    cout << endl;
    cout << "And the size of A is: " << A.size() << endl;
    cout << endl;
    cout << "Now I am testing pop: the item that I am removing is " << A.pop() << endl;
    cout << "So now 6 should be removed from the top of the stack..." << endl;
    A.printStack();
    cout << "And the size of A is: " << A.size() << endl;
    cout << endl;
    cout << endl;

    //Test the overloaded assignment operator
    cout << "Time to test the assignment (=) operator." << endl;
    A.pop();
    B = A;
    cout << "MyStack object B should now hold 4 3 2 1" << endl;
    B.printStack();
    cout << endl;
    cout << endl;

    //What happens when I try to peek into an empty stack?
    cout << "Let's find out what happens when I peek or pop an empty MyStack" << endl;
    MyStack<int> C;
    cout << "Here I try to peek into an empty stack: " << C.peek() << endl;
    cout << "Here I try to pop from an empty stack: " << C.pop() << endl;
    cout << endl;
    cout << endl;

    //Test cascading effect of assignment operator
    A.pop();
    A.pop();
    C = B = A;
    cout << "The contents of MyStack object A are:" << endl;
    A.printStack();
    cout << endl;
    cout << "The contents of MyStack object B are:" << endl;
    B.printStack();
    cout << endl;
    cout << "The contents of MyStack object C are:" << endl;
    C.printStack();
    cout << endl;
    cout << endl;

    //Testing the swap function from swap.h
    cout << "Testing the swap() function from swap.h" << endl;
    MyStack<int> D;
    D.push(100);
    D.push(200);
    cout << "Stack A before swap: ";
    A.printStack();
    cout << "Stack D before swap: ";
    D.printStack();

    swap(A, D);
    cout << "Stack A after swap: ";
    A.printStack();
    cout << "Stack D after swap: ";
    D.printStack();
    cout << endl;
    cout << endl;

    // Test MyStack with strings to demonstrate full template functionality
    cout << "Testing MyStack with strings" << endl;
    MyStack<string> E;
    E.push("Apple");
    E.push("Banana");
    E.push("Cherry");
    cout << "MyStack object E contains: ";
    E.printStack();

    MyStack<string> F;
    F.push("X");
    F.push("Y");
    cout << "MyStack object F contains: ";
    F.printStack();

    cout << "Swapping E and F" << endl;
    swap(E, F);
    cout << "After swap, E contains: ";
    E.printStack();
    cout << "After swap, F contains: ";
    F.printStack();
    cout << endl;
    cout << endl;

    //Testing the destructor explicitly
    cout << "Testing the destructor" << endl;
    cout << "Destructor called" << endl;
    A.~MyStack();
    cout << "This program still runs" << endl;

    return 0;
}
