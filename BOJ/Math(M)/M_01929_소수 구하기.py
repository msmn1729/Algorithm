m, n = map(int, input().split())

dp = [0 for i in range(n + 1)]
dp[1] = 1

for i in range(2, n + 1):
    if dp[i] == 1:
        continue
    for j in range(i + i, n + 1, i):
        dp[j] = 1

for i in range(m, n + 1):
    if dp[i] == 0:
        print(i)
