#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minWorth(string s, vector<int> &cost)
{
    int n = s.length();
    int i = 0;

    int worth = 0;

    while (i < n)
    {
        int j = i + 1;

        int maxIdx = i;
        int maxi = cost[i];

        while (j < n && s[i] == s[j])
        {
            if (cost[j] > maxi)
            {
                worth += cost[maxIdx];
                maxIdx = j;
                maxi = max(maxi, cost[j]);
            }
            else if (cost[j] <= maxi)
            {
                worth += cost[j];
            }

            j++;
        }

        i = j;
    }

    return worth;
}

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cout << minWorth(s, cost);

    return 0;
}