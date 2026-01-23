#include <bits/stdc++.h>
using namespace std;

int find_lca(int a, int b, vector<vector<int>> &parent, vector<int> &level, int limit)
{
    if (level[a] > level[b])
        swap(a, b);

    int d = level[b] - level[a];

    while (d > 0)
    {
        int i = int(log2(d));
        b = parent[b][i];
        d -= (1 << i);
    }

    if (a == b)
        return a;

    for (int i = limit - 1; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

void dfs(int start, vector<vector<int>> &edges, vector<int> &level, int par, vector<vector<int>> &parent)
{
    for (auto nxt : edges[start])
    {
        if (nxt != par)
        {
            parent[nxt][0] = start;
            level[nxt] = level[start] + 1;
            dfs(nxt, edges, level, start, parent);
        }
    }
}

void dfs1(int start, vector<vector<int>> &edges, int par, vector<long long> &value)
{
    for (auto nxt : edges[start])
    {
        if (nxt != par)
        {
            dfs1(nxt, edges, start, value);
            value[start] += value[nxt];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int limit = int(log2(n)) + 1;

    vector<vector<int>> parent(n + 1, vector<int>(limit, -1));
    vector<int> level(n + 1, 0);

    dfs(1, edges, level, -1, parent);

    for (int j = 1; j < limit; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int x = parent[i][j - 1];
            if (x != -1)
                parent[i][j] = parent[x][j - 1];
        }
    }

    vector<long long> value(n + 1, 0);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int x = find_lca(a, b, parent, level, limit);

        value[a] += 1;
        value[b] += 1;
        value[x] -= 1;

        int y = parent[x][0];
        if (y != -1)
            value[y] -= 1;
    }

    dfs1(1, edges, -1, value);

    for (int i = 1; i <= n; i++)
        cout << value[i] << (i == n ? '\n' : ' ');

    return 0;
}