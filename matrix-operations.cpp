// Two-dimensional array (matrix) operations in C++

#include <iostream>
using namespace std;

const int MAX = 3;

class Matrix
{
private:
    int mat[MAX][MAX];

public:
    Matrix()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    void create()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    void display()
    {
        cout << "Matrix Elemntes: \n";
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void mat_add(Matrix &m1, Matrix &m2)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
            }
        }
    }

    void mat_mul(Matrix &m1, Matrix &m2)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                mat[i][j] = 0;
                for (int k = 0; k < MAX; k++)
                {
                    mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
                }
            }
        }
    }

    void transpose(Matrix &m1)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                mat[i][j] = m1.mat[j][i];
            }
        }
    }

    int sum()
    {
        int total = 0;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                total += mat[i][j];
            }
        }
        return total;
    }
};

int main()
{
    Matrix m1, m2, result;
    int choice;

    do
    {
        cout << "\n========= Matrix Operations =========\n";
        cout << "1. Create matrix\n";
        cout << "2. Display matrix\n";
        cout << "3. Add two matrices\n";
        cout << "4. Multiply two matrices\n";
        cout << "5. Transpose matrix\n";
        cout << "6. Sum of all elements\n";
        cout << "-1. Exit program\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Values for Matrix 1:\n";
            m1.create();
            cout << "\nValues for Matrix 2:\n";
            m2.create();
            break;
        case 2:
            cout << "Matrix 1: " << endl;
            m1.display();
            cout << "Matrix 2: " << endl;
            m2.display();
            break;
        case 3:
            result.mat_add(m1, m2);
            cout << "Result of Matrix Addition:\n";
            result.display();
            break;
        case 4:
            result.mat_mul(m1, m2);
            cout << "Result of Matrix Multiplication:\n";
            result.display();
            break;
        case 5:
            result.transpose(m1);
            cout << "Transpose of Matrix 1:\n";
            result.display();
            break;
        case 6:
            cout << "Sum of Matrix 1: " << m1.sum() << endl;
            cout << "Sum of Matrix 2: " << m2.sum() << endl;
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