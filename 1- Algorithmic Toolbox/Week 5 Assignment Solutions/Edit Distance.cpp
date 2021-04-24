#include<bits/stdc++.h>
using namespace std;

int Min(int a, int b, int c){
    return min(min(a,b),c);
}

int EditDistance(string a, string b){
    int n = a.length();
    int m = b.length();
    int MinEditDistance[m+1][n+1];
     for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            MinEditDistance[i][j]=0;
     }
    for(int i=0;i<=m;i++)MinEditDistance[i][0]=i;
    for(int j=0;j<=n;j++)MinEditDistance[0][j]=j;
    int ins, del, matches, mismatches;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ins = MinEditDistance[i][j-1]+1;
            del = MinEditDistance[i-1][j]+1;
            matches = MinEditDistance[i-1][j-1];
            mismatches = MinEditDistance[i-1][j-1]+1;
            if(a[j-1]==b[i-1])
                MinEditDistance[i][j]=Min(ins,del,matches);
            else
                MinEditDistance[i][j]=Min(ins,del,mismatches);
        }
    }
    return MinEditDistance[m][n];
}

int main(){
    string n,m;
    cin>>n>>m;
    cout<<EditDistance(n,m);

    return 0;
}
