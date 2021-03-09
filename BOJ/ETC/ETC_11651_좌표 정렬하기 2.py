n = int(input())

ar = []
for i in range(n):
    [x, y] = map(int, input().split())
    ar.append([y, x])

ar = sorted(ar)
for i in range(n):
    print(ar[i][1], ar[i][0])
