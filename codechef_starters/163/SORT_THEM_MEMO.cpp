#include <iostream>
#include <string>
#include <climits>
using namespace std;

char swap(char c, const string &p)
{
    int idxC = p.find(c);
    return p[25 - idxC];
}

int f(int i, int change, const string &s, const string &p, vector<vector<int>> &dp)
{
    if (i == s.length())
    {
        return dp[i][change] = 0;
    }

    if (dp[i][change] != -1)
        return dp[i][change];

    int mini = 1e9;

    if (change == 0)
    {
        if (s[i] >= s[i - 1])
        {
            mini = min(mini, f(i + 1, 0, s, p, dp));
        }

        if (swap(s[i], p) >= s[i - 1])
        {
            mini = min(mini, 1 + f(i + 1, 1, s, p, dp));
        }
    }

    if (change == 1)
    {
        if (s[i] >= swap(s[i - 1], p))
        {
            mini = min(mini, f(i + 1, 0, s, p, dp));
        }

        if (swap(s[i], p) >= swap(s[i - 1], p))
        {
            mini = min(mini, 1 + f(i + 1, 1, s, p, dp));
        }
    }

    return dp[i][change] = mini;
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

        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        int result = min(f(1, 0, s, p, dp), 1 + f(1, 1, s, p, dp));

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