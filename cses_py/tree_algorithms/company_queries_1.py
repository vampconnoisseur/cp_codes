import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n, q = map(int, input().split())
boss = [0] + [1] + list(map(int, input().split()))

LOG = 20
up = [[-1] * (LOG) for _ in range(n + 1)]

for i in range(1, n + 1):
    up[i][0] = boss[i] if i != 1 else -1

for j in range(1, LOG):
    for i in range(1, n + 1):
        if up[i][j - 1] != -1:
            up[i][j] = up[up[i][j - 1]][j - 1]
        else:
            up[i][j] = -1

def kth_ancestor(node, k):
    for i in range(LOG):
        if node == -1:
            break
        if k & (1 << i):
            node = up[node][i]
    return node

output = []
for _ in range(q):
    x, k = map(int, input().split())
    ans = kth_ancestor(x, k)
    output.append(str(ans))

print(*(output), sep='\n')