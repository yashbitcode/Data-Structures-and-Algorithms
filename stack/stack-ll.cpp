#include <stdexcept>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;

    Node(int data, Node *prev = nullptr)
    {
        this->data = data;
        this->prev = prev;
    }
};

class Stack
{
private:
    Node *top;
    int length;

public:
    Stack(Node *top)
    {
        this->top = top;
        length = top ? 1 : 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    int peek()
    {
        if (isEmpty())
            throw runtime_error("Stack is empty");

        return top->data;
    }

    int push(int data)
    {
        Node *newNode = new Node(data);

        if (!top)
        {
            top = newNode;
            length++;
            return data;
        }

       newNode->prev = top;
       top = newNode;

       length++;

       return data;
    }

    void pop()
    {
        if (isEmpty())
            throw runtime_error("Stack is empty");

        Node *temp = top->prev;
        top->prev = nullptr;

        delete top;

        length--;
        top = temp;
    }

    int getLen()
    {
        return length;
    }
};

int main()
{
    Stack st(new Node(10));
    st.push(90);
    st.push(100);

    st.pop();
    st.pop();
    st.pop();

    st.push(90);
    st.push(70);
    st.push(60);
    st.push(500);

    cout << st.peek() << endl;
    cout << st.getLen() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.getLen() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.getLen() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.getLen() << endl;
}