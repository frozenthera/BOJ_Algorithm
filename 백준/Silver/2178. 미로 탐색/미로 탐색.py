import sys
import queue

N, M = map(int, sys.stdin.readline().rstrip().split())

arr = [[0 for j in range(M)] for i in range(N)]

for i in range(N):
    cur = sys.stdin.readline().rstrip()
    for j in range(M):
        arr[i][j] = int(cur[j])

curpos = (0,0,1)
queue = queue.Queue()
isvisited = set()

queue.put(curpos)
isvisited.add((curpos[0], curpos[1]))

diff = [(1,0),(-1,0), (0,1),(0,-1)]

while not queue.empty():
    curpos = queue.get()

    if curpos[0] is N-1 and curpos[1] is M-1:
        break

    for i in range(4):
        nextpos = (curpos[0] + diff[i][0], curpos[1] + diff[i][1], curpos[2]+1)
        if nextpos[0] > -1 and nextpos[0] < N and nextpos[1] > -1 and nextpos[1] < M and (nextpos[0], nextpos[1]) not in isvisited and arr[nextpos[0]][nextpos[1]] is 1:
            isvisited.add((nextpos[0], nextpos[1]))
            queue.put(nextpos)
    
print(curpos[2])