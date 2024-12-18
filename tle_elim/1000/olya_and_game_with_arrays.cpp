#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int len = n;

    vector<pair<int, int>> v;

    while (n--)
    {
        int m;
        cin >> m;

        int smallest = 1e9;
        int second_smallest = 1e9;

        for (int i = 0; i < m; i++)
        {
            int a;
            cin >> a;

            if (a < second_smallest)
            {
                second_smallest = a;
                if (second_smallest < smallest)
                    swap(second_smallest, smallest);
            }
        }

        v.emplace_back(second_smallest, smallest);
    }

    sort(v.begin(), v.end());

    int mini = v[0].second;
    long long ans = 0;

    for (int i = 1; i < len; i++)
    {
        mini = min(mini, v[i].second);
        ans += v[i].first;
    }

    ans += mini;
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