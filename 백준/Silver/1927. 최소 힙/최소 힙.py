import sys
import heapq

N = int(sys.stdin.readline().rstrip())

heap = []

for i in range(N):
    dat = int(sys.stdin.readline().rstrip())
    if dat is 0:
        if len(heap) is 0:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, dat)