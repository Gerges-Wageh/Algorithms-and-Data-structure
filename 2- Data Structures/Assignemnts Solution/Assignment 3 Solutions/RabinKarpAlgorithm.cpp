#include<bits/stdc++.h>
using namespace std;

static unsigned long long H[100000000];
vector<int>R;

unsigned long long PolyHash(string S, int x){
    unsigned long long Hash = 0;
    for(int i=S.length()-1;i>=0;i--){
        Hash = Hash*x + S[i];
    }
    return Hash;
}
void RabinKarpAlgorithm(string T, string P){
    unsigned long long p = 1000000000007,x=31;
    H[T.length()-P.length()] = PolyHash(T.substr(T.length()-P.length()),x);
    unsigned long long y = 1,PHash;
    for(int i=1;i<=P.length();i++)
        y = y*x;
    for(int i=T.length()-P.length()-1;i>=0;i--)
        H[i] = x*H[i+1]-y*T[i+P.length()]+T[i];
    PHash = PolyHash(P,x);
    for(int i=0;i<=T.length()-P.length();i++){
        if(PHash != H[i])
            continue;
        if(T.substr(i,P.length())== P)
            R.push_back(i);
    }
    for(int i=0;i<R.size();i++)
        cout<<R[i]<<" ";
}

int main(){
    string P,T;
    cin>>P>>T;
    RabinKarpAlgorithm(T,P);

    return 0;
}
