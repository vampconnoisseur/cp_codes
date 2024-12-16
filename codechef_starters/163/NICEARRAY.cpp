#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        vector<int> mins;
        vector<int> maxs;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            double d = (double)arr[i] / (double)k;

            mins.push_back(floor(d));
            maxs.push_back(ceil(d));
        }

        int ans = accumulate(mins.begin(), mins.end(), 0);
        int ans1 = accumulate(maxs.begin(), maxs.end(), 0);

        if (ans <= 0 && ans1 >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}