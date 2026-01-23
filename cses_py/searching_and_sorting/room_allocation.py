import sys
import heapq

input = sys.stdin.readline

n = int(input())
events = []

for i in range(n):
    a, b = map(int, input().split())
    events.append((a, 1, i))
    events.append((b, 2, i))

events.sort()

assignments = [0] * n
free_rooms = []
room_count = 0

for _, type, i in events:
    if type == 1:
        if not free_rooms:
            room_count += 1
            assignments[i] = room_count
        else:
            assignments[i] = heapq.heappop(free_rooms)
    else: 
        heapq.heappush(free_rooms, assignments[i])

print(room_count)
print(*assignments)