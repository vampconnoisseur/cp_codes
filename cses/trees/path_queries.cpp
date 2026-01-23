#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

vector<int> adj[MAXN + 1];
int tin[MAXN + 1], tout[MAXN + 1];
long long val[MAXN + 1];
long long bit[2 * MAXN + 5];
int timer = 0;
int N2;

void bit_add(int idx, long long delta)
{
    while (idx <= N2)
    {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

long long bit_sum(int idx)
{
    long long res = 0;
    while (idx > 0)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    for (int u : adj[v])
    {
        if (u == p)
            continue;
        dfs(u, v);
    }
    tout[v] = ++timer;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    N2 = 2 * n;

    for (int v = 1; v <= n; ++v)
    {
        bit_add(tin[v], val[v]);
        bit_add(tout[v], -val[v]);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s;
            long long x;
            cin >> s >> x;
            long long diff = x - val[s];
            val[s] = x;
            bit_add(tin[s], diff);
            bit_add(tout[s], -diff);
        }
        else
        {
            int s;
            cin >> s;
            cout << bit_sum(tin[s]) << '\n';
        }
    }

    return 0;
}