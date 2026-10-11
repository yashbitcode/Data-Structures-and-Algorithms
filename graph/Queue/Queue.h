
#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int *qu;
    int front;
    int rear;
    int length;

public:
    Queue(int length = 1);

    bool isEmpty() const;
    bool isFull() const;

    int getLength() const;
    int getCapacity() const;

    int push(int data);
    int pop();

    int getFront();
    int getRear();

    ~Queue();
};

#endif
