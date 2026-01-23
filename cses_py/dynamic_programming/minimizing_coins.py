import sys
input = sys.stdin.readline

n, x = map(int, input().split())
coins = list(map(int, input().split()))

INF = 10**18
dp = [INF] * (x + 1)
dp[0] = 0

coins.sort()

for i in range(1, x + 1):
    best = INF
    for c in coins:
        if c > i:
            break
        best = min(best, dp[i - c] + 1)

    dp[i] = best

print(dp[x] if dp[x] < INF else -1)