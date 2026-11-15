#include <iostream>
using namespace std;

struct Node
{
    int bit;
    Node *prev;
    Node *next;
};

class binary
{
public:
    Node *msb;
    Node *lsb;

    binary()
    {
        msb = lsb = NULL;
    }

    void insertEnd(int b);
    void insertFront(int b);
    void storebin();
    void display();
    void add(binary &b2, binary &res);
};

void binary::insertEnd(int b)
{
    Node *nn = new Node;
    nn->bit = b;
    nn->prev = NULL;
    nn->next = NULL;

    if (msb == NULL)
    {
        msb = lsb = nn;
    }
    else
    {
        lsb->next = nn;
        nn->prev = lsb;
        lsb = nn;
    }
}

void binary::insertFront(int b)
{
    Node *nn = new Node;
    nn->bit = b;
    nn->prev = NULL;
    nn->next = NULL;

    if (msb == NULL)
    {
        msb = lsb = nn;
    }
    else
    {
        nn->next = msb;
        msb->prev = nn;
        msb = nn;
    }
}

void binary::storebin()
{
    int n, b;
    cout << "Enter total number of bits: ";
    cin >> n;

    cout << "Enter the bits (MSB first): ";
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        while (b != 0 && b != 1)
        {
            cout << "Bit must be 0 or 1. Enter again: ";
            cin >> b;
        }
        insertEnd(b);
    }
}

void binary::display()
{
    Node *temp = msb;
    while (temp != NULL)
    {
        cout << temp->bit;
        temp = temp->next;
    }
}

void binary::add(binary &b2, binary &res)
{
    Node *t1 = lsb;
    Node *t2 = b2.lsb;
    int carry = 0, sum;

    while (t1 != NULL || t2 != NULL)
    {
        sum = carry;

        if (t1 != NULL)
        {
            sum = sum + t1->bit;
            t1 = t1->prev;
        }
        if (t2 != NULL)
        {
            sum = sum + t2->bit;
            t2 = t2->prev;
        }

        res.insertFront(sum % 2);
        carry = sum / 2;
    }

    if (carry == 1)
    {
        res.insertFront(1);
    }
}

int main()
{
    binary b1, b2, res;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Enter two binary numbers";
        cout << "\n2. Add the two binary numbers";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b1 = binary();
            b2 = binary();
            res = binary();
            cout << "\nFirst binary number:\n";
            b1.storebin();
            cout << "\nSecond binary number:\n";
            b2.storebin();
            cout << "\nFirst  number: ";
            b1.display();
            cout << "\nSecond number: ";
            b2.display();
            break;
        case 2:
            res = binary();
            b1.add(b2, res);
            cout << "Addition result: ";
            res.display();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
