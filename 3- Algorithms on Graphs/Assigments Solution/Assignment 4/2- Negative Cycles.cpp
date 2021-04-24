#include <bits/stdc++.h>
using namespace std;
#define INF  100000
class Vertex{
public:
	int key;
	int dist;
public:
	Vertex(int key){
		this->key = key;
		this->dist = INF;
	}
};

Vertex* G[10001];
pair<int,int> E[10001];
int W[10001];

void BellmanFord(int n, int m){
	bool flag;
	for(int i=1;i<=n;i++){
		flag = false;
		for(int j=1;j<=m;j++){
			if(G[E[j].second]->dist > G[E[j].first]->dist + W[j]){
				G[E[j].second]->dist = G[E[j].first]->dist + W[j];
				flag = true;
			}
		}
	}
	cout<<flag;
}
int main(){
	int n, m, u, v, w;
	cin>>n>>m;
	if(n == 1){
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=n;i++){
		Vertex* x = new Vertex(i);
		G[i] = x;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		E[i] = make_pair(u,v);
		W[i] = w;
	}
	G[1]->dist = 0;
	BellmanFord(n,m);
	

	return 0;
}
