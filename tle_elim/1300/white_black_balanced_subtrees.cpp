// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
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
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }
void sieve(vector<bool> &primes, int N) { primes[0] = primes[1] = true; for (int i = 2; i * i <= N; i++) { if (!primes[i]) { for (int j = i * i; j <= N; j += i) { primes[j] = true; } } } }
int binpow(int a, int b) { int res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
int binpowMod(int a, int b) { a %= MOD; int res = 1; while (b > 0) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1; } return res; }
void addPrimeDivs(int x, map<int, int> &divs) { int i = 2; while (i * i <= x) { while (x % i == 0) { divs[i]++; x /= i; } i++; } if (x > 1) divs[x]++; }
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,lzcnt,fma,tune=native")
// clang-format on

struct Node
{
    int data;
    int color;
    vector<Node *> children;

    Node(int data, int color)
    {
        this->data = data;
        this->color = color;
    }
};

struct CompareNode
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

pii isBalanced(Node *root, int &ans)
{
    if (!root)
        return {0, 0};

    int white_nodes = root->color;
    int black_nodes = !root->color;

    fore(child, root->children)
    {
        pii sub = isBalanced(child, ans);
        white_nodes += sub.X;
        black_nodes += sub.Y;
    }

    if (white_nodes == black_nodes)
        ans++;

    return {white_nodes, black_nodes};
}

void solve()
{
    int n;
    cin >> n;

    vpii v;
    rep(i, 0, n - 1)
    {
        int a;
        cin >> a;
        v.eb(a, i + 2);
    }
    SORT(v);

    string s;
    cin >> s;

    priority_queue<Node *, vector<Node *>, CompareNode> q;

    Node *root = new Node(1, (s[0] == 'B' ? 0 : 1));
    q.push(root);

    rep(i, 0, n - 1)
    {
        int parent = v[i].X;
        int idx = v[i].Y;

        while (parent != q.top()->data)
            q.pop();

        Node *new_node = new Node(idx, (s[idx - 1] == 'B' ? 0 : 1));
        q.top()->children.pb(new_node);
        q.push(new_node);
    }

    int ans = 0;
    isBalanced(root, ans);

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}