def find_parent(parent, x):     #부모 노드를 찾는 함수
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b): # 부모 노드를 합치는 함수
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())

parent = [0] * (n + 1)
edges = []
result = 0

for i in range(1, n + 1):
    parent[i] = i

for _ in range(m):
    x, y, z = map(int, input().split())
    edges.append((z, x, y))
    print(edges)

    edges.sort()
    print(edges)

    total = 0

    for edge in edges:
        cost, a, b = edge
        total += cost

        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            result += cost

print(total - result)

