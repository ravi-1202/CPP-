#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int val)
{
    Node *nn = new Node();
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return createNewNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        cout << "Duplicate value, not inserted\n";
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int findmin(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

void mirror(Node *root)
{
    if (root == NULL)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main()
{
    Node *root = NULL;
    int n, val, ch;

    cout << "Enter number of values to construct the BST: ";
    cin >> n;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }
    cout << "BST constructed. Inorder: ";
    inorder(root);

    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Insert new node";
        cout << "\n2. Find minimum value";
        cout << "\n3. Mirror the tree (swap left and right)";
        cout << "\n4. Display (inorder and preorder)";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            cout << "Inorder: ";
            inorder(root);
            break;
        case 2:
            if (root == NULL)
                cout << "Tree is empty";
            else
                cout << "Minimum value = " << findmin(root);
            break;
        case 3:
            mirror(root);
            cout << "Tree mirrored";
            break;
        case 4:
            cout << "Inorder  : ";
            inorder(root);
            cout << "\nPreorder : ";
            preorder(root);
            break;
        case 0:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (ch != 0);

    return 0;
}
