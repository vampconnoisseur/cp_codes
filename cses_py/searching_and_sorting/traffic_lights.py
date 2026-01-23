import sys
from sortedcontainers import SortedList

x, n = map(int, sys.stdin.readline().split())
lights = list(map(int, sys.stdin.readline().split()))

positions = SortedList([0, x])
passages = SortedList([x])

results = []
for p in lights:
    idx = positions.bisect_right(p)
    
    hi = positions[idx]
    lo = positions[idx - 1]

    old_passage_length = hi - lo
    passages.remove(old_passage_length)

    passages.add(p - lo)
    passages.add(hi - p)

    positions.add(p)

    results.append(passages[-1])

print(*results)