#include <iostream>
using namespace std;
void block(string s, vector<int> &v)
{
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            cnt++;
        }
        else
        {
            v.push_back(cnt);
            cnt = 1;
            c = s[i];
        }
    }
    v.push_back(cnt);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[0])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            if (s == t)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if (s[0] != t[0])
            {
                cout << "NO\n";
            }
            else
            {
                vector<int> a, b;
                block(s, a);
                block(t, b);
                bool f = true;

                for (auto i : a)
                {
                    cout << i << " ";
                }
                cout << endl;

                for (auto i : b)
                {
                    cout << i << " ";
                }
                cout << endl;

                if (a.size() != b.size())
                {
                    f = false;
                }
                else
                {
                    for (int i = 0; i < a.size(); i++)
                    {
                        if ((a[i] < b[i]) || ((a[i] - b[i]) % 2 == 1))
                        {
                            f = false;
                            break;
                        }
                    }
                }
                if (f)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
}
