import sys

N = sys.stdin.readline().rstrip()
data = sys.stdin.readline().rstrip().split()

arr = []
for i in range(int(N)):
    arr.append(int(data[i]))

arr.sort()
sum = 0
for i in range(int(N)):
    sum += arr[i] * (int(N) - i)

print(sum)