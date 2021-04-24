#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define MAX_SIZE 1000

// Priority Queue based on Binary Max_Heap Tree
// Class PriorityQueue Declaration

class PriorityQueue{
private:
    int H[MAX_SIZE];
    int Size;
public:
    PriorityQueue();  //Constructor
    int Parent(int i);
    int LeftChild(int i);
    int RightChild(int i);
    void SiftDown(int i);
    void SiftUp(int i);
    void Insert(int key);
    void Remove(int i);
    int GetSize();
    void ChangePriority(int i, int p);
    void Print();
    int ExtractMax();
    ~PriorityQueue();  //Destructor
};


#endif // PRIORITYQUEUE_H
