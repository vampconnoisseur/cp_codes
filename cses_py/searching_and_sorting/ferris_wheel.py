import sys

n, x = map(int, sys.stdin.readline().split())
weights = list(map(int, sys.stdin.readline().split()))

weights.sort()

i = 0
j = n - 1

gondolas = 0

while i <= j:
    gondolas += 1
    
    if i != j and weights[i] + weights[j] <= x:
        i += 1
    
    j -= 1

print(gondolas)