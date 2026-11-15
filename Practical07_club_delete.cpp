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
    void delet();
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

void club::delet()
{
    if (pres == NULL)
    {
        cout << "Club list is empty";
        return;
    }

    int choice;
    cout << "\n1. President";
    cout << "\n2. Member";
    cout << "\n3. Secretary";
    cout << "\nEnter your choice: ";
    cin >> choice;

    node *temp, *temp1;
    if (choice == 1)
    {
        temp = pres;
        pres = pres->next;
        if (pres == NULL)
            secr = NULL;
        delete temp;
        cout << "President deleted successfully";
    }
    else if (choice == 2)
    {
        int key;
        cout << "Enter the PRN of the member to delete: ";
        cin >> key;

        if (pres->PRN == key)
        {
            cout << "This is the president. Use option 1 to delete";
            return;
        }
        temp = pres;
        while (temp->next != NULL && temp->next->PRN != key)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "PRN not found";
        }
        else if (temp->next == secr)
        {
            cout << "This is the secretary. Use option 3 to delete";
        }
        else
        {
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            cout << "Member deleted successfully";
        }
    }
    else if (choice == 3)
    {
        if (pres == secr)
        {
            delete pres;
            pres = secr = NULL;
        }
        else
        {
            temp = pres;
            while (temp->next != secr)
            {
                temp = temp->next;
            }
            temp1 = secr;
            temp->next = NULL;
            secr = temp;
            delete temp1;
        }
        cout << "Secretary deleted successfully";
    }
    else
    {
        cout << "Invalid choice";
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
        cout << "\n2. Delete president / member / secretary";
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
            c.delet();
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
