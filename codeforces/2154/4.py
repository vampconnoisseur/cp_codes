import sys
input = sys.stdin.readline

N = 2 * 10**5 + 10
pfac = [[] for _ in range(N + 1)]

for i in range(2, N + 1):
    if not pfac[i]:
        for j in range(i, N + 1, i):
            pfac[j].append(i)

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ord_idx = sorted(range(n), key=lambda x: b[x])
    ans = b[ord_idx[0]] + b[ord_idx[1]]

    cnt = {}
    repeated = False

    for i in range(n):
        for x in pfac[a[i]]:
            if cnt.get(x, 0) > 0:
                ans = 0
            cnt[x] = cnt.get(x, 0) + 1

    for i in range(n):
        for x in pfac[a[i]]:
            cnt[x] -= 1
        for x in pfac[a[i] + 1]:
            if cnt.get(x, 0) > 0:
                ans = min(ans, b[i])
        for x in pfac[a[i]]:
            cnt[x] = cnt.get(x, 0) + 1

    idx = ord_idx[0]
    check = []
    for i in range(n):
        if i == idx:
            continue
        for x in pfac[a[i]]:
            check.append(x)

    for x in check:
        times = x - (a[idx] % x)
        if times == x:
            times = 0
        ans = min(ans, times * b[idx])

    print(ans)