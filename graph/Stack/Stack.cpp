
#include "Stack.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

Stack::Stack(int length)
{
    int baseLen = length <= 0 ? 1 : length;

    st = (int *)calloc(baseLen, sizeof(int));
    if (!st)
        throw bad_alloc();

    idx = 0;
    this->length = baseLen;
}

Stack::~Stack()
{
    cout << "Stack destruction" << endl;

    free(st);
    st = nullptr;
}

bool Stack::isEmpty()
{
    return idx == 0;
}

bool Stack::isFull()
{
    return idx == length;
}

int Stack::getLen()
{
    return length;
}

int Stack::getIdx()
{
    return idx;
}

bool Stack::reallocStack(int newLength)
{
    int baseLen = newLength <= 0 ? 1 : newLength;

    if (baseLen == length)
        return false;

    int *temp = (int *)realloc(st, baseLen * sizeof(int));

    if (!temp)
        return false;

    st = temp;

    if (baseLen < length && idx >= baseLen)
    {
        cout << "Data will be lost" << endl;
        idx = baseLen;
    }

    length = baseLen;

    return true;
}

int Stack::peek()
{
    if (isEmpty())
        throw runtime_error("Stack is empty");

    return st[idx - 1];
}

int Stack::push(int data)
{
    if (isFull())
        throw runtime_error("Stack is full");

    st[idx++] = data;

    return data;
}

int Stack::pop()
{
    if (isEmpty())
        throw runtime_error("Stack is empty");

    int val = st[--idx];
    st[idx] = 0;

    return val;
}
