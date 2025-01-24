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
ll binpowMod(ll a, ll b) { a %= MOD; ll res = 1; while (b > 0) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1; } return res; }
void addPrimeDivs(int x, map<int, int> &divs) { int i = 2; while (i * i <= x) { while (x % i == 0) { divs[i]++; x /= i; } i++; } if (x > 1) divs[x]++; }
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")
// clang-format on

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vi a(n);
        fore(e, a) cin >> e;

        l--, r--;

        int segmentSize = r - l + 1;

        vi smallestElements = a;
        SORT(smallestElements);
        smallestElements.resize(segmentSize);

        vi segment(a.begin() + l, a.begin() + r + 1);
        SORT(segment);
        vi remaining;
        vi minimalInSegment;

        int si = 0, ri = 0;
        while (si < segmentSize && ri < segment.size())
        {
            if (smallestElements[si] == segment[ri])
            {
                minimalInSegment.push_back(segment[ri]);
                si++;
                ri++;
            }
            else if (smallestElements[si] < segment[ri])
            {
                si++;
            }
            else
            {
                remaining.push_back(segment[ri]);
                ri++;
            }
        }
        while (ri < segment.size())
        {
            remaining.pb(segment[ri]);
            ri++;
        }

        vi left(a.begin(), a.begin() + l);
        vi right(a.begin() + r + 1, a.end());

        left.insert(left.end(), remaining.begin(), remaining.end());
        right.insert(right.end(), remaining.begin(), remaining.end());

        SORT(left);
        SORT(right);

        int remainingSize = remaining.size();
        ll leftSum = accumulate(left.begin(), left.begin() + remainingSize, 0LL);
        ll rightSum = accumulate(right.begin(), right.begin() + remainingSize, 0LL);

        ll minimalSum = accumulate(minimalInSegment.begin(), minimalInSegment.end(), 0LL);
        leftSum += minimalSum;
        rightSum += minimalSum;

        cout << min(leftSum, rightSum) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}