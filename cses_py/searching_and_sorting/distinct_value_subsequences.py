import sys
from collections import defaultdict

input = sys.stdin.readline

MOD = 10**9+7

n = int(input())
arr = list(map(int, input().split()))

m = defaultdict(int)
for i in arr:
    m[i] += 1

ans = 1
for i in m.values():
    ans = (ans * (i + 1)) % MOD

print(ans - 1)