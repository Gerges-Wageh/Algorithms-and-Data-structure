#include<bits/stdc++.h>
using namespace std;
unsigned long long fibb(int n){
    if(n<=1)
        return n;
    unsigned long long x1,x2,temp;
    x1=1;
    x2=0;
    for(int i=2;i<n;i++){
        temp=(x1+x2);
        x2=x1;
        x1=temp;
    }
    return x1+x2;

}
int main(){
    int n;
    cin>>n;
    cout<<fibb(n);
}




