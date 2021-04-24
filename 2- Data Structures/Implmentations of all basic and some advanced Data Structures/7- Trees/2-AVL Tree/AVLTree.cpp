// AVL Tree Implementation
// 5- Basic Operations: Find, Next, SearchByRange, AVLInsert and AVLDelete
// 2- Additional Operations: Merge, Split
// All Operations work in O(Log(n))

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int key;
		int height;
		Node* left;
		Node* right;
		Node* parent;
	public:
		Node(int key){
			this->key = key;
			this->height = 1;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}
};

class AVLTree{
	public:
		Node* root;
	public:
		AVLTree(){this->root = nullptr;}
		// Find()
		Node* Find(int x, Node* R){
			if(R == nullptr)
				return R;
			else if(x == R->key)
				return R;
			else if(x < R->key){
				if(R->left != nullptr)
					return Find(x,R->left);
				return R;
			}
			else{
				if(R->right != nullptr)
					return Find(x,R->right);
				return R;
			}
		}
		// Assistant method AppropriateChild()
		bool AppropriateChild(Node* N){
			if(N->parent->left == N)
				return 0;
			return 1;
		}
		// Assistant method LeftDescendent()
		Node* LeftDescendent(Node* N){
			if(N->left == nullptr)
				return N;
			return LeftDescendent(N->left);
		}
		// Assistant method RightAncestor()
		Node* RightAncestor(Node* N){
			if(N->parent == nullptr)
				return nullptr;
			if(N->parent->key > N->key)
				return N->parent;
			else
				return RightAncestor(N->parent);
		}
		// Next()
		Node* Next(Node* N){
			if(N->right != nullptr)
				return LeftDescendent(N->right);
			else
				return RightAncestor(N);
		}
		// SearchByRange()
		vector<int> SearchByRange(int x, int y){
			vector<int> L;
			Node* N = Find(x,this->root);
			while(N->key <= y){
				if(N->key >= x)
					L.push_back(N->key);
				N = Next(N);
				if(N == nullptr)
					break;
			}
			return L;
		}
		// Insert()
		void Insert(int x){
			Node* N = new Node(x);
			Node* P = Find(x,this->root);
			if(P == nullptr){
				this->root = N;
				return;
			}
			else if(P->key == x)
				return;
			
			else if(x < P->key){
				P->left = N;
				N->parent = P;
			}
			else{
				P->right = N;
				N->parent = P;
			}
		}
		// Assistant method AdjustHeight()
		void AdjustHeight(Node* N){
			if(N == nullptr)
				return;
			else if(N->right != nullptr && N->left != nullptr)
				N->height = (1 + max(N->right->height,N->left->height));
			else if (N->right != nullptr && N->left == nullptr)
				N->height = 1 + N->right->height;
			else if (N->right == nullptr && N->left != nullptr)	
				N->height = 1 + N->left->height;
			else
				N->height = 1;
			if(N->parent != nullptr)
				AdjustHeight(N->parent);
		}
		// Assistant method RotateRight()
		void RotateRight(Node* N){
			Node* P = N->parent;
			Node* Y = N->left;
			Node* B = Y->right;
			Node* A = Y->left;
			Node* C = N->right;
			Y->parent = P;
			if(P != nullptr){
				if(AppropriateChild(N))
					P->right = Y;
				else
					P->left = Y;
			}
			else
				this->root = Y;
				
			N->parent = Y;
			Y->right = N;
			if(B != nullptr)
				B->parent = N;
			N->left = B;
			AdjustHeight(N);
			AdjustHeight(Y);
			if(B != nullptr){
				AdjustHeight(B);
				AdjustHeight(B->left);
				AdjustHeight(B->right);
			}
			if(A != nullptr){
				AdjustHeight(A);
				AdjustHeight(A->left);
				AdjustHeight(A->right);
			}
			if(C != nullptr){
				AdjustHeight(C);
				AdjustHeight(C->left);
				AdjustHeight(C->right);
			}
			
		}
		// Assistant method RotateLeft()
		void RotateLeft(Node* N){
			Node* P = N->parent;
			Node* X = N->right;
			Node* B = X->left;
			Node* C = X->right;
			Node* A = N->left;
			X->parent = P;
			if(P != nullptr){
				if(AppropriateChild(N))
					P->right = X;
				else
					P->left = X;
			}
			else
				this->root = X;
			
			N->parent = X;
			X->left = N;
			if(B != nullptr)
				B->parent = N;
			N->right = B;
			AdjustHeight(N);
			AdjustHeight(X);
			if(B != nullptr){
				AdjustHeight(B);
				AdjustHeight(B->left);
				AdjustHeight(B->right);
			}
			if(A != nullptr){
				AdjustHeight(A);
				AdjustHeight(A->left);
				AdjustHeight(A->right);
			}
			if(C != nullptr){
				AdjustHeight(C);
				AdjustHeight(C->left);
				AdjustHeight(C->right);
			}
		}
		// Assistant method RebalanceRight()
		void RebalanceRight(Node* N){
			Node* M = N->left;
			if(M != nullptr){
				int RightWeight, LeftWeight;
				if(M->right != nullptr)
					RightWeight = M->right->height;
				else
					RightWeight = 0;
				if(M->left != nullptr)
					LeftWeight = M->left->height;
				else
					LeftWeight = 0;
				if(LeftWeight < RightWeight)
					RotateLeft(M);
			}
			RotateRight(N);
		}
		// Assistant method RebalanceLeft()
		void RebalanceLeft(Node* N){
			Node* M = N->right;
			if(M != nullptr){
				int RightWeight, LeftWeight;
				if(M->right != nullptr)
					RightWeight = M->right->height;
				else
					RightWeight = 0;
				if(M->left != nullptr)
					LeftWeight = M->left->height;
				else
					LeftWeight = 0;
				if(LeftWeight > RightWeight)
					RotateRight(M);
			}
			RotateLeft(N);
		}
		// Assistant method Rebalance()
		void Rebalance(Node* N){
			int RightWeight, LeftWeight;
			if(N->right == nullptr)
				RightWeight = 0;
			else
				RightWeight = N->right->height;
			if(N->left == nullptr)
				LeftWeight = 0;
			else
				LeftWeight = N->left->height;
			if(LeftWeight > RightWeight + 1)	
				RebalanceRight(N);
			if(RightWeight > LeftWeight + 1)
				RebalanceLeft(N);
			if(N->parent != nullptr)
				Rebalance(N->parent);
		}
		// AVLinsert
		void AVLinsert(int x){
			Insert(x);
			Node* N = Find(x,this->root);
			AdjustHeight(N);
			Rebalance(N);
		}
		// Delete()
		void AVLDelete(Node* N){
			if(N == this->root && N->right == nullptr && N->left == nullptr){
				this->root = nullptr;
				delete N;
				return;
			}
			if(N->right == nullptr){
				if(N->left != nullptr){
					N->left->parent = N->parent;
					if(N->parent != nullptr)
						N->parent->left = N->left;
				}
				else{
					if(N->parent->right == N)
						N->parent->right = nullptr;
					else
						N->parent->left = nullptr;
				}
				if(N == this->root)
					this->root = N->left;
			}
			else{
				Node* next = Next(N);
				Node* M = next->parent;
				if(next != N->right){
					Node* Y = next->right;
					Node* P = next->parent;
					if(N->parent != nullptr){
						if(N->parent->right == N)
							N->parent->right = next;
						else
							N->parent->left = next;
					}
					next->parent = N->parent;
					next->left = N->left;
					next->right = N->right;
					N->left->parent = next;
					N->right->parent = next;
					P->left = Y;
					P->parent = next;
				}
				else{
					next->parent = N->parent;
					if(N->parent != nullptr){
						if(N->parent->right == N)
							N->parent->right = next;
						else
							N->parent->left = next;
					}
					next->left = N->left;
					if(N->left != nullptr)
						N->left->parent = next;
				}
				if(N == this->root)
					this->root = next;
				if(M != nullptr)
					Rebalance(M);
			}
				delete N;
		}
		// MergeWithRoot()
		Node* MergeWithRoot(Node* R1, Node* R2, Node* T){
			if(R1 == nullptr && R2 == nullptr)
				return T;
			if(R1 == nullptr && R2 != nullptr){
				T->left = nullptr;
				T->right = R2;
				R2->parent = T;
				return T;
			}
			if(R2 == nullptr && R1 != nullptr){
				T->right = nullptr;
				T->left = R1;
				R1->parent = T;
				return T;
			}
				
			T->left = R1;
			T->right = R2;
			R1->parent = T;
			R2->parent = T;
			return T;
		}
		// Assistant method GetMax()
		Node* GetMax(Node* R){
			if(R->right == nullptr)
				return R;
			return GetMax(R->right);
		}
		// MergeWithoutRoot()
		Node* MergeWithoutRoot(Node* R1, Node* R2){
			Node* T = GetMax(R1);
			AVLDelete(T);
			return MergeWithRoot(R1,R2,T);
			}
		Node* AVLMergeWithRoot(Node* R1, Node* R2, Node* T){
			if(abs(R1->height - R2->height) <= 1){
				Node* TR = MergeWithRoot(R1,R2,T);
				TR->height = 1 + max(R1->height,R2->height);
				return TR;
			}
			else if(R1->height > R2->height){
				Node* TR = AVLMergeWithRoot(R1->right,R2,T);
				R1->right = TR;
				TR->parent = R1;
				Rebalance(R1);
				return R1;
			}
			else{
				Node* TR = AVLMergeWithRoot(R1,R2->left,T);
				R2->left = TR;
				TR->parent = R2;
				Rebalance(R2);
				return R2;
			}
		}
		// Print the tree nodes
		void PrintInOrder(Node* R){
			if(R == nullptr)
				return;
			PrintInOrder(R->left);
			cout<<R->key<<"\n";
			PrintInOrder(R->right);
		}
		void Print(){
			if(this->root == nullptr){
				cout<<"The tree is empty!\n";
				return;
			}
			PrintInOrder(this->root);
		}
};

