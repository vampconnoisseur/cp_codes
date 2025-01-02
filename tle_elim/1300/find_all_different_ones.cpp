#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define si set<int>
#define sll set<long long>
#define spii set<pair<int, int>>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define maxpq priority_queue<int>
#define SORT(a) sort(a.begin(), a.end())
#define REVSORT(a, T) sort(a.begin(), a.end(), greater<T>())
#define rev(a) reverse(a.begin(), a.end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define fore(e, a) for (auto &e : a)
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")

struct Node
{
    int minVal, maxVal, minIndex, maxIndex;
};

class SegmentTree
{
    vector<Node> tree;
    vector<int> arr;
    int n;

    Node merge(Node left, Node right)
    {
        Node res;
        if (left.minVal <= right.minVal)
        {
            res.minVal = left.minVal;
            res.minIndex = left.minIndex;
        }
        else
        {
            res.minVal = right.minVal;
            res.minIndex = right.minIndex;
        }

        if (left.maxVal >= right.maxVal)
        {
            res.maxVal = left.maxVal;
            res.maxIndex = left.maxIndex;
        }
        else
        {
            res.maxVal = right.maxVal;
            res.maxIndex = right.maxIndex;
        }
        return res;
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = {arr[start], arr[start], start, start};
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    Node query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
        {
            return {INT_MAX, INT_MIN, -1, -1};
        }
        if (start >= l && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left = query(2 * node + 1, start, mid, l, r);
        Node right = query(2 * node + 2, mid + 1, end, l, r);
        return merge(left, right);
    }

public:
    SegmentTree(vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    Node query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    fore(e, arr) cin >> e;

    int q;
    cin >> q;
    SegmentTree segTree(arr);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        Node res = segTree.query(l, r);
        if (res.minVal == res.maxVal)
        {
            cout << "-1 -1" << endl;
        }
        else
        {
            cout << res.minIndex + 1 << " " << res.maxIndex + 1 << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}