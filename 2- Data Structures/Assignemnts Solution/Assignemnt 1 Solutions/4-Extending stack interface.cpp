#include<bits/stdc++.h>
using namespace std;
static int Stack_Space[400000];
static int Buffer[400000];

class Stack{
private:
    int Size,inx;
    int Max;
public:
    Stack()
    {
        Size = 0;
        inx=0;
        Max=0;
    }

    void Push(int key)  // Time Complexity: O(1)
    {
        Stack_Space[Size]=key;
        Size++;
        if(key>=Max){
            Max=key;
            Buffer[inx]=key;
            inx++;
        }

    }
    int Top()  // Time Complexity: O(1)
    {
        return Stack_Space[Size-1];
    }

    void Pop()  // Time Complexity: O(1)
    {
        if(Stack_Space[Size-1]==Max){
            inx--;
            Max=Buffer[inx-1];
        }
        Size--;

    }

    bool Empty()  // Time Complexity: O(1)
    {
        return(Size<1);
    }
    int GetMax(){
        return Max;
    }

};
int main(){
    Stack S;
    int n,v;
    cin>>n;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x=="push"){
            cin>>v;
            S.Push(v);
        }
        else if(x=="pop")
            S.Pop();
        else
            cout<<S.GetMax()<<endl;
    }

    return 0;
}
