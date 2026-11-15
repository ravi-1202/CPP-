#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

struct node
{
    string name;
    long long TeleNo;
    node *next;
};

class HashTable
{
public:
    node *T[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            T[i] = NULL;
        }
    }

    int hashFunction(string nm);
    void insert();
    void search();
    void display();
};

int HashTable::hashFunction(string nm)
{
    int total = 0;
    for (int i = 0; i < (int)nm.size(); i++)
    {
        total = total + nm[i];
    }
    return total % SIZE;
}

void HashTable::insert()
{
    node *nn = new node;
    cout << "Enter name of client: ";
    cin >> nn->name;
    cout << "Enter telephone number: ";
    cin >> nn->TeleNo;
    nn->next = NULL;

    int index = hashFunction(nn->name);

    if (T[index] == NULL)
    {
        T[index] = nn;
        cout << "Inserted at index " << index;
    }
    else
    {
        node *temp = T[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        cout << "Collision occurred. Added to the chain at index " << index;
    }
}

void HashTable::search()
{
    string nm;
    cout << "Enter name to search: ";
    cin >> nm;

    int index = hashFunction(nm);
    int comparisons = 0;
    node *temp = T[index];
    while (temp != NULL)
    {
        comparisons++;
        if (temp->name == nm)
        {
            cout << "Found at index " << index << "\nTelephone Number: " << temp->TeleNo;
            cout << "\nComparisons: " << comparisons;
            return;
        }
        temp = temp->next;
    }
    cout << "Client not found";
}

void HashTable::display()
{
    cout << "\nIndex\tChain\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";
        node *temp = T[i];
        if (temp == NULL)
            cout << "NULL";
        while (temp != NULL)
        {
            cout << "[" << temp->name << ", " << temp->TeleNo << "] -> ";
            temp = temp->next;
            if (temp == NULL)
                cout << "NULL";
        }
        cout << endl;
    }
}

int main()
{
    HashTable h;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Insert client";
        cout << "\n2. Search client";
        cout << "\n3. Display hash table";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.search();
            break;
        case 3:
            h.display();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
