#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

static vector<pair<int,int>> V;

int Parent(int i){
    return (i-1)/2;
}
int LeftChild(int i){
    return 2*i+1;
}
int RightChild(int i){
    return 2*i+2;
}
void SiftDown(int A[], int n, int i){

    int MinIndex = i;
    int L = LeftChild(i);
    if(L<n && A[L]<A[MinIndex])
        MinIndex = L;
    int R = RightChild(i);
    if(R<n && A[R]<A[MinIndex])
        MinIndex = R;
    if(MinIndex != i){
        swap(A[i],A[MinIndex]);
        V.push_back(make_pair(i,MinIndex));
        SiftDown(A,n,MinIndex);
    }
}
void BuildMinHeap(int A[], int n){
    for(int i=n/2;i>=0;i--)
        SiftDown(A,n,i);

    cout<<V.size()<<"\n";
    for(int i=0;i<V.size();i++)
        cout<<V[i].first<<" "<<V[i].second<<"\n";
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    BuildMinHeap(A,n);

    return 0;
}
