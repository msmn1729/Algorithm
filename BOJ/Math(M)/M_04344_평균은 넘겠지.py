t = int(input())

for i in range(t):
    n = list(map(int, input().split()))
    sum = 0
    for j in n[1:]:
        sum += j
    cnt = 0
    avg = sum / n[0]
    for j in n[1:]:
        if avg < j:
            cnt += 1
    print(str('%.3f' % round(cnt / n[0] * 100, 3)) + '%')
