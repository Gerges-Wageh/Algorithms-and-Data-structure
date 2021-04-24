#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
int main(){
     int n,i=0;
     cin>>n;
     pair<ui,ui>pairs[n];
     for(int i=0;i<n;i++)
        cin>>pairs[i].first>>pairs[i].second;
     sort(pairs,pairs+n,greater<>());
     vector<ui>points;
     set<ui>fake;
     ui temp;
     while(i<n){
        temp=pairs[i].first;
        fake.clear();
        fake.insert(temp);
        i++;
        while(temp<=pairs[i].second&&i<n){
            fake.insert(pairs[i].first);
            i++;
        }
        auto it=fake.end();
        it--;
        temp = *it;
        points.push_back(temp);
     }
     sort(points.begin(),points.end());
     cout<<points.size()<<"\n";
     for(int i=0;i<points.size();i++)
        cout<<points[i]<< " ";
}

