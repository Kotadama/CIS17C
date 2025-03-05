#include <iostream>

using namespace std;

// FUNCTION PROTOTYPE
bool match(const char[], const char[]);

int main()
{
    char a[10] = "pointy";
    char b[10] = "pointless";
    
    if (match(a,b))
    {
        cout << "They're the same!\n";
    }
    else
    {
        cout << "They're different!\n";
    }
    return 0;
}

//FUNCTION DEFINITION
// This function takes two C-strings as arguments and returns true if they are the same, false otherwise
bool match(const char str1[], const char str2[]) 
{
    while (*str1 != 0 && *str2 != 0) 
    { // zero bytes at ends
        if (*str1 != *str2) 
        { 
            return false;
        }
        str1++; // advance to the next character
        str2++;
    }
    return *str1 == *str2; // both ended at the same time?
}