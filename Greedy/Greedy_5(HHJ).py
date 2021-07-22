#5 볼링공 고르기
#N은 볼링공의 개수, M은 공의 최대 무게
N = map(int, input().split())
#K는 각각의 공의 무게
K = list(map(int, input().split()))
result = 0

for i in range(len(K)):
    tmp = K[i+1:]
    if K[i] in tmp:
        tmp.remove(K[i])
    result += len(tmp)

print(result)
