#include <iostream>
#include <set>
// #include <bits/stdc++.
using namespace std;

#define ll long long

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define vvi vector<vector<int>>

#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq priority_queue<int>

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(e, a) for (auto &e : a)

#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int find_mex(set<int> values)
{
    int mex = 0;
    int n = values.size();

    fore(e, values)
    {
        if (mex != e)
            return mex;
        mex++;
    }

    return mex;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vi a(n + 1, -1);
    vvi adj(n + 1);

    rep(i, 1, n + 1)
    {
        set<int> s;
        int left = (i == 1) ? n : i - 1;
        int right = (i == n) ? 1 : i + 1;
        s.insert(left);
        s.insert(right);

        if (i == x)
            s.insert(y);
        else if (i == y)
            s.insert(x);

        for (auto val : s)
        {
            adj[i].pb(val);
        }
    }

    rep(i, 1, n + 1)
    {
        set<int> values;
        fore(e, adj[i])
        {
            if (a[e] != -1)
                values.insert(a[e]);
            else
                values.insert(e);
        }

        a[i] = find_mex(values);
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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