#1. 모험가 길드
#모험가 N명, 각각의 공포도 X
N = int(input())
X = list(map(int, input().split()))
#공포도 X를 정렬
X.sort()
#임시 그룹원의 수
tmp = 0
#임시 그룹의 공포도 최댓값
x = 0
#최종 그룹수의 최댓값
result = 0

for i in X:
    if(i > x):
        x = i
    tmp += 1
    if(tmp >= x):
        result += 1
        tmp = 0
        x = 0

print(result)