#include<bits/stdc++.h>
using namespace std;
unsigned long long LCM(int a, int b){
    unsigned long long temp,i=1,x,y;
    x=max(a,b);
    y=min(a,b);
    if(x%y==0)
        return x;
    while(1){
        temp = y*i;
        if(temp%x==0)
            return temp;
        i++;
    }

}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<LCM(a,b);
}




