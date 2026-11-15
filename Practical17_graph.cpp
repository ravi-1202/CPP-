#include <iostream>
#include <string>
using namespace std;

#define MAX 20

class Graph
{
public:
    int n;
    string city[MAX];
    int cost[MAX][MAX];
    int visited[MAX];

    Graph()
    {
        n = 0;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cost[i][j] = 0;
            }
        }
    }

    int findCity(string nm);
    void addCity();
    void addFlight();
    void displayMatrix();
    void dfs(int v);
    void isConnected();
};

int Graph::findCity(string nm)
{
    for (int i = 0; i < n; i++)
    {
        if (city[i] == nm)
            return i;
    }
    return -1;
}

void Graph::addCity()
{
    if (n == MAX)
    {
        cout << "Maximum cities reached";
        return;
    }
    cout << "Enter name of the city / airport: ";
    cin >> city[n];
    n++;
    cout << "City added";
}

void Graph::addFlight()
{
    string a, b;
    int c;
    cout << "Enter source city: ";
    cin >> a;
    cout << "Enter destination city: ";
    cin >> b;
    int u = findCity(a), v = findCity(b);
    if (u == -1 || v == -1)
    {
        cout << "City not found. Add the city first";
        return;
    }
    cout << "Enter cost (flight time in minutes / fuel): ";
    cin >> c;
    cost[u][v] = c;
    cost[v][u] = c;
    cout << "Flight added between " << a << " and " << b;
}

void Graph::displayMatrix()
{
    if (n == 0)
    {
        cout << "Graph is empty";
        return;
    }
    cout << "\nAdjacency matrix:\n\t";
    for (int i = 0; i < n; i++)
    {
        cout << city[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}

void Graph::dfs(int v)
{
    visited[v] = 1;
    for (int j = 0; j < n; j++)
    {
        if (cost[v][j] != 0 && visited[j] == 0)
        {
            dfs(j);
        }
    }
}

void Graph::isConnected()
{
    if (n == 0)
    {
        cout << "Graph is empty";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    dfs(0);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            count++;
    }

    if (count == n)
    {
        cout << "The graph is CONNECTED";
    }
    else
    {
        cout << "The graph is NOT connected. Unreachable cities: ";
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                cout << city[i] << " ";
        }
    }
}

int main()
{
    Graph g;
    int choice;
    char ch;
    do
    {
        cout << "\n\n******Menu******";
        cout << "\n1. Add city";
        cout << "\n2. Add flight";
        cout << "\n3. Display adjacency matrix";
        cout << "\n4. Check whether graph is connected";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.addCity();
            break;
        case 2:
            g.addFlight();
            break;
        case 3:
            g.displayMatrix();
            break;
        case 4:
            g.isConnected();
            break;
        default:
            cout << "Invalid choice";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    return 0;
}
