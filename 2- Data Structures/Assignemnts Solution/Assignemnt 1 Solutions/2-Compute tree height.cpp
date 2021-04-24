#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    vector<Node*> children;
public:
    void AddKey(int key){
        this->key = key;
    }
    void AddChild(Node* child){
        this->children.push_back(child);
    }
    int GetKey(){
        return this->key;
    }


};
class Tree{
public:
    Node* root;
public:
    Tree(){
        root = nullptr;
    }
    int GetHeight(Node* root){
        if(root->children.size()==0)
            return 1;
        int temp, x=0;
        for(int i=0;i<root->children.size();i++){
            temp = GetHeight(root->children[i])+1;
            if(temp > x)
                x=temp;
        }
        return x;
    }

};
int main(){
    int n;
    cin>>n;
    int parent_index[n];
    Node nodes[n];
    for(int i=0;i<n;i++)
        cin>>parent_index[i];
    for(int i=0;i<n;i++)
        nodes[i].AddKey(i);
    Tree myTree;
    for(int i=0;i<n;i++){
        if(parent_index[i]==-1)
            myTree.root=&nodes[i];
        else
            nodes[parent_index[i]].AddChild(&nodes[i]);
    }
    cout<<myTree.GetHeight(myTree.root);

    return 0;
}
