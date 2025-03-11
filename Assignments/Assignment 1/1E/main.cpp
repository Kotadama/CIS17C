#include <iostream>

using namespace std;

// FUNCTION PROTOTYPE
void deleteS(char* str);

int main()
{
    char a[] = "Silly snakes swiftly slither silently southward, seeking sweet snacks.";
    
    cout << "Original string: " << a << endl;// Display the original string

    deleteS(a);// Call the function to delete 's' and 'S' characters

    cout << "Modified string: " << a << endl; // Display the modified string

    return 0;
}

// FUNCTION DEFINITION
void deleteS(char* str)
{
    char* p = str; // Pointer to traverse the string
    
    // Traverse the string until the null terminator is reached
    while (*str != 0)
    {
        if (*str != 's' && *str != 'S') 
        {
            *p = *str;  // If not 's' or 'S', copy the character
            p++;         // Move p to the next position
        }
        str++;  // Move str to the next character
    }

    *p = 0; // Null-terminate the string after modifications
}
