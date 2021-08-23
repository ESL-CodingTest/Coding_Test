#연구소
from itertools import combinations
import copy

#안전구역의 개수를 구하는 함수
def Savecnt(graph):
    cnt = 0
    for row in range(len(graph)):
        for col in range(len(graph[0])):
            if graph[row][col] == 0:
                cnt += 1
    return cnt

#벽의 조합을 그래프에 적용하는 함수
def build(graph, comb):
    for i in range(len(comb)):
        x, y = comb[i]
        graph[x][y] = 1


#바이러스를 퍼트리는 함수
def DFS(graph, start):
    x = start[0]
    y = start[1]
    #현재 위치에 바이러스 투척
    graph[x][y] = 2
    #바이러스가 이동가능한 위치
    able = [[x-1,y],[x+1,y],[x,y-1],[x,y+1]]
    for a, b in able:
        #이동한 위치가 범위 밖일 경우 패스
        if (a < 0 or a >= len(graph) or b < 0 or b >= len(graph[0])):
            continue
        #이동한 위치가 벽이거나 이미 바이러스인 경우 패스
        if graph[a][b] != 0:
            continue
        #이동한 위치가 빈공간인 경우 재귀함수를 통해 반복
        DFS(graph, [a, b])


#n,m 그래프 크기
n, m = map(int, input().split())
graph = []
for row in range(n):
    graph.append(list(map(int, input().split())))

#빈 공간과 바이러스가 있는 공간 표시
empty = []
virus = []

for row in range(len(graph)):
    for col in range(len(graph[0])):
        if graph[row][col] == 0:
            empty.append([row, col])
        if graph[row][col] == 2:
            virus.append([row, col])

print(empty)
combs = list(combinations(empty, 3))
max = 0
for comb in combs:
    print(comb)
    #임시 그래프 생성
    tmp = copy.deepcopy(graph)
    #임의의 벽 설치
    build(tmp, comb)
    print(tmp)
    #바이러스 퍼트리기
    for i in virus:
        DFS(tmp, i)
    print(tmp)
    #임시 그래프의 안전구역 개수 세기
    cnt = Savecnt(tmp)
    if cnt > max:
        max = cnt

print(max)