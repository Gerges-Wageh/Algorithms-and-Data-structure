#include<bits/stdc++.h>
using namespace std;

static int Max_weight[301][10001];

int MaxAmountOfGold(int W, int n, int w[]){
    int weight;
    for(int i=0;i<=n;i++)Max_weight[i][0]=0;
    for(int j=0;j<=W;j++)Max_weight[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            Max_weight[i][j]=Max_weight[i-1][j];
            if(j>=w[i-1]){
                    weight = Max_weight[i-1][j-w[i-1]]+w[i-1];
                    if(weight>Max_weight[i][j])
                        Max_weight[i][j]=weight;
            }
        }
    }

    return Max_weight[n][W];
}
int main()
{
    int W,n;
    cin>>W>>n;
    int w[n];
    for(int i=0;i<n;i++)cin>>w[i];
    cout<<MaxAmountOfGold(W,n,w);


    return 0;
}