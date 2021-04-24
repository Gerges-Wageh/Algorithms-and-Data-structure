// Binary Search Tree Implementation
// 5- Basic Operations: Find, Next, Search by range, Insert and Delete
// All Operations work in O(Depth)

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int key;
		Node* LeftChild;
		Node* RightChild;
		Node* Parent;
	public:
		Node(int key){
			this->key = key;
			this->Parent = nullptr;
			this->LeftChild = nullptr;
			this->RightChild = nullptr;
		}

};

class BST{
	public:
		Node* Root;
	public:
		BST(){
			this->Root = nullptr;
		}
		// Function name: Find()
		// Input: value to search for, tree root
		// Output: pointer to the node containing that value or where the value should have been
		Node* Find(int x, Node* R){
			if(R == nullptr)
				return R;
			else if(R->key == x)
				return R;
			else if(R->key > x){
				if(R->LeftChild != nullptr)
					return Find(x,R->LeftChild);
				return R;
			}
			else{
				if(R->RightChild != nullptr)
					return Find(x,R->RightChild);
				return R;
			}
		}
		// Function name: Next()
		// Input: pointer to the node for which we're searching for the next
		// Output: pointer to the node containing the successor key or nullptr if this node containing the largest key
		Node* LeftDescendent(Node* N){
			if(N->LeftChild == nullptr)
				return N;
			return LeftDescendent(N->LeftChild);
		}
		Node* RightAncestor(Node* N){
			if(N->Parent == nullptr)
				return nullptr;
			if(N->Parent->key > N->key)
				return N->Parent;
			else
				return RightAncestor(N->Parent);

		}
		Node* Next(Node* N){
			if(N->RightChild != nullptr)
				return LeftDescendent(N->RightChild);
			else
				return RightAncestor(N);
		}
		// Function name: SearchByRanage()
		// Input: x,y the range we're searching between it and the tree root
		// Output: vector of the keys between the input range [x,y]
		vector<int> SearchByRange(int x, int y){
			vector<int> L;
			Node* N = Find(x,this->Root);
			while(N->key <= y){
				if(N->key >= x)
					L.push_back(N->key);
				N = Next(N);
				if(N == nullptr)
					break;
			}
			return L;
		}
		// Function name: Insert()
		// Input: key, tree root
		// Output: none
		void Insert(int key){
			Node* N = new Node(key);
				if(this->Root == nullptr){
					this->Root = N;
					return;
				}
			Node* P = Find(key,this->Root);
			if(P->key == key)
                return;
			else if(key < P->key){
				N->Parent = P;
				P->LeftChild = N;
			}
			else{
				N->Parent = P;
				P->RightChild = N;
			}
		}
		// Function name: Delete()
		// Input: key, tree root
		// Output: none
		void Delete(int key, Node* R){
			Node* N = Find(key,R);
			if(N == this->Root && N->RightChild == nullptr && N->LeftChild == nullptr){
				this->Root = nullptr;
				delete N;
				return;
			}
			else if(N->key == key){
				if(N->RightChild == nullptr){
					if(N->LeftChild != nullptr){
						N->LeftChild->Parent = N->Parent;
						N->Parent->LeftChild = N->LeftChild;
					}
					else{
						if(N->Parent->RightChild == N)
							N->Parent->RightChild = nullptr;
						else
							N->Parent->LeftChild = nullptr;
					}
				}
				else{
					Node* next = Next(N);
					if(next != N->RightChild){
						Node* Y = next->RightChild;
						Node* P = next->Parent;
						if(N->Parent != nullptr){
							if(N->Parent->RightChild == N)
								N->Parent->RightChild = next;
							else
								N->Parent->LeftChild = next;
						}
						next->Parent = N->Parent;
						next->LeftChild = N->LeftChild;
						next->RightChild = N->RightChild;
						N->LeftChild->Parent = next;
						N->RightChild->Parent = next;
						P->LeftChild = Y;
						P->Parent = next;
					}
					else{
						next->Parent = N->Parent;
						if(N->Parent != nullptr){
							if(N->Parent->RightChild == N)
								N->Parent->RightChild = next;
							else
								N->Parent->LeftChild = next;
						}
						next->LeftChild = N->LeftChild;
						N->LeftChild->Parent = next;
					}
					
					if(N == this->Root)
						this->Root = next;
				}
				delete N;
			}
		}
		// Function name: PrintInOrder()
		// Input: tree root
		// Output: none
		void PrintInOrder(Node* R){
			if(R == nullptr)
				return;
			PrintInOrder(R->LeftChild);
			cout<<R->key<<endl;
			PrintInOrder(R->RightChild);
		}
		void Print(){
			PrintInOrder(this->Root);
		}
};
int main(){
	BST myTree;
	myTree.Insert(6);
	myTree.Insert(3);
	myTree.Insert(8);
	myTree.Insert(7);
	myTree.Insert(9);
	myTree.Insert(4);
	myTree.Insert(5);
	myTree.Insert(10);
	myTree.Print();
	cout<<"---------------\n";
	myTree.Delete(8,myTree.Root);
	myTree.Print();
	cout<<"---------------\n";
	myTree.Delete(6,myTree.Root);
	myTree.Print();
	
	return 0;
}
