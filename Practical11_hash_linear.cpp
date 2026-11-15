#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

struct record
{
    string name;
    long long TeleNo;
    int used;
};

class HashTable
{
public:
    record T[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            T[i].used = 0;
            T[i].TeleNo = 0;
        }
    }

    int hashFunction(string nm);
    int probe(int index, int i);
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

int HashTable::probe(int index, int i)
{
    return (index + i) % SIZE;
}

void HashTable::insert()
{
    string nm;
    long long telno;

    cout << "Enter name of client: ";
    cin >> nm;
    cout << "Enter telephone number: ";
    cin >> telno;

    int index = hashFunction(nm);
    for (int i = 0; i < SIZE; i++)
    {
        int pos = probe(index, i);
        if (T[pos].used == 0)
        {
            T[pos].name = nm;
            T[pos].TeleNo = telno;
            T[pos].used = 1;
            if (i == 0)
                cout << "Inserted at index " << pos << " (no collision)";
            else
                cout << "Collision occurred. Inserted at index " << pos << " after " << i << " probe(s)";
            return;
        }
    }
    cout << "Could not insert: no free slot found (table full)";
}

void HashTable::search()
{
    string nm;
    cout << "Enter name to search: ";
    cin >> nm;

    int index = hashFunction(nm);
    int comparisons = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int pos = probe(index, i);
        if (T[pos].used == 0)
        {
            break;
        }
        comparisons++;
        if (T[pos].name == nm)
        {
            cout << "Found at index " << pos << "\nTelephone Number: " << T[pos].TeleNo;
            cout << "\nComparisons: " << comparisons;
            return;
        }
    }
    cout << "Client not found";
}

void HashTable::display()
{
    cout << "\nIndex\tName\tTelephone No\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";
        if (T[i].used == 1)
            cout << T[i].name << "\t" << T[i].TeleNo;
        else
            cout << "---";
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
