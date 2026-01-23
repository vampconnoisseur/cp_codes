import sys

n = int(sys.stdin.readline())
l = []

while n:
    a, b = map(int, sys.stdin.readline().split())
    l.append((a, b))
    n -= 1

l.sort()

suff_min = [0] * len(l)
suff_min[-1] = l[-1][1]

for i in range(len(l) - 2, -1, -1):
    suff_min[i] = min(suff_min[i + 1], l[i][1])

ans = 0
i = 0

while i < len(l):
    curr_min = suff_min[i]

    while i < len(l) and l[i][0] < curr_min:
        i += 1

    ans += 1

print(ans)