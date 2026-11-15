#include <iostream>
using namespace std;

void selectionsort(int n, float A[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        float temp = A[i];
        A[i] = A[min];
        A[min] = temp;

        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << A[k] << " ";
        }
        cout << endl;
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

    selectionsort(n, A);

    cout << "\nSorted (ascending) percentages: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    topfive(n, A);

    return 0;
}
