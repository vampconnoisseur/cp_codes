#include <iostream>
#include <vector>
using namespace std;

void k235(int n, int k, const vector<int> &v)
{
    int ans = k - 1;
    for (size_t i = 0; i < n; i++)
    {
        int rem = v[i] % k;
        if (rem == 0)
        {
            ans = 0;
            break;
        }
        ans = min(ans, k - rem);
    }
    cout << ans << endl;
}

void k4(int n, const vector<int> &v)
{
    int ans = 2;
    int evens = 2;
    for (size_t i = 0; i < n; i++)
    {

        if (v[i] % 4 == 0)
        {
            ans = 0;
            break;
        }
        if (v[i] % 2 == 0)
        {
            evens--;
            if (evens == 0)
            {
                ans = 0;
                break;
            }
        }
        else
        {
            int rem = v[i] % 4;
            ans = min(ans, 4 - rem);
        }
    }
    cout << min(ans, evens) << endl;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (k == 2 || k == 3 || k == 5)
        k235(n, k, v);
    else
        k4(n, v);
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