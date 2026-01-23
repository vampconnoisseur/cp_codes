import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

arr.sort()
sum = sum(arr[:-1])
maxi = arr[-1]

if maxi > sum:
    print(2 * maxi)
else:
    print(sum + maxi)