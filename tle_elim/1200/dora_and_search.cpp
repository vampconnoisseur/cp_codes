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

class SegmentTree
{
    int n;
    vector<int> treeMin, treeMax;

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        treeMin.resize(4 * n);
        treeMax.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int node, int start, int end, const vector<int> &arr)
    {
        if (start == end)
        {
            treeMin[node] = arr[start];
            treeMax[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);
            treeMin[node] = min(treeMin[2 * node + 1], treeMin[2 * node + 2]);
            treeMax[node] = max(treeMax[2 * node + 1], treeMax[2 * node + 2]);
        }
    }

    int queryMin(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return INF;
        if (start >= l && end <= r)
            return treeMin[node];
        int mid = (start + end) / 2;
        int left = queryMin(2 * node + 1, start, mid, l, r);
        int right = queryMin(2 * node + 2, mid + 1, end, l, r);
        return min(left, right);
    }

    int queryMax(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return -INF;
        if (start >= l && end <= r)
            return treeMax[node];
        int mid = (start + end) / 2;
        int left = queryMax(2 * node + 1, start, mid, l, r);
        int right = queryMax(2 * node + 2, mid + 1, end, l, r);
        return max(left, right);
    }

    int getMin(int l, int r) { return queryMin(0, 0, n - 1, l, r); }
    int getMax(int l, int r) { return queryMax(0, 0, n - 1, l, r); }
};

void solve()
{
    int n;
    cin >> n;

    vi v(n);
    for (auto &e : v)
        cin >> e;

    SegmentTree segTree(v);

    int i = 0, j = n - 1;
    while (i < j)
    {
        int currentMin = segTree.getMin(i, j);
        int currentMax = segTree.getMax(i, j);

        if ((v[i] != currentMin && v[i] != currentMax) && (v[j] != currentMin && v[j] != currentMax))
        {
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }

        if (v[i] == currentMin || v[i] == currentMax)
            ++i;
        if (v[j] == currentMin || v[j] == currentMax)
            --j;
    }

    cout << -1 << endl;
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