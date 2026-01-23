#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200111;
const int N = 20;

vector<int> adj[MAXN];
int up[MAXN][N], level[MAXN];

void dfs(int node, int parent)
{
    up[node][0] = parent;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        level[child] = level[node] + 1;
        dfs(child, node);
    }
}

void preprocess(int n)
{
    dfs(1, -1);

    for (int j = 1; j < N; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (up[i][j - 1] == -1)
                up[i][j] = -1;
            else
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);

    int diff = level[b] - level[a];
    for (int i = 0; i < N; i++)
    {
        if (diff & (1 << i))
        {
            b = up[b][i];
        }
    }

    if (a == b)
        return a;

    for (int i = N - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        for (int j = 0; j < N; j++)
            up[i][j] = -1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    preprocess(n);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int l = LCA(a, b);
        int dist = level[a] + level[b] - 2 * level[l];
        cout << dist << "\n";
    }

    return 0;
}