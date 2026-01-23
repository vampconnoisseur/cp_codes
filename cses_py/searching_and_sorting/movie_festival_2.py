import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())
movies = []

for _ in range(n):
    a, b = map(int, input().split())
    movies.append((b, a))

movies.sort()

available = [-0] * k
heapq.heapify(available)

busy = []
ans = 0

for end, start in movies:
    while busy and busy[0] <= start:
        finish_time = heapq.heappop(busy)
        heapq.heappush(available, -finish_time)

    if available:
        finish_time = -heapq.heappop(available)
        heapq.heappush(busy, end)
        ans += 1

print(ans)