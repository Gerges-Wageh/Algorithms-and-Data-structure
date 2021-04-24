#include<bits/stdc++.h>
using namespace std;
unsigned int gcd(unsigned int a,unsigned int b){
    if(b==0)
        return a;
    unsigned int x=a%b;
    return gcd(b,x);
}
int main(){
    unsigned int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}




