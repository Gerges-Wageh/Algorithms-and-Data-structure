#include<bits/stdc++.h>

using namespace std;

int DPChange(int money, vector<int>& coins){
    int MinNumCoins[money+1];
    MinNumCoins[0] = 0;
    int NumCoins;
    for(int i=1;i<=money;i++){
        MinNumCoins[i] = INT_MAX;
        for(int j=0;j<coins.size();j++){
            if(i >= coins[j]){
                NumCoins = MinNumCoins[i-coins[j]] + 1;
                if(NumCoins < MinNumCoins[i])
                    MinNumCoins[i] = NumCoins;
            }
        }
    }
    return MinNumCoins[money];
}

int main(){

   vector<int> coins{4,3,1};
   int money;
   cin>>money;
   cout<<DPChange(money, coins);

    return 0;
}
