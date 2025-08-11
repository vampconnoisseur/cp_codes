#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int f(int n, const vector<string> &g, string w)
{
    int len = w.length();
    if (len == 0)
        return 0;

    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j] == w[0])
            {
                for (int d = 0; d < 8; ++d)
                {
                    int x = i, y = j;
                    bool flag = true;

                    for (int k = 1; k < len; ++k)
                    {
                        x += dx[d];
                        y += dy[d];

                        if (x < 0 || x >= n || y < 0 || y >= n || g[x][y] != w[k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    vector<string> g(n);
    for (int i = 0; i < n; ++i)
        cin >> g[i];

    string w;
    cin >> w;

    cout << f(n, g, w) << endl;
    return 0;
}