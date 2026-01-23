import sys

n = int(sys.stdin.readline())
l = list(map(int, sys.stdin.readline().split()))

l.sort()

median = l[len(l) // 2]

ans = 0
for i in l:
    ans += abs(median - i)

print(ans)