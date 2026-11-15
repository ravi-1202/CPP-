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
    void onescomp(binary &r);
    void twoscomp(binary &r);
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

void binary::onescomp(binary &r)
{
    Node *temp = msb;
    while (temp != NULL)
    {
        if (temp->bit == 1)
            r.insertEnd(0);
        else
            r.insertEnd(1);
        temp = temp->next;
    }
}

void binary::twoscomp(binary &r)
{
    onescomp(r);

    Node *temp = r.lsb;
    int carry = 1;
    while (temp != NULL && carry == 1)
    {
        if (temp->bit == 1)
        {
            temp->bit = 0;
        }
        else
        {
            temp->bit = 1;
            carry = 0;
        }
        temp = temp->prev;
    }
}

int main()
{
    binary b, ones, twos;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Enter a binary number";
        cout << "\n2. Display 1's complement";
        cout << "\n3. Display 2's complement";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b = binary();
            ones = binary();
            twos = binary();
            b.storebin();
            cout << "Binary number: ";
            b.display();
            break;
        case 2:
            ones = binary();
            b.onescomp(ones);
            cout << "Binary number   : ";
            b.display();
            cout << "\n1's complement  : ";
            ones.display();
            break;
        case 3:
            twos = binary();
            b.twoscomp(twos);
            cout << "Binary number   : ";
            b.display();
            cout << "\n2's complement  : ";
            twos.display();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
