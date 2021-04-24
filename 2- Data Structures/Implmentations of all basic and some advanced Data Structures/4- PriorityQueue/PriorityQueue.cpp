#include"PriorityQueue.h"
#include<iostream>
#include<algorithm>

//Class PriorityQueue Implementation

PriorityQueue::PriorityQueue()  // Time Complexity: O(1)
{
    Size = 0;
}

int PriorityQueue::Parent(int i)  // Time Complexity: O(1)
{
    return (i-1)/2;
}

int PriorityQueue::LeftChild(int i)  // Time Complexity: O(1)
{
    return 2*i+1;
}

int PriorityQueue::RightChild(int i)  // Time Complexity: O(1)
{
    return 2*i+2;
}

void PriorityQueue::SiftDown(int i)  // Time Complexity: O(logn)
{
    if(Size==0)
        return;
    int m = i;
    int l = LeftChild(i);
    if(l<Size && H[l]>H[m])
        m = l;
    int r = RightChild(i);
    if(r<Size && H[r]>H[m])
        m = r;
    if(i != m){
        std::swap(H[i],H[m]);
        SiftDown(m);
    }
}
void PriorityQueue::SiftUp(int i)  // Time Complexity: O(logn)
{
    while(i>0 && H[i]>H[Parent(i)]){
        std::swap(H[i],H[Parent(i)]);
        i=Parent(i);
    }
}
void PriorityQueue::Insert(int key)  // Time Complexity: O(logn)
{
    if(Size>=MAX_SIZE)
        return;

    H[Size]=key;
    SiftUp(Size);
    Size++;
}
void PriorityQueue::Remove(int i)  // Time Complexity: O(logn)
{
    H[i] = INT_MAX;
    SiftUp(i);
    ExtractMax();
}
int PriorityQueue::GetSize()  // Time Complexity: O(1)
{
    return Size;
}
void PriorityQueue::ChangePriority(int i, int p) // Time Complexity: O(logn)
{
    if(i<0 || i>=Size)
        return;
    if(p > H[i]){
        H[i]=p;
        SiftUp(i);
    }
    else{
        H[i]=p;
        SiftDown(i);
    }


}
int PriorityQueue::ExtractMax()  // Time Complexity: O(logn)
{
    if(Size==0)
        return INT_MIN;

    int m = H[0];
    H[0]=H[Size-1];
    Size--;
    SiftDown(0);
    return m;
}
void PriorityQueue::Print()  // Time Complexity: O(n)
{
    std::cout<<"Binary Heap Content: ";
    for(int i=0;i<Size;i++)
        std::cout<<H[i]<< " ";
    std::cout<<"\n";
}
PriorityQueue::~PriorityQueue(){}
