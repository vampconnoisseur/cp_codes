import sys
import bisect

input = sys.stdin.readline

n = int(input())
events = []

for i in range(n):
    a, b = map(int, input().split())
    events.append((a, b, i))


# -----------------------------------------------------
# FIRST PASS (ASC) – batch-processing groups of same a
# -----------------------------------------------------
events_sorted = sorted(events)

ms = sorted([b for a, b, _ in events_sorted])
ans1 = [0] * n

i = 0
while i < n:
    j = i
    # find all with same 'a'
    while j < n and events_sorted[j][0] == events_sorted[i][0]:
        j += 1

    # First compute answers for group [i, j)
    for k in range(i, j):
        a, b, idx = events_sorted[k]

        # compute pos BEFORE deletion
        pos = bisect.bisect_right(ms, b)
        ans1[idx] = pos - 1

    # After computing all answers for this 'a', delete all b's
    for k in range(i, j):
        a, b, idx = events_sorted[k]
        del ms[bisect.bisect_left(ms, b)]

    i = j


# -----------------------------------------------------
# SECOND PASS (DESC) – batch-processing groups of same a
# -----------------------------------------------------
events_sorted_desc = sorted(events, key=lambda x: (-x[0], -x[1]))

ms2 = sorted([b for a, b, _ in events_sorted_desc])
ans2 = [0] * n

i = 0
while i < n:
    j = i
    while j < n and events_sorted_desc[j][0] == events_sorted_desc[i][0]:
        j += 1

    # compute answers before deletion
    for k in range(i, j):
        a, b, idx = events_sorted_desc[k]

        lb = bisect.bisect_left(ms2, b)
        count = len(ms2) - lb
        ans2[idx] = count - 1

    # then delete all b's of this group
    for k in range(i, j):
        a, b, idx = events_sorted_desc[k]
        del ms2[bisect.bisect_left(ms2, b)]

    i = j


# OUTPUT
print(*ans1)
print(*ans2)