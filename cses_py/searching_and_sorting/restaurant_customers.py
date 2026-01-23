import sys

n = int(sys.stdin.readline())
l = []

while(n):
    a, b = map(int, sys.stdin.readline().split())
    l.append((a, 1))
    l.append((b, -1))
    n -= 1

l.sort()

ans = 0
maxi = 0

for p in l:
    idx = p[1]
    maxi += idx
    if maxi > ans:
        ans = maxi

print(ans)