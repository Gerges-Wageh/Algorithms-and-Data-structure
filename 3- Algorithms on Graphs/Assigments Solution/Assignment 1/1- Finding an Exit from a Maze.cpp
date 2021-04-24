#include <bits/stdc++.h>
using namespace std;

class Vertex{
	public:
		int key;
		bool visited;
		vector<Vertex*> Adjs;
	public:
		Vertex(int key){
			this->key = key;
			this->visited = false;
		}
};

Vertex* V[10001];
bool done = false;

void IsReachable(Vertex* S, Vertex* D){
	S->visited = true;
	for(int i=0;i<(int)S->Adjs.size();i++){
		if(S->Adjs[i] == D){
			done = true;
		}
		
		if(S->Adjs[i]->visited != true)
			IsReachable(S->Adjs[i],D);
	}
}
int main(){
	int n, m, u, v;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		Vertex* x = new Vertex(i);
		V[i] = x;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v;
		V[u]->Adjs.push_back(V[v]);
		V[v]->Adjs.push_back(V[u]);
	}
	cin>>u>>v;
	IsReachable(V[u],V[v]);
	cout<<done;
	
	return 0;
}
