// Circular queue implementation using array in C++

#include <iostream>
using namespace std;

const int MAX = 10;

class Queue
{
private:
    int arr[MAX];
    int front, rear, count, nextValue;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        count = 0;
        nextValue = 2;
    }

    bool is_full()
    {
        return count == MAX;
    }

    bool is_empty()
    {
        return count == 0;
    }

    void enqueue(int size)
    {
        if (size <= 0)
        {
            cout << "Invalid size.\n";
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (is_full())
            {
                cout << "Queue is full.\n";
                return;
            }
            rear = (rear + 1) % MAX;
            arr[rear] = nextValue;
            nextValue += 2;
            count++;
        }
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        int data = arr[front];
        front = (front + 1) % MAX;
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
        cout << "Front Element: " << arr[front] << endl;
    }

    void rearElement()
    {
        if (is_empty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Rear Element: " << arr[rear] << endl;
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

        cout << "Queue Elements: ";
        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, num, size;

    do
    {
        cout << "\n========= Queue Using Array =========\n";
        cout << "1. Enqueue (a sequence of even numbers)\n";
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
            cout << "Enter size of even number to insert: ";
            cin >> size;
            q.enqueue(size);
            break;
        case 2:
            num = q.dequeue();
            if (num != -1)
                cout << "Dequeue Value: " << num << endl;
            break;
        case 3:
            q.frontElement();
            break;
        case 4:
            q.rearElement();
            break;
        case 5:
            cout << "Queue size: " << q.size() << endl;
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