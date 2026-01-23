#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> adj[MAXN + 1];
int in[MAXN + 1], subtree[MAXN + 1];
long long flat[MAXN + 1], values[MAXN + 1];
long long fenwick[MAXN + 1];
int timer = 1;

void fenwick_add(int idx, long long val)
{
    while (idx <= MAXN)
    {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

long long fenwick_sum(int idx)
{
    long long s = 0;
    while (idx > 0)
    {
        s += fenwick[idx];
        idx -= idx & -idx;
    }
    return s;
}

void dfs(int v, int p)
{
    in[v] = timer;
    flat[timer] = values[v];
    timer++;

    subtree[v] = 1;
    for (int u : adj[v])
    {
        if (u == p)
            continue;
        dfs(u, v);
        subtree[v] += subtree[u];
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> values[i];

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++)
        fenwick_add(i, flat[i]);

    while (q--)
    {
        int type, s;
        cin >> type >> s;

        if (type == 1)
        {
            long long x;
            cin >> x;
            long long diff = x - values[s];
            values[s] = x;
            fenwick_add(in[s], diff);
        }
        else
        {
            int L = in[s];
            int R = in[s] + subtree[s] - 1;
            cout << fenwick_sum(R) - fenwick_sum(L - 1) << "\n";
        }
    }

    return 0;
}