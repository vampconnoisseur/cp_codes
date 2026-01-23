import sys
input = sys.stdin.readline

n, x = map(int, input().split())
l = list(map(int, input().split()))

lo, hi = 1, 10**18

while lo <= hi:
    mid = (lo + hi) // 2

    prods = 0
    for t in l:
        prods += mid // t

    if prods >= x:
        hi = mid - 1
    else:
        lo = mid + 1

print(lo)