#include<bits/stdc++.h>
using namespace std;

static long long M[15][15],m[15][15];

long long Min(long long m, long long a, long long b, long long c, long long d){
    return min(m,min(a,min(b,min(c,d))));
}

long long Max(long long M, long long a, long long b, long long c, long long d){
    return max(M,max(a,max(b,max(c,d))));
}
pair<long long,long long> MinAndMax(char op[], int i, int j){
    long long min = INT_MAX;
    long long max = INT_MIN;
    long long a,b,c,d;
    for(int k=i;k<j;k++){
        if(op[k-1]=='+'){
            a = M[i][k] + M[k+1][j];
            b = M[i][k] + m[k+1][j];
            c = m[i][k] + M[k+1][j];
            d = m[i][k] + m[k+1][j];
            min = Min(min,a,b,c,d);
            max = Max(max,a,b,c,d);
        }
        else if(op[k-1]=='-'){
            a = M[i][k] - M[k+1][j];
            b = M[i][k] - m[k+1][j];
            c = m[i][k] - M[k+1][j];
            d = m[i][k] - m[k+1][j];
            min = Min(min,a,b,c,d);
            max = Max(max,a,b,c,d);
        }
        else{
            a = M[i][k] * M[k+1][j];
            b = M[i][k] * m[k+1][j];
            c = m[i][k] * M[k+1][j];
            d = m[i][k] * m[k+1][j];
            min = Min(min,a,b,c,d);
            max = Max(max,a,b,c,d);
        }
    }
    return make_pair(min,max);
}

long long MaxVal_of_Expression(int d[], char op[], int n){
    int j;
    for(int i=1;i<=n;i++){
            m[i][i]=d[i-1];
            M[i][i]=d[i-1];
    }
    for(int s=1;s<=n;s++){
        for(int i=1;i<=n-s;i++){
            j=i+s;
            m[i][j]=MinAndMax(op,i,j).first;
            M[i][j]=MinAndMax(op,i,j).second;
        }
    }

    return M[1][n];
}

int main(){
    string E;
    cin>>E;
    int n = E.length();
    int d[n/2+1];
    char op[n/2];
    for(int i=0;i<n/2+1;i++)d[i]=stoi(E.substr(i*2,1));
    for(int j=0;j<n/2;j++)op[j]=E[j*2+1];
    cout<<MaxVal_of_Expression(d,op,n/2+1);



    return 0;
}
