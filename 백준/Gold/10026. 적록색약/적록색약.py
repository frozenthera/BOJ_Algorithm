import sys
N = int(input())
arr = [[-1 for _ in range(N)] for _ in range(N)]
blind = [[-1 for _ in range(N)] for _ in range(N)]
diff = [(0,-1), (0,1), (-1,0), (1,0)]

for i in range(N):
    data = sys.stdin.readline().rstrip()
    for j in range(N):
        arr[i][j] = 0 if data[j] == 'R' else (1 if data[j] == 'G' else 2)
        blind[i][j] = 0 if data[j] == 'R' or data[j] == 'G' else 1

def partition(arr):

    isvisited = set()
    que = []
    ans = 0

    for i in range(N):
        for j in range(N):

            if (i,j) in isvisited:
                continue

            isvisited.add((i,j))
            que.append((i,j))
            ans += 1

            while len(que) != 0:
                cur = que.pop()
                for k in range(4):
                    x, y = cur[0]+diff[k][0], cur[1]+diff[k][1]
                    if 0 <= x < N and 0 <= y < N and (x, y) not in isvisited and arr[x][y] == arr[cur[0]][cur[1]]:
                        isvisited.add((x,y))
                        que.append((x,y))
    return ans

print(partition(arr), partition(blind))