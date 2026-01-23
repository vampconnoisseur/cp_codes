import sys

input = sys.stdin.readline
n, m = map(int, input().split())
arr = [0] + list(map(int, input().split()))

pos = [0] * (n + 1)
for i in range(1, n + 1):
    pos[arr[i]] = i

rounds = 1
for i in range(1, n):
    if pos[i] > pos[i + 1]:
        rounds += 1

for _ in range(m):
    a, b = map(int, input().split())

    u = arr[a]
    v = arr[b]

    affected_pairs = set()
    if u > 1:
        affected_pairs.add((u - 1, u))
    if u < n:
        affected_pairs.add((u, u + 1))
    if v > 1:
        affected_pairs.add((v - 1, v))
    if v < n:
        affected_pairs.add((v, v + 1))

    for x, y in affected_pairs:
        if pos[x] > pos[y]:
            rounds -= 1

    arr[a], arr[b] = arr[b], arr[a]
    pos[u], pos[v] = b, a

    for x, y in affected_pairs:
        if pos[x] > pos[y]:
            rounds += 1

    print(str(rounds))