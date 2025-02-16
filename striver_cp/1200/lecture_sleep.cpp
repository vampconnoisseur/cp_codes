#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fore(e, a) for (auto &e : a)
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n), t(n);
    fore(e, a) cin >> e;
    fore(e, t) cin >> e;

    int sum = 0;
    vi pre(n, 0);

    rep(i, 0, n)
    {
        if (t[i] == 1)
            sum += a[i];

        pre[i] = (i > 0 ? pre[i - 1] : 0) + (t[i] == 0 ? a[i] : 0);
    }

    int maxi = 0;
    maxi = pre[k - 1];

    rep(i, k, n) maxi = max(maxi, pre[i] - pre[i - k]);

    cout << sum + maxi << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}