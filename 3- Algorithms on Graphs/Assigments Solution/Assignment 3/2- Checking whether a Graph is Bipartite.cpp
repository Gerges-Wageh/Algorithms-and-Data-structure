#include <bits/stdc++.h>
using namespace std;

class Vertex{
	public:
		int key;
		char color;
		vector<Vertex*> Adjs;
	public:
		Vertex(int key){
			this->key = key;
			this->color = 'N';
		}
};

Vertex* G[100001];
pair<int,int> E[100001];

void BFS(Vertex* S){
	S->color = 'B';
	queue<Vertex*> Q;
	Q.push(S);
	while(!Q.empty()){
		Vertex* X = Q.front();
		Q.pop();
		for(int i=0; i<(int)X->Adjs.size();i++){
			if(X->Adjs[i]->color == 'N'){
				Q.push(X->Adjs[i]);
				if(X->color == 'B')
					X->Adjs[i]->color = 'W';
				else
					X->Adjs[i]->color = 'B';
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
		E[i] = make_pair(u,v);
		G[u]->Adjs.push_back(G[v]);
		G[v]->Adjs.push_back(G[u]);
	}
	for(int i=1;i<=n;i++){
		if(G[i]->color == 'N')
			BFS(G[i]);
	}
	for(int i=0;i<m;i++){
		if(G[E[i].first]->color == G[E[i].second]->color){
			cout<<'0';
			return 0;
		}	
	}
	cout<<'1';
		
	return 0;
}
