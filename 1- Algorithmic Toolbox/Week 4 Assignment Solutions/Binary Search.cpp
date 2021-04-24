#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int l, int r, int key){
    int m = l+(r-l)/2;
    if(l>r)
        return -1;
    else if(arr[m]==key)
        return m;
    else if(key>arr[m])
        return BinarySearch(arr,m+1,r,key);
    else
        return BinarySearch(arr,l,m-1,key);
}
int main(){
    int n,k;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    cin>>k;
    int key;
    for(int i=0;i<k;i++){
        cin>>key;
        cout<<BinarySearch(A,0,n-1,key)<< " ";
    }
    return 0;
}
