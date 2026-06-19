#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int ans = 0;

        if (a > m)
            ans += m;
        else
            ans += a;

        if (b > m)
            ans += m;
        else
            ans += b;

        int seatsLeft = (2 * m) - ans;
        if (c > seatsLeft)
            ans += seatsLeft;
        else
            ans += c;

        cout << ans << endl;
    }

    return 0;
}