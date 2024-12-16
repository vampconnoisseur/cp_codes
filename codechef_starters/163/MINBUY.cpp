#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, cost;
        cin >> n >> cost;

        vector<int> type(n);
        vector<int> coins(n);
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            cin >> type[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }

        for (int i = 0; i < n; i++)
        {
            v.push_back(type[i] * coins[i]);
        }

        sort(v.begin(), v.end(), greater<int>());

        int i = 0;
        int distinct_coins = 0;

        while (cost > 0 && i < n)
        {
            cost -= v[i];
            i++;
            distinct_coins++;
        }

        if (cost > 0)
            cout << -1 << endl;
        else
            cout << distinct_coins << endl;
    }

    return 0;
}