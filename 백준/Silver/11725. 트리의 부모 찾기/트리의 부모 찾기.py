import sys
import queue

N = int(input())
graph = {}

for i in range(N):
    graph[i] = []

for _ in range(N-1):
    i, j = map(int, sys.stdin.readline().rstrip().split())
    graph[i-1].append(j-1)
    graph[j-1].append(i-1)
    
ans = [-1 for _ in range(N-1)]
que = queue.Queue()
que.put(0)

while not que.empty():
    curPos = que.get()
    for item in graph[curPos]:
        if item != 0 and ans[item-1] == -1:
            ans[item-1] = curPos+1
            que.put(item)

print(*ans)