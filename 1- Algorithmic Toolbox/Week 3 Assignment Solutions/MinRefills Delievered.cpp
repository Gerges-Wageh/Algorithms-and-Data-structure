#include<bits/stdc++.h>
using namespace std;
int MinNumRefills(int a[],int n, int d){
    int R=0;
    int current=1;
    int last=0;
    while(current<n){
        if(a[current]-a[last]<=d)
            current++;
        else{
            if(current-last==1)
                return -1;
            else
                last = current-1;
                R++;
        }

    }
    return R;
}
int main(){
    int d,m,n;
    cin>>d>>m>>n;
    n+=2;
    int stops[n];
    stops[0]=0;
    stops[n-1]=d;
    for(int i=1;i<n-1;i++)
        cin>>stops[i];
   cout<<MinNumRefills(stops,n,m);
}

