#include <iostream>
using namespace std;

//FUNCTION PROTOTYPE
void findDisorder(int[], int, int*&);

int main()
{
    int nums[6] = {10, 20, 20, 40, 30, 50};
    int* ptr;

    findDisorder(nums, 6, ptr);  // Call the function

    if (ptr == nullptr)
    {
        cout << "The array is ordered" << endl;
    }
    else
    {
        cout << "The disorder is at address " << ptr << endl;
        cout << "It's at index " << ptr - nums << endl;
        cout << "The item's value is " << *ptr << endl;
    }

    return 0;
}

//FUNCTION DEFINITION
void findDisorder(int arr[], int n, int* &p)
{
    for (int k = 1; k < n; k++)
    {
        if (arr[k] < arr[k - 1]) // Check for disorder
        {
            p = arr + k;  // Set pointer to the first disorder element
            return;        // Exit the function once disorder is found
        }
    }
    p = nullptr;  // If no disorder is found, set p to nullptr
}