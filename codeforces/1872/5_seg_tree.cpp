// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq priority_queue<int>
#define SORT(a) sort(a.begin(), a.end())
#define REVSORT(a, T) sort(a.begin(), a.end(), greater<T>())
#define rev(a) reverse(a.begin(), a.end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(e, a) for (auto &e : a)
#define all(v) v.begin(), v.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")
// clang-format on

const int MAXN = 1e5 + 5;
pair<ll, ll> seg[4 * MAXN];
bool lazy[4 * MAXN];

void build(int node, int l, int r, const vi &a, const string &s)
{
    if (l == r)
    {
        if (s[l - 1] == '0')
            seg[node] = {a[l - 1], 0};
        else
            seg[node] = {0, a[l - 1]};
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid, a, s);
    build(node * 2 + 1, mid + 1, r, a, s);
    seg[node] = {
        seg[node * 2].X ^ seg[node * 2 + 1].X,
        seg[node * 2].Y ^ seg[node * 2 + 1].Y};
}

void push(int node, int l, int r)
{
    if (lazy[node])
    {
        swap(seg[node].X, seg[node].Y);
        if (l != r)
        {
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr)
{
    push(node, l, r);
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        lazy[node] ^= 1;
        push(node, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr);
    update(node * 2 + 1, mid + 1, r, ql, qr);
    seg[node] = {
        seg[node * 2].X ^ seg[node * 2 + 1].X,
        seg[node * 2].Y ^ seg[node * 2 + 1].Y};
}

pll query(int node, int l, int r)
{
    push(node, l, r);
    return seg[node];
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    fore(e, a) cin >> e;

    string s;
    cin >> s;

    fill(lazy, lazy + 4 * n + 4, false);
    build(1, 1, n, a, s);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
        }
        else
        {
            int g;
            cin >> g;
            auto res = query(1, 1, n);
            cout << (g == 0 ? res.X : res.Y) << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}