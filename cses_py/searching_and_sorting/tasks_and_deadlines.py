import sys
input = sys.stdin.readline

n = int(input())
l = []

while n:
    a, b = map(int, input().split())
    l.append((a, b))
    n -= 1

l.sort()

sum, ans = 0, 0

for a, b in l:
    sum += a
    ans += (b - sum)

print(ans)