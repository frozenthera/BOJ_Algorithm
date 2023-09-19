N = int(input())

arr = [0,0,0]
ans = [0 for _ in range(N+3)]
for i in range(N):
    arr.append(int(input()))

for i in range(3, N+3):
    ans[i] = max(ans[i-1], max(ans[i-2], ans[i-3] + arr[i-1])+arr[i])

print(max(ans))