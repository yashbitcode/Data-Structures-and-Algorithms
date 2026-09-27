#include <stdexcept>
#include <iostream>
using namespace std;

class Queue
{
private:
    int *qu;
    int front;
    int rear;
    int length;

public:
    Queue(int length = 1)
    {
        int baseLen = length <= 0 ? 1 : length;

        qu = new int[baseLen];
        front = rear = -1;
        this->length = length;
    }

    bool isEmpty() const
    {
        return rear == -1 && front == -1;
    }

    bool isFull() const
    {
        return (rear + 1) >= length;
    }

    int getLength() const
    {
        return length;
    }

    int getCapacity() const
    {
        if (isEmpty())
            return 0;

        // cout << front << " ; " << rear << endl;
        return (rear - front) + 1;
    }

    int push(int data)
    {
        if (isFull())
            throw runtime_error("Queue overflow");

        if (isEmpty())
            front++;
        qu[++rear] = data;

        return data;
    }

    int pop()
    {
        if (isEmpty())
            throw runtime_error("Queue underflow");

        int val = qu[front];

        if (front == rear)
        {
            front = rear = -1;
            return val;
        }

        for (int i = (front + 1); i <= rear; i++)
        {
            qu[i - 1] = qu[i];
        }

        rear--;

        return val;
    }

    int getFront()
    {
        if (isEmpty())
            throw runtime_error("Queue underflow");

        return qu[front];
    }

    int getRear()
    {
        if (isEmpty())
            throw runtime_error("Queue underflow");

        return qu[rear];
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);

    q.pop();
    q.push(90);
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.push(100);
    //   q.pop();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.getLength() << endl;
    cout << q.getCapacity() << endl;
}