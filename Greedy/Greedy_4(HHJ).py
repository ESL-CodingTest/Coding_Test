#4 만들수 없는 금액
#동전의 개수
N = int(input())
#화폐 단위
M = list(map(int, input().split(" ")))

def biggest(arr, n):
    b = 0
    for i in arr:
        if i > b and i <= n:
            b = i
    if b == 0:
        return -1
    return b

result = 0
while(True):
    # 최소 금액의 값을 1씩 증가시키며 확인
    result += 1
    #tmp는 동전의 화폐단위 M을 복사
    tmp = M[:]
    #최소 금액이 하나의 동전으로 처리가능한 경우 pass
    if result in tmp:
        continue
    #하나의 동전으로 처리가 안되는 경우
    mid = result
    while(True):
        sub = biggest(tmp, mid)
        if sub == -1:
            break
        mid -= sub
        tmp.remove(sub)
    if mid != 0:
        break


print(result)