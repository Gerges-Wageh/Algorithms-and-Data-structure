#include<bits/stdc++.h>
using namespace std;

static int MinNumOp[1000001];

void PrimitiveCalculator(int n){
    int NumOp;
    MinNumOp [1] = 0;
    for(int i=2;i<=n;i++){
        MinNumOp[i] = INT_MAX;
        if(i%3==0){
            NumOp = MinNumOp[i/3]+1;
            if(NumOp < MinNumOp[i])
                MinNumOp[i] = NumOp;
        }
        if(i%2==0){
            NumOp = MinNumOp[i/2]+1;
            if(NumOp < MinNumOp[i])
                MinNumOp[i] = NumOp;
        }
        NumOp = MinNumOp[i-1]+1;
        if(NumOp < MinNumOp[i])
                MinNumOp[i] = NumOp;
    }
    cout<<MinNumOp[n]<<"\n";
    stack<int>numbers;
    numbers.push(n);
    while(n>1){
        if(n%2==0){
            if(MinNumOp[n]==MinNumOp[n/2]+1){
                numbers.push(n/2);
                n/=2;
            }
            else{
                numbers.push(n-1);
                n-=1;
            }
        }
        else if(n%3==0){
            if(MinNumOp[n]==MinNumOp[n/3]+1){
            numbers.push(n/3);
            n/=3;
            }
            else{
                numbers.push(n-1);
                n-=1;
            }
        }
        else{
             numbers.push(n-1);
                n-=1;
        }

    }
    while(!numbers.empty()){
        cout<<numbers.top()<<" ";
        numbers.pop();
    }

}


int main(){
    int n;
    cin>>n;
    PrimitiveCalculator(n);

    return 0;
}
