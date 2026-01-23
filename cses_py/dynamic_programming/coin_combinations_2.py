import sys
input = sys.stdin.readline

n, x = map(int, input().split())
coins = list(map(int, input().split()))
mod = 10**9 + 7

dp = [0] * (x + 1)
dp[0] = 1

coins.sort()

for c in coins:
    for i in range(c, x + 1):
        dp[i] = (dp[i] + dp[i - c]) % mod

print(dp[x])