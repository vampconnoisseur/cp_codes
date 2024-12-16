#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        int zeroOne = 0;
        int oneZero = 0;

        int i = 0;
        while (i < n)
        {
            if (s[i] == '1' && t[i] == '0')
                oneZero++;
            else if (s[i] == '0' && t[i] == '1')
                zeroOne++;
            i++;
        }

        if (oneZero > zeroOne)
        {
            oneZero -= zeroOne;
            if (oneZero % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            zeroOne -= oneZero;
            if (zeroOne % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}