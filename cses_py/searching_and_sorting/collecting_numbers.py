import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

d = {}
for i, val in enumerate(arr):
    d[val] = i

ans = 1
curr = -1
for i in range(n):
    idx = d[i + 1]
    if idx < curr:
        ans += 1
    curr = idx

print(ans)