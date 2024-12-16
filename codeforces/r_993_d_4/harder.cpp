#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> transformArray(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, 0);
    unordered_set<int> seen;
    int filler = 1;

    for (int i = 0; i < n; ++i)
    {
        if (seen.find(arr[i]) == seen.end())
        {
            result[i] = arr[i];
            seen.insert(arr[i]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (result[i] == 0)
        {
            while (seen.find(filler) != seen.end())
            {
                ++filler;
            }
            result[i] = filler;
            seen.insert(filler);
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        vector<int> result = transformArray(arr);

        for (int x : result)
        {
            cout << x << endl;
        }
    }

    return 0;
}