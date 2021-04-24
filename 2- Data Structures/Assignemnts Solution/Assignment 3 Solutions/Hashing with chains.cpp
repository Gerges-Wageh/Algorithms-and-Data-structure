#include<bits/stdc++.h>
using namespace std;
#define NUM_BUCKETS 10000000
///LinkedList
//Node
class Node{
private:
    Node* next;
    string key;
public:
    Node(string key){
        this->key = key;
        next = nullptr;
    }
    friend class LinkedList;
};
//LinkedList
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }
    void PushFront(string key){
        Node* N = new Node(key);
        N->next = head;
        head = N;
    }
    bool Find(string key){
        Node* CurrentNode = head;
        while(CurrentNode != nullptr){
            if(CurrentNode->key == key)
                return 1;
            else
                CurrentNode = CurrentNode->next;
        }
        return 0;
    }

    void Delete(string key){
        Node* CurrentNode = head;
        Node* PreviousNode = head;
        while(CurrentNode != nullptr){
            if(CurrentNode->key == key){
                if(PreviousNode == head && CurrentNode == head){
                    head = CurrentNode->next;
                    delete CurrentNode;
                    return;
                }
                else{
                    PreviousNode->next = CurrentNode->next;
                    delete CurrentNode;
                    return;
                }
            }
            PreviousNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }
    }

    void Print(){
        Node* CurrentNode = head;
        while(CurrentNode != nullptr){
            cout<<CurrentNode->key<< " ";
            CurrentNode = CurrentNode->next;
        }
        cout<<endl;
    }
};

static LinkedList BUCKETS [NUM_BUCKETS];

unsigned long long PolyHash(string S, int p, int x, int m){
    unsigned long long Hash = 0;
    for(int i=S.length()-1;i>=0;i--){
        Hash = (Hash*x + S[i])%p;
    }
    return Hash%m;
}

int main(){
    int m,N,k;
    string query,key;
    cin>>m>>N;
    for(int i=0;i<N;i++){
        cin>>query;
        if(query == "add"){
            cin>>key;
            if(!BUCKETS[PolyHash(key,1000000007,263,m)].Find(key))
                BUCKETS[PolyHash(key,1000000007,263,m)].PushFront(key);
        }
        else if(query == "del"){
            cin>>key;
            BUCKETS[PolyHash(key,1000000007,263,m)].Delete(key);
        }
        else if(query == "find"){
            cin>>key;
            (BUCKETS[PolyHash(key,1000000007,263,m)].Find(key))?cout<<"yes\n":cout<<"no\n";
        }
        else{
            cin>>k;
            BUCKETS[k].Print();
        }
    }

    return 0;
}