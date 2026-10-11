
#include "Queue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Queue::Queue(int length)
{
    int baseLen = length <= 0 ? 1 : length;

    qu = new int[baseLen];
    front = rear = -1;
    this->length = baseLen;
}

Queue::~Queue()
{
    delete[] qu;
}

bool Queue::isEmpty() const
{
    return rear == -1 && front == -1;
}

bool Queue::isFull() const
{
    return (rear + 1) >= length;
}

int Queue::getLength() const
{
    return length;
}

int Queue::getCapacity() const
{
    if (isEmpty())
        return 0;

    return (rear - front) + 1;
}

int Queue::push(int data)
{
    if (isFull())
        throw runtime_error("Queue overflow");

    if (isEmpty())
        front++;

    qu[++rear] = data;

    return data;
}

int Queue::pop()
{
    if (isEmpty())
        throw runtime_error("Queue underflow");

    int val = qu[front];

    if (front == rear)
    {
        front = rear = -1;
        return val;
    }

    for (int i = front + 1; i <= rear; i++)
    {
        qu[i - 1] = qu[i];
    }

    rear--;

    return val;
}

int Queue::getFront()
{
    if (isEmpty())
        throw runtime_error("Queue underflow");

    return qu[front];
}

int Queue::getRear()
{
    if (isEmpty())
        throw runtime_error("Queue underflow");

    return qu[rear];
}
