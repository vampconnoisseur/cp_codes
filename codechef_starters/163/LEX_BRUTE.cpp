#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int f(string s, string t, unordered_map<string, int> &dp)
{
    if (s == t)
        return 1;

    if (s.length() < 4 || s.length() < t.length())
        return 0;

    if (dp.find(s) != dp.end())
        return dp[s];

    for (int i = 0; i < s.length() - 3; i++)
    {
        if (s[i + 1] == s[i + 2] && s[i] != s[i + 3])
        {
            string modS = s;
            modS.erase(i + 1, 2);
            if (f(modS, t, dp))
                return dp[s] = 1;
        }
    }

    return dp[s] = 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s, t;
        cin >> s >> t;

        if (s.length() == 1 && t.length() == 1)
        {
            if (s == t)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        unordered_map<string, int> dp;

        if (f(s, t, dp) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}