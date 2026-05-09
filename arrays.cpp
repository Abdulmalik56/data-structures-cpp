// Array implementation and operations in C++

#include <iostream>
using namespace std;

const int MAX = 10;

class Array
{
private:
    int arr[MAX];
    int count;

public:
    Array()
    {
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

    void insert(int num)
    {
        if (is_full())
        {
            cout << "Array is full, cannot insert. \n";
            return;
        }

        arr[count] = num;
        count++;
    }

    void del(int pos)
    {
        if (is_empty())
        {
            cout << "Array is empty. Cannot delete. \n";
            return;
        }

        if (pos < 0 || pos >= count)
        {
            cout << "Invalid position.\n";
            return;
        }

        for (int i = pos; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void reverse()
    {
        if (is_empty())
        {
            cout << "Array is empty.\n";
            return;
        }
        int temp;
        for (int i = 0; i < count / 2; i++)
        {
            temp = arr[i];
            arr[i] = arr[count - 1 - i];
            arr[count - 1 - i] = temp;
        }
    }

    void sort()
    {
        if (is_empty())
        {
            cout << "Array is empty.\n";
            return;
        }

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Array is empty.\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void search(int num)
    {
        if (is_empty())
        {
            cout << "Array is empty.\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            if (arr[i] == num)
            {
                cout << "Number is found at index:" << i << endl;
                return;
            }
        }

        cout << "Number is not found. " << endl;
    }
};

int main()
{
    Array obj;
    int choice, num, pos;

    do
    {
        cout << "\n========= Array Operations =========\n";
        cout << "1. Insert a number\n";
        cout << "2. Delete a number from a specific position\n";
        cout << "3. Reverse the array\n";
        cout << "4. Display all elements\n";
        cout << "5. Search for a number\n";
        cout << "6. Sort array\n";
        cout << "-1. Exit Program\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to insert: ";
            cin >> num;
            obj.insert(num);
            break;
        case 2:
            cout << "Enter position to delete: ";
            cin >> pos;
            obj.del(pos);
            break;
        case 3:
            obj.reverse();
            break;
        case 4:
            obj.display();
            break;
        case 5:
            cout << "Enter number to search: ";
            cin >> num;
            obj.search(num);
            break;
        case 6:
            obj.sort();
            cout << "Array sorted successfully.\n";
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