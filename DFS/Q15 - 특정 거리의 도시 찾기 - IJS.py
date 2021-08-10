from collections import deque


def convert_graph(graph, N):
    node_list = [[] for _ in range(N)]
    for node_info in graph:
        node_list[node_info[0] - 1].append(node_info[1])
    # print(node_list)
    return [[]] + node_list

# case 1
N, M, K, X = 4, 4, 2, 1
graph = [[1, 2],
         [1, 3],
         [2, 3],
         [2, 4]]

# case 2
# N, M, K, X = 4, 3, 2, 1
# graph = [[1, 2],
#          [1, 3],
#          [1, 4]]

# case 3
# N, M, K, X = 4, 4, 1, 1
# graph = [[1, 2],
#          [1, 3],
#          [2, 3],
#          [2, 4]]



graph = convert_graph(graph, N)
print(graph)
answer = [-1 for _ in range(N + 1)]     # -1은 방문하지 않았다는 뜻
answer[X] = 0     # root는 시작 노드이므로 -1 => 0으로 변환
# print(answer)
que = deque([X])
while que:
    print(que)
    now = que.popleft()
    # print(now)
    for nxt in graph[now]:
        if answer[nxt] == -1:
            answer[nxt] = answer[now] + 1
            que.append(nxt)
print(answer)
for i in range(N + 1):
    if answer[i] == K:
        print(i)
if K not in answer:
    print(-1)
