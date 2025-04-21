// clang-format off
#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> tree;
    int size;

    SegmentTree(int n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int idx, int value, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, value, 2 * node, l, mid);
        else
            update(idx, value, 2 * node + 1, mid + 1, r);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int ql, int qr, int node, int l, int r)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(ql, qr, 2 * node, l, mid) +
               query(ql, qr, 2 * node + 1, mid + 1, r);
    }

    void pointUpdate(int idx)
    {
        update(idx, 1, 1, 0, size - 1);
    }

    int rangeQuery(int left, int right)
    {
        return query(left, right, 1, 0, size - 1);
    }
};

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        SegmentTree seg(n);

        unordered_map<int, int> map_index;
        for (int i = 0; i < n; ++i)
        {
            map_index[nums2[i]] = i;
        }

        long long result = 0;
        for (int i = 0; i < n; ++i)
        {
            int val = nums1[i];
            int idx = map_index[val];

            int common_left = seg.rangeQuery(0, idx);
            int uncommon_left = i - common_left;
            int common_right = (n - 1 - idx) - uncommon_left;

            result += 1LL * common_left * common_right;

            seg.pointUpdate(idx);
        }

        return result;
    }
};