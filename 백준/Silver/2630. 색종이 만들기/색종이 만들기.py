import sys

N = int(sys.stdin.readline().rstrip())
arr = [[0 for j in range(N)] for i in range(N)]

for i in range(N):
    input = sys.stdin.readline().rstrip().split()
    for j in range(N):
        arr[i][j] = int(input[j])

def RecurCheck(data):

    flag = 0
    for i in range(len(data)):
        for j in range(len(data)):
            if data[i][j] is not data[0][0]:
                flag = 1

    if flag is 0:
        if data[0][0] is 0:
            return (1, 0)
        else:
            return (0, 1)
    
    sum = (0,0)
    half = int(len(data)/2)
    diff = [(0, 0), (half, 0),(0, half), (half, half)]
    tempData = [[0 for j in range(half)] for i in range(half)]
    for k in range(4):
        for i in range(half):
            for j in range(half):
                tempData[i][j] = data[i + diff[k][0]][j + diff[k][1]]
        sum = (sum[0] + RecurCheck(tempData)[0], sum[1] + RecurCheck(tempData)[1])

    return sum

print(RecurCheck(arr)[0])
print(RecurCheck(arr)[1])