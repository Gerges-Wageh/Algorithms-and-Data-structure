#include"ArrayBasedStack.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    Stack S1;
    S1.Push(1);
    S1.Push(2);
    S1.Push(3);
    while(!S1.Empty()){
        cout<<S1.Top()<< " ";
        S1.Pop();
    }
    return 0;
}
