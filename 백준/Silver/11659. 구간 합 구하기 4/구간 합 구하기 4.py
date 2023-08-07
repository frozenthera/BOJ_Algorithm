import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
data = sys.stdin.readline().rstrip().split()

arr = []
ans = []
accumulated = []

arr.append(0)
accumulated.append(0)

for i in range(N):
    arr.append(int(data[i]))
    accumulated.append(accumulated[i] + int(data[i]))
    
for i in range(M):
    input = sys.stdin.readline().rstrip().split()
    ans.append(accumulated[int(input[1])] - accumulated[int(input[0])-1])

for i in range(M):
    print(ans[i])