#퇴사
N = int(input())
T = []
P = []
result = 0
end_day = 0
dp = [0] * N

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