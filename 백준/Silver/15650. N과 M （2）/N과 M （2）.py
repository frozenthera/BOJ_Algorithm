import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
serial = []

def func(series, left, curPos):
    if left <= 0:
        for i in range(len(series)):
            print(series[i], end= ' ')
        print()
        return
    if curPos > N and left > 0:
        return
    
    
    series.append(curPos)
    func(series, left-1, curPos+1)
    series.pop(len(series)-1)
    func(series, left, curPos+1)

func(serial, M, 1)