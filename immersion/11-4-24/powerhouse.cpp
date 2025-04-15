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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void sieve(vector<bool> &primes, int N) { primes[0] = primes[1] = true; for (int i = 2; i * i <= N; i++) if (!primes[i]) for (int j = i * i; j <= N; j += i) primes[j] = true; }
ll binpow(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res *= a; a *= a; b >>= 1; } return res; }
ll binpowMod(ll a, ll b) { a %= MOD; ll res = 1; while (b > 0) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1; } return res; }
void addPrimeDivs(int x, map<int, int> &divs) { for (int i = 2; i * i <= x; ++i) while (x % i == 0) { divs[i]++; x /= i; } if (x > 1) divs[x]++; }
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")
// clang-format on

struct SegmentTree
{
    int size;
    vll tree, lazy;

    SegmentTree(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }

    void push(int x, int lx, int rx)
    {
        if (lazy[x] == 0 || rx - lx == 1)
            return;
        tree[2 * x + 1] += lazy[x] * ((rx - lx) / 2);
        tree[2 * x + 2] += lazy[x] * ((rx - lx) / 2);
        lazy[2 * x + 1] += lazy[x];
        lazy[2 * x + 2] += lazy[x];
        lazy[x] = 0;
    }

    void add(int l, int r, ll v, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            tree[x] += v * (rx - lx);
            lazy[x] += v;
            return;
        }
        push(x, lx, rx);
        int mid = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, mid);
        add(l, r, v, 2 * x + 2, mid, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void add(int l, int r, ll v)
    {
        add(l, r, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
            return 0;
        if (lx >= l && rx <= r)
            return tree[x];
        push(x, lx, rx);
        int mid = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
    }

    ll sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }

    void build(const vll &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                tree[x] = a[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void build(const vll &a)
    {
        build(a, 0, 0, size);
    }
};

bool can(ll x, int D, ll W, int N, const vll &a)
{
    SegmentTree seg(N);
    seg.build(a);
    ll w = W;

    rep(i, 0, N)
    {
        int l = max(0, i - D), r = min(N - 1, i + D);
        ll sum = seg.sum(l, r + 1);

        if (sum < x)
        {
            ll need = x - sum;
            if (need > w)
                return false;
            w -= need;

            seg.add(r, r + 1, need);
        }
    }
    return true;
}

void solve()
{
    int N, D;
    ll W;
    vll a;
    cin >> N >> D >> W;

    a.resize(N);
    rep(i, 0, N) cin >> a[i];

    ll low = 0, high = 2e18, ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (can(mid, D, W, N, a))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
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
        solve();
}