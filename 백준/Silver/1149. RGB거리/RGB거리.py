import sys

N = int(input())
data = []
cache = [[987654321 for _ in range(3)] for _ in range(N)]

for i in range(N):
    data.append(list(map(int, sys.stdin.readline().rstrip().split())))

cache[0][0] = data[0][0]
cache[0][1] = data[0][1]
cache[0][2] = data[0][2]

for i in range(1, N):
    for j in range(3):
        cache[i][j] = min(cache[i-1][(j+1)%3], cache[i-1][(j+2)%3]) + data[i][j]

print(min(cache[N-1][0], cache[N-1][1], cache[N-1][2]))