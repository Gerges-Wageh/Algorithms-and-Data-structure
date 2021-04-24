#include<bits/stdc++.h>
using namespace std;

int main(){
    int S,n,t,i;
    cin>>S>>n;
    if(n==0)
        return 0;
    pair<int,int> x[n];
    for(i=0;i<n;i++)
        cin>>x[i].first>>x[i].second;
    queue<pair<int,int>> Q;
    queue<int>op,finish_time;
    t=x[0].first;
    for(i=0;i<S;i++){
        Q.push(x[i]);
        if(x[i].first>t){
            op.push(x[i].first);
            finish_time.push(x[i].first+x[i].second);
            t=x[i].first;
        }
        else{
            op.push(t);
            finish_time.push(t+x[i].second);
            t+=x[i].second;
        }
    }

    while(i<n){
        if(x[i].first>=finish_time.front()){
             if(x[i].first>t){
                op.push(x[i].first);
                finish_time.push(x[i].first+x[i].second);
                t=x[i].first;
            }
            else{
                op.push(t);
                finish_time.push(t+x[i].second);
                t+=x[i].second;
            }
            Q.pop();
            Q.push(x[i]);
            finish_time.pop();
        }
        else{
            op.push(-1);
        }
        
        i++;
    }
    while(!op.empty()){
        cout<<op.front()<<endl;
        op.pop();
    }

    return 0;
}
