#include<bits/stdc++.h>
using namespace std;
void SortAccordingly(int v[],int w[],double c[],int n){
    pair<double,int>p1[n];
    pair<double,int>p2[n];
    for(int i=0;i<n;i++){
        p1[i].first = c[i];
        p1[i].second = v[i];
        p2[i].first = c[i];
        p2[i].second = w[i];
    }
    sort(p1,p1+n);
    sort(p2,p2+n);
    for(int i=0;i<n;i++){
        c[n-1-i]=p1[i].first;
        v[n-1-i]=p1[i].second;
        w[n-1-i]=p2[i].second;
    }
}
int main(){
   int n,c;
   cin>>n>>c;
   int v[n],w[n];
   double x[n];
   for(int i=0;i<n;i++){
        cin>>v[i]>>w[i];
         x[i]=(double)v[i]/w[i];
   }
   SortAccordingly(v,w,x,n);
   double max_value=0.0;
   int i=0;
   while(c&&i<n){
            if(c>=w[i]){
                c-=w[i];
                max_value+=v[i];
            }
            else{
                max_value+=c*x[i];
                c=0;
            }
        i++;
    }
   cout.precision(10);
   cout<<max_value;
}

