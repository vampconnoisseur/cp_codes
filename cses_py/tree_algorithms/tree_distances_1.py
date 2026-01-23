import sys
sys.setrecursionlimit(300000)

n = int(sys.stdin.readline())
tree = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    tree[a].append(b)
    tree[b].append(a)

depth = [0] * (n + 1)
ans = [0] * (n + 1)

def eval_depth(src, par):
    max_depth = 0
    for child in tree[src]:
        if child == par:
            continue
        eval_depth(child, src)
        max_depth = max(max_depth, 1 + depth[child])
    depth[src] = max_depth

def solve(src, par, par_ans):
    children = []
    for child in tree[src]:
        if child == par:
            continue
        children.append(child)

    k = len(children)
    prefix = [0] * k
    suffix = [0] * k

    for i in range(k):
        prefix[i] = depth[children[i]]
        suffix[i] = depth[children[i]]

    for i in range(1, k):
        prefix[i] = max(prefix[i], prefix[i - 1])

    for i in range(k - 2, -1, -1):
        suffix[i] = max(suffix[i], suffix[i + 1])

    for i, child in enumerate(children):
        left = prefix[i - 1] if i > 0 else -1
        right = suffix[i + 1] if i < k - 1 else -1
        best_sibling = max(left, right)

        partial_ans = 1 + max(par_ans, best_sibling)
        solve(child, src, partial_ans)

    best_child = prefix[-1] if k > 0 else -1
    ans[src] = 1 + max(par_ans, best_child)

eval_depth(1, -1)
solve(1, -1, -1)

print(*ans[1:])