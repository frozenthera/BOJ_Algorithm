import sys

H, W, X, Y = map(int, sys.stdin.readline().rstrip().split())
arr = []
ans = [[-1 for _ in range(W)] for _ in range(H)]

for i in range(H+X):
    arr.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(X):
    for j in range(W):
        ans[i][j] = arr[i][j]
for i in range(H):
    for j in range(Y):
        ans[i][j] = arr[i][j]

for i in range(X, H):
    for j in range(Y, W):
        ans[i][j] = arr[i][j] - ans[i-X][j-Y]

for i in range(H):
    print(*ans[i])
