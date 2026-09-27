#include <stdexcept>
#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *qu;
    int front;
    int rear;
    int length;

public:
    CircularQueue(int length = 1)
    {
        int baseLen = length <= 0 ? 1 : length;

        qu = new int[baseLen];
        front = rear = -1;
        this->length = length;
    }

    void getIdxPositions() {
        cout << "front: " << front << " : " << "rear: " << rear << endl << endl;
    }

    bool isEmpty() const
    {
        return rear == -1 && front == -1;
    }

    bool isFull() const
    {
        return ((rear + 1) % length) == front;
    }

    int getLength() const
    {
        return length;
    }

    int getCapacity() const
    {
        if (isEmpty())
            return 0;

        return (rear < front) ? ((length + rear) - front) + 1 : (rear - front) + 1;
    }

    int push(int data)
    {
        if (isFull())
            throw runtime_error("Queue overflow");

        if (isEmpty())
            front++;
        qu[((rear + 1) % length)] = data;

        rear = (rear + 1) % length;
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

        front = (front + 1) % length;

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
    CircularQueue q(5);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    // q.push(16);

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    q.pop();

    q.push(21);
    // q.push(22);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.getIdxPositions();
    cout << q.getCapacity() << endl;
    // cout << q.getFront() << endl;
    // cout << q.getRear() << endl;
}