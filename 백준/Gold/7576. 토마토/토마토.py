import sys
from collections import deque

N, M = map(int, sys.stdin.readline().rstrip().split())

data = [[0 for _ in range(N)] for _ in range(M)]
visited = [[0 for _ in range(N)] for _ in range(M)]

empty = 0
day = 0
cnt = 0
queue = deque()

for i in range(M):
    temp = sys.stdin.readline().rstrip().split()
    for j in range(N):
        data[i][j] = int(temp[j])
        if data[i][j] is 1:
            queue.append((i,j))
            visited[i][j] = 1
            cnt += 1
        if data[i][j] is -1:
            empty += 1
            visited[i][j] = 1

while len(queue) > 0:
    limit = len(queue)

    for i in range(limit):
        x, y = queue.popleft()
        
        if 0 <= x+1 < M and visited[x+1][y] == 0:
            queue.append((x+1, y))
            visited[x+1][y] = 1
            cnt += 1 
        
        if 0 <= y+1 < N and visited[x][y+1] == 0:
            queue.append((x, y+1))
            visited[x][y+1] = 1
            cnt += 1 

        if 0 <= x-1 < M and visited[x-1][y] == 0:
            queue.append((x-1, y))
            visited[x-1][y] = 1
            cnt += 1 

        if 0 <= y-1 < N and visited[x][y-1] == 0:
            queue.append((x, y-1))
            visited[x][y-1] = 1
            cnt += 1 
    day += 1

if cnt < N*M - empty:
    day = -1
else:
    day -= 1

print(day)
