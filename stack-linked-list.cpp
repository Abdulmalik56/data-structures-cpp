// Stack implementation using linked list in C++

#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node *link;

        Node(int value) : data(value), link(NULL) {}
    } *top;
    int count;

public:
    Stack()
    {
        top = NULL;
        count = 0;
    }

    bool is_empty()
    {
        return top == NULL;
    }

    void push(int num)
    {
        if (num % 2 != 0)
            num = num + 1;

        Node *newNode = new Node(num);
        newNode->link = top;
        top = newNode;
        count++;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        Node *temp = top;
        int data = temp->data;
        top = top->link;
        delete temp;
        count--;
        return data;
    }

    void topelement()
    {
        if (is_empty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        Node *temp = top;
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
    Stack s;
    int choice, num;

    do
    {
        cout << "\n========= Stack Using Linked List =========\n";
        cout << "1. Push a number into stack\n";
        cout << "2. Pop top element\n";
        cout << "3. Display the top element\n";
        cout << "4. Display stack size\n";
        cout << "5. Display all elements\n";
        cout << "-1. Exit Program\n";
        cout << "===========================================\n";
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
                cout << "Popped value: " << num << endl;
            break;
        case 3:
            s.topelement();
            break;
        case 4:
            cout << "Stack Size: " << s.size() << endl;
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