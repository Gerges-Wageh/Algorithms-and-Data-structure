#include<bits/stdc++.h>
using namespace std;

int Min(int a, int b, int c){
    return min(min(a,b),c);
}

int LCS_2(int n, int A[], int m, int B[]){
    int D[m+1][n+1];
     for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            D[i][j]=0;
     }
    for(int i=0;i<=m;i++)D[i][0]=i;
    for(int j=0;j<=n;j++)D[0][j]=j;
    int ins, del, matches, mismatches;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ins = D[i][j-1]+1;
            del = D[i-1][j]+1;
            matches = D[i-1][j-1];
            mismatches = D[i-1][j-1]+1;
            if(A[j-1]==B[i-1])
                D[i][j]=Min(ins,del,matches);
            else
                D[i][j]=min(ins,del);
        }
    }
    matches=0;
    while(n>0 && m>0){
        if(D[m][n]==D[m][n-1]+1 && n>0)
            n--;
        else if(D[m][n]==D[m-1][n]+1 && m>0)
            m--;
        else{
            if(A[n-1]==B[m-1]){
                matches++;

            }
            m--;
            n--;
        }
    }
    return matches;
}

int main(){
    int n,m;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    cin>>m;
    int B[m];
    for(int j=0;j<m;j++)cin>>B[j];
    cout<<LCS_2(n,A,m,B);

    return 0;
}

