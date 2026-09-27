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

class DoublyLL
{
public:
    Node *head;

    DoublyLL(Node *head = nullptr)
    {
        this->head = head;
    };

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);

        if (!this->head)
        {
            this->head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head->prev = newNode;

        this->head = newNode;
    }

    void insertAtEnd(int data) {
         Node *newNode = new Node(data);

        if (!this->head)
        {
            this->head = newNode;
            return;
        }

        Node* temp = this->head;

        while(temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int data, int position) {
        if(position <= 0 ) return this->insertAtStart(data);

        Node* temp = this->head;
        int cnt = 0;

        while(cnt < position && temp) {
            temp = temp->next;
            cnt++;
        }

        if(!temp) return this->insertAtEnd(data);

        Node* newNode = new Node(data);
        Node* prev = temp->prev;

        temp->prev = newNode;
        newNode->next = temp;

        newNode->prev = prev;
        prev->next = newNode;
    }

    void deleteAtStart() {
        if(!this->head) return;

        Node* next = this->head->next;
        this->head->next = nullptr;

        delete this->head;

        this->head = next;

        if(this->head) this->head->prev = nullptr;
    }

    void deleteAtEnd() {
        if(!this->head || !this->head->next) return this->deleteAtStart();

        Node* temp = this->head;

        while(temp->next) {
            temp = temp->next;
        }

        Node* prev = temp->prev;

        prev->next = nullptr;
        temp->prev = nullptr;
        temp->next = nullptr;

        delete temp;
    }

    void deleteAtPosition(int position) {
        if(position <= 0) return this->deleteAtStart();

        int cnt = 0;
        Node* temp = this->head;

        while(cnt < position && temp) {
            temp = temp->next;
            cnt++;
        }

        if(!temp) return this->deleteAtEnd();

        Node* prev = temp->prev;
        Node* next = temp->next;

        temp->next = temp->prev = nullptr;
        delete temp;

        prev->next = next;

        if(next) next->prev = prev;
    }

    void printLL(bool withAddress = false, bool withBackward = false)
    {
        Node *temp = this->head;
        Node *prev = nullptr;

        cout << endl << "-------------------" << endl;
        cout << "FORWARD: " << endl;

        while (temp)
        {
            cout << "[";

            if (withAddress)
                cout << temp << " : ";

            cout << temp->data << "]";

            prev = temp;
            temp = temp->next;

            if (temp)
                cout << " <--> ";
        }
       
        if (withBackward && prev)
        {
            cout << endl << endl << "BACKWARD" << endl;

            while (prev)
            {
                cout << "[";

                if (withAddress)
                    cout << prev << " : ";

                cout << prev->data << "]";

                prev = prev->prev;

                if (prev)
                    cout << " <--> ";
            }
        }
        
        cout << endl << "-------------------" << endl;

        cout << endl;
    }
};

int main()
{
    Node *head = new Node(10);

    DoublyLL dll(head);

    // dll.printLL(true, true);
    
    dll.insertAtStart(20);
    // dll.printLL(false, true);
    
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    // dll.printLL(false, true);

    dll.insertAtPosition(100, 0);
    dll.insertAtPosition(90, -100);
    dll.insertAtPosition(80, 5);
    dll.insertAtPosition(70, 50);
    dll.insertAtPosition(60, 4);

    dll.deleteAtStart();
    dll.deleteAtStart();

    dll.deleteAtEnd();

    dll.deleteAtPosition(0);
    // dll.deleteAtPosition(-100);

    dll.deleteAtPosition(4);
    dll.deleteAtPosition(40);
    dll.deleteAtPosition(1);
    dll.printLL(false, true);
}