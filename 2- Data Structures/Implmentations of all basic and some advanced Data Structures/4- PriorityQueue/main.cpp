#include"PriorityQueue.h"
#include<bits/stdc++.h>

using namespace std;

int main(){
    PriorityQueue Q;
    Q.Insert(5);
    Q.Insert(14);
    Q.Insert(10);
    Q.Print();
    cout<<"\n"<<Q.ExtractMax()<<"\n";
    Q.Print();
    cout<<"\n";
    Q.Insert(2);
    Q.Print();
    cout<<"\n"<<Q.ExtractMax()<<"\n";
    Q.Print();
    Q.Insert(1);
    Q.Print();
    Q.ChangePriority(2,50);
    Q.Print();
    Q.ChangePriority(1,1);
    Q.Print();
    cout<<Q.GetSize();


    return 0;
}
