#include<bits/stdc++.h>
using namespace std;

int Min(int a, int b, int c){
    return min(min(a,b),c);
}

static int arr[100];
void CommonSubSeq(int n, int A[], int m, int B[], vector<int>&M){
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
    stack<int>S;
    while(n>0 && m>0){
        if(D[m][n]==D[m][n-1]+1 && n>0)
            n--;
        else if(D[m][n]==D[m-1][n]+1 && m>0)
            m--;
        else{
            if(A[n-1]==B[m-1]){
                matches++;
                S.push(A[n-1]);
            }
            m--;
            n--;
        }
    }
    while(!S.empty()){
        M.push_back(S.top());
        S.pop();
    }
}

int LCS_Compare(int n, int A[], int m, int B[]){
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

int LCS_3(int n, int A[], int m, int B[], int l, int C[]){
    int x = LCS_Compare(n,A,m,B);
    int y = LCS_Compare(m,B,l,C);
    int z = LCS_Compare(n,A,l,C);
    vector<int> ComSeq;
    if(x>y && x>z){
        CommonSubSeq(n,A,m,B,ComSeq);
        for(int i=0;i<ComSeq.size();i++)arr[i]=ComSeq[i];
        return LCS_Compare(ComSeq.size(),arr,l,C);
    }
    else if(y>x && y>z){
        CommonSubSeq(m,B,l,C,ComSeq);
        for(int i=0;i<ComSeq.size();i++)arr[i]=ComSeq[i];
        return LCS_Compare(n,A,ComSeq.size(),arr);
    }
    else{
        CommonSubSeq(n,A,l,C,ComSeq);
        for(int i=0;i<ComSeq.size();i++)arr[i]=ComSeq[i];
        return LCS_Compare(m,B,ComSeq.size(),arr);
    }

}

int main(){
    int n,m,l;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    cin>>m;
    int B[m];
    for(int j=0;j<m;j++)cin>>B[j];
    cin>>l;
    int C[l];
    for(int k=0;k<l;k++)cin>>C[k];
    cout<<LCS_3(n,A,m,B,l,C);

    return 0;
}

