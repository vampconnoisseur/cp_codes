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
#define vvll vector<vector<long long>>
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

void solve()
{
    int n;
    cin >> n;

    vpii a(n);
    vi freq(2 * n + 1, 0);
    vi pref(2 * n + 2, 0);

    rep(i, 0, n)
    {
        cin >> a[i].X >> a[i].Y;
        if (a[i].X == a[i].Y)
        {
            freq[a[i].X]++;
        }
    }

    rep(i, 1, 2 * n + 1)
    {
        pref[i] = pref[i - 1] + (freq[i] == 0 ? 1 : 0);
    }

    string result = "";

    rep(i, 0, n)
    {
        int l = a[i].X, r = a[i].Y;

        if (l == r)
        {
            result += (freq[l] == 1 ? '1' : '0');
        }
        else
        {
            int unused_count = pref[r] - pref[l - 1];
            result += (unused_count > 0 ? '1' : '0');
        }
    }

    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}