#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class SinglyLL
{
public:
    Node *head;

    SinglyLL(Node *head = nullptr)
    {
        this->head = head;
    };

    void printLL(bool withAddress = false)
    {
        Node *temp = this->head;

        while (temp)
        {
            // cout << "[" << (withAddress ? to_string(reinterpret_cast<uintptr_t>(temp)) +  " : " : "") << temp->data << "]";

            cout << "[";

            if (withAddress)
                cout << temp << " : ";

            cout << temp->data << "]";

            temp = temp->next;

            if (temp)
                cout << " -> ";
        }

        cout << endl << endl;
    }

    void insertAtPosition(int data, int position)
    {
        if(position <= 0) return this->insertAtStart(data);

        int cnt = 0;
        Node* temp = this->head;
        Node* prev = nullptr;

        while(cnt < position && temp) {
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        if(!temp) return this->insertAtEnd(data);

        Node* newNode = new Node(data);
        prev->next = newNode;
        newNode->next = temp;
    }

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);

        if (!this->head)
            this->head = newNode;
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = this->head;

        if (!temp)
            this->head = newNode;
        else
        {
            while (temp->next)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void deleteAtStart()
    {
        if (!this->head)
            return;

        Node *temp = this->head->next;

        delete this->head;

        this->head = temp;
    }

    void deleteAtEnd()
    {
        if(!this->head || !this->head->next) return deleteAtStart();

        Node* temp = this->head;
        Node* prev = nullptr;

        while(temp->next) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        temp->next = nullptr;

        delete temp;
    }

    void deleteAtPosition(int position) {
        if(position <= 0 || !this->head) return this->deleteAtStart();

        Node* temp = this->head;
        Node* prev = nullptr;
        int cnt = 0;

        while(cnt < position && temp) {
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        if(!temp) return this->deleteAtEnd();

        prev->next = temp->next;
        temp->next = nullptr;

        delete temp;
    }
};

int main()
{
    Node *head = new Node(10);
    SinglyLL sll(head);

    sll.insertAtEnd(20);
    sll.insertAtEnd(30);
    sll.insertAtEnd(40);
    sll.insertAtEnd(50);

    sll.insertAtStart(60);

    
    sll.insertAtPosition(11, 0);
    sll.insertAtPosition(12, -10);
    sll.insertAtPosition(13, 6);
    sll.insertAtPosition(14, 100);
    sll.printLL();
    sll.insertAtPosition(15, 10);
    sll.printLL();


    // sll.deleteAtStart();
    // sll.deleteAtEnd();

    // sll.printLL();

    // sll.deleteAtPosition(0);
    
    // sll.deleteAtPosition(-100);
    // sll.printLL();
    // sll.deleteAtPosition(6);
    // sll.printLL();
    // sll.deleteAtPosition(60);
    // sll.printLL();

    // sll.deleteAtPosition(2);

    // sll.printLL(true);
    // sll.deleteAtEnd();
    // sll.printLL(true);
}