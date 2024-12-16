#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Optimized
int getLargestOutlier(vector<int> &nums)
{
    int total = 0;
    int maxi = INT_MIN;

    for (int num : nums)
    {
        total += num;
    }

    unordered_map<int, int> f;
    for (int num : nums)
    {
        f[num]++;
    }

    for (int num : nums)
    {
        int remain = total - num;

        if (remain % 2 == 0)
        {
            int half = remain / 2;

            if ((half != num && f[half] > 0) ||
                (half == num && f[half] > 1))
            {
                maxi = max(maxi, num);
            }
        }
    }

    return maxi;
}

// Brute
int getLargestOutlier(vector<int> &nums)
{
    int total_sum = 0;
    int maxi = INT_MIN;

    for (int num : nums)
    {
        total_sum += num;
    }

    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (total_sum - nums[i] == 2 * nums[j])
                {
                    maxi = max(maxi, nums[i]);
                }
            }
        }
    }

    return maxi;
}