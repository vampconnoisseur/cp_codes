#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int LOG = 18;

vector<int> adj[MAXN + 5];
int LCA[MAXN + 5][LOG];
int depth[MAXN + 5];

int n, q;

void dfs(int v, int p)
{
    LCA[v][0] = p;

    for (int i = 1; i < LOG; i++)
    {
        if (LCA[v][i - 1] != -1)
            LCA[v][i] = LCA[LCA[v][i - 1]][i - 1];
        else
            LCA[v][i] = -1;
    }

    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
    {
        if (diff & (1 << i))
            a = LCA[a][i];
    }
    if (a == b)
        return a;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (LCA[a][i] != LCA[b][i])
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    depth[1] = 0;
    dfs(1, -1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}