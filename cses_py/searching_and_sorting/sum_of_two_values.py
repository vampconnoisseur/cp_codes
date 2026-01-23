import sys

n, x = map(int, sys.stdin.readline().split())
l = list(map(int, sys.stdin.readline().split()))
l = [(x, i) for i, x in enumerate(l)]

l.sort()

i = 0
j = len(l) - 1
f = 0

while i < j:
    if l[i][0] + l[j][0] == x:
        print(l[i][1]+1, l[j][1]+1)
        f = 1
        break
    elif l[i][0] + l[j][0] < x:
        i += 1
    else:
        j -= 1

if f == 0:
    print("IMPOSSIBLE")