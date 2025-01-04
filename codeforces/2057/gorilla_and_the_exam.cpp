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
    int n, k;
    cin >> n >> k;

    map<int, int> m;
    rep(i, 0, n)
    {
        int a;
        cin >> a;
        m[a]++;
    }

    vpii v(all(m));

    sort(all(v), [](const pii &a, const pii &b)
         { return a.Y < b.Y; });

    for (auto it = v.begin(); it != v.end();)
    {
        if (k == 0)
            break;

        if (it->Y <= k)
        {
            k -= it->Y;
            it = v.erase(it);
        }
        else
        {
            break;
        }
    }

    cout << ((v.size() > 0) ? v.size() : 1) << endl;
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