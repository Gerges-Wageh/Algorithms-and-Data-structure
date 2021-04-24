#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// In-Place HeapSort implementation using Binary Heap_max complete tree.

int Parent(int i)  // Time Complexity: O(1)
{
    return (i-1)/2;
}
int LeftChild(int i)  // Time Complexity: O(1)
{
    return 2*i+1;
}
int RightChild(int i)  // Time Complexity: O(1)
{
    return 2*i+2;
}
void SiftUp(int A[], int n, int i)  // Time Complexity: O(log(n))
{
    while(i>0 && i<n && A[i]>A[Parent(i)]){
        std::swap(A[i],A[Parent(i)]);
        i = Parent(i);
    }
}
void SiftDown(int A[], int n, int i)  // Time Complexity: O(log(n))
{
    if(n == 0)
        return;
    int MaxIndex = i;
    int l = LeftChild(i);
    if(l<n && A[l]>A[MaxIndex])
        MaxIndex = l;
    int r = RightChild(i);
    if(r<n && A[r]>A[MaxIndex])
        MaxIndex = r;
    if( i != MaxIndex){
        std::swap(A[i],A[MaxIndex]);
        SiftDown(A,n,MaxIndex);
    }
}
void BuildHeap(int A[], int n)  // Time Complexity: O(n)
{
    for(int i=n/2;i>=0;i--){
        SiftDown(A,n,i);
    }
}

void HeapSort(int A[], int n)  // Time Complexity: O(nlog(n))
{
    BuildHeap(A,n);
    for(int i=n-1;i>0;i--){
        std::swap(A[0],A[i]);
        SiftDown(A,i,0);
    }
}

int main(){

    int A[]{62,51,30,100,55,1};
    HeapSort(A,6);
    for(int i=0;i<6;i++)cout<<A[i]<< " ";

    return 0;
}
