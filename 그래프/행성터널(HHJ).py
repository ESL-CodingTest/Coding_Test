#행성터널
#부모 노드를 찾는 함수
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

#두 노드가 속한 집합을 합치는 함수
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

V = int(input())    #노드의 개수
parent = [0] * (V+1)    #부모노드 테이블
P = [[0,0,0] * (V+1)]  #노드들의 좌표
edges = []  #간선과 길이
result = 0

for i in range(1, V+1):
    parent[i] = i

for i in range(1, V+1):
    x, y, z = map(int, input().split())
    P.append([x,y,z])

#좌표들을 가지고 간선의 길이를 구함
for i in range(1, V+1):
    for j in range(i+1, V+1):
        m = min(abs(P[i][0]-P[j][0]), abs(P[i][1]-P[j][1]), abs(P[i][2]-P[j][2]))
        edges.append((m, i, j))

#간선의 길이로 정렬
print(edges)
edges.sort()

for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

print(result)