#include <bits/stdc++.h>
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
#define vpii vector<pair<int, int>>

#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq priority_queue<int>

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(e, a) for (auto &e : a)

#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> lists(m);

    ll quesSum = (1LL * n * (n + 1)) / 2;
    ll knowsSum = 0;

    rep(i, 0, m)
    {
        cin >> lists[i];
    }
    rep(i, 0, k)
    {
        ll a;
        cin >> a;
        knowsSum += a;
    }

    if (k < n - 1)
    {
        cout << string(m, '0') << endl;
        return;
    }

    if (knowsSum == quesSum)
    {
        cout << string(m, '1') << endl;
        return;
    }

    string ans;
    rep(i, 0, m)
    {
        ll quesS = quesSum;
        quesS -= lists[i];
        if (quesS == knowsSum)
            ans += '1';
        else
            ans += '0';
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