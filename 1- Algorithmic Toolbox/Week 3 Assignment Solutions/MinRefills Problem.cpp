#include<bits/stdc++.h>
using namespace std;
int MinRefills(int a[],int d,int n){
    int currentStop=0;
    int numRefills=0;
    int lastStop;
    while(currentStop<n-1){
        lastStop=currentStop;
        while(currentStop<n && a[currentStop+1]-a[lastStop]<=d)
            currentStop++;

        if(currentStop<n-1)
            numRefills++;
        if(currentStop==lastStop)
            return -1;
    }
    return numRefills;

}
int main(){
    int x[6]{0,200,375,550,750,950};
    cout<<MinRefills(x,400,6);

}




