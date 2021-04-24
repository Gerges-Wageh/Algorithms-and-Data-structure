#include<bits/stdc++.h>
using namespace std;
int MinNumOfCoins(int m){
    int coins[3]{10,5,1};
    int i=0,counter=0;
    while(m){
        while(m&&coins[i]<=m){
            m-=coins[i];
            counter++;
        }
        i++;
    }
    return counter;
}
int main(){
    int m;
    cin>>m;
    cout<<MinNumOfCoins(m);
}




