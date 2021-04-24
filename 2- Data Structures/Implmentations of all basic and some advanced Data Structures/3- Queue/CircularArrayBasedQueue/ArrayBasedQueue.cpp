#include"ArrayBasedQueue.h"
#include<iostream>

// Class Queue Implementation

Queue::Queue()  // Time Complexity: O(1)
{
    read_ptr = 0;
    write_ptr =0;
}

void Queue::Enqueue(int key)  // Time Complexity: O(1)
{
    if((write_ptr+1)%MAX_SIZE == read_ptr%MAX_SIZE){
        std::cout<<"The Queue is Full!";
        return;
    }
    Queue_Space[write_ptr%MAX_SIZE]=key;
    write_ptr++;
    if(write_ptr==MAX_SIZE)
        write_ptr=0;
}

int Queue::Dequeue()  // Time Complexity: O(1)
{
    int x;
    if(write_ptr%MAX_SIZE == read_ptr%MAX_SIZE){
        std::cout<<"The Queue is Empty!";
        return -1;
    }
    x=Queue_Space[read_ptr%MAX_SIZE];
    read_ptr++;
    if(read_ptr==MAX_SIZE)
        read_ptr=0;

    return x;
}

bool Queue::Empty() // Time Complexity: O(1)
{
    return(read_ptr==write_ptr);
}
Queue::~Queue(){}
