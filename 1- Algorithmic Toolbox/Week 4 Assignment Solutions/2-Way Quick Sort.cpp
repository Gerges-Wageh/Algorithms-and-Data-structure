#include<bits/stdc++.h>
using namespace std;

// Selection sort algorithm
// Time COmplexity: O(n^2)
void SelectionSrot(int arr[], int n){
    int min_idx;
    for(int i=0;i<n-1;i++){
        min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        swap(arr[i],arr[min_idx]);
    }

}

int Partitioning(int A[], int l, int r){
    int temp[r-l+1];
    int left_idx=l, right_idx=r;
    for(int i=0;i<r-l+1;i++)temp[i]=A[i+l];
    for(int i=1;i<r-l+1;i++){
        if(temp[i]<=temp[l])
            A[left_idx++]=temp[i];
        else
            A[right_idx--]=temp[i];
    }
    A[right_idx]=temp[l];
    return right_idx;
}

int Partitioning_2(int A[], int l, int r){
    int j=l;
    for(int i=l+1;i<=r;i++){
        if(A[i]<A[l]){
            swap(A[j+1],A[i]);
            j++;
        }
    }
    swap(A[l],A[j]);
    return j;
}

// Quick sort Algorithm
//Time Complexity: O(n log(n)) in average
void QuickSort(int A[], int l, int r){
    if(l>=r)
        return;
    int k = l + rand() % (r - l + 1);
    swap(A[l],A[k]);
    int m = Partitioning_2(A,l,r);
    QuickSort(A,l,m-1);
    QuickSort(A,m+1,r);
}

// Driver code 
int main()
{
    int A[]{1,2,5,2,1,9,2,2};
    QuickSort(A,0,7);
    for(int i=0;i<8;i++)cout<<A[i]<< " ";

    return 0;
}