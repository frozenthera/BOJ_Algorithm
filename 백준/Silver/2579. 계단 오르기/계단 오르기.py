N = int(input())

arr = [0]
dp = [-1 for _ in range(N+1)]
for i in range(N):
    arr.append(int(input()))

def chooseN(n):
    if n > N:
        return -987654321
    if n == N:
        return arr[n]

    if dp[n] is not -1:
        return dp[n]

    if n == N-1:
        return arr[n] + arr[n+1]
    
    if n == N-2:
        return arr[n] + arr[n+2]

    dp[n] = max( arr[n] + chooseN(n+2), arr[n] + arr[n+1] + chooseN(n+3) ) 
    return dp[n]

print(max(chooseN(1), chooseN(2)))