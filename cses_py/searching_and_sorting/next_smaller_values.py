import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr = [(a, i + 1) for i, a in enumerate(arr)]

arr.sort()

l = [0] * n

