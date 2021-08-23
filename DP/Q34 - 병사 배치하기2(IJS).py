N = int(input())
soldiers = list(map(int, input().split()))

dp = [1] * N
print(dp)

# n^2
# dp[i] : i번째 수를 마지막 원소로 가지는 lis의 길이
for i in range(1, N):
    for j in range(i):
        if soldiers[j] > soldiers[i]:
            dp[i] = max(dp[i], dp[j]+1)
            print(dp)

print(N - max(dp))