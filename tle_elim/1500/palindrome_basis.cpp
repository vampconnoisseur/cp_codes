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
    return binpow(a, mod - 2);
}
int divmod(int a, int b, int mod) {
    return ((a % mod) * inversemod(b, mod)) % mod;
}
// clang-format on

const int MAXN = 40004;
const int PALIN_COUNT = 502;

vvll dp(MAXN, vll(PALIN_COUNT));
vi palin;

int reverse_num(int n)
{
    int r = 0;
    while (n > 0)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

bool is_palindrome(int n)
{
    return (reverse_num(n) == n);
}

void precompute()
{
    palin.pb(0);
    rep(i, 1, MAXN) if (is_palindrome(i)) palin.pb(i);

    rep(j, 1, PALIN_COUNT) dp[0][j] = 1;

    rep(i, 1, MAXN)
    {
        dp[i][0] = 0;
        rep(j, 1, palin.size())
        {
            dp[i][j] = dp[i][j - 1];

            if (palin[j] <= i)
            {
                dp[i][j] = (dp[i][j] + dp[i - palin[j]][j]) % MOD;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n][palin.size() - 1] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}