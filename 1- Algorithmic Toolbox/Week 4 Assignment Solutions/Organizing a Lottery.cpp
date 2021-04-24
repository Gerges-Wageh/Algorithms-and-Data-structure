#include<bits/stdc++.h>
using namespace std;


int main()
{
    int s,p;
    cin>>s>>p;
    int points[p];
    vector<pair<int,char>> NumLine;
    int a,b;
    for(int i=0;i<s;i++){
        cin>>a>>b;
        NumLine.push_back(make_pair(a,'l'));
        NumLine.push_back(make_pair(b,'r'));

    }
    for(int i=0;i<p;i++)cin>>points[i];
    for(int i=0;i<p;i++){
         NumLine.push_back(make_pair(points[i],'p'));
    }
    sort(NumLine.begin(),NumLine.end());
    a = 0;
    unordered_map<int,int> op;
    for(int i=0;i<p+2*s;i++){
        if(NumLine[i].second == 'l')
            a++;
        else if(NumLine[i].second == 'r')
            a--;
        else
            op[NumLine[i].first] = a;
    }
    for(int i=0;i<p;i++){
        cout<<op[points[i]]<<" ";
    }
    return 0;
}
