#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int data, Node* left = nullptr, Node* right = nullptr) {
        this->left = left;
        this->right = right;
        this->data = data;
    }
};

void preOrder(Node* root) {
    if(!root) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}  

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrder(root);
    cout << endl;

    inOrder(root);
    cout << endl;
    
    postOrder(root);
    cout << endl;
}