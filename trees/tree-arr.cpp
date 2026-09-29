#include <stdexcept>
#include <algorithm>
#include <iostream>
using namespace std;

class TreeArr
{
private:
    int *tree;
    int length;

    bool ifParentExist(int idx)
    {
        return idx < length && tree[idx] != -1;
    }

    int getLeftIdx(int parentIdx)
    {
        int LIdx = (parentIdx * 2) + 1;

        return LIdx;
    }

    int getRightIdx(int parentIdx)
    {
        int RIdx = (parentIdx * 2) + 2;

        return RIdx;
    }

    int getParentIdxFromChildIdx(int idx)
    {
        return (idx - 1) / 2;
    }

public:
    TreeArr(int length = 1)
    {
        int baseLen = length <= 0 ? 1 : length;

        tree = new int[baseLen];

        fill(tree, tree + baseLen, -1);

        this->length = baseLen;
    }

    int insertRoot(int data)
    {
        if (tree[0] != -1)
            cout << "Resetting the root" << endl;

        tree[0] = data;

        return data;
    }

    int insertLeft(int parentIdx, int data)
    {
        if (!ifParentExist(parentIdx))
            throw runtime_error("Parent idx out of bound");

        int LIdx = getLeftIdx(parentIdx);

        if (LIdx >= length)
            throw runtime_error("Left idx out of bound");

        tree[LIdx] = data;

        return data;
    }

    int insertRight(int parentIdx, int data)
    {
        if (!ifParentExist(parentIdx))
            throw runtime_error("Parent idx out of bound");

        int RIdx = getRightIdx(parentIdx);

        if (RIdx >= length)
            throw runtime_error("Right idx out of bound");

        tree[RIdx] = data;

        return data;
    }

    void printTreeLinear()
    {
        for (int i = 0; i < length; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    void preOrder(int idx)
    {
        if (idx >= length)
            return;

        cout << tree[idx] << " ";

        preOrder(getLeftIdx(idx));
        preOrder(getRightIdx(idx));
    }

    void inOrder(int idx)
    {
        if (idx >= length)
            return;

        inOrder(getLeftIdx(idx));
        cout << tree[idx] << " ";
        inOrder(getRightIdx(idx));
    }

    void postOrder(int idx)
    {
        if (idx >= length)
            return;

        postOrder(getLeftIdx(idx));
        postOrder(getRightIdx(idx));
        cout << tree[idx] << " ";
    }
};

int main()
{
    TreeArr t(8);

    t.insertRoot(10);

    t.insertLeft(0, 20);
    t.insertRight(0, 30);

    t.insertLeft(1, 40);
    t.insertRight(1, 50);

    t.insertLeft(2, 60);
    t.insertRight(2, 70);

    t.insertLeft(3, 80);
    // t.insertRight(3, 80);

    cout << "Linear: ";
    t.printTreeLinear();

    cout << "PreOrder: ";
    t.preOrder(0);
    cout << endl;

    cout << "InOrder: ";
    t.inOrder(0);
    cout << endl;

    cout << "PostOrder: ";
    t.postOrder(0);
    cout << endl;

    // cout << t.getParentIdxFromChildIdx(1) << endl;
    // cout << t.getParentIdxFromChildIdx(2) << endl;
}