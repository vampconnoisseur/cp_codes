import sys

n, m, k = map(int, sys.stdin.readline().split())
l1 = list(map(int, sys.stdin.readline().split()))
l2 = list(map(int, sys.stdin.readline().split()))

l1.sort()
l2.sort()

i = 0
j = 0

count = 0
while i < n and j < m:
    if l1[i] - k <= l2[j] <= l1[i] + k:
        count += 1
        i += 1
        j += 1
    elif l2[j] < l1[i] - k:
        j += 1
    else: 
        i += 1

print(count)