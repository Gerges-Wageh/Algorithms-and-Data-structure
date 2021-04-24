#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10001

class Disjoint_Set{
public:
    int Parent[MAX_SIZE];
    int Rank[MAX_SIZE];
public:
    void MakeSet(int i){
        Parent[i] = i;
        Rank[i] = 0;
    }
    int Find(int x){
        if(x != Parent[x])
            Parent[x] = Find(Parent[x]);
        return Parent[x];
    }
    void Union(int i, int j){
        int i_id = Find(i);
        int j_id = Find(j);
        if(i_id == j_id){
                return;
        }
        if(Rank[i_id] > Rank[j_id]){
            Parent[j_id] = i_id;
        }
        else{
          Parent[i_id] = j_id;
          if(Rank[i_id] == Rank[j_id])
				Rank[j_id] = Rank[j_id] + 1;
        }
    }
};

vector<pair<double,pair<int,int>>> E;

double distance(int x1, int y1, int x2, int y2){ 
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0); 
}

double Kruskal(int n){
	double ans = 0.0;
	Disjoint_Set S;
	for(int i=1;i<=n;i++)
		S.MakeSet(i);
	sort(E.begin(),E.end());
	for(int i=0;i<(int)E.size();i++){
		if(S.Find(E[i].second.first) != S.Find(E[i].second.second)){
			ans += E[i].first;
			S.Union(E[i].second.first,E[i].second.second);
		}
	}
	return ans;
}
int main(){
	int n, x, y;
	cin>>n;
	pair<int,int> P[n];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		P[i] = make_pair(x,y);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
			E.push_back(make_pair((double)distance(P[i].first,P[i].second,P[j].first,P[j].second),make_pair(i,j)));
	}
	cout.precision(10);
	cout<<(double)Kruskal(n);
	
	return 0;
}
