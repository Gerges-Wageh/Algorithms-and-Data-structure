#include"DoublyLiknedList.h"
#include<iostream>

//Class Node implementation
Node::Node(int key){
    this->key = key;  // "this" is just a pointer to the object invokes the function(constructor) in other words it returns its address
    this->next = nullptr;
    this->previous = nullptr;
}
void Node::Set_next(Node* next){
    this->next = next;
}
Node* Node::Get_next(){
    return next;
}
void Node::Set_previous(Node* previous){
    this->previous = previous;
}
Node* Node::Get_Previous(){
    return previous;
}
void Node::Set_data(int data){
    key = data;
}
int Node::Get_data(){
    return key;
}


// Class LinkedList implementation
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

bool LinkedList::Empty() // Time Complexity: O(1)
{
    return (head == nullptr);
}

int LinkedList::Length() // Time Complexity: O(n)
{
     Node* current = head;
     int counter = 0;
     while(current != nullptr){
        counter ++;
        current = current->next;
     }
     return counter;
}

void LinkedList::PushFront(int key) // Time Complexity: O(1)
{
        Node* N = new Node(key);  // if we declare an object Node not pointer it will be deleted when the function ends
        if(head == nullptr){
            head = N;
            tail = N;
        }
        else{
            N->next = head;
            head->previous = N;
            head = N;
        }

}

void LinkedList::PopFront() // Time Complexity: O(1)
{
    if(head == nullptr)
        return;
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node* head_to_be_deleted = head;
        head = head->next;
        head->previous = nullptr;
        delete head_to_be_deleted;
    }
}

void LinkedList::PushBack(int key) // Time Complexity: O(1)
{
    if(head == nullptr){
        PushFront(key);
        return;
    }
    Node* N = new Node(key);
    tail->next = N;
    tail = N;
}

void LinkedList::PopBack() // Time Complexity: O(1)
{
    if(head == nullptr)
        return;
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node* tail_to_be_deleted = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete tail_to_be_deleted;
    }
}

int LinkedList::TopFront() // Time Complexity: O(1)
{
    if(head == nullptr){
        std::cout<<"The LinkedList is empty!\n";
        return -1;
    }
    return head->key;
}

int LinkedList::TopBack() // Time Complexity: O(1)
{
    if(head == nullptr){
        std::cout<<"The LinkedList is empty!\n";
        return -1;
    }
    return tail->key;
}

void LinkedList::Sort()  // Time Complexity: O(n^2)
{
    if(head == nullptr || head->next == nullptr)
        return;
    Node* current = head;
    Node* it = current->next;
    while(current->next != nullptr){
        while(it != nullptr){
            if(it->key < current->key)
                std::swap(it->key,current->key);
            it = it->next;
        }
        current = current->next;
        it = current->next;
    }
}

void LinkedList::Clear() // Time Complexity: O(n)
{
    while(!Empty())
        PopFront();
}

void LinkedList::Print() // Time Complexity: O(n)
{
    if(head == nullptr){
        std::cout<<"The LinkedList is empty!\n";
        return;
    }
    Node* current = head;
    while(current != nullptr){
        std::cout<<current->key<<" ";
        current = current->next;
    }
    std::cout<<"\n";
}

LinkedList::~LinkedList()  // Time Complexity: O(n)
{
    Clear();
}

