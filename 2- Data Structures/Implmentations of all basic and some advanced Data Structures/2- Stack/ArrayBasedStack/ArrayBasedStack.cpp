#include "ArrayBasedStack.h"
#include<iostream>

// Class Stack Implementation
Stack::Stack()
{
    Size = 0;
}

void Stack::Push(int key)  // Time Complexity: O(1)
{
    if(Size>=1000){
        std::cout<<"The Stack is Full!";
        return;
    }
    Stack_Space[Size]=key;
    Size++;
}

int Stack::Top()  // Time Complexity: O(1)
{
    if(Size<1){
        std::cout<<"The Stack is Empty!";
        return -1;
    }
    return Stack_Space[Size-1];
}

void Stack::Pop()  // Time Complexity: O(1)
{
    if(Size<1){
        std::cout<<"The Stack is Empty!";
        return;
    }
    Size--;
}

bool Stack::Empty()  // Time Complexity: O(1)
{
    return(Size<1);
}

Stack::~Stack(){}
