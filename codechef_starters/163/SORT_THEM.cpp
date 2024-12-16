#include <iostream>
#include <string>
#include <climits>
using namespace std;

char swap(char c, const string &p)
{
    int idxC = p.find(c);
    return p[25 - idxC];
}

int f(int i, char prev, const string &s, const string &p)
{
    if (i == s.length())
    {
        return 0;
    }

    int mini = 1e9;

    if (s[i] >= prev)
    {
        mini = min(mini, f(i + 1, s[i], s, p));
    }

    if (swap(s[i], p) >= prev)
    {
        mini = min(mini, 1 + f(i + 1, swap(s[i], p), s, p));
    }

    return mini;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s, p;

        cin >> n >> s >> p;

        int result = min(f(1, s[0], s, p), 1 + f(1, swap(s[0], p), s, p));

        if (result == 1e9)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}