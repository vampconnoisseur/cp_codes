#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<long long> queries(q);
        for (int i = 0; i < q; i++)
        {
            cin >> queries[i];
        }

        bool hasB = false;
        for (char c : s)
        {
            if (c == 'B')
            {
                hasB = true;
                break;
            }
        }

        if (!hasB)
        {
            for (long long x : queries)
            {
                cout << x << '\n';
            }
            continue;
        }

        for (long long x : queries)
        {
            long long steps = 0;
            int idx = 0;

            while (x > 0)
            {
                if (s[idx] == 'A')
                {
                    x -= 1;
                }
                else
                {
                    x /= 2;
                }
                steps++;

                idx++;
                if (idx == n)
                    idx = 0;
            }

            cout << steps << endl;
        }
    }

    return 0;
}