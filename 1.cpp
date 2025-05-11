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

bool is_adj(char a, char b)
{
    return abs(a - b) <= 1;
}

ll interval_score(int l, int r)
{
    int len = r - l + 1;
    return 1LL * len * (len - 1) / 2;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size(), start = 0;
    vpii intervals;

    rep(i, 1, n)
    {
        if (!is_adj(s[i], s[i - 1]))
        {
            if (i - start >= 2)
                intervals.pb({start, i - 1});
            start = i;
        }
    }
    if (n - start >= 2)
        intervals.pb({start, n - 1});

    ll base_score = n;
    for (auto [l, r] : intervals)
        base_score += interval_score(l, r);

    ll max_score = base_score;

    rep(i, 0, intervals.size() - 1)
    {
        auto [l1, r1] = intervals[i];
        auto [l2, r2] = intervals[i + 1];
        int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;

        if (r1 + 2 == l2)
        {
            rep(c, 0, 26)
            {
                char ch = 'a' + c;
                if (is_adj(s[r1], ch) && is_adj(ch, s[l2]))
                {
                    ll merged_len = r2 - l1 + 1;
                    ll merged_score = merged_len * (merged_len - 1) / 2;

                    max_score = max(max_score, base_score - interval_score(l1, r1) - interval_score(l2, r2) + merged_score);
                    break;
                }
            }
        }

        if (r1 + 1 == l2)
        {
            int longer = max(len1, len2);
            int shorter = min(len1, len2);

            ll temp_score = base_score - (shorter - 1) + longer;
            max_score = max(max_score, temp_score);
        }
        else
        {
            max_score = max(max_score, base_score + max(len1, len2));
        }
    }

    cout << max_score << endl;
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