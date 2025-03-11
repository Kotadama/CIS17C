#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE
void hypotenuse(double, double, double*);

int main()
{
    double result;  // Declare a double variable to store the result
    double* p = &result;  // Initialize the pointer to the address of 'result'

    hypotenuse(1.5, 2.0, p);  // Pass the pointer to the function

    cout << "The hypotenuse is " << *p << endl;  
}

// FUNCTION DEFINITION
void hypotenuse(double leg1, double leg2, double* resultPtr)
{
    *resultPtr = sqrt(leg1 * leg1 + leg2 * leg2);  // Calculate the hypotenuse and store it at the address pointed to by 'resultPtr'
}
