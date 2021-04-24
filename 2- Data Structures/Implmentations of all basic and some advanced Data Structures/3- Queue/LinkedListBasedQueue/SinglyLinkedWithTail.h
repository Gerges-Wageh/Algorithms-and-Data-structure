#ifndef SINGLYLINKEDWITHTAIL_H
#define SINGLYLINKEDWITHTAIL_H

// Class Node Declaration
class Node{
 private:
    int key;
    Node* next;
 public:

    Node(int key); // Constructor
    void Set_next(Node* next);
    Node* Get_next();
    void Set_data(int data);
    int Get_data();

    friend class LinkedList; // To allow class LinkedList of accessing the data members of Node class.
};

// Class LinkedList Declaration
class LinkedList{
 private:
     Node* head;
     Node* tail;
 public:

    LinkedList();  // Constructor
    bool Empty();
    int Length();
    void PushFront(int key);
    void PopFront();
    void PushBack(int key);
    void PopBack();
    int TopFront();
    int TopBack();
    void Sort();
    void Clear();
    void Print();
    ~LinkedList(); // Destructor

};

#endif // SINGLYLINKEDWITHTAIL_H
