#include <iostream>
using namespace std;

struct node
{
    int PRN;
    char name[30];
    node *next;
};

class club
{
public:
    node *pres;
    node *secr;

    club()
    {
        pres = secr = NULL;
    }
    void create();
    void add();
    void compute();
    void display();
};

void club::create()
{
    int n;
    cout << "Enter total number of students (first = President, last = Secretary): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node *nn = new node;
        nn->next = NULL;
        cout << "Enter PRN of student: ";
        cin >> nn->PRN;
        cout << "Enter name of student: ";
        cin >> nn->name;
        if (pres == NULL)
        {
            pres = secr = nn;
        }
        else
        {
            secr->next = nn;
            secr = nn;
        }
    }
}

void club::add()
{
    int choice;
    cout << "\n1. President";
    cout << "\n2. Member";
    cout << "\n3. Secretary";
    cout << "\nEnter your choice: ";
    cin >> choice;

    node *nn = new node;
    nn->next = NULL;
    cout << "Enter PRN of student: ";
    cin >> nn->PRN;
    cout << "Enter name of student: ";
    cin >> nn->name;

    if (choice == 1)
    {
        nn->next = pres;
        pres = nn;
        if (secr == NULL)
            secr = nn;
        cout << "President added successfully";
    }
    else if (choice == 2)
    {
        if (pres == NULL)
        {
            cout << "List is empty. Add the president first";
            delete nn;
            return;
        }
        int key;
        cout << "Enter the PRN after which you want to add: ";
        cin >> key;
        node *temp = pres;
        while (temp != NULL && temp->PRN != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "PRN not found";
            delete nn;
        }
        else if (temp == secr)
        {
            cout << "Member cannot be added after the secretary (the secretary must stay last)";
            delete nn;
        }
        else
        {
            nn->next = temp->next;
            temp->next = nn;
            cout << "Member added successfully";
        }
    }
    else if (choice == 3)
    {
        if (pres == NULL)
        {
            pres = secr = nn;
        }
        else
        {
            secr->next = nn;
            secr = nn;
        }
        cout << "Secretary added successfully";
    }
    else
    {
        cout << "Invalid choice";
        delete nn;
    }
}

void club::compute()
{
    int count = 0;
    node *temp = pres;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Total number of members of the club: " << count;
}

void club::display()
{
    node *temp = pres;
    if (pres == NULL)
    {
        cout << "\nClub list is empty";
        return;
    }
    cout << "\nPRN\tName\tPost\n";
    while (temp != NULL)
    {
        cout << temp->PRN << "\t" << temp->name << "\t";
        if (temp == pres)
            cout << "President";
        else if (temp == secr)
            cout << "Secretary";
        else
            cout << "Member";
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    club c;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Create club list";
        cout << "\n2. Add president / member / secretary";
        cout << "\n3. Compute total members";
        cout << "\n4. Display members";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            c.create();
            c.display();
            break;
        case 2:
            c.add();
            c.display();
            break;
        case 3:
            c.compute();
            break;
        case 4:
            c.display();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
