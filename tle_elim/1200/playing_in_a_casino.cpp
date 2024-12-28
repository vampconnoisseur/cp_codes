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
    int n, m;
    cin >> n >> m;
    vvll v(n, vll(m));
    fore(x, v) fore(y, x) cin >> y;

    vvll preFix(m, vll(n)), org(m, vll(n));
    rep(i, 0, m) rep(j, 0, n) preFix[i][j] = v[j][i];

    fore(e, preFix) SORT(e);
    rep(i, 0, m) rep(j, 0, n) org[i][j] = preFix[i][j];
    rep(i, 0, m) rep(j, 1, n) preFix[i][j] += preFix[i][j - 1];

    ll ans = 0;
    rep(i, 0, m) rep(j, 1, n) ans += ((org[i][j] * j) - (preFix[i][j - 1]));

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