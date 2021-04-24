#include<bits/stdc++.h>
using namespace std;
bool IsGreaterThanOrEqual(string a,string b){
    string x,y;
    int xi,yi;
    x=a+b;
    y=b+a;
    for(int i=0;i<x.size();i++){
        stringstream s1(x.substr(i,1));
        s1>>xi;
        stringstream s2(y.substr(i,1));
        s2>>yi;
        if(xi>yi)
            return 1;
        if(yi>xi)
            return 0;
    }
    return 1;
}
string LargestNumber(vector<string> &Digits){
    string result="",maxDigit;
    while(!Digits.empty()){
        maxDigit="0";
        for(int i=0;i<Digits.size();i++){
            if(IsGreaterThanOrEqual(Digits[i],maxDigit))
                maxDigit=Digits[i];
        }
        result+=maxDigit;
        for(auto it=Digits.begin();it!=Digits.end();it++){
            if(*it==maxDigit){
                Digits.erase(it);
                break;
            }
        }

    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<LargestNumber(a);
}

