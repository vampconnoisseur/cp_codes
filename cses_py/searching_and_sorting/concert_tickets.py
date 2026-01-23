import sys, bisect

n, m = map(int, sys.stdin.readline().split())
l1 = list(map(int, sys.stdin.readline().split()))
l2 = list(map(int, sys.stdin.readline().split()))

l1.sort()

for i in l2:
    idx = bisect.bisect_left(l1, i)

    if len(l1) == 0:
        print(-1)
        continue

    if idx == len(l1):
        print(l1.pop(idx-1))
    else:
        if l1[idx] > i:
            if idx == 0:
                print(-1)
            else:
                print(l1.pop(idx-1))
        else:
            print(l1.pop(idx))