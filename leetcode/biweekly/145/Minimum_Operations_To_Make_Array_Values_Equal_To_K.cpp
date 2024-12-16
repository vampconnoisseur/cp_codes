#include <iostream>
#include <set>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    set<int> s(nums.begin(), nums.end());

    if (k == *s.begin())
        return s.size() - 1;
    else if (k < *s.begin())
        return s.size();
    else
        return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << minOperations(arr, k) << endl;
    }

    return 0;
}