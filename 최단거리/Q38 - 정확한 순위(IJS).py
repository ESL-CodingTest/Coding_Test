import sys

INF = int(1e9)

N, M = 6, 6

graph = [[INF] * N for _ in range(N)]
# print(graph)

graph_inputs = [[1, 5], [3, 4], [4, 2], [4, 6], [5, 2], [5, 4]]

for graph_input in graph_inputs:
    graph[graph_input[0] - 1][graph_input[1] - 1] = 2
# print(graph)

for i in range(N):      # 경유하는 노드
    for j in range(N):      # 시작 노드
        for k in range(N):      # 끝 노드
            # j -> i -> k, j -> k 중 길이가 더 짧은 경로로 갱신
            graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

# print(graph)

answer, check_set = 0, set([0, 1, 2, 3, 4, 5])
graph_T = list(map(list, zip(*graph)))      # graph의 행, 열을 바꾼 리스트
# print(graph_T)

for i in range(N):
    check = set([])
    for j in range(N):
        if graph[i][j] != INF:
            check.add(j)
        if graph_T[i][j] != INF:
            check.add(j)
    check_set.remove(i)
    if check == check_set:
        answer += 1
    check_set.add(i)

print(answer)

# print(N, M)
# print(graph)




