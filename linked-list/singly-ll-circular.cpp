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

class SinglyCircularLL
{
public:
    Node *head = nullptr;

    SinglyCircularLL(Node *head = nullptr)
    {
        this->head = head;

        if (this->head)
            this->head->next = head;
    };

    void printLL(int circularCnt = 0, bool withAddress = false)
    {
        Node *temp = this->head;

        do
        {
            cout << "[";

            if (withAddress)
                cout << temp << " : ";

            cout << temp->data << "]";

            temp = temp->next;

            if (temp != head || circularCnt)
                cout << " -> ";
        } while (temp != head || circularCnt--);

        cout << endl;
    }

    void insertAtPosition(int data, int position)
    {
        if (position <= 0 || !this->head)
            return this->insertAtStart(data);

        int cnt = 0;
        Node *temp = this->head;
        Node *prev = nullptr;

        while (cnt < position && temp)
        {
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        if (temp == this->head)
            return this->insertAtStart(data);

        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = temp;
    }

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);

        if (!this->head)
        {
            this->head = newNode;
            this->head->next = newNode;
        }
        else
        {
            Node *temp = this->head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            newNode->next = this->head;
            temp->next = newNode;

            this->head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = this->head;

        if (!temp)
        {
            this->head = newNode;
            this->head->next = newNode;
        }
        else
        {
            Node *temp = this->head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = this->head;
        }
    }

    void deleteAtStart()
    {
        if (!this->head)
            return;

        Node *temp = this->head;
        Node *assignedLast = nullptr;

        while (temp->next != this->head)
        {
            temp = temp->next;
        }

        if (temp == this->head)
            this->head->next = nullptr;
        else
        {
            Node *headNext = this->head->next;

            temp->next = headNext;
            this->head->next = nullptr;

            assignedLast = headNext;
        }

        delete this->head;

        this->head = assignedLast;
    }

    void deleteAtEnd()
    {
        if (!this->head)
            return;

        Node *temp = this->head;
        Node *prev = nullptr;

        while (temp->next != this->head)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == this->head)
            return this->deleteAtStart();

        prev->next = this->head;
        temp->next = nullptr;

        delete temp;
    }

    void deleteAtPosition(int position)
    {
        if (position <= 0 || !this->head)
            return this->deleteAtStart();

        Node *temp = this->head;
        Node *prev = nullptr;

        int cnt = 0;

        while (cnt < position && temp)
        {
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        if (temp == this->head)
            return this->deleteAtStart();

        Node *tempNext = temp->next;
        prev->next = tempNext;

        temp->next = nullptr;
        delete temp;
    }
};

int main()
{
    SinglyCircularLL scll(new Node(10));

    scll.insertAtStart(20);
    scll.insertAtStart(30);
    scll.insertAtStart(40);
    scll.insertAtStart(50);
    scll.insertAtStart(60);

    scll.insertAtEnd(90);
    scll.insertAtEnd(95);
    // scll.printLL();
    // scll.insertAtPosition(100, 0);
    // scll.insertAtPosition(110, -100);
    // scll.insertAtPosition(120, 9);

    // scll.printLL(0);
    scll.insertAtPosition(110, 9);
    // scll.insertAtPosition(120, -100);
    // scll.printLL();
    // scll.deleteAtStart();
    // scll.deleteAtStart();
    // scll.deleteAtStart();
    scll.printLL();
    // scll.deleteAtEnd();
    // scll.deleteAtEnd();

    // scll.deleteAtPosition(0);
    // scll.deleteAtPosition(-100);
    // scll.deleteAtPosition(8);
    scll.deleteAtPosition(10);
    scll.printLL();
}