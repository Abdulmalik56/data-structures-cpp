// Doubly linked list implementation in C++

#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    bool is_empty() { return head == nullptr; }

    void readNumbers(int size)
    {
        int num;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter a value " << i + 1 << " to insert: ";
            cin >> num;
            append(num);
        }
    }

    void append(int num)
    {
        Node *newNode = new Node(num);

        if (is_empty())
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void del(int value)
    {
        if (is_empty())
        {
            cout << "list is empty.\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "value not found!\n";
            return;
        }

        if (temp == head)
            head = head->next;

        if (temp == tail)
            tail = tail->prev;

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Value deleted successfully.\n";
    }

    void printForward()
    {
        if (is_empty())
        {
            cout << "list is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "List (Forward): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printBackward()
    {
        if (is_empty())
        {
            cout << "list is empty.\n";
            return;
        }

        Node *temp = tail;
        cout << "List (Backward): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void addBefore(int target, int newValue)
    {
        if (is_empty())
        {
            cout << "list is empty.\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != target)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Target value not found.\n";
            return;
        }

        Node *newNode = new Node(newValue);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != nullptr)
            temp->prev->next = newNode;
        else
            head = newNode;

        temp->prev = newNode;

        cout << "Value inserted successfully.\n";
    }

    int Count()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ~DoubleLinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    int choice, size, num, target;

    do
    {
        cout << "\n========= Doubly Linked List Operations =========\n";
        cout << "1. Read multiple values into list\n";
        cout << "2. Delete a value\n";
        cout << "3. Print list forward\n";
        cout << "4. Print list backward\n";
        cout << "5. Add a number before another number\n";
        cout << "6. Count nodes\n";
        cout << "-1. Exit Program\n";
        cout << "===============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of elements: ";
            cin >> size;
            list.readNumbers(size);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> num;
            list.del(num);
            break;
        case 3:
            list.printForward();
            break;
        case 4:
            list.printBackward();
            break;
        case 5:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> num;
            list.addBefore(target, num);
            break;
        case 6:
            cout << "Number of nodes: " << list.Count() << endl;
            break;
        case -1:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != -1);
}