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

void solve()
{
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    fore(e, a) cin >> e;
    fore(e, b) cin >> e;

    vi s(m, -INF), p(m, INF);

    int p1 = 0;
    rep(i, 0, n)
    {
        if (p1 >= m)
            break;
        if (a[i] >= b[p1])
        {
            p[p1] = i;
            p1++;
        }
    }

    int p2 = m - 1;
    rrep(i, n - 1, 0)
    {
        if (p2 < 0)
            break;
        if (a[i] >= b[p2])
        {
            s[p2] = i;
            p2--;
        }
    }

    if (p[m - 1] != INF)
    {
        cout << 0 << endl;
        return;
    }

    int ans = INT_MAX;

    rep(i, 1, m - 1)
    {
        if (s[i + 1] > p[i - 1])
        {
            ans = min(ans, b[i]);
        }
    }

    if (s[1] != -INF)
        ans = min(ans, b[0]);

    if (p[m - 2] != INF)
        ans = min(ans, b[m - 1]);

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
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

    return 0;
}