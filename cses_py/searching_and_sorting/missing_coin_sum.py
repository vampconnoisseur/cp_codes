import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

S = 0

for x in arr:
    if x > S + 1:
        print(S + 1)
        exit()
    S += x

print(S + 1)