#include <bits/stdc++.h>
using namespace std;

class Vertex{
	public:
		int key;
		int dist;
		vector<Vertex*> Adjs;
	public:
		Vertex(int key){
			this->key = key;
			this->dist = -1;
		}
};

Vertex* G[100001];

void BFS(Vertex* S){
	S->dist = 0;
	queue<Vertex*> Q;
	Q.push(S);
	while(!Q.empty()){
		Vertex* X = Q.front();
		Q.pop();
		for(int i=0; i<(int)X->Adjs.size();i++){
			if(X->Adjs[i]->dist == -1){
				Q.push(X->Adjs[i]);
				X->Adjs[i]->dist = X->dist + 1;
			}
		}
	}
}
int main(){
	int n, m, u, v;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		Vertex* x = new Vertex(i);
		G[i] = x;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v;
		G[u]->Adjs.push_back(G[v]);
		G[v]->Adjs.push_back(G[u]);
	}
	cin>>u>>v;
	BFS(G[u]);
	cout<<G[v]->dist;
		
	return 0;
}
