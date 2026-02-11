#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k == 1)
    {
        cout << 1 << "\n";
        return;
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[1][i] = 1;
    for (int i = 1; i <= k; i++)
        dp[i][0] = 1;

    for (int age = 2; age <= k; age++)
    {
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = (pref[i] + dp[age - 1][i]) % MOD;
        }

        for (int i = 1; i <= n; i++)
        {
            int lower_bound = n - i;
            int upper_bound = n - 1;

            long long range_sum = (pref[upper_bound + 1] - pref[lower_bound] + MOD) % MOD;
            dp[age][i] = (1 + range_sum) % MOD;
        }
    }

    cout << dp[k][n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}