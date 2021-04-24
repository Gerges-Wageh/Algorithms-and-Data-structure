#include<bits/stdc++.h>
using namespace std;

int Fibb_Sum(int n){
    if(n<=1)
        return n;
    int x1=1,x2=0,temp,sum=1;
    for(int i=2;i<=n;i++){
        temp=(x1+x2)%10;
        sum += pow(temp%10,2);
        x2=x1;
        x1=temp;
    }
    return sum%10;
}

int main(){
    unsigned long long n;
    cin>>n;
    cout<<Fibb_Sum(n%60);

    return 0;
}
