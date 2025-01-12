#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int count(string m, vector<string> &s, unordered_map<string, int> &dp)
{
    if (m.length() == 0 || s.size() == 0)
    {
        return 0;
    }

    if (dp.find(m) != dp.end())
    {
        return dp[m];
    }

    int maxi = 0;

    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < s.size(); j++)
        {
            const string &sub = s[j];
            if (m.substr(i, sub.size()) == sub)
            {
                string modifiedM = m;
                modifiedM.erase(i, sub.size());

                vector<string> newSubStr = s;
                newSubStr.erase(newSubStr.begin() + j);

                maxi = max(maxi, 1 + count(modifiedM, newSubStr, dp));
            }
        }
    }

    dp[m] = maxi;
    return maxi;
}

int main()
{
    int n;
    cin >> n;

    vector<string> subStr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> subStr[i];
    }

    string mainStr;
    cin >> mainStr;

    unordered_map<string, int> dp;

    cout << count(mainStr, subStr, dp) << endl;

    return 0;
}