#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int f(int i, const vector<int> &nums)
    {
        int n = nums[i];

        if (nums[i] >= 0)
        {
            n %= nums.size();
            while (n)
            {
                if (i == nums.size() - 1)
                    i = 0;
                else
                    i++;
                n--;
            }
        }
        else
        {
            n = abs(n);
            n %= nums.size();
            while (n)
            {

                if (i == 0)
                    i = nums.size() - 1;
                else
                    i--;
                n--;
            }
        }
        cout << i << endl;
        return nums[i];
    }

    vector<int> constructTransformedArray(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(f(i, nums));
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {3, -2, 1, 1};
    vector<int> result1 = solution.constructTransformedArray(nums1);
    cout << "Input: nums = [3, -2, 1, 1]\nOutput: [";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]\n\n";

    vector<int> nums2 = {-1, 4, -1};
    vector<int> result2 = solution.constructTransformedArray(nums2);
    cout << "Input: nums = [-1, 4, -1]\nOutput: [";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]\n";

    return 0;
}