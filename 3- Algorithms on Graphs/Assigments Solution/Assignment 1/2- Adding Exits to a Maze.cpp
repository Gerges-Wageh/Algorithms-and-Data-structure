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

void Explore(Vertex* S){
	S->visited = true;
	for(int i=0;i<(int)S->Adjs.size();i++){
		if(S->Adjs[i]->visited != true){
				Explore(S->Adjs[i]);
		}
	}
}

int main(){
	int n, m, u, v, CC_num = 0;
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
	for(int i=1;i<=n;i++){
		if(V[i]->visited != true){
			CC_num++;
			Explore(V[i]);
		}
	}
	cout<<CC_num;
	
	return 0;
}
