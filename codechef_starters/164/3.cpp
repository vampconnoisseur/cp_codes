#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }

        bool exists = false;
        do
        {
            vector<int> f(n, 0);

            int preSum = 0;
            exists = false;
            for (size_t i = 0; i < n; i++)
            {
                preSum += v[i];
                int rem = preSum % (n + 1);

                if (rem == 0 || f[rem] > 0)
                {
                    cout << preSum << " " << rem << " " << f[rem] << endl;
                    exists = true;
                    break;
                }
                f[rem]++;
            }

            if (!exists)
            {
                for (auto i : v)
                {
                    cout << i << " ";
                }
                cout << endl;
                break;
            }

        } while (next_permutation(v.begin(), v.end()));

        if (exists)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}