import sys

input = sys.stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))
arr = [(a, i + 1) for i, a in enumerate(arr)]

arr.sort()

for i in range(n):
    for j in range(i+1, n):

        k, t = j + 1, n - 1
        tar = x - arr[i][0] - arr[j][0]

        while k < t:
            s = arr[t][0] + arr[k][0]
            
            if s == tar:
                print(arr[i][1], arr[j][1], arr[k][1], arr[t][1])
                exit()
            elif s < tar:
                k += 1
            else:
                t -= 1

print("IMPOSSIBLE")