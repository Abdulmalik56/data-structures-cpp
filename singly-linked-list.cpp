// Singly linked list implementation in C++

// Singly linked list implementation in C++

#include <iostream>
using namespace std;

class linkList
{
private:
    struct Node
    {
        int data;
        Node *link;

        Node(int num) : data(num), link(NULL) {}
    };
    Node *head;

public:
    linkList() : head(NULL)
    {
        head = NULL;
    }

    bool is_empty()
    {
        return head == NULL;
    }

    void append(int num)
    {
        Node *newNode = new Node(num);

        if (is_empty())
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }

    void prepend(int num)
    {
        Node *newNode = new Node(num);
        newNode->link = head;
        head = newNode;
    }

    void after(int loc, int num)
    {
        if (is_empty())
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        while (temp != NULL && temp->data != loc)
        {
            temp = temp->link;
        }

        if (temp == NULL)
        {
            cout << "Value not found.\n";
            return;
        }

        Node *newNode = new Node(num);
        newNode->link = temp->link;
        temp->link = newNode;
    }

    void del(int num)
    {
        if (is_empty())
        {
            cout << "List is empty.\n";
            return;
        }

        Node *old, *temp = head;
        while (temp != NULL)
        {
            if (temp->data == num)
            {
                if (temp == head)
                {
                    head = head->link;
                }
                else
                {
                    old->link = temp->link;
                }

                delete temp;
                cout << "Element " << num << " is deleted" << endl;
                return;
            }
            else
            {
                old = temp;
                temp = temp->link;
            }
        }
        cout << "Element " << num << " not found" << endl;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "List elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
    int count()
    {
        int counrter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            counrter++;
            temp = temp->link;
        }
        return counrter;
    }

    void search(int num)
    {
        if (is_empty())
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->data == num)
            {
                cout << "Value found at position: " << pos << endl;
                return;
            }
            temp = temp->link;
            pos++;
        }

        cout << "Value not found.\n";
    }
};

int main()
{
    linkList list;
    int choice, num, loc;

    do
    {
        cout << "\n========= Linked List Operations =========\n";
        cout << "1. Insert at end (append)\n";
        cout << "2. Insert at beginning (prepend)\n";
        cout << "3. Insert after a specific value\n";
        cout << "4. Delete a value\n";
        cout << "5. Display list\n";
        cout << "6. Count number of nodes\n";
        cout << "7. Search for value\n";
        cout << "-1. Exit Program\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> num;
            list.append(num);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> num;
            list.prepend(num);
            break;
        case 3:
            cout << "Enter value after which to insert: ";
            cin >> loc;
            cout << "Enter number: ";
            cin >> num;
            list.after(loc, num);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> num;
            list.del(num);
            break;
        case 5:
            list.display();
            break;
        case 6:
            cout << "Number of elemnts: " << list.count() << endl;
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> num;
            list.search(num);
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