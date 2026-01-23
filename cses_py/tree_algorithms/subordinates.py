import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
boss = list(map(int, input().split()))

adj = [[] for _ in range(n + 1)]

for e in range(2, n + 1):
    adj[boss[e - 2]].append(e)

ans = [0] * (n + 1)

def dfs(n):
    children = 0
    for child in adj[n]:
        children += dfs(child)
    ans[n] = children
    return children + 1

dfs(1)

print(ans[1:])