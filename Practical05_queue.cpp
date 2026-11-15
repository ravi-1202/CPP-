#include <iostream>
using namespace std;

class JobQueue
{
public:
    int f, r, max;
    int Q[5];

    JobQueue()
    {
        f = 0;
        r = -1;
        max = 5;
    }
    int isEmpty();
    int isFull();
    void addJob();
    void deleteJob();
    void display();
};

int JobQueue::isEmpty()
{
    return f > r;
}

int JobQueue::isFull()
{
    return r == max - 1;
}

void JobQueue::addJob()
{
    int j;
    if (isFull())
    {
        cout << "Job queue is full";
        return;
    }
    cout << "Enter the job number: ";
    cin >> j;
    r++;
    Q[r] = j;
    cout << "Job " << j << " added";
}

void JobQueue::deleteJob()
{
    if (isEmpty())
    {
        cout << "Job queue is empty";
    }
    else
    {
        cout << "Job " << Q[f] << " deleted (processed)";
        f++;
    }
}

void JobQueue::display()
{
    if (isEmpty())
    {
        cout << "\nJob queue is empty";
    }
    else
    {
        cout << "\nJobs in queue (front to rear): ";
        for (int i = f; i <= r; i++)
        {
            cout << Q[i] << " ";
        }
    }
}

int main()
{
    JobQueue q;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Check if queue is empty";
        cout << "\n2. Check if queue is full";
        cout << "\n3. Add job";
        cout << "\n4. Delete job";
        cout << "\n5. Display";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (q.isEmpty())
                cout << "Queue is empty";
            else
                cout << "Queue is not empty";
            break;
        case 2:
            if (q.isFull())
                cout << "Queue is full";
            else
                cout << "Queue is not full";
            break;
        case 3:
            q.addJob();
            q.display();
            break;
        case 4:
            q.deleteJob();
            q.display();
            break;
        case 5:
            q.display();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
