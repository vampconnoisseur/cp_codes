#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define vvi vector<vector<int>>

#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq priority_queue<int>

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(e, a) for (auto &e : a)

#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string binaryStringXor(const string &s, const string &t)
{
    string result;
    int n1 = s.length(), n2 = t.length();
    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 || j >= 0)
    {
        char bit1 = (i >= 0) ? s[i] : '0';
        char bit2 = (j >= 0) ? t[j] : '0';
        result.push_back((bit1 != bit2) ? '1' : '0');
        i--;
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    int p = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            p = i;
            break;
        }
    }

    if (p == -1)
    {
        cout << 1 << " " << n << " " << 1 << " " << 1 << endl;
        return;
    }

    int len = n - p;
    string maxXor = "";
    int startIndex = 0, endIndex = 0;

    for (int i = 0; i <= n - len; i++)
    {
        int start = i;
        int end = i + len - 1;

        if (s[start] == '0')
            continue;

        string t = s.substr(start, len);
        string currentXor = binaryStringXor(s, t);

        if (currentXor > maxXor)
        {
            maxXor = currentXor;
            startIndex = start + 1;
            endIndex = end + 1;
        }
    }

    cout << 1 << " " << n << " " << startIndex << " " << endIndex << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}