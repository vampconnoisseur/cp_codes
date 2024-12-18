#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long f(int n, int k)
{
    n -= k - 1;
    return ((long long)n * (long long)(n + 1)) / 2;
}

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    long long ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a <= q)
            count++;
        else
        {
            if (count >= k)
                ans += f(count, k);
            count = 0;
        }
    }

    if (count >= k)
        ans += f(count, k);
    cout << ans << endl;
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