import sys

n = int(sys.stdin.readline())
l = list(map(int, sys.stdin.readline().split()))

curr = 0
maxi = -10**18

for i in l:
    curr += i
    maxi = max(curr, maxi)
    curr = max(0, curr)

print(maxi)