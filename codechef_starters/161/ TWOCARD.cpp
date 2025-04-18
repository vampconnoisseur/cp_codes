#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        int b = a;
        int arr[a];
        int arr2[b];

        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < b; i++)
        {
            cin >> arr2[i];
        }

        vector<pair<int, int>> vp;
        for (int i = 0; i < a; i++)
        {
            vp.push_back({arr[i], arr2[i]});
        }

        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());

        int bobmax = max(vp[0].first, vp[0].second);
        bool flag = false;

        for (int i = 0; i < a; i++)
        {
            if (arr[i] == vp[0].first)
                continue;
            if (arr[i] > bobmax || arr2[i] > bobmax)
            {
                flag = true;
                break;
            }
        }

        if (!flag && a > 1)
        {
            int bobmax2 = max(vp[1].first, vp[1].second);
            for (int i = 0; i < a; i++)
            {
                if (arr[i] == vp[1].first)
                    continue;
                if (arr[i] > bobmax2 || arr2[i] > bobmax2)
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
