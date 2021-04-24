#include"LinkedListBasedQueue.h"
#include<iostream>

// Class Queue Implementation

Queue::Queue() //Time Complexity: O(1)
{
    Size = 0;
}

void Queue::Enqueue(int key) //Time Complexity: O(1)
{
    Queue_Space.PushBack(key);
    Size++;
}

int Queue::Dequeue() //Time Complexity: O(1)
{
    if(Size<1){
        std::cout<<"The Queue is Empty!";
        return -1;
    }
    int x = Queue_Space.TopFront();
    Queue_Space.PopFront();
    Size--;
    return x;
}

bool Queue::Empty() //Time Complexity: O(1)
{
    return(Size<1);
}
Queue::~Queue(){}
