import sys

input = sys.stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))

l = 0
sum = 0
ans = 0

for r in range(n):
    sum += arr[r]
    
    while sum > x:
        sum -= arr[l]
        l += 1
        
    if sum == x:
        ans += 1
        
print(ans)