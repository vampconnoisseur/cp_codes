import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

s = set()

i = 0 
j = 0
ans = 0

while(j < n):
    if arr[j] in s:
        while arr[i] != arr[j]:
            s.remove(arr[i])
            i += 1
        i += 1

    ans += j - i + 1
    
    s.add(arr[j])
    j += 1

print(ans)