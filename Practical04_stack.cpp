#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
    int top;
    int max;
    char st[100];

    Stack()
    {
        top = -1;
        max = 100;
    }
    int isEmpty();
    int isFull();
    void push(char c);
    char pop();
    void isWellParenthesized(string exp);
};

int Stack::isEmpty()
{
    return top == -1;
}

int Stack::isFull()
{
    return top == max - 1;
}

void Stack::push(char c)
{
    if (isFull())
    {
        cout << "Stack overflow";
    }
    else
    {
        top++;
        st[top] = c;
    }
}

char Stack::pop()
{
    if (isEmpty())
    {
        return '\0';
    }
    char c = st[top];
    top--;
    return c;
}

void Stack::isWellParenthesized(string exp)
{
    top = -1;

    for (int i = 0; i < (int)exp.size(); i++)
    {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (isEmpty())
            {
                cout << "Expression is NOT well parenthesized (extra closing '" << c << "')";
                return;
            }
            char t = pop();
            if ((t == '(' && c == ')') || (t == '{' && c == '}') || (t == '[' && c == ']'))
            {
                continue;
            }
            else
            {
                cout << "Expression is NOT well parenthesized (mismatch '" << t << "' and '" << c << "')";
                return;
            }
        }
    }

    if (isEmpty())
        cout << "Expression is well parenthesized";
    else
        cout << "Expression is NOT well parenthesized (unclosed '" << st[top] << "')";
}

int main()
{
    Stack s;
    int choice;
    char ch;
    string exp;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Check expression";
        cout << "\n2. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the expression (without spaces): ";
            cin >> exp;
            s.isWellParenthesized(exp);
            break;
        case 2:
            return 0;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
