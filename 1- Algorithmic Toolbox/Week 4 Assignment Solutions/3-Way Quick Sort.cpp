#include<bits/stdc++.h>
using namespace std;

// 3-Way Partitioning
pair <int,int> Partitioning(int A[], int l, int r){
    int j=l, k=l;
    pair <int, int> indexes;
    for(int i=l+1;i<=r;i++){
        if(A[i]<A[l]){
            swap(A[i],A[k+1]);
            swap(A[k+1],A[j+1]);
            j++;
            k++;
        }
        else if(A[i]==A[l]){
            swap(A[i],A[k+1]);
            k++;
        }
    }
    swap(A[l],A[j]);
    indexes = make_pair(j,k);
    return indexes;
}

// Improved Quick sort Algorithm using 3-way partitioning
// This improvement (3-way partitioning) saves a lot of time when there are equal elements in the given sequence
// Time Complexity: O(n log(n)) in average
void Randamized_QuickSort(int A[], int l, int r){
    if(l>=r)
        return;
    int k = l + rand() % (r - l + 1);
    swap(A[l],A[k]);
    pair<int,int> indexes;
    indexes = Partitioning(A,l,r);
    Randamized_QuickSort(A,l,indexes.first-1);
    Randamized_QuickSort(A,indexes.second+1,r);
}

// Driver Code
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    Randamized_QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)cout<<arr[i]<< " ";

    return 0;
}
