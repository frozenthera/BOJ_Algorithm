import sys

N = int(sys.stdin.readline().rstrip())

data = [[0 for _ in range(N)] for _ in range(N)]
cache = [[-1 for _ in range(N)] for _ in range(N)]

for i in range(N):
    temp = sys.stdin.readline().rstrip().split()
    for j in range(i+1):
        data[i][j] = int(temp[j])

# max sum at (i, j)
def calc(i, j):
    if not 0 <= j < i+1:    
        return 0
    
    if cache[i][j] != -1:
        return cache[i][j] 
    
    maxSum = max(data[i][j] + calc(i-1, j), data[i][j] + calc(i-1, j-1))
    cache[i][j] = maxSum
    return maxSum

res = []
for i in range(N):
    res.append(calc(N-1, i))

print(max(res))