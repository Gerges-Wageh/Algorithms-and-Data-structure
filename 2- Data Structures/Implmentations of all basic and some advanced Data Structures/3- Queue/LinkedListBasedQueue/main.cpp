#include"LinkedListBasedQueue.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    Queue Q1;
    Q1.Enqueue(1);
    Q1.Enqueue(2);
    Q1.Enqueue(3);
    while(!Q1.Empty())
        cout<<Q1.Dequeue()<< " ";

    return 0;
}

