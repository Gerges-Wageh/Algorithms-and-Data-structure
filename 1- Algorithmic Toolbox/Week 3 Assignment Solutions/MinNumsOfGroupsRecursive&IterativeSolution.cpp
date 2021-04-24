#include<bits/stdc++.h>
using namespace std;
//Iterative Solution
int MinNumsOfGroups(double x[],int n){
    int R=1,i=1;
    double Leftpoint=x[0];
    while(i<n){
        if(x[i]-Leftpoint<=1)i++;
        else{
            Leftpoint=x[i];
            R++;
        }
    }
    return R;
}
//Recursive Solution
int MinRecursively(double a[],int l, int r){
    if(l>=r)
        return 1;
    double Leftpoint = a[l];
    l++;
    while(l<=r){
        if(a[l]-Leftpoint<=1)
            l++;
        else
            break;
    }
    return 1+MinRecursively(a,l,r);

}

int main(){
    double a[]{2,2.3,2.5,3,3.5,3.9,5,6,9,12}; 
    //if the array not sorted sort it before in O(nlogn)
    cout<<"Recursive Solution: "<<MinRecursively(a,0,9)<<endl;
    cout<<"Iterative Solution: "<<MinNumsOfGroups(a,10)<<endl;
}




