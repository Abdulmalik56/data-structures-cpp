// Queue implementation using array in C++

#include <iostream>
using namespace std;

const int MAX = 10;

class Queue
{
private:
    int arr[MAX];
    int front, rear, count;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool is_full()
    {
        return count == MAX;
    }

    bool is_empty()
    {
        return count == 0;
    }

    void enqueue(int value)
    {
        if (is_full())
        {
            cout << "Queueu is full.\n";
            return;
        }
        rear++;
        arr[rear] = value;
        count++;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        int data = arr[front];

        for (int i = 0; i < count; i++)
        {
            arr[i] = arr[i + 1];
        }
        rear--;
        count--;
        return data;
    }

    void frontElement()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void rearElement()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "rear element: " << arr[rear] << endl;
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
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
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
        cout << "\n========= Queue Using Array =========\n";
        cout << "1. Enqueue (add value to queue)\n";
        cout << "2. Dequeue (remove front value)\n";
        cout << "3. Show front value\n";
        cout << "4. Show rear value\n";
        cout << "5. Show the size\n";
        cout << "6. Display queue elements\n";
        cout << "-1. Exit Program\n";
        cout << "====================================\n";
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
            q.frontElement();
            break;
        case 4:
            q.rearElement();
            break;
        case 5:
            cout << "Queue Size is: " << q.size() << endl;
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