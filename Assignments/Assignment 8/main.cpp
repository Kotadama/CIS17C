#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() 
{

    // Test constructor and add functions
    LinkedList A;
    A.addToRear(5);
    A.addToRear(3);
    A.addToRear(8);
    A.addToRear(1);
    A.addToRear(4);
    A.addToRear(7);

    cout << "Original list A: ";
    A.printItems();

    // Test sort function
    A.sort();
    cout << "Sorted list A: ";
    A.printItems();

    // Test copy constructor
    LinkedList B = A;
    cout << "Copy of A into B: ";
    B.printItems();

    // Test size function
    cout << "Size of A: " << A.size() << endl;
    cout << "Size of B: " << B.size() << endl;

    // Test assignment operator
    A.addToRear(10);
    B = A;
    cout << "After assigning A to B: ";
    B.printItems();

    // Test swapList function
    LinkedList C;
    C.addToRear(100);
    C.addToRear(200);
    cout << "List C before swap: ";
    C.printItems();

    A.swapList(C);
    cout << "List C after swap with A: ";
    C.printItems();
    cout << "List A after swap with C: ";
    A.printItems();

    return 0;
}
