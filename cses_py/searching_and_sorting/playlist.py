import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

s = set()
i = 0
max_len = 0

for j in range(n):
    while arr[j] in s:
        s.remove(arr[i])
        i += 1

    s.add(arr[j])
    max_len = max(max_len, len(s))

print(max_len)