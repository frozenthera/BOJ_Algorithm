import sys

N = int(sys.stdin.readline().rstrip())
arr = []

for i in range(N):
    data = sys.stdin.readline().rstrip().split()
    arr.append((int(data[0]), int(data[1])))

arr.sort(key = lambda x: (x[1], x[0]))
minStart = 0
minEnd = 0
count = 0
for item in arr:
    if item[0] >= minEnd:
        minEnd = item[1]
        count += 1

print(count)
