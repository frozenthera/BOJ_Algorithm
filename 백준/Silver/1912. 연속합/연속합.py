import sys

N = int(input())
acc = list(map(int, sys.stdin.readline().rstrip().split()))

dp = [0 for _ in range(len(acc))]
dp[0] = acc[0]
for i in range(1, len(acc)):
    dp[i] = max(dp[i-1] + acc[i], acc[i])
print(max(dp))