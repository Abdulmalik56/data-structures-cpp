// Stack implementation using array in C++

#include <iostream>
using namespace std;

const int MAX = 10;

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool is_full()
    {
        return top == MAX - 1;
    }

    bool is_empty()
    {
        return top == -1;
    }

    void push(int n)
    {
        if (is_full())
        {
            cout << "Stack is full.\n";
            return;
        }
        top++;
        arr[top] = n;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack is Empty.\n";
            return -1;
        }
        int data = arr[top];
        top--;
        return data;
    }

    void topelement()
    {
        if (is_empty())
        {
            cout << "Stack is Empty.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Stack is Empty.\n";
            return;
        }

        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, num;

    do
    {
        cout << "\n========= Stack Using Array =========\n";
        cout << "1. Push a number into stack\n";
        cout << "2. Pop top element\n";
        cout << "3. Display the top element\n";
        cout << "4. Display stack size\n";
        cout << "5. Display all elements\n";
        cout << "-1. Exit Program\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to push: ";
            cin >> num;
            s.push(num);
            break;
        case 2:
            num = s.pop();
            if (num != -1)
                cout << "Popped numer: " << num << endl;
            break;
        case 3:
            s.topelement();
            break;
        case 4:
            cout << "Stack size is: " << s.size() << endl;
            break;
        case 5:
            s.display();
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