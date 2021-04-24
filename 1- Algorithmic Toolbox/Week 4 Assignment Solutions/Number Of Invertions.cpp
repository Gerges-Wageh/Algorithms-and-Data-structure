#include<bits/stdc++.h>
using namespace std;

/// Number Of Inversions ///
// Based on Merge Sort Algorithm
// Time Complexity: O(n log(n))

int Merge(int arr[], int l, int m, int r){
    int i=0,j=0,k=l,c=0;
    int s1=m-l+1;
    int s2=r-m;
    int left[s1], right[s2];
    for(int i=0;i<s1;i++)left[i]=arr[l+i];
    for(int i=0;i<s2;i++)right[i]=arr[m+i+1];
    while(i<s1&&j<s2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else{
            arr[k++]=right[j++];
            c+=(s1-i);
        }
    }
    while(i<s1)
        arr[k++]=left[i++];
    while(j<s2)
        arr[k++]=right[j++];
    return c;
}
int Number_Of_Invertions(int arr[], int l, int r){
    if(l==r)
        return 0;

    int m = l + (r-l)/2;
    return Number_Of_Invertions(arr,l,m)+Number_Of_Invertions(arr,m+1,r)+Merge(arr,l,m,r);
}

// Driver Code
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<Number_Of_Invertions(arr,0,n-1);

    return 0;
}
