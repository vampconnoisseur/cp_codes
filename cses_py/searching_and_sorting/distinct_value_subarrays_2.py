import sys
from collections import defaultdict

input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

s = set()
d = defaultdict(int)

ans = 0
i, j = 0, 0

while j < n:
    d[arr[j]] += 1
    s.add(arr[j])

    while len(s) > k:
        d[arr[i]] -= 1
        if d[arr[i]] == 0:
            s.remove(arr[i])
        i += 1

    ans += (j - i + 1)

    j += 1

print(ans)