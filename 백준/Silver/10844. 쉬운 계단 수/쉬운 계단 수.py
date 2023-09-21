N = int(input())

dp = [[-1 for _ in range(101)] for _ in range(11)]

for i in range(11):
    dp[i][0] = 1

def check(cur, left):
    if dp[cur][left] != -1:
        return dp[cur][left]

    dp[cur][left] = ((check(cur+1, left-1) if cur < 9 else 0) + (check(cur-1, left-1) if cur > 0 else 0)) % 1000000000
    return dp[cur][left]

sum = 0
for i in range(1, 10):
    sum += check(i, N-1) % 1000000000
print(sum % 1000000000)