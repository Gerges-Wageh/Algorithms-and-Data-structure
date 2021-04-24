#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
ui Maximum(vector<ui>&x){
    if(x.size()==1)
        return x[0];
    ui m=x[0];
    for(int i=1;i<x.size();i++)
        m=max(m,x[i]);
    return m;
}
int main(){
     int n,i=0;
     cin>>n;
     pair<ui,ui>pairs[n];
     for(int i=0;i<n;i++)
        cin>>pairs[i].first>>pairs[i].second;
     sort(pairs,pairs+n,greater<>());
     vector<ui>points,fake;
     ui temp;
     while(i<n){
        temp=pairs[i].first;
        fake.clear();
        fake.push_back(temp);
        i++;
        while(temp<=pairs[i].second&&i<n){
            fake.push_back(pairs[i].first);
            i++;
        }
        temp = Maximum(fake);
        points.push_back(temp);
     }
     sort(points.begin(),points.end());
     cout<<points.size()<<"\n";
     for(int i=0;i<points.size();i++)
        cout<<points[i]<< " ";
}

