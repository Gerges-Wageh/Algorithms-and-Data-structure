#include <bits/stdc++.h>
using namespace std;

class Vertex{
	public:
		int key, pre, post;
		bool visited;
		vector<Vertex*> Adjs;
	public:
		Vertex(int key){
			this->key = key;
			this->visited = false;
			this->pre = 0;
			this->post = 0;
			
		}
};

bool sortbypost(Vertex* a, Vertex* b){ 
    return (a->post > b->post); 
}

Vertex* G[100001];
Vertex* GR[100001];
int c = 1;

void Explore(Vertex* S){
	S->visited = true;
	S->pre = c;
	c++;
	for(int i=0;i<(int)S->Adjs.size();i++){
		if(S->Adjs[i]->visited != true){
				Explore(S->Adjs[i]);	
		}
	}
	S->post = c;
	c++;
}
void Exp(Vertex* S){
	S->visited = true;
	for(int i=0;i<(int)S->Adjs.size();i++){
		if(S->Adjs[i]->visited != true){
				Exp(S->Adjs[i]);
		}
	}
}
int main(){
	int n, m, u, v, SCC_num = 0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		Vertex* x = new Vertex(i);
		Vertex* y = new Vertex(i);
		G[i] = x;
		GR[i] = y;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v;
		G[u]->Adjs.push_back(G[v]);
		GR[v]->Adjs.push_back(GR[u]);
	}
	for(int i=1;i<=n;i++){
		if(GR[i]->visited != true){
			Explore(GR[i]);
		}
	}
	for(int i=1;i<=n;i++){
		G[i]->post = GR[i]->post;
	}
	sort(G+1,G+n+1,sortbypost);
	for(int i=1;i<=n;i++){
		if(G[i]->visited != true){
			Explore(G[i]);
			SCC_num++;
		}
	}
	cout<<SCC_num;
		
	return 0;
}
