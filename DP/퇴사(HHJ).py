#퇴사
#남은 일수
N = int(input())
#상담 기간
T = []
#금액
P = []
#벌 수 있는 최대 금액
result = 0
#해당 일을 시작할 경우 다음 일을 시작할 수 있는 날
end_day = 0
#i일부터 마지막날까지 일했을 경우 벌 수 있는 최대 금액
dp = [0] * N
햣
for _ in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

for i in range(N-1, -1, -1):
    end_day = T[i] + i
    if(end_day < N):
        dp[i] = max(P[i] + dp[end_day], result)
        result = dp[i]
    else:
        dp[i] = 0

print(result)