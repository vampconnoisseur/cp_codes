import sys
from collections import defaultdict

input = sys.stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))

d = defaultdict(int)
d[0] = 1

prefix = 0
ans = 0

for i in arr:
    prefix += i
    ans += d[prefix - x]
    d[prefix] += 1

print(ans)