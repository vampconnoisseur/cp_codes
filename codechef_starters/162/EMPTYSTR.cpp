#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minOps(string s, int n)
{
    bool flag = true;

    int ops = 0;
    int len = n;

    while (flag)
    {
        string temp = "";

        int newLen = 0;
        flag = false;
        bool isA = false;

        if (s[0] == 'A')
            isA = false;
        else
            isA = true;

        for (int i = 1; i < len; i++)
        {
            if (s[i] == 'B' && isA == false)
            {
                isA = true;
            }
            else if (s[i] == 'A' && isA == true)
            {
                isA = false;
            }
            else
            {
                flag = true;
                newLen++;
                temp += s[i];
            }
        }

        if (temp.length() == s.length() - 1)
        {
            ops += temp.length() + 1;
            break;
        }

        s = temp;
        ops++;
        len = newLen;
    }

    return ops;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;

        int ans = 0;

        int len = minOps(str, n);

        if (len == 1)
        {
            cout << (n * (n + 1)) / 2 << endl;
            continue;
        }
        else if (len == n)
        {
            cout << (n * (n + 1) * (n + 2)) / 6 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = i; j < n; j++)
            {
                s += str[j];
                int n = s.length();
                ans += minOps(s, n);
            }
        }

        cout << ans << endl;
    }

    return 0;
}