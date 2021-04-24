#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;

#define P               165
#define m1              1000000007
#define m2              1000000009
#define sz(x)           ((int) x.size())
#define print(a)        for (auto x : a) cout << x << " "; cout << "\n";

ll H1_a[200000+1], H2_a[200000+1];
ll H1_b[100000+1], H2_b[100000+1];
ll P1[100000+1], P2[100000+1];
string s , t;
int k;

void PrecomputedPrefixesHashes(string a, string b){
	H1_a[0] = 0, H2_a[0] = 0;
	H1_b[0] = 0, H2_b[0] = 0;
	P1[0] = 1;
	P2[0] = 1;
	for(ui i=1;i<=a.length();++i){
		H1_a[i] = ((P*H1_a[i-1])%m1 + a[i-1])%m1;
		H2_a[i] = ((P*H2_a[i-1])%m2 + a[i-1])%m2;
	}
	for(ui i=1;i<=b.length();++i){
		H1_b[i] = ((P*H1_b[i-1])%m1 + b[i-1])%m1;
		H2_b[i] = ((P*H2_b[i-1])%m2 + b[i-1])%m2;
		P1[i] = ((ll)P1[i-1]*P)%m1;
		P2[i] = ((ll)P2[i-1]*P)%m2;
	}
}

inline pair<ll,ll> InstantHashing_a(int i, int len){
	ll h1 = (H1_a[i+len] - ((ll)P1[len]*H1_a[i])%m1)%m1;
	h1 = ((h1%m1)+m1)%m1;
	ll h2 = (H2_a[i+len] - ((ll)P2[len]*H2_a[i])%m2)%m2;
	h2 = ((h2%m2)+m2)%m2;
	return make_pair(h1,h2);
}

inline pair<ll,ll> InstantHashing_b(int i, int len){
	ll h1 = (H1_b[i+len] - ((ll)P1[len]*H1_b[i])%m1)%m1;
	h1 = ((h1%m1)+m1)%m1;
	ll h2 = (H2_b[i+len] - ((ll)P2[len]*H2_b[i])%m2)%m2;
	h2 = ((h2%m2)+m2)%m2;
	return make_pair(h1,h2);
}


void solve(){
     while (cin >> k >> s >> t){
         PrecomputedPrefixesHashes(s,t);
         vector<int> Result;
         for (int i = 0; i < sz(s) - sz(t) + 1; i++){
             int low = i, c = 0;
             while (low < i + sz(t)){
                 int l = low, r = i + sz(t) - 1, ind = -1;
                 while (l <= r){
                     int mid = (l + r)/2;
                     pair<ll,ll> x = InstantHashing_a(l,mid-l+1);
                     pair<ll,ll> y = InstantHashing_b(l-i,mid-l+1);
                     if (y == x)
                          l = mid + 1, ind = mid;
                     else
                          r = mid - 1;
                    }
                    if (ind == -1){
                         low++;
                         c++;
                    }
                    else
                         low = ind + 1;

                    if(c > k)
                         break;
               }
               if (c <= k)
                    Result.push_back(i);
          }
          cout << sz(Result) << " ";
          print(Result);
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
     solve();
     
     return 0;
}
