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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")

template <typename T, typename Y>
istream &operator>>(istream &is, pair<T, Y> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, pair<T, Y> p) {
    os << p.first << ' ' << p.second << ' ';
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v) os << i << ' ';
    return os;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll binpowMod(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inversemod(int a, int mod) {
    return binpow(a, mod - 2) % mod;
}
int divmod(int a, int b, int mod) {
    return ((a % mod) * inversemod(b, mod)) % mod;
}

void addPrimeDivs(int x, map<int, int> &divs) {
    int i = 2;
    while (i * i <= x) {
        while (x % i == 0) {
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if (x > 1) divs[x]++;
}
void sieve(vector<bool> &primes, int N) {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!primes[i]) {
            for (int j = i * i; j <= N; j += i) {
                primes[j] = true;
            }
        }
    }
}

const int NUM = 2e5 + 5;
vector<int> power(NUM), fact(NUM);
void initpow(int x) {
    power[0] = 1;
    for (int i = 1; i < NUM; i++) {
        power[i] = (1LL * power[i - 1] * x) % MOD;
    }
}
void initFactorial() {
    fact[0] = 1;
    for (int i = 1; i < NUM; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
}
int combination(int n, int k) {
    if (k > n) return 0;
    int p1 = (1LL * fact[n] * inversemod(fact[k], MOD)) % MOD;
    int p2 = inversemod(fact[n - k], MOD);
    return (1LL * p1 * p2) % MOD;
}

int N = NUM;
vector<int> lp(N + 1, 0), sieve_arr(N + 1, 0), pr;
void calc_sieve() {
    for (int x = 2; x <= N; x++) {
        if (sieve_arr[x]) continue;
        for (int u = x; u <= N; u += x) {
            sieve_arr[u] = x;
        }
    }
}
void primefactor() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
// clang-format on

void solve()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;

    vll a(n);
    ll total_transferable = 0;

    rep(i, 0, n)
    {
        cin >> a[i];
        total_transferable += (a[i] / x) * y;
    }

    ll max_rubles = 0;

    rep(i, 0, n)
    {
        ll contribution_i = (a[i] / x) * y;
        ll current_total = a[i] + (total_transferable - contribution_i);

        if (current_total > max_rubles)
        {
            max_rubles = current_total;
        }
    }

    cout << max_rubles << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}