import sys
from collections import defaultdict

input = sys.stdin.readline
    
n = int(input())
arr = list(map(int, input().split()))

rem = [0] * n
rem[0] = 1

prefix_sum = 0
ans = 0

for num in arr:
    prefix_sum += num
    r = prefix_sum % n
    ans += rem[r]
    rem[r] += 1
    
print(ans)