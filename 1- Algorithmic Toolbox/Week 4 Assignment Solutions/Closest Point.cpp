#include<bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int,int> &P1, const pair<int,int> &P2){
    return (P1.second < P2.second);
}

float GetDistance(const pair<int,int> &P1, const pair<int,int> &P2){
    return sqrt(pow(P1.first-P2.first,2)+pow(P1.second-P2.second,2));
}

float NaiveClosestDistance(const vector<pair<int,int>> &P, int l, int r){
    float d = FLT_MAX, temp;
    for(int i=l;i<r;i++){
        for(int j=i+1;j<=r;j++){
            temp = GetDistance(P[i],P[j]);
            if(temp<d)
                d=temp;
        }
    }
    return d;
}

float ClosestPoint( const vector<pair<int,int>> &P, int l,  int r){
    if(r-l<=3)
        return NaiveClosestDistance(P,l,r);

    int m = l + (r-l)/2;
    float L = P[m].first;
    float d1 = ClosestPoint(P,l,m);
    float d2 = ClosestPoint(P,m+1,r);
    float d = min(d1,d2);
    float temp;
    vector<pair<int,int>> Strip;
    for(int i=l;i<=r;i++){
        if(abs(P[i].first-L)<=d)
            Strip.push_back(P[i]);
    }
    sort(Strip.begin(),Strip.end(),sortbysec);
    for(int i=0;i<Strip.size();i++){
        for(int j=i+1;j<Strip.size()&&abs(Strip[j].second-Strip[i].second)<=d;j++){
            temp = GetDistance(Strip[i],Strip[j]);
            if(temp<d)
                d = temp;
        }
    }
    return d;
}

int main(){

    int n,x,y;
    cin>>n;
    vector<pair<int,int>> points;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }
    sort(points.begin(),points.end());
    cout<<setprecision(7)<<ClosestPoint(points,0,n-1);

    return 0;
}
