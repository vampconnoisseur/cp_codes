// clang-format off
#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define ll long long
#define vi vector<int>

const int NUM = 300000 + 5;
vector<int> fact(NUM);

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

ll inversemod(ll a) {
    return binpowMod(a, MOD - 2);
}

void initFactorial() {
    fact[0] = 1;
    for (int i = 1; i < NUM; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
}

void solve()
{
    int n;
    cin >> n;
    vi w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    ll ans = 1;

    for (int i = 0; i < n; i += 3) {
        int a = w[i], b = w[i + 1], c = w[i + 2];
        ll mult = 1;

        if (a == b && b == c) {
            mult = 3;
        }
        else if (a != b && b != c && a != c) {
            mult = 1;
        }
        else {
            int mx = max({a, b, c});
            if ((a == b && a == mx) || (a == c && a == mx) || (b == c && b == mx)) {
                mult = 1;
            } else {
                mult = 2;
            }
        }

        ans = ans * mult % MOD;
    }

    ll res = ans;
    res = res * fact[n/3] % MOD;
    res = res * inversemod(fact[n / 6]) % MOD;
    res = res * inversemod(fact[n / 6]) % MOD;

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    initFactorial();

    solve();

    return 0;
}