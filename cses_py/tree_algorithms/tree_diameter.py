import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
adj = [[] for _ in range(n)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

diameter = 0

def dfs(curr, parent):
    global diameter

    max1 = 0
    max2 = 0

    for nxt in adj[curr]:
        if nxt != parent:
            h = dfs(nxt, curr) + 1

            if h > max1:
                max2 = max1
                max1 = h
            elif h > max2:
                max2 = h

    diameter = max(diameter, max1 + max2)
    return max1


dfs(0, -1)
print(diameter)