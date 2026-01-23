#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> events(n);
    for (int i = 0; i < n; i++)
    {
        cin >> events[i][0] >> events[i][1];
        events[i][2] = i;
    }

    // ---------------------------------------------------------
    // FIRST PASS (ASC)
    // ---------------------------------------------------------
    vector<array<int, 3>> asc = events;
    sort(asc.begin(), asc.end()); // by a, then b, then index

    multiset<int> ms;
    for (auto &e : asc)
        ms.insert(e[1]);

    vector<int> ans1(n);

    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && asc[j][0] == asc[i][0])
            j++;

        // Compute BEFORE deletion
        for (int k = i; k < j; k++)
        {
            int b = asc[k][1];
            int idx = asc[k][2];

            // count of <= b  → use upper_bound(b)
            int pos = distance(ms.begin(), ms.upper_bound(b));
            ans1[idx] = pos - 1;
        }

        // Delete AFTER batch
        for (int k = i; k < j; k++)
        {
            int b = asc[k][1];
            auto it = ms.find(b);
            if (it != ms.end())
                ms.erase(it);
        }

        i = j;
    }

    // ---------------------------------------------------------
    // SECOND PASS (DESC)
    // ---------------------------------------------------------
    vector<array<int, 3>> desc = events;

    sort(desc.begin(), desc.end(), [&](auto &x, auto &y)
         {
        if (x[0] != y[0]) return x[0] > y[0];
        if (x[1] != y[1]) return x[1] > y[1];
        return x[2] > y[2]; });

    multiset<int> ms2;
    for (auto &e : desc)
        ms2.insert(e[1]);

    vector<int> ans2(n);

    i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && desc[j][0] == desc[i][0])
            j++;

        // Compute BEFORE deletion
        for (int k = i; k < j; k++)
        {
            int b = desc[k][1];
            int idx = desc[k][2];

            // count of >= b → size - index of first >= b
            int lb = distance(ms2.begin(), ms2.lower_bound(b));
            int count = ms2.size() - lb;
            ans2[idx] = count - 1;
        }

        // Delete AFTER batch
        for (int k = i; k < j; k++)
        {
            int b = desc[k][1];
            auto it = ms2.find(b);
            if (it != ms2.end())
                ms2.erase(it);
        }

        i = j;
    }

    // ---------------------------------------------------------
    // OUTPUT
    // ---------------------------------------------------------
    for (int x : ans1)
        cout << x << " ";
    cout << "\n";
    for (int x : ans2)
        cout << x << " ";
    cout << "\n";

    return 0;
}