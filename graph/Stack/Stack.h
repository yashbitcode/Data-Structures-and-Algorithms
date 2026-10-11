#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int *st;
    int length;
    int idx;

public:
    Stack(int length = 1);
    ~Stack();

    bool isEmpty();
    bool isFull();

    int getLen();
    int getIdx();

    bool reallocStack(int newLength);

    int peek();
    int push(int data);
    int pop();
};

#endif
