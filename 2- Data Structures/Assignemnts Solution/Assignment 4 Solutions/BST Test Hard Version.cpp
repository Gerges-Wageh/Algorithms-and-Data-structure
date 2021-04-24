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
vector<Node*> T;
void InOrderTraversal(Node* R){
	if(R == nullptr)
		return;
	InOrderTraversal(R->left);
	T.push_back(R);
	InOrderTraversal(R->right);
}


int main(){
	int key=0, left=0, right=0, n=0;
	cin>>n;
	if(n == 0 || n == 1){
		cout<<"CORRECT";
		return 0;
	}
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
	for(int i=0;i<n-1;i++){
		if(T[i]->key >T[i+1]->key){
			cout<<"INCORRECT";
			return 0;
		}
		else if(T[i]->key == T[i+1]->key){
			if(T[i]->left == T[i+1] || T[i+1]->left == T[i]){
				cout<<"INCORRECT";
				return 0;
			}
		}
	}
	cout<<"CORRECT";
	
	return 0;
}
