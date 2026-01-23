#include <bits/stdc++.h>
using namespace std;

// Helper to make visualizing easier
void print_separator()
{
    cout << "----------------------------------------------------" << endl;
}

template <class T>
class MaxSegmentTree
{
private:
    const T DEFAULT = 0;

    int len;
    vector<T> segtree;

public:
    MaxSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val)
    {
        cout << "    [SegTree] Setting Position " << ind << " to Value " << val << endl;
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2)
        {
            segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
        }
    }

    T range_max(int start, int end)
    {
        cout << "    [SegTree] Querying Range [Pos " << start << ", Pos " << end - 1 << "]" << endl;
        T max = DEFAULT;
        int original_start = start;
        int original_end = end;

        for (start += len, end += len; start < end; start /= 2, end /= 2)
        {
            if (start % 2 == 1)
            {
                max = std::max(max, segtree[start++]);
            }
            if (end % 2 == 1)
            {
                max = std::max(max, segtree[--end]);
            }
        }
        cout << "      -> Max found in range [" << original_start << ", " << original_end - 1 << "]: " << max << endl;
        return max;
    }
};

template <class T, bool VALS_IN_EDGES>
class HLD
{
private:
    int N, R, tim = 0;
    vector<vector<int>> adj;
    vector<int> par, siz, depth, rt, pos;
    MaxSegmentTree<T> segtree;

    void dfs_sz(int v)
    {
        if (par[v] != -1)
            adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));

        for (int &u : adj[v])
        {
            par[u] = v, depth[u] = depth[v] + 1;
            dfs_sz(u);
            siz[v] += siz[u];
            // Visualization of Heavy Edge logic
            if (siz[u] > siz[adj[v][0]])
            {
                swap(u, adj[v][0]);
            }
        }
        if (!adj[v].empty())
        {
            cout << "  [Preproc] Node " << (v + 1) << " (Size: " << siz[v] << ") prefers Heavy Child: Node " << (adj[v][0] + 1) << endl;
        }
    }

    void dfs_hld(int v)
    {
        pos[v] = tim++;
        cout << "  [Preproc] Mapping Node " << (v + 1) << " -> SegTree Pos " << pos[v]
             << " | Chain Root: " << (rt[v] + 1) << endl;

        for (int u : adj[v])
        {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfs_hld(u);
        }
    }

    template <class B>
    void process(int u, int v, B op)
    {
        cout << "  [HLD Process] Path from Node " << (u + 1) << " to Node " << (v + 1) << endl;
        for (; rt[u] != rt[v]; v = par[rt[v]])
        {
            if (depth[rt[u]] > depth[rt[v]])
                swap(u, v); // Ensure v is the one deeper to jump up

            cout << "    Step: Nodes on different chains. Jumping Node " << (v + 1)
                 << " (Root " << (rt[v] + 1) << ") up." << endl;

            op(pos[rt[v]], pos[v]);
        }

        if (depth[u] > depth[v])
            swap(u, v);

        cout << "    Step: Nodes on same chain (Root " << (rt[u] + 1) << "). Processing segment "
             << (u + 1) << " to " << (v + 1) << endl;

        op(pos[u] + VALS_IN_EDGES, pos[v]);
    }

public:
    HLD(vector<vector<int>> adj_, int _R)
        : N(adj_.size()), R(_R), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N),
          pos(N), segtree(N)
    {
        cout << "--- HLD Initialization Started ---" << endl;
        rt[R] = R;
        dfs_sz(R);
        cout << "--- Size & Heavy Child Calculation Done ---" << endl;
        dfs_hld(R);
        cout << "--- Linearization (DFS Order) Done ---" << endl;
        print_separator();
    }

    T query_path(int u, int v)
    {
        cout << "Query: Max on path " << (u + 1) << " <-> " << (v + 1) << endl;
        T res = 0;
        process(u, v, [&](int l, int r)
                { res = max(res, segtree.range_max(l, r + 1)); });
        cout << "Query Result: " << res << endl;
        print_separator();
        return res;
    }

    void modify_node(int u, T val)
    {
        cout << "Update: Node " << (u + 1) << " -> Value " << val << endl;
        segtree.set(pos[u], val);
        // print_separator(); // Optional: uncomment if initialization spam is too much
    }
};

int main()
{
    // Removing fast IO to prevent print buffer mixing
    // ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q;
    if (!(cin >> n >> q))
        return 0;

    cout << "Input received: N=" << n << ", Q=" << q << endl;

    vector<int> v(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    HLD<int, 0> H(adj, 0);

    cout << "--- Initializing Values into SegTree ---" << endl;
    for (int i = 0; i < n; i++)
    {
        H.modify_node(i, v[i]);
    }
    print_separator();

    cout << "--- Processing Queries ---" << endl;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s, x;
            cin >> s >> x;
            --s;
            H.modify_node(s, x);
            print_separator();
        }
        else if (type == 2)
        {
            int a, b;
            cin >> a >> b;
            --a, --b;
            cout << H.query_path(a, b) << " ";
        }
    }
    cout << endl;
}