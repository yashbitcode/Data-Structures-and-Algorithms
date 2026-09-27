#include <stdexcept>
#include <iostream>
using namespace std;

class Stack
{
private:
    int *st;
    int length;
    int idx;

public:
    Stack(int length = 1)
    {
        int baseLen = length <= 0 ? 1 : length;
        // st = new int[baseLen];
        st = (int *)calloc(baseLen, sizeof(int));
        idx = 0;

        this->length = baseLen;
    }

    ~Stack()
    {
        cout << "Stack destruction" << endl;
        // delete[] st;

        free(st);

        st = nullptr;
    }

    bool isEmpty()
    {
        return idx == 0;
    }

    bool isFull()
    {
        return idx == length;
    }

    int getLen()
    {
        return length;
    }

    bool reallocStack(int newLength)
    {
        int baseLen = newLength <= 0 ? 1 : newLength;
        if (baseLen == length)
            return false;

        int *temp = (int *)realloc(st, baseLen * sizeof(int));

        if (!temp)
            return false;

        if (baseLen < length && idx >= baseLen)
        {
            cout << "Data will be lost" << endl;
            idx = baseLen;
        }

        length = baseLen;

        return true;
    }

    int peek()
    {
        if (isEmpty())
            throw runtime_error("Stack is empty");

        return st[idx - 1];
    }

    int push(int data)
    {
        if (isFull())
            throw runtime_error("Stack is full");

        st[idx++] = data;

        return data;
    }

    int pop()
    {
        if (isEmpty())
            throw runtime_error("Stack is empty");

        int val = st[--idx];

        st[idx] = 0;

        return val;
    }

    int getIdx()
    {
        return idx;
    }
};

int main()
{
    Stack st(5);

    // cout << st.getLen() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << st.peek() << endl;
    cout << st.getIdx() << endl;
    cout << st.getLen() << endl
         << endl;

    st.reallocStack(3);

    cout << st.peek() << endl;
    cout << st.getIdx() << endl;
    cout << st.getLen() << endl
         << endl;

    st.reallocStack(5);

    cout << st.peek() << endl;
    cout << st.getIdx() << endl;
    cout << st.getLen() << endl
         << endl;

    st.reallocStack(4);

    cout << st.peek() << endl;
    cout << st.getIdx() << endl;
    cout << st.getLen() << endl
         << endl;

    st.push(90);

    cout << st.peek() << endl;
    cout << st.getIdx() << endl;
    cout << st.getLen() << endl
         << endl;

    st.reallocStack(3);

    cout << st.peek() << endl;
    cout << st.getIdx() << endl;
    cout << st.getLen() << endl
         << endl;
}