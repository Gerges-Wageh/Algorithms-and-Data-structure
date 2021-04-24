#include<bits/stdc++.h>
#include<algorithm>
#define MAX_SIZE 100001
typedef long long ll;
using namespace std;

class PriorityHeapMin{
private:
    pair<ll,ll> A[MAX_SIZE];
    int Size;

public:
PriorityHeapMin(){
    Size = 0;
}
int Parent(int i){
    return (i-1)/2;
}
int LeftChild(int i){
    return 2*i+1;
}
int RightChild(int i){
    return 2*i+2;
}
void SiftDown(int i){
    int MinIndex = i;
    int L = LeftChild(i);
    if(L<Size && A[L].first<A[MinIndex].first)
        MinIndex = L;
    else if(L<Size && A[L].first==A[MinIndex].first){
        if(A[L].second<A[MinIndex].second)
            MinIndex = L;
    }
    int R = RightChild(i);
    if(R<Size && A[R].first<A[MinIndex].first)
        MinIndex = R;
    else if(R<Size && A[R].first==A[MinIndex].first){
        if(A[R].second<A[MinIndex].second)
            MinIndex = R;
    }
    if(MinIndex != i){
        swap(A[MinIndex],A[i]);
        SiftDown(MinIndex);
    }
}
void SiftUp(int i){
    while(i>0 && (A[i].first<A[Parent(i)].first ||(A[i].first==A[Parent(i)].first && A[i].second<A[Parent(i)].second))){
        std::swap(A[i],A[Parent(i)]);
        i=Parent(i);
    }
}
void Insert(pair<ll,ll> key){
    if(Size>=MAX_SIZE)
        return;

    A[Size]=key;
    SiftUp(Size);
    Size++;
}
pair<ll,ll> Top()
{
    return A[0];
}
void Pop(){
    if(Size<=0)
        return;
    A[0]=A[Size-1];
    Size--;
    SiftDown(0);
}

};

int main(){
    int n,m;
    cin>>n>>m;
    PriorityHeapMin Q;
    vector<pair<ll,ll>> X;
    ll T[m];
    for(int j=0;j<m;j++)cin>>T[j];
    if(m<=n){
        for(int i=0;i<m;i++)
            cout<<i<< " "<<"0\n";
        return 0;
    }
    int i=0,k=0;
    while(k<n){
        if(T[i]!=0){
            Q.Insert(make_pair(T[i],k));
            X.push_back(make_pair(k,0));
            k++;
        }
        else{
            X.push_back(make_pair(k,0));
        }
        i++;
    }
    while(i<m){
        if(T[i]!=0){
            X.push_back(make_pair(Q.Top().second,Q.Top().first));
            Q.Insert(make_pair(Q.Top().first+T[i],Q.Top().second));
            Q.Pop();

        }
        else{
             X.push_back(make_pair(Q.Top().second,Q.Top().first));
            Q.Insert(make_pair(Q.Top().first+T[i],Q.Top().second));
        }
        i++;
    }
    for(int i=0;i<X.size();i++)
        cout<<X[i].first<< " " << X[i].second<<"\n";



    return 0;
}
