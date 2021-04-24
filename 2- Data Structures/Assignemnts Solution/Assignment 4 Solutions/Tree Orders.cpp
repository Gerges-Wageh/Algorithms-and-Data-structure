#include <bits/stdc++.h>
using namespace std;

int x[100001][3];

class Node{
	public:
		int key;
		Node* left;
		Node* right;
	public:
		Node(int key){
			this->key = key;
			this->left = nullptr;
			this->right = nullptr;
		}
};

Node* tree[100001];

void InOrderTraversal(Node* R){
	if(R == nullptr)
		return;
	InOrderTraversal(R->left);
	cout<<R->key<<" ";
	InOrderTraversal(R->right);
}
void PreOrderTraversal(Node* R){
	if(R == nullptr)
		return;
	cout<<R->key<<" ";
	PreOrderTraversal(R->left);
	PreOrderTraversal(R->right);
}
void PostOrderTraversal(Node* R){
	if(R == nullptr)
		return;
	PostOrderTraversal(R->left);
	PostOrderTraversal(R->right);
	cout<<R->key<<" ";
}

int main(){
	int key=0, left=0, right=0, n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>key>>left>>right;
		x[i][0] = key;
		x[i][1] = left;
		x[i][2] = right;
		Node* N = new Node(key);
		tree[i] = N;
	}
	for(int i=0;i<n;i++){
		if(x[i][1] != -1)
			tree[i]->left = tree[x[i][1]];
		if(x[i][2])
		tree[i]->right = tree[x[i][2]];
	}
	InOrderTraversal(tree[0]);
	cout<<endl;
	PreOrderTraversal(tree[0]);
	cout<<endl;
	PostOrderTraversal(tree[0]);
	
	return 0;
}
