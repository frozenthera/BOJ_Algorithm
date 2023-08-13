import sys

N = int(input())
tree = {}

for i in range(N):
    root, left, right = map(str, sys.stdin.readline().rstrip().split())
    tree[root] = [left, right]

def pre(cur):
    print(cur, end = '')
    if tree[cur][0] != '.':        
        pre(tree[cur][0])
    if tree[cur][1] != '.':
        pre(tree[cur][1])

def mid(cur):
    if tree[cur][0] != '.':        
        mid(tree[cur][0])
    print(cur, end = '')
    if tree[cur][1] != '.':
        mid(tree[cur][1])

def post(cur):
    if tree[cur][0] != '.':        
        post(tree[cur][0])
    if tree[cur][1] != '.':
        post(tree[cur][1])
    print(cur, end = '')

pre('A')
print()
mid('A')
print()
post('A')