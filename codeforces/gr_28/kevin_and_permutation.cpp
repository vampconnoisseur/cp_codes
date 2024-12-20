#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> ans(n, -1);

    int j = 1;
    for (int i = k - 1; i < n; i += k)
    {
        ans[i] = j++;
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == -1)
            ans[i] = j++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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