#ifndef ARRAYBASEDSTACK_H
#define ARRAYBASEDSTACK_H

#define MAX_SIZE 1000

// the main disadvantage is that the size of the stack is limited and as the size increases there will be overhead of the memory frame

// Stack Class Declaration

class Stack{
private:
    int Stack_Space[MAX_SIZE];
    int Size;
public:
    Stack(); // Constructor
    void Push(int key);
    int Top();
    void Pop();
    bool Empty();
    ~Stack(); // Destructor
};

#endif // ARRAYBASEDSTACK_H
