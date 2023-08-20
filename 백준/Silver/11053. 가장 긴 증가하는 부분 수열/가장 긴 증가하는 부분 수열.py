import sys

N = int(input())
data = list(map(int, sys.stdin.readline().rstrip().split()))
cache = [-1 for _ in range(N)]

cache[0] = 1
for i in range(1, N):
    cache[i] = 1
    for j in range(1, i+1):
        if data[i] > data[i-j] and cache[i-j] >= cache[i]:
            cache[i] = cache[i-j] + 1
            
print(max(cache))