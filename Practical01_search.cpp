#include <iostream>
#include <algorithm>
using namespace std;

void linsearch(int n, int A[])
{
    char ch;
    int key, i, comparison;
    do
    {
        int found = 0;
        comparison = 0;
        cout << "\nEnter the roll number we want to find: ";
        cin >> key;
        for (i = 0; i < n; i++)
        {
            comparison++;
            if (A[i] == key)
            {
                found = 1;
                cout << key << " is present (position " << i + 1 << ")";
                break;
            }
        }
        if (found == 0)
        {
            cout << key << " is absent";
        }
        cout << "\nNumber of comparisons in Linear Search: " << comparison;
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void binsearch(int n, int A[])
{
    char ch;
    int key, comparison;

    int B[50];
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
    sort(B, B + n);
    cout << "Sorted roll numbers: ";
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }

    do
    {
        int found = 0;
        comparison = 0;
        cout << "\nEnter the roll number to search: ";
        cin >> key;

        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            comparison++;
            if (B[mid] == key)
            {
                found = 1;
                cout << key << " is present (position " << mid + 1 << " in sorted list)";
                break;
            }
            else if (B[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (found == 0)
        {
            cout << key << " is absent";
        }
        cout << "\nNumber of comparisons in Binary Search: " << comparison;
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

int main()
{
    int n;
    int A[50];
    int choice;

    cout << "Enter the total number of roll numbers: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the roll number of present student: ";
        cin >> A[i];
    }
    cout << "Roll numbers (random order): ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Linear search";
        cout << "\n2. Binary search";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            linsearch(n, A);
        }
        else if (choice == 2)
        {
            binsearch(n, A);
        }
        else if (choice == 3)
        {
            cout << "Program is finished";
        }
        else
        {
            cout << "Unavailable choice";
        }
    } while (choice != 3);

    return 0;
}
