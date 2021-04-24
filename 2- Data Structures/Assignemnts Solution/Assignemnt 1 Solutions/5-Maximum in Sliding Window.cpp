#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c=0;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)cin>>x[i];
    cin>>m;
    deque<int> Q;
    stack<int> S;

    Q.push_back(0);
    for(int i=1;i<n;i++){
        while(x[i]>x[Q.back()]&&Q.size()>1&&i-Q.back()<m){
            Q.pop_back();
        }
        if(!Q.empty())
            if(x[i]>x[Q.back()]&&i-Q.back()<m){
                Q.pop_back();
            }

        Q.push_back(i);
        if(i>=m-1){
            cout<<x[Q.front()]<<" ";
            c++;
            if(i-Q.front()>=m-1)
                Q.pop_front();
        }

    }
    if(c<n-m+1)
        cout<<x[Q.front()];
    return 0;
}
