import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

s = []  
ans = []

for i in range(n):
    while s and s[-1][0] >= a[i]:
        s.pop()
    
    if not s:
        ans.append(0)
    else:
        ans.append(s[-1][1] + 1)
    
    s.append((a[i], i))

print(*ans)