#include <iostream>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();

    int i = 0;
    int j = 0;

    while (i < n || j < n)
    {
        while (i < n && s[i] != '0')
            i++;
        while (j < n && s[j] != '1')
            j++;

        if (i >= n || j >= n)
            break;
        else
        {
            i++;
            j++;
        }
    }

    if (i >= n && j >= n)
        cout << 0 << endl;
    else if (i >= n)
        cout << n - j << endl;
    else
        cout << n - i << endl;
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