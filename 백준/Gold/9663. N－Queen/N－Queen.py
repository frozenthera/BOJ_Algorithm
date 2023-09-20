N = int(input())
arr = [-1 for _ in range(N)]

def putQueen(row, col, arr):
    for i in range(row):
        if arr[i] == col or abs(arr[i] - col) == abs(i - row):
            return 0
        
    if row == N-1:
        return 1
    
    sum = 0
    arr[row] = col
    for i in range(N):
        sum += putQueen(row+1, i, arr)
    return sum

sum = 0
for i in range(N//2):
    sum += putQueen(0, i, arr)*2
if N%2 is 1:
    sum += putQueen(0, N//2, arr)

print(sum)