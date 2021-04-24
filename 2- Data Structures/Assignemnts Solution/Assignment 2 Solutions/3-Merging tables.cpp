#include<bits/stdc++.h>
#define MAX_SIZE 100001
using namespace std;

int Max=0;
class Disjoint_Set{
public:
    pair<int,int> Parent[MAX_SIZE];
    int Rank[MAX_SIZE];
public:
    void MakeSet(int x, int data){
        Parent[x].first=x;
        Parent[x].second=data;
        Rank[x]=0;
    }
    pair<int,int> Find(int x){
        if(x != Parent[x].first)
            Parent[x].first=Find(Parent[x].first).first;
        return make_pair(Parent[x].first,Parent[x].second);
    }
    void Union(int destination, int source){
        pair<int,int> P_destination = Find(destination);
        pair<int,int> P_source = Find(source);
        if(P_destination.first == P_source.first){
                cout<<Max<<"\n";
                return;
        }
        if(Rank[P_destination.first]>Rank[P_source.first]){
            Parent[P_destination.first].second+=Parent[P_source.first].second;
            if(Parent[P_destination.first].second>Max)
                Max=Parent[P_destination.first].second;
            cout<<Max<<"\n";
            Parent[P_source.first].second=0;
            Parent[P_source.first].first=P_destination.first;
        }
        else{
            if(Rank[P_destination.first]==Rank[P_source.first])
                Rank[P_source.first]+=1;
            Parent[P_source.first].second+=Parent[P_destination.first].second;
            if(Parent[P_source.first].second>Max)
                Max=Parent[P_source.first].second;
            cout<<Max<<"\n";
            Parent[P_destination.first].second=0;
            Parent[P_destination.first].first=P_source.first;
        }
    }
};

int main(){
    int n,m,x,y;
    cin>>n>>m;
    Disjoint_Set S;
    for(int i=1;i<=n;i++){
        cin>>x;
        S.MakeSet(i,x);
        if(x>Max)
            Max=x;
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        S.Union(x,y);
    }

    return 0;
}
