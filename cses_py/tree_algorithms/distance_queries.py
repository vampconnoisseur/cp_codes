import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n, q = map(int, input().split())

LOG = 20
tree = [[] for _ in range(n + 1)]
up = [[-1] * LOG for _ in range(n + 1)]
lvl = [0] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

def dfs(node, parent):
    up[node][0] = parent
    for i in range(1, LOG):
        if up[node][i - 1] != -1:
            up[node][i] = up[up[node][i - 1]][i - 1]
        else:
            up[node][i] = -1

    for child in tree[node]:
        if child != parent:
            lvl[child] = lvl[node] + 1
            dfs(child, node)

dfs(1, -1)

def lift_node(u, jump):
    for i in range(LOG - 1, -1, -1):
        if jump & (1 << i):
            u = up[u][i]
            if u == -1:
                break
    return u

def LCA(u, v):
    if lvl[u] < lvl[v]:
        u, v = v, u

    u = lift_node(u, lvl[u] - lvl[v])

    if u == v:
        return u

    for i in range(LOG - 1, -1, -1):
        if up[u][i] != up[v][i]:
            u = up[u][i]
            v = up[v][i]

    return up[u][0]


out = []
for _ in range(q):
    u, v = map(int, input().split())
    x = LCA(u, v)
    dist = (lvl[u] - lvl[x]) + (lvl[v] - lvl[x])
    out.append(str(dist))

print("\n".join(out))