import sys
arr = list(map(int, sys.stdin.readline().rstrip().split()))
arr.sort()
print(arr[1])