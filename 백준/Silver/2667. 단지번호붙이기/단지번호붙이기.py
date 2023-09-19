import sys

N = int(input())
arr = []
diff = [(0,1), (0,-1), (1,0), (-1,0)]

for i in range(N):
    data = input()
    temp = []
    for j in range(N):
        temp.append(int(data[j]))
    arr.append(temp)

stack = []
isvisited = set()
ans = []

for i in range(N):
    for j in range(N):
        
        start = (i,j)
        if start in isvisited or arr[start[0]][start[1]] is 0:
            continue

        local = 0
        stack.append(start)

        while len(stack) > 0:
            x, y = stack.pop()

            if (x,y) in isvisited or arr[x][y] == 0:
                continue

            isvisited.add((x,y))
            local += 1

            for k in range(4):
                next = (x+diff[k][0], y+diff[k][1])
                if -1 < next[0] < N and -1 < next[1] < N and next not in isvisited:
                    stack.append(next)
        ans.append(local)

ans.sort()
print(len(ans))
print(*ans, sep= '\n')