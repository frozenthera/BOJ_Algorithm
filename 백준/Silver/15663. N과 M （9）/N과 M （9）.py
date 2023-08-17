import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
data = sorted(list(map(int, sys.stdin.readline().rstrip().split())))
check = set()


def func(series, left, _data, curPos):
    if tuple(series) in check:
        return
    if left <= 0:
        check.add(tuple(series))
        print(*series)
        return
    if curPos >= len(_data) and left > 0:
        return

    series.append(_data[curPos])
    temp = _data.pop(curPos)
    func(series, left-1, _data, 0)

    series.pop()
    _data.insert(curPos, temp)
    func(series, left, _data, curPos+1)

func([], M, data, 0)