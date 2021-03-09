n = int(input())

ar = []
for i in range(n):
    [x, y] = map(int, input().split())
    ar.append([x, y])

ar.sort()
for i in range(n):
    print(ar[i][0], ar[i][1])