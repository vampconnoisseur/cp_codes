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

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int change = 1;

        while (change)
        {
            change = 0;

            for (int i = 1; i < n - 1; i++)
            {
                if ((a[i - 1] + a[i + 1] == 4) && (a[i] > 2))
                {
                    a[i] = 4 - a[i];
                    change = 1;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }

        cout << sum << endl;
    }

    return 0;
}