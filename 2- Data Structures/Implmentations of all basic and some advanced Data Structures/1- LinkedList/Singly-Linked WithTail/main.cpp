#include<bits/stdc++.h>
#include "SinglyLinkedWithTail.h"
using namespace std;

int main(){

    LinkedList MyLinkedList;
    MyLinkedList.PushBack(4);
    MyLinkedList.PushBack(15);
    MyLinkedList.PushBack(10);
    MyLinkedList.PushBack(6);
    MyLinkedList.Print();
    MyLinkedList.Sort();
    MyLinkedList.Print();
    cout<<MyLinkedList.TopFront()<<endl;
    cout<<MyLinkedList.TopBack()<<endl;
    MyLinkedList.Print();
    cout<<MyLinkedList.Empty()<<endl;
    MyLinkedList.PopBack();
    MyLinkedList.Print();
    MyLinkedList.PopFront();
    MyLinkedList.Print();
    cout<<MyLinkedList.TopFront()<<endl;
    cout<<MyLinkedList.TopBack()<<endl;
    MyLinkedList.Clear();
    MyLinkedList.Print();

    return 0;
}
