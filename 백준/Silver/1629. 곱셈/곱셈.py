import sys

A,B,C = map(int, sys.stdin.readline().rstrip().split())
dict = {}

dict[0] = 1
dict[1] = A%C

def mod(base, exp):
    if exp in dict:
        return dict[exp]
    
    if exp % 2 == 0:
        dict[exp] = (mod(base, int(exp/2)) * mod(base, int(exp/2))) % C
    else :
        dict[exp] = (mod(base, int((exp-1)/2)) * mod(base, int((exp-1)/2)) * A%C) % C
    return dict[exp]
        
print(mod(A,B))