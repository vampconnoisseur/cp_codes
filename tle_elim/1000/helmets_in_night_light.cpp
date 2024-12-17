#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void solve()
{
    long long n, p;
    cin >> n >> p;

    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++)
    {
        v.emplace_back(b[i], a[i]);
    }

    sort(v.begin(), v.end());
    queue<pair<long long, long long>> q;

    long long i = 0;
    long long people = 0;
    long long cost = 0;
    bool brake = false;

    q.emplace(p, 1);

    while (people < n)
    {
        long long c = q.front().first;
        long long m = q.front().second;
        q.pop();

        if (c > p)
        {
            brake = true;
            break;
        }

        if (m <= n - people)
        {
            people += m;
            cost += m * c;
        }
        else
        {
            long long remaining_people = n - people;
            cost += remaining_people * c;
            people = n;
        }

        if (people < n)
        {
            while (m-- && i < n)
            {
                q.emplace(v[i].first, v[i].second);
                i++;
            }
        }
    }

    if (brake)
    {
        long long remaining_people = n - people;
        cost += remaining_people * p;
    }

    cout << cost << endl;
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