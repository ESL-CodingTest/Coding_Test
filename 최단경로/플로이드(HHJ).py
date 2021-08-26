#플로이드
#n은 도시의 개수, m은 버스의 개수
n = int(input())
m = int(input())
#도시의 개수만큼 2차원 리스트 생성, 최소 비용을 담을 리스트, 인덱스를 편하게 보기 위해 0,0은 생략
array = [[(int(1e9))]*(n+1) for _ in range(n+1)]

#2차원 리스트의 대각선은 자기자신의 경로이기 때문에 0으로 초기화
for i in range(n+1):
    array[i][i] = 0

#각각의 버스의 경로와 비용을 입력해서 array 갱신
for _ in range(m):
    x, y, p = map(int, input().split())
    if p < array[x][y]:
        array[x][y] = p

#i번째 도시를 경유하여 도시 j에서 k로 가는데 필요한 비용을 구하고 최소값 갱신
for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            if (j != k and i != j and i != k):
                array[j][k] = min(array[j][k], array[j][i] + array[i][k])

for i in range(1, n+1):
    for j in range(1, n+1):
        print(array[i][j], end=" ")
    print()