import sys
input = sys.stdin.readline

n, x = map(int, input().split())
coins = list(map(int, input().split()))
mod = 10**9 + 7

dp = [0] * (x + 1)
dp[0] = 1

coins.sort()

for i in range(1, x + 1):
    for c in coins:
        if i >= c:
            dp[i] = (dp[i] + dp[i - c]) % mod

print(dp[x])