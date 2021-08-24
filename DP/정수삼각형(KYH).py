n = int(input())

dp = []

for _ in range(n):
    dp.append(list(map(int, input().split())))

for j in range(1,n):
    for k in range(j+1):
        if k==0:
            dp[j][k] += dp[j-1][k]
        elif k==j:
            dp[j][k] += dp[j-1][k-1]
        else:
            dp[j][k] += max(dp[j-1][k], dp[j-1][k-1])
        print(dp)

print(max(dp[-1]))
