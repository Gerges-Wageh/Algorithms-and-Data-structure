#include"SinglyLinkedWithTail.h"
#ifndef LINKEDLISTBASEDQUEUE_H
#define LINKEDLISTBASEDQUEUE_H

// This implementation eliminates the dis advantages of ArrayBased implementation as now the size is unlimited and Queue space reserved in the heap
// Class Queue Declaration

class Queue{
private:
    LinkedList Queue_Space;
    int Size;
public:
    Queue(); //Constructor
    void Enqueue(int key);
    int Dequeue();
    bool Empty();
    ~Queue(); //Destructor

};


#endif // LINKEDLISTBASEDQUEUE_H
