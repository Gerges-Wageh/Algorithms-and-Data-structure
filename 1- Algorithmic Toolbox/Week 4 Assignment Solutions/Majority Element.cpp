#include<bits/stdc++.h>
using namespace std;

/// Finding the Majority Element in an array ///
// 1- Naive iterative solution
// Time Complexity: O(n^2)
int Naive_Iterative_MajorityElement(int arr[], int n){
    if(n==1)
        return arr[0];
    int c;
    for(int i=0;i<n-1;i++){
        c = 1;
        for(int j=i+1;j<n;j++){
            if(arr[j]==arr[i])
                c++;
        }
        if(c>n/2)
            return arr[i];
    }
    return -1;
}

// 2- Naive recursive solution
// Time Complexity: O(n^2)
int Naive_Recursive_MajorityElement(int arr[], int n, int inx){
    if(inx==n-1){
        return arr[0];
    }
    int c = 1;
    for(int i=inx+1;i<n;i++){
        if(arr[i]==arr[inx])
            c++;
    }
    if(c>n/2)
        return arr[inx];

    if(inx==n-2){
        return -1;
    }
    return  Naive_Recursive_MajorityElement(arr,n,inx+1);
}

// 3- Divide and Conquer solution
// Time Complexity: O(n log(n))
int MajorityElement(int arr[], int l, int r){
    if(r==l)
        return arr[l];
    int m = l + (r-l)/2;
    int n = r-l+1;
    int M1 = MajorityElement(arr,l,m);
    int M2 = MajorityElement(arr,m+1,r);
    int counter = 0;
    for(int i=l;i<=r;i++){
        if(arr[i]==M1)
            counter++;
    }
    if(counter>n/2)
        return M1;
    counter = 0;
    for(int i=l;i<=r;i++){
        if(arr[i]==M2)
            counter++;
    }
     if(counter>n/2)
        return M2;

    return -1;
}

// 4- Another solution based on sorting the array in advance
// Time complexity: O(n log(n))
int Sorting_Based_Majority_Element(int arr[], int n){
    sort(arr,arr+n);
    int c = 1;
     for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])
            c++;
        else
            c=1;
        if(c>n/2)
            return arr[i];
    }

    return -1;
}

//Driver Code
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    (MajorityElement(arr,0,n-1)==-1)?cout<<"0":cout<<"1";

    return 0;
}
