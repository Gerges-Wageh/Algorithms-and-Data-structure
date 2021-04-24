#include<bits/stdc++.h>
using namespace std;

bool IsOpenning(char x){
    return (x == '[' || x == '{' || x == '(');
}
bool IsClosing(char x){
    return (x == ']' || x == '}' || x == ')');
}
int Isbalanced(string s){
    stack<char> T;
    stack<int> index;
    for(int i=0;i<s.length();i++){
        if(IsOpenning(s[i])){
            T.push(s[i]);
            index.push(i);
        }
        else if(IsClosing(s[i])){
            if(!T.empty()){
                if(s[i] == ']' && T.top() == '['){
                    T.pop();
                    index.pop();
                }
                else if(s[i] == '}' && T.top() == '{'){
                    T.pop();
                    index.pop();
                }
                else if(s[i] == ')' && T.top() == '('){
                    T.pop();
                    index.pop();
                }
                else
                    return i;
            }
            else{
                return i;
            }
        }
    }
    if(index.size()>=1){
        while(index.size()!=1){
            index.pop();
        }
        return index.top();
    }

    return -1;
}

int main(){
    string s;
    cin>>s;
    int index = Isbalanced(s);
    (index == -1)?cout<<"Success":cout<<index+1;

    return 0;
}
