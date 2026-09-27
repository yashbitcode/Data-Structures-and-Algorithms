#include <stdexcept>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class Deque
{
private:
    Node *front;
    Node *rear;
    int length;

    int insertFirst(int data)
    {
        if (!isEmpty())
            throw runtime_error("Deque is not empty");

        Node *newNode = new Node(data);

        length++;

        front = rear = newNode;

        return data;
    }

    int deleteFirst()
    {
        if (isEmpty())
            throw runtime_error("Deque underflow");
        if (front != rear)
            throw runtime_error("front and rear are not in same position");

        int data = front->data;

        delete front;

        front = rear = nullptr;
        length--;

        return data;
    }

public:
    Deque(Node *newNode = nullptr)
    {
        front = rear = newNode;
        length = newNode ? 1 : 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    int getLength()
    {
        return length;
    }

    int getFront()
    {
        if (isEmpty())
            throw runtime_error("Deque underflow");
        return front->data;
    }

    int getRear()
    {
        if (isEmpty())
            throw runtime_error("Deque underflow");
        return rear->data;
    }

    int insertFromFront(int data)
    {
        if (isEmpty())
            return insertFirst(data);

        Node *newNode = new Node(data);
        newNode->next = front;
        front->prev = newNode;

        front = newNode;

        length++;
    }

    int insertFromRear(int data)
    {
        if (isEmpty())
            return insertFirst(data);

        Node *newNode = new Node(data);
        newNode->prev = rear;
        rear->next = newNode;

        rear = newNode;

        length++;
    }

    int deleteFromFront()
    {
        if (isEmpty())
            throw runtime_error("Deque underflow");

        if (front == rear)
            return deleteFirst();
        
        Node* temp = front->next;
        front->next = nullptr;

        delete front;
        front = temp;

        length--;
    }

    int deleteFromRear()
    {
        if (isEmpty())
            throw runtime_error("Deque underflow");

        if (front == rear)
            return deleteFirst();
        
        Node* temp = rear->prev;
        rear->prev = nullptr;

        delete rear;
        rear = temp;

        length--;
    }
};

int main()
{
    Deque dq;

    // cout << dq.getLength() << endl;

    dq.insertFromFront(10);
    dq.insertFromFront(20);
    dq.insertFromRear(40);

    dq.deleteFromFront();
    dq.deleteFromRear();
    dq.deleteFromRear();

    cout << dq.getLength() << endl;

    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;
}