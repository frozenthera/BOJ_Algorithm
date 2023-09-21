N = int(input())

dp = [[-1 for _ in range(N)] for _ in range(2)]

for i in range(2):
    dp[i][0] = 1

def check(bin, left):
    if dp[bin][left] != -1:
        return dp[bin][left]

    if bin == 0:
        dp[bin][left] = check(0, left-1) + check(1, left-1)
    else:
        dp[bin][left] = check(0, left-1)
    return dp[bin][left]

print(check(1, N-1))