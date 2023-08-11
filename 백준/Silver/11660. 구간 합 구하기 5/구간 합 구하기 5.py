import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
sum = [[0 for _ in range(N+1)] for _ in range(N)]

for i in range(N):
    temp = sys.stdin.readline().rstrip().split()
    for j in range(N):
        sum[i][j+1] = int(temp[j]) + sum[i][j]
ans = []
for i in range(M):
    temp = list(map(int, sys.stdin.readline().rstrip().split()))
    localSum = 0
    for j in range(temp[2] - temp[0] + 1):
        localSum += sum[j+temp[0]-1][temp[3]] - sum[j+temp[0]-1][temp[1]-1]
    ans.append(localSum)

for i in range(len(ans)):
    print(ans[i])