n, m = map(int, input().split())
ans = 1
for i in range(n, n-m, -1):
    ans *= i
for i in range(1, m+1):
    ans //= i
print(ans)