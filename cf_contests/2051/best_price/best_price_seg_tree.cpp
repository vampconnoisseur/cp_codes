#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define si set<int>
#define sll set<long long>
#define spii set<pair<int, int>>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq priority_queue<int>
#define SORT(a) sort(a.begin(), a.end())
#define REVSORT(a, T) sort(a.begin(), a.end(), greater<T>())
#define rev(a) reverse(a.begin(), a.end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(e, a) for (auto &e : a)
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")

struct SegmentTree
{
    struct Node
    {
        ll value = 0;
        ll lazy = 0;
    };

    vector<Node> tree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);
    }

    void push(int v, int tl, int tr)
    {
        if (tree[v].lazy != 0)
        {
            tree[v].value += tree[v].lazy * (tr - tl + 1);
            if (tl != tr)
            {
                tree[2 * v].lazy += tree[v].lazy;
                tree[2 * v + 1].lazy += tree[v].lazy;
            }
            tree[v].lazy = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, ll val)
    {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            tree[v].lazy += val;
            push(v, tl, tr);
        }
        else
        {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v].value = tree[v * 2].value + tree[v * 2 + 1].value;
        }
    }

    ll query(int v, int tl, int tr, int l, int r)
    {
        push(v, tl, tr);
        if (l > r)
            return 0;
        if (l <= tl && tr <= r)
        {
            return tree[v].value;
        }
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int l, int r, ll val)
    {
        update(1, 0, n - 1, l, r, val);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;

    vpii vals(n);
    fore(e, vals) cin >> e.X;
    fore(e, vals) cin >> e.Y;

    map<int, int> coordMap;
    set<int> coords;
    fore(e, vals)
    {
        coords.insert(e.X);
        coords.insert(e.Y);
    }

    int idx = 0;
    fore(coord, coords)
    {
        coordMap[coord] = idx++;
    }
    int m = coordMap.size();

    SegmentTree buysSeg(m), negRevsSeg(m);

    fore(e, vals)
    {
        int aIdx = coordMap[e.X];
        int bIdx = coordMap[e.Y];
        buysSeg.update(0, bIdx, 1);
        negRevsSeg.update(aIdx + 1, bIdx, 1);
    }

    ll ans = LLONG_MIN;
    fore(coord, coords)
    {
        int i = coordMap[coord];
        if (negRevsSeg.query(i, i) <= k)
        {
            ll current = buysSeg.query(i, i) * coord;
            ans = max(ans, current);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}