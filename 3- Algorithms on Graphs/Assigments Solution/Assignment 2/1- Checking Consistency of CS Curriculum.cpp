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
bool IsCyclic = false;

void Explore(Vertex* S, Vertex* F){
	S->visited = true;
	for(int i=0;i<(int)S->Adjs.size();i++){
		if(S->Adjs[i] == F)
			IsCyclic = true;
		if(S->Adjs[i]->visited != true){
				Explore(S->Adjs[i],F);
		}
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
	}
	for(int i=1;i<=n;i++){
		if(IsCyclic){
			cout<<'1';
			return 0;
		}
		if(V[i]->visited != true){
			Explore(V[i],V[i]);
		}
	}
	cout<<'0';

	
	
	return 0;
}
