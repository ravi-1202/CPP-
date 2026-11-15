#include <iostream>
using namespace std;

void bubblesort(int n, float A[])
{
    for (int p = 1; p < n; p++)
    {
        int swapped = 0;
        for (int i = 0; i <= n - 1 - p; i++)
        {
            if (A[i] > A[i + 1])
            {
                float temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swapped = 1;
            }
        }

        cout << "Pass " << p << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << A[k] << " ";
        }
        cout << endl;

        if (swapped == 0)
        {
            break;
        }
    }
}

void topfive(int n, float A[])
{
    int count = 0;
    cout << "Top five scores: ";
    for (int i = n - 1; i >= 0 && count < 5; i--)
    {
        cout << A[i] << " ";
        count++;
    }
}

int main()
{
    float A[50];
    int n;

    cout << "Enter the total number of percentages: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the percentage of student " << i + 1 << ": ";
        cin >> A[i];
    }

    bubblesort(n, A);

    cout << "\nSorted (ascending) percentages: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    topfive(n, A);

    return 0;
}
