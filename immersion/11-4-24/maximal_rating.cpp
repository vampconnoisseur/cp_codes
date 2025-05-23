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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }
void sieve(vector<bool> &primes, int N) { primes[0] = primes[1] = true; for (int i = 2; i * i <= N; i++) { if (!primes[i]) { for (int j = i * i; j <= N; j += i) { primes[j] = true; } } } }
ll binpow(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
ll binpowMod(ll a, ll b) { a %= MOD; int res = 1; while (b > 0) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1; } return res; }
void addPrimeDivs(int x, map<int, int> &divs) { int i = 2; while (i * i <= x) { while (x % i == 0) { divs[i]++; x /= i; } i++; } if (x > 1) divs[x]++; }
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")
// clang-format on

const int MAXN = 2e6 + 5;
vector<int> segtree;

void build(int node, int l, int r, vi &arr)
{
    if (l == r)
    {
        segtree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid, arr);
    build(2 * node + 1, mid + 1, r, arr);
    segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

int query(int node, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r)
        return 0;
    if (ql <= l && r <= qr)
        return segtree[node];
    int mid = (l + r) / 2;
    return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n;
    cin >> n;
    vpii laptops(n);
    set<int> all_prices;
    rep(i, 0, n)
    {
        cin >> laptops[i].X >> laptops[i].Y;
        all_prices.insert(laptops[i].X);
    }

    int q;
    cin >> q;
    vpii queries(q);
    rep(i, 0, q)
    {
        cin >> queries[i].X >> queries[i].Y;
        all_prices.insert(queries[i].X);
        all_prices.insert(queries[i].Y);
    }

    vi compressed(all_prices.begin(), all_prices.end());
    unordered_map<int, int> price_to_index;
    rep(i, 0, compressed.size()) price_to_index[compressed[i]] = i;

    int m = compressed.size();
    vi rating_array(m, 0);
    for (auto &[p, r] : laptops)
    {
        int idx = price_to_index[p];
        rating_array[idx] = max(rating_array[idx], r);
    }

    segtree.assign(4 * m, 0);
    build(1, 0, m - 1, rating_array);

    rep(i, 0, q)
    {
        int l = queries[i].X;
        int r = queries[i].Y;

        auto it1 = lower_bound(all(compressed), l);
        auto it2 = upper_bound(all(compressed), r);
        if (it1 == compressed.end() || it1 >= it2)
        {
            cout << 0 << '\n';
            continue;
        }
        int li = it1 - compressed.begin();
        int ri = it2 - compressed.begin() - 1;

        cout << query(1, 0, m - 1, li, ri) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    solve();

    return 0;
}