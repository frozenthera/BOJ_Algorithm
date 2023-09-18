import sys
from collections import deque

N, M = map(int, sys.stdin.readline().rstrip().split())
trusted = {}

for i in range(1, N+1):
    trusted[i] = []

for i in range(M):
    st, ed = map(int, sys.stdin.readline().rstrip().split())
    if st is ed:
        continue
    trusted[ed].append(st)

ans = (0, [])

for i in range(1, N+1):
    
    que = deque()
    que.append(i)

    isvisited = [0 for _ in range(N)]
    isvisited[i-1] = 1
    
    localSum = 0
    
    while len(que) > 0:
        cur = que.popleft()
        for item in trusted[cur]:
            if isvisited[item-1] is 0:
                isvisited[item-1] = 1
                que.append(item)
                localSum += 1

    if localSum > ans[0]:
        ans = (localSum, [i])
    elif localSum is ans[0]:
        ans[1].append(i)

print(*(ans[1]))