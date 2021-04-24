#ifndef ARRAYBASEDQUEUE_H
#define ARRAYBASEDQUEUE_H

#define MAX_SIZE 1000

// the main disadvantage is that the size of the queue is limited and as the size increases there will be overhead of the memory frame

// Class Queue Declaration
class Queue{
private:
    int Queue_Space[MAX_SIZE];
    int read_ptr;
    int write_ptr;
public:
    Queue();  // Constructor
    void Enqueue(int key);
    int Dequeue();
    bool Empty();
    ~Queue();  // Destructor
};

#endif // ARRAYBASEDQUEUE_H
