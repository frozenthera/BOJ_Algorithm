import sys
import queue

N, M = map(int, sys.stdin.readline().rstrip().split())

arr = [[0 for j in range(M)] for i in range(N)]
length = [[0 for j in range(M)] for i in range(N)]

queue = queue.Queue()
isvisited = set()

for i in range(N):
    cur = sys.stdin.readline().rstrip().split()
    for j in range(M):
        arr[i][j] = int(cur[j])
        if int(cur[j]) is 2:
            length[i][j] = 0
            queue.put((i,j))
            isvisited.add((i,j))

diff = [(1,0),(-1,0), (0,1),(0,-1)]

while not queue.empty():

    curpos = queue.get()
    for i in range(4):
        nextpos = (curpos[0] + diff[i][0], curpos[1] + diff[i][1])
        if nextpos[0] > -1 and nextpos[0] < N and nextpos[1] > -1 and nextpos[1] < M and (nextpos[0], nextpos[1]) not in isvisited and arr[nextpos[0]][nextpos[1]] is 1:
            length[nextpos[0]][nextpos[1]] = length[curpos[0]][curpos[1]] + 1
            isvisited.add(nextpos)
            queue.put(nextpos)

for i in range(N):
    for j in range(M):
        if (i,j) not in isvisited and arr[i][j] is not 0:
            length[i][j] = -1

for i in range(N):
    for j in range(M):
        print(length[i][j], end = " ")
    print()