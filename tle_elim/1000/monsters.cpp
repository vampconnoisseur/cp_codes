#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<pair<int, int>> other_remainders;

    for (int i = 0; i < n; i++)
    {
        int remainder = v[i] % k;
        if (remainder == 0)
        {
            cout << i + 1 << " ";
        }
        else
        {
            other_remainders.push_back({remainder, i + 1});
        }
    }

    sort(other_remainders.begin(), other_remainders.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             if (a.first != b.first)
             {
                 return a.first > b.first; 
             }
             return a.second < b.second; });

    for (auto p : other_remainders)
    {
        cout << p.second << " ";
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