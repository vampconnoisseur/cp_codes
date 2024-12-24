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

void solve()
{
    int n, k;
    cin >> n >> k;

    vpii vals(n);
    fore(e, vals) cin >> e.X;
    fore(e, vals) cin >> e.Y;

    vi coords = {-INF, INF};
    fore(e, vals)
    {
        coords.pb(e.X);
        coords.pb(e.Y);
    }
    SORT(coords);
    (coords).erase(unique(all(coords)), (coords).end());
    int m = coords.size();

    vi buys(m);
    vi negRevs(m);

    fore(e, vals)
    {
        int aIdx = lower_bound(all(coords), e.X) - coords.begin();
        int bIdx = lower_bound(all(coords), e.Y) - coords.begin();
        buys[0]++;
        buys[bIdx + 1]--;
        negRevs[aIdx + 1]++;
        negRevs[bIdx + 1]--;
    }
    rep(i, 0, m)
    {
        buys[i + 1] += buys[i];
        negRevs[i + 1] += negRevs[i];
    }

    ll ans = LLONG_MIN;
    rep(i, 1, m)
    {
        if (negRevs[i] <= k)
            ans = max(ans, 1LL * buys[i] * coords[i]);
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