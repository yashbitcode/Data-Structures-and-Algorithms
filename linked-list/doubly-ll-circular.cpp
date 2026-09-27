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

class DoublyCircularLL
{
public:
    Node *head = nullptr;

    DoublyCircularLL(Node *head = nullptr)
    {
        this->head = head;

        if (this->head)
            this->head->next = this->head->prev = head;
    };

    void printLL(int circularCnt = 0, bool withAddress = false, bool withBackward = false)
    {
        Node *temp = this->head;
        int cirCnt = circularCnt;

        if (!temp)
            return;

        do
        {
            cout << "[";

            if (withAddress)
                cout << temp->prev << " : ";

            cout << temp->data;

            if (withAddress)
                cout << " : " << temp->next;

            cout << "]";

            temp = temp->next;

            if (temp != head || cirCnt)
                cout << " <-> ";
        } while (temp != head || cirCnt--);

        temp = this->head->prev;

        if (withBackward)
        {
            cout << endl
                 << "-----------------------------------" << endl;

            cirCnt = circularCnt;

            do
            {
                cout << "[";

                if (withAddress)
                    cout << temp->prev << " : ";

                cout << temp->data;

                if (withAddress)
                    cout << " : " << temp->next;

                cout << "]";

                temp = temp->prev;

                if (temp != this->head->prev || cirCnt)
                    cout << " <-> ";
            } while (temp != this->head->prev || cirCnt--);
        }

        cout << endl
             << endl;
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

        Node *tempPrev = temp->prev;
        tempPrev->next = newNode;

        temp->prev = newNode;
        newNode->prev = tempPrev;

        newNode->next = temp;
    }

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);

        if (!this->head)
        {
            this->head = newNode;
            this->head->next = this->head->prev = newNode;
            return;
        }

        Node *headPrev = this->head->prev;

        newNode->next = this->head;
        this->head->prev = newNode;

        headPrev->next = newNode;
        newNode->prev = headPrev;

        this->head = newNode;
    }

    void insertAtEnd(int data)
    {
        if (!this->head)
            return this->insertAtStart(data);

        Node *newNode = new Node(data);
        Node *end = this->head->prev;

        newNode->prev = end;
        newNode->next = this->head;
        end->next = this->head->prev = newNode;
    }

    void deleteAtStart()
    {
        if (!this->head)
            return;

        Node *headPrev = this->head->prev;
        Node *headNext = this->head->next;

        bool isSame = this->head == headPrev;

        this->head->next = this->head->prev = nullptr;

        delete this->head;

        if (isSame)
        {
            this->head = nullptr;
            return;
        }

        headNext->prev = headPrev;
        headPrev->next = headNext;

        this->head = headNext;
    }

    void deleteAtEnd()
    {
        if (!head)
            return;

        Node *headP = head->prev;
        Node *headPP = head->prev->prev;

        bool isSame = head == headP;

        if(isSame) return this->deleteAtStart();

        headP->next = headP->prev = nullptr;

        headPP->next = head;
        head->prev = headPP;

        delete headP;
    }

    void deleteAtPosition(int position)
    {
        if(position <= 0) return this->deleteAtStart();

        Node* temp = head;
        int cnt = 0;

        while(cnt < position && temp) {
            cnt++;
            temp = temp->next;
        }

        if(temp == head) return this->deleteAtStart();

        Node* tempNext = temp->next;
        Node* tempPrev = temp->prev;

        temp->next = temp->prev = nullptr;
        delete temp;

        tempNext->prev = tempPrev;
        tempPrev->next = tempNext;
    }
};

int main()
{
    DoublyCircularLL dcll(new Node(10));
    // dcll.printLL();

    dcll.insertAtStart(12);
    dcll.insertAtStart(15);
    dcll.insertAtStart(20);

    dcll.insertAtEnd(21);
    dcll.insertAtEnd(22);
    dcll.insertAtEnd(23);

    // dcll.printLL(0, false, true);
    // dcll.printLL(0, false, true);
    // dcll.insertAtPosition(30, 0);
    // dcll.insertAtPosition(31, -100);

    //  dcll.printLL(0, false, true);
    dcll.insertAtPosition(31, 8);

    // dcll.printLL(0, false, true);
    // dcll.deleteAtStart();
    // dcll.deleteAtStart();
    // dcll.printLL(0, false, true);
    dcll.deleteAtEnd();
    dcll.deleteAtEnd();
    dcll.printLL(0, false, true);
    // dcll.deleteAtPosition(7);
    // dcll.deleteAtPosition(-100);
    dcll.printLL(0, false, true);
}