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

class SegmentTree
{
    vector<ll> tree;
    int n;

public:
    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);
    }

    void update(int idx, ll val, int node = 1, int start = 0, int end = -1)
    {
        if (end == -1)
            end = n - 1;
        if (start == end)
        {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, start, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(int left, int right, int node = 1, int start = 0, int end = -1)
    {
        if (end == -1)
            end = n - 1;
        if (right < start || left > end)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return query(left, right, 2 * node, start, mid) +
               query(left, right, 2 * node + 1, mid + 1, end);
    }
};

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    vll a(n);
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    vll values = a;
    SORT(values);
    values.erase(unique(all(values), values.end()));

    map<ll, int> compress;
    for (int i = 0; i < values.size(); i++)
    {
        compress[values[i]] = i;
    }

    ll ans = 0;
    SegmentTree seg(values.size());

    for (int i = 0; i < n; i++)
    {
        ll min_val = total - y - a[i];
        ll max_val = total - x - a[i];
        int left_idx = lower_bound(all(values), min_val) - values.begin();
        int right_idx = upper_bound(all(values), max_val) - values.begin() - 1;

        if (left_idx < n && right_idx >= left_idx)
        {
            ans += seg.query(left_idx, right_idx);
        }
        seg.update(compress[a[i]], 1);
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
