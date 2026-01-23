import sys

input = sys.stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))
arr = [(x, i + 1) for i, x in enumerate(arr)]

arr.sort()

for i in range(n):
    j, k = i + 1, n - 1

    tar = x - arr[i][0]

    while j < k:
        if arr[j][0] + arr[k][0] == tar:
            print(arr[i][1], arr[j][1], arr[k][1])
            exit()
        elif arr[j][0] + arr[k][0] < tar:
            j += 1
        else:
            k -= 1

print("IMPOSSIBLE")