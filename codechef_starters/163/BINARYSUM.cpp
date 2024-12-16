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
        int n, k;
        cin >> n >> k;

        if (2 * k - 1 <= n && n <= 2 * k + 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}