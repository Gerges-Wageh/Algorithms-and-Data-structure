#include"SinglyLinkedWithoutTail.h"
#ifndef LINKEDLISTBASEDSTACK_H
#define LINKEDLISTBASEDSTACK_H

// This way of implementation eliminates the ArrayBased implementation as now the size is unlimited and it`s done in the heap.

// Class Stack Declaration

class Stack{
private:
    LinkedList Stack_Space;
    int Size;
public:
    Stack(); // Constructor
    void Push(int key);
    int Top();
    void Pop();
    bool Empty();
    ~Stack(); // Destructor
};

#endif // LINKEDLISTBASEDSTACK_H
