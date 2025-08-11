#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[u] = true;
    for (int v = 0; v < adj.size(); ++v)
    {
        if (adj[u][v] && !vis[v])
        {
            dfs(v, vis, adj);
        }
    }
}

int cntConnComp(int n, vector<vector<int>> &adj, int ex)
{
    vector<bool> vis(n, false);
    if (ex != -1)
    {
        vis[ex] = true;
    }
    int comp = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj);
            comp++;
        }
    }
    return comp;
}

set<int> findA(int n, vector<vector<int>> &adj)
{
    set<int> TA;
    int init_comp = cntConnComp(n, adj, -1);
    for (int i = 0; i < n; ++i)
    {
        int new_comp = cntConnComp(n, adj, i);
        if (new_comp > init_comp)
        {
            TA.insert(i);
        }
    }
    return TA;
}

set<int> findB(int n, vector<vector<int>> &adj, set<int> &TA)
{
    set<int> TB;
    for (int a : TA)
    {
        for (int b = 0; b < n; ++b)
        {
            if (adj[a][b])
            {
                TB.insert(b);
            }
        }
    }
    for (int a : TA)
    {
        TB.erase(a);
    }
    return TB;
}

void connVer(int **arr, int n)
{
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            adj[i][j] = arr[i][j];
        }
    }

    set<int> TA = findA(n, adj);
    set<int> TB = findB(n, adj, TA);

    for (int city : TB)
    {
        cout << city << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int **arr;
    arr = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    connVer(arr, n);
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}