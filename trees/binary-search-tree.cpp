#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BST
{
public:
    Node *root;

    BST(Node *root = nullptr)
    {
        this->root = root;
    }

    Node *insert(Node *root, int value)
    {
        if (!root)
            return new Node(value);
        else if (root->data >= value)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    Node* getSuccessor(Node* root) {
        Node* temp = root->right;

        while(temp && temp->left) {
            temp = temp->left;
        }

        return temp;
    }

    Node* getPredecessor(Node* root) {
        Node* temp = root->left;

        while(temp && temp->right) {
            temp = temp->right;
        }

        return temp;
    }

    Node *deleteNode(Node *root, int val)
    {
        if (!root) return nullptr;
        if (root->data > val)
            root->left = deleteNode(root->left, val);
        else if (root->data < val)
            root->right = deleteNode(root->right, val);
        else
        {
            if (!root->left)
            {
                Node *temp = root->right;
                root->left = root->right = nullptr;

                delete root;

                root = temp;
            }
            else if (!root->right)
            {
                Node *temp = root->left;
                root->left = root->right = nullptr;

                delete root;

                root = temp;
            }
            else
            {
                Node* successor = getSuccessor(root);
                root->data = successor->data;

                root->right = deleteNode(root->right, successor->data);
            }
        }
        
        return root;
    }

    void search(Node *root, int element)
    {
        if (!root)
            cout << "Element not found" << endl;
        else if (root->data == element)
            cout << "Element found: " << element << endl;
        else if (root->data > element)
            search(root->right, element);
        else
            search(root->left, element);
    }

    void inOrder(Node *root)
    {
        if (!root)
            return;

        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }
};

int main()
{
    BST bst;
    int arr[] = {6, 8, 9, 10, 20, 25, 22, 30, 35, 40, 50};

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        bst.root = bst.insert(bst.root, arr[i]);
    }

    bst.inOrder(bst.root);

    cout << endl;

    // bst.root = bst.deleteNode(bst.root, 6);
    bst.root = bst.deleteNode(bst.root, 30);

    bst.inOrder(bst.root);
}