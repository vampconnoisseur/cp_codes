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

vi prime_factors(int x)
{
    vi pf;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            pf.pb(i);
            x /= i;
        }
    }
    if (x > 1)
        pf.pb(x);
    return pf;
}

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vi one(n + 1), two_same(n + 1), two_diff(n + 1), cnt(n + 1);
    int prime_so_far = 0;

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        vi pf = prime_factors(x);

        if (pf.size() > 2)
            continue;

        if (pf.size() == 1)
        {
            one[x]++;
            prime_so_far++;
            ans += two_same[x] + two_diff[x] + (prime_so_far - one[x]);
        }
        else if (pf[0] == pf[1])
        {
            two_same[pf[0]]++;
            ans += one[pf[0]] + two_same[pf[0]];
        }
        else
        {
            two_diff[pf[0]]++;
            two_diff[pf[1]]++;
            cnt[x]++;
            ans += one[pf[0]] + one[pf[1]] + cnt[x];
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

    return 0;
}