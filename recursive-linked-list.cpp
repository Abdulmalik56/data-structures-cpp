// Recursive linked list implementation in C++

#include <iostream>
using namespace std;

class LinkedList
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
    LinkedList() : head(NULL) {}

    bool is_empty()
    {
        return head == NULL;
    }

    void insert(int num)
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

    int count(Node *temp)
    {
        int c;
        if (temp == NULL)
            return 0;

        c = 1 + count(temp->link);
        return c;
    }

    int countMain()
    {
        return count(head);
    }

    bool compare(Node *l1, Node *l2)
    {
        if (l1 == NULL && l2 == NULL)
            return true;
        if (l1 == NULL || l2 == NULL)
            return false;
        if (l1->data != l2->data)
            return false;
        return compare(l1->link, l2->link);
    }

    bool CompareMain(LinkedList &obj)
    {
        return compare(head, obj.head);
    }

    void copy(Node *l1, Node **l2)
    {
        if (l1 == NULL)
        {
            *l2 = NULL;
            return;
        }
        *l2 = new Node(l1->data);
        copy(l1->link, &((*l2)->link));
    }

    void copyMain(LinkedList &source, LinkedList &destination)
    {
        if (destination.head != NULL)
            destination.head = NULL;

        copy(source.head, &(destination.head));
    }

    void display_recursive(Node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        display_recursive(temp->link);
    }

    void displayMain()
    {
        if (is_empty())
        {
            cout << "List is empty\n";
            return;
        }
        display_recursive(head);
        cout << endl;
    }
};

int main()
{
    LinkedList l1, l2, l3;
    int choice, num, n;

    do
    {
        cout << "\n========= Recursive Linked List Operations =========\n";
        cout << "1. Insert a number into List 1\n";
        cout << "2. Insert a number into List 2\n";
        cout << "3. Count nodes in a list\n";
        cout << "4. Compare List 1 and List 2\n";
        cout << "5. Copy a list into List 3\n";
        cout << "6. Display List (1 / 2 / 3)\n";
        cout << "-1. Exit Program\n";
        cout << "===============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to insert in list 1: ";
            cin >> num;
            l1.insert(num);
            break;
        case 2:
            cout << "Enter number to insert in list 2: ";
            cin >> num;
            l2.insert(num);
            break;
        case 3:
            cout << "Which list do you want to count? (1/2/3): ";
            cin >> n;
            switch (n)
            {
            case 1:
                cout << "Count list 1 is: " << l1.countMain() << endl;
                break;
            case 2:
                cout << "Count list 2 is: " << l2.countMain() << endl;
                break;
            case 3:
                cout << "Count list 3 is: " << l3.countMain() << endl;
                break;
            default:
                cout << "Invalid list number\n";
                break;
            }

            break;
        case 4:
            if (l1.CompareMain(l2))
                cout << "The two lists are equal.\n";
            else
                cout << "The two lists are not equal.\n";
            break;
        case 5:
            cout << "Which list do you want to copy? (1/2): ";
            cin >> n;
            if (n == 1)
                l3.copyMain(l1, l3);
            else if (n == 2)
                l3.copyMain(l2, l3);
            else
                cout << "Invalid list number\n";

            break;
        case 6:
            cout << "Which list do you want to Display? (1/2/3): ";
            cin >> n;
            switch (n)
            {
            case 1:
                l1.displayMain();
                break;
            case 2:
                l2.displayMain();
                break;
            case 3:
                l3.displayMain();
                break;
            default:
                cout << "Invalid list number\n";
                break;
            }
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