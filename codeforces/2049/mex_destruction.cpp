#include <iostream>
// #include <bits/stdc++.h>
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

void solve()
{
    int n;
    cin >> n;

    vi v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }

    int islands = 0;
    int count = 0;

    rep(i, 0, n)
    {
        if (v[i] != 0)
            count++;
        else
            count = 0;
        if (count == 1)
            islands++;
    }

    if (islands > 1)
        cout << 2 << endl;
    else if (islands == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
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