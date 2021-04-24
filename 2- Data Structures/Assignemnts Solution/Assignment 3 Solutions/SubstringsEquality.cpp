#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll H1[500001], H2[500001], P1[500001], P2[500001];
ll m1 = 1000000007;
ll m2 = 1000000009;
ll x = 165;
void PrecomputeHashes(string S){
    H1[0] = 0;
    H2[0] = 0;
    for(int i=1;i<=S.length();i++)
        H1[i]=((x*H1[i-1])%m1+S[i-1])%m1;

    for(int i=1;i<=S.length();i++)
        H2[i]=((x*H2[i-1])%m2+S[i-1])%m2;

}
bool AreEqual(int a, int b, int l, int y1, int y2){
    ll S11 = (H1[a+l]-((ll)y1*H1[a])%m1)%m1;
    S11 = ((S11%m1)+m1)%m1;
    ll S12 = (H2[a+l]-((ll)y2*H2[a])%m2)%m2;
    S12 = ((S12%m2)+m2)%m2;
    ll S21 = (H1[b+l]-((ll)y1*H1[b])%m1)%m1;
    S21 = ((S21%m1)+m1)%m1;
    ll S22 = (H2[b+l]-((ll)y2*H2[b])%m2)%m2;
    S22 = ((S22%m2)+m2)%m2;
    if(S11 == S21 && S12 == S22)
        return 1;
    return 0;
}
int main(){
    string S;
    cin>>S;
    P1[0] = 1;
    P2[0] = 1;
    for(int i=1;i<=S.length();i++){
        P1[i] = ((ll)P1[i-1]*x)%m1;
        P2[i] = ((ll)P2[i-1]*x)%m2;
    }
    int n,a,b,l;
    cin>>n;
    PrecomputeHashes(S);
    for(int i=0;i<n;i++){
        cin>>a>>b>>l;
        (AreEqual(a,b,l,P1[l],P2[l]))?cout<<"Yes\n":cout<<"No\n";
    }
    return 0;
}
