#include"LinkedListBasedStack.h"
#include"SinglyLinkedWithoutTail.h"
#include<iostream>

// Class Stack Implementation
Stack::Stack()
{
    Size = 0;
}

void Stack::Push(int key)  // Time Complexity: O(1)
{
    Stack_Space.PushFront(key);
    Size++;
}

int Stack::Top()  // Time Complexity: O(1)
{

    return Stack_Space.TopFront();
}

void Stack::Pop()  // Time Complexity: O(1)
{
    if(Size<1){
        std::cout<<"The Stack is Empty!";
        return;
    }
    Stack_Space.PopFront();
    Size--;
}

bool Stack::Empty()  // Time Complexity: O(1)
{
    return(Size<1);
}

Stack::~Stack(){}
