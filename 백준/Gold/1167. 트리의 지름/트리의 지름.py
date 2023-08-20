import sys

N = int(input())
graph = {}  
parent = {}

for i in range(N):
    temp = list(map(int, sys.stdin.readline().rstrip().split()))
    graph[temp[0]-1] = []
    for j in range((len(temp)-2) // 2):
        graph[temp[0]-1].append((temp[j*2+1]-1, temp[j*2+2]))

que = [0]
parent[0] = -1
isvisited = set()
isvisited.add(0)
while que:
    cur = que.pop()
    for child, _ in graph[cur]:
        if child not in isvisited:
            parent[child] = cur
            que.append(child)
            isvisited.add(child)

heightMap = [-1 for _ in range(N)]
def height(idx):
    if len(graph[idx]) == 1:
        heightMap[idx] = 0
        return 0

    if heightMap[idx] != -1:
        return heightMap[idx]

    nodes = []
    for nextIdx, dist in graph[idx]:
        if nextIdx != parent[idx]:
            nodes.append(height(nextIdx) + dist)
    heightMap[idx] = max(nodes)
    return max(nodes)

def diameter(idx):
    candidate = []
    childHeight = [0, 0]
    for nextPos, distance in graph[idx]:
        if nextPos != parent[idx]:
            candidate.append(diameter(nextPos))
            childHeight.append(height(nextPos) + distance)

    childHeight.sort()
    candidate.append(childHeight[-1] + childHeight[-2])
    return max(candidate)

print(diameter(0))