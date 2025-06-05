#ifndef SWAP_H
#define SWAP_H

// swap.h - Templated swap subroutine for MyStack (or any templated class with assignment operator)

template<typename T>

void swap(T& obj1, T& obj2)
{
    T temp = obj1;   // Create a temporary copy of obj1
    obj1 = obj2;     // Assign obj2 into obj1
    obj2 = temp;     // Assign original obj1 into obj2
}

#endif
