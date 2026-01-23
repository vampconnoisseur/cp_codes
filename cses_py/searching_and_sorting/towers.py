import sys, bisect

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

l = []

for i in arr:
    idx = bisect.bisect_right(l, i)
    if idx == len(l):
        l.append(i)
    else:
        l[idx] = i

print(len(l))