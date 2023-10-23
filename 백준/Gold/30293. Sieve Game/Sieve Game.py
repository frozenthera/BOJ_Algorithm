import sys

N = int(input())
t = list(map(int, sys.stdin.readline().rstrip().split()))

res = 0

for i in range(1, N + 1):
    res += abs(t[i - 1])
    temp = t[i-1]
    j = 1
    while j*i < N+1:
        t[j*i - 1] -= temp
        j += 1

if t[N - 1] != 0:
    print(-1)
else:
    print(res)
