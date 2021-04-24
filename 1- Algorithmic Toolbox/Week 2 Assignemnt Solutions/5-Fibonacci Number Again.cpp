#include<bits/stdc++.h>
using namespace std;

int PisanoPeriodLength(int m) {
    int a = 0, b = 1, c;
    for (int i = 0; i < m*m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
unsigned long long fibb(unsigned long long n, int m){
    if(n<=1)
        return n;
    unsigned long long x1,x2,temp;
    x1=1;
    x2=0;
    for(int i=2;i<n;i++){
        temp=(x1+x2)%m;
        x2=x1;
        x1=temp;
    }
    return (x1+x2)%m;

}
int main(){
    unsigned long long n;
    int m;
    cin>>n>>m;
    int PPL = PisanoPeriodLength(m);
    n %= PPL;
    cout<<fibb(n,m);
    
    return 0;
}