// MergeWithRoot()
Node* MergeWithRoot(Node* R1, Node* R2, Node* T){
	if(R1 == nullptr && R2 == nullptr)
		return T;
	if(R1 == nullptr && R2 != nullptr){
		T->left = nullptr;
		T->right = R2;
		R2->parent = T;
		return T;
	}
	if(R2 == nullptr && R1 != nullptr){
		T->right = nullptr;
		T->left = R1;
		R1->parent = T;
		return T;
	}
		
	T->left = R1;
	T->right = R2;
	R1->parent = T;
	R2->parent = T;
	return T;
}
// Split()
pair<Node*,Node*> Split(int x, Node* R){
	if(R == nullptr)
		return make_pair(nullptr,nullptr);
	else if(x <= R->key){
		pair<Node*,Node*> X = Split(x,R->left);
		Node* TR = MergeWithRoot(X.second,R->right,R);
		return make_pair(X.first,TR);
	}
	else{
		pair<Node*,Node*> X = Split(x,R->right);
		Node* TR = MergeWithRoot(X.first,R->left,R);
		return make_pair(TR,X.second);
	}
}
void PrintInOrder(Node* R){
	if(R == nullptr)
		return;
	PrintInOrder(R->left);
	cout<<R->key<<"\n";
	PrintInOrder(R->right);
}

int main(){
	AVLTree myTree;
	myTree.AVLinsert(6);
	myTree.AVLinsert(8);
	myTree.AVLinsert(4);
	myTree.AVLinsert(3);
	myTree.AVLinsert(5);
	myTree.AVLinsert(2);
	myTree.AVLinsert(7);
	myTree.AVLinsert(10);
	myTree.AVLinsert(11);
	myTree.AVLinsert(15);
	myTree.AVLinsert(13);
	myTree.Print();
	cout<<"------------\n";
	pair<Node*,Node*> X = Split(7,myTree.root);
	PrintInOrder(X.first);
	cout<<endl;
	PrintInOrder(X.second);
	
	
	
	return 0;
}
