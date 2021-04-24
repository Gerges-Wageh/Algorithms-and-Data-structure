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

Vertex* V[1000001];
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
		if(V[i]->visited != true){
			Explore(V[i]);
		}
	}
	pair<int,int> x[n];
	for(int i=1;i<=n;i++){
		x[i-1] = make_pair(V[i]->post,i);
	}
	sort(x,x+n,greater<>());
	for(int i=0; i<n;i++)
		cout<<x[i].second<< " ";
	
	

	
	
	return 0;
}
