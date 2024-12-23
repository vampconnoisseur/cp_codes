#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
#define SORT(a) sort((a).begin(), (a).end())
#define REVSORT(a, T) sort((a).begin(), (a).end(), greater<T>())
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

ll getCount(const vll &v, ll s)
{
    ll cnt = 0;
    vll b;
    fore(e, v)
    {
        int idx = upper_bound(all(b), s - e) - b.begin();
        cnt += idx;
        b.pb(e);
    }

    return cnt;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll sum = 0;
    vll v;
    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        v.pb(a);
        sum += a;
    }

    SORT(v);

    cout << getCount(v, sum - x) - getCount(v, sum - y - 1) << endl;
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