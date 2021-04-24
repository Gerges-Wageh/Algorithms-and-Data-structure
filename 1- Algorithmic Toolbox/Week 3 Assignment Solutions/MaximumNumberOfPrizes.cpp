#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
int main(){
    ui n,i=1;
    cin>>n;
    vector<ui>x;
    while(n>0){
        if(n-i>i||n-i==0){
            x.push_back(i);
            n-=i;
        }
        i++;
    }
    cout<<x.size()<<endl;
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
}
