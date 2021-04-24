#include<bits/stdc++.h>
using namespace std;

int Maximum(vector<int>&x){
    if(x.size()==1)
        return x[0];
    int m=x[0];
    for(int i=1;i<x.size();i++)
        m=max(m,x[i]);
    return m;
}
int main(){
     int n,a,b,i=0;
     bool flag = 0;
     cin>>n;
     vector <pair<int,char>>pairs;
     for(int i=0;i<n;i++){
        cin>>a>>b;
        pairs.push_back(make_pair(a,'l'));
        pairs.push_back((make_pair(b,'r')));
     }
     sort(pairs.begin(),pairs.end());
     vector<int>points,fake;
     while(i<2*n){
        fake.clear();
        while(pairs[i].second=='l'){
            fake.push_back(pairs[i].first);
            i++;
            flag = 1;
        }
        if(flag){
            points.push_back(Maximum(fake));
            flag = 0;
        }
        i++;
     }
     cout<<points.size()<<endl;
     for(int i=0;i<points.size();i++)
        cout<<points[i]<< " ";
}

