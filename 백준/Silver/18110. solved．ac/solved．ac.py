import sys
import decimal

N = int(input())

data = []
for _ in range(N):
    data.append(int(sys.stdin.readline().rstrip()))

data.sort()

rN = decimal.Decimal(N) * decimal.Decimal(15) / decimal.Decimal(100)
cut = int(rN) + (1 if rN - int(rN) >= 0.5 else 0)
data = data[cut:]
data = data[:len(data)-cut]

if len(data) is 0:
    print("0")
else:
    sum = 0
    for i in range(len(data)):
        sum += data[i]

    res = decimal.Decimal(sum) / decimal.Decimal(len(data))
    print(int(res) + (1 if res - int(res) >= 0.5 else 0))