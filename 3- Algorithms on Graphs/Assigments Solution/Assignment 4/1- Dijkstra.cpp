#include <bits/stdc++.h>
using namespace std;
#define INF  INT_MAX
class Vertex{
public:
	int key;
	int dist;
	bool in;
	vector<pair<Vertex*,int>> Adjs;
public:
	Vertex(int key){
		this->key = key;
		this->dist = INF;
		this->in = true;
	}
};

Vertex* G[100001];

Vertex* MinDist(int n){
	Vertex* x = new Vertex(0);
	for(int i=1;i<=n;i++){
		if(G[i]->dist < x->dist && G[i]->in == true)
			x = G[i];
	}
	return x;
}
void Dijkstra(int n){
	for(int j=1;j<=n;j++){
		Vertex* S = MinDist(n);
		S->in = false;
		for(int i=0;i<(int)S->Adjs.size();i++){
			if(S->Adjs[i].first->dist > S->dist + S->Adjs[i].second){
				S->Adjs[i].first->dist = S->dist + S->Adjs[i].second;
			}	
		}
	}
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
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		G[u]->Adjs.push_back(make_pair(G[v],w));
	}
	cin>>u>>v;
	G[u]->dist = 0;
	Dijkstra(n);
	if(G[v]->dist == INF)
		cout<<"-1";
	else
		cout<<G[v]->dist;

	return 0;
}
