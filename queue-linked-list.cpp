// Queue implementation using linked list in C++

#include <iostream>
using namespace std;

class Queue
{
private:
    struct node
    {
        int data;
        node *link;

        node(int value) : data(value), link(NULL) {}
    };

    node *front, *rear;
    int count;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    bool is_empty()
    {
        return front == NULL;
    }

    void enqueue(int value)
    {
        node *newNode = new node(value);

        if (is_empty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->link = newNode;
            rear = newNode;
        }
        count++;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        node *temp = front;
        int data = temp->data;
        front = front->link;

        if (is_empty())
        {
            rear = NULL;
        }

        delete temp;
        count--;
        return data;
    }

    void frontelment()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    void rearelment()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "rear element: " << rear->data << endl;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, num;

    do
    {
        cout << "\n========= Queue Using Linked List =========\n";
        cout << "1. Enqueue (add value to queue)\n";
        cout << "2. Dequeue (remove front value)\n";
        cout << "3. Show front value\n";
        cout << "4. Show rear value\n";
        cout << "5. Show the size\n";
        cout << "6. Display queue elements\n";
        cout << "-1. Exit Program\n";
        cout << "==========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> num;
            q.enqueue(num);
            break;
        case 2:
            num = q.dequeue();
            if (num != -1)
                cout << "Dequeue value: " << num << endl;
            break;
        case 3:
            q.frontelment();
            break;
        case 4:
            q.rearelment();
            break;
        case 5:
            cout << "queue size : " << q.size() << endl;
            break;
        case 6:
            q.display();
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