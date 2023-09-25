import sys

N = int(input())
data = list(map(int, sys.stdin.readline().rstrip().split()))
V = int(input())

ans = 0
for i in range(N):
    if data[i] == V:
        ans += 1
print(ans)