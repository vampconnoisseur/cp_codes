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
    int n;
    cin >> n;

    n -= 2;

    vi v(n);
    fore(e, v) cin >> e;

    vpii zero_seg;
    int start = -1;

    rep(i, 0, n)
    {
        if (v[i] == 0)
        {
            if (start == -1)
            {
                start = i;
            }
        }
        else
        {
            if (start != -1)
            {
                zero_seg.pb({start, i - 1});
                start = -1;
            }
        }
    }
    if (start != -1)
    {
        zero_seg.pb({start, n - 1});
    }

    bool hasValidSegment = false;
    bool hasInvalidSegment = false;

    for (auto &[s, e] : zero_seg)
    {
        if ((e - s + 1) >= 2 || s == 0 || e == n - 1)
        {
            hasValidSegment = true;
        }
        else
        {
            hasInvalidSegment = true;
        }
    }

    if (hasInvalidSegment)
        no;
    else
        yes;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}