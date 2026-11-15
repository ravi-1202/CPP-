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
    void compute();
    void display();
    void concatenate(club &c2);
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

void club::concatenate(club &c2)
{
    if (c2.pres == NULL)
    {
        cout << "Second list is empty, nothing to concatenate";
        return;
    }
    if (pres == NULL)
    {
        pres = c2.pres;
        secr = c2.secr;
    }
    else
    {
        secr->next = c2.pres;
        secr = c2.secr;
    }
    c2.pres = c2.secr = NULL;
    cout << "Lists concatenated successfully";
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
    club c1, c2;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Create list of division 1";
        cout << "\n2. Create list of division 2";
        cout << "\n3. Compute total members (division 1)";
        cout << "\n4. Display both lists";
        cout << "\n5. Concatenate division 2 after division 1";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            c1.create();
            break;
        case 2:
            c2.create();
            break;
        case 3:
            c1.compute();
            break;
        case 4:
            cout << "\n--- Division 1 ---";
            c1.display();
            cout << "\n--- Division 2 ---";
            c2.display();
            break;
        case 5:
            c1.concatenate(c2);
            c1.display();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
