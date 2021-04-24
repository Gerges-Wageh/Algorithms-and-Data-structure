#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define P 165
#define m1 1000000007
#define m2 1000000009
typedef long long ll;
typedef unsigned int ui;

ll H1_a[100000+1], H2_a[100000+1];
ll H1_b[100000+1], H2_b[100000+1];
ll P1[100000+1], P2[100000+1];

void PrecomputedPrefixesHashes(string a, string b){
	H1_a[0] = 0, H2_a[0] = 0;
	H1_b[0] = 0, H2_b[0] = 0;
	for(ui i=1;i<=a.length();++i){
		H1_a[i] = ((P*H1_a[i-1])%m1 + a[i-1])%m1;
		H2_a[i] = ((P*H2_a[i-1])%m2 + a[i-1])%m2;
	}
	for(ui i=1;i<=b.length();++i){
		H1_b[i] = ((P*H1_b[i-1])%m1 + b[i-1])%m1;
		H2_b[i] = ((P*H2_b[i-1])%m2 + b[i-1])%m2;
	}
}

void PrecomputePowers(){
	P1[0] = 1;
	P2[0] = 1;
	for(int i=1;i<=100000;++i){
		P1[i] = ((ll)P1[i-1]*P)%m1;
		P2[i] = ((ll)P2[i-1]*P)%m2;
	} 
}

pair<ll,ll> InstantHashing_a(int i, int len){
	ll h1 = (H1_a[i+len] - ((ll)P1[len]*H1_a[i])%m1)%m1;
	h1 = ((h1%m1)+m1)%m1;
	ll h2 = (H2_a[i+len] - ((ll)P2[len]*H2_a[i])%m2)%m2;
	h2 = ((h2%m2)+m2)%m2;
	return make_pair(h1,h2);
}

pair<ll,ll> InstantHashing_b(int i, int len){
	ll h1 = (H1_b[i+len] - ((ll)P1[len]*H1_b[i])%m1)%m1;
	h1 = ((h1%m1)+m1)%m1;
	ll h2 = (H2_b[i+len] - ((ll)P2[len]*H2_b[i])%m2)%m2;
	h2 = ((h2%m2)+m2)%m2;
	return make_pair(h1,h2);
}

int main(){
	string s, t, a, b;
	PrecomputePowers();
	while(cin>>s>>t){
		bool flag = 1;
		if(s.length()>= t.length()){
			a = s;
			b = t;
		}
		else{
			a = t;
			b = s;
			flag = 0;
		}
		PrecomputedPrefixesHashes(a,b);
		// Note that high is min length + 1 to cover the case when the whole second string is in the first one 
		// As mid determines the length of the substrign each iteration if you use high = min length it won't cover it
		ui low = 0, high = min(b.length(),a.length())+1, a_index = 0, b_index = 0;
		while(high - low > 1){
			ui mid = low + (high - low)/2;
			map<pair<ll,ll>,int> hashes;
			for(ui i=0; i + mid <= a.length(); ++i){
				hashes[InstantHashing_a(i,mid)] = i+1;
			}
			int k = -1;
			for(ui i=0; i + mid <= b.length(); ++i){
				if(hashes[InstantHashing_b(i,mid)]){
					a_index = hashes[InstantHashing_b(i,mid)]-1;
					b_index = i;
					k = i;
				}
			}
			if(k >= 0)
				low = mid;
			else
				high = mid;
		}
		(flag)?cout<<a_index<<" "<<b_index<<" "<<low:cout<<b_index<<" "<<a_index<<" "<<low;
		cout<<endl;
	}
}
