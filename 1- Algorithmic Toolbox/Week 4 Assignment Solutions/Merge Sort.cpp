#include<bits/stdc++.h>
using namespace std;

/// Sorting Problem ///
// Merge Sort Algorithm
// Time Complexity: O(n log(n))

void Merge(int arr[], int l, int m, int r){
    int i=0,j=0,k=l;
    int s1=m-l+1;
    int s2=r-m;
    int left[s1], right[s2];
    for(int i=0;i<s1;i++)left[i]=arr[l+i];
    for(int i=0;i<s2;i++)right[i]=arr[m+i+1];
    while(i<s1&&j<s2){
        if(left[i]<right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<s1)
        arr[k++]=left[i++];
    while(j<s2)
        arr[k++]=right[j++];
}
void MergeSort(int arr[], int l, int r){
    if(l==r)
        return;

    int m = l + (r-l)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    Merge(arr,l,m,r);
}

// Driver Code
int main(){
    int A[]{5,3,10,6,4,1};
    cout<<"Given Sequence: ";
    for(int i=0;i<6;i++)cout<<A[i]<<" ";
    MergeSort(A,0,5);
    cout<<endl<<"Sorted Sequence: ";
    for(int i=0;i<6;i++)cout<<A[i]<< " ";

    return 0;
}